#pragma once

#include <QWebEngineView>
#include <QString>

class WebView : public QWebEngineView {
    Q_OBJECT
public:
    explicit WebView(QString url);
    explicit WebView();
};
