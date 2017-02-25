#ifndef MYGROUP_H
#define MYGROUP_H
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsItemGroup>
#include<QDebug>
#include<QPainterPath>
class MyGroup : public QGraphicsItemGroup
{
public:
    MyGroup();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool Pressed;
    protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};
#endif // MYGROUP_H
