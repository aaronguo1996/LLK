#include <QApplication>
#include <QFont>
#include <QSplashScreen>

#include "startwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc,argv);
	
	QSplashScreen *splash = new QSplashScreen;
	splash->setPixmap(QPixmap("../menu/llk.jpg"));
	splash->show();
	
	for(int i=0;i<1000;i++)
		splash->repaint();
		
	StartWindow *game = new StartWindow();
	game->show();
	QApplication::setStyle("windows");// "motif""windowsxp""plastique", "macintosh", , "plastique", , or "cde"
	QFont font("Times", 10, QFont::Bold); 
	app.setFont(font);
	
	splash->finish(game);
	delete splash;
	
	return app.exec();
}