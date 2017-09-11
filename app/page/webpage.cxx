#include <QWebEngineProfile>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <iostream>

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
    QString fileName = QFileInfo(item->path()).fileName();
    QFileDialog dialog;
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setWindowTitle("Choose a Folder");
    QString downloads = QDir::homePath()+"/Downloads";
    if (QDir(downloads).exists()) {
        dialog.setDirectory(downloads);
    }
    if (dialog.exec()) {
        if (dialog.selectedFiles().size()==0) {
            return;
        }
        QString path = dialog.selectedFiles().at(0);
        if (!path.endsWith("/")) {
            path+="/";
        }
        path+=fileName;
        item->setPath(path);
        item->accept();
    }
}
