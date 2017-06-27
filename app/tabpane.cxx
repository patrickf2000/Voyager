#include "tabpane.hh"
#include "page/webview.hh"

QTabWidget *TabPane::tabs;

TabPane::TabPane() {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    tabs = new QTabWidget;
    tabs->setTabsClosable(true);
    tabs->setMovable(true);
    layout->addWidget(tabs);

    WebView *view = new WebView("https://google.com");
    tabs->addTab(view,"Home");
}

TabPane::~TabPane() {
    delete layout;
    delete tabs;
}
