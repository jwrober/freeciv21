// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: Freeciv21 and Freeciv Contributors
// SPDX-FileCopyrightText: Louis Moureaux <m_louis30@yahoo.com>

// self
#include "unit_utils.h"

// utility
#include "shared.h"

// common
#include "city.h"
#include "effects.h"
#include "fc_types.h"
#include "game.h"
#include "tile.h"
#include "unit.h"
#include "unittype.h"

/**
 * returns how many hp's a unit will gain on this square
 * depends on whether or not it's inside city or fortress.
 * barracks will regen landunits completely
 * airports will regen airunits  completely
 * ports    will regen navalunits completely
 * fortify will add a little extra.
 */
static int hp_gain_coord(struct unit *punit)
{
  int bonus, hp;
  const int base = unit_type_get(punit)->hp;

  // Includes barracks (100%), fortress (25%), etc.
  bonus = get_unit_bonus(punit, EFT_HP_REGEN);
  bonus = MAX(bonus, get_unit_bonus(punit, EFT_HP_REGEN_MIN));
  if (bonus <= 0)
    return 0;
  hp = (base - 1) * bonus / 100 + 1; // rounds up

  return MAX(hp, 0);
}

/**
 * add hitpoints to the unit, hp_gain_coord returns the amount to add
 * united nations will speed up the process by 2 hp's / turn, means
 * helicopters will actually not lose hp's every turn if player have that
 * wonder. Units which have moved don't gain hp, except the United Nations
 * and helicopter effects still occur.
 *
 * If 'game.info.killunhomed' is greater than 0, unhomed units lose
 * 'game.info.killunhomed' hitpoints each turn, killing the unit at the end.
 */
void unit_restore_hitpoints(struct unit *punit)
{
  bool was_lower;
  int save_hp;
  struct unit_class *pclass = unit_class_get(punit);
  struct city *pcity = tile_city(unit_tile(punit));

  was_lower = (punit->hp < unit_type_get(punit)->hp);
  save_hp = punit->hp;

  if (!punit->moved) {
    punit->hp += hp_gain_coord(punit);
  }

  // Bonus recovery HP (traditionally from the United Nations)
  punit->hp += get_unit_bonus(punit, EFT_UNIT_RECOVER);

  if (!punit->homecity && 0 < game.info.killunhomed
      && !unit_has_type_flag(punit, UTYF_GAMELOSS)) {
    // Hit point loss of units without homecity; at least 1 hp!
    // Gameloss units are immune to this effect.
    int hp_loss =
        MAX(unit_type_get(punit)->hp * game.info.killunhomed / 100, 1);
    punit->hp = MIN(punit->hp - hp_loss, save_hp - 1);
  }

  if (!pcity && !tile_has_native_base(unit_tile(punit), unit_type_get(punit))
      && !unit_transported(punit)) {
    punit->hp -= unit_type_get(punit)->hp * pclass->hp_loss_pct / 100;
  }

  if (punit->hp >= unit_type_get(punit)->hp) {
    punit->hp = unit_type_get(punit)->hp;
    if (was_lower && punit->activity == ACTIVITY_SENTRY) {
      set_unit_activity(punit, ACTIVITY_IDLE);
    }
  }

  if (punit->hp < 0) {
    punit->hp = 0;
  }

  punit->moved = false;
  punit->paradropped = false;
}
