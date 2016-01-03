#include <QtGui>

#include "linemap.h"

Linemap::Linemap(int x_1,int y_1,int x_2,int y_2,QWidget *parent)
	:QWidget(parent),x1(x_1),y1(y_1),x2(x_2),y2(y_2)
{
	leftOffset = 100;
	upOffset = 50;
	//控制画出的线显示的时间
	connect(&myTimerId,SIGNAL(timeout()),this,SLOT(hide()));
	myTimerId.start(100);
	this->setFixedSize(1000,800);
}

void Linemap::paintEvent(QPaintEvent *)
{
	QPainter *p = new QPainter;
	p->begin(this);
	p->setCompositionMode(QPainter::CompositionMode_Clear );
	p->setPen(QPen(Qt::green,10,Qt::SolidLine));
	p->drawLine(x1,y1,x2,y2);
	p->end();
}