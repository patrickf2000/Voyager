#pragma once

#include <QWebEngineView>
#include <QString>

class WebView : public QWebEngineView {
    Q_OBJECT
public:
    explicit WebView(QString url);
    explicit WebView();
    void loadUrl(QString url);
private:
    bool tried = false;
    QString completeAddress(bool https, QString url);
private slots:
    void onLoadFinished(bool ok);
signals:
    void loadCompleted();
};
