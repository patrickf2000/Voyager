#include <QListWidget>
#include <QStringList>
#include <QIcon>

#include "history_page.hh"
#include "history.hh"

HistoryPage::HistoryPage() {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    toolbar = new QToolBar;
    layout->addWidget(toolbar,0,Qt::AlignTop);

    historyList = new QListWidget;
    layout->addWidget(historyList);

    loadHistory();

    clear = new QToolButton;
    clear->setIcon(QIcon::fromTheme("edit-delete"));
    clear->setToolTip("Clear history");
    toolbar->addWidget(clear);

    connect(clear,&QToolButton::clicked,this,&HistoryPage::onClearClicked);
}

HistoryPage::~HistoryPage() {
    delete layout;
}

void HistoryPage::loadHistory() {
    historyList->clear();
    QStringList *list1 = History::AllEntries();
    QStringList *list2 = new QStringList;
    for (int i = 0; i<list1->size(); i++) {
        list2->push_front(list1->at(i));
    }

    for (int i = 0; i<list2->size(); i++) {
        historyList->addItem(list2->at(i));
    }
}

void HistoryPage::onClearClicked() {
    History::ClearAllEntries();
    loadHistory();
}
