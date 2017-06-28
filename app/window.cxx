#include <QIcon>

#include "window.hh"
#include "tabpane.hh"

Window::Window() {
	this->setWindowTitle("Voyager");
    this->setWindowIcon(QIcon::fromTheme("applications-internet"));
	this->resize(600,500);

    TabPane *tabs = new TabPane;
    this->setCentralWidget(tabs);
}
