#ifndef MYSVGIEM_H
#define MYSVGIEM_H
#include<QRectF>
#include<QSizeF>
#include<QGraphicsSvgItem>
#include <QGraphicsSvgItem>

class MySvgItem : public QGraphicsSvgItem
{
public:
        MySvgItem(QGraphicsItem* parent = 0);
        MySvgItem(const QString& fileName, QGraphicsItem* parent = 0);
        void set_size(QSizeF size);
        /*inl*/ void set_size(qreal width, qreal height);
        QSizeF size();
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
        QRectF boundingRect();
private:
        QSizeF size_m;
};

inline void MySvgItem::set_size(qreal width, qreal height) { set_size(QSizeF(width, height)); }
#endif
