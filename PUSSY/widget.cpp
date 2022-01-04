#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    bb=0;


    ui->setupUi(this);
    ui->reg_login_label->hide();
    ui->nik_label->hide();
    ui->reg_pass_label->hide();
    ui->reg_label->hide();
    ui->nik_edit->hide();
    ui->reg_login_edit->hide();
    ui->reg_pass_edit->hide();
    ui->reg2_button->hide();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bd_password");
    db.open();
    tt=QSqlDatabase::addDatabase("QPSQL","1");
    tt.setHostName("195.19.32.74");
    tt.setDatabaseName("fn1133_2021");
    tt.setPort(5432);
    tt.setUserName("student");
    tt.setPassword("bmstu");
    tt.open();
    std::string cmd;
    QSqlQuery msg(db);
    cmd="PRAGMA Foreign_keys=on";
    msg.exec(cmd.c_str());
    msg.exec("select name From sqlite_master where type='table' and name='pass'");
    if (!msg.next())
        msg.exec("CREATE TABLE pass( LOGIN Text not null, PASS Text not null)");
    msg.exec("Select COUNT(*) from pass");
    msg.next();

    mas=new QString[msg.value("COUNT(*)").toString().toInt()];
    int n=0;
    msg.exec("select LOGIN,PASS from pass");
    while(msg.next())
    {
        QListWidgetItem *item_1=new QListWidgetItem(QIcon(":/img/1.jpg"),msg.value("LOGIN").toString());
        ui->listWidget->setIconSize(QSize(100,100));
    ui->listWidget->addItem(item_1);
    mas[n]=msg.value("PASS").toString();
     n++;
    }
    QObject::connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(vibor()));
    QObject::connect(ui->autorization_button,SIGNAL(clicked()),this,SLOT(Push()));
    QObject::connect(ui->reg2_button,SIGNAL(clicked()),this,SLOT(Push2()));
    QObject::connect(ui->reg_button,SIGNAL(clicked()),this,SLOT(reg_2()));
}

Widget::~Widget()
{
    delete ui;
    delete[] mas;
}
void Widget::vibor()
{
    QSqlQuery msg(db);
    ui->login_edit->setText(ui->listWidget->currentItem()->text());
    ui->pass_edit->setText(mas[ui->listWidget->currentRow()]);
}
void Widget::Push()
{
  std::string k="select LOGIN From bd where  LOGIN='"+ui->login_edit->text().toStdString()+"' and PASS='"+ui->pass_edit->text().toStdString()+"'";
  QSqlQuery msg(tt);
  QSqlQuery msgg(db);
  msg.exec(k.c_str());
  if (msg.next())
  {

      std::string k="select LOGIN From pass where  LOGIN='"+ui->login_edit->text().toStdString()+"'";
      msgg.exec(k.c_str());
      if(!msgg.next())
      {
      k="Insert into pass(LOGIN,PASS) values ('"+ui->login_edit->text().toStdString()+"','"+ ui->pass_edit->text().toStdString()+"')";
      msgg.exec(k.c_str());
      }
      k="select id From bd where  LOGIN='"+ui->login_edit->text().toStdString()+"'";
      msg.exec(k.c_str());
      msg.next();
      Menu *m=new Menu(nullptr,msg.value(0).toInt());
      m->show();
      this->close();
      //this->deleteLater();

  }
  else
  {
      ui->pass_edit->setText("неправильный пароль");
  }
}
void Widget::Push2()
{
    std::string k="select login From bd where  LOGIN='"+ui->reg_login_edit->text().toStdString()+"'";
    QSqlQuery msg(tt);
    QSqlQuery msgg(db);
    msg.exec(k.c_str());
    if (!msg.next())
    {
        k="Insert into pass(LOGIN,PASS) values ('"+ui->reg_login_edit->text().toStdString()+"','"+ ui->reg_pass_edit->text().toStdString()+"')";
        msgg.exec(k.c_str());
        k="Select max(id) From count1";
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

        k="Create table table_1_"+std::to_string(ww)+"(id_table_1 TEXT NOT NULL,name TEXT NOT NULL,id1 int)";
        std::string i="Create table table_2_"+std::to_string(ww)+"(id_table_2 TEXT NOT NULL, id1 int)";
        std::string j="Insert into bd(id,LOGIN,PASS,NIK,num) values ("+std::to_string(ww)+",'"+ui->reg_login_edit->text().toStdString()+"','"+ ui->reg_pass_edit->text().toStdString()+"','"+ui->nik_edit->text().toStdString()+"','1')";
        std::string q="insert into table_1_"+std::to_string(ww)+"(id_table_1,name,id1) values('0','ALL',0)";
        std::string qq="insert into name_0(id, bool) values("+std::to_string(ww)+",0)";
        msg.exec(("insert into count1(id) values("+std::to_string(ww)+")").c_str());
        msg.exec(k.c_str());
        msg.exec(i.c_str());

        msg.exec(j.c_str());

        msg.exec(q.c_str());
        msg.exec(qq.c_str());
        msgg.exec("Select COUNT(*) from pass");
        msgg.next();
        delete []mas;
        mas=new QString[msgg.value("COUNT(*)").toString().toInt()];
        int n=0;
        ui->listWidget->clear();
        msgg.exec("select LOGIN,PASS from pass");
        while(msgg.next())
        {
            QListWidgetItem *item_1=new QListWidgetItem(QIcon(":/img/1.jpg"),msgg.value("LOGIN").toString());
            ui->listWidget->setIconSize(QSize(100,100));
        ui->listWidget->addItem(item_1);
        mas[n]=msgg.value("PASS").toString();
         n++;
        }


    }
    else
    {
        ui->reg_login_edit->setText("логин используется");
    }
}
void Widget::reg_2()
{
    if (bb==1)
    {
        ui->reg_login_label->hide();
        ui->nik_label->hide();
        ui->reg_pass_label->hide();
        ui->reg_label->hide();
        ui->nik_edit->hide();
        ui->reg_login_edit->hide();
        ui->reg_pass_edit->hide();
        ui->reg2_button->hide();
        bb=0;
    }
    else
    {
        ui->reg_login_label->show();
        ui->nik_label->show();
        ui->reg_pass_label->show();
        ui->reg_label->show();
        ui->nik_edit->show();
        ui->reg_login_edit->show();
        ui->reg_pass_edit->show();
        ui->reg2_button->show();
        bb=1;
    }
}

