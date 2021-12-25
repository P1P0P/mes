#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "widget.h"
#include <QSqlDatabase>
#include <QPixmap>
#include <QListWidgetItem>
namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr, int idd=0);
    ~Menu();

private:
    Ui::Menu *ui;
    QSqlDatabase tt;
    int id;
    std::string mm;
    std::string q="0";
    int id1;
    int *mas=new int[1];
    int *mas1=new int[1];
    int *mas2=new int[1];
    int *mas3=new int[1];
    int *mas4=new int[1];
    QString *mas5=new QString[1];
    QString *mas6=new QString[1];
    QTimer *time;
    int sx=-2;
    bool LLL=false;
public slots:
    void    vibor();
    void    vibor2();
    void    mes();
    void    bes();
    void    push();
    void chat();
    void chat2();
    void add();
    //void pushButton();
    void smaql();
    void smaql2();
    void push_grup();
    void push_grup2();
    void friend_3();
    void grup();
    void ych();
    void grup2();
    void ych_4();
    void ych_2();
    void ych_3();
    void ych_5();
    void vibork();
    void vibork2();
    void QQ();
    void stop();
};

#endif // MENU_H
