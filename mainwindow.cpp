#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int sizeX = 600;
    int sizeY = 600;

    QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);
    image.fill(QColor(255, 255, 255)); //wypelnienie bialym kolorem

    //rysowanie kwadratu
    /*for (int wysokosc = 0; wysokosc < sizeX; wysokosc++)
    {
        for (int szerokosc = 0; szerokosc < sizeY; szerokosc++)
        {

            if (wysokosc == 100 || wysokosc == 300)
            {
                if (szerokosc >= 100 && szerokosc <= 300)
                {
                    image.setPixel(wysokosc, szerokosc, qRgb(0, 0, 0));
                }
            } else if (szerokosc == 100 || szerokosc == 300)
            {
                if (wysokosc >= 100 && wysokosc <= 300)
                {
                    image.setPixel(wysokosc, szerokosc, qRgb(0, 0, 0));
                }
            }

        }
    }*/

    /*
    //rysowanie linii
    for (int wysokosc = 0; wysokosc < sizeX; wysokosc++)
    {
        for (int szerokosc = 0; szerokosc < sizeY; szerokosc++)
        {

            if (wysokosc == 100)
            {
                if (szerokosc >= 100 && szerokosc <= 500)
                {
                    image.setPixel(wysokosc, szerokosc, qRgb(0, 0, 0)); //image.setPixel(szerokosc, wysokosc, qRgb(0, 0, 0)); //pionowa, pozioma
                }
            }
        }
    }*/



    int x = 300;
    int y = 300;

    //rysowanie trojkata
    for (int wysokosc = 0; wysokosc < sizeX; wysokosc++)
    {
        for (int szerokosc = 0; szerokosc < sizeY; szerokosc++)
        {
            if (wysokosc >= 300 && wysokosc < 500)
            {
                if (szerokosc == x || szerokosc == y) //linie skosne
                    image.setPixel(szerokosc, wysokosc, qRgb(0, 0, 0));
            }

            if (wysokosc == 500) //linia pozioma
            {
                if (szerokosc >= 100 && szerokosc <= 500)
                    image.setPixel(szerokosc, wysokosc, qRgb(0, 0, 0));
            }

        }

        if (wysokosc >= 300 && wysokosc < 500)
        {
            x--;
            y++;
        }
    }

    QGraphicsScene *graphic = new QGraphicsScene(this);

    graphic->addPixmap(QPixmap::fromImage(image));

    ui->graphicsView->setScene(graphic);
}

MainWindow::~MainWindow()
{
    delete ui;
}



