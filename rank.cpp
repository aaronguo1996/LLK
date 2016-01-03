#include <QtGui>
#include <QPixmap>
#include <QPalette>
#include "rank.h"

Rank::Rank(QWidget *parent)
	:QWidget(parent)
{//从文件读取相应的值来初始化
	QFile f("../rank.txt");
	f.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream txtOutput(&f);
	txtOutput >>highScores[0]>>highScores[1]>>highScores[2];
	f.close();
	highScores[3] = 0;
	QPixmap pm("../pictures/rank.jpg");
	QPalette palette = this->palette();
	palette.setBrush(backgroundRole(), QBrush(pm));
	setPalette(palette);
	first = new QLabel(this);
	first->setGeometry(100,50,200,30);
	second = new QLabel(this);
	second->setGeometry(100,100,200,30);
	third = new QLabel(this);
	third->setGeometry(100,150,200,30);
	setLabels();
	
	setFixedSize(300,250);
}

void Rank::setLabels()
{
	QFont font;
	font.setPointSize(15);
	first->setText("GOLD:"+QString::number(highScores[0],10));
	first->setFont(font);
	second->setText("SILVER:"+QString::number(highScores[1],10));
	second->setFont(font);
	third->setText("BRONZE:"+QString::number(highScores[2],10));
	third->setFont(font);
}

int Rank::getRanks(int i)
{
	if(i>2)  return 0;
	return highScores[i];
}
//每次增加新的分数后比较之后再更新
void Rank::addScore(int i)
{
	highScores[3] = i;
	sort();
	setLabels();
}
//对排行榜中的数据进行排序操作
void Rank::sort()
{
	int max = highScores[0];
	int mid = max;
	int min = mid;
	for(int i=1;i<4;i++){
		if(max <= highScores[i])
			max = highScores[i];
		else if(min >= highScores[i])
			min = highScores[i];
	}
	for(int i=0;i<3;i++){
		if(highScores[i]!=max && highScores[i] != min)
			mid = highScores[i];
	}
	highScores[0] = max;
	highScores[1] = mid;
	highScores[2] = min;
}