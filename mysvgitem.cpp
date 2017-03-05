#include"mysvgitem.h"

MySvgItem::MySvgItem(const QString &path)
    :QGraphicsSvgItem(path)
{
    QSizeF size = this->maximumCacheSize();
    MyWidth  = size.width();
    MyHeight = size.height();
}

MySvgItem::MySvgItem(const QString &path,qreal width,qreal height)
    :QGraphicsSvgItem(path), MyWidth(width), MyHeight(height)
{
    QSizeF size = this->maximumCacheSize();
    MyWidth  = size.width();
    MyHeight = size.height();
}

QRectF MySvgItem::boundingRect() const
{
    return QRectF(0,0,MyWidth,MyHeight); 
}

void MySvgItem::setSize(qreal w, qreal h)
{
    MyWidth  = w;
    MyHeight = h;
}
