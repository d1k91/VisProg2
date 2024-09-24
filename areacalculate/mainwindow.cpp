#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    updateImage();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_calculateButton_clicked() {
    QString figure = ui->figureComboBox->currentText();
    double area = 0;

    if (figure == "Квадрат") {
        double side = ui->sideLineEdit->text().toDouble();
        area = AreaCalculator::square(side);
    } else if (figure == "Прямоугольник") {
        double length = ui->lengthLineEdit->text().toDouble();
        double width = ui->widthLineEdit->text().toDouble();
        area = AreaCalculator::rectangle(length, width);
    } else if (figure == "Параллелограмм") {
        double base = ui->baseLineEdit->text().toDouble();
        double height = ui->heightLineEdit->text().toDouble();

        area = AreaCalculator::parallelogram(base, height);
    } else if (figure == "Ромб") {
        double diagonal1 = ui->diagonal1LineEdit->text().toDouble();
        double diagonal2 = ui->diagonal2LineEdit->text().toDouble();
        area = AreaCalculator::rhombus(diagonal1, diagonal2);
    } else if (figure == "Треугольник") {
        double base = ui->baseLineEdit->text().toDouble();
        double height = ui->heightLineEdit->text().toDouble();
        area = AreaCalculator::triangle(base, height);
    } else if (figure == "Трапеция") {
        double base1 = ui->base1LineEdit->text().toDouble();
        double base2 = ui->base2LineEdit->text().toDouble();
        double height = ui->heightLineEdit->text().toDouble();
        area = AreaCalculator::trapezoid(base1, base2, height);
    } else if (figure == "Круг") {
        double radius = ui->radiusLineEdit->text().toDouble();
        area = AreaCalculator::circle(radius);
    } else if (figure == "Сектор") {
        double radius = ui->radiusLineEdit->text().toDouble();
        double angle = ui->angleLineEdit->text().toDouble();
        area = AreaCalculator::sector(radius, angle);
    }

    ui->resultLabel->setText(QString::number(area));
}

void MainWindow::on_actionAuthors_2_triggered() {
    QMessageBox::information(this, "Авторы", "Автор: Глинский Вадим");
}

void MainWindow::on_actionClear_2_triggered() {
    ui->sideLineEdit->clear();
    ui->lengthLineEdit->clear();
    ui->widthLineEdit->clear();
    ui->baseLineEdit->clear();
    ui->heightLineEdit->clear();
    ui->diagonal1LineEdit->clear();
    ui->diagonal2LineEdit->clear();
    ui->base1LineEdit->clear();
    ui->base2LineEdit->clear();
    ui->radiusLineEdit->clear();
    ui->angleLineEdit->clear();
    ui->resultLabel->clear();
}

void MainWindow::on_actionExit_2_triggered() {
    close();
}

void MainWindow::updateImage() {
    QString figure = ui->figureComboBox->currentText();
        QPixmap pixmap;

        if (figure == "Квадрат") {
            pixmap.load(":/images/square.PNG");
        } else if (figure == "Прямоугольник") {
            pixmap.load(":/images/rectangle.PNG");
        } else if (figure == "Параллелограмм") {
            pixmap.load(":/images/parallelogram.PNG");
        } else if (figure == "Ромб") {
            pixmap.load(":/images/rhombus.PNG");
        } else if (figure == "Треугольник") {
            pixmap.load(":/images/triangle.PNG");
        } else if (figure == "Трапеция") {
            pixmap.load(":/images/trapezoid.PNG");
        } else if (figure == "Круг") {
            pixmap.load(":/images/circle.PNG");
        } else if (figure == "Сектор") {
            pixmap.load(":/images/sector.PNG");
        }

        // Убедитесь, что изображение загружено
        if (!pixmap.isNull()) {
            ui->imageLabel->setPixmap(pixmap.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
        } else {
            qDebug() << "Ошибка загрузки изображения для фигуры:" << figure;
        }
}

void MainWindow::on_figureComboBox_currentIndexChanged(int index) {

    Q_UNUSED(index);
    ui->sideLineEdit->setVisible(false);
    ui->lengthLineEdit->setVisible(false);
    ui->widthLineEdit->setVisible(false);
    ui->baseLineEdit->setVisible(false);
    ui->heightLineEdit->setVisible(false);
    ui->diagonal1LineEdit->setVisible(false);
    ui->diagonal2LineEdit->setVisible(false);
    ui->base1LineEdit->setVisible(false);
    ui->base2LineEdit->setVisible(false);
    ui->radiusLineEdit->setVisible(false);
    ui->angleLineEdit->setVisible(false);

    // Отображаем QLineEdit на основе выбранной фигуры
    if (ui->figureComboBox->currentText() == "Квадрат") {
        ui->sideLineEdit->setVisible(true);
    } else if (ui->figureComboBox->currentText() == "Прямоугольник") {
        ui->lengthLineEdit->setVisible(true);
        ui->widthLineEdit->setVisible(true);
    } else if (ui->figureComboBox->currentText() == "Параллелограмм") {
        ui->baseLineEdit->setVisible(true);
        ui->heightLineEdit->setVisible(true);
    } else if (ui->figureComboBox->currentText() == "Ромб") {
        ui->diagonal1LineEdit->setVisible(true);
        ui->diagonal2LineEdit->setVisible(true);
    } else if (ui->figureComboBox->currentText() == "Треугольник") {
        ui->baseLineEdit->setVisible(true);
        ui->heightLineEdit->setVisible(true);
    } else if (ui->figureComboBox->currentText() == "Трапеция") {
        ui->base1LineEdit->setVisible(true);
        ui->base2LineEdit->setVisible(true);
        ui->heightLineEdit->setVisible(true);
    } else if (ui->figureComboBox->currentText() == "Круг") {
        ui->radiusLineEdit->setVisible(true);
    } else if (ui->figureComboBox->currentText() == "Сектор") {
        ui->radiusLineEdit->setVisible(true);
        ui->angleLineEdit->setVisible(true);
    }

    updateImage();
}

