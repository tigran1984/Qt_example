#include "mysquare.h"

MySquare::MySquare()
        :QGraphicsItemGroup()
{
    myItemRect = QRectF(0,0,150,70); //default value
    setFlag(ItemSendsScenePositionChanges, true);
    setMyPolygon();//member function
    setFlags(ItemIsSelectable | ItemIsMovable);
    //QGraphicsTextItem *text = new QGraphicsTextItem("description",this);
    //text->setTextInteractionFlags(Qt::TextEditorInteraction);
    //text->setPos(55, 25);
    //this->addToGroup(text);
    QGraphicsItem  *m_svgItem = new QGraphicsSvgItem(\
            QCoreApplication::applicationDirPath() + "/image.svg");
    Q_ASSERT(!m_svgItem.isNull());
    m_svgItem->setPos(5,5);
    this->addToGroup(m_svgItem);
}

QRectF MySquare::boundingRect() const
{
    return myItemRect;
}

void MySquare::setItemSize(qreal x1,qreal y1,qreal height,qreal width)
{
     myItemRect = QRectF(x1,y1,height,width);
}

void MySquare::paint(QPainter *painter,
        const QStyleOptionGraphicsItem *option, QWidget *widget)

{
    QRectF rect = boundingRect();
    QBrush brush(Qt::green);


    QPainterPath path;
    path.addRoundedRect( rect.translated(0.3,0.3), 5.0, 5.0 );
    QFont font;
    font.setPointSize(20);
    QString mystr = "Partners and\nCustomers";
    painter->fillPath(path, Qt::white);
    painter->setPen(Qt::blue);
    painter->drawText(QRect(55, 5, 115, 35), Qt::AlignLeft, mystr );
    QPen pen(Qt::black, 1);
    painter->setPen(pen);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPath(path);

}





void MySquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItemGroup::mousePressEvent(event);
}

void MySquare::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItemGroup::mouseReleaseEvent(event);
}


QVariant MySquare::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItemGroup::ItemPositionChange && scene()) {
        foreach (Arrow *arrow, arrows) {
            arrow->updatePosition();
        }
    }
    return QGraphicsItemGroup::itemChange(change, value);
}

              // this is a mysquare itemChange implementation 
           
//QVariant MySquare::itemChange(GraphicsItemChange change, const QVariant &value)
//{
//    if (change == QGraphicsItem::ItemPositionChange && scene()) {
//        foreach (Arrow *arrow, arrows) {
//            arrow->updatePosition();
//        }
//        // value is the new position.
//        //QPointF newPos = value.toPointF();
//        //QRectF rect = scene()->sceneRect();
//        //if (!rect.contains(newPos)) {
//            // Keep the item inside the scene rect.
//        //    newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
//        //    newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
//        //    return newPos;
//        //}
//    qDebug() << "helooooooo"<< boundingRect().topLeft() << this->pos() 
//                << this->polygon();
//    }
//    return QGraphicsItem::itemChange(change, value);
//}








void MySquare::addArrow(Arrow *arrow)
{
    arrows.append(arrow);
}

QPointF MySquare::returnCenter()
{
    QRectF rect = boundingRect();
    qreal width = rect.width();
    qreal height = rect.height();
    QPointF p = QPointF(width/2 + rect.x(), rect.y() + height/2 );
    return this->pos()+p; 
}

// polygon using to find arrow and endItem rect corners intersection points.
void MySquare::setMyPolygon()
{
    QRectF rec = boundingRect();
    QPolygonF poly ;
    poly << rec.topLeft() + this->pos()  << rec.topRight() + this->pos() 
        << rec.bottomRight()  + this->pos() << rec.bottomLeft() + this->pos()
        << rec.topLeft() + this->pos();
    myPolygon =  poly;
}

