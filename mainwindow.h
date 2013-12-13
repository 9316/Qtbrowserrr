#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString url; //სტრინგ ცვლადი url
    QStringListModel *model; //სტრინგმასივისმოდელი model რომელიც არის ობიექტზე მიმთითებელი
    QStringList fav; //სტრინგების მასივი fav
    QFile *file; //QFile კლასის ობიექტზე მიმთითებელი file

    
private slots:


    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
