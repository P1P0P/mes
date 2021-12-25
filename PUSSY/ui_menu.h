#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *vibor;
    QLabel *prof;
    QVBoxLayout *verticalLayout_5;
    QPushButton *kot;
    QPushButton *ych_5;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QListWidget *friend_2;
    QVBoxLayout *verticalLayout_6;
    QFormLayout *formLayout;
    QTextEdit *TEXT;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QSplitter *splitter;
    QListWidget *listWidget_2;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *mes;
    QPushButton *bes;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *list_2;
    QListWidget *list;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QPushButton *push_grup;
    QLineEdit *name;
    QPushButton *push_grup2;
    QPushButton *ych;
    QPushButton *friend_3;
    QPushButton *ych_4;
    QHBoxLayout *horizontalLayout;
    QListWidget *grup;
    QGridLayout *gridLayout;
    QPushButton *ych_2;
    QPushButton *ych_3;
    QListWidget *grup2;
    QTextEdit *textEdit_2;
    QPushButton *push;
    QPushButton *stop;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->setEnabled(true);
        Menu->resize(1362, 715);
        gridLayout_2 = new QGridLayout(Menu);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_2 = new QLabel(Menu);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_7->addWidget(label_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        vibor = new QListWidget(Menu);
        vibor->setObjectName(QString::fromUtf8("vibor"));
        vibor->setEnabled(true);

        horizontalLayout_6->addWidget(vibor);

        prof = new QLabel(Menu);
        prof->setObjectName(QString::fromUtf8("prof"));

        horizontalLayout_6->addWidget(prof);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_7->addLayout(horizontalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        kot = new QPushButton(Menu);
        kot->setObjectName(QString::fromUtf8("kot"));

        verticalLayout_5->addWidget(kot);

        ych_5 = new QPushButton(Menu);
        ych_5->setObjectName(QString::fromUtf8("ych_5"));

        verticalLayout_5->addWidget(ych_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        label_3 = new QLabel(Menu);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        friend_2 = new QListWidget(Menu);
        friend_2->setObjectName(QString::fromUtf8("friend_2"));

        verticalLayout_5->addWidget(friend_2);


        verticalLayout_7->addLayout(verticalLayout_5);


        gridLayout_2->addLayout(verticalLayout_7, 0, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));

        verticalLayout_6->addLayout(formLayout);

        TEXT = new QTextEdit(Menu);
        TEXT->setObjectName(QString::fromUtf8("TEXT"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Niagara Solid")});
        font.setPointSize(20);
        TEXT->setFont(font);

        verticalLayout_6->addWidget(TEXT);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        listWidget = new QListWidget(Menu);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_2->addWidget(listWidget);

        splitter = new QSplitter(Menu);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        listWidget_2 = new QListWidget(splitter);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(22);
        listWidget_2->setFont(font1);
        listWidget_2->setViewMode(QListView::IconMode);
        splitter->addWidget(listWidget_2);
        textEdit = new QTextEdit(splitter);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setFont(font);
        splitter->addWidget(textEdit);

        horizontalLayout_2->addWidget(splitter);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 13);

        verticalLayout_6->addLayout(horizontalLayout_2);

        verticalLayout_6->setStretch(1, 13);
        verticalLayout_6->setStretch(3, 1);

        gridLayout_2->addLayout(verticalLayout_6, 0, 1, 3, 2);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        mes = new QPushButton(Menu);
        mes->setObjectName(QString::fromUtf8("mes"));

        verticalLayout_2->addWidget(mes);

        bes = new QPushButton(Menu);
        bes->setObjectName(QString::fromUtf8("bes"));

        verticalLayout_2->addWidget(bes);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        list_2 = new QListWidget(Menu);
        list_2->setObjectName(QString::fromUtf8("list_2"));

        horizontalLayout_3->addWidget(list_2);

        list = new QListWidget(Menu);
        list->setObjectName(QString::fromUtf8("list"));

        horizontalLayout_3->addWidget(list);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_9->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        push_grup = new QPushButton(Menu);
        push_grup->setObjectName(QString::fromUtf8("push_grup"));

        verticalLayout->addWidget(push_grup);

        name = new QLineEdit(Menu);
        name->setObjectName(QString::fromUtf8("name"));

        verticalLayout->addWidget(name);

        push_grup2 = new QPushButton(Menu);
        push_grup2->setObjectName(QString::fromUtf8("push_grup2"));

        verticalLayout->addWidget(push_grup2);

        ych = new QPushButton(Menu);
        ych->setObjectName(QString::fromUtf8("ych"));

        verticalLayout->addWidget(ych);

        friend_3 = new QPushButton(Menu);
        friend_3->setObjectName(QString::fromUtf8("friend_3"));

        verticalLayout->addWidget(friend_3);

        ych_4 = new QPushButton(Menu);
        ych_4->setObjectName(QString::fromUtf8("ych_4"));

        verticalLayout->addWidget(ych_4);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        grup = new QListWidget(Menu);
        grup->setObjectName(QString::fromUtf8("grup"));

        horizontalLayout->addWidget(grup);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ych_2 = new QPushButton(Menu);
        ych_2->setObjectName(QString::fromUtf8("ych_2"));

        gridLayout->addWidget(ych_2, 0, 0, 1, 1);

        ych_3 = new QPushButton(Menu);
        ych_3->setObjectName(QString::fromUtf8("ych_3"));

        gridLayout->addWidget(ych_3, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        grup2 = new QListWidget(Menu);
        grup2->setObjectName(QString::fromUtf8("grup2"));

        horizontalLayout->addWidget(grup2);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_9->addLayout(verticalLayout_4);


        gridLayout_2->addLayout(verticalLayout_9, 0, 4, 1, 1);

        textEdit_2 = new QTextEdit(Menu);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setEnabled(false);

        gridLayout_2->addWidget(textEdit_2, 1, 2, 2, 3);

        push = new QPushButton(Menu);
        push->setObjectName(QString::fromUtf8("push"));

        gridLayout_2->addWidget(push, 2, 3, 1, 1);

        stop = new QPushButton(Menu);
        stop->setObjectName(QString::fromUtf8("stop"));

        gridLayout_2->addWidget(stop, 2, 0, 1, 1);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Menu", "TextLabel", nullptr));
        prof->setText(QString());
        kot->setText(QCoreApplication::translate("Menu", "\321\201\320\274\320\265\320\275\320\270\321\202\321\214 \320\272\320\276\321\202\320\270\320\272\320\260", nullptr));
        ych_5->setText(QCoreApplication::translate("Menu", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214 \320\260\320\272\320\260\321\203\320\275\321\202", nullptr));
        label_3->setText(QCoreApplication::translate("Menu", "\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
        mes->setText(QCoreApplication::translate("Menu", "\321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
        bes->setText(QCoreApplication::translate("Menu", "\320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        push_grup->setText(QCoreApplication::translate("Menu", "\321\201\320\276\320\267\320\264\320\260\321\202\321\214 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
        name->setText(QCoreApplication::translate("Menu", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        push_grup2->setText(QCoreApplication::translate("Menu", "\321\201\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        ych->setText(QCoreApplication::translate("Menu", "\320\277\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\203\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\276\320\262", nullptr));
        friend_3->setText(QCoreApplication::translate("Menu", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\276\320\262", nullptr));
        ych_4->setText(QCoreApplication::translate("Menu", "\320\262\321\213\320\271\321\202\320\270 \320\270\320\267 \321\207\320\260\321\202\320\260", nullptr));
        ych_2->setText(QCoreApplication::translate("Menu", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        ych_3->setText(QCoreApplication::translate("Menu", "\321\201\320\264\320\265\320\273\320\260\321\202\321\214 \320\263\320\273\320\260\320\262\320\275\321\213\320\274", nullptr));
        push->setText(QCoreApplication::translate("Menu", "\320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        stop->setText(QCoreApplication::translate("Menu", "stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
