#include <QApplication>

#include "window.hh"

int main(int argc, char *argv[]) {
	QApplication app(argc,argv);
	
	Window window;
	window.showMaximized();
	
	return app.exec();
}
