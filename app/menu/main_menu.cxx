#include <QApplication>
#include <QIcon>

#include "main_menu.hh"

MainMenu::MainMenu() {
    quit = new QAction("Quit",this);

    quit->setIcon(QIcon::fromTheme("application-exit"));

    connect(quit,&QAction::triggered,qApp,&QApplication::exit);

    this->addAction(quit);
}

MainMenu::~MainMenu() {
    delete quit;
}
