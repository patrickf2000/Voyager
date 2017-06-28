#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QToolBar>
#include <QToolButton>
#include <QString>

#include "webview.hh"
#include "addressbar.hh"

class TabPage : public QFrame {
    Q_OBJECT
public:
    explicit TabPage(QString url);
    explicit TabPage();
    ~TabPage();
    WebView *webView();
    QString pageTitle();
private:
    QVBoxLayout *layout;
    QToolBar *toolbar;
    AddressBar *addressBar;
    QToolButton *back, *forward, *reload;
    WebView *view;
private slots:
    void goBack();
    void goForward();
    void refreshPage();
    void onUrlSubmitted(QString url);
};
