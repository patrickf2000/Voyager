#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QTabWidget>

#include "page/page.hh"

class TabPane : public QFrame {
    Q_OBJECT
public:
    TabPane();
    ~TabPane();
    static void addNewTab();
    static void addNewTab(QString url);
    static TabPage *currentView();
private:
    QVBoxLayout *layout;
    static QTabWidget *tabs;
};
