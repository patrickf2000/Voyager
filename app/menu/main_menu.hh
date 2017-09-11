#pragma once

#include <QMenu>
#include <QAction>

class MainMenu : public QMenu {
    Q_OBJECT
public:
    MainMenu();
    ~MainMenu();
private:
    QAction *viewHistory;
    QAction *quit;
private slots:
    void onViewHistoryClicked();
};
