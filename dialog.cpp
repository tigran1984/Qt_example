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


    square = new MySquare();
	square2 = new MySquare();
    //QGraphicsEllipseItem square5 = new QGraphicsEllipseItem(0,0,30,30);
    //square->setPos(10,10);
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
    QGraphicsLineItem *line = new QGraphicsLineItem(0,0,100,100);
	Arrow *ar = new Arrow(square,square2);
    //group->addToGroup(ar);
    scene->addItem(square);
	scene->addItem(square2);
    scene->addItem(line);
    //qDebug() << (scene->items())  << " Items";



}

Dialog::~Dialog()
{
    //delete ui;
}
