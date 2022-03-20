/**************************************************************************
 Copyright (c) 1996-2020 Freeciv21 and Freeciv contributors. This file is
 part of Freeciv21. Freeciv21 is free software: you can redistribute it
 and/or modify it under the terms of the GNU  General Public License  as
 published by the Free Software Foundation, either version 3 of the
 License,  or (at your option) any later version. You should have received
 a copy of the GNU General Public License along with Freeciv21. If not,
 see https://www.gnu.org/licenses/.
**************************************************************************/
#pragma once

// Qt
#include <QToolButton>
#include <QWidget>

class QHBoxLayout;
class QPixmap;

typedef void (*pfcn_bool)(bool);
typedef void (*pfcn)();

void top_bar_blink_end_turn(bool do_restore);
void top_bar_center_unit();
void top_bar_disable_end_turn(bool do_restore);
void top_bar_finish_turn(bool nothing);
void top_bar_indicators_menu();
void top_bar_rates_wdg(bool nothing);
void top_bar_right_click_diplomacy();
void top_bar_right_click_science();
void top_bar_left_click_science(bool nothing);
void top_bar_show_map(bool nothing);

/***************************************************************************
  Class representing single widget(icon) on top_bar
***************************************************************************/
class top_bar_widget : public QToolButton {
  Q_OBJECT

public:
  enum standards { SW_STD, SW_TAX, SW_INDICATORS };

  top_bar_widget(const QString &label, const QString &pg, pfcn_bool func,
                 standards type = SW_STD);
  ~top_bar_widget() override;
  int getPriority();
  QPixmap *get_pixmap();
  void paint(QPainter *painter, QPaintEvent *event);
  void setCustomLabels(const QString &);
  void setLabel(const QString &str);
  void setLeftClick(pfcn_bool func);
  void setRightClick(pfcn func);
  void setTooltip(const QString &tooltip);
  void setWheelDown(pfcn func);
  void setWheelUp(pfcn func);

  bool blink;
  bool keep_blinking;
  standards standard;
  QString page;
public slots:
  void sblink();
  void someSlot();

protected:
  void mousePressEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;

private:
  pfcn right_click;
  pfcn wheel_down;
  pfcn wheel_up;
  pfcn_bool left_click;
  QTimer *timer;
};

/***************************************************************************
  Freeciv21 top_bar
***************************************************************************/
class top_bar : public QWidget {
  Q_OBJECT

public:
  top_bar();
  ~top_bar() override;
  void addWidget(top_bar_widget *fsw);
  QList<top_bar_widget *> objects;

private:
  QHBoxLayout *layout;
};