#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QWidget>

const int button_w = 50;
const int button_h = 60;

class QPushButton;

class GameButton : public QPushButton//public QWidget , 
{
	Q_OBJECT;
public:
	GameButton(QString str,int w, int h,QWidget *parent = 0);
	//~GameButton();
	void set_x(int i){ x = i;}
	void set_y(int i){ y = i;}
	int get_width() { return width; }
	int get_length() { return length; } 
	int get_x() { return x; }
	int get_y() { return y; }
	void isSelected();
	void set_image(const QString &str);
	void set_name(const QString &str) { imageName = str; }
	QString get_image() { return imageName;}
	QPixmap get_pix() { return buttonPixmap;}
	
signals:
	void click(int,int);
	void send(const QString&);
	
private slots:
	//当鼠标单击时，会触发该信号.
	void save();
	void sendSignal();

private:
	//按钮的图片名
    QString imageName;
	//是否被选中
	bool beSelected;
	
    QPixmap buttonPixmap; 
	
	bool flag;
	//这个用来标示按钮的位置
	int x;
	int y;
	//记录按钮的长宽
	int width;
	int length;
};

#endif
