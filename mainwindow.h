#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QLabel>
#include <QSound>

#include "gameboard.h"
#include "finalwindow.h"
#include "rank.h"
#include "setmenu.h"

#define easy_w 12
#define easy_h 7

class MainWindow : public QMainWindow
{
	Q_OBJECT;
public:
	MainWindow(int m);

protected:
	void closeEvent(QCloseEvent *event);

signals:
	void callHome();
	void finish();
	void save();
	void loading();

private slots:
	//void exit();
	void settings();
	void m_easy();
	void m_medium();
	void m_hard();
	void about();
	void newGame();
	void newNextGame();
	void showHome();
	void showWinWindow(int);
	void showLoseWindow();
	void setContinue();
	void saveMode();
	void showRank();
	void loadScores();
	void checkReasonable();

private:
	void createActions();
	void createMenus();
	void createArea();
	void connectSignals();

	GameBoard *gameArea;
	FinalWindow *winWindow;

	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *diffMenu;
	QMenu *helpMenu;

	QAction *newAction;
	QAction *vedioAction;
	QAction *playAction;
	QAction *stopAction;
	QAction *continueAction;
	QAction *giveupAction;
	QAction *exitAction;
	QAction *saveAction;
	QAction *setAction;
	QAction *easyAction;
	QAction *mediumAction;
	QAction *hardAction;
	QAction *hintAction;
	QAction *rearrangeAction;
	QAction *highScoreAction;
	QAction *aboutAction;
	QAction *aboutQtAction;

	QString winMessage;
	QString loseMessage;
	//排行榜
	Rank *rank;
	SetMenu *setting;
	//设置关数
	static int level;
	
	static int mode;
	enum Mode {easy,medium,hard};
};

#endif