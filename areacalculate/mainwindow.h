#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "areacalculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculateButton_clicked();
    void on_actionAuthors_2_triggered();
    void on_actionClear_2_triggered();
    void on_actionExit_2_triggered();
    void on_figureComboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    void updateImage();
};
#endif // MAINWINDOW_H
