#include <iostream>

#include "webpage.hh"

QWebEnginePage *WebPage::createWindow(WebWindowType type) {
    if (type==QWebEnginePage::WebBrowserTab) {
        std::cout << "Tab" << std::endl;
    } else if (type==QWebEnginePage::WebBrowserWindow) {
        std::cout << "Window" << std::endl;
    }
}
