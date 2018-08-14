// Copyright 2018 Patrick Flynn
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//	this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this
//	list of conditions and the following disclaimer in the documentation and/or
//	other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may
//	be used to endorse or promote products derived from this software
//	without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#include <QApplication>
#include <QIcon>

#include "tabpane.hh"
#include "page/page.hh"
#include "menu/main_menu.hh"

QTabWidget *TabPane::tabs;

TabPane::TabPane() {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    tabs = new QTabWidget;
    tabs->setTabsClosable(true);
    tabs->setMovable(true);
    tabs->setStyleSheet("QTabBar::tab { width: 200px; }");
    layout->addWidget(tabs);

    menu = new QPushButton("Voyager");
    menu->setFlat(true);
    menu->setMenu(new MainMenu);
    tabs->setCornerWidget(menu,Qt::TopLeftCorner);

    newTab = new QPushButton("New Tab");
    newTab->setIcon(QIcon::fromTheme("tab-new"));
    newTab->setFlat(true);
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

void TabPane::addNewTab(QWidget *widget, QString title) {
    int index = tabs->count();
    tabs->addTab(widget,title);
    tabs->setCurrentIndex(index);
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
