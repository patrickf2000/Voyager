#include <QApplication>
#include <QIcon>
#include <QWebEngineHistory>

#include "main_menu.hh"
#include "../tabpane.hh"
#include "../history/history_page.hh"

MainMenu::MainMenu() {
    historyMenu = new QMenu("History");

    viewHistory = new QAction("View History",this);
    clearHistory = new QAction("Clear History",this);
    quit = new QAction("Quit",this);

    quit->setIcon(QIcon::fromTheme("application-exit"));

    connect(viewHistory,&QAction::triggered,this,&MainMenu::onViewHistoryClicked);
    connect(clearHistory,&QAction::triggered,this,&MainMenu::onClearHistoryClicked);
    connect(quit,&QAction::triggered,qApp,&QApplication::exit);

    historyMenu->addAction(viewHistory);
    historyMenu->addAction(clearHistory);

    this->addMenu(historyMenu);
    this->addAction(quit);
}

MainMenu::~MainMenu() {
    delete historyMenu;
    delete viewHistory;
    delete clearHistory;
    delete quit;
}

void MainMenu::onViewHistoryClicked() {
    HistoryPage *page = new HistoryPage(TabPane::currentView()->webView());
    TabPane::addNewTab(page,"History");
}

void MainMenu::onClearHistoryClicked() {
    if (TabPane::currentView()==nullptr) {
        return;
    }
    TabPane::currentView()->webView()->history()->clear();
}
