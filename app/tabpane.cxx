#include <QApplication>
#include <QIcon>

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

    newTab = new QPushButton("New Tab");
    newTab->setIcon(QIcon::fromTheme("tab-new"));
    tabs->setCornerWidget(newTab);

    connect(tabs,SIGNAL(tabCloseRequested(int)),this,SLOT(onTabCloseRequested(int)));
    connect(newTab,&QToolButton::clicked,this,&TabPane::onNewTabClicked);

    TabPage *view = new TabPage;
    tabs->addTab(view,"Home");
}

TabPane::~TabPane() {
    delete layout;
    delete tabs;
}

void TabPane::addNewTab() {
    int index = tabs->count();
    TabPage *view = new TabPage();
    tabs->addTab(view,view->pageTitle());
    tabs->setCurrentIndex(index);
}

void TabPane::addNewTab(QString url) {
    TabPage *view = new TabPage(url);
    tabs->addTab(view,view->pageTitle());
}

TabPage *TabPane::currentView() {
    TabPage *page = static_cast<TabPage *>(tabs->currentWidget());
    return page;
}

void TabPane::setCurrentTabTitle(QString title) {
    tabs->setTabText(tabs->currentIndex(),title);
}

void TabPane::onTabCloseRequested(int index) {
    if ((index==0)&&(tabs->count()==1)) {
        qApp->exit(0);
    } else {
        delete tabs->widget(index);
    }
}

void TabPane::onNewTabClicked() {
    addNewTab();
}
