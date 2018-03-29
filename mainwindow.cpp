#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::zip(QString filename, QString zip_filename)
{
    QFile infile(filename);
    QFile outfile(zip_filename);
    if (!infile.open(QIODevice::ReadOnly))
        QMessageBox::critical(this, "Ошибка", "Ошибка открытия файла для архивирования");
    if (!outfile.open(QIODevice::WriteOnly))
        QMessageBox::critical(this, "Ошибка", "Ошибка сохрания файла архива");
    QByteArray uncompressed_data = infile.readAll();
    QByteArray compressed_data = qCompress(uncompressed_data, 9);
    outfile.write(compressed_data);
    infile.close();
    outfile.close();
}

void MainWindow::unZip(QString zip_filename, QString filename)
{
    QFile infile(zip_filename);
    QFile outfile(filename);
    if (!infile.open(QIODevice::ReadOnly))
        QMessageBox::critical(this, "Ошибка", "Ошибка открытия файла для разархивирования");
    if (!outfile.open(QIODevice::WriteOnly))
        QMessageBox::critical(this, "Ошибка", "Ошибка сохранения разархивированного файла");
    QByteArray uncompressed_data = infile.readAll();
    QByteArray compressed_data = qUncompress(uncompressed_data);
    outfile.write(compressed_data);
    infile.close();
    outfile.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_choose_a_clicked()
{
    FileName_to_compress = ui->lineEdit_choose_a->text();

    FileName_to_compress = QFileDialog::getOpenFileName(this,
        tr("Открыть файл..."), FileName_to_compress , tr("All files (*.*)"));

    if (!FileName_to_compress.isEmpty()){
        ui->lineEdit_choose_a->setText(FileName_to_compress);
        FileName_file_compress = ui->lineEdit_choose_a->text() + ".mzip";
        ui->lineEdit_create_a->setText(FileName_file_compress);
    }
}

void MainWindow::on_lineEdit_choose_a_textChanged(const QString &arg1)
{
    if (!FileName_to_compress.isEmpty()){
        FileName_to_compress = ui->lineEdit_choose_a->text();
        FileName_file_compress = ui->lineEdit_choose_a->text() + ".mzip";
        ui->lineEdit_create_a->setText(FileName_file_compress);
    }
}

void MainWindow::on_pushButton_create_a_clicked()
{
    FileName_file_compress = ui->lineEdit_create_a->text();

    FileName_file_compress = QFileDialog::getSaveFileName(this,
        tr("Сохранить в файл..."), FileName_file_compress , tr("M-zip files (*.mzip)"));

    if (!FileName_file_compress.isEmpty())
        ui->lineEdit_create_a->setText(FileName_file_compress);
}

void MainWindow::on_lineEdit_create_a_textChanged(const QString &arg1)
{
    FileName_file_compress = ui->lineEdit_create_a->text();
}


void MainWindow::on_pushButton_compess_clicked()
{
    FileName_to_compress = ui->lineEdit_choose_a->text();
    FileName_file_compress = ui->lineEdit_create_a->text();

    zip(FileName_to_compress, FileName_file_compress);
    ui->statusBar->showMessage("Архивирование завершено.");

}

void MainWindow::on_pushButton_choose_r_clicked()
{
    FileName_to_uncompress = ui->lineEdit_choose_r->text();

    FileName_to_uncompress = QFileDialog::getOpenFileName(this,
        tr("Открыть файл..."), FileName_to_uncompress , tr("M-zip files (*.mzip)"));

    if (!FileName_to_uncompress.isEmpty()){
        ui->lineEdit_choose_r->setText(FileName_to_uncompress);
        if (ui->lineEdit_choose_r->text().contains(".mzip"))
            FileName_file_uncompress = ui->lineEdit_choose_r->text().remove(".mzip");
        ui->lineEdit_create_r->setText(FileName_file_uncompress);
    }
}

void MainWindow::on_lineEdit_choose_r_textChanged(const QString &arg1)
{
    if (!FileName_to_uncompress.isEmpty()){
        FileName_to_uncompress = ui->lineEdit_choose_r->text();
        if (ui->lineEdit_choose_r->text().contains(".mzip"))
            FileName_file_uncompress = ui->lineEdit_choose_r->text().remove(".mzip");
        ui->lineEdit_create_r->setText(FileName_file_uncompress);
    }
}

void MainWindow::on_pushButton_create_r_clicked()
{
    FileName_file_uncompress = ui->lineEdit_create_r->text();

    FileName_file_uncompress = QFileDialog::getSaveFileName(this,
        tr("Сохранить в файл..."), FileName_file_uncompress , tr("All files (*.*)"));

    if (!FileName_file_uncompress.isEmpty())
        ui->lineEdit_create_r->setText(FileName_file_uncompress);
}

void MainWindow::on_lineEdit_create_r_textChanged(const QString &arg1)
{
    FileName_file_uncompress = ui->lineEdit_create_r->text();
}

void MainWindow::on_pushButton_uncompess_clicked()
{
     FileName_to_uncompress = ui->lineEdit_choose_r->text();
     FileName_file_uncompress = ui->lineEdit_create_r->text();

     unZip(FileName_to_uncompress, FileName_file_uncompress);
     ui->statusBar->showMessage("Разархивирование завершено.");
}





