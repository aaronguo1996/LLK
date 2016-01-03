#include <QtGui>

#include "mainwindow.h"
#include "gameboard.h"

int MainWindow::mode = MainWindow::easy;
int MainWindow::level = 0;

MainWindow::MainWindow(int m)
{	
	setting = new SetMenu();
	rank = new Rank();
	mode = m;
	createArea();
	createActions();
	createMenus();
	connectSignals();
	
	setWindowIcon(QIcon("../menu/smilestar.jpg"));
	setFixedSize(1000,800);
}
//创建整个窗口
void MainWindow::createArea()
{
	//初始化模式为简单模式
	gameArea = new GameBoard(easy_w+mode*2,easy_h+mode,mode,level);
	setCentralWidget(gameArea);
	winWindow = new FinalWindow();
	connect(gameArea,SIGNAL(winGame(int)),this,SLOT(showWinWindow(int)));
	connect(gameArea,SIGNAL(loseGame()),this,SLOT(showLoseWindow()));
	connect(gameArea,SIGNAL(enableContinue()),this,SLOT(setContinue()));
	connect(winWindow,SIGNAL(thisGame()),this,SLOT(newGame()));
	connect(winWindow,SIGNAL(nextGame()),this,SLOT(newNextGame()));
	connect(winWindow,SIGNAL(returnHome()),this,SLOT(showHome()));
	connect(this,SIGNAL(loading()),this,SLOT(loadScores()));
}
//连接窗口部件之间的信号与槽
void MainWindow::connectSignals()
{
	connect(stopAction,SIGNAL(triggered()),gameArea,SLOT(stop()));
	connect(continueAction,SIGNAL(triggered()),gameArea,SLOT(onGame()));
	connect(hintAction,SIGNAL(triggered()),gameArea,SLOT(giveHints()));
	connect(rearrangeAction,SIGNAL(triggered()),gameArea,SLOT(rearrange()));
	connect(this,SIGNAL(save()),gameArea,SLOT(saveAs()));
	connect(saveAction,SIGNAL(triggered()),this,SLOT(saveMode()));
	connect(this,SIGNAL(loading()),gameArea,SLOT(files()));
	connect(vedioAction,SIGNAL(triggered()),gameArea,SLOT(record()));
	connect(playAction,SIGNAL(triggered()),gameArea,SLOT(playRecord()));
	connect(gameArea,SIGNAL(exit()),this,SLOT(close()));
	connect(gameArea,SIGNAL(updateStatus()),this,SLOT(checkReasonable()));
	connect(setting,SIGNAL(turnOnMusic(int)),gameArea,SLOT(changeMusic(int)));
	connect(setting,SIGNAL(setBackground(const QString&)),gameArea,SLOT(changeBackground(const QString&)));
}
//创建窗口的多个操作
void MainWindow::createActions()
{	
	stopAction = new QAction(tr("&Stop"),this);
	stopAction->setStatusTip(tr("Stop your current game"));
	

	continueAction = new QAction(tr("&Continue"),this);
	continueAction->setStatusTip(tr("Continue your current game"));
	continueAction->setEnabled(false);
	
	vedioAction = new QAction(tr("&Video"),this);
	vedioAction->setStatusTip(tr("record your excellent game play"));
	
	playAction = new QAction(tr("&Play"),this);
	playAction->setStatusTip(tr("play your recorded video"));
	
	saveAction = new QAction(tr("&Save"),this);
	saveAction->setStatusTip(tr("Save your current game"));
	
	giveupAction = new QAction(tr("&Give up"),this);
	giveupAction->setStatusTip(tr("Give up your current game"));
	connect(giveupAction,SIGNAL(triggered()),this,SLOT(showHome()));
	giveupAction->setEnabled(true);

	exitAction = new QAction(tr("E&xit"),this);
	exitAction->setStatusTip(tr("Exit the application"));
	connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
	
	setAction = new QAction(tr("Se&ttings"),this);
	setAction->setStatusTip(tr("Change some settings of the game"));
	connect(setAction,SIGNAL(triggered()),this,SLOT(settings()));

	easyAction = new QAction(tr("&Easy"),this);
	easyAction->setStatusTip(tr("Change into the easy model"));
	connect(easyAction,SIGNAL(triggered()),this,SLOT(m_easy()));

	mediumAction = new QAction(tr("&Medium"),this);
	mediumAction->setStatusTip(tr("Change into the medium model"));
	connect(mediumAction,SIGNAL(triggered()),this,SLOT(m_medium()));

	hardAction = new QAction(tr("&Hard"),this);
	hardAction->setStatusTip(tr("Change into the hard model"));
	connect(hardAction,SIGNAL(triggered()),this,SLOT(m_hard()));
	
	hintAction = new QAction(tr("&Hint"),this);
	hintAction->setStatusTip(tr("Give you some hints"));
	
	rearrangeAction = new QAction(tr("&Rearrange"),this);
	rearrangeAction->setStatusTip(tr("Rearrange your current gameboard"));
	
	highScoreAction = new QAction(tr("&High Score"),this);
	highScoreAction->setStatusTip(tr("Check your high scores"));
	connect(highScoreAction,SIGNAL(triggered()),this,SLOT(showRank()));

	aboutAction = new QAction(tr("About &LinkGame"),this);
	aboutAction->setStatusTip(tr("Show the LinkGame About box"));
	connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));

	aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
	connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}
//创建菜单栏
void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	diffMenu = fileMenu->addMenu(tr("&NewGame"));
	diffMenu->addAction(easyAction);
	diffMenu->addAction(mediumAction);
	diffMenu->addAction(hardAction);
	fileMenu->addAction(stopAction);
	fileMenu->addAction(continueAction);
	fileMenu->addAction(vedioAction);
	fileMenu->addAction(playAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(giveupAction);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);
	
	editMenu = menuBar()->addMenu(tr("&Edit"));
	editMenu->addAction(setAction);
	editMenu->addAction(hintAction);
	editMenu->addAction(highScoreAction);
	editMenu->addAction(rearrangeAction);
	
	menuBar()->addSeparator();

	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAction);
	helpMenu->addAction(aboutQtAction);
}
//设置槽的实现
void MainWindow::settings()
{
	setting->show();
}

void MainWindow::setContinue()
{
	if(continueAction->isEnabled()){
		continueAction->setEnabled(false);
		stopAction->setEnabled(true);
	}else{
		continueAction->setEnabled(true);
		stopAction->setEnabled(false);
	}
}
//重新开始游戏
void MainWindow::newGame()
{	
	winWindow->hide();
	delete gameArea;
	createArea();
	connectSignals();
}
//下一关
void MainWindow::newNextGame()
{
	winWindow->hide();
	int temp = gameArea->getScore();
	delete gameArea;
	level++;
	createArea();
	connectSignals();
	gameArea->setScore(temp);
}
//简单模式
void MainWindow::m_easy()
{
	delete gameArea;
	mode = MainWindow::easy;
	createArea();
	connectSignals();
	gameArea->setScore(0);
}
//中等模式
void MainWindow::m_medium()
{
	delete gameArea;
	mode = MainWindow::medium;
	createArea();
	connectSignals();
	gameArea->setScore(0);
}
//困难模式
void MainWindow::m_hard()
{
	delete gameArea;
	mode = MainWindow::hard;
	createArea();
	connectSignals();
	gameArea->setScore(0);
}
//关于连连看游戏的一些信息
void MainWindow::about()
{
	QMessageBox::about(this, tr("About LinkGame"),
            tr("<h2>LinkGame 2.0</h2>"
               "<p>Copyright &copy; 2014 Aaron Guo"
               "<p>LinkGame is a small application that "
               "entertain you"));
}
//关闭窗口的事件
void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}
//胜利时显示提示窗口，并且将成绩计入排行榜文件中
void MainWindow::showWinWindow(int len)
{
	if(gameArea->getLevel()!=8){
		winWindow->set_message("Congratulations! You pass the match.\n"
						   "You get bonus "+QString::number(len,10)+" points.\n");
		winWindow->show();
	}else{
		winWindow->set_message("Congratulations! You pass all matches.\n"
						   "You get bonus "+QString::number(len,10)+" points.\n");
		winWindow->show();
		winWindow->setDisable();
	}
	rank->addScore(gameArea->getScore());
	QFile f("../rank.txt");
	f.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream txtOutput(&f);
	txtOutput << rank->getRanks(0)<<"\n"
			  << rank->getRanks(1)<<"\n"
			  << rank->getRanks(2)<<"\n";
	f.close();
}
//失败窗口与胜利窗口的差别是没有下一关按钮
void MainWindow::showLoseWindow()
{
	winWindow->set_message("Sorry! You haven't pass the match.\n");
	winWindow->setDisable();
	winWindow->show();
}
//回到开始页面
void MainWindow::showHome()
{
	gameArea->setScore(0);
	emit callHome();
	winWindow->hide();
}
//存档功能
void MainWindow::saveMode()
{
	QFile file("../file.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream txtOutput(&file);
	txtOutput << mode <<"\n";
	file.close();
	emit save();
}
//显示排行榜
void MainWindow::showRank()
{
	rank->show();
}
//载入排行榜分数
void MainWindow::loadScores()
{
	QFile file("../file.txt");
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream txtOutput(&file);
	int temp;
	txtOutput >> temp;
	txtOutput >> temp;
	rank->addScore(temp);
	txtOutput >> temp;
	rank->addScore(temp);
	txtOutput >> temp;
	rank->addScore(temp);
	
	file.close();
}
//检查是否可以使用提示或重排
void MainWindow::checkReasonable()
{
	if(gameArea->getHeart()==0)
		rearrangeAction->setEnabled(false);
	else if(gameArea->getHeart()>0)
		rearrangeAction->setEnabled(true);
	if(gameArea->getHelp()==0)
		hintAction->setEnabled(false);
	else if(gameArea->getHelp()>0)
		hintAction->setEnabled(true);
}