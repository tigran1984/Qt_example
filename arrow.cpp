#include "arrow.h"


const qreal Pi = 3.14;

Arrow::Arrow(MySquare *startItem, MySquare *endItem,QGraphicsItem *parent  )
    : QGraphicsLineItem(parent)
{
    myStartItem = startItem;
    myEndItem = endItem;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    myColor = Qt::black;
    setPen(QPen(myColor, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    setZValue(-1000);
}

QRectF Arrow::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

QPainterPath Arrow::shape() const
{
    QPainterPath path = QGraphicsLineItem::shape();
    path.addPolygon(arrowHead);
    return path;
}

void Arrow::updatePosition()
{
    QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    setLine(line);
    //qDebug() << myEndItem->x() << "myEndItem pos.x()" << myEndItem->y() << "myEndItem pos.y()" ; 
}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
          QWidget *)
{
    if (myStartItem->collidesWithItem(myEndItem))
        return;

    QPen myPen = pen();
    myPen.setColor(myColor);
    qreal arrowSize = 5;
    painter->setRenderHint(QPainter::Antialiasing); 
    painter->setPen(myPen);
    painter->setBrush(myColor);

    QLineF centerLine(myStartItem->returnCenter(), myEndItem->returnCenter());
    myEndItem->setMyPolygon();// update item polygon values
    QPolygonF endPolygon = myEndItem->polygon();
    //QPointF p1 = endPolygon.first() + myEndItem->returnCenter();
    QPointF p1 = endPolygon.first() ; // changed for test
    QPointF p2;
    QPointF intersectPoint;
    QLineF polyLine;
    for (int i = 1; i < endPolygon.count(); ++i) {
    //p2 = endPolygon.at(i) + myEndItem->returnCenter();
    p2 = endPolygon.at(i);//changed for test
    polyLine = QLineF(p1, p2);
    QLineF::IntersectType intersectType =
        polyLine.intersect(centerLine, &intersectPoint);
    if (intersectType == QLineF::BoundedIntersection)
        break;
        p1 = p2;
    }

    setLine(QLineF(intersectPoint, myStartItem->returnCenter()));
    //setLine(QLineF(myEndItem->pos()+myEndItem->returnCenter(), myStartItem->pos()+myStartItem->returnCenter()));//before test
    //setLine(QLineF(myEndItem->returnCenter(), myStartItem->returnCenter()));//changed for test

    double angle = ::acos(line().dx() / line().length());
    if (line().dy() >= 0)
        angle = (Pi * 2) - angle;

        QPointF arrowP1 = line().p1() + QPointF(sin(angle + Pi / 3) * arrowSize,
                                        cos(angle + Pi / 3) * arrowSize);
        QPointF arrowP2 = line().p1() + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                        cos(angle + Pi - Pi / 3) * arrowSize);

        arrowHead.clear();
        arrowHead << line().p1() << arrowP1 << arrowP2;
        painter->drawLine(line());
        painter->drawPolygon(arrowHead);
        if (isSelected()) {
            painter->setPen(QPen(myColor, 1, Qt::DashLine));
        QLineF myLine = line();
        myLine.translate(0, 4.0);
        painter->drawLine(myLine);
        myLine.translate(0,-8.0);
        painter->drawLine(myLine);
    }
}


