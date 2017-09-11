#include <QApplication>

#include "window.hh"
#include "history/history.hh"

int main(int argc, char *argv[]) {
	QApplication app(argc,argv);

    History::Init();
	
	Window window;
	window.showMaximized();
	
	return app.exec();
}
