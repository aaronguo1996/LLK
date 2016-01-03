#include "gameboard.h"
#include <QtGui>
#include <QBrush>
#include <QImage>
#include <iostream>
#include <QPalette>
#include <cstdlib>
#include <ctime>

using namespace std;

int GameBoard::num = 0;
int GameBoard::finalScores = 0;
int GameBoard::heart = 5;
int GameBoard::help = 3;

//为保证文件流能够每隔1秒从文件中读取一组数据，将文件流声明为静态常量
QFile GameBoard::file("../place.txt");
QTextStream GameBoard::txtOutput(&file);

void GameBoard::init()
{
	//计时器
	myTimerId = 0;

	//背景颜色的RGB控制
	red = 100;//255;0;
	green = 255;//255;
	blue = 100;//255;
	
	leftOffset = (1000 - button_w * (width+1))/2;
	upOffset = 50;
	sum = width * length;
	//得分标签
	score = new QLabel(this);
	
	//提示标签
	hints = new QLabel(this);
	
	//生命标签	
	lives = new QLabel(this);
	
	//关卡标签
	hits = new QLabel(this);
	
	//随机奖励标签
	award = new QLabel(this);
	
	//游戏后台控制
	gameManager = new Control(width+2,length+2);
	
	//默认不播放录像
	flag = false;
	
	//默认播放音效
	isMusic = true;
	
	//计时器的初始化
	timer = new QTimer;
	timer->start(30000);
	connect(timer,SIGNAL(timeout()),this,SLOT(randAward()));
	
	//设置背景颜色
	this->setAutoFillBackground(true);
	QPalette bgpal =  palette();
	bgpal.setColor (QPalette::Window, QColor (red,blue,green));
	this->setPalette(bgpal);
	
	//定义时间进度条的长宽
	rectLength = 500;
	rectWidth = 30;
	
	//设置窗口大小
	setFixedSize(1000,800);
}

void GameBoard::increase()
{
	display();
}

void GameBoard::playRecord()
{
	file.open(QIODevice::ReadOnly);
	t = new QTimer;
	t->start(1000);
	connect(t,SIGNAL(timeout()),this,SLOT(increase()));
}

void GameBoard::drawButtons()
{
	//随机打乱数组，以获得随机图片组
	int pictures[sum];
	imagecnt = sum/4;
	gameManager->randomPictures(pictures,imagecnt);
	for(int i = 0;i < width;i++){
		QVector<GameButton*>cards;
		for(int j = 0; j < length;j++){
			button = new GameButton(images[pictures[i*length+j]],button_w,button_h,this);
			//设置按钮坐标
			button->set_x(i+1);
			button->set_y(j+1);
			button->setGeometry(leftOffset+(i+1)*button_w,upOffset+(j+1)*button_h,button_w,button_h);
			button->show();
			//存储按钮进入一维容器
			cards.append(button);
			//将点击信号与存储信号关联
			connect(button,SIGNAL(clicked()),button,SLOT(save()));
			//点击后发射按钮坐标，存储相应的按钮
			connect(button,SIGNAL(click(int,int)),this,SLOT(addButtons(int,int)));
			//点击满两个按钮之后检测是否可以连接
			connect(this,SIGNAL(check()),this,SLOT(updateGameBoard()));
			//实现重播功能
			connect(this,SIGNAL(redraw()),button,SLOT(save()));
		}
		//将一维容器存储成二维容器
		gamebuttons.append(cards);
	}
	//可以连接后会发射连线信号
	connect(this,SIGNAL(linkLine()),this,SLOT(createLine()));
	connect(this,SIGNAL(hideButton()),this,SLOT(deleteButton()));
}

void GameBoard::setLabels(){
	score->setText("Score:"+QString::number(finalScores,10));
	hints->setText("Hints:"+QString::number(help,10));
	lives->setText("Lives:"+QString::number(heart,10));
	hits->setText("Hits:"+QString::number(currentLevel,10));
	setLabelPosition();
}

void GameBoard::setLabelPosition(){
//设置标签的位置和字体大小
	QFont font;
	font.setPointSize(15);
	score->setGeometry(10,10,100,30);
	score->setFont(font);
	hints->setGeometry(800,10,80,30);
	hints->setFont(font);
	lives->setGeometry(900,10,80,30);
	lives->setFont(font);
	hits->setGeometry(150,10,60,30);
	hits->setFont(font);
	award->setGeometry(300,50,800,30);
	award->setFont(font);
}

GameBoard::GameBoard(int w,int h,int count,int l,QWidget *parent)
	:QWidget(parent),imagecnt(count),width(w),length(h),currentLevel(l)
{
	init();
	drawButtons();
	setLabels();
}

//载入图片时用到的图形库
QString GameBoard::images2[] =
			{"../animals/01.png","../animals/02.png","../animals/03.png","../animals/04.png","../animals/05.png","../animals/06.png",
			 "../animals/07.png","../animals/08.png","../animals/09.png","../animals/10.png","../animals/11.png","../animals/12.png",
			 "../animals/13.png","../animals/14.png","../animals/15.png","../animals/16.png","../animals/17.png","../animals/18.png",
			 "../animals/19.png","../animals/20.png","../animals/21.png","../animals/22.png","../animals/23.png","../animals/24.png",
			 "../animals/25.png","../animals/26.png","../animals/27.png","../animals/28.png","../animals/29.png","../animals/30.png",
			 "../animals/31.png","../animals/32.png","../animals/33.png","../animals/34.png","../animals/35.png","../animals/36.png"};
QString GameBoard::images[] =
	   {"../animals/001.png","../animals/002.png","../animals/003.png","../animals/004.png","../animals/005.png","../animals/006.png",
		"../animals/007.png","../animals/008.png","../animals/009.png","../animals/010.png","../animals/011.png","../animals/012.png",
		"../animals/013.png","../animals/014.png","../animals/015.png","../animals/016.png","../animals/017.png","../animals/018.png",
		"../animals/019.png","../animals/020.png","../animals/021.png","../animals/022.png","../animals/023.png","../animals/024.png",
		"../animals/025.png","../animals/026.png","../animals/027.png","../animals/028.png","../animals/029.png","../animals/030.png",
	   "../animals/031.png","../animals/032.png","../animals/033.png","../animals/034.png","../animals/035.png","../animals/036.png"};

//点击按钮之后，储存连续点击的两个按钮
void GameBoard::addButtons(int i,int j)
{
	if(isMusic) QSound::play("../sound/touch.wav");
	changeImage(i,j);
	clickedButtons.append(gamebuttons[i-1][j-1]);
	num++;
	if(num==2){
		emit check();
	}
}

//每当点击的两个块不能消除时，恢复前一个物块为未点击状态，后一个物块为第一个点击的状态
void GameBoard::recovery()
{
	for(int k=0;k<maxElements;k++){
		if(clickedButtons[0]->get_image()==images[k]){
			clickedButtons[0]->set_image(images[k]);
			break;
		}
	}
	GameButton *t_button = clickedButtons[1];
	clickedButtons.clear();
	clickedButtons.append(t_button);
	num = 1;

}

bool GameBoard::updateGameBoard()
{
	int place = num / 2;
	if(num==2){
		//判断点击的两个图块的图片是否相同
		if(!gameManager->is_same_picture(clickedButtons[place*2-2]->get_image(),clickedButtons[place *2-1]->get_image())){
			recovery();
			return false;
		}
		//判断点击的两个图块是否可以连接
		if(!gameManager->isLinkable(clickedButtons[place*2-2]->get_x(),clickedButtons[place*2-2]->get_y(),clickedButtons[place*2-1]->get_x(),clickedButtons[place*2-1]->get_y())){
			recovery();
			return false;
		}
		drawLine();
		if(isMusic)  QSound::play("../sound/pair.wav");
		clickedButtons[0]->hide();
		clickedButtons[1]->hide();
		clickedButtons.clear();
		num = 0;
		
		//记录消除后的分数
		finalScores+=10;
		//获得一定的时间奖励
		if(rectLength <= 500)
		rectLength+=5;
		QString str="Score:"+QString::number(finalScores,10);
		QPalette pe;
		score->setText(str);
		
		//根据当前关卡的情况设置剩下的图块的移动情况
		gameManager->setLevel(currentLevel,gamebuttons);
		//视情况是否录制
		if(isRecorded)
			recordPlace();
		//检查是否是僵局
		gameManager->isDead(gamebuttons);
		
		return true;
	}

}

void GameBoard::drawLine()
{
	//记录两个图块的坐标
	int x1 = clickedButtons[0]->get_x();
	int y1 = clickedButtons[0]->get_y();
	int x2 = clickedButtons[1]->get_x();
	int y2 = clickedButtons[1]->get_y();
	//在二维数组中将消去的图块的坐标变为零
	gameManager->pos[x1][y1] = 0;
	gameManager->pos[x2][y2] = 0;
	//如果连线过程中只有一个拐点，只要将拐点与两个顶点分别连线
	if(gameManager->getCorner() == 1){
		int x3 = gameManager->getPoints(0);
		int y3 = gameManager->getPoints(1);
		lines = new Linemap(leftOffset+(x1+0.5)*button_w,upOffset+(y1+0.5)*button_h,
							leftOffset+(x3+0.5)*button_w,upOffset+(y3+0.5)*button_h,this);
		lines->show();
		Linemap *lines1 = new Linemap(leftOffset+(x3+0.5)*button_w,upOffset+(y3+0.5)*button_h,
					leftOffset+(x2+0.5)*button_w,upOffset+(y2+0.5)*button_h,this);
		lines1->show();
	//如果连线中有两个拐点，可分别获得两个拐点的坐标并连线
	}else if(gameManager->getCorner() == 2){
		int x3 = gameManager->getPoints(0);
		int y3 = gameManager->getPoints(1);
		int x4 = gameManager->getPoints(2);
		int y4 = gameManager->getPoints(3);
		lines = new Linemap(leftOffset+(x1+0.5)*button_w,upOffset+(y1+0.5)*button_h,
							leftOffset+(x3+0.5)*button_w,upOffset+(y3+0.5)*button_h,this);
		lines->show();
		Linemap *lines1 = new Linemap(leftOffset+(x3+0.5)*button_w,upOffset+(y3+0.5)*button_h,
									  leftOffset+(x4+0.5)*button_w,upOffset+(y4+0.5)*button_h,this);
		lines1->show();
		Linemap *lines2 = new Linemap(leftOffset+(x4+0.5)*button_w,upOffset+(y4+0.5)*button_h,
									  leftOffset+(x2+0.5)*button_w,upOffset+(y2+0.5)*button_h,this);
		lines2->show();
	//如果没有拐点
	}else if(gameManager->getCorner() == 0){
		lines = new Linemap(leftOffset+(x1+0.5)*button_w,upOffset+(y1+0.5)*button_h,
							leftOffset+(x2+0.5)*button_w,upOffset+(y2+0.5)*button_h,this);
		lines->show();
	}
}
//绘制记录时间的进度条
void GameBoard::paintEvent(QPaintEvent *)
{	
	paint = new QPainter;
	int temp = 500;
	//绘制一个矩形外框
	paint->begin(this);
	paint->setPen(QPen(Qt::blue,2,Qt::SolidLine));
	paint->drawRect(260,8,temp,rectWidth);
	paint->end();
	//绘制一个有填充的矩形
	paint->begin(this);
	paint->setBrush(QBrush(Qt::red,Qt::SolidPattern));
	paint->drawRect(260,8,rectLength,rectWidth);
	paint->end();
}

//每隔一定的时间后，矩形长度缩短，并检查游戏是否结束，是否已出现输赢
void GameBoard::timerEvent(QTimerEvent *event)
{
	if(event->timerId() == myTimerId){	
		if(rectLength!=0)
			rectLength--;
		
		if(gameManager->win(rectLength)==true){
			killTimer(myTimerId);
			finalScores+=get_rect()*2;
			emit winGame(get_rect()*2);
		}
		//除了时间到没完全消除外，生命值没有也算失败
		if(gameManager->lose(rectLength)==true || heart == 0){
			killTimer(myTimerId);
			emit loseGame();
		}
		update();
	}else{
		QWidget::timerEvent(event);
	}
}

void GameBoard::showEvent(QShowEvent *)
{
	myTimerId = startTimer(500);//计时器设置为500毫秒刷新一次
}

void GameBoard::hideEvent(QHideEvent *)
{
	killTimer(myTimerId);//终止计时器
	myTimerId = 0;
}

void GameBoard::stop()
{
	killTimer(myTimerId);//暂停计时器
	for(int i=0;i<width;i++)//游戏暂停时为保证游戏可玩性，将所有的块都隐藏
		for(int j =0;j<length;j++)
			if(gameManager->pos[i+1][j+1])
				gamebuttons[i][j]->hide();
	emit enableContinue();//同时关闭暂停操作，恢复继续操作
}

void GameBoard::onGame()
{
	myTimerId = startTimer(500);//重启计时器
	for(int i=0;i<width;i++){
		for(int j =0;j<length;j++){//游戏继续时，所有的块重新出现，同时恢复暂停操作
			if(gameManager->pos[i+1][j+1])
				gamebuttons[i][j]->show();
		}
	}
	emit enableContinue();
}

//重排操作，每重排一次，生命值减一
void GameBoard::rearrange()
{
	gameManager->rearrange(gamebuttons);
	heart-=1;
	lives->setText("Lives:"+QString::number(heart,10));
	emit updateStatus();//检验此时是否还有生命值，关闭rearrange操作
}

//提示操作，每提示一次，提示值减一
void GameBoard::giveHints()
{
	gameManager->hint(gamebuttons,images,images2);
	help-=1;
	hints->setText("Hints:"+QString::number(help,10));
	emit updateStatus();//检验提示使用之后是否还可以使用提示操作
}

//点击按钮之后，按钮出现被点击的记号
void GameBoard::changeImage(int i,int j)
{
	for(int k=0;k<maxElements;k++){
		if(gamebuttons[i-1][j-1]->get_image()==images[k]){
			gamebuttons[i-1][j-1]->set_image(images2[k]);
			return;
		}
	}
}
//随机产生一些奖惩，并对所影响的参数作出相应的调整
void GameBoard::randAward()
{
	srand(time(NULL));
	int temp = rand() % 10;
	award->setText(gameManager->getRandomMessage(temp));
	switch(temp)
	{
	case 0:
		help+=2;
		break;
	case 1:
		rectLength+=5;
		break;
	case 2:
		heart+=1;
		break;
	case 3:
		heart+=3;
		break;
	case 4:
		rectLength+=10;
		break;
	case 5:
		if(help>=1)
		help-=1;
		break;
	case 6:
		if(rectLength>=10)
		rectLength-=10;
		break;
	case 7:
		if(heart>=1)
			heart-=1;
		break;
	case 8:
		if(help>=3)
			help-=3;
		break;
	case 9:
		if(rectLength>=5)
			rectLength-=5;
		break;
	}
	hints->setText("Hints:"+QString::number(help,10));
	lives->setText("Lives:"+QString::number(heart,10));
	emit updateStatus();
	update();
}
//录制过程，记录每次消除之后的其他块的位置和此时的时间（即矩形条长度）
void GameBoard::recordPlace()
{
	QFile file("../place.txt");
	if(!file.open(QIODevice::WriteOnly |QIODevice::Text | QIODevice::Append ))
	{
		cout << "Open failed." << endl;
		return;
	}

	QTextStream txtOutput(&file);
	
	txtOutput<<rectLength<<"\n";
	for(int i=0;i<width;i++){
		for(int j =0;j<length;j++){
			if(gameManager->pos[i+1][j+1])
				txtOutput << "1"<<"\n" << gamebuttons[i][j]->get_image()<<"\n";
			else 
				txtOutput << "0"<<"\n";
		}
	}
	file.close();
}
//重现录制的过程
void GameBoard::display()
{
	if(! txtOutput.atEnd()){
		QString str;

		txtOutput>>rectLength;
		for(int i=0;i<width;i++){
			for(int j =0;j<length;j++){
				txtOutput>>gameManager->pos[i+1][j+1];
				if(gameManager->pos[i+1][j+1]){
					gamebuttons[i][j]->show();
					txtOutput>>str;
					gamebuttons[i][j]->set_image(str);
					gamebuttons[i][j]->set_name(str);
				}else{ 
					gamebuttons[i][j]->hide();
				}
			}
		}
		update();
	}else{
		file.close();
		emit exit();
	}
}
//对游戏进行存档，存储所有需要记录的数据
void GameBoard::saveAs()
{
	QFile file("../file.txt");
	if(!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
	{
		cout << "Open failed." << endl;
		return;
	}

	QTextStream txtOutput(&file);
	txtOutput << width <<"\n"<<length<<"\n";
	txtOutput << score->text() <<"\n";
	txtOutput << hits->text() <<"\n";
	txtOutput << hints->text() <<"\n";
	txtOutput << lives->text() <<"\n";
	txtOutput << rectLength << "\n";
	txtOutput << currentLevel <<"\n";
	txtOutput << finalScores << "\n";
	txtOutput << help << "\n"<<heart<<"\n";
	
	for(int i=0;i<width;i++){
		for(int j =0;j<length;j++){
			if(gameManager->pos[i+1][j+1])
				txtOutput << "1"<<"\n" << gamebuttons[i][j]->get_image()<<"\n";
			else 
				txtOutput << "0"<<"\n";
		}
	}
	file.close();
	emit exit();
}
//对存档的游戏进行重新载入，使得可以实现继续游戏
void GameBoard::files()
{
	QFile file("../file.txt");
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream txtOutput(&file);
	int temp;
	txtOutput >> temp;
	txtOutput >> width >>length;
	QString str;
	txtOutput >> str;
	score->setText(str);
	txtOutput >> str;
	hits->setText(str); 
	txtOutput >> str; 
	hints->setText(str);
	txtOutput >> str;
	lives->setText(str);
	
	setLabelPosition();
	
	txtOutput >> rectLength;
	txtOutput >> currentLevel;
	txtOutput >> finalScores;
	txtOutput >> help >> heart;

	for(int i=0;i<width;i++){
		for(int j =0;j<length;j++){
			txtOutput>>gameManager->pos[i+1][j+1];
			if(gameManager->pos[i+1][j+1]){
				gamebuttons[i][j]->show();
				txtOutput>>str;
				gamebuttons[i][j]->set_image(str);
				gamebuttons[i][j]->set_name(str);
			}else{ 
				gamebuttons[i][j]->hide();
			}
		}
	}
	file.close();
	update();
}
//关闭或开启音效
void GameBoard::changeMusic(int p)
{
	if(p==0)
	isMusic = false;
	else isMusic = true;
}
//更换皮肤或壁纸
void GameBoard::changeBackground(const QString& str)
{
	QPixmap pm(str);
	pm = pm.scaled(1000,800,Qt::IgnoreAspectRatio);
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Window, QBrush(pm));
	this->setPalette(palette);
	
}