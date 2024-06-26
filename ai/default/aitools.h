/**************************************************************************
 Copyright (c) 1996-2020 Freeciv21 and Freeciv contributors. This file is
 __    __          part of Freeciv21. Freeciv21 is free software: you can
/ \\..// \    redistribute it and/or modify it under the terms of the GNU
  ( oo )        General Public License  as published by the Free Software
   \__/         Foundation, either version 3 of the License,  or (at your
                      option) any later version. You should have received
    a copy of the GNU General Public License along with Freeciv21. If not,
                  see https://www.gnu.org/licenses/.
**************************************************************************/
#pragma once

// utility
#include "support.h" // bool type

// common
#include "fc_types.h"
#include "unit.h" // enum ai_unit_task

/* server/advisors */
#include "advgoto.h"

/* ai/default */
#include "aiunit.h"
#include "daicity.h"

class PFPath;
struct pf_parameter;
struct pft_amphibious;

const char *dai_unit_task_rule_name(const enum ai_unit_task task);
const char *dai_choice_rule_name(const struct adv_choice *choice);

int military_amortize(struct player *pplayer, struct city *pcity, int value,
                      int delay, int build_cost);
int stack_cost(struct unit *pattacker, struct unit *pdefender);

void dai_unit_move_or_attack(ai_type *ait, unit *punit, tile *ptile,
                             const PFPath &path, int step);

void dai_fill_unit_param(struct ai_type *ait, struct pf_parameter *parameter,
                         struct adv_risk_cost *risk_cost, struct unit *punit,
                         struct tile *ptile);
bool dai_gothere(struct ai_type *ait, struct player *pplayer,
                 struct unit *punit, struct tile *dst_tile);
struct tile *immediate_destination(struct unit *punit,
                                   struct tile *dest_tile);
void dai_log_path(struct unit *punit, const PFPath &path,
                  struct pf_parameter *parameter);
bool dai_unit_goto_constrained(struct ai_type *ait, struct unit *punit,
                               struct tile *ptile,
                               struct pf_parameter *parameter);
bool dai_unit_goto(struct ai_type *ait, struct unit *punit,
                   struct tile *ptile);
bool goto_is_sane(struct unit *punit, struct tile *ptile);

void dai_unit_new_task(struct ai_type *ait, struct unit *punit,
                       enum ai_unit_task task, struct tile *ptile);
void dai_unit_new_adv_task(struct ai_type *ait, struct unit *punit,
                           enum adv_unit_task task, struct tile *ptile);
bool dai_unit_make_homecity(struct unit *punit, struct city *pcity);
bool dai_unit_attack(struct ai_type *ait, struct unit *punit,
                     struct tile *ptile);
bool dai_unit_move(struct ai_type *ait, struct unit *punit,
                   struct tile *ptile);

void dai_government_change(struct player *pplayer, struct government *gov);
int dai_gold_reserve(struct player *pplayer);

bool dai_choose_role_unit(struct ai_type *ait, struct player *pplayer,
                          struct city *pcity, struct adv_choice *choice,
                          enum choice_type type, int role, int want,
                          bool need_boat);
void dai_build_adv_override(struct ai_type *ait, struct city *pcity,
                            struct adv_choice *choice);
bool dai_assess_military_unhappiness(struct city *pcity);

void dai_consider_plr_dangerous(struct ai_type *ait, struct player *plr1,
                                struct player *plr2,
                                enum override_bool *result);
