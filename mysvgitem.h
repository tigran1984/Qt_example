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

//==================
// SETTERS & GETTERS
void setSize(QSizeF size);
/*inl*/ void setSize(qreal width, qreal height);
QSizeF size();

//================================================== ======
// REIMPLEMENTATION OF VIRTUAL METHODS OF QGRAPHICSSVGITEM
void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
QRectF boundingRect();

private:
QSizeF size_m;
};

inline void MySvgItem::setSize(qreal width, qreal height) { setSize(QSizeF(width, height)); }
#endif
