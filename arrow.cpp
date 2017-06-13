#include "arrow.h"
#include <math.h>
#include <QPen>
#include <QPainter>

const qreal Pi = 3.14;

        Arrow::Arrow(MySquare *start_item, MySquare *end_item,
                     QGraphicsItem *parent  )
        : QGraphicsLineItem(parent)
{
        m_my_start_item = start_item;
        m_my_end_item = end_item;
        setFlag(QGraphicsItem::ItemIsSelectable, true);
        m_color = Qt::black;
        setPen(QPen(m_color, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
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
        path.addPolygon(m_arrow_head);
        return path;
}

void Arrow::update_position()
{
        QLineF line(mapFromItem(m_my_start_item, 0, 0),
                    mapFromItem(m_my_end_item, 0, 0));
        setLine(line);
        //this->setOpacity(m_my_start_item->opacity());
}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                QWidget *)
{
        if (m_my_start_item->collidesWithItem(m_my_end_item)){
                return;
        }
        QPen myPen = pen();
        myPen.setColor(m_color);
        qreal arrow_size = 5;
        painter->setRenderHint(QPainter::Antialiasing); 
        painter->setPen(myPen);
        painter->setBrush(m_color);
        //QLineF centerLine(m_my_start_item->return_center(),
        //m_my_end_item->return_center());
        //m_my_end_item->set_my_polygon();// update item polygon values
        //QPolygonF endPolygon = m_my_end_item->polygon();
        //QPointF p1 = endPolygon.first() ; // changed for test
        //QPointF p2;
        //QPointF intersectPoint;
        //QLineF polyLine;
        //for (int i = 1; i < endPolygon.count(); ++i) {
        ////p2 = endPolygon.at(i) + m_my_end_item->return_center();
        //p2 = endPolygon.at(i);//changed for test
        //polyLine = QLineF(p1, p2);
        //QLineF::IntersectType intersect_type =
        //    polyLine.intersect(centerLine, &intersectPoint);
        //if (intersect_type == QLineF::BoundedIntersection)
        //    break;
        //    p1 = p2;
        //}
        QPointF intersect_point1 = get_intersect_point(m_my_start_item);
        QPointF intersect_point2 = get_intersect_point(m_my_end_item);
        //setLine(QLineF(intersectPoint, m_my_start_item->return_center()));
        setLine(QLineF(intersect_point1, intersect_point2));
        double angle = ::acos(line().dx() / line().length());
        if (line().dy() >= 0)
                angle = (Pi * 2) - angle;
        QPointF arrow_p1 = line().p1() + QPointF(sin(angle + Pi / 3) * arrow_size,
                          cos(angle + Pi / 3) * arrow_size);
        QPointF arrow_p2 = line().p1() + QPointF(sin(angle + Pi - \
                          Pi / 3) * arrow_size, cos(angle + Pi - \
                          Pi / 3) * arrow_size);
        m_arrow_head.clear();
        m_arrow_head << line().p1() << arrow_p1 << arrow_p2;
        painter->drawLine(line());
        painter->drawPolygon(m_arrow_head);
        if (isSelected()) {
                painter->setPen(QPen(m_color, 1, Qt::DashLine));
                QLineF myLine = line();
                myLine.translate(0, 4.0);
                painter->drawLine(myLine);
                myLine.translate(0,-8.0);
                painter->drawLine(myLine);
        }
}

QPointF Arrow::get_intersect_point(MySquare * my_sqr_item)
{
        QLineF centerLine(m_my_start_item->return_center(),
                          m_my_end_item->return_center());
        my_sqr_item->set_my_polygon();// update item polygon values
        QPolygonF polygon = my_sqr_item->polygon();
        QPointF p1 = polygon.first() ; // changed for test
        QPointF p2;
        QPointF intersect_point;
        QLineF polyLine;
        for (int i = 1; i < polygon.count(); ++i) {
                //p2 = endPolygon.at(i) + m_my_end_item->return_center();
                p2 = polygon.at(i);//changed for test
                polyLine = QLineF(p1, p2);
                QLineF::IntersectType intersect_type =
                        polyLine.intersect(centerLine, &intersect_point);
                if (intersect_type == QLineF::BoundedIntersection)
                        break;
                p1 = p2;
        }
        return intersect_point;
}
Arrow::~Arrow()
{
        //delete m_my_start_item;
        //delete m_my_end_item;
        //
}
