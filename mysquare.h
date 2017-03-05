#ifndef MYSQUARE_H
#define MYSQUARE_H
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsItemGroup>
#include<QDebug>
#include<QPainterPath>
#include<QPointF>
#include<QSizeF>
#include<QImage>
#include<QCoreApplication>
#include <QStringBuilder>
#include <QString>
#include <QTranslator>
#include <QList>
#include <QVariant>
#include <QDebug>
#include <QtSvg>
#include <QSvgGenerator>
#include "arrow.h"
class QGraphicsSvgItem;
class QPolygonF;
class Arrow;

class MySquare : public QGraphicsItem
{
public:
    MySquare();

    QRectF boundingRect() const;
    QPolygonF polygon() const { return myPolygon; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool Pressed;
    void addArrow(Arrow *arrow);
    QPointF returnCenter();
    void setMyPolygon();
    void setItemSize(qreal height,qreal width);
    void setImage(const QString& str);
    void setImage(const QString& str ,QSizeF);
 
protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;
private:
        QPolygonF myPolygon;
        QList<Arrow *> arrows;
        QRectF myItemRect;

};

#endif // MYSQUARE_H
