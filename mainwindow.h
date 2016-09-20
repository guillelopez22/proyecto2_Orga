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
    void on_actionBuscar_2_triggered();

    void on_actionLoad_from_File_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
