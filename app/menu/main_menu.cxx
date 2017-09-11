#include <QApplication>
#include <QIcon>
#include <QWebEngineHistory>

#include "main_menu.hh"
#include "../tabpane.hh"
#include "../history/history_page.hh"

MainMenu::MainMenu() {
    viewHistory = new QAction("View History",this);
    quit = new QAction("Quit",this);

    quit->setIcon(QIcon::fromTheme("application-exit"));

    connect(viewHistory,&QAction::triggered,this,&MainMenu::onViewHistoryClicked);
    connect(quit,&QAction::triggered,qApp,&QApplication::exit);

    this->addAction(viewHistory);
    this->addAction(quit);
}

MainMenu::~MainMenu() {
    delete viewHistory;
    delete quit;
}

void MainMenu::onViewHistoryClicked() {
    HistoryPage *page = new HistoryPage;
    TabPane::addNewTab(page,"History");
}
