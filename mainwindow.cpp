#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>


class Point{
public:
    float x,y;
    Point(float x,float y){
        this->x=x;
        this->y=y;
    };
};

class Piece{
public:
    int num;
    std::vector<Point> vertex;
    float rad;
    float S;
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)//描画イベント
{

    Piece test;

    test.num=4;
    test.vertex.push_back(Point(10,10));
    test.vertex.push_back(Point(10,100));
    test.vertex.push_back(Point(100,100));
    test.vertex.push_back(Point(100,10));
    test.rad=60;
    test.S=100;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);//アンチエイリアスセット
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));

    QPointF point[4];

    for(int i=0;i<test.num;i++){
        point[i]=QPointF(test.vertex[i].x, test.vertex[i].y);
    }

    painter.drawPolygon(point, test.num);

//    for(int i=0; i<test.num ;i++){
//        QPoint point1(test.vertex[i].x, test.vertex[i].y);
//        QPoint point2(test.vertex[i+1].x, test.vertex[i+1].y);
//        painter.drawLine(point1, point2);
//    }
//    QPoint point1(test.vertex[test.num-1].x, test.vertex[test.num-1].y);
//    QPoint point2(test.vertex[0].x, test.vertex[0].y);
//    painter.drawLine(point1, point2);

}
