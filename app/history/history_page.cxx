#include <QListWidget>
#include <QStringList>

#include "history_page.hh"
#include "history.hh"

HistoryPage::HistoryPage() {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    QListWidget *historyList = new QListWidget;
    layout->addWidget(historyList);

    QStringList *list1 = History::AllEntries();
    QStringList *list2 = new QStringList;
    for (int i = 0; i<list1->size(); i++) {
        list2->push_front(list1->at(i));
    }

    for (int i = 0; i<list2->size(); i++) {
        historyList->addItem(list2->at(i));
    }
}

HistoryPage::~HistoryPage() {
    delete layout;
}
