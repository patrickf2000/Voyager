#pragma once

#include <QMenu>
#include <QAction>

class MainMenu : public QMenu {
    Q_OBJECT
public:
    MainMenu();
    ~MainMenu();
private:
    QAction *quit;
};
