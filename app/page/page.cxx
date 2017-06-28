#include <QIcon>

#include "page.hh"

TabPage::TabPage(QString url) {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    toolbar = new QToolBar;
    layout->addWidget(toolbar,0,Qt::AlignTop);

    addressBar = new QLineEdit(url);

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

    view = new WebView(url);
    layout->addWidget(view);
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
