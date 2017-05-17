#include "mysquare.h"
#include "mysvgitem.h"
#include<QTranslator>

MySquare::MySquare()
        :QGraphicsItem()
{
    myItemRect = QRectF(0,0,150,70); //default value
    setFlag(ItemIsMovable);
    setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setMyPolygon();//member function
    setFlag(ItemSendsScenePositionChanges, true);
    setAcceptHoverEvents(true);
    posXY = new QString(QString::number(this->x())+", "+
            QString::number(this->y()));
    itemXY = new QGraphicsTextItem(this);
    //itemXY->setPlainText((*posXY));
    //itemXY->setTextInteractionFlags(Qt::TextEditorInteraction);
    itemXY->setZValue(2000);
    //text->setHtml("<heloooooooooo>");
    itemXY->setPos(this->x(), this->y());
    this->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    this->setPos(100,100); 
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
    //update();
    //qDebug() << this->type();
    bool diagonal_flag = false ;
    clickFlag = true;
    //QString *xy = new QString(QString::number(event->pos().x())+", "+
    //        QString::number(event->pos().y()));
    //itemXY->setPlainText((*xy));
    QPointF p = event->pos();
    QRectF r = sceneBoundingRect(); // relative to scene
    QPointF tl = mapFromScene(r.topLeft());
    QPointF br = mapFromScene(r.bottomRight());
    if (p.x() >= br.x()-10 && p.y() >= br.y()-10)
    {
        diagonal_flag = true ;
        //qDebug() << "rd_diagonal" ;
    }
    else { diagonal_flag = false ;}
    if (p.x() <= tl.x()+10 && !diagonal_flag)
    {
        resize_direction_ = rd_left;
        //itemXY->setPlainText("rd_left");
    }
    else if (p.x() >= br.x()-10 && !diagonal_flag)
    {
        resize_direction_ = rd_right;
    }
    else if (p.y() <= tl.y()+10 && !diagonal_flag)
    {
        resize_direction_ = rd_top;
    }
    else if (p.y() >= br.y()-10 && !diagonal_flag)
    {
        resize_direction_ = rd_bottom;
        //qDebug() << "rd_right" ;
    }
    ////// testing diagonal resize /////
    else if (diagonal_flag)
    {
        resize_direction_ = rd_diagonal;
        //qDebug() << "rd_diagonal" ;
    }
    else
    {
        resize_direction_ = rd_none;
    }
    //this->setCursor(Qt::SizeAllCursor);

    QGraphicsItem::mousePressEvent(event);
}

void MySquare::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    clickFlag = false;
    if (isSelected())
    {
        // resize border to mouse position
        QPointF p = event->pos();
        QPointF pp = mapToItem(this, p);
        //QRectF r = rect();
        QRectF r = boundingRect();
        //////// minimum size limit //////
        if (r.width() <= myItemRect.width() && r.width() < 30.0)
        {
            resize_direction_ = rd_none;
            return;
        }
        if (r.height() <= myItemRect.height() && r.height() < 30.0)
        {
            resize_direction_ = rd_none;
            return;
        }
        ///////////// resize item //// 
        switch (resize_direction_)
        {
        case rd_left:
            r.setLeft(pp.x());
            prepareGeometryChange();
            myItemRect = r ;
            break;
        case rd_top:
            r.setTop(pp.y());
            prepareGeometryChange();
            myItemRect = r ;
            break;
        case rd_right:
            r.setRight(pp.x());
            prepareGeometryChange();
            myItemRect = r ;
            break;
        case rd_bottom:
            r.setBottom(pp.y());
            prepareGeometryChange();
            myItemRect = r ;
            break;
        case rd_diagonal:
            r.setBottomRight(pp);
            //qDebug() << " diagonal moving "; 
            prepareGeometryChange();
            myItemRect = r ;
            break;

        default:
            QGraphicsItem::mouseMoveEvent(event);
            //this->setCursor(Qt::ArrowCursor);
            break;
        }
        return; //
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void MySquare::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //Pressed = false;
    QRectF r = sceneBoundingRect(); // relative to scene
    if (r.width() <= myItemRect.width() && r.width() < 30.0)
        myItemRect.setWidth(35);
    if (r.height() <= myItemRect.height() && r.height() < 30.0)
        myItemRect.setHeight(35);
    //update();
    if(clickFlag)
    {
        emit click();
    }
    //QTimer::singleShot(500, this, SIGNAL(click()));
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant MySquare::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange && scene()) {
        foreach (Arrow *arrow, arrows) {
            arrow->updatePosition();
        }
       *posXY = QString::number(this->x())+", "+
                            QString::number(this->y());
        //itemXY->setPlainText((*posXY));

    }
    if (change == QGraphicsItem::ItemOpacityChange ) {
        foreach (Arrow *arrow, arrows) {
            arrow->setOpacity(this->opacity()-0.2);
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
    return this->pos()+p;// changed for test 
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
    prepareGeometryChange();
    myItemRect.setWidth(width);
    myItemRect.setHeight(height);
}

void MySquare::setSize(QSizeF size)
{
    prepareGeometryChange();
    myItemRect.setWidth(size.width());
    myItemRect.setHeight(size.height());
}

QSizeF MySquare::size()
{
    return QSizeF( myItemRect.width(), myItemRect.height());
}

void MySquare::setImage(const QString& str) 
{
    QImage image(QCoreApplication::applicationDirPath() + "/" + str);

    QImage img = image;
    QGraphicsItem *item = new QGraphicsPixmapItem(\
                    QPixmap::fromImage(img));

    //svg->setMaximumCacheSize(QSize(350,350));
    Q_ASSERT(!item.isNull());
    item->setFlag(QGraphicsItem::ItemIsSelectable,false);
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
    item->setFlag(QGraphicsItem::ItemIsSelectable,false);
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
    item->setFlag(QGraphicsItem::ItemIsSelectable,false);
    //item->setSize(QSize(rec.width(),rec.height()));
    item->setParentItem(this);
    item->setPos(rec.x(),rec.y());
}

void MySquare::setSvgImage(const QString& str) 
{
    QGraphicsItem  *m_svgItem = new QGraphicsSvgItem(\
            QCoreApplication::applicationDirPath() + "/" + str);
    Q_ASSERT(!m_svgItem.isNull());
    m_svgItem->setFlag(QGraphicsItem::ItemIsSelectable,false);
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
    m_svgItem->setFlag(QGraphicsItem::ItemIsSelectable,false);
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
    m_svgItem->setFlag(QGraphicsItem::ItemIsSelectable,false);
    m_svgItem->setParentItem(this);
    m_svgItem->setPos(rec.x(),rec.y());
    m_svgItem->setZValue(-1000);
}

void MySquare::setText(const QString& str ,QRectF rec) 
{
    QGraphicsTextItem *text = new QGraphicsTextItem(this);
    //text->setTextInteractionFlags(Qt::TextEditorInteraction);
    text->setFlag(QGraphicsItem::ItemIsSelectable,false);
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
