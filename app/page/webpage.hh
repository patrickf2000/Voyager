#pragma once

#include <QWebEnginePage>

class WebPage : public QWebEnginePage {
    Q_OBJECT
protected:
    QWebEnginePage *createWindow(WebWindowType type);
};
