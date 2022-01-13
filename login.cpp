#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(DateTime()));
    timer->start(1000);
    QPixmap icon(":/login.png");
    ui->Loginicon->setPixmap(icon.scaled(80,70,Qt::KeepAspectRatio));

    ui->agences->addItems({"Directeur", "Agence de Paris", "Agence de Bordeaux", "Agence de Lyon", "Agence de Strasbourg", "Agence de Toulouse"});
    ui->datefin->setDate(QDate::currentDate());
    ui->datefin->setMaximumDate(QDate::currentDate());
}

Login::~Login()
{
    delete ui;
}

void Login::on_connexion_clicked()
{
    close();

    loginas = ui->agences->itemText(ui->agences->currentIndex());
    dd = ui->datedebut->date();
    df = ui->datefin->date();
    w = new BankSupervision(loginas, dd,df);
    w->show();
}

void Login::DateTime()
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    QString date_text = date.toString("dd / MM / yy");
    ui->DateTime->setText("Date :  "+date_text+"\n"+"Time :  " +time_text);
}


