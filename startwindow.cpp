#include "startwindow.h"

#include <QtGui>

using namespace std;

void initButton(GameButton *button,int x,int y,int l)
{
	//button->isSelected();
	button->setGeometry(x,y,l,l/rate);
	button->show();
}

StartWindow::StartWindow()
{
	myTimerId = 0;
	for(int i=0;i<6;i++)
		angle[i]=pi*60*i/180;
	width[0]=200;
	width[1]=250;
	a_length = 200;
	b_length = 100;
	a_offset = 350;
	b_offset = 350;
	
	mainwindow = new MainWindow(0);
	connect(mainwindow,SIGNAL(callHome()),this,SLOT(homeComes()));
	
	newButton = new GameButton("../menu/new game.png",sbuttonw,sbuttonh,this);
	initButton(newButton,x_position[0],y_position[0],width[0]);
	connect(newButton,SIGNAL(clicked()),this,SLOT(newGame()));
	
	exitButton = new GameButton("../menu/exit.png",sbuttonw,sbuttonh,this);
	initButton(exitButton,x_position[1],y_position[1],width[0]);
	connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
	
	continueButton = new GameButton("../menu/continue.png",sbuttonw,sbuttonh,this);
	initButton(continueButton,x_position[2],y_position[2],width[0]);
	connect(continueButton,SIGNAL(clicked()),this,SLOT(onGame()));
	
	adventureButton = new GameButton("../menu/condition.png",sbuttonw,sbuttonh,this);
	initButton(adventureButton,x_position[3],y_position[3],width[0]);
	
	traditionButton = new GameButton("../menu/adventure.png",sbuttonw,sbuttonh,this);
	initButton(traditionButton,x_position[4],y_position[4],width[0]);
	
	setButton = new GameButton("../menu/settings.png",sbuttonw,sbuttonh,this);
	initButton(setButton,x_position[5],y_position[5],width[0]);
	
	init();
	QPalette palette;
	palette.setBrush(QPalette::Window, Qt::black);
	this->setPalette(palette);
	
	QSound music("../sound/TinyGame.wav");
	music.play();
	setFixedSize(1000,800);
}

void StartWindow::init(){//为按钮注册事件
	newButton->installEventFilter(this);
	continueButton->installEventFilter(this);
	exitButton->installEventFilter(this);
	traditionButton->installEventFilter(this);
	adventureButton->installEventFilter(this);
	setButton->installEventFilter(this);
}

//系统监听器监听按钮对象
//鼠标进入，按钮变大，鼠标离开，按钮变小
bool StartWindow::eventFilter(GameButton *target, QEvent *e){	
	if(target == newButton){		
		if(e->type() == QEvent::Enter){
			target->resize(lbuttonw,lbuttonh);	
			target->setIcon(QIcon("../menu/new game+.png"));
			killTimer(myTimerId);	
			return true;
		}else if(e->type() == QEvent::Leave){		
			target->resize(sbuttonw,sbuttonh);	
			target->setIcon(QIcon("../menu/new game.png"));
			myTimerId = startTimer(100);		
			return true;				
		}
	}else if(target == continueButton){		
		if(e->type() == QEvent::Enter){
			target->resize(lbuttonw,lbuttonh);	
			target->setIcon(QIcon("../menu/continue+.png"));
			killTimer(myTimerId);	
			return true;
		}else if(e->type() == QEvent::Leave){		
			target->resize(sbuttonw,sbuttonh);	
			target->setIcon(QIcon("../menu/continue.png"));
			myTimerId = startTimer(100);		
			return true;				
		}
	}else if(target == exitButton){
		if(e->type() == QEvent::Enter){
			target->resize(lbuttonw,lbuttonh);	
			target->setIcon(QIcon("../menu/exit+.png"));
			killTimer(myTimerId);	
			return true;
		}else if(e->type() == QEvent::Leave){		
			target->resize(sbuttonw,sbuttonh);	
			target->setIcon(QIcon("../menu/exit.png"));
			myTimerId = startTimer(100);		
			return true;				
		}
	}else if(target == traditionButton){
		if(e->type() == QEvent::Enter){
			target->resize(lbuttonw,lbuttonh);	
			target->setIcon(QIcon("../menu/tradition+.png"));
			killTimer(myTimerId);	
			return true;
		}else if(e->type() == QEvent::Leave){		
			target->resize(sbuttonw,sbuttonh);	
			target->setIcon(QIcon("../menu/tradition.png"));
			myTimerId = startTimer(100);		
			return true;				
		}
	}else if(target == adventureButton){
		if(e->type() == QEvent::Enter){
			target->resize(lbuttonw,lbuttonh);	
			target->setIcon(QIcon("../menu/adventure+.png"));
			killTimer(myTimerId);	
			return true;
		}else if(e->type() == QEvent::Leave){		
			target->resize(sbuttonw,sbuttonh);	
			target->setIcon(QIcon("../menu/adventure.png"));
			myTimerId = startTimer(100);		
			return true;				
		}
	}else if(target == setButton){
		if(e->type() == QEvent::Enter){
			target->resize(lbuttonw,lbuttonh);	
			target->setIcon(QIcon("../menu/settings+.png"));
			killTimer(myTimerId);	
			return true;
		}else if(e->type() == QEvent::Leave){		
			target->resize(sbuttonw,sbuttonh);	
			target->setIcon(QIcon("../menu/settings.png"));
			myTimerId = startTimer(100);		
			return true;				
		}
	}
	return QWidget::eventFilter(target, e);
}

void StartWindow::timerEvent(QTimerEvent *event)
{
	if(event->timerId() == myTimerId){
		double r = 300;//旋转圆的半径
		for(int i=0;i<6;i++){
			angle[i]+=pi*1/180;//每次转动1°
		}
		//重新设置各个按钮的位置
		newButton->setGeometry(a_offset+r*cos(angle[0]),b_offset+r*sin(angle[0]),width[0],width[0]/rate);
		exitButton->setGeometry(a_offset+r*cos(angle[1]),b_offset+r*sin(angle[1]),width[0],width[0]/rate);
		continueButton->setGeometry(a_offset+r*cos(angle[2]),b_offset+r*sin(angle[2]),width[0],width[0]/rate);
		adventureButton->setGeometry(a_offset+r*cos(angle[3]),b_offset+r*sin(angle[3]),width[0],width[0]/rate);
		traditionButton->setGeometry(a_offset+r*cos(angle[4]),b_offset+r*sin(angle[4]),width[0],width[0]/rate);
		setButton->setGeometry(a_offset+r*cos(angle[5]),b_offset+r*sin(angle[5]),width[0],width[0]/rate);
		update();
	}else{
		QWidget::timerEvent(event);
	}
}

void StartWindow::showEvent(QShowEvent *)
{
	myTimerId = startTimer(100);//设置更新时间为100毫秒
}

void StartWindow::hideEvent(QHideEvent *)
{
	killTimer(myTimerId);//最后通过hide来结束计时器
	myTimerId = 0;
}
//新游戏
void StartWindow::newGame()
{
	delete mainwindow;
	mainwindow = new MainWindow(0);
	connect(mainwindow,SIGNAL(callHome()),this,SLOT(homeComes()));
	mainwindow->show();
	this->hide();
}
//回到开始界面
void StartWindow::homeComes()
{
	mainwindow->hide();
	this->show();
}
//继续上次的游戏
void StartWindow::onGame()
{
	QFile file("../file.txt");
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream txtOutput(&file);
	int mode;
	txtOutput >> mode;
	mainwindow = new MainWindow(mode);
	connect(mainwindow,SIGNAL(callHome()),this,SLOT(homeComes()));
	connect(this,SIGNAL(loadFile()),mainwindow,SIGNAL(loading()));
	mainwindow->show();
	this->hide();
	emit loadFile();
	file.close();
}
//关闭窗口的事件
void StartWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}