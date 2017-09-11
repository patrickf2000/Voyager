#include <QIcon>

#include "page.hh"
#include "../tabpane.hh"
#include "../history/history.hh"

TabPage::TabPage(QString url) {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    toolbar = new QToolBar;
    layout->addWidget(toolbar,0,Qt::AlignTop);

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
    layout->addWidget(loadStatus,0,Qt::AlignBottom);
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
