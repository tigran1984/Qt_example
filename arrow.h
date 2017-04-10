#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>

#include <QDebug>
#include "mysquare.h"
class MySquare;


class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;

class Arrow : public QGraphicsLineItem
{
public:
    enum { Type = UserType + 4 };

    Arrow(MySquare *startItem, MySquare *endItem, QGraphicsItem *parent = 0);
    //Arrow(qreal x1, qreal x2, qreal x3, qreal x4, QGraphicsItem *parent = 0);

    int type() const Q_DECL_OVERRIDE { return Type; }
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void setColor(const QColor &color) { myColor = color; }
    MySquare *startItem() const { return myStartItem; }
    MySquare *endItem() const { return myEndItem; }

    void updatePosition();
    ~Arrow();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

private:
    MySquare *myStartItem;
    MySquare *myEndItem;
    QColor myColor;
    QPolygonF arrowHead;
};

#endif // ARROW_H
 
