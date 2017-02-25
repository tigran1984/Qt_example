#ifndef MYSQUARE_H
#define MYSQUARE_H
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsItemGroup>
#include<QDebug>
#include<QPainterPath>
#include<QPointF>
#include<QImage>
#include<QCoreApplication>
#include <QStringBuilder>
#include <QTranslator>

class MySquare : public QGraphicsItem
{
public:
    MySquare();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool Pressed;
    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


};

#endif // MYSQUARE_H
