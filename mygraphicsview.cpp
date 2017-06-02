#include "mygraphicsview.h" 

MyGraphicsView::MyGraphicsView(QGraphicsScene * scene, QWidget * )
        : QGraphicsView (scene)
{
        this->setCacheMode(QGraphicsView::CacheBackground);
        this->setRenderHints(QPainter::Antialiasing | \
                             QPainter::SmoothPixmapTransform);
        setMouseTracking(true);
        viewport()->setMouseTracking(true);
}

        MyGraphicsView::MyGraphicsView(QWidget * )
        : QGraphicsView ()
{
        this->setCacheMode(QGraphicsView::CacheBackground);
        this->setRenderHints(QPainter::Antialiasing | \
                             QPainter::SmoothPixmapTransform);
        setMouseTracking(true);
        viewport()->setMouseTracking(true);
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
        QGraphicsView::mouseMoveEvent(event);
        QGraphicsItem* item = itemAt(event->pos());
        MySquare mysqr;

        //if (item==0)
        //        return;
        ////qDebug() << "item Type ==== " << typeid(*item);
        ////item->setCursor(Qt::ArrowCursor);
        //viewport()->setCursor(Qt::ArrowCursor);
        //if(item->type() == mysqr.type()) {
        //        //qDebug() <<  "ItemType ========" << item->type();
        //        qDebug() <<  "mouseTracking ========" << hasMouseTracking();
        //        //emit item->changeCursor();
        //        bool diagl_flag = false ;
        //        QPointF mp = event->pos();
        //        QRectF mr =item->sceneBoundingRect(); // relative to scene
        //        QPointF tl = mapFromScene(mr.topLeft());
        //        QPointF br = mapFromScene(mr.bottomRight());
        //        if (mp.x() >= br.x()-10 && mp.y() >= br.y()-10) {
        //                diagl_flag = true ;
        //                //qDebug() << "rd_diagonal" ;
        //        } else {
        //                diagl_flag = false ;
        //        }
        //        if (((mp.x() <= tl.x()+10) ||( mp.x() >= br.x()-10)) && \
        //            !diagl_flag) {
        //                //item->setCursor(Qt::SizeHorCursor);
        //                viewport()->setCursor(Qt::SizeHorCursor);
        //                //qDebug() << "cs_horizotal" ;
        //                //itemXY->setPlainText("rd_left");
        //        }
        //        else if (((mp.y() <= tl.y()+10) ||(mp.y() >= br.y()-10)) && \
        //                 !diagl_flag) {
        //                //item->setCursor(Qt::SizeVerCursor);
        //                viewport()->setCursor(Qt::SizeVerCursor);
        //                //qDebug() << "cs_vertical" ;
        //        }
        //        ////// testing diagonal resize /////
        //        else if (diagl_flag) {
        //                //item->setCursor(Qt::SizeFDiagCursor);
        //                viewport()->setCursor(Qt::SizeFDiagCursor);
        //                //qDebug() << "cs_diagonal" ;
        //        } else {
        //                item->setCursor(Qt::ArrowCursor);
        //        }
        //} else {
        //        return;
        //}
        ////QPointF p = event->pos(); // relative to page-view
        ////QRectF r = item->sceneBoundingRect(); // relative to scene
        ////QPointF tl = mapFromScene(r.topLeft());
        ////QPointF br = mapFromScene(r.bottomRight());

        ////if ((p.x() <= tl.x()+10) ||( p.x() >= br.x()-10))
        ////    item->setCursor(Qt::SizeHorCursor);
        ////else if ((p.y() <= tl.y()+10) ||( p.y() >= br.y()-10))
        ////    item->setCursor(Qt::SizeVerCursor);
        ////else
        ////    item->setCursor(Qt::OpenHandCursor);
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
        QGraphicsView::mousePressEvent(event);
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
        QGraphicsView::mouseReleaseEvent(event);
}
