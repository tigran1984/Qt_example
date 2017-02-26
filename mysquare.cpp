#include "mysquare.h"
#include<QTranslator>

MySquare::MySquare()
        :QGraphicsItem()
{
    Pressed = false;
    setFlag(ItemIsMovable);
    QGraphicsTextItem *text = new QGraphicsTextItem("description",this);
    text->setTextInteractionFlags(Qt::TextEditorInteraction);
    text->setPos(105, 75);
}

QRectF MySquare::boundingRect() const
{
    return QRectF(50,50,150,70);
}

void MySquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

{
    //QRectF rect = boundingRect();
    QRectF rect(50,50,150 ,70);
    QBrush brush(Qt::green);

    if (Pressed)
    {
        brush.setColor(Qt::red);
    }

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
    painter->drawText(QRect(105, 55, 115, 35), Qt::AlignLeft, mystr );
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    //painter->setBrush(brush);

    painter->setRenderHint(QPainter::Antialiasing); // this for rectangel alignment
    //painter->drawRoundedRect( rect.translated(0.5,0.5), 5.0, 5.0 ) ;
    //painter->setRenderHint(painter->HighQualityAntialiasing );
    painter->drawPath(path);
    QImage img("/home/tiko/workspace/Qt_proj/view2/image.svg");
    //QImage img(QCoreApplication::applicationDirPath() + "/image.png");
    //qDebug() << "App path : " << QCoreApplication::applicationDirPath();
    Q_ASSERT(!img.isNull());
    painter->drawImage(QRect(55, 55, 35, 35), img);


    //painter->drawRect(rec);
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
    if (change == QGraphicsItem::ItemPositionChange || scene()) {
        foreach (Arrow *arrow, arrows) {
            arrow->updatePosition();
        }
        // value is the new position.
        //QPointF newPos = value.toPointF();
        //QRectF rect = scene()->sceneRect();
        //if (!rect.contains(newPos)) {
            // Keep the item inside the scene rect.
        //    newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
        //    newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
        //    return newPos;
        //}
    qDebug() << "helooooooo" ;
    }
    return QGraphicsItem::itemChange(change, value);
}








void MySquare::addArrow(Arrow *arrow)
{
    arrows.append(arrow);
}
