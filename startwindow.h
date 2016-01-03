#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <cmath>
#include "gamebutton.h"
#include "mainwindow.h"

#define rate 3 
#define pi 3.1415926
#define sbuttonw 200
#define sbuttonh 60
#define lbuttonw 300
#define lbuttonh 100

class StartWindow : public QWidget
{
	Q_OBJECT;
public:
	StartWindow();
	
signals:
	void loadFile();
	
protected:
	void timerEvent(QTimerEvent *event);
	void showEvent(QShowEvent *event);
	void hideEvent(QHideEvent *event);
	void closeEvent(QCloseEvent *event);

private slots:
	void newGame();
	void homeComes();
	void onGame();
	
private:
	MainWindow *mainwindow;
	int myTimerId;
	void init();
	bool eventFilter(GameButton *target,QEvent *e);

	GameButton *newButton;
	GameButton *exitButton;
	GameButton *setButton;
	GameButton *adventureButton;
	GameButton *traditionButton;
	GameButton *continueButton;
	int x_position[6];
	int y_position[6];
	int width[2];
	double angle[6];
	int a_length;
	int b_length;
	int a_offset;
	int b_offset;
};

#endif