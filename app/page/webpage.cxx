#include <iostream>
#include <QWebEngineProfile>
#include <QDir>

#include "webpage.hh"
#include "../tabpane.hh"

WebPage::WebPage() {
    connect(this->profile(),SIGNAL(downloadRequested(QWebEngineDownloadItem*)),this,SLOT(onDownloadRequested(QWebEngineDownloadItem*)));
}

QWebEnginePage *WebPage::createWindow(WebWindowType type) {
    if (type==QWebEnginePage::WebBrowserTab) {
        TabPane::addNewTab();
        return TabPane::currentView()->webView()->page();
    } else if (type==QWebEnginePage::WebBrowserWindow) {
        std::cout << "Window" << std::endl;
    }
}

void WebPage::onDownloadRequested(QWebEngineDownloadItem *item) {
    QString path = QDir::homePath();
    path+="/Downloads";
    item->setPath(path);
    item->accept();
}
