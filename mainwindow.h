#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QBytearray>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void zip(QString filename , QString zip_filename);
    void unZip(QString zip_filename , QString filename);

    ~MainWindow();

private slots:
    void on_pushButton_choose_a_clicked();

    void on_pushButton_create_a_clicked();

    void on_pushButton_compess_clicked();

    void on_pushButton_choose_r_clicked();

    void on_pushButton_create_r_clicked();

    void on_pushButton_uncompess_clicked();

    void on_lineEdit_choose_a_textChanged(const QString &arg1);

    void on_lineEdit_create_a_textChanged(const QString &arg1);

    void on_lineEdit_choose_r_textChanged(const QString &arg1);

    void on_lineEdit_create_r_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QString FileName_to_compress;
    QString FileName_file_compress;
    QString FileName_to_uncompress;
    QString FileName_file_uncompress;
};

#endif // MAINWINDOW_H
