#include "mysquare.h"
#include "mysvgitem.h"
#include<QTranslator>

MySquare::MySquare()
        :QGraphicsItem()
{
    myItemRect = QRectF(0,0,150,70); //default value
    setFlag(ItemIsMovable);
    QGraphicsTextItem *text = new QGraphicsTextItem("description",this);
    text->setTextInteractionFlags(Qt::TextEditorInteraction);
    //text->setPos(105, 75);
    text->setPos(55, 25);
    setMyPolygon();//member function
    setFlag(ItemSendsScenePositionChanges, true);
}

QRectF MySquare::boundingRect() const
{
    return myItemRect;
}

void MySquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

{
    QRectF rect = boundingRect();
    QBrush brush(Qt::green);
    QPainterPath path;
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
    painter->drawPath(path);


}





void MySquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Pressed = true;
    //update();
    QGraphicsItem::mousePressEvent(event);
}

void MySquare::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //Pressed = false;
    //update();
    QGraphicsItem::mouseReleaseEvent(event);
}


//QVariant MySquare::itemChange(GraphicsItemChange change, const QVariant &value)
//{
//    if (change == QGraphicsItem::ItemPositionChange) {
//        foreach (Arrow *arrow, arrows) {
//            arrow->updatePosition();
//        }
//       qDebug() << "helooooooo" ;
//    }
//
//    return value;
//}



QVariant MySquare::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange && scene()) {
        foreach (Arrow *arrow, arrows) {
            arrow->updatePosition();
        }
    }
    return QGraphicsItem::itemChange(change, value);
}

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


void MySquare::setItemSize(qreal width,qreal height)
{
     myItemRect = QRectF(0,0,width,height);
}

void MySquare::setImage(QString str) 
{
    QGraphicsItem  *m_svgItem = new QGraphicsSvgItem(\
            QCoreApplication::applicationDirPath() + "/" + str);
    Q_ASSERT(!m_svgItem.isNull());
    m_svgItem->setPos(5,5);
    m_svgItem->setParentItem(this);
}

void MySquare::setImage(QString str ,qreal w, qreal h) 
{
    //QGraphicsSvgItem  *svg = new QGraphicsSvgItem(\
            QCoreApplication::applicationDirPath() + "/" + str);
    MySvgItem  *svg = new MySvgItem(\
            QCoreApplication::applicationDirPath() + "/" + str +"h");
    svg->setSize(w,h);
    //svg->setMaximumCacheSize(QSize(35,35));
    QGraphicsItem  *m_svgItem = svg; 
    //m_svgItem->setPos(5,5);
    m_svgItem->setParentItem(this);
}
