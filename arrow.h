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

        Arrow(MySquare *start_item, MySquare *end_item,
              QGraphicsItem *parent = 0);
        //Arrow(qreal x1, qreal x2, qreal x3, qreal x4, 
        //QGraphicsItem *parent = 0);
        //int type() const Q_DECL_OVERRIDE { return Type; }
        int type() const  { return Type; }
        //QRectF boundingRect() const Q_DECL_OVERRIDE;
        QRectF boundingRect() const ;
        //QPainterPath shape() const Q_DECL_OVERRIDE;
        QPainterPath shape() const ;
        void setColor(const QColor &color) { m_color = color; }
        MySquare *start_item() const { return m_my_start_item; }
        MySquare *end_item() const { return m_my_end_item; }
        void update_position();
        QPointF get_intersect_point(MySquare * my_sqr_item);
        ~Arrow();
protected:
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget = 0); //Q_DECL_OVERRIDE;

private:
        MySquare *m_my_start_item;
        MySquare *m_my_end_item;
        QColor m_color;
        QPolygonF m_arrow_head;
};

#endif // ARROW_H

