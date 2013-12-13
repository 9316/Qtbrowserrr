#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore> //სუპერ კლასი
#include <QtGui> //გუი აპლიკაცის კლასი
#include <QtWebKit>//QWeb კლასი
#include <QFileDialog>//დილაოგური ფანჯრის კლასი
#include <QTextStream>//ნაკადების შეტანა გამოტანის კლასი
#include <QMessageBox>
#include <QTextCodec>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    setWindowTitle("Nika Browser"); //მთავარ ფანჯარაზე სახელის დარქმევა
    this->showMaximized(); //გახსინას თავიდანვე დიდი ზომა რომ იყოს
    model =new QStringListModel(this); //სტრინგების მასივის მოდელის ობიექტზე მიმთითებელ(model)მივანიჭეთ QStringListModel-ის ობიექტი
    file = new QFile("favorite"); //
    if(file->open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(file); //ფაილის მითითება
        fav = in.readAll().split("#"); //fav მასივის წაკითხვა და დაყოფა #
        

        fav.append(ui->lineEdit->text()); //fav მასივში LineEdit ტექსტის ჩაწერა
        QFile fileout("favorite"); //მისამართის გადაცემა
        if(fileout.open(QFile::WriteOnly | QFile::Text | QFile::Append)){
            QTextStream out(&fileout);//ფაილის მითითება თუ სად ჩაწეროს
            out<<"#"<<fav[fav.size()-1]; //ბოლო წევრის ჩაწერა მასივში
        }

           ui->comboBox->addItem(ui->lineEdit->text()); //კომბობოქსში ელემენტის დამატება
           file->close();
           model->setStringList(fav); //model-ს ვაფუძნებთ fav მასივზე
           ui->comboBox->setModel(model); //კომბობოქსი დავაფუძნეთ model-ზე


    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    url = ui->lineEdit->text(); // url ცვლადი

    ui->webView->load(QUrl("http://" +url));
}

void MainWindow::on_pushButton_6_clicked()
{
    fav.append(ui->lineEdit->text());
    QFile fileout("favorite");
    if(fileout.open(QFile::WriteOnly | QFile::Text | QFile::Append)){
        QTextStream out (&fileout);
        out<<"#"<<fav[fav.size()-1];
    }
    ui->comboBox->addItem(ui->lineEdit->text());
    QMessageBox::information(this, "ინფორმაცია", "<font size=4>საიტი დამატებულია</font>");

}


