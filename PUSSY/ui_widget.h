#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *Login;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *Pass;
    QPushButton *PUSH;
    QPushButton *reg_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *Login2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *NIK;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *Pass2;
    QPushButton *PUSH2;
    QListWidget *listWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(805, 499);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        Login = new QLineEdit(Widget);
        Login->setObjectName(QString::fromUtf8("Login"));

        horizontalLayout_4->addWidget(Login);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        Pass = new QLineEdit(Widget);
        Pass->setObjectName(QString::fromUtf8("Pass"));
        Pass->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_5->addWidget(Pass);


        verticalLayout->addLayout(horizontalLayout_5);

        PUSH = new QPushButton(Widget);
        PUSH->setObjectName(QString::fromUtf8("PUSH"));

        verticalLayout->addWidget(PUSH);

        reg_2 = new QPushButton(Widget);
        reg_2->setObjectName(QString::fromUtf8("reg_2"));

        verticalLayout->addWidget(reg_2);

        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        Login2 = new QLineEdit(Widget);
        Login2->setObjectName(QString::fromUtf8("Login2"));

        horizontalLayout->addWidget(Login2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        NIK = new QLineEdit(Widget);
        NIK->setObjectName(QString::fromUtf8("NIK"));

        horizontalLayout_2->addWidget(NIK);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        Pass2 = new QLineEdit(Widget);
        Pass2->setObjectName(QString::fromUtf8("Pass2"));

        horizontalLayout_3->addWidget(Pass2);


        verticalLayout->addLayout(horizontalLayout_3);

        PUSH2 = new QPushButton(Widget);
        PUSH2->setObjectName(QString::fromUtf8("PUSH2"));

        verticalLayout->addWidget(PUSH2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "                    \320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        PUSH->setText(QCoreApplication::translate("Widget", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        reg_2->setText(QCoreApplication::translate("Widget", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "                   \320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\320\273\320\276\320\263\320\270\320\275", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\320\275\320\270\320\272", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        PUSH2->setText(QCoreApplication::translate("Widget", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
