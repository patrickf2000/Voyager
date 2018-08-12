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
#include <QIcon>

#include "page.hh"
#include "../tabpane.hh"
#include "../history/history.hh"

TabPage::TabPage(QString url) {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    toolbar = new QToolBar;
    //layout->addWidget(toolbar,0,Qt::AlignTop);
    layout->addWidget(toolbar);

    addressBar = new AddressBar(url);
    connect(addressBar,SIGNAL(urlSubmitted(QString)),this,SLOT(onUrlSubmitted(QString)));

    back = new QToolButton;
    forward = new QToolButton;
    reload = new QToolButton;

    back->setIcon(QIcon::fromTheme("go-previous"));
    forward->setIcon(QIcon::fromTheme("go-next"));
    reload->setIcon(QIcon::fromTheme("view-refresh"));

    connect(back,&QToolButton::clicked,this,&TabPage::goBack);
    connect(forward,&QToolButton::clicked,this,&TabPage::goForward);
    connect(reload,&QToolButton::clicked,this,&TabPage::refreshPage);

    toolbar->addWidget(back);
    toolbar->addWidget(forward);
    toolbar->addWidget(reload);
    toolbar->addWidget(addressBar);

    info = new QLabel("Google Search: ");
    toolbar->addSeparator();
    toolbar->addWidget(info);

    search = new SearchBar;
    connect(search,SIGNAL(completeAddressSubmitted(QString)),this,SLOT(onSearchCompleted(QString)));
    toolbar->addWidget(search);

    view = new WebView(url);
    connect(view,&WebView::loadStarted,this,&TabPage::onLoadStarted);
    connect(view,SIGNAL(loadProgress(int)),this,SLOT(loadProgress(int)));
    connect(view,&WebView::loadCompleted,this,&TabPage::onLoadCompleted);
    layout->addWidget(view);

    loadStatus = new QProgressBar;
    loadStatus->setVisible(false);
    //layout->addWidget(loadStatus,0,Qt::AlignBottom);
    layout->addWidget(loadStatus);
}

TabPage::TabPage() : TabPage("https://duckduckgo.com") {
}

TabPage::~TabPage() {
    delete layout;
    delete addressBar;
    delete back;
    delete forward;
    delete reload;
    delete view;
    delete info;
    delete search;
    delete loadStatus;
}

WebView *TabPage::webView() {
    return view;
}

QString TabPage::pageTitle() {
    return view->title();
}

void TabPage::goBack() {
    view->back();
}

void TabPage::goForward() {
    view->forward();
}

void TabPage::refreshPage() {
    view->reload();
}

void TabPage::onUrlSubmitted(QString url) {
    view->loadUrl(url);
}

void TabPage::onSearchCompleted(QString path) {
    addressBar->setText(path);
    view->load(QUrl(path));
}

void TabPage::onLoadStarted() {
    loadStatus->setVisible(true);
    loadStatus->setValue(0);
}

void TabPage::loadProgress(int state) {
    loadStatus->setValue(state);
}

void TabPage::onLoadCompleted() {
    loadStatus->setVisible(false);
    TabPane::setCurrentTabTitle(view->page()->title());
    addressBar->setText(view->url().toString());
    History::AddPath(view->url().toString());
}
