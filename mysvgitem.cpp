#include "mysvgitem.h"
#include <QSvgRenderer>
#include <QStyleOptionGraphicsItem>

MySvgItem::MySvgItem(QGraphicsItem* parent)
    : QGraphicsSvgItem(parent), size_m(-1.0, -1.0)
{
}

MySvgItem::MySvgItem(const QString& fileName, QGraphicsItem* parent)
    : QGraphicsSvgItem(fileName, parent), size_m(-1.0, -1.0)
{
}

void MySvgItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    //QGraphicsSvgItem::paint(painter, option, widget);

    Q_UNUSED(widget);
    Q_UNUSED(option);
    
    if (!renderer()->isValid())
        return;
    
    if (elementId().isEmpty())
        renderer()->render(painter, boundingRect());
    else
        renderer()->render(painter, elementId(), boundingRect());
}

void MySvgItem::set_size(QSizeF size)
{
    if (size_m != size) {
        prepareGeometryChange();
        size_m = size;
        update(boundingRect());
    }
}

QSizeF MySvgItem::size()
{
    qreal width = size_m.width();
    qreal height = size_m.height();
    
    if (size_m.width() < 0) {
        width = (renderer()->boundsOnElement(elementId()).size().width());
    }
    
    if (size_m.height() < 0) {
        height = (renderer()->boundsOnElement(elementId()).size().width());
    }
    
    return QSizeF(width, height);
}

QRectF MySvgItem::boundingRect()
{
    return QRectF(QPointF(0.0, 0.0), size());
}

