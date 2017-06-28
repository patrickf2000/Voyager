#pragma once

#include <QFrame>
#include <QVBoxLayout>

#include "../page/webview.hh"

class HistoryPage : public QFrame {
    Q_OBJECT
public:
    explicit HistoryPage(WebView *view);
    ~HistoryPage();
private:
    QVBoxLayout *layout;
};
