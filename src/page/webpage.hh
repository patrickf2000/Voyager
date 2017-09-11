#pragma once

#include <QWebEnginePage>
#include <QWebEngineDownloadItem>

class WebPage : public QWebEnginePage {
    Q_OBJECT
public:
    WebPage();
protected:
    QWebEnginePage *createWindow(WebWindowType type);
private slots:
    void onDownloadRequested(QWebEngineDownloadItem *item);
};
