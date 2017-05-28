#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    //ui->setupUi(this);
    //this->setGeometry(0,0,400,400);
    QHBoxLayout *hb = new QHBoxLayout();
    MyGraphicsView *gview = new MyGraphicsView();
    //QGraphicsView *gview = new QGraphicsView();
    hb->addWidget(gview);
    this->setLayout(hb);
    scene = new QGraphicsScene(this);
    //scene = new MyGraphicsScene(this);
    scene->setSceneRect(10,10,650,650);
    gview->setScene(scene);
    gview->setGeometry(0,0,700,700);
    scene->addRect(10,10,650,650);
    ////// setup First Page Items /////
    QList<MySquare * > item1 ;
    items   =  item1 ;
    for (int i=0 ;i<9 ;++i)
    {
        items.append(new MySquare);
    }

    items.at(0)->type();

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
    //items.at(0)->setSvgImage("instigate_design3.svg",QSizeF(286,203));
    items.at(1)->setSvgImage("barcode8.svg",QRectF(5,5,60,60));
    items.at(2)->setSvgImage("tools.svg",QRectF(16,15,32,35));
    items.at(3)->setSvgImage("settings21.svg",QRectF(17,17,44,47));
    items.at(4)->setSvgImage("newspaper11.svg",QRectF(15,16,36,39));
    items.at(5)->setSvgImage("address14.svg",QRectF(11,12,37,44));
    items.at(6)->setSvgImage("workers.svg",QRectF(12,15,38,46));
    items.at(7)->setSvgImage("businessman175.svg",QRectF(9,13,39,40));
    //items.at(8)->setSvgImage("image.svg",QRectF(14,16,35,37));
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
    //items.at(8)->setText(str8,QRectF(61,0,286,203));
    //////////////////
    items.at(8)->setZValue(1000);
    items.at(0)->setZValue(999);
    /////////////////
    items.at(1)->setText(str1_,QRectF(4,48,286,203));
    items.at(2)->setText(str2_,QRectF(10,50,286,203));
    items.at(3)->setText(str3_,QRectF(16,50,286,203));
    ////////////////
    QVariant null; // uninitialized QVariant == NULL or QVariant::invalid;
    initItem_0 = MySquareStruct  { null,null,\
        null,null,null,QString("instigate_design3.svg"),QSizeF(286,203),\
        null, null, null, null, null };
    initItem_8 = MySquareStruct { null,null,\
        null,null,null,QString("image.svg"),null,\
        QRectF(14,16,35,37), str8,QRectF(61,0,286,203), null, null };
    items.at(0)->initMySquare(initItem_0);
    items.at(8)->initMySquare(initItem_8);
    /////////////////
    // create arrows
    QList<Arrow *> arrow_list1;
    ar_list = arrow_list1  ;
	Arrow *ar0 = new Arrow(items.at(0),items.at(1));
    ar_list.append(ar0);
    items.at(0)->addArrow(ar0);
    items.at(1)->addArrow(ar0);
    /////////////////
	Arrow *ar1 = new Arrow(items.at(0),items.at(2));
    ar_list.append(ar1);
    items.at(0)->addArrow(ar1);
    items.at(2)->addArrow(ar1);
    /////////////////
	Arrow *ar2 = new Arrow(items.at(0),items.at(3));
    ar_list.append(ar2);
    items.at(0)->addArrow(ar2);
    items.at(3)->addArrow(ar2);
    /////////////////
	Arrow *ar3 = new Arrow(items.at(0),items.at(4));
    ar_list.append(ar3);
    items.at(0)->addArrow(ar3);
    items.at(4)->addArrow(ar3);
    /////////////////
	Arrow *ar4 = new Arrow(items.at(0),items.at(5));
    ar_list.append(ar4);
    items.at(0)->addArrow(ar4);
    items.at(5)->addArrow(ar4);
    /////////////////
	Arrow *ar5 = new Arrow(items.at(0),items.at(6));
    ar_list.append(ar5);
    items.at(0)->addArrow(ar5);
    items.at(6)->addArrow(ar5);
    /////////////////
	Arrow *ar6 = new Arrow(items.at(0),items.at(7));
    ar_list.append(ar6);
    items.at(0)->addArrow(ar6);
    items.at(7)->addArrow(ar6);
    /////////////////
	Arrow *ar7 = new Arrow(items.at(0),items.at(8));
    ar_list.append(ar7);
    items.at(0)->addArrow(ar7);
    items.at(8)->addArrow(ar7);
    /////////////////
	Arrow *ar8 = new Arrow(items.at(2),items.at(3));
    ar_list.append(ar8);
    items.at(2)->addArrow(ar8);
    items.at(3)->addArrow(ar8);
    /////////////////
	Arrow *ar9 = new Arrow(items.at(1),items.at(3));
    ar_list.append(ar9);
    items.at(1)->addArrow(ar9);
    items.at(3)->addArrow(ar9);
    /////// add items in scene //////////
    for (int i=0 ;i<9 ;++i)
    {
        scene->addItem(items.at(i));
    }
    for( int i=0; i<ar_list.count(); ++i )
    { 
        scene->addItem(ar_list.at(i));
        ar_list.at(i)->updatePosition();
        //ar_list.at(i)->setOpacity(0.0);
    }
    ///////// setup Second Page Items ////
    QList<MySquare * > item2 ;
    items2  =  item2 ;
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
    //items2.at(7)->setItemSize(211,281);
    //////////////////
    items2.at(0)->setImage("atmel.jpg",QRectF(12,15,226,41));
    items2.at(1)->setImage("xilinx.jpg",QRectF(34,6,186,63));
    items2.at(2)->setImage("exar.png",QRectF(18,2,212,77));
    items2.at(3)->setImage("uite.jpg",QRectF(21,11,151,66));
    items2.at(4)->setImage("logo_laflin.gif",QRectF(10,10,165,62));
    items2.at(5)->setImage("logo_conintec.jpg",QRectF(10,10,165,70));
    items2.at(6)->setSvgImage("instigate_design3.svg",QRectF(4,5,132,79));
    //items2.at(7)->setSvgImage("image.svg",QRectF(19,23,63,57));
    QString str2_8 = "<div  style='color:blue'><h3>\
     Partners and <br>Customers</h3></div>";
    QString str2_8_ = "<p>Many of the partners and<br> customers\
                     cannot be listed<br> due to NDA. It is possible\
                     to<br> obtain more information via<br> special request,\
                     under<br> condition that the partner<br> approves it.\
                     <br></p>";

    //items2.at(7)->setText(str2_8,QRectF(105,31,99,46));
    //items2.at(7)->setText(str2_8_,QRectF(21,97,176,170));
    items2.at(0)->setPos(529,72);
    items2.at(1)->setPos(598,216);
    items2.at(2)->setPos(568,343);
    items2.at(3)->setPos(522,479);
    items2.at(4)->setPos(50,466);
    items2.at(5)->setPos(39,264);
    items2.at(6)->setPos(42,139);
    //items2.at(7)->setPos(291,168);
    //////// items.at(8) equal items2.at(7)  ////////
    initItem_8_2_page = MySquareStruct  { null,null,\
        null,null,null,QString("image.svg"),null,\
        QRectF(19,23,63,57), str2_8 ,QRectF(105,31,99,46),\
        str2_8_, QRectF(21,97,176,170) };
    //items.at(8)->initMySquare(initItem_8_2_page);
    items.at(8)->printStruct(initItem_8_2_page);
    //////// items.at(0) equal items2.at(6)  ////////
    initItem_0_2_page = MySquareStruct  { null,null,\
        null,null,null,QString("instigate_design3.svg"),null,\
        QRectF(4,5,132,79), null, null, null, null };

    // create arrows
    QList<Arrow *> arrow_list2;
    ar2_list  = arrow_list2 ;
	//Arrow *ar2_0 = new Arrow(items.at(0),items.at(8));
    //ar2_list.append(ar2_0);
    //items.at(8)->addArrow(ar2_0);
    //items.at(0)->addArrow(ar2_0);
    ///////////////
	Arrow *ar2_1 = new Arrow(items.at(8),items2.at(5));
    ar2_list.append(ar2_1);
    items.at(8)->addArrow(ar2_1);
    items2.at(5)->addArrow(ar2_1);
    //////////////
	Arrow *ar2_2 = new Arrow(items.at(8),items2.at(4));
    ar2_list.append(ar2_2);
    items.at(8)->addArrow(ar2_2);
    items2.at(4)->addArrow(ar2_2);
    /////////////
	Arrow *ar2_3 = new Arrow(items.at(8),items2.at(3));
    ar2_list.append(ar2_3);
    items.at(8)->addArrow(ar2_3);
    items2.at(3)->addArrow(ar2_3);
    ////////////
	Arrow *ar2_4 = new Arrow(items.at(8),items2.at(2));
    ar2_list.append(ar2_4);
    items.at(8)->addArrow(ar2_4);
    items2.at(2)->addArrow(ar2_4);
    ////////////
	Arrow *ar2_5 = new Arrow(items.at(8),items2.at(1));
    ar2_list.append(ar2_5);
    items.at(8)->addArrow(ar2_5);
    items2.at(1)->addArrow(ar2_5);
    ////////////
	Arrow *ar2_6 = new Arrow(items.at(8),items2.at(0));
    ar2_list.append(ar2_6);
    items2.at(0)->addArrow(ar2_6);
    items.at(8)->addArrow(ar2_6);
    /////////// add second page items in scene /////////
    for (int i=0 ;i<7 ;++i)
    {
        scene->addItem(items2.at(i));
        items2.at(i)->setOpacity(0.000);
    }
    for( int i=0; i<ar2_list.count(); ++i )
    { 
        scene->addItem(ar2_list.at(i));
        ar2_list.at(i)->updatePosition();
        ar2_list.at(i)->setOpacity(0.0);
        ar2_list.at(i)->hide();
    }
    groupAnim_1 = new QParallelAnimationGroup;
    groupAnim_2 = new QParallelAnimationGroup;
    groupAnim_3 = new QParallelAnimationGroup;
    connect(items.at(8), &MySquare::click, this, &Dialog::partnersPage);
    connect(items2.at(6), &MySquare::click, this, &Dialog::firstPage);
    //QList<QGraphicsItem * > allItms = scene->items();
    //for( int i=0; i<allItms.count(); ++i )
    //{ 
    //    qDebug() << i  << " \n";
    //    //allItms.at(i)->setOpacity(0.0000);
    //}
    //setFirstPage();
    firstAppearance();
    groupAnim_1->start();
    animateSecondPage();
    setFirstPage();

}

void Dialog::firstAppearance()
{
    ///////////// apearance of first page //////////////
    //groupAnim_2->clear();
    for (int i=0 ;i<9 ;++i)
    {
        groupAnim_1->addAnimation(opacityAnimation(
                                items.at(i),2001,0.0,1.0,QEasingCurve::Linear));   
    }
}

void Dialog::setFirstPage()
{
    // set Animation when page changed //
    //removeChildItems(items.at(8));
    //scene->removeItem(items.at(8));
    //items.at(8)->setText("heloooooooooo",QRectF(105,31,99,46));
    //////////////////////
    groupAnim_2->addAnimation(posAnimation(
                                items.at(0),2001,QPointF(291,168),
                                QPointF(42,139),QEasingCurve::OutExpo));
    groupAnim_2->addAnimation(posAnimation(
                                items.at(8),2001,QPointF(42,139),
                                QPointF(291,168),QEasingCurve::OutExpo));
    ////////////////////////
    //groupAnim_2->addAnimation(opacityAnimation(
    //                          items.at(0),2001,1.0,0.0,QEasingCurve::InExpo));
    groupAnim_2->addAnimation(opacityAnimation(
                              items.at(1),2001,1.0,0.0,QEasingCurve::OutExpo));
    groupAnim_2->addAnimation(opacityAnimation(
                              items.at(2),2001,1.0,0.0,QEasingCurve::OutExpo));
    groupAnim_2->addAnimation(opacityAnimation(
                              items.at(3),2001,1.0,0.0,QEasingCurve::OutExpo));
    groupAnim_2->addAnimation(opacityAnimation(
                              items.at(4),2001,1.0,0.0,QEasingCurve::OutExpo));
    groupAnim_2->addAnimation(opacityAnimation(
                              items.at(5),2001,1.0,0.0,QEasingCurve::OutExpo));
    groupAnim_2->addAnimation(opacityAnimation(
                              items.at(6),2001,1.0,0.0,QEasingCurve::OutExpo));
    groupAnim_2->addAnimation(opacityAnimation(
                              items.at(7),2001,1.0,0.0,QEasingCurve::OutExpo));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                          items.at(8),2001,1.0,0.0,QEasingCurve::InExpo));
    ////////////////////
    groupAnim_2->addAnimation(sizeAnimation(
                              items.at(8),
                              2001,
                              QSizeF(169,70),
                              QSizeF(211,281),
                              QEasingCurve::OutExpo));
    ////////////////////
    groupAnim_2->addAnimation(sizeAnimation(
                              items.at(0),
                              2001,
                              QSizeF(291,168),
                              QSizeF(148,89),
                              QEasingCurve::OutExpo));
    /////////////////// second page items /////////////
    groupAnim_2->addAnimation(opacityAnimation(
                                items2.at(0), 2001,0.0,1.0,
                                QEasingCurve::Linear));
    groupAnim_2->addAnimation(opacityAnimation(
                                items2.at(1), 2001,0.0,1.0,
                                QEasingCurve::Linear));
    groupAnim_2->addAnimation(opacityAnimation(
                                items2.at(2), 2001,0.0,1.0,
                                QEasingCurve::Linear));
    groupAnim_2->addAnimation(opacityAnimation(
                                items2.at(3), 2001,0.0,1.0,
                                QEasingCurve::Linear));
    groupAnim_2->addAnimation(opacityAnimation(
                                items2.at(4), 2001,0.0,1.0,
                                QEasingCurve::Linear));
    groupAnim_2->addAnimation(opacityAnimation(
                                items2.at(5), 2001,0.0,1.0,
                                QEasingCurve::Linear));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            items2.at(6), 2001,0.0,1.0,
    //                            QEasingCurve::Linear));
    //groupAnim_2->addAnimation(opacityAnimation(
    //                            items2.at(7), 2001,0.0,1.0,
    //                            QEasingCurve::Linear));
    //groupAnim_3->stop();
    //groupAnim_2->start();
}

void Dialog::firstPage()
{

    //items.at(0)->setPos(291,168);
    items.at(1)->setPos(106,423);
    items.at(2)->setPos(647,203);
    items.at(3)->setPos(489,414);
    items.at(4)->setPos(475,57);
    items.at(5)->setPos(259,57);
    items.at(6)->setPos(41,232);
    items.at(7)->setPos(42,328);
    //items.at(8)->setPos(42,139);
    ///////////////////
    //items.at(0)->setItemSize(314,220);
    //items.at(8)->setItemSize(169,70);
    items.at(0)->disconnect();
    connect(items.at(8), &MySquare::click, this, &Dialog::partnersPage);
    removeChildItems(items.at(8));
    removeChildItems(items.at(0));
    //scene->addItem(items.at(8));
    items.at(8)->printStruct(initItem_8_2_page);
    items.at(8)->initMySquare(initItem_8);
    items.at(0)->initMySquare(initItem_0);
    groupAnim_2->stop();
    groupAnim_3->start();
    //setFirstPage();
    for( int i=0; i<ar2_list.count(); ++i )
    { 
        scene->addItem(ar2_list.at(i));
        ar2_list.at(i)->updatePosition();
        ar2_list.at(i)->setOpacity(0.0);
        ar2_list.at(i)->hide();
    }
}
void Dialog::animateSecondPage()
{

    /////////////change position animation ///////
    groupAnim_3->addAnimation(opacityAnimation(
                               items2.at(0), 2001,1.0,
                               0.0,QEasingCurve::Linear));
    groupAnim_3->addAnimation(opacityAnimation(
                               items2.at(1), 2001,1.0,0.0,
                               QEasingCurve::Linear));
    groupAnim_3->addAnimation(opacityAnimation(
                               items2.at(2), 2001,1.0,0.0,
                               QEasingCurve::Linear));
    groupAnim_3->addAnimation(opacityAnimation(
                               items2.at(3), 2001,1.0,0.0,
                               QEasingCurve::Linear));
    groupAnim_3->addAnimation(opacityAnimation(
                               items2.at(4), 2001,1.0,0.0,
                               QEasingCurve::Linear));
    groupAnim_3->addAnimation(opacityAnimation(
                               items2.at(5), 2001,1.0,0.0,
                               QEasingCurve::Linear));
    //groupAnim_3->addAnimation(opacityAnimation(
    //                           items2.at(6), 2001,1.0,0.0,
    //                           QEasingCurve::Linear));
    //groupAnim_3->addAnimation(opacityAntimation(
    //                           items2.at(7), 2001,1.0,0.0,
    //                           QEasingCurve::Linear));
    //////////////////////
    //items2.at(6)->setZValue(1000);
    //items2.at(7)->setZValue(0);
    ////////////////////
    groupAnim_3->addAnimation(sizeAnimation(
                              items.at(8),
                              2001,
                              QSizeF(211,281),
                              QSizeF(169,70),
                              QEasingCurve::OutExpo));
    ////////////////////
    groupAnim_3->addAnimation(sizeAnimation(
                              items.at(0),
                              2001,
                              QSizeF(148,89),
                              QSizeF(314,220),
                              QEasingCurve::OutExpo));
    //////////////////
    groupAnim_3->addAnimation(opacityAnimation(
                              items.at(1),2001,0.0,1.0,QEasingCurve::OutExpo));
    groupAnim_3->addAnimation(opacityAnimation(
                              items.at(2),2001,0.0,1.0,QEasingCurve::OutExpo));
    groupAnim_3->addAnimation(opacityAnimation(
                              items.at(3),2001,0.0,1.0,QEasingCurve::OutExpo));
    groupAnim_3->addAnimation(opacityAnimation(
                              items.at(4),2001,0.0,1.0,QEasingCurve::OutExpo));
    groupAnim_3->addAnimation(opacityAnimation(
                              items.at(5),2001,0.0,1.0,QEasingCurve::OutExpo));
    groupAnim_3->addAnimation(opacityAnimation(
                              items.at(6),2001,0.0,1.0,QEasingCurve::OutExpo));
    groupAnim_3->addAnimation(opacityAnimation(
                              items.at(7),2001,0.0,1.0,QEasingCurve::OutExpo));
    /////////////// position change //////////
    groupAnim_3->addAnimation(posAnimation(
                                items.at(0),2001,QPointF(42,139),
                                QPointF(291,168),QEasingCurve::Linear));
    groupAnim_3->addAnimation(posAnimation(
                                items.at(8),2001,QPointF(291,168),
                                QPointF(42,139),QEasingCurve::Linear));
}

void Dialog::partnersPage()
{
    items.at(8)->disconnect();
    connect(items.at(0), &MySquare::click, this, &Dialog::firstPage);
    removeChildItems(items.at(8));
    removeChildItems(items.at(0));
    //scene->addItem(items.at(8));
    items.at(8)->printStruct(initItem_8_2_page);
    items.at(8)->initMySquare(initItem_8_2_page);
    items.at(0)->initMySquare(initItem_0_2_page);
    //QTimer::singleShot(4100, scene, SLOT(clear()));
    //scene->clear();
    //QTimer::singleShot(4330, this, SLOT(animateSecondPage()));
    //animateSecondPage();
    connect(groupAnim_2,SIGNAL(finished()),this,SLOT(showSecondPageArrows()));
    groupAnim_2->start();
    
}

QPropertyAnimation* Dialog::posAnimation(MySquare* ptr,int duration,
        QPointF startValue,
        QPointF endValue,
        QEasingCurve easing)
{
    QPropertyAnimation *anim = new QPropertyAnimation(ptr,"pos" );
    anim->setDuration(duration);
    anim->setStartValue(startValue);
    anim->setEndValue(endValue);
    anim->setEasingCurve(easing);
    return anim;
}

QPropertyAnimation* Dialog::opacityAnimation(MySquare* ptr,
            int duration,
            qreal startValue,
            qreal endValue,
            QEasingCurve easing)
{
    QPropertyAnimation *anim = new QPropertyAnimation(ptr,"opacity" );
    anim->setDuration(duration);
    anim->setStartValue(startValue);
    anim->setEndValue(endValue);
    anim->setEasingCurve(easing);
    return anim;
}

QPropertyAnimation* Dialog::sizeAnimation(MySquare* ptr,
            int duration,
            QSizeF startValue,
            QSizeF endValue,
            QEasingCurve easing)
{
    QPropertyAnimation *anim = new QPropertyAnimation(ptr,"size" );
    anim->setDuration(duration);
    anim->setStartValue(startValue);
    anim->setEndValue(endValue);
    anim->setEasingCurve(easing);
    return anim;
}

void Dialog::removeChildItems(MySquare* item)
{
    QList<QGraphicsItem*> item_ =item->childItems();
    QList<QGraphicsItem*>::iterator i;
    for (i = item_.begin(); i != item_.end(); ++i)
    {
           //qDebug() <<  typeid(i).name();
           //(*i)->setParentItem(NULL);
           delete (*i);
    }
}

void Dialog::showSecondPageArrows()
{
            qDebug() << "ar2_list finished\n\n\n\n";
            qDebug() << "duration ====" << groupAnim_2->currentTime();
                                                                      ;
    //if (groupAnim_3->currentTime() == 1)
    {
        for( int i=0; i<ar2_list.count(); ++i )
        { 
            ar2_list.at(i)->updatePosition();
            ar2_list.at(i)->show();
            qDebug() << "ar2_list finished";
        }
    }
}

void Dialog::showFirstPageArrows()
{
            qDebug() << "ar_list finished\n\n\n\n";
            qDebug() << "duration ====" << groupAnim_2->currentTime();
    //if (groupAnim_2->currentTime() == 1)
    {
        for( int i=0; i<ar_list.count(); ++i )
        { 
            ar_list.at(i)->updatePosition();
            ar_list.at(i)->show();
            qDebug() << "ar_list finished\n\n\n\n";
        }
    }
                                                                      ;
}

Dialog::~Dialog()
{
    //delete ui;
}
