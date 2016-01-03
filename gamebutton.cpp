#include <QtGui>
#include "gamebutton.h"

GameButton::GameButton(QString str,int w,int h,QWidget *parent) 
	: QPushButton(parent),imageName(str),width(w),length(h)
{  
	//初始化flag
	flag=false; 
	beSelected = false;
	if(w < 5 || h < 5) { w = 65; h = 85; }
	
	this->clearMask();
	this->setBackgroundRole(QPalette::Base);
	
	QPixmap pixmap;
	pixmap.load(imageName);
	buttonPixmap = pixmap.scaled(w,h,Qt::KeepAspectRatio);
	//设置按钮的图案
	this->setIcon(buttonPixmap);
	this->setIconSize(QSize(buttonPixmap.width(),buttonPixmap.height()));
}

//每当按钮被点击后，触发此槽发出按钮的坐标信号
void GameButton::save()
{
	beSelected = true;
	
	emit click(get_x(),get_y());
}

//每当按钮被点击后，此槽发出按钮的图片信息
void GameButton::sendSignal()
{
	emit send(get_image());
}

//设置按钮的图案但是不改变按钮图片的名称
void GameButton::set_image(const QString &str) { 
	QPixmap pixmap;
	pixmap.load(str);
	this->setIcon(pixmap);
}

void GameButton::isSelected() { 
	this -> setFlat(true);  
	this->setFocusPolicy(Qt::NoFocus);   
}