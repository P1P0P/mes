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
    QLabel *autorizaion_label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *login_label;
    QLineEdit *login_edit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *pass_label;
    QLineEdit *pass_edit;
    QPushButton *autorization_button;
    QPushButton *reg_button;
    QLabel *reg_label;
    QHBoxLayout *horizontalLayout;
    QLabel *reg_login_label;
    QLineEdit *reg_login_edit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *nik_label;
    QLineEdit *nik_edit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *reg_pass_label;
    QLineEdit *reg_pass_edit;
    QPushButton *reg2_button;
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
        autorizaion_label = new QLabel(Widget);
        autorizaion_label->setObjectName(QString::fromUtf8("autorization_label"));

        verticalLayout->addWidget(autorizaion_label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        login_label = new QLabel(Widget);
        login_label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(login_label);

        login_edit = new QLineEdit(Widget);
        login_edit->setObjectName(QString::fromUtf8("Login"));

        horizontalLayout_4->addWidget(login_edit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pass_label = new QLabel(Widget);
        pass_label->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(pass_label);

        pass_edit = new QLineEdit(Widget);
        pass_edit->setObjectName(QString::fromUtf8("Pass"));
        pass_edit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_5->addWidget(pass_edit);


        verticalLayout->addLayout(horizontalLayout_5);

        autorization_button = new QPushButton(Widget);
        autorization_button->setObjectName(QString::fromUtf8("PUSH"));

        verticalLayout->addWidget(autorization_button);

        reg_button = new QPushButton(Widget);
        reg_button->setObjectName(QString::fromUtf8("reg_2"));

        verticalLayout->addWidget(reg_button);

        reg_label = new QLabel(Widget);
        reg_label->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(reg_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        reg_login_label = new QLabel(Widget);
        reg_login_label->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(reg_login_label);

        reg_login_edit = new QLineEdit(Widget);
        reg_login_edit->setObjectName(QString::fromUtf8("Login2"));

        horizontalLayout->addWidget(reg_login_edit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        nik_label = new QLabel(Widget);
        nik_label->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(nik_label);

        nik_edit = new QLineEdit(Widget);
        nik_edit->setObjectName(QString::fromUtf8("NIK"));

        horizontalLayout_2->addWidget(nik_edit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        reg_pass_label = new QLabel(Widget);
        reg_pass_label->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(reg_pass_label);

        reg_pass_edit = new QLineEdit(Widget);
        reg_pass_edit->setObjectName(QString::fromUtf8("Pass2"));

        horizontalLayout_3->addWidget(reg_pass_edit);


        verticalLayout->addLayout(horizontalLayout_3);

        reg2_button = new QPushButton(Widget);
        reg2_button->setObjectName(QString::fromUtf8("PUSH2"));

        verticalLayout->addWidget(reg2_button);


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
        autorizaion_label->setText(QCoreApplication::translate("Widget", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        login_label->setText(QCoreApplication::translate("Widget", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        pass_label->setText(QCoreApplication::translate("Widget", "\320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        autorization_button->setText(QCoreApplication::translate("Widget", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        reg_button->setText(QCoreApplication::translate("Widget", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        reg_label->setText(QCoreApplication::translate("Widget", "                   \320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        reg_login_label->setText(QCoreApplication::translate("Widget", "\320\273\320\276\320\263\320\270\320\275", nullptr));
        nik_label->setText(QCoreApplication::translate("Widget", "\320\275\320\270\320\272", nullptr));
        reg_pass_label->setText(QCoreApplication::translate("Widget", "\320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        reg2_button->setText(QCoreApplication::translate("Widget", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
