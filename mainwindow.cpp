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
    image.fill(QColor(255, 123, 123)); //wypelnienie bialym kolorem

    //rysowanie prostokata
    /*int margines_x = 200;
    int margines_y = 100;
    int dlugosc_boku_x = 200;
    int dlugosc_boku_y = 300;

    for (int wysokosc = 0; wysokosc < sizeX; wysokosc++)
    {
        for (int szerokosc = 0; szerokosc < sizeY; szerokosc++)
        {

            if (wysokosc == margines_y || wysokosc == margines_y + dlugosc_boku_y)
            {
                if (szerokosc >= margines_x && szerokosc <= margines_x + dlugosc_boku_x)
                    image.setPixel(szerokosc, wysokosc, qRgb(0, 0, 0));

            } else if (szerokosc == margines_x || szerokosc == margines_x + dlugosc_boku_x)
            {
                if (wysokosc >= margines_y && wysokosc <= margines_y + dlugosc_boku_y)
                    image.setPixel(szerokosc, wysokosc, qRgb(0, 0, 0));
            }

        }
    }*/


    //rysowanie linii
    /*int margines_x = 200;
    int margines_y = 100;
    int dlugosc = 200;

    for (int wysokosc = 0; wysokosc < sizeX; wysokosc++)
    {
        for (int szerokosc = 0; szerokosc < sizeY; szerokosc++)
        {

            //pozioma
            if (wysokosc == margines_y)
            {
                if (szerokosc >= margines_x && szerokosc <= margines_x + dlugosc)
                {               
                    image.setPixel(szerokosc, wysokosc, qRgb(0, 0, 0));
                }
            }

            //pionowa
            if (szerokosc == margines_x)
            {
                if (wysokosc >= margines_y && wysokosc <= margines_y + dlugosc)
                {
                    image.setPixel(szerokosc, wysokosc, qRgb(0, 0, 0));
                }
            }
        }
    }*/

    //rysowanie linii algorytmem bresenham
    //punkt startowy
    int x1 = 100;
    int y1 = 150;

    //punkt koncowy
    int x2 = 500;
    int y2 = 250;

    int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new - (x2 - x1);

    for(int x = x1, y = y1; x <= x2; x++) {
        image.setPixel(x, y, qRgb(0, 0, 0));

        slope_error_new += m_new;

        if(slope_error_new >= 0) {
            y++;
            slope_error_new -= 2 * (x2 - x1);
        }
    }

    //rysowanie trojkata
    /*int margines_x = 200;
    int margines_y = 100;
    int dlugosc_boku = 200;
    int wskaznik_skosnej_1 = margines_x + dlugosc_boku/2;
    int wskaznik_skosnej_2 = margines_x + dlugosc_boku/2;

    for (int wysokosc = 0; wysokosc < sizeX; wysokosc++)
    {
        for (int szerokosc = 0; szerokosc < sizeY; szerokosc++)
        {
            if (wysokosc >= margines_y && wysokosc < margines_y + dlugosc_boku/2)
            {
                if (szerokosc == wskaznik_skosnej_1 || szerokosc == wskaznik_skosnej_2) //linie skosne
                    image.setPixel(szerokosc, wysokosc, qRgb(0, 0, 0));
            }

            if (wysokosc == margines_y + dlugosc_boku/2) //linia pozioma
            {
                if (szerokosc >= margines_x && szerokosc <= margines_x + dlugosc_boku)
                    image.setPixel(szerokosc, wysokosc, qRgb(0, 0, 0));
            }

        }

        if (wysokosc >= margines_y && wysokosc < margines_y + dlugosc_boku)
        {
            wskaznik_skosnej_1--;
            wskaznik_skosnej_2++;
        }
    }*/

    QGraphicsScene *graphic = new QGraphicsScene(this);

    graphic->addPixmap(QPixmap::fromImage(image));

    ui->graphicsView->setScene(graphic);
}

MainWindow::~MainWindow()
{
    delete ui;
}



