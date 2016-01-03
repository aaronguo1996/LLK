#ifndef CONTROL_H
#define CONTROL_H
#include <QPixmap>
#include <QVector>
#include "gamebutton.h"

#define maxElements 36

class Control
{
public:
	Control(int w,int l);
	//一张二维数组来记录按钮的出现和隐藏情况
	int pos[20][20];
	//判断两个位置的块能否连接
	bool isLinkable(int x1,int y1,int x2, int y2);
	//判断点击的两个块的图片是否相同
	bool is_same_picture(QString pic1, QString pic2);
	//将图片打乱顺序且保证每张图片出现4次
	void randomPictures(int *a,int max);
	//重排所有的块
	void rearrange(QVector<QVector<GameButton *> >gamebuttons);
	//提示
	void hint(QVector<QVector<GameButton *> >gamebuttons,QString*,QString*);
	//判断是否胜利
	bool win(int len);
	//判断是否失败
	bool lose(int len);
	//获得在判断成功连接后的拐点的坐标
	int getPoints(int i) const { return points[i]; }
	//获取拐点数
	int getCorner() { return cornerPoint; }
	//根据关卡数设置相应的物块移动
	void setLevel(int nLevel,QVector<QVector<GameButton *> >gamebuttons);
	//判断是否僵局
	bool isDead(QVector<QVector<GameButton *> >gamebuttons);
	//一组奖惩信息
	QString getRandomMessage(int i);
	
private:
	int width;
	int length;
	//拐点数目
	int cornerPoint;
	//包括起点、拐点的位置坐标的数组
	int points[4];

	//跳过所有的空白找到最近的块（行与列分开）
	int findBlank(int k,int x,int y);
	int findRowBlank(int k,int x,int y);
	void setupRandomArray(int *a,int max);
	//找到两个点是否存在交点可以连接
	bool findInteractPoint(int &x1,int &y1,int &x2,int &y2);
	//检验直线连接
	bool check_none_corner(int x1,int y1,int x2,int y2);
	//检验没有拐点的连接
	bool check_zero_corner(int x1,int y1,int x2,int y2);
	//检验有一个拐点的连接
	bool check_one_corner(int x1,int y1,int x2,int y2);
	//检验有两个拐点的连接
	bool check_two_corner(int x1,int y1,int x2,int y2);
	//检验是否点击的是两个不同的物块
	bool is_double_button(int x1,int y1,int x2,int y2);
	//向下移动
	void moveDown(QVector<QVector<GameButton *> >gamebuttons,int startRow,int endRow,int startColumn,int endColumn);
	//向上移动
	void moveUp(QVector<QVector<GameButton *> >gamebuttons,int startRow,int endRow,int startColumn,int endColumn);
	//向左移动
	void moveLeft(QVector<QVector<GameButton *> >gamebuttons,int startRow,int endRow,int startColumn,int endColumn);
	//向右移动
	void moveRight(QVector<QVector<GameButton *> >gamebuttons,int startRow,int endRow,int startColumn,int endColumn);
	static QString messages[10];
};

#endif