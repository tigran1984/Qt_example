#include "mysquare.h"
#include "mysvgitem.h"
#include<QTranslator>

MySquare::MySquare()
        :QGraphicsItem()
{
    myItemRect = QRectF(0,0,150,70); //default value
    setFlag(ItemIsMovable);
    setMyPolygon();//member function
    setFlag(ItemSendsScenePositionChanges, true);
}

QRectF MySquare::boundingRect() const
{
    return myItemRect;
}

void MySquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    QRectF rect = boundingRect();
    QBrush brush(Qt::green);
    QPainterPath path;
    path.addRoundedRect( rect.translated(0.3,0.3), 5.0, 5.0 );
    QFont font;
    //font.setFamily("Armenian (phonetic)");
    font.setPointSize(20);
    //QString mystr = "Partners and\nCustomers";
    //path.addText(QPointF(40,30),font, tr("Partners \nand Customers"));
    painter->fillPath(path, Qt::white);
    painter->setPen(Qt::blue);
    //painter->drawText(QRect(105, 55, 115, 35), Qt::AlignLeft, mystr );
    painter->drawText(MyTextRect, Qt::AlignLeft, MyText );
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
    emit click();
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

void MySquare::setImage(const QString& str) 
{
    QImage image(QCoreApplication::applicationDirPath() + "/" + str);

    QImage img = image;
    QGraphicsItem *item = new QGraphicsPixmapItem(\
                    QPixmap::fromImage(img));

    //item->setSize(size);
    //svg->setMaximumCacheSize(QSize(350,350));
    Q_ASSERT(!item.isNull());
    item->setParentItem(this);
}

void MySquare::setImage(const QString& str, const QSize size) 
{
    QImage image(QCoreApplication::applicationDirPath() + "/" + str);

    QImage img = image.scaled(size);
    /*QGraphicsPixmapItem* item = new QGraphicsPixmapItem(\
                    QPixmap::fromImage(image));*/
    QGraphicsItem *item = new QGraphicsPixmapItem(\
                    QPixmap::fromImage(img));

    //item->setSize(size);
    //svg->setMaximumCacheSize(QSize(350,350));
    Q_ASSERT(!item.isNull());
    item->setPos(21,11);
    item->setParentItem(this);
}

void MySquare::setImage(const QString& str ,QRectF rec) 
{
    QImage image(QCoreApplication::applicationDirPath() + "/" + str);

    QImage img = image.scaled(QSize(rec.width(),rec.height()));
    /*QGraphicsPixmapItem* item = new QGraphicsPixmapItem(\
                    QPixmap::fromImage(image));*/
    QGraphicsItem *item = new QGraphicsPixmapItem(\
                    QPixmap::fromImage(img));
    Q_ASSERT(!item.isNull());
    //item->setSize(QSize(rec.width(),rec.height()));
    item->setParentItem(this);
    item->setPos(rec.x(),rec.y());
}

void MySquare::setSvgImage(const QString& str) 
{
    QGraphicsItem  *m_svgItem = new QGraphicsSvgItem(\
            QCoreApplication::applicationDirPath() + "/" + str);
    Q_ASSERT(!m_svgItem.isNull());
    m_svgItem->setPos(5,5);
    m_svgItem->setParentItem(this);
}

void MySquare::setSvgImage(const QString& str ,QSizeF size) 
{
    /*QGraphicsSvgItem  *svg = new QGraphicsSvgItem(\
            QCoreApplication::applicationDirPath() + "/" + str);*/
    MySvgItem  *svg = new MySvgItem(\
            QCoreApplication::applicationDirPath() + "/" + str );
    svg->setSize(size);
    //svg->setMaximumCacheSize(QSize(350,350));
    Q_ASSERT(!svg.isNull());
    QGraphicsItem  *m_svgItem = svg; 
    //m_svgItem->setPos(5,5);
    m_svgItem->setParentItem(this);
    m_svgItem->setZValue(-1000);
}

void MySquare::setSvgImage(const QString& str ,QRectF rec) 
{
    MySvgItem  *svg = new MySvgItem(\
            QCoreApplication::applicationDirPath() + "/" + str );
    Q_ASSERT(!svg.isNull());
    svg->setSize(QSize(rec.width(),rec.height()));
    QGraphicsItem  *m_svgItem = svg; 
    m_svgItem->setParentItem(this);
    m_svgItem->setPos(rec.x(),rec.y());
    m_svgItem->setZValue(-1000);
}

void MySquare::setText(const QString& str ,QRectF rec) 
{
    QGraphicsTextItem *text = new QGraphicsTextItem(this);
    //text->setTextInteractionFlags(Qt::TextEditorInteraction);
    text->setHtml(str);
    text->setPos(rec.x(), rec.y());
}

MySquare::~MySquare()
{
    for (int i=0; i< arrows.count(); i++)
    {
        if (arrows.at(i)== NULL){
          delete arrows.at(i);   
        }
    }
}
