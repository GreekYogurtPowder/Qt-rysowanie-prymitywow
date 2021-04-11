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

    //for(int l=0; l<sizeX; l++) { //kolorowanie calego tla

        //for (int c=0; c<sizeY; c++) {

            //image.setPixel(l, c, qRgb(100, 150, 200));

        //}

    //}



    //rysowanie kwadratu
    /*for (int wysokosc = 0; wysokosc < sizeX; wysokosc++)
    {
        for (int szerokosc = 0; szerokosc < sizeY; szerokosc++)
        {

            if (wysokosc == 100 || wysokosc == 300)
            {
                if (szerokosc >= 100 && szerokosc <= 300)
                {
                    image.setPixel(wysokosc, szerokosc, qRgb(100, 150, 200));
                }
            } else if (szerokosc == 100 || szerokosc == 300)
            {
                if (wysokosc >= 100 && wysokosc <= 300)
                {
                    image.setPixel(wysokosc, szerokosc, qRgb(100, 150, 200));
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
                    image.setPixel(wysokosc, szerokosc, qRgb(100, 150, 200)); //image.setPixel(szerokosc, wysokosc, qRgb(100, 150, 200)); //pionowa, pozioma
                }
            }
        }
    }*/



    int x = 250;
    int y = 450;

    //rysowanie trojkata
    for (int wysokosc = 0; wysokosc < sizeX; wysokosc++)
    {
        for (int szerokosc = 0; szerokosc < sizeY; szerokosc++)
        {

            if (wysokosc == 500)
            {
                if (szerokosc >= 100 && szerokosc <= 500)
                {
                    image.setPixel(szerokosc, wysokosc, qRgb(100, 150, 200)); //linia pozioma
                }
            } else if (szerokosc == x) //skosna
            {
                if (wysokosc >= 200 && wysokosc <= 500)
                {
                    x--;
                    //y++;
                    image.setPixel(szerokosc, wysokosc, qRgb(100, 150, 200));

                }
            } else if (szerokosc == y)
            {
                if (wysokosc >= 200 && wysokosc <= 500)
            {
                y++;
                image.setPixel(szerokosc, wysokosc, qRgb(100, 150, 200));

            }
        }

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

