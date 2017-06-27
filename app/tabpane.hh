#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QTabWidget>

class TabPane : public QFrame {
    Q_OBJECT
public:
    TabPane();
    ~TabPane();
private:
    QVBoxLayout *layout;
    static QTabWidget *tabs;
};
