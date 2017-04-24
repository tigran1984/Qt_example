#include "dialog.h"

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
    groupAnim_1 = new QParallelAnimationGroup;
    groupAnim_2 = new QParallelAnimationGroup;
    groupAnim_3 = new QParallelAnimationGroup;
    //QPushButton * btn = new QPushButton();
    //btn->setGeometry(0,0,100,50);
    //btn->setParent(this);
    //btn->setText("Clear Page");
    //btn->show();
    ////connect(btn, &QPushButton::clicked, scene, &QGraphicsScene::clear);
    //connect(btn, &QPushButton::clicked, this, &Dialog::partnersPage);
    setFirstPage();
    //QTimer *timer1 = new QTimer(this);
    //QTimer *timer2 = new QTimer(this);
    //connect(timer1, SIGNAL(timeout()), this, SLOT(setFirstPage()));
    //connect(timer2, SIGNAL(timeout()), this, SLOT(partnersPage()));
    //timer1->start(1000);
    //timer2->start(1500);


}

void Dialog::setFirstPage()
{
    //scene->clear();
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
    ///////////////////
    items.at(0)->setPos(291,168);
    items.at(1)->setPos(106,423);
    items.at(2)->setPos(647,203);
    items.at(3)->setPos(489,414);
    items.at(4)->setPos(475,57);
    items.at(5)->setPos(259,57);
    items.at(6)->setPos(41,232);
    items.at(7)->setPos(42,328);
    items.at(8)->setPos(42,139);
    ///////////////////
    items.at(0)->setSvgImage("instigate_design3.svg",QSizeF(286,203));
    items.at(1)->setSvgImage("barcode8.svg",QRectF(5,5,60,60));
    items.at(2)->setSvgImage("tools.svg",QRectF(16,15,32,35));
    items.at(3)->setSvgImage("settings21.svg",QRectF(17,17,44,47));
    items.at(4)->setSvgImage("newspaper11.svg",QRectF(15,16,36,39));
    items.at(5)->setSvgImage("address14.svg",QRectF(11,12,37,44));
    items.at(6)->setSvgImage("workers.svg",QRectF(12,15,38,46));
    items.at(7)->setSvgImage("businessman175.svg",QRectF(9,13,39,40));
    items.at(8)->setSvgImage("image.svg",QRectF(14,16,35,37));
    ////////////////////
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
    /////////////////////
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
    //////////////////
    items.at(1)->setText(str1_,QRectF(4,48,286,203));
    items.at(2)->setText(str2_,QRectF(10,50,286,203));
    items.at(3)->setText(str3_,QRectF(16,50,286,203));
    // create arrows
	Arrow *ar0 = new Arrow(items.at(0),items.at(1));
    items.at(0)->addArrow(ar0);
    items.at(1)->addArrow(ar0);
    /////////////////
	Arrow *ar1 = new Arrow(items.at(0),items.at(2));
    items.at(0)->addArrow(ar1);
    items.at(2)->addArrow(ar1);
    /////////////////
	Arrow *ar2 = new Arrow(items.at(0),items.at(3));
    items.at(0)->addArrow(ar2);
    items.at(3)->addArrow(ar2);
    /////////////////
	Arrow *ar3 = new Arrow(items.at(0),items.at(4));
    items.at(0)->addArrow(ar3);
    items.at(4)->addArrow(ar3);
    /////////////////
	Arrow *ar4 = new Arrow(items.at(0),items.at(5));
    items.at(0)->addArrow(ar4);
    items.at(5)->addArrow(ar4);
    /////////////////
	Arrow *ar5 = new Arrow(items.at(0),items.at(6));
    items.at(0)->addArrow(ar5);
    items.at(6)->addArrow(ar5);
    /////////////////
	Arrow *ar6 = new Arrow(items.at(0),items.at(7));
    items.at(0)->addArrow(ar6);
    items.at(7)->addArrow(ar6);
    /////////////////
	Arrow *ar7 = new Arrow(items.at(0),items.at(8));
    items.at(0)->addArrow(ar7);
    items.at(8)->addArrow(ar7);
    /////////////////
	Arrow *ar8 = new Arrow(items.at(2),items.at(3));
    items.at(2)->addArrow(ar8);
    items.at(3)->addArrow(ar8);
    /////////////////
	Arrow *ar9 = new Arrow(items.at(1),items.at(3));
    items.at(1)->addArrow(ar9);
    items.at(3)->addArrow(ar9);
    /////// add items in scene //////////
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
    /////////////////
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
    qDebug() << items.at(0)->x()  << " \n";

    ///////////// apearance of first page //////////////
    groupAnim_2->clear();
     for (int i=0 ;i<9 ;++i)
    {
        groupAnim_2->addAnimation(opacityAnimation(
                                items.at(i),3001,0.0,1.0,QEasingCurve::InExpo));   
    }
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            ar0,3001,0.0,1.0,QEasingCurve::InExpo));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            ar1,3001,0.0,1.0,QEasingCurve::InExpo));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            ar2,3001,0.0,1.0,QEasingCurve::InExpo));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            ar3,3001,0.0,1.0,QEasingCurve::InExpo));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            ar4,3001,0.0,1.0,QEasingCurve::InExpo));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            ar5,3001,0.0,1.0,QEasingCurve::InExpo));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            ar6,3001,0.0,1.0,QEasingCurve::InExpo));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            ar7,3001,0.0,1.0,QEasingCurve::InExpo));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            ar8,3001,0.0,1.0,QEasingCurve::InExpo));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            ar9,3001,0.0,1.0,QEasingCurve::InExpo));
   // set Animation when page changed //
    groupAnim_1->addAnimation(posAnimation(
                                items.at(0),3001,items.at(0)->pos(),items.at(0)->pos(),QEasingCurve::InExpo));
    //QPropertyAnimation *anim0 = new QPropertyAnimation(items.at(0),"pos" );
    //anim0->setDuration(3001);
    ////anim0->setStartValue(items.at(0)->pos());
    //anim0->setStartValue(QPoint(42,139));
    //anim0->setEndValue(items.at(0)->pos());
    QPropertyAnimation *anim1 = new QPropertyAnimation(items.at(1),"pos" );
    anim1->setDuration(3001);
    anim1->setEndValue(items.at(0)->pos());
    QPropertyAnimation *anim2 = new QPropertyAnimation(items.at(2),"pos" );
    anim2->setDuration(3001);
    anim2->setEndValue(items.at(0)->pos());
    QPropertyAnimation *anim3 = new QPropertyAnimation(items.at(3),"pos" );
    anim3->setDuration(3001);
    anim3->setEndValue(items.at(0)->pos());
    QPropertyAnimation *anim4 = new QPropertyAnimation(items.at(4),"pos" );
    anim4->setDuration(3001);
    anim4->setEndValue(items.at(0)->pos());
    QPropertyAnimation *anim5 = new QPropertyAnimation(items.at(5),"pos" );
    anim5->setDuration(3001);
    anim5->setEndValue(items.at(0)->pos());
    QPropertyAnimation *anim6 = new QPropertyAnimation(items.at(6),"pos" );
    anim6->setDuration(3001);
    anim6->setEndValue(items.at(0)->pos());
    QPropertyAnimation *anim7 = new QPropertyAnimation(items.at(7),"pos" );
    anim7->setDuration(3001);
    anim7->setEndValue(items.at(0)->pos());
    QPropertyAnimation *anim8 = new QPropertyAnimation(items.at(8),"pos" );
    anim8->setDuration(3001);
    anim8->setStartValue(QPoint(291,168));
    anim8->setEndValue(items.at(0)->pos());
    //////////////////////

    //anim0->setEasingCurve(QEasingCurve::InElastic);
    anim1->setEasingCurve(QEasingCurve::OutExpo);
    anim2->setEasingCurve(QEasingCurve::OutExpo);
    anim3->setEasingCurve(QEasingCurve::OutExpo);
    anim4->setEasingCurve(QEasingCurve::OutExpo);
    anim5->setEasingCurve(QEasingCurve::OutExpo);
    anim6->setEasingCurve(QEasingCurve::OutExpo);
    anim7->setEasingCurve(QEasingCurve::OutExpo);
    anim8->setEasingCurve(QEasingCurve::InExpo);
    //////////////////////
    QPropertyAnimation *anim10 = new QPropertyAnimation(items.at(0),"opacity" );
    anim10->setDuration(3001);
    anim10->setEndValue(0.0);
    QPropertyAnimation *anim11 = new QPropertyAnimation(items.at(1),"opacity" );
    anim11->setDuration(3001);
    anim11->setEndValue(0.0);
    QPropertyAnimation *anim12 = new QPropertyAnimation(items.at(2),"opacity" );
    anim12->setDuration(3001);
    anim12->setEndValue(0.0);
    QPropertyAnimation *anim13 = new QPropertyAnimation(items.at(3),"opacity" );
    anim13->setDuration(3001);
    anim13->setEndValue(0.0);
    QPropertyAnimation *anim14 = new QPropertyAnimation(items.at(4),"opacity" );
    anim14->setDuration(3001);
    anim14->setEndValue(0.0);
    QPropertyAnimation *anim15 = new QPropertyAnimation(items.at(5),"opacity" );
    anim15->setDuration(3001);
    anim15->setEndValue(0.0);
    QPropertyAnimation *anim16 = new QPropertyAnimation(items.at(6),"opacity" );
    anim16->setDuration(3001);
    anim16->setEndValue(0.0);
    QPropertyAnimation *anim17 = new QPropertyAnimation(items.at(7),"opacity" );
    anim17->setDuration(3001);
    anim17->setEndValue(0.0);
    QPropertyAnimation *anim18 = new QPropertyAnimation(items.at(8),"opacity" );
    anim18->setDuration(3001);
    anim18->setEndValue(0.0);
    //////////////////////
    anim10->setEasingCurve(QEasingCurve::OutExpo);
    anim11->setEasingCurve(QEasingCurve::InExpo);
    anim12->setEasingCurve(QEasingCurve::InExpo);
    anim13->setEasingCurve(QEasingCurve::InExpo);
    anim14->setEasingCurve(QEasingCurve::InExpo);
    anim15->setEasingCurve(QEasingCurve::InExpo);
    anim16->setEasingCurve(QEasingCurve::InExpo);
    anim17->setEasingCurve(QEasingCurve::InExpo);
    anim18->setEasingCurve(QEasingCurve::OutExpo);
    //////////////////////
    //groupAnim_1->addAnimation(anim0);
    groupAnim_1->addAnimation(anim1);
    groupAnim_1->addAnimation(anim2);
    groupAnim_1->addAnimation(anim3);
    groupAnim_1->addAnimation(anim4);
    groupAnim_1->addAnimation(anim5);
    groupAnim_1->addAnimation(anim6);
    groupAnim_1->addAnimation(anim7);
    groupAnim_1->addAnimation(anim8);
    //////////////////////
    groupAnim_1->addAnimation(anim10);
    groupAnim_1->addAnimation(anim11);
    groupAnim_1->addAnimation(anim12);
    groupAnim_1->addAnimation(anim13);
    groupAnim_1->addAnimation(anim14);
    groupAnim_1->addAnimation(anim15);
    groupAnim_1->addAnimation(anim16);
    groupAnim_1->addAnimation(anim17);
    groupAnim_1->addAnimation(anim18);
    //groupAnim_1->addAnimation(anim19);
    connect(items.at(8), &MySquare::click, this, &Dialog::partnersPage);
    groupAnim_2->start();
}

void Dialog::firstPage()
{
    groupAnim_3->start();
    setFirstPage();
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
    //////////////////
    items2.at(0)->setImage("atmel.jpg",QRectF(12,15,226,41));
    items2.at(1)->setImage("xilinx.jpg",QRectF(34,6,186,63));
    items2.at(2)->setImage("exar.png",QRectF(18,2,212,77));
    items2.at(3)->setImage("uite.jpg",QRectF(21,11,151,66));
    items2.at(4)->setImage("logo_laflin.gif",QRectF(10,10,165,62));
    items2.at(5)->setImage("logo_conintec.jpg",QRectF(10,10,165,70));
    items2.at(6)->setSvgImage("instigate_design3.svg",QRectF(4,5,132,79));
    items2.at(7)->setSvgImage("image.svg",QRectF(19,23,63,57));
    QString str8 = "<div  style='color:blue'><h3>\
     Partners and <br>Customers</h3></div>";
    QString str8_ = "<p>Many of the partners and<br> customers\
                     cannot be listed<br> due to NDA. It is possible\
                     to<br> obtain more information via<br> special request,\
                     under<br> condition that the partner<br> approves it.\
                     <br></p>";

    items2.at(7)->setText(str8,QRectF(105,31,99,46));
    items2.at(7)->setText(str8_,QRectF(21,97,176,170));
    //  origin position
    //items2.at(0)->setPos(557,56);
    //items2.at(1)->setPos(558,165);
    //items2.at(2)->setPos(559,284);
    //items2.at(3)->setPos(391,417);
    //items2.at(4)->setPos(134,381);
    //items2.at(5)->setPos(39,209);
    //items2.at(6)->setPos(30,21);
    ////items2.at(7)->setPos(280,47);
    //items2.at(7)->setPos(291,168);


    // position testing
    items2.at(0)->setPos(529,72);
    items2.at(1)->setPos(598,216);
    items2.at(2)->setPos(568,343);
    items2.at(3)->setPos(522,479);
    items2.at(4)->setPos(50,466);
    items2.at(5)->setPos(39,264);
    items2.at(6)->setPos(42,139);
    items2.at(7)->setPos(291,168);







    // create arrows
	Arrow *ar0 = new Arrow(items2.at(6),items2.at(7));
    items2.at(7)->addArrow(ar0);
    items2.at(6)->addArrow(ar0);
    ///////////////
	Arrow *ar1 = new Arrow(items2.at(7),items2.at(5));
    items2.at(7)->addArrow(ar1);
    items2.at(5)->addArrow(ar1);
    //////////////
	Arrow *ar2 = new Arrow(items2.at(7),items2.at(4));
    items2.at(7)->addArrow(ar2);
    items2.at(4)->addArrow(ar2);
    /////////////
	Arrow *ar3 = new Arrow(items2.at(7),items2.at(3));
    items2.at(7)->addArrow(ar3);
    items2.at(3)->addArrow(ar3);
    ////////////
	Arrow *ar4 = new Arrow(items2.at(7),items2.at(2));
    items2.at(7)->addArrow(ar4);
    items2.at(2)->addArrow(ar4);
    ////////////
	Arrow *ar5 = new Arrow(items2.at(7),items2.at(1));
    items2.at(7)->addArrow(ar5);
    items2.at(1)->addArrow(ar5);
    ////////////
	Arrow *ar6 = new Arrow(items2.at(7),items2.at(0));
    items2.at(0)->addArrow(ar6);
    items2.at(7)->addArrow(ar6);
    ///////////
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
    ///////////
    ar0->updatePosition();
    ar1->updatePosition();
    ar2->updatePosition();
    ar3->updatePosition();
    ar4->updatePosition();
    ar5->updatePosition();
    ar6->updatePosition();
    QPropertyAnimation *anim20 = new QPropertyAnimation(items2.at(0),"opacity" );
    anim20->setDuration(3001);
    anim20->setStartValue(0.0);
    anim20->setEndValue(1.0);
    QPropertyAnimation *anim21 = new QPropertyAnimation(items2.at(1),"opacity" );
    anim21->setDuration(3001);
    anim21->setStartValue(0.0);
    anim21->setEndValue(1.0);
    QPropertyAnimation *anim22 = new QPropertyAnimation(items2.at(2),"opacity" );
    anim22->setDuration(3001);
    anim22->setStartValue(0.0);
    anim22->setEndValue(1.0);
    QPropertyAnimation *anim23 = new QPropertyAnimation(items2.at(3),"opacity" );
    anim23->setDuration(3001);
    anim23->setStartValue(0.0);
    anim23->setEndValue(1.0);
    QPropertyAnimation *anim24 = new QPropertyAnimation(items2.at(4),"opacity" );
    anim24->setDuration(3001);
    anim24->setStartValue(0.0);
    anim24->setEndValue(1.0);
    QPropertyAnimation *anim25 = new QPropertyAnimation(items2.at(5),"opacity" );
    anim25->setDuration(3001);
    anim25->setStartValue(0.0);
    anim25->setEndValue(1.0);
    QPropertyAnimation *anim26 = new QPropertyAnimation(items2.at(6),"opacity" );
    anim26->setDuration(3001);
    anim26->setStartValue(0.0);
    anim26->setEndValue(1.0);
    QPropertyAnimation *anim27 = new QPropertyAnimation(items2.at(7),"opacity" );
    anim27->setDuration(3001);
    anim27->setStartValue(0.0);
    anim27->setEndValue(1.0);
    ///////////
    groupAnim_2->clear();
    groupAnim_2->addAnimation(anim20);
    groupAnim_2->addAnimation(anim21);
    groupAnim_2->addAnimation(anim22);
    groupAnim_2->addAnimation(anim23);
    groupAnim_2->addAnimation(anim24);
    groupAnim_2->addAnimation(anim25);
    groupAnim_2->addAnimation(anim26);
    groupAnim_2->addAnimation(anim27);
    groupAnim_2->start();
    //////////////////
    QPropertyAnimation *anim30 = new QPropertyAnimation(items2.at(0),"opacity" );
    anim30->setDuration(3001);
    anim30->setStartValue(1.0);
    anim30->setEndValue(0.0);
    QPropertyAnimation *anim31 = new QPropertyAnimation(items2.at(1),"opacity" );
    anim31->setDuration(3001);
    anim31->setStartValue(1.0);
    anim31->setEndValue(0.0);
    QPropertyAnimation *anim32 = new QPropertyAnimation(items2.at(2),"opacity" );
    anim32->setDuration(3001);
    anim32->setStartValue(1.0);
    anim32->setEndValue(0.0);
    QPropertyAnimation *anim33 = new QPropertyAnimation(items2.at(3),"opacity" );
    anim33->setDuration(3001);
    anim33->setStartValue(1.0);
    anim33->setEndValue(0.0);
    QPropertyAnimation *anim34 = new QPropertyAnimation(items2.at(4),"opacity" );
    anim34->setDuration(3001);
    anim34->setStartValue(1.0);
    anim34->setEndValue(0.0);
    QPropertyAnimation *anim35 = new QPropertyAnimation(items2.at(5),"opacity" );
    anim35->setDuration(3001);
    anim35->setStartValue(1.0);
    anim35->setEndValue(0.0);
    QPropertyAnimation *anim36 = new QPropertyAnimation(items2.at(6),"opacity" );
    anim36->setDuration(3001);
    anim36->setStartValue(1.0);
    anim36->setEndValue(0.0);
    QPropertyAnimation *anim37 = new QPropertyAnimation(items2.at(7),"opacity" );
    anim37->setDuration(3001);
    anim37->setStartValue(1.0);
    anim37->setEndValue(0.0);
    /////////////change position animation ///////
    QPropertyAnimation *anim40 = new QPropertyAnimation(items2.at(0),"pos" );
    anim40->setDuration(3001);
    anim40->setEndValue(items2.at(7)->pos());
    QPropertyAnimation *anim41 = new QPropertyAnimation(items2.at(1),"pos" );
    anim41->setDuration(3001);
    anim41->setEndValue(items2.at(7)->pos());
    QPropertyAnimation *anim42 = new QPropertyAnimation(items2.at(2),"pos" );
    anim42->setDuration(3001);
    anim42->setEndValue(items2.at(7)->pos());
    QPropertyAnimation *anim43 = new QPropertyAnimation(items2.at(3),"pos" );
    anim43->setDuration(3001);
    anim43->setEndValue(items2.at(7)->pos());
    QPropertyAnimation *anim44 = new QPropertyAnimation(items2.at(4),"pos" );
    anim44->setDuration(3001);
    anim44->setEndValue(items2.at(7)->pos());
    QPropertyAnimation *anim45 = new QPropertyAnimation(items2.at(5),"pos" );
    anim45->setDuration(3001);
    anim45->setEndValue(items2.at(7)->pos());
    QPropertyAnimation *anim46 = new QPropertyAnimation(items2.at(6),"pos" );
    anim46->setDuration(3001);
    anim46->setEndValue(items2.at(7)->pos());
    items2.at(6)->setZValue(1000);
    QPropertyAnimation *anim47 = new QPropertyAnimation(items2.at(7),"pos" );
    anim47->setDuration(3001);
    anim47->setEndValue(items2.at(6)->pos());
    items2.at(7)->setZValue(0);
    //////////////////////////

    anim40->setEasingCurve(QEasingCurve::OutExpo);
    anim41->setEasingCurve(QEasingCurve::OutExpo);
    anim42->setEasingCurve(QEasingCurve::OutExpo);
    anim43->setEasingCurve(QEasingCurve::OutExpo);
    anim44->setEasingCurve(QEasingCurve::OutExpo);
    anim45->setEasingCurve(QEasingCurve::OutExpo);
    anim46->setEasingCurve(QEasingCurve::OutExpo);
    anim47->setEasingCurve(QEasingCurve::OutExpo);
    groupAnim_3->clear();
    groupAnim_3->addAnimation(anim30);
    groupAnim_3->addAnimation(anim31);
    groupAnim_3->addAnimation(anim32);
    groupAnim_3->addAnimation(anim33);
    groupAnim_3->addAnimation(anim34);
    groupAnim_3->addAnimation(anim35);
    groupAnim_3->addAnimation(anim36);
    groupAnim_3->addAnimation(anim37);
    groupAnim_3->addAnimation(anim40);
    groupAnim_3->addAnimation(anim41);
    groupAnim_3->addAnimation(anim42);
    groupAnim_3->addAnimation(anim43);
    groupAnim_3->addAnimation(anim44);
    groupAnim_3->addAnimation(anim45);
    groupAnim_3->addAnimation(anim46);
    groupAnim_3->addAnimation(anim47);
    connect(items2.at(6), &MySquare::click, this, &Dialog::firstPage);
}

void Dialog::partnersPage()
{
    //std::cout << scene->
    groupAnim_1->start();
    //QTimer::singleShot(4100, scene, SLOT(clear()));
    //scene->clear();
    //QTimer::singleShot(4330, this, SLOT(setPartnersPage()));
    setPartnersPage();
}

QPropertyAnimation* Dialog::posAnimation(MySquare* ptr,int duration,QPointF startValue,
            QPointF endValue, QEasingCurve easing)
{
    QPropertyAnimation *anim = new QPropertyAnimation(ptr,"pos" );
    anim->setDuration(duration);
    anim->setStartValue(startValue);
    anim->setEndValue(endValue);
    anim->setEasingCurve(easing);
    return anim;
}

QPropertyAnimation* Dialog::opacityAnimation(MySquare* ptr,int duration,qreal startValue,
            qreal endValue, QEasingCurve easing)
{
    QPropertyAnimation *anim = new QPropertyAnimation(ptr,"opacity" );
    anim->setDuration(duration);
    anim->setStartValue(startValue);
    anim->setEndValue(endValue);
    anim->setEasingCurve(easing);
    return anim;
}

Dialog::~Dialog()
{
    //delete ui;
}
