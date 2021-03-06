#include<QHBoxLayout>
#include<QGraphicsView>
#include "dialog.h"
#include"arrow.h"
//#include "mygroup.h"
//#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    //ui->setupUi(this);
    //this->setGeometry(0,0,400,400);
    QHBoxLayout *hb = new QHBoxLayout();
    QGraphicsView *gview = new QGraphicsView();
    hb->addWidget(gview);
    this->setLayout(hb);

    scene = new QGraphicsScene(this);

    scene->setSceneRect(10,10,300,300);
    gview->setScene(scene);
    gview->setGeometry(0,0,350,350);

    QList<MySquare * > items;
    for (int i=0 ;i<9 ;++i)
    {
        items.append(new MySquare);
    }
    square = new MySquare();
    items.at(0)->setItemSize(0,0,200,200);
	square2 = new MySquare();
    square2->setPos(130,130);
    //square->setPos(100,200);
    MyGroup *group = new MyGroup();
    //group2 = new MyGroup();
    //group->addToGroup(square);
 
    //group2->addToGroup(square5);// changed

    //scene->addItem(square);
    //scene->addItem(square2);
    //scene->
    //QGraphicsTextItem *text = new QGraphicsTextItem("hello \n world",group);
    //text->setTextInteractionFlags(Qt::TextEditorInteraction);

    //text->setPos(160,160);
    //group->addToGroup(square2);
    //group->addToGroup(text);
    scene->addRect(0,0,400,400);
    //square2->setPos(0,0);
    //scene->addItem(group);
    QLineF line ;
    line.setP1(QPointF(80,80));
    line.setAngle(0);
    line.setLength(500);
    QGraphicsLineItem *myline = new QGraphicsLineItem();
    group->addToGroup(myline);
    myline->setLine(line);
    //scene->addItem(myline);
    scene->addItem(group);

	//Arrow *ar = new Arrow(0,0,100,200);
    //group->addToGroup(ar);

    //scene->addItem(square);
    scene->addItem(items.at(0));
	scene->addItem(square2);
	//Arrow *ar = new Arrow(square,square2);
	Arrow *ar = new Arrow(items.at(0),square2);
    square->addArrow(ar);
    square2->addArrow(ar);
    scene->addItem(ar);
    ar->updatePosition();
    //qDebug() << (scene->items())  << " Items";
    //QGraphicsItem  *m_svgItem = new QGraphicsSvgItem(QCoreApplication::applicationDirPath() + "/image.svg");
    //qDebug() << "App path : " << QCoreApplication::applicationDirPath();
    Q_ASSERT(!img.isNull());
    //painter->drawImage(QRect(55, 55, 35, 35), img);
;
    //m_svgItem->setPos(100,100);
    //scene->addItem(m_svgItem);



}

Dialog::~Dialog()
{
    //delete ui;
}
