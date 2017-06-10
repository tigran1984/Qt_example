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
        set_my_polygon();//member function
        setFlag(ItemSendsScenePositionChanges, true);
        //setFlag(QGraphicsItem::ItemStacksBehindParent);
        setAcceptHoverEvents(true);
        posXY = new QString(QString::number(this->x())+", "+
                        QString::number(this->y()));
        itemXY = new QGraphicsTextItem(this);
        //itemXY->setPlainText((*posXY));
        //itemXY->eetTextInteractionFlags(Qt::TextEditorInteraction);      
        //itemXY->setZValue(2000);
        //text->setHtml("<heloooooooooo>");
        itemXY->setPos(this->x(), this->y());
        this->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
        this->setPos(100,100); 
        connect(this, SIGNAL(changeCursor()),this, SLOT(show_cursor_as()));
}

void MySquare::initMySquare( MySquareStruct &st)
{
        if(!(st.itemPos.isNull())){
                QPointF point = st.itemPos.toPointF();
                this->setPos(point);
                qDebug() << "Position changed successfully";
        }
        if(!(st.itemSize.isNull())){
                QSizeF size = st.itemSize.toSizeF();
                this->set_item_size(size.width(),size.height());
                qDebug() << "Size changed successfully";
        }
        qDebug() << "null value "  << st.image.isNull();
        if(!(st.image.isNull())){
                const QString image = st.image.toString();
                if(!(st.imgSize.isNull())){
                        this->set_image(image,st.imgSize.toSize());
                        qDebug() << "imgSize added successfully";
                }  else { 
                        this->set_image(image,st.imgRect.toRectF());
                        qDebug() << "imgRect added successfully";
                }
        }
        if(!(st.svgImage.isNull())){
                const QString svgImage = st.svgImage.toString();
                if(!(st.svgImgSize.isNull())){
                        this->set_svg_image(svgImage,st.svgImgSize.toSizeF());
                        qDebug() << "svgSize added successfully";
                }  else {
                        this->set_svg_image(svgImage,st.svgImgRect.toRectF());
                        qDebug() << "svgRect added successfully";
                }
        }
        if(!(st.text.isNull())){
                const QString text = st.text.toString();
                this->set_text(text,st.txtRect.toRectF());
                qDebug() << "text added successfully";
        }
        if(!(st.description.isNull())){
                const QString desc = st.description.toString();
                this->set_text(desc, st.descRect.toRectF());
                qDebug() << "description added successfully";
        }
}

QRectF MySquare::boundingRect() const
{
        return myItemRect;
}

void MySquare::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
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
        painter->setRenderHint(QPainter::Antialiasing); 
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
        if (p.x() >= br.x()-10 && p.y() >= br.y()-10) {
                diagonal_flag = true ;
                //qDebug() << "rd_diagonal" ;
        } else { 
                diagonal_flag = false ;
        }
        if (p.x() <= tl.x()+10 && !diagonal_flag) {
                resize_direction_ = rd_left;
                //itemXY->setPlainText("rd_left");
        } else if (p.x() >= br.x()-10 && !diagonal_flag) {
                resize_direction_ = rd_right;
        }
        else if (p.y() <= tl.y()+10 && !diagonal_flag) {
                resize_direction_ = rd_top;
        }
        else if (p.y() >= br.y()-10 && !diagonal_flag) {
                resize_direction_ = rd_bottom;
                //qDebug() << "rd_right" ;
        }
        ////// testing diagonal resize /////
        else if (diagonal_flag) {
                resize_direction_ = rd_diagonal;
                //qDebug() << "rd_diagonal" ;
        } else {
                resize_direction_ = rd_none;
        }
        //this->setCursor(Qt::SizeAllCursor);
        QGraphicsItem::mousePressEvent(event);
}

void MySquare::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
        clickFlag = false;
        if (isSelected()) {
                //emit changeCursor();
                //qDebug() << " cursor_shape_ == " << cursor_shape_; 
                // resize border to mouse position
                QPointF p = event->pos();
                QPointF pp = mapToItem(this, p);
                //QRectF r = rect();
                QRectF r = boundingRect();
                //////// minimum size limit //////
                if (r.width() <= myItemRect.width() && r.width() < 30.0) {
                        resize_direction_ = rd_none;
                        return;
                }
                if (r.height() <= myItemRect.height() && r.height() < 30.0) {
                        resize_direction_ = rd_none;
                        return;
                }
                ///////////// resize item //// 
                switch (resize_direction_) {
                        case rd_left:
                                r.setLeft(pp.x());
                                prepareGeometryChange();
                                myItemRect = r ;
                                cursor_shape_ = cs_horizotal;
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
                                cursor_shape_ = cs_horizotal;
                                break;
                        case rd_bottom:
                                r.setBottom(pp.y());
                                prepareGeometryChange();
                                myItemRect = r ;
                                break;
                        case rd_diagonal:
                                r.setBottomRight(pp);
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
        if(clickFlag) {
                emit click();
        }
        //QTimer::singleShot(500, this, SIGNAL(click()));
        QGraphicsItem::mouseReleaseEvent(event);
}

void MySquare::hoverMoveEvent(QGraphicsSceneHoverEvent * event)
{
        //qDebug() <<  "ItemType ========" << this->type();
        //qDebug() <<  "mouseTracking ========" << hasMouseTracking();
        //emit this->changeCursor();
        bool diagl_flag = false ;
        QPointF mp = event->pos();
        QRectF mr =sceneBoundingRect(); // relative to scene
        QPointF tl = mapFromScene(mr.topLeft());
        QPointF br = mapFromScene(mr.bottomRight());
        if (mp.x() >= br.x()-10 && mp.y() >= br.y()-10) {
                diagl_flag = true ;
                //qDebug() << "rd_diagonal" ;
        } else {
                diagl_flag = false ;
        }
        if (((mp.x() <= tl.x()+10) ||( mp.x() >= br.x()-10)) && \
            !diagl_flag) {
                this->setCursor(Qt::SizeHorCursor);
                //viewport()->setCursor(Qt::SizeHorCursor);
                //qDebug() << "cs_horizotal" ;
                //itemXY->setPlainText("rd_left");
        }
        else if (((mp.y() <= tl.y()+10) ||(mp.y() >= br.y()-10)) && \
                 !diagl_flag) {
                this->setCursor(Qt::SizeVerCursor);
                //viewport()->setCursor(Qt::SizeVerCursor);
                //qDebug() << "cs_vertical" ;
        }
        ////// testing diagonal resize /////
        else if (diagl_flag) {
                this->setCursor(Qt::SizeFDiagCursor);
                //viewport()->setCursor(Qt::SizeFDiagCursor);
                //qDebug() << "cs_diagonal" ;
        } else {
                this->setCursor(Qt::ArrowCursor);
        }
        QGraphicsItem::hoverMoveEvent(event);
}

QVariant MySquare::itemChange(GraphicsItemChange change, const QVariant &value)
{
        if (change == QGraphicsItem::ItemPositionChange && scene()) {
                foreach (Arrow *arrow, arrows) {
                        arrow->update_position();
                }
                *posXY = QString::number(this->x())+", "+
                        QString::number(this->y());
                //itemXY->setPlainText((*posXY));
        }
        //if (change == QGraphicsItem::ItemOpacityChange ) {
        //        int n = 3;
        //       foreach (Arrow *arrow, arrows) {
        //                if(0.4 >= this->opacity()){
        //                        n = 1;
        //                }  
        //                if(0.6 <= this->opacity()){
        //                        n = 2;
        //                }
        //                switch (n)
        //                {
        //                        case 1:
        //                                arrow->setOpacity(0);
        //                                break;
        //                        case 2:
        //                                arrow->setOpacity(1.0);
        //                                break;
        //                        default:
        //                                arrow->setOpacity(this->opacity());
        //                                break;
        //                }
        //        }
        //}
        return QGraphicsItem::itemChange(change, value);
}

void MySquare::add_arrow(Arrow *arrow)
{
        arrows.append(arrow);
}

QPointF MySquare::return_center()
{
        QRectF rect = boundingRect();
        qreal width = rect.width();
        qreal height = rect.height();
        QPointF p = QPointF(width/2 + rect.x(), rect.y() + height/2 );
        //return p;// changet for test 
        return this->pos()+p;// changed for test 
}

void MySquare::set_my_polygon()
{
        QRectF rec = boundingRect();
        QPolygonF poly ;
        //QPointF p = rec.topLeft();
        poly << rec.topLeft() + this->pos()\
             << rec.topRight() + this->pos()\
             << rec.bottomRight()  + this->pos()\
             << rec.bottomLeft() + this->pos()\
             << rec.topLeft() + this->pos();
        myPolygon =  poly;
}


void MySquare::set_item_size(qreal width,qreal height)
{
        prepareGeometryChange();
        myItemRect.setWidth(width);
        myItemRect.setHeight(height);
}

void MySquare::set_size(QSizeF size)
{
        prepareGeometryChange();
        myItemRect.setWidth(size.width());
        myItemRect.setHeight(size.height());
}

QSizeF MySquare::size()
{
        return QSizeF( myItemRect.width(), myItemRect.height());
}

void MySquare::set_image(const QString& str) 
{
        QImage image(QCoreApplication::applicationDirPath() + "/" + str);
        QImage img = image;
        QGraphicsItem *item = new QGraphicsPixmapItem(\
                        QPixmap::fromImage(img));
        //svg->setMaximumCacheSize(QSize(350,350));
        Q_ASSERT(!item.isNull());
        item->setFlag(QGraphicsItem::ItemIsSelectable,false);
        item->setParentItem(this);
        item->setAcceptHoverEvents(false);
}

void MySquare::set_image(const QString& str, const QSize size) 
{
        QImage image(QCoreApplication::applicationDirPath() + "/" + str);
        QImage img = image.scaled(size);
        /*QGraphicsPixmapItem* item = new QGraphicsPixmapItem(\
          QPixmap::fromImage(image));*/
        QGraphicsItem *item = new QGraphicsPixmapItem(\
                        QPixmap::fromImage(img));
        //item->set_size(size);
        //svg->setMaximumCacheSize(QSize(350,350));
        Q_ASSERT(!item.isNull());
        item->setFlag(QGraphicsItem::ItemIsSelectable,false);
        item->setPos(21,11);
        item->setParentItem(this);
        item->setAcceptHoverEvents(false);
}

void MySquare::set_image(const QString& str ,QRectF rec) 
{
        QImage image(QCoreApplication::applicationDirPath() + "/" + str);
        QImage img = image.scaled(QSize(rec.width(),rec.height()));
        /*QGraphicsPixmapItem* item = new QGraphicsPixmapItem(\
          QPixmap::fromImage(image));*/
        QGraphicsItem *item = new QGraphicsPixmapItem(\
                        QPixmap::fromImage(img));
        Q_ASSERT(!item.isNull());
        item->setFlag(QGraphicsItem::ItemIsSelectable,false);
        //item->set_size(QSize(rec.width(),rec.height()));
        item->setParentItem(this);
        item->setPos(rec.x(),rec.y());
        item->setAcceptHoverEvents(false);
}

void MySquare::set_svg_image(const QString& str) 
{
        QGraphicsItem  *m_svgItem = new QGraphicsSvgItem(\
                        QCoreApplication::applicationDirPath() + "/" + str);
        Q_ASSERT(!m_svgItem.isNull());
        m_svgItem->setFlag(QGraphicsItem::ItemIsSelectable,false);
        m_svgItem->setPos(5,5);
        m_svgItem->setParentItem(this);
        m_svgItem->setAcceptHoverEvents(false);
}

void MySquare::set_svg_image(const QString& str ,QSizeF size) 
{
        /*QGraphicsSvgItem  *svg = new QGraphicsSvgItem(\
          QCoreApplication::applicationDirPath() + "/" + str);*/
        MySvgItem  *svg = new MySvgItem(\
                        QCoreApplication::applicationDirPath() + "/" + str );
        svg->set_size(size);
        //svg->setMaximumCacheSize(QSize(350,350));
        Q_ASSERT(!svg.isNull());
        QGraphicsItem  *m_svgItem = svg; 
        //m_svgItem->setPos(5,5);
        m_svgItem->setFlag(QGraphicsItem::ItemIsSelectable,false);
        m_svgItem->setParentItem(this);
        //m_svgItem->setZValue(this->zValue);
        m_svgItem->setAcceptHoverEvents(false);
}

void MySquare::set_svg_image(const QString& str ,QRectF rec) 
{
        MySvgItem  *svg = new MySvgItem(\
                        QCoreApplication::applicationDirPath() + "/" + str );
        Q_ASSERT(!svg.isNull());
        svg->set_size(QSize(rec.width(),rec.height()));
        QGraphicsItem  *m_svgItem = svg; 
        m_svgItem->setFlag(QGraphicsItem::ItemIsSelectable,false);
        m_svgItem->setParentItem(this);
        m_svgItem->setPos(rec.x(),rec.y());
        //m_svgItem->setZValue(-1000);
        m_svgItem->setAcceptHoverEvents(false);
}

void MySquare::set_text(const QString& str ,QRectF rec) 
{
        QGraphicsTextItem *text = new QGraphicsTextItem(this);
        //text->eetTextInteractionFlags(Qt::TextEditorInteraction);
        text->setFlag(QGraphicsItem::ItemIsSelectable,false);
        text->setHtml(str);
        text->setPos(rec.x(), rec.y());
        text->setAcceptHoverEvents(false);
}

void MySquare::print_struct(const MySquareStruct &st) 
{
        qDebug() <<  "  itemPos ;   "   << st.itemPos ;
        qDebug() <<  "  itemSize ;  "   << st.itemSize ;
        qDebug() <<  "  image ;     "   << st.image ;
        qDebug() <<  "  imgSize ;   "   << st.imgSize ;
        qDebug() <<  "  imgRect;    "   << st.imgRect;
        qDebug() <<  "  svgImage ;  "   << st.svgImage ;
        qDebug() <<  "  svgImage;   "   << st.svgImage;
        qDebug() <<  "  svgImgRect; "   << st.svgImgRect;
        qDebug() <<  "  text ;      "   << st.text ;
        qDebug() <<  "  txtRect ;   "   << st.txtRect ;
        qDebug() <<  "  description "   << st.description ;
        qDebug() <<  "  descRect ;  "   << st.descRect ;
}

void MySquare::show_cursor_as() 
{
        //qDebug( << "changeCursor signal is emmited "; 
        //switch (cursor_shape_)
        //{
        //case cs_vertical:
        //    this->setCursor(Qt::SizeVerCursor);
        //    break;
        //case cs_horizotal:
        //    this->setCursor(Qt::SizeHorCursor);
        //    break;
        //case cs_diagonal:
        //    this->setCursor(Qt::SizeFDiagCursor);
        //    break;
        //default:
        //    this->setCursor(Qt::ArrowCursor);
        //    break;
        //}
}

MySquare::~MySquare()
{
        for (int i=0; i< arrows.count(); i++) {
                if (arrows.at(i)== NULL){
                        delete arrows.at(i);   
                }
        }
}
