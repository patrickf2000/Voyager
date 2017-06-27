#include "window.hh"
#include "page/webview.hh"

Window::Window() {
	this->setWindowTitle("Voyager");
	this->resize(600,500);

    WebView *view = new WebView();
    this->setCentralWidget(view);
}
