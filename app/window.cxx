#include "window.hh"
#include "tabpane.hh"

Window::Window() {
	this->setWindowTitle("Voyager");
	this->resize(600,500);

    TabPane *tabs = new TabPane;
    this->setCentralWidget(tabs);
}
