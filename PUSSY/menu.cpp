#include "menu.h"
#include "ui_menu.h"
#include "widget.h"
#include <QTextDocumentFragment>
#include <QWidget>
#include <QToolButton>
#include <QTimeEdit>
#include <QCursor>
#include <QTextCharFormat>
#include <QTimer>

Menu::Menu(QWidget *parent, int idd):
    QWidget(parent),
    ui(new Ui::Menu)
{

    ui->setupUi(this);


    delete []mas5;
    mas5=new QString[6];
    mas5[0]="\U00000001";
    mas5[1]="\U00000002";
    mas5[2]="\U00000003";
    mas5[3]="\U00000004";
    mas5[4]="\U00000005";
    mas5[5]="\U00000006";
    delete []mas6;
    mas6=new QString[17];
    mas6[0]="\U0001F638";
    mas6[1]="\U0001F639";
    mas6[2]="\U0001F63A";
    mas6[3]="\U0001F63B";
    mas6[4]="\U0001F63C";
    mas6[5]="\U0001F63D";
    mas6[6]="\U0001F63E";
    mas6[7]="\U0001F63F";
    mas6[8]="\U0001F431";
    mas6[9]="\U0001F436";
    mas6[10]="\U0001F640";
    mas6[11]="\U0001F351";
    mas6[12]="\U0001F381";
    mas6[13]="\U0001F4A3";
    mas6[14]="\U0001F339";
    mas6[15]="\U0001F36A";
    mas6[16]="\U0001F4A9";

    for(int i=0;i<17;i++)
    {

        ui->textEdit_2->clear();
        ui->textEdit_2->setPlainText(mas6[i]);
       ui->listWidget_2->addItem(ui->textEdit_2->toPlainText());
    }
    for(int i=1;i<7;i++)
    {

        std::string k;
        ui->vibor->setIconSize(QSize(50,50));
        k=":/img/"+std::to_string(i)+".jpg";
        QListWidgetItem *item_1=new QListWidgetItem(QIcon(k.c_str()),std::to_string(i).c_str());
        ui->vibor->addItem(item_1);
    }

    for(int i=1;i<7;i++)
    {
        std::string k;
        ui->listWidget->setIconSize(QSize(50,50));
        k=":/img/"+std::to_string(i)+".jpg";
        QListWidgetItem *item_1=new QListWidgetItem(QIcon(k.c_str())," ");
        ui->listWidget->addItem(item_1);
    }
    ui->vibor->hide();
    ui->list->hide();
    ui->textEdit_2->hide();
    ui->push_grup2->hide();
    ui->name->hide();
    ui->friend_3->hide();
    ui->grup->hide();
    ui->grup2->hide();
    ui->ych->hide();
    ui->ych_2->hide();
    ui->ych_3->hide();
    ui->ych->hide();
    ui->ych_4->hide();
    tt=QSqlDatabase::addDatabase("QPSQL","1");
    tt.setHostName("195.19.32.74");
    tt.setDatabaseName("fn1133_2021");
    tt.setPort(5432);
    tt.setUserName("student");
    tt.setPassword("bmstu");
    tt.open();
    id=idd;

    QSqlQuery msg(tt);
    std::string k;

    msg.exec(("select count(*) from table_1_"+std::to_string(id)).c_str());
    msg.next();
    if(msg.value(0).toInt()!=0)
    {
        delete[] mas;
        mas=new int[msg.value(0).toInt()];
    }
    int o=-1;
    k="select name,id1 from table_1_"+std::to_string(id);
    msg.exec(k.c_str());
    while(msg.next())
    {
        o++;
        mas[o]=msg.value("id1").toInt();
        ui->list_2->addItem(msg.value("name").toString());
    }


    msg.exec(("select count(*) from table_2_"+std::to_string(id)).c_str());
    msg.next();
    if(msg.value(0).toInt()!=0)
    {
        delete[] mas1;
        mas1=new int[msg.value(0).toInt()];
    }
     o=-1;
    k="select id_table_2,id1 from table_2_"+std::to_string(id);
    msg.exec(k.c_str());
    while(msg.next())
    {
        o++;
        mas1[o]=msg.value("id1").toInt();
        k=msg.value(0).toString().toStdString();
        std::string i;
        std::string j;
        bool fll=true;
        for(int p=0;p<k.size();p++)
        {
            if(k[p]!='_')
            {
                if(fll)
                {
                    i=i+k[p];
                }
                else
                {
                    j=j+k[p];
                }
            }
            else
            {
                fll=false;
            }
        }
        QSqlQuery y(tt);
        i="select nik from bd where id="+i;
        j="select nik from bd where id="+j;
        y.exec(i.c_str());
        y.next();
        i=y.value(0).toString().toStdString();
        y.exec(j.c_str());
        y.next();
        j=y.value(0).toString().toStdString();
        ui->list->addItem(("Чат: "+i+" и "+j).c_str());
    }

    msg.exec("select count(*) from bd");
    msg.next();
    if(msg.value(0).toInt()!=0)
    {
        delete[] mas4;
        mas4=new int[msg.value(0).toInt()];
    }
     o=-1;
    msg.exec("select num,nik,id from bd");
    while(msg.next())
    {
        o++;
        mas4[o]=msg.value("id").toInt();
        k=":/img/"+msg.value("num").toString().toStdString()+".jpg";
        QListWidgetItem *item_1=new QListWidgetItem(QIcon(k.c_str()),msg.value("nik").toString());
        ui->friend_2->setIconSize(QSize(50,50));
        ui->friend_2->addItem(item_1);
    }
    k="select num from bd where id="+std::to_string(id);
     msg.exec(k.c_str());
      //ui->TEXT->append(k.c_str());
     msg.next();

    k=":/img/"+msg.value(0).toString().toStdString()+".jpg";
    QPixmap my(k.c_str());
    //ui->prof->setPixmap(my.scaled(ui->prof->width(),ui->prof->height()));

    k="select nik from bd where id="+std::to_string(id);
    msg.exec(k.c_str());
    msg.next();
    ui->label_2->setText(msg.value(0).toString());
    QObject::connect(ui->kot,SIGNAL(clicked()),this,SLOT(vibor()));
    QObject::connect(ui->vibor,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(vibor2()));
     QObject::connect(ui->mes,SIGNAL(clicked()),this,SLOT(mes()));
      QObject::connect(ui->bes,SIGNAL(clicked()),this,SLOT(bes()));
    QObject::connect(ui->push,SIGNAL(clicked()),this,SLOT(push()));
    QObject::connect(ui->list,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(chat()));
    QObject::connect(ui->list_2,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(chat2()));
     QObject::connect(ui->friend_2,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(add()));

     QObject::connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(smaql()));
     QObject::connect(ui->push_grup,SIGNAL(clicked()),this,SLOT(push_grup()));
      QObject::connect(ui->push_grup2,SIGNAL(clicked()),this,SLOT(push_grup2()));
      QObject::connect(ui->friend_3,SIGNAL(clicked()),this,SLOT(friend_3()));
      QObject::connect(ui->grup,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(grup()));
      QObject::connect(ui->ych,SIGNAL(clicked()),this,SLOT(ych()));
      QObject::connect(ui->grup2,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(grup2()));
      QObject::connect(ui->ych_4,SIGNAL(clicked()),this,SLOT(ych_4()));
      QObject::connect(ui->ych_3,SIGNAL(clicked()),this,SLOT(ych_3()));
      QObject::connect(ui->ych_2,SIGNAL(clicked()),this,SLOT(ych_2()));
      QObject::connect(ui->ych_5,SIGNAL(clicked()),this,SLOT(ych_5()));
      QObject::connect(ui->listWidget_2,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(smaql2()));
        time=new QTimer(this);
        time->setInterval(4000);
      QObject::connect(time,SIGNAL(timeout()),this,SLOT(QQ()));
      time->start();
      QObject::connect(ui->stop,SIGNAL(clicked()),this,SLOT(stop()));







}

Menu::~Menu()
{
    delete ui;
    delete[] mas;
    delete[] mas1;
    delete[] mas2;
    delete[] mas3;
    delete[] mas4;
    delete[] mas5;
}
void Menu::vibor()
{
   ui->vibor->show();
   ui->prof->hide();
}
void Menu::vibor2()
{
   ui->vibor->hide();
   QSqlQuery msg(tt);
   std::string k=":/img/"+ui->vibor->currentItem()->text().toStdString()+".jpg";
   QPixmap my(k.c_str());
   ui->prof->setPixmap(my.scaled(ui->prof->width(),ui->prof->height()));
    k="update bd set num='"+ui->vibor->currentItem()->text().toStdString()+"' where id="+std::to_string(id);
    msg.exec(k.c_str());
    ui->prof->show();
    msg.exec("select count(*) from bd");
    msg.next();
    if(msg.value(0).toInt()!=0)
    {
        delete[] mas4;
        mas4=new int[msg.value(0).toInt()];
    }
     int o=-1;
    msg.exec("select num,nik,id from bd");
    ui->friend_2->clear();
    while(msg.next())
    {
        o++;
        mas4[o]=msg.value("id").toInt();
        k=":/img/"+msg.value("num").toString().toStdString()+".jpg";
        QListWidgetItem *item_1=new QListWidgetItem(QIcon(k.c_str()),msg.value("nik").toString());
        ui->friend_2->setIconSize(QSize(50,50));
        ui->friend_2->addItem(item_1);
    }


}
void Menu::vibork()
{
   ui->vibor->show();
   ui->prof->hide();
}
void Menu::vibork2()
{
   ui->vibor->hide();
   QSqlQuery msg(tt);
   std::string k;
   k="select num from bd where id="+std::to_string(id);
    msg.exec(k.c_str());
     //ui->TEXT->append(k.c_str());
    msg.next();

   k=":/img/"+msg.value(0).toString().toStdString()+".jpg";
   QPixmap my(k.c_str());
   ui->prof->setPixmap(my.scaled(ui->prof->width(),ui->prof->height()));
    ui->prof->show();


}
void Menu::mes()
{
   ui->list->show();
   ui->list_2->hide();

}
void Menu::bes()
{
   ui->list->hide();
   ui->list_2->show();
}
void Menu::push()
{


    if(!mm.empty())
    {
        if(!ui->textEdit->toPlainText().isEmpty())
        {
        ui->TEXT->append("");
        ui->textEdit_2->clear();
        ui->textEdit_2->setPlainText(mas5[5]);
        QChar t=ui->textEdit_2->toPlainText()[0];
        //ui->textEdit->setPlainText(t);
        QSqlQuery msg(tt);


        if(id!=id1)
        {

        ui->TEXT->append("");
        msg.exec(("select nik,num from bd where id="+std::to_string(id)).c_str());
        msg.next();
        ui->TEXT->append("");
        ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"25\" height=\"25\">").arg((":/img/"+msg.value("num").toString()+".jpg")));
        ui->TEXT->insertPlainText(msg.value("nik").toString());
        ui->TEXT->setAlignment(Qt::AlignLeft);
        id1=id;
        }
        ui->TEXT->append("");
        QString tt=ui->textEdit->toPlainText();
        for(int i=0 ; i<tt.size();i++)
        {
            if(tt[i]<=t)
            {
                int ii=-1;
                while(ii!=-2)
                {
                 ii++;
                ui->textEdit_2->clear();
                ui->textEdit_2->setPlainText(mas5[ii]);
                if(ui->textEdit_2->toPlainText()[0]==tt[i])
                {
                ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg((":/img/"+std::to_string(ii+1)+".jpg").c_str()));
                ii=-2;
                }
                }
            }
            else
            {

                ui->TEXT->insertPlainText(tt.at(i));
            }
        }

        QString cmd=ui->textEdit->toPlainText();
        std::string k="Insert into "+mm+"(TEXT,bool,num,id) values ('"+cmd.toStdString()+"',"+"1"+",'0',"+std::to_string(id)+")";

        msg.exec(k.c_str());
        ui->textEdit->clear();
        }


    }

}
void Menu::chat()
{

    ui->friend_3->hide();
    ui->ych->hide();
    ui->ych_4->hide();
    ui->ych_2->hide();
    ui->ych_3->hide();
    ui->grup->hide();
    ui->grup2->hide();

    std::string k;
   k="select id_table_2 from table_2_"+std::to_string(id) +" where id1="+ std::to_string(mas1[ui->list->currentRow()]);

   QSqlQuery msg(tt);
   msg.exec(k.c_str());

   msg.next();
   k=msg.value(0).toString().toStdString();
   std::string i;
   std::string j;
   bool fll=true;
   for(int p=0;p<k.size();p++)
   {
       if(k[p]!='_')
       {
           if(fll)
           {
               i=i+k[p];
           }
           else
           {
               j=j+k[p];
           }
       }
       else
       {
           fll=false;
       }
   }
   id1=-1;
   sx=0;
   mm="table2_"+msg.value(0).toString().toStdString();
   i="select nik from bd where id="+i;
   j="select nik from bd where id="+j;
   msg.exec(i.c_str());
   msg.next();
   i=msg.value(0).toString().toStdString();
   msg.exec(j.c_str());
   msg.next();
   j=msg.value(0).toString().toStdString();

   k="select text,id,num from "+mm;
   msg.exec(k.c_str());
   //QTextDocumentFragment ff= QTextDocumentFragment::fromHtml("<img src='source/1.jpg'>");
   //ui->TEXT->textCursor().insertFragment(ff);
   //ui->TEXT->setVisible(true);
    ui->TEXT->clear();
   ui->TEXT->append(("Чат: "+i+" и "+j).c_str());
   ui->TEXT->setAlignment(Qt::AlignCenter);
   //ui->TEXT->set
   ui->textEdit_2->clear();
   ui->textEdit_2->setPlainText(mas5[5]);
   QChar t=ui->textEdit_2->toPlainText()[0];
   QSqlQuery h(tt);
   while(msg.next())
   {

       ui->TEXT->append("");

       if (msg.value("id").toInt()!=id1)
       {

           ui->TEXT->append("");
       k="select num,nik from bd where id="+msg.value("id").toString().toStdString();
       h.exec(k.c_str());
       h.next();

       k=":/img/"+h.value("num").toString().toStdString()+".jpg";
       ui->TEXT->append("");
       ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"25\" height=\"25\">").arg(k.c_str()));
       ui->TEXT->insertPlainText(h.value("nik").toString());
       if(msg.value("id").toInt()==id)
       {

           ui->TEXT->setAlignment(Qt::AlignLeft);
       }
       else
       {
           ui->TEXT->setAlignment(Qt::AlignRight);
       }
       id1=(msg.value("id").toInt());

       }
       ui->TEXT->append("");
       QString tt=msg.value("text").toString();
       for(int i=0 ; i<tt.size();i++)
       {
           if(tt[i]<=t)
           {
               int ii=-1;
               while(ii!=-2)
               {
                ii++;
               ui->textEdit_2->clear();
               ui->textEdit_2->setPlainText(mas5[ii]);
               if(ui->textEdit_2->toPlainText()[0]==tt[i])
               {
               ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg((":/img/"+std::to_string(ii+1)+".jpg").c_str()));
               ii=-2;
               }
               }
           }
           else
           {

               ui->TEXT->insertPlainText(tt.at(i));
           }
       }
       if(msg.value("num").toString().toStdString()!="0")
       {
       ui->TEXT->append("");
       k=":/img/"+msg.value("num").toString().toStdString()+".jpg";
       ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg(k.c_str()));
       }
   }

   ui->friend_3->hide();
   ui->grup->hide();
}
void Menu::chat2()
{
    ui->ych_2->hide();
    ui->ych_3->hide();
    ui->grup->hide();
    ui->grup2->hide();
    id1=-1;
    ui->ych->show();

    std::string k;
   k="select id_table_1,name from table_1_"+std::to_string(id) +" where id1="+ std::to_string(mas[ui->list_2->currentRow()]);

   QSqlQuery msg(tt);
   QSqlQuery h(tt);
   msg.exec(k.c_str());
   msg.next();
   sx=1;
   mm="table1_"+msg.value("id_table_1").toString().toStdString();
   ui->TEXT->clear();
  ui->TEXT->append(("Чат: "+msg.value("name").toString().toStdString()).c_str());
  ui->TEXT->setAlignment(Qt::AlignCenter);
   k="select text,id,num from "+mm;
   msg.exec(k.c_str());
   ui->textEdit_2->clear();
   ui->textEdit_2->setPlainText(mas5[5]);
   QChar t=ui->textEdit_2->toPlainText()[0];
   while(msg.next())
   {
       ui->TEXT->append("");

       if (msg.value("id").toInt()!=id1)
       {
           ui->TEXT->append("");
       k="select num,nik from bd where id="+msg.value("id").toString().toStdString();
       h.exec(k.c_str());
       h.next();

       k=":/img/"+h.value("num").toString().toStdString()+".jpg";
       ui->TEXT->append("");
       ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"25\" height=\"25\">").arg(k.c_str()));
       ui->TEXT->insertPlainText(h.value("nik").toString());

       if(msg.value("id").toInt()==id)
       {

           ui->TEXT->setAlignment(Qt::AlignLeft);
       }
       else
       {
           ui->TEXT->setAlignment(Qt::AlignRight);
       }

       id1=(msg.value("id").toInt());

       }
       ui->TEXT->append("");
       QString tt=msg.value("text").toString();

       for(int i=0 ; i<tt.size();i++)
       {

           if(tt[i]<=t)
           {
               int ii=-1;
               while(ii!=-2)
               {
                ii++;
               ui->textEdit_2->clear();
               ui->textEdit_2->setPlainText(mas5[ii]);
               if(ui->textEdit_2->toPlainText()[0]==tt[i])
               {
               ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg((":/img/"+std::to_string(ii+1)+".jpg").c_str()));
               ii=-2;
               }
               }
           }
           else
           {

               ui->TEXT->insertPlainText(tt.at(i));
           }
       }
       if(msg.value("num").toString().toStdString()!="0")
       {
       ui->TEXT->append("");
       k=":/img/"+msg.value("num").toString().toStdString()+".jpg";
       ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg(k.c_str()));
       }
   }
   ui->friend_3->show();
   ui->ych_4->show();
   ui->grup->hide();

}
void Menu::add()
{

    ui->friend_3->hide();
    ui->ych->hide();
    ui->ych_4->hide();
    ui->ych_2->hide();
    ui->ych_3->hide();
    ui->grup->hide();
    ui->grup2->hide();
    std::string k;
    k="select id_table_2 from table_2_"+std::to_string(id) +" where id_table_2='"+ std::to_string(mas4[ui->friend_2->currentRow()])+"_"+std::to_string(id)+"'";
    QSqlQuery msg(tt);

    msg.exec(k.c_str());
    if(msg.next())
    {
        id1=-1;
        k=msg.value(0).toString().toStdString();
        std::string i;
        std::string j;
        bool fll=true;
        for(int p=0;p<k.size();p++)
        {
            if(k[p]!='_')
            {
                if(fll)
                {
                    i=i+k[p];
                }
                else
                {
                    j=j+k[p];
                }
            }
            else
            {
                fll=false;
            }
        }
        sx=0;
        mm="table2_"+msg.value(0).toString().toStdString();
        i="select nik from bd where id="+i;
        j="select nik from bd where id="+j;
        msg.exec(i.c_str());
        msg.next();
        i=msg.value(0).toString().toStdString();
        msg.exec(j.c_str());
        msg.next();
        j=msg.value(0).toString().toStdString();
         //mm="table2_"+std::to_string(ui->friend_2->currentRow()+1)+"_"+std::to_string(id);
        ui->TEXT->clear();
       ui->TEXT->append(("Чат: "+i+" и "+j).c_str());
       ui->TEXT->setAlignment(Qt::AlignCenter);
        k="select text,id,num from "+mm;
        msg.exec(k.c_str());
        QSqlQuery h(tt);
        ui->textEdit_2->clear();
        ui->textEdit_2->setPlainText(mas5[5]);
        QChar t=ui->textEdit_2->toPlainText()[0];

        while(msg.next())
        {
            ui->TEXT->append("");

            if (msg.value("id").toInt()!=id1)
            {
                ui->TEXT->append("");
            k="select num,nik from bd where id="+msg.value("id").toString().toStdString();
            h.exec(k.c_str());
            h.next();

            k=":/img/"+h.value("num").toString().toStdString()+".jpg";
            ui->TEXT->append("");
            ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"25\" height=\"25\">").arg(k.c_str()));
            ui->TEXT->insertPlainText(h.value("nik").toString());
            if(msg.value("id").toInt()==id)
            {

                ui->TEXT->setAlignment(Qt::AlignLeft);
            }
            else
            {
                ui->TEXT->setAlignment(Qt::AlignRight);
            }

            id1=(msg.value("id").toInt());

            }
            ui->TEXT->append("");
            QString tt=msg.value("text").toString();
            for(int i=0 ; i<tt.size();i++)
            {
                if(tt[i]<=t)
                {
                    int ii=-1;
                    while(ii!=-2)
                    {
                     ii++;
                    ui->textEdit_2->clear();
                    ui->textEdit_2->setPlainText(mas5[ii]);
                    if(ui->textEdit_2->toPlainText()[0]==tt[i])
                    {
                    ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg((":/img/"+std::to_string(ii+1)+".jpg").c_str()));
                    ii=-2;
                    }
                    }
                }
                else
                {

                    ui->TEXT->insertPlainText(tt.at(i));
                }
            }
            if(msg.value("num").toString().toStdString()!="0")
            {
            ui->TEXT->append("");
            k=":/img/"+msg.value("num").toString().toStdString()+".jpg";
            ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg(k.c_str()));
            }
        }

        ui->friend_3->hide();
        ui->grup->hide();
    }
    else
    {

        k="select id_table_2 from table_2_"+std::to_string(id) +" where id_table_2='"+std::to_string(id)+"_"+std::to_string(mas4[ui->friend_2->currentRow()])+"'";

        msg.exec(k.c_str());
        if(msg.next())
        {
            id1=-1;
            k=msg.value(0).toString().toStdString();
            std::string i;
            std::string j;
            bool fll=true;
            for(int p=0;p<k.size();p++)
            {
                if(k[p]!='_')
                {
                    if(fll)
                    {
                        i=i+k[p];
                    }
                    else
                    {
                        j=j+k[p];
                    }
                }
                else
                {
                    fll=false;
                }
            }
            sx=0;
            mm="table2_"+msg.value(0).toString().toStdString();
            i="select nik from bd where id="+i;
            j="select nik from bd where id="+j;
            msg.exec(i.c_str());
            msg.next();
            i=msg.value(0).toString().toStdString();
            msg.exec(j.c_str());
            msg.next();
            j=msg.value(0).toString().toStdString();
            ui->TEXT->clear();
           ui->TEXT->append(("Чат: "+i+" и "+j).c_str());
           ui->TEXT->setAlignment(Qt::AlignCenter);
            // mm="table2_"+std::to_string(id)+"_"+std::to_string(ui->friend_2->currentRow()+1);
             k="select text,id,num from "+mm;
             msg.exec(k.c_str());
             QSqlQuery h(tt);
             ui->textEdit_2->clear();
             ui->textEdit_2->setPlainText(mas5[5]);
             QChar t=ui->textEdit_2->toPlainText()[0];
             while(msg.next())
             {
                 ui->TEXT->append("");

                 if (msg.value("id").toInt()!=id1)
                 {
                     ui->TEXT->append("");
                 k="select num,nik from bd where id="+msg.value("id").toString().toStdString();
                 h.exec(k.c_str());
                 h.next();
                 ui->TEXT->append("");
                 k=":/img/"+h.value("num").toString().toStdString()+".jpg";
                 ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"25\" height=\"25\">").arg(k.c_str()));
                 ui->TEXT->insertPlainText(h.value("nik").toString());
                 if(msg.value("id").toInt()==id)
                 {

                     ui->TEXT->setAlignment(Qt::AlignLeft);
                 }
                 else
                 {
                     ui->TEXT->setAlignment(Qt::AlignRight);
                 }

                 id1=(msg.value("id").toInt());

                 }
                 ui->TEXT->append("");
                 QString tt=msg.value("text").toString();
                 for(int i=0 ; i<tt.size();i++)
                 {
                     if(tt[i]<=t)
                     {
                         int ii=-1;
                         while(ii!=-2)
                         {
                          ii++;
                         ui->textEdit_2->clear();
                         ui->textEdit_2->setPlainText(mas5[ii]);
                         if(ui->textEdit_2->toPlainText()[0]==tt[i])
                         {
                         ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg((":/img/"+std::to_string(ii+1)+".jpg").c_str()));
                         ii=-2;
                         }
                         }
                     }
                     else
                     {

                         ui->TEXT->insertPlainText(tt.at(i));
                     }
                 }
                 if(msg.value("num").toString().toStdString()!="0")
                 {
                 ui->TEXT->append("");
                 k=":/img/"+msg.value("num").toString().toStdString()+".jpg";
                 ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg(k.c_str()));
                 }
             }

             ui->friend_3->hide();
             ui->grup->hide();

        }
        else
            if(id!=(mas4[ui->friend_2->currentRow()]))
            {
                sx=0;
                ui->TEXT->setText("диалог");
                mm="table2_"+std::to_string(id)+"_"+std::to_string(mas4[ui->friend_2->currentRow()]);
                id1=mas4[ui->friend_2->currentRow()];
                k="Create table "+mm+"(text text , bool int, num text, id int)";
                msg.exec(k.c_str());
                k="Select max(id1) From table_2_"+std::to_string(id);
                msg.exec(k.c_str());
                int ww;
                if(msg.next())
                {
                    ww=msg.value(0).toInt()+1;
                }
                else
                {
                    ww=1;
                }
                k="Insert into table_2_"+std::to_string(id)+"(id_table_2,id1) values ('"+std::to_string(id)+"_"+std::to_string(mas4[ui->friend_2->currentRow()])+"',"+std::to_string(ww)+")";
                msg.exec(k.c_str());

                k="Select max(id1) from table_2_"+std::to_string(mas4[ui->friend_2->currentRow()]);
                msg.exec(k.c_str());


                if(msg.next())
                {
                    ww=msg.value(0).toInt()+1;
                }
                else
                {
                    ww=1;
                }

                k="Insert into table_2_"+std::to_string(mas4[ui->friend_2->currentRow()])+"(id_table_2,id1) values ('"+std::to_string(id)+"_"+std::to_string(mas4[ui->friend_2->currentRow()])+"',"+std::to_string(ww)+")";
                msg.exec(k.c_str());

                msg.exec(("select count(*) from table_2_"+std::to_string(id)).c_str());
                msg.next();
                if(msg.value(0).toInt()!=0)
                {
                    delete[] mas1;
                    mas1=new int[msg.value(0).toInt()];
                }
                int o=-1;
                k="select id_table_2,id1 from table_2_"+std::to_string(id);
                msg.exec(k.c_str());
                ui->list->clear();
                while(msg.next())
                {
                    k=msg.value(0).toString().toStdString();
                    std::string i;
                    std::string j;
                    bool fll=true;
                    for(int p=0;p<k.size();p++)
                    {
                        if(k[p]!='_')
                        {
                            if(fll)
                            {
                                i=i+k[p];
                            }
                            else
                            {
                                j=j+k[p];
                            }
                        }
                        else
                        {
                            fll=false;
                        }
                    }
                    o++;
                    mas1[o]=msg.value("id1").toInt();
                    QSqlQuery y(tt);
                    i="select nik from bd where id="+i;
                    j="select nik from bd where id="+j;
                    y.exec(i.c_str());
                    y.next();
                    i=y.value(0).toString().toStdString();
                    y.exec(j.c_str());
                    y.next();
                    j=y.value(0).toString().toStdString();
                    ui->list->addItem(("Чат: "+i+" и "+j).c_str());
                }


            }
    }
}


void Menu::smaql()
{

    std::string k=":/img/"+std::to_string(ui->listWidget->currentRow()+1)+".jpg";
    ui->textEdit->insertHtml(QString("<img src=\"%1\" width=\"50\" height=\"50\">").arg(k.c_str()));  //.replace("12x12", "24x24"));
    ui->textEdit->insertPlainText(mas5[ui->listWidget->currentRow()]);

}
void Menu::smaql2()
{

    ui->textEdit->insertPlainText(mas6[ui->listWidget_2->currentRow()]);

}
void Menu::push_grup()
{
    ui->push_grup->hide();
    ui->push_grup2->show();
    ui->name->show();
}
void Menu::push_grup2()
{
     QSqlQuery msg(tt);
     msg.exec(("select max(id1) from table_1_"+std::to_string(id)).c_str());
     msg.next();
     int w=msg.value(0).toInt()+1;
    ui->push_grup->show();
    ui->push_grup2->hide();
    ui->name->hide();
    msg.exec("select max(id) from count");
    msg.next();
    std::string k="Create table table1_"+std::to_string(msg.value(0).toInt()+1)+"(Text TEXT NOT NULL, bool int, num int, id int)";
    std::string q="insert into table_1_"+std::to_string(id)+"(id_table_1,name,id1) values('"+std::to_string(msg.value(0).toInt()+1)+"','"+ui->name->text().toStdString()+"',"+std::to_string(w)+")";
    std::string qq="Create table name_"+std::to_string(msg.value(0).toInt()+1)+"(id int, bool int,FOREIGN KEY (id) REFERENCES bd(id) ON DELETE CASCADE ON UPDATE CASCADE)";
    std::string kk="insert into name_"+std::to_string(msg.value(0).toInt()+1)+"(id, bool) values("+std::to_string(id)+",1)";
    msg.exec(("insert into count(id)values("+std::to_string(msg.value(0).toInt()+1)+")").c_str());

     msg.exec(k.c_str());
     msg.exec(q.c_str());
     msg.exec(qq.c_str());
     msg.exec(kk.c_str());

     msg.exec(("select count(*) from table_1_"+std::to_string(id)).c_str());
     msg.next();
     if(msg.value(0).toInt()!=0)
     {
         delete []mas;
         mas=new int[msg.value(0).toInt()];
     }
     int o=-1;
     k="select name,id1 from table_1_"+std::to_string(id);
     msg.exec(k.c_str());

     ui->list_2->clear();
     while(msg.next())
     {
        o++;
        mas[o]=msg.value("id1").toInt();
         ui->list_2->addItem(msg.value("name").toString());
     }
     /*ui->TEXT->append(k.c_str());
     ui->TEXT->append(q.c_str());
     ui->TEXT->append(qq.c_str());
     ui->TEXT->append(kk.c_str());*/

}
void Menu::friend_3()
{
    ui->ych->hide();
    ui->ych_4->hide();
    ui->friend_3->hide();
    ui->grup->show();
    ui->grup->clear();
    QSqlQuery msg(tt);
    msg.exec("select count(*) from bd");
    msg.next();
    if(msg.value(0).toInt()!=0)
    {
        delete mas2;
        mas2=new int[msg.value(0).toInt()];
    }
    int o=-1;
    msg.exec("select num,nik,id from bd order by id");
    std::string k;
    while(msg.next())
    {
        o++;

        mas2[o]=msg.value("id").toInt();
        std::string k=":/img/"+msg.value("num").toString().toStdString()+".jpg";
        QListWidgetItem *item_1=new QListWidgetItem(QIcon(k.c_str()),msg.value("nik").toString());
        ui->grup->setIconSize(QSize(50,50));
        ui->grup->addItem(item_1);
    }

}
void Menu::grup()
{
    ui->ych_4->show();
    ui->friend_3->show();
    ui->ych->show();
    ui->friend_3->show();
    ui->grup->hide();
    if(mas2[ui->grup->currentRow()]!=id)
    {
     std::string k;
    QSqlQuery msg(tt);

    std::string i;
    std::string j;
    bool fll=true;
    for(int p=0;p<mm.size();p++)
    {
        if(mm[p]!='_')
        {
            if(fll)
            {
                i=i+mm[p];
            }
            else
            {
                j=j+mm[p];
            }
        }
        else
        {
            fll=false;
        }
    }
    k="select id from name_"+j+" where id="+std::to_string(mas2[ui->grup->currentRow()]);
    msg.exec(k.c_str());
    //ui->TEXT->append(k.c_str());
    if(!msg.next())
    {
    k="select max(id1) from table_1_"+std::to_string(mas2[ui->grup->currentRow()]);
    msg.exec(k.c_str());
    msg.next();
    i=std::to_string(msg.value(0).toInt()+1);
    k="select name from table_1_"+std::to_string(id)+" where id_table_1='"+j+"'";
    msg.exec(k.c_str());
    msg.next();

    std::string q="insert into table_1_"+std::to_string(mas2[ui->grup->currentRow()])+"(id_table_1,name,id1) values('"+j+"','"+msg.value(0).toString().toStdString()+"',"+i+")";
    std::string kk="insert into name_"+j+"(id, bool) values("+std::to_string(mas2[ui->grup->currentRow()])+",0)";
    //msg.exec(k.c_str());
    msg.exec(q.c_str());
    msg.exec(kk.c_str());
    }
    }
}
void Menu::grup2()
{
    QSqlQuery msg(tt);
    std::string i;
    std::string j;
    bool fll=true;
    ui->grup2->hide();
    ui->ych->show();

    for(int p=0;p<mm.size();p++)
    {
        if(mm[p]!='_')
        {
            if(fll)
            {
                i=i+mm[p];
            }
            else
            {
                j=j+mm[p];
            }
        }
        else
        {
            fll=false;
        }
    }
    msg.exec(("select bool from name_"+j+" where id="+std::to_string(id)).c_str());
    msg.next();
    id1=mas3[ui->grup2->currentRow()];
    if (msg.value("bool").toInt()==1 && id1!=id)
    {

        ui->ych_2->show();
        ui->ych_3->show();
    }
    else
    {

        ui->ych_4->show();
        ui->friend_3->show();
        ui->ych->show();
    }


}
void Menu::ych()
{
    ui->ych_4->hide();
    ui->friend_3->hide();
    ui->ych->hide();
    ui->grup2->show();
    ui->grup2->clear();
    QSqlQuery msg(tt);
    std::string i;
    std::string j;
    bool fll=true;
    for(int p=0;p<mm.size();p++)
    {
        if(mm[p]!='_')
        {
            if(fll)
            {
                i=i+mm[p];
            }
            else
            {
                j=j+mm[p];
            }
        }
        else
        {
            fll=false;
        }
    }
    msg.exec(("select count(*) from name_"+j).c_str());
    msg.next();
    if(msg.value(0).toInt()!=0)
    {
        delete mas3;
        mas3=new int[msg.value(0).toInt()];
    }
    msg.exec(("select id from name_"+j).c_str());
    int o=-1;
    while(msg.next())
    {
        o++;
        QSqlQuery m(tt);
        mas3[o]=msg.value("id").toInt();
        std::string k="select num,nik from bd where id="+msg.value("id").toString().toStdString();
        m.exec(k.c_str());
        m.next();
        k=":/img/"+m.value("num").toString().toStdString()+".jpg";
        QListWidgetItem *item_1=new QListWidgetItem(QIcon(k.c_str()),m.value("nik").toString());
        ui->grup2->setIconSize(QSize(50,50));
        ui->grup2->addItem(item_1);
    }
}
void Menu::ych_4()
{

    std::string i;
    std::string j;
    bool fll=true;
    for(int p=0;p<mm.size();p++)
    {
        if(mm[p]!='_')
        {
            if(fll)
            {
                i=i+mm[p];
            }
            else
            {
                j=j+mm[p];
            }
        }
        else
        {
            fll=false;
        }
    }
    QSqlQuery msg(tt);
    msg.exec(("select count(*) from name_"+j).c_str());
    msg.next();
    if(msg.value(0).toInt()>1)
    {
        msg.exec(("select bool from name_"+j+" where id="+std::to_string(id)).c_str());
        msg.next();
        if(msg.value(0).toInt()==0)
        {
             msg.exec(("delete from name_"+j+" where id="+std::to_string(id)).c_str());

             msg.exec(("delete from table_1_"+std::to_string(id)+" where id_table_1='"+j+"'").c_str());
             ui->TEXT->clear();
             msg.exec(("select count(*) from table_1_"+std::to_string(id)).c_str());
             msg.next();
             ui->list_2->clear();
             if(msg.value(0).toInt()!=0)
             {
                 delete[] mas;
                 mas=new int[msg.value(0).toInt()];
             }
             int o=-1;
             std::string k="select name,id1 from table_1_"+std::to_string(id);
             msg.exec(k.c_str());
             while(msg.next())
             {
                 o++;
                 mas[o]=msg.value("id1").toInt();
                 ui->list_2->addItem(msg.value("name").toString());
             }
             mm="";
             id1=-1;
        }
    }
    else
    {
        msg.exec(("drop table name_"+j).c_str());
        msg.exec(("drop table "+mm).c_str());
        msg.exec(("delete from table_1_"+std::to_string(id)+" where id_table_1='"+j+"'").c_str());
        ui->TEXT->clear();
        msg.exec(("select count(*) from table_1_"+std::to_string(id)).c_str());
        msg.next();
        if(msg.value(0).toInt()!=0)
        {
            delete[] mas;
            mas=new int[msg.value(0).toInt()];
        }
        int o=-1;
        ui->list_2->clear();
        std::string k="select name,id1 from table_1_"+std::to_string(id);
        msg.exec(k.c_str());
        while(msg.next())
        {
            o++;
            mas[o]=msg.value("id1").toInt();
            ui->list_2->addItem(msg.value("name").toString());
        }
        mm="";
        id1=-1;
    }
}
void Menu::ych_3()
{
    QSqlQuery msg(tt);
    std::string i;
    std::string j;
    bool fll=true;
    for(int p=0;p<mm.size();p++)
    {
        if(mm[p]!='_')
        {
            if(fll)
            {
                i=i+mm[p];
            }
            else
            {
                j=j+mm[p];
            }
        }
        else
        {
            fll=false;
        }
    }
    msg.exec(("update name_"+j+" set bool=1 where id="+std::to_string(id1)).c_str());
    msg.exec(("update name_"+j+" set bool=0 where id="+std::to_string(id)).c_str());

    ui->grup->hide();
    ui->grup2->hide();
    ui->ych_2->hide();
    ui->ych_3->hide();
    ui->ych->show();
    ui->ych_4->show();
    ui->friend_3->show();


}
void Menu::ych_2()
{
     QSqlQuery msg(tt);
     std::string i;
     std::string j;
     bool fll=true;
     for(int p=0;p<mm.size();p++)
     {
         if(mm[p]!='_')
         {
             if(fll)
             {
                 i=i+mm[p];
             }
             else
             {
                 j=j+mm[p];
             }
         }
         else
         {
             fll=false;
         }
     }
    msg.exec(("delete from name_"+j+" where id="+std::to_string(id1)).c_str());
    msg.exec(("delete from table_1_"+std::to_string(id1)+" where id_table_1='"+j+"'").c_str());
    ui->grup->hide();
    ui->grup2->hide();
    ui->ych_2->hide();
    ui->ych_3->hide();

    ui->ych_4->show();
    ui->friend_3->show();
    ui->ych->show();
}
void Menu::ych_5()
{
     QSqlQuery msg(tt);

     msg.exec(("select id_table_2 from table_2_"+std::to_string(id)).c_str());

     while (msg.next())
     {
          QSqlQuery y(tt);
         std::string i;
         std::string j;
         bool fll=true;
         mm=msg.value(0).toString().toStdString();
         for(int p=0;p<mm.size();p++)
         {
             if(mm[p]!='_')
             {
                 if(fll)
                 {
                     i=i+mm[p];
                 }
                 else
                 {
                     j=j+mm[p];
                 }
             }
             else
             {
                 fll=false;
             }
         }

         if (std::to_string(id)==i)
         {
             i=j;
         }

         y.exec(("select id from bd where id="+i).c_str());

         if(!y.next())
         {

             y.exec(("drop table table2_"+msg.value(0).toString().toStdString()).c_str());

         }
     }




   msg.exec(("delete from bd where id="+std::to_string(id)).c_str());

   msg.exec(("select id_table_1 from table_1_"+std::to_string(id)).c_str());
    while (msg.next())
    {
        QSqlQuery y(tt);

        y.exec(("select bool from name_"+msg.value(0).toString().toStdString()).c_str());
        if(!y.next())
        {
            y.exec(("drop table name_"+msg.value(0).toString().toStdString()).c_str());
            y.exec(("drop table table1_"+msg.value(0).toString().toStdString()).c_str());
        }
    }

    msg.exec(("drop table table_1_"+std::to_string(id)).c_str());
    msg.exec(("drop table table_2_"+std::to_string(id)).c_str());
    this->close();
}
void Menu::QQ()
{

    if(sx==0)
    {
    QSqlQuery msg(tt);

    std::string k=mm;
    std::string i;
    std::string j;
    int fll=0;
    for(int p=0;p<k.size();p++)
    {
        if(k[p]!='_')
        {
            if(fll==1)
            {
                i=i+k[p];
            }
            else
            {
                if(fll==2)
                {
                j=j+k[p];
                }
            }
        }
        else
        {
            fll++;
        }
    }
    id1=-1;
    i="select nik from bd where id="+i;
    j="select nik from bd where id="+j;
    msg.exec(i.c_str());
    msg.next();
    i=msg.value(0).toString().toStdString();
    msg.exec(j.c_str());
    msg.next();
    j=msg.value(0).toString().toStdString();

    k="select text,id,num from "+mm;
    msg.exec(k.c_str());
    //QTextDocumentFragment ff= QTextDocumentFragment::fromHtml("<img src='source/1.jpg'>");
    //ui->TEXT->textCursor().insertFragment(ff);
    //ui->TEXT->setVisible(true);
     ui->TEXT->clear();
    ui->TEXT->append(("Чат: "+i+" и "+j).c_str());
    ui->TEXT->setAlignment(Qt::AlignCenter);
    //ui->TEXT->set
    ui->textEdit_2->clear();
    ui->textEdit_2->setPlainText(mas5[5]);
    QChar t=ui->textEdit_2->toPlainText()[0];
    QSqlQuery h(tt);
    while(msg.next())
    {

        ui->TEXT->append("");

        if (msg.value("id").toInt()!=id1)
        {

            ui->TEXT->append("");
        k="select num,nik from bd where id="+msg.value("id").toString().toStdString();
        h.exec(k.c_str());
        h.next();

        k=":/img/"+h.value("num").toString().toStdString()+".jpg";
        ui->TEXT->append("");
        ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"25\" height=\"25\">").arg(k.c_str()));
        ui->TEXT->insertPlainText(h.value("nik").toString());
        if(msg.value("id").toInt()==id)
        {

            ui->TEXT->setAlignment(Qt::AlignLeft);
        }
        else
        {
            ui->TEXT->setAlignment(Qt::AlignRight);
        }
        id1=(msg.value("id").toInt());

        }
        ui->TEXT->append("");
        QString tt=msg.value("text").toString();
        for(int i=0 ; i<tt.size();i++)
        {
            if(tt[i]<=t)
            {
                int ii=-1;
                while(ii!=-2)
                {
                 ii++;
                ui->textEdit_2->clear();
                ui->textEdit_2->setPlainText(mas5[ii]);
                if(ui->textEdit_2->toPlainText()[0]==tt[i])
                {
                ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg((":/img/"+std::to_string(ii+1)+".jpg").c_str()));
                ii=-2;
                }
                }
            }
            else
            {

                ui->TEXT->insertPlainText(tt.at(i));
            }
        }
        if(msg.value("num").toString().toStdString()!="0")
        {
        ui->TEXT->append("");
        k=":/img/"+msg.value("num").toString().toStdString()+".jpg";
        ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg(k.c_str()));
        }
    }
    }
    else
    {
        if(sx==1)
        {
            id1=-1;
            std::string k;
            std::string i;
            std::string j;
            int fll=0;
            for(int p=0;p<k.size();p++)
            {
                if(k[p]!='_')
                {
                    if(fll==1)
                    {
                        i=i+k[p];
                    }
                    else
                    {
                        if(fll==2)
                        {
                        j=j+k[p];
                        }
                    }
                }
                else
                {
                    fll++;
                }
            }
            QSqlQuery msg(tt);
            QSqlQuery h(tt);
            k="select name from table_1_"+std::to_string(id) +" where id_table_1="+ i;
            msg.exec(k.c_str());
            msg.next();
            ui->TEXT->clear();
           ui->TEXT->append(("Чат: "+msg.value("name").toString().toStdString()).c_str());
           ui->TEXT->setAlignment(Qt::AlignCenter);
            k="select text,id,num from "+mm;
            msg.exec(k.c_str());
            ui->textEdit_2->clear();
            ui->textEdit_2->setPlainText(mas5[5]);
            QChar t=ui->textEdit_2->toPlainText()[0];
            while(msg.next())
            {
                ui->TEXT->append("");

                if (msg.value("id").toInt()!=id1)
                {
                    ui->TEXT->append("");
                k="select num,nik from bd where id="+msg.value("id").toString().toStdString();
                h.exec(k.c_str());
                h.next();

                k=":/img/"+h.value("num").toString().toStdString()+".jpg";
                ui->TEXT->append("");
                ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"25\" height=\"25\">").arg(k.c_str()));
                ui->TEXT->insertPlainText(h.value("nik").toString());

                if(msg.value("id").toInt()==id)
                {

                    ui->TEXT->setAlignment(Qt::AlignLeft);
                }
                else
                {
                    ui->TEXT->setAlignment(Qt::AlignRight);
                }

                id1=(msg.value("id").toInt());

                }
                ui->TEXT->append("");
                QString tt=msg.value("text").toString();

                for(int i=0 ; i<tt.size();i++)
                {

                    if(tt[i]<=t)
                    {
                        int ii=-1;
                        while(ii!=-2)
                        {
                         ii++;
                        ui->textEdit_2->clear();
                        ui->textEdit_2->setPlainText(mas5[ii]);
                        if(ui->textEdit_2->toPlainText()[0]==tt[i])
                        {
                        ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg((":/img/"+std::to_string(ii+1)+".jpg").c_str()));
                        ii=-2;
                        }
                        }
                    }
                    else
                    {

                        ui->TEXT->insertPlainText(tt.at(i));
                    }
                }
                if(msg.value("num").toString().toStdString()!="0")
                {
                ui->TEXT->append("");
                k=":/img/"+msg.value("num").toString().toStdString()+".jpg";
                ui->TEXT->insertHtml(QString("<img src=\"%1\" width=\"70\" height=\"70\">").arg(k.c_str()));
                }
            }
        }
    }
}
void Menu::stop()
{
    if(LLL)
    {
        time->start();
        LLL=false;
    }
    else
    {
        time->stop();
        LLL=true;
    }
}





