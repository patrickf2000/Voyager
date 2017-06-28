#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPushButton>

#include "page/page.hh"

class TabPane : public QFrame {
    Q_OBJECT
public:
    TabPane();
    ~TabPane();
    static void addNewTab();
    static void addNewTab(QString url);
    static TabPage *currentView();
    static void setCurrentTabTitle(QString title);
private:
    QVBoxLayout *layout;
    static QTabWidget *tabs;
    QPushButton *newTab;
private slots:
    void onTabCloseRequested(int index);
    void onNewTabClicked();
};
