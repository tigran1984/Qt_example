#include "mysquare.h"
#include<QTranslator>

MySquare::MySquare()
        //:QGraphicsItem()
        :QGraphicsItemGroup()
{
    //Pressed = false;
    //setFlag(ItemIsMovable);
    //QGraphicsTextItem *text = new QGraphicsTextItem("description",this);
    //text->setTextInteractionFlags(Qt::TextEditorInteraction);
    ////text->setPos(105, 75);
    //text->setPos(55, 25);
    //setMyPolygon();//member function
    //setFlag(ItemSendsScenePositionChanges, true);
    //
    //
    //
    //
    //
    setFlag(ItemSendsScenePositionChanges, true);
    setMyPolygon();//member function
    setFlags(ItemIsSelectable | ItemIsMovable);
    QGraphicsTextItem *text = new QGraphicsTextItem("description",this);
    text->setTextInteractionFlags(Qt::TextEditorInteraction);
    text->setPos(55, 25);
    this->addToGroup(text);
    QGraphicsItem  *m_svgItem = new QGraphicsSvgItem(QCoreApplication::applicationDirPath() + "/image.svg");
    Q_ASSERT(!m_svgItem.isNull());
    m_svgItem->setPos(5,5);
    //m_svgItem->setSize(35,35);
    this->addToGroup(m_svgItem);
}

QRectF MySquare::boundingRect() const
{
    //return QRectF(50,50,150,70);
    return QRectF(0,0,150,70);
}

void MySquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

{
    QRectF rect = boundingRect();
    //QRectF rect(50,50,150 ,70);
    QBrush brush(Qt::green);


    QPainterPath path;
    //path.addRoundedRect(QRectF(0, 0, 150, 50), 5,5);
    //path.addRoundedRect(rec, 10, 10);
    path.addRoundedRect( rect.translated(0.3,0.3), 5.0, 5.0 );
    QFont font;
    //font.setFamily("Armenian (phonetic)");
    font.setPointSize(20);
    QString mystr = "Partners and\nCustomers";
    //path.addText(QPointF(40,30),font, tr("Partners \nand Customers"));
    painter->fillPath(path, Qt::white);
    painter->setPen(Qt::blue);
    //painter->drawText(QRect(105, 55, 115, 35), Qt::AlignLeft, mystr );
    painter->drawText(QRect(55, 5, 115, 35), Qt::AlignLeft, mystr );
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    //painter->setBrush(brush);

    painter->setRenderHint(QPainter::Antialiasing); // this for rectangel alignment
    //painter->drawRoundedRect( rect.translated(0.5,0.5), 5.0, 5.0 ) ;
    //painter->setRenderHint(painter->HighQualityAntialiasing );
    painter->drawPath(path);

    //QImage img("/home/tiko/workspace/Qt_proj/view2/image.svg");
    //QGraphicsItem *img = new QGraphicsSvgItem("/home/tiko/workspace/Qt_proj/view2/image.svg");

    //QImage img(QCoreApplication::applicationDirPath() + "/image.svg");

    //qDebug() << "App path : " << QCoreApplication::applicationDirPath();
    
    //Q_ASSERT(!img.isNull());

    //painter->drawImage(QRect(55, 55, 35, 35), img);

    //painter->drawImage(QRect(5, 5, 35, 35), img);

    //foreach (Arrow *arrow, arrows) {
    //    arrow->updatePosition();
    //}


    //painter->drawRect(rec);
}





void MySquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Pressed = true;
    //update();
    QGraphicsItemGroup::mousePressEvent(event);
}

void MySquare::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //Pressed = false;
    //update();
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
    //return p;// changet for test 
    return this->pos()+p;// changet for test 
}

// polygon using for arrow and endItem rect corners intersection points.
void MySquare::setMyPolygon()
{
    QRectF rec = boundingRect();
    QPolygonF poly ;
    //QPointF p = rec.topLeft();
    poly << rec.topLeft() + this->pos()  << rec.topRight() + this->pos() 
        << rec.bottomRight()  + this->pos() << rec.bottomLeft() + this->pos()
        << rec.topLeft() + this->pos();
    myPolygon =  poly;
}

