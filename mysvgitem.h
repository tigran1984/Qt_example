#ifndef MYSVGIEM_H
#define MYSVGIEM_H
#include<QRectF>
#include<QSizeF>
#include<QGraphicsSvgItem>

class MySvgItem: public QGraphicsSvgItem
{
public:
    MySvgItem(const QString &path);
    MySvgItem(const QString &path,qreal width,qreal height);
    QRectF boundingRect() const;
    void setSize(qreal w, qreal h);

private:
    qreal MyWidth;
    qreal MyHeight;
};

#endif
