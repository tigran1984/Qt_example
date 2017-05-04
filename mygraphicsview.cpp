#include<QDebug> 
#include "mygraphicsview.h" 
#include "mysquare.h" 

MyGraphicsView::MyGraphicsView( QWidget * )
         : QGraphicsView ()
{
}

MyGraphicsView::MyGraphicsView(QGraphicsScene * scene, QWidget * )
         : QGraphicsView (scene)
{
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    QGraphicsItem * item = itemAt(event->pos());

    if (item->type()!= 13)
        return;
    //qDebug() << item->type();
    QPointF p = event->pos(); // relative to page-view
    QRectF r = item->sceneBoundingRect(); // relative to scene
    QPointF tl = mapFromScene(r.topLeft());
    QPointF br = mapFromScene(r.bottomRight());

    if (p.x() <= tl.x()+3 || p.x() >= br.x()-3)
        item->setCursor(Qt::SizeHorCursor);
    else if (p.y() <= tl.y()+3 || p.y() >= br.y()-3)
        item->setCursor(Qt::SizeVerCursor);
    else
        item->setCursor(Qt::OpenHandCursor);

}
