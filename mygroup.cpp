#include "mygroup.h"
#include "mysquare.h"

MyGroup::MyGroup()

{
    Pressed = false;
    //MySquare square = new MySquare();
    //setFlag(ItemIsMovable);
    //setFlags(ItemIsSelectable | ItemIsMovable);
    //QGraphicsTextItem *text = new QGraphicsTextItem("hello \n world",this);
    //text->setTextInteractionFlags(Qt::TextEditorInteraction);
    //this->addToGroup(text);
}

QRectF MyGroup::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void MyGroup::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

{
    QRectF rec = boundingRect();
    QBrush brush(Qt::green);

    if (Pressed)
    {
        brush.setColor(Qt::red);
    }

    //painter->fillRect(rec,brush);
    //painter->drawRect(rec);
}

void MyGroup::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void MyGroup::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
