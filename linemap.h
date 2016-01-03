#ifndef LINEMAP_H
#define LINEMAP_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class Linemap : public QWidget
{
	Q_OBJECT;
public:
	Linemap(int,int,int,int,QWidget *parent = 0);

protected:
	void paintEvent(QPaintEvent *);
	
private:
	int x1,y1,x2,y2;
	QTimer myTimerId;
	int leftOffset;
	int upOffset;
};

#endif