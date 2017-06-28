#pragma once

#include <QMenu>
#include <QAction>

class MainMenu : public QMenu {
    Q_OBJECT
public:
    MainMenu();
    ~MainMenu();
private:
    QMenu *historyMenu;
    QAction *clearHistory;
    QAction *quit;
private slots:
    void onClearHistoryClicked();
};
