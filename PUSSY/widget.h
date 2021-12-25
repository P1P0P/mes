#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "menu.h"
#include <QPixmap>
#include <QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
    QString *mas;
    QSqlDatabase tt;
    int bb;

public slots:
    void     Push();
    void    vibor();
    void     Push2();
    void reg_2();
};
#endif // WIDGET_H
