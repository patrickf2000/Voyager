#include <iostream>

#include "webpage.hh"
#include "../tabpane.hh"

QWebEnginePage *WebPage::createWindow(WebWindowType type) {
    if (type==QWebEnginePage::WebBrowserTab) {
        TabPane::addNewTab();
        return TabPane::currentView()->webView()->page();
    } else if (type==QWebEnginePage::WebBrowserWindow) {
        std::cout << "Window" << std::endl;
    }
}
