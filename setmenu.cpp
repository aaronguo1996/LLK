#include <QtGui>
#include "setmenu.h"

SetMenu::SetMenu(QWidget *parent)
	:QWidget(parent)
{//按钮以结束对话框
	okButton = new QPushButton("OK");
	connect(okButton,SIGNAL(clicked()),this,SLOT(hide()));
	//四个按钮对应不同的背景设置
	bk_1 = new GameButton("../menu/1.jpg",100,30);
	connect(bk_1,SIGNAL(clicked()),bk_1,SLOT(sendSignal()));
	connect(bk_1,SIGNAL(send(const QString&)),this,SIGNAL(setBackground(const QString&)));
	bk_2 = new GameButton("../menu/2.jpg",30,30);
	connect(bk_2,SIGNAL(clicked()),bk_2,SLOT(sendSignal()));
	connect(bk_2,SIGNAL(send(const QString&)),this,SIGNAL(setBackground(const QString&)));
	bk_3 = new GameButton("../menu/3.jpg",30,30);
	connect(bk_3,SIGNAL(clicked()),bk_3,SLOT(sendSignal()));
	connect(bk_3,SIGNAL(send(const QString&)),this,SIGNAL(setBackground(const QString&)));
	bk_4 = new GameButton("../menu/4.jpg",30,30);
	connect(bk_4,SIGNAL(clicked()),bk_4,SLOT(sendSignal()));
	connect(bk_4,SIGNAL(send(const QString&)),this,SIGNAL(setBackground(const QString&)));
	
	QFont font;
	font.setPointSize(15);
	setLabel = new QLabel("SETTINGS");
	setLabel->setFont(font);
	music = new QLabel("Music:");
	bkLabel = new QLabel("BackGround:");
	bkLabel->setFont(font);
	//单选框设置音效的开关
	on = new QRadioButton("ON");
	on->setChecked(true);
	off = new QRadioButton("OFF");
	off->setChecked(false);
	
	QButtonGroup *buttonGroup = new QButtonGroup();
	
	buttonGroup->addButton(on,0);
	buttonGroup->addButton(off,1);
	connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonGroupChanged(int)));
	//通过智能布局，不过有点难看>……<
	QHBoxLayout *musicLayout = new QHBoxLayout;
	musicLayout->addWidget(music);
	musicLayout->addWidget(on);
	musicLayout->addWidget(off);
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(setLabel);
	mainLayout->addLayout(musicLayout);
	mainLayout->addWidget(bkLabel);
	mainLayout->addWidget(bk_1);
	mainLayout->addWidget(bk_2);
	mainLayout->addWidget(bk_3);
	mainLayout->addWidget(bk_4);
	mainLayout->addWidget(okButton);
	setLayout(mainLayout);
	setFixedSize(300,200);
}

void SetMenu::buttonGroupChanged(int id)
{	
	
	switch(id)
	{//如果是On就打开音乐，否则关闭音乐
	case 0:
		emit turnOnMusic(1);
		break;
	case 1:
		emit turnOnMusic(0);
		break;
	default:
		break;
	}
}
