#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Application");
    ui->comboBox->addItem("Application in Terminal");
    ui->comboBox->addItem("Location");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_commandToolButton_clicked()
{
    command = QFileDialog::getOpenFileName();
    ui->commandLineEdit->setText(command);
}

void MainWindow::on_icontoolButton_clicked()
{
    QString selfilter = tr("PNG (*.png)");
    iconPath = QFileDialog::getOpenFileName(this, "Select an icon file", QString(),
                                            tr("All files (*.*);;JPEG (*.jpg *.jpeg);;TIFF (*.tif);;PNG (*.png)" ),
                                            &selfilter);
    ui->iconLineEdit->setText(iconPath);
}

QString MainWindow::getShortcutName(){
    return ui->nameLineEdit->text();
}

QString MainWindow::getApplicationType(){
    return ui->comboBox->currentText();
}

QString MainWindow::getShortcutCommand(){
    return ui->commandLineEdit->text();
}

QString MainWindow::getIconPath(){
    return ui->iconLineEdit->text();
}
void MainWindow::writeShortcut()
{
    QString filename = QFileDialog::getSaveFileName();
    QFile *File = new QFile(filename);

    if (File->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(File);
        out << "#!/usr/bin/env xdg-open" << "\n" <<
               "[Desktop Entry]" << "\n" <<
               "Version=1.0" << "\n" <<
               "Type=" << getApplicationType() << "\n" <<
               "Terminal=false" << "\n" <<
               "Icon[en_IN]=" << getIconPath() << "\n" <<
               "Name[en_IN]=" << getShortcutName() << "\n" <<
               "Exec=" << getShortcutCommand() << "\n" <<
               "Name=" << getShortcutName() << "\n" <<
               "Icon=" << getIconPath();
    }

}
void MainWindow::on_buttonBox_accepted()
{
    writeShortcut();
    this->close();
}

void MainWindow::on_buttonBox_rejected()
{
    this->close();
}
