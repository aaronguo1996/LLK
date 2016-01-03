#include <QtGui>

#include "finalwindow.h"

FinalWindow::FinalWindow()
{
	message = "";
	label = new QLabel(message,this);
	label->setGeometry(10,10,200,100);
	label->show();
	replay = new GameButton("../pictures/again.png",50,50,this);
	replay->setGeometry(100,150,40,40);
	next = new GameButton("../pictures/next.png",50,50,this);
	next->setGeometry(150,150,40,40);
	home = new GameButton("../pictures/home.png",50,50,this);
	home->setGeometry(200,150,40,40);

	connect(replay,SIGNAL(clicked()),this,SLOT(replayGame()));
	connect(next,SIGNAL(clicked()),this,SLOT(goToGame()));
	connect(home,SIGNAL(clicked()),this,SLOT(goToHome()));

	setFixedSize(300,200);
}

void FinalWindow::replayGame()
{
	emit thisGame();
}

void FinalWindow::goToGame()
{
	emit nextGame();
}

void FinalWindow::goToHome()
{
	emit returnHome();
}