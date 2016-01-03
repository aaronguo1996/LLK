#ifndef SETMENU_H
#define SETMENU_H

#include <QWidget>
#include <QRadioButton>
#include <QLabel>
#include <QFont>
#include "gamebutton.h"

class SetMenu : public QWidget
{
	Q_OBJECT;
public:
	SetMenu(QWidget *parent = 0);

signals:
	void turnOnMusic(int);
	void setBackground(const QString&);
	void change();
	
private slots:
	void buttonGroupChanged(int id);
	
private:
	QRadioButton *on;
	QRadioButton *off;
	QLabel *setLabel;
	QLabel *music;
	QLabel *musicOn;
	QLabel *musicOff;
	QLabel *bkLabel;
	GameButton *bk_1;
	GameButton *bk_2;
	GameButton *bk_3;
	GameButton *bk_4;
	QPushButton *okButton;
};

#endif