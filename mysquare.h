#ifndef MYSQUARE_H
#define MYSQUARE_H
#include<QObject>
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsItemGroup>
#include<QGraphicsPixmapItem>
#include<QPainterPath>
#include<QPointF>
#include<QSizeF>
#include<QImage>
#include<QLabel>
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
#include "mysvgitem.h"
class QGraphicsSvgItem;
class QPolygonF;
class Arrow;

class MySquare : public QObject,  public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity);
    Q_PROPERTY(QSizeF size READ size WRITE setSize);
    Q_PROPERTY(QPointF pos READ pos WRITE setPos);
    Q_PROPERTY(qreal x READ x WRITE setX);
    Q_PROPERTY(qreal y READ y WRITE setY);
    enum resize_direction
    {
        rd_none,
        rd_left,
        rd_top,
        rd_right,
        rd_bottom,
        rd_diagonal

    };
public:
    enum { Type = UserType + 1 };
    MySquare();

    QRectF boundingRect() const;
    int type() const Q_DECL_OVERRIDE ; 
    QPolygonF polygon() const { return myPolygon; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool Pressed;
    void addArrow(Arrow *arrow);
    QPointF returnCenter();
    void setMyPolygon();
    void setItemSize(qreal height,qreal width);
    void setImage(const QString& str);
    void setImage(const QString& str ,QSize);
    void setImage(const QString& str ,QRectF rec);
    void setSvgImage(const QString& str);
    void setSvgImage(const QString& str ,QSizeF);
    void setSvgImage(const QString& str ,QRectF rec);
    void setText(const QString& str ,QRectF rec);
    QSizeF size(); 
    void setSize(QSizeF size); 
    ~MySquare();
signals:
    void click();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) ;
private:
    QPolygonF myPolygon;
    QList<Arrow *> arrows;
    QRectF myItemRect;
    QString MyText;
    QRectF MyTextRect;
    QGraphicsTextItem *itemXY;
    QString *posXY;
    resize_direction resize_direction_;
    bool clickFlag ;


};

#endif // MYSQUARE_H
