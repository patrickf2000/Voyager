#include "tabpane.hh"
#include "page/page.hh"

QTabWidget *TabPane::tabs;

TabPane::TabPane() {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    tabs = new QTabWidget;
    tabs->setTabsClosable(true);
    tabs->setMovable(true);
    layout->addWidget(tabs);

    TabPage *view = new TabPage;
    tabs->addTab(view,"Home");
}

TabPane::~TabPane() {
    delete layout;
    delete tabs;
}
