#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_commandToolButton_clicked();

    void on_icontoolButton_clicked();

    void on_buttonBox_accepted();


    void on_buttonBox_rejected();

private:
    Ui::MainWindow *ui;
    QString command;
    QString iconPath;
    void writeShortcut();
    QString getShortcutName();
    QString getApplicationType();
    QString getShortcutCommand();
    QString getIconPath();
};

#endif // MAINWINDOW_H
