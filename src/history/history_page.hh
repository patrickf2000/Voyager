#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QToolBar>
#include <QListWidget>
#include <QToolButton>

#include "../page/webview.hh"

class HistoryPage : public QFrame {
    Q_OBJECT
public:
    explicit HistoryPage();
    ~HistoryPage();
private:
    QVBoxLayout *layout;
    QToolBar *toolbar;
    QListWidget *historyList;
    QToolButton *clear;
    void loadHistory();
private slots:
    void onClearClicked();
};
