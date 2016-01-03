#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include "gamebutton.h"

class FinalWindow : public QWidget
{
	Q_OBJECT;
public:
	FinalWindow();
	void set_message(QString str) {
	delete label;
	message = str;
	label = new QLabel(message,this);
	label->setGeometry(10,10,200,100);
	label->show();}
	void setDisable(){ next->hide();}

signals:
	void thisGame();
	void nextGame();
	void returnHome();

private slots:
	void goToHome();
	void replayGame();
	void goToGame();

private:
	QString message;
	GameButton *replay;
	GameButton *next;
	GameButton *home;
	QLabel *label;
};

#endif