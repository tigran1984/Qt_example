#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsItemGroup>
#include<QGraphicsPixmapItem>
#include<QDebug>
#include<QPainterPath>
#include<QPointF>
#include<QRectF>
#include<QImage>
#include<QCoreApplication>
#include <QString>
#include <QList>
#include <QVariant>
#include <QtSvg>
#include <typeinfo>
#include "mysquare.h"

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView(QGraphicsScene * scene, QWidget * parent = 0);
    MyGraphicsView(QWidget * parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};
#endif // MYGRAPHICSVIEW_H
