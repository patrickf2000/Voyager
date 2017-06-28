#include <QApplication>
#include <QIcon>
#include <QWebEngineHistory>

#include "main_menu.hh"
#include "../tabpane.hh"

MainMenu::MainMenu() {
    historyMenu = new QMenu("History");

    clearHistory = new QAction("Clear History",this);
    quit = new QAction("Quit",this);

    quit->setIcon(QIcon::fromTheme("application-exit"));

    connect(clearHistory,&QAction::triggered,this,&MainMenu::onClearHistoryClicked);
    connect(quit,&QAction::triggered,qApp,&QApplication::exit);

    historyMenu->addAction(clearHistory);

    this->addMenu(historyMenu);
    this->addAction(quit);
}

MainMenu::~MainMenu() {
    delete historyMenu;
    delete clearHistory;
    delete quit;
}

void MainMenu::onClearHistoryClicked() {
    if (TabPane::currentView()==nullptr) {
        return;
    }
    TabPane::currentView()->webView()->history()->clear();
}
