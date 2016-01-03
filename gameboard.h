#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QLabel>
#include <QVector>
#include <QWidget>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include "gamebutton.h"
#include "control.h"
#include "linemap.h"

using namespace std;

class GameBoard : public QWidget
{
	Q_OBJECT;
public:
	GameBoard(int ,int, int,int,QWidget *parent=0);
	int get_rect() {return rectLength;}
	int getScore() { return finalScores;}
	void setScore(int s) { finalScores = s;}
	int getLevel() const { return currentLevel;}
	int getHeart() const {return heart;}
	int getHelp() const { return help;}
	
signals:
	//检查是否可以连接
	void check();
	//重播
	void redraw();
	//胜利
	void winGame(int);
	//失败
	void loseGame();
	//连线
	void linkLine();
	//按钮消失
	void hideButton();
	//开启继续菜单
	void enableContinue();
	//开启暂停菜单
	void enableStop();
	
	void exit();
	
	void updateStatus();
private slots:
	//暂停
	void stop();
	//继续游戏
	void onGame();
	//存储点击的按钮
	void addButtons(int,int);
	//更新游戏面板
	bool updateGameBoard();
	//重排
	void rearrange();
	//提示
	void giveHints();
	//储存游戏进度
	void saveAs();
	//载入文件记录
	void files();
	//随机奖励
	void randAward();
	
	void increase();
	
	void record(){isRecorded = true;}
	
	void playRecord();
	
	void changeBackground(const QString&);
	
	void changeMusic(int);
	
private:
	//改变按钮的图标
	void changeImage(int,int);
	//绘制地图
	void drawMap();
	//播放录制
	void display();
	//记载操作的流
	static QFile file;
	static QTextStream txtOutput;
	//是否需要回放
	bool flag;
	//播放还是录制
	bool isRecorded;
	//音乐开关
	bool isMusic;
	//初始化一些窗口常量
	void init();
	//添加按钮
	void drawButtons();
	//设置标签
	void setLabels();
	void setLabelPosition();
	//窗口上的各种标签
	QLabel *score;
	QLabel *hints;
	QLabel *lives;
	QLabel *hits;
	QLabel *award;
	//画线的图层
	Linemap *lines;
	//记录分数
	static int finalScores;
	//记录提示数
	static int help;
	//记录生命数
	static int heart;
	//图中总块数
	int sum;
	//控制类
	Control *gameManager;
	//添加到屏幕的按钮
	GameButton *button;
	//所有按钮存储的容器
	QVector <QVector<GameButton*> >gamebuttons;
	//被点击的按钮存储的地方
	QVector <GameButton*>clickedButtons;
	//两个图片库
	static QString images[];
	static QString images2[];
	//记录当前图形的图片数目
	int imagecnt;
	//记录当前图的按钮数的长宽
	int width;
	int length;
	//记录点击的按钮块数
	static int num;
	//一个计时器
	int myTimerId;

	//计时矩形的长宽
	int rectLength;
	int rectWidth;
	//背景色的RGB
	int red,green,blue;
	//用来画图的工具
	QPainter *paint;
	//记录当前的关卡数
	int currentLevel;
	//恢复点击了但没有被消除的块的图片
	void recovery();
	//画两个可以连接的块之间的线
	void drawLine();
	//记录点击的位置
	void recordPlace();
	//随机奖励的计时器
	QTimer *timer;
	//回放控制的计时器
	QTimer *t;
	//方便计算按钮坐标的常量
	int leftOffset;
	int upOffset;
protected:
	void timerEvent(QTimerEvent *event);
	void showEvent(QShowEvent *event);
	void hideEvent(QHideEvent *event);
	void paintEvent(QPaintEvent *);
};

#endif