#include<iostream>
#include<QHBoxLayout>
#include<QGraphicsView>
#include "dialog.h"
#include"arrow.h"
#include<QPushButton>
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

    QPushButton * btn = new QPushButton();
    btn->setGeometry(0,0,100,50);
    btn->setParent(this);
    btn->setText("Clear Page");
    btn->show();
    //connect(btn, &QPushButton::clicked, scene, &QGraphicsScene::clear);
    connect(btn, &QPushButton::clicked, this, &Dialog::nextPage);

    //create MySquare item pointers
    QList<MySquare * > items;
    for (int i=0 ;i<9 ;++i)
    {
        items.append(new MySquare);
    }
    items.at(0)->setItemSize(314,220);
    items.at(1)->setItemSize(305,171);
    items.at(2)->setItemSize(250,155);
    items.at(3)->setItemSize(409,209);
    items.at(4)->setItemSize(169,70);
    items.at(5)->setItemSize(169,70);
    items.at(6)->setItemSize(169,70);
    items.at(7)->setItemSize(169,70);
    items.at(8)->setItemSize(169,70);

    items.at(0)->setPos(291,168);
    items.at(1)->setPos(106,423);
    items.at(2)->setPos(647,203);
    items.at(3)->setPos(489,414);
    items.at(4)->setPos(475,57);
    items.at(5)->setPos(259,57);
    items.at(6)->setPos(41,232);
    items.at(7)->setPos(42,328);
    items.at(8)->setPos(42,139);

    items.at(0)->setSvgImage("instigate_design3.svg",QSizeF(286,203));
    items.at(1)->setSvgImage("barcode8.svg",QRectF(5,5,60,60));
    items.at(2)->setSvgImage("tools.svg",QRectF(16,15,32,35));
    items.at(3)->setSvgImage("settings21.svg",QRectF(17,17,44,47));
    items.at(4)->setSvgImage("newspaper11.svg",QRectF(15,16,36,39));
    items.at(5)->setSvgImage("address14.svg",QRectF(11,12,37,44));
    items.at(6)->setSvgImage("workers.svg",QRectF(12,15,38,46));
    items.at(7)->setSvgImage("businessman175.svg",QRectF(9,13,39,40));
    items.at(8)->setSvgImage("image.svg",QRectF(14,16,35,37));


    QString str1 = "<div  style='color:blue'><h3>IP\
          offerings</h3></div>";
    QString str2 = "<div  style='color:blue'>\
            <h3>Design Services</h3></div>";
    QString str3 = "<div  style='color:blue'><h3>\
          Specialization</h3></div>";
    QString str4 = "<div  style='color:blue'><h3>\
            News</h3></div>";
    QString str5 = "<div  style='color:blue'><h3>\
     Contacts</h3></div>";
    QString str6 = "<div  style='color:blue'><h3>\
        Team</h3></div>";
    QString str7 = "<div  style='color:blue'><h3>\
     Career</h3></div>";
    QString str8 = "<div  style='color:blue'><h3>\
     Partners and <br>Customers</h3></div>";

    QString str3_ = "<ul><li>Electronic Design Automation,\
            CAD</li><li>Embedded Systems, OS/FW</li><li>\
            Close-to-HW programming, DSP</li><li>HW modeling\
            and prototyping</li><li>FPGA design, RTL design,\
            &nbsp;</li><li>Coarse Grain Reconfigurable Computing\
                </li><li>Massive-parallel computing, HPC</li></ul>";
    QString str2_ = "<ul><li>System Development</li><li>\
        System Verification</li><li>System Validation</li></ul>";
    QString str1_ = "<ul><li>CAD Application Framework</li><li>\
                     SW and HW IDE Framework</li><li>\
                     IP-XACT Front-End</li></ul>"; 
    items.at(1)->setText(str1,QRectF(64,22,286,203));
    items.at(2)->setText(str2,QRectF(63,20,286,203));
    items.at(3)->setText(str3,QRectF(71,23,286,203));
    items.at(4)->setText(str4,QRectF(73,21,286,203));
    items.at(5)->setText(str5,QRectF(64,21,286,203));
    items.at(6)->setText(str6,QRectF(66,22,286,203));
    items.at(7)->setText(str7,QRectF(63,22,286,203));
    items.at(8)->setText(str8,QRectF(61,0,286,203));
    

    items.at(1)->setText(str1_,QRectF(4,48,286,203));
    items.at(2)->setText(str2_,QRectF(10,50,286,203));
    items.at(3)->setText(str3_,QRectF(16,50,286,203));

             

    // create arrows
	Arrow *ar0 = new Arrow(items.at(0),items.at(1));
    items.at(0)->addArrow(ar0);
    items.at(1)->addArrow(ar0);

	Arrow *ar1 = new Arrow(items.at(0),items.at(2));
    items.at(0)->addArrow(ar1);
    items.at(2)->addArrow(ar1);

	Arrow *ar2 = new Arrow(items.at(0),items.at(3));
    items.at(0)->addArrow(ar2);
    items.at(3)->addArrow(ar2);

	Arrow *ar3 = new Arrow(items.at(0),items.at(4));
    items.at(0)->addArrow(ar3);
    items.at(4)->addArrow(ar3);
    
	Arrow *ar4 = new Arrow(items.at(0),items.at(5));
    items.at(0)->addArrow(ar4);
    items.at(5)->addArrow(ar4);
    
	Arrow *ar5 = new Arrow(items.at(0),items.at(6));
    items.at(0)->addArrow(ar5);
    items.at(6)->addArrow(ar5);
    
	Arrow *ar6 = new Arrow(items.at(0),items.at(7));
    items.at(0)->addArrow(ar6);
    items.at(7)->addArrow(ar6);
    
	Arrow *ar7 = new Arrow(items.at(0),items.at(8));
    items.at(0)->addArrow(ar7);
    items.at(8)->addArrow(ar7);
    
	Arrow *ar8 = new Arrow(items.at(2),items.at(3));
    items.at(2)->addArrow(ar8);
    items.at(3)->addArrow(ar8);
    
	Arrow *ar9 = new Arrow(items.at(1),items.at(3));
    items.at(1)->addArrow(ar8);
    items.at(3)->addArrow(ar8);
    


    for (int i=0 ;i<9 ;++i)
    {
        scene->addItem(items.at(i));
    }

    scene->addItem(ar0);
    scene->addItem(ar1);
    scene->addItem(ar2);
    scene->addItem(ar3);
    scene->addItem(ar4);
    scene->addItem(ar5);
    scene->addItem(ar6);
    scene->addItem(ar7);
    scene->addItem(ar8);
    scene->addItem(ar9);

    ar0->updatePosition();
    ar1->updatePosition();
    ar2->updatePosition();
    ar3->updatePosition();
    ar4->updatePosition();
    ar5->updatePosition();
    ar6->updatePosition();
    ar7->updatePosition();
    ar8->updatePosition();
    ar9->updatePosition();
    //setPartnersPage();
    //qDebug() << (scene->items())  << " Items";

    //QPushButton * btn2 = new QPushButton();
    //btn2->setGeometry(0,0,50,100);
    //btn2->setParent(this);
    //btn2->setText("Clear Page");
    //btn2->show();
    connect(items.at(8), &MySquare::click, this, &Dialog::nextPage);


}

void Dialog::nextPage()
{
    //std::cout << scene->
    scene->clear();
    setPartnersPage();
}

void Dialog::setPartnersPage()
{
    //create MySquare item pointers
    QList<MySquare * > items2;
    for (int i=0 ;i<8 ;++i)
    {
        items2.append(new MySquare);
    }
    items2.at(0)->setItemSize(248,79);
    items2.at(1)->setItemSize(248,79);
    items2.at(2)->setItemSize(248,81);
    items2.at(3)->setItemSize(196,94);
    items2.at(4)->setItemSize(198,84);
    items2.at(5)->setItemSize(198,84);
    items2.at(6)->setItemSize(148,89);
    items2.at(7)->setItemSize(211,281);

    items2.at(0)->setImage("atmel.jpg",QRectF(12,15,226,41));
    items2.at(1)->setImage("xilinx.jpg",QRectF(34,6,186,63));
    items2.at(2)->setImage("exar.png",QRectF(18,2,212,77));
    items2.at(3)->setImage("uite.jpg",QRectF(21,11,151,66));
    items2.at(4)->setImage("logo_laflin.gif",QRectF(10,10,165,62));
    items2.at(5)->setImage("logo_conintec.jpg",QRectF(10,10,165,70));
    items2.at(6)->setSvgImage("instigate_design3.svg",QRectF(4,5,132,79));
    items2.at(7)->setSvgImage("image.svg",QRectF(19,23,63,57));
    //items.at(6)->setImage("workers.svg",QRectF(12,15,38,46));
    //items.at(7)->setImage("businessman175.svg",QRectF(9,13,39,40));


    /* //QString str1 = "<div  style='color:blue'><h3>IP\
    //      offerings</h3></div>";
    //QString str2 = "<div  style='color:blue'>\
    //        <h3>Design Services</h3></div>";
    //QString str3 = "<div  style='color:blue'><h3>\
    //      Specialization</h3></div>";
    //QString str4 = "<div  style='color:blue'><h3>\
    //        News</h3></div>";
    //QString str5 = "<div  style='color:blue'><h3>\
    // Contacts</h3></div>";
    //QString str6 = "<div  style='color:blue'><h3>\
    //    Team</h3></div>";
    //QString str7 = "<div  style='color:blue'><h3>\
    // Career</h3></div>";*/
    QString str8 = "<div  style='color:blue'><h3>\
     Partners and <br>Customers</h3></div>";
    QString str8_ = "<p>Many of the partners and<br> customers\
                     cannot be listed<br> due to NDA. It is possible\
                     to<br> obtain more information via<br> special request,\
                     under<br> condition that the partner<br> approves it.\
                     <br></p>";

    /* //QString str3_ = "<ul><li>Electronic Design Automation,\
    //        CAD</li><li>Embedded Systems, OS/FW</li><li>\
    //        Close-to-HW programming, DSP</li><li>HW modeling\
    //        and prototyping</li><li>FPGA design, RTL design,\
    //        &nbsp;</li><li>Coarse Grain Reconfigurable Computing\
    //            </li><li>Massive-parallel computing, HPC</li></ul>";
    //QString str2_ = "<ul><li>System Development</li><li>\
    //    System Verification</li><li>System Validation</li></ul>";
    //QString str1_ = "<ul><li>CAD Application Framework</li><li>\
    //                 SW and HW IDE Framework</li><li>\
    //                 IP-XACT Front-End</li></ul>"; 
    //items.at(1)->setText(str1,QRectF(64,22,286,203));
    //items.at(2)->setText(str2,QRectF(63,20,286,203));
    //items.at(3)->setText(str3,QRectF(71,23,286,203));
    //items.at(4)->setText(str4,QRectF(73,21,286,203));
    //items.at(5)->setText(str5,QRectF(64,21,286,203));
    //items.at(6)->setText(str6,QRectF(66,22,286,203));*/
    items2.at(7)->setText(str8,QRectF(105,31,99,46));
    items2.at(7)->setText(str8_,QRectF(21,97,176,170));
    //items.at(8)->setText(str8,QRectF(61,0,286,203));
    //

    //items.at(1)->setText(str1_,QRectF(4,48,286,203));
    //items.at(2)->setText(str2_,QRectF(10,50,286,203));
    //items.at(3)->setText(str3_,QRectF(16,50,286,203));

    //         
    items2.at(0)->setPos(557,56);
    items2.at(1)->setPos(558,165);
    items2.at(2)->setPos(559,284);
    items2.at(3)->setPos(391,417);
    items2.at(4)->setPos(134,381);
    items2.at(5)->setPos(39,209);
    items2.at(6)->setPos(30,21);
    items2.at(7)->setPos(280,47);
    //items.at(8)->setPos(42,139);

    // create arrows
	Arrow *ar0 = new Arrow(items2.at(6),items2.at(7));
    items2.at(7)->addArrow(ar0);
    items2.at(6)->addArrow(ar0);

	Arrow *ar1 = new Arrow(items2.at(7),items2.at(5));
    items2.at(7)->addArrow(ar1);
    items2.at(5)->addArrow(ar1);

	Arrow *ar2 = new Arrow(items2.at(7),items2.at(4));
    items2.at(7)->addArrow(ar2);
    items2.at(4)->addArrow(ar2);

	Arrow *ar3 = new Arrow(items2.at(7),items2.at(3));
    items2.at(7)->addArrow(ar3);
    items2.at(3)->addArrow(ar3);
    
	Arrow *ar4 = new Arrow(items2.at(7),items2.at(2));
    items2.at(7)->addArrow(ar4);
    items2.at(2)->addArrow(ar4);
    
	Arrow *ar5 = new Arrow(items2.at(7),items2.at(1));
    items2.at(7)->addArrow(ar5);
    items2.at(1)->addArrow(ar5);
    
	Arrow *ar6 = new Arrow(items2.at(7),items2.at(0));
    items2.at(0)->addArrow(ar6);
    items2.at(7)->addArrow(ar6);
    
	//Arrow *ar7 = new Arrow(items.at(0),items.at(8));
    //items.at(0)->addArrow(ar7);
    //items.at(8)->addArrow(ar7);
    //
	//Arrow *ar8 = new Arrow(items.at(2),items.at(3));
    //items.at(2)->addArrow(ar8);
    //items.at(3)->addArrow(ar8);
    //
	//Arrow *ar9 = new Arrow(items.at(1),items.at(3));
    //items.at(1)->addArrow(ar8);
    //items.at(3)->addArrow(ar8);
    //


    for (int i=0 ;i<8 ;++i)
    {
        scene->addItem(items2.at(i));
    }

    
    scene->addItem(ar0);
    scene->addItem(ar1);
    scene->addItem(ar2);
    scene->addItem(ar3);
    scene->addItem(ar4);
    scene->addItem(ar5);
    scene->addItem(ar6);
    //scene->addItem(ar7);
    //scene->addItem(ar8);
    //scene->addItem(ar9);

    //ar0->updatePosition();
    //ar1->updatePosition();
    //ar2->updatePosition();
    //ar3->updatePosition();
    //ar4->updatePosition();
    //ar5->updatePosition();
    //ar6->updatePosition();
    //ar7->updatePosition();
    //ar8->updatePosition();
    //ar9->updatePosition();
    //delete ui;
}

Dialog::~Dialog()
{
    //delete ui;
}
