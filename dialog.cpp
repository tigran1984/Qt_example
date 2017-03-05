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

    scene->setSceneRect(10,10,650,650);
    gview->setScene(scene);
    gview->setGeometry(0,0,700,700);
    scene->addRect(10,10,650,650);

    QList<MySquare * > items;
    for (int i=0 ;i<9 ;++i)
    {
        items.append(new MySquare);
    }
    items.at(0)->setItemSize(314,220);
    items.at(1)->setItemSize(305,171);
    items.at(2)->setItemSize(250,155);
    items.at(3)->setItemSize(169,70);
    items.at(4)->setItemSize(169,70);
    items.at(5)->setItemSize(169,70);
    items.at(6)->setItemSize(169,70);
    items.at(7)->setItemSize(169,70);
    items.at(8)->setItemSize(169,70);

    items.at(0)->setImage("instigate_design3.svg");
    items.at(1)->setImage("barcode8.svg");
    items.at(2)->setImage("tools.svg");
    items.at(3)->setImage("settings21.svg",QSizeF(35,35));
    items.at(4)->setImage("newspaper11.svg");
    items.at(5)->setImage("address14.svg");
    items.at(6)->setImage("workers.svg");
    items.at(7)->setImage("businessman175.svg");
    items.at(8)->setImage("image.svg");

    items.at(0)->setPos(291,168);
    items.at(1)->setPos(106,423);
    items.at(2)->setPos(647,203);
    items.at(3)->setPos(489,414);
    items.at(4)->setPos(475,57);
    items.at(5)->setPos(259,57);
    items.at(6)->setPos(41,232);
    items.at(7)->setPos(42,328);
    items.at(8)->setPos(42,139);

    for (int i=0 ;i<9 ;++i)
    {
        scene->addItem(items.at(i));
    }

    square = new MySquare();
	square2 = new MySquare();
	Arrow *ar = new Arrow(items.at(0),items.at(1));
    items.at(0)->addArrow(ar);
    items.at(1)->addArrow(ar);
    scene->addItem(ar);
    ar->updatePosition();
    //qDebug() << (scene->items())  << " Items";



}

Dialog::~Dialog()
{
    //delete ui;
}
