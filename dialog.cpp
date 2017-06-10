#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
        QDialog(parent)
{
        QHBoxLayout *hb = new QHBoxLayout();
        MyGraphicsView *gview = new MyGraphicsView();
        //QGraphicsView *gview = new QGraphicsView();
        hb->addWidget(gview);
        this->setLayout(hb);
        m_scene = new QGraphicsScene(this);
        //m_scene = new MyGraphicsScene(this);
        m_scene->setSceneRect(10,10,650,650);
        gview->setScene(m_scene);
        gview->setGeometry(0,0,700,700);
        QGraphicsRectItem *sceneRect = new QGraphicsRectItem(10,10,650,650);
        sceneRect->setZValue(-11001);
        m_scene->addItem(sceneRect);
        //m_scene->addRect(10,10,650,650);
        setup_1_page_items();
        setup_2_page_items();
        m_group_anim_1 = new QParallelAnimationGroup;
        m_group_anim_2 = new QParallelAnimationGroup;
        m_group_anim_3 = new QParallelAnimationGroup;
        connect(m_items.at(8), &MySquare::click,
                this, &Dialog::animate_and_show_2_page);
        connect(m_items2.at(6), &MySquare::click,
                this, &Dialog::animate_and_show_1_page);
        //QList<QGraphicsItem * > allItms = m_scene->m_items();
        //for( int i=0; i<allItms.count(); ++i )
        //{ 
        //    qDebug() << i  << " \n";
        //    //allItms.at(i)->setOpacity(0.0000);
        //}
        //create_2_page_animation();
        //show_first_page();
        //m_group_anim_1->start();
        create_1_page_animation();
        create_2_page_animation();
}

void Dialog::show_first_page()
{
        ///////////// apearance of first page //////////////
        //m_group_anim_2->clear();
        for (int i=0 ;i<9 ;++i)
        {
                m_group_anim_1->addAnimation(opacity_animation(
                        m_items.at(i),701,0.0,1.0,QEasingCurve::Linear));
        }
}

void Dialog::create_2_page_animation()
{
        // set Animation when page changed //
        //remove_child_items(m_items.at(8));
        //////////////////////
        m_group_anim_2->addAnimation(pos_animation(
                                m_items.at(0),701,QPointF(291,168),
                                QPointF(42,139),QEasingCurve::OutExpo));
        m_group_anim_2->addAnimation(pos_animation(
                                m_items.at(8),701,QPointF(42,139),
                                QPointF(291,168),QEasingCurve::OutExpo));
        ////////////////////////
        //m_group_anim_2->addAnimation(opacity_animation(
        //        m_items.at(0),701,1.0,0.0,QEasingCurve::InExpo));
        m_group_anim_2->addAnimation(opacity_animation(
                m_items.at(1),701,1.0,0.0,QEasingCurve::OutExpo));
        m_group_anim_2->addAnimation(opacity_animation(
                m_items.at(2),701,1.0,0.0,QEasingCurve::OutExpo));
        m_group_anim_2->addAnimation(opacity_animation(
                m_items.at(3),701,1.0,0.0,QEasingCurve::OutExpo));
        m_group_anim_2->addAnimation(opacity_animation(
                m_items.at(4),701,1.0,0.0,QEasingCurve::OutExpo));
        m_group_anim_2->addAnimation(opacity_animation(
                m_items.at(5),701,1.0,0.0,QEasingCurve::OutExpo));
        m_group_anim_2->addAnimation(opacity_animation(
                m_items.at(6),701,1.0,0.0,QEasingCurve::OutExpo));
        m_group_anim_2->addAnimation(opacity_animation(
                m_items.at(7),701,1.0,0.0,QEasingCurve::OutExpo));
        //m_group_anim_2->addAnimation(opacity_animation(
        //        m_items.at(8),701,1.0,0.0,QEasingCurve::InExpo));
        ////////////////////
        m_group_anim_2->addAnimation(size_animation(
                                m_items.at(8),
                                701,
                                QSizeF(169,70),
                                QSizeF(211,281),
                                QEasingCurve::OutExpo));
        ////////////////////
        m_group_anim_2->addAnimation(size_animation(
                                m_items.at(0),
                                701,
                                QSizeF(291,168),
                                QSizeF(148,89),
                                QEasingCurve::OutExpo));
        /////////////////// second page m_items /////////////
        m_group_anim_2->addAnimation(opacity_animation(
                                m_items2.at(0), 701,0.0,1.0,
                                QEasingCurve::Linear));
        m_group_anim_2->addAnimation(opacity_animation(
                                m_items2.at(1), 701,0.0,1.0,
                                QEasingCurve::Linear));
        m_group_anim_2->addAnimation(opacity_animation(
                                m_items2.at(2), 701,0.0,1.0,
                                QEasingCurve::Linear));
        m_group_anim_2->addAnimation(opacity_animation(
                                m_items2.at(3), 701,0.0,1.0,
                                QEasingCurve::Linear));
        m_group_anim_2->addAnimation(opacity_animation(
                                m_items2.at(4), 701,0.0,1.0,
                                QEasingCurve::Linear));
        m_group_anim_2->addAnimation(opacity_animation(
                                m_items2.at(5), 701,0.0,1.0,
                                QEasingCurve::Linear));
        //m_group_anim_2->addAnimation(opacity_animation(
        //                            m_items2.at(6), 701,0.0,1.0,
        //                            QEasingCurve::Linear));
        //m_group_anim_2->addAnimation(opacity_animation(
        //                            m_items2.at(7), 701,0.0,1.0,
        //                            QEasingCurve::Linear));
        //m_group_anim_3->stop();
        //m_group_anim_2->start();
}

void Dialog::animate_and_show_1_page()
{
        //m_items.at(0)->setPos(291,168);
        m_items.at(1)->setPos(106,423);
        m_items.at(2)->setPos(647,203);
        m_items.at(3)->setPos(489,414);
        m_items.at(4)->setPos(475,57);
        m_items.at(5)->setPos(259,57);
        m_items.at(6)->setPos(41,232);
        m_items.at(7)->setPos(42,328);
        //m_items.at(8)->setPos(42,139);
        ///////////////////
        //m_items.at(0)->set_item_size(314,220);
        //m_items.at(8)->set_item_size(169,70);
        m_items.at(0)->disconnect();
        connect(m_items.at(8), &MySquare::click,
                this, &Dialog::animate_and_show_2_page);
        remove_child_items(m_items.at(8));
        remove_child_items(m_items.at(0));
        //m_scene->addItem(m_items.at(8));
        m_items.at(8)->print_struct(item_struct_8_2_page);
        m_items.at(8)->initMySquare(item_struct_8);
        m_items.at(0)->initMySquare(item_struct_0);
        m_group_anim_2->stop();
        hide_second_page_arrows();
        connect(m_group_anim_3,SIGNAL(finished()),
                this,SLOT(show_first_page_arrows()));
        m_group_anim_3->start();
        //create_2_page_animation();
}
void Dialog::create_1_page_animation()
{
        /////////////change position animation ///////
        m_group_anim_3->addAnimation(opacity_animation(
                                m_items2.at(0), 701,1.0,
                                0.0,QEasingCurve::Linear));
        m_group_anim_3->addAnimation(opacity_animation(
                                m_items2.at(1), 701,1.0,0.0,
                                QEasingCurve::Linear));
        m_group_anim_3->addAnimation(opacity_animation(
                                m_items2.at(2), 701,1.0,0.0,
                                QEasingCurve::Linear));
        m_group_anim_3->addAnimation(opacity_animation(
                                m_items2.at(3), 701,1.0,0.0,
                                QEasingCurve::Linear));
        m_group_anim_3->addAnimation(opacity_animation(
                                m_items2.at(4), 701,1.0,0.0,
                                QEasingCurve::Linear));
        m_group_anim_3->addAnimation(opacity_animation(
                                m_items2.at(5), 701,1.0,0.0,
                                QEasingCurve::Linear));
        //m_group_anim_3->addAnimation(opacity_animation(
        //                           m_items2.at(6), 701,1.0,0.0,
        //                           QEasingCurve::Linear));
        //m_group_anim_3->addAnimation(opacityAntimation(
        //                           m_items2.at(7), 701,1.0,0.0,
        //                           QEasingCurve::Linear));
        //////////////////////
        //m_items2.at(6)->setZValue(1000);
        //m_items2.at(7)->setZValue(0);
        ////////////////////
        m_group_anim_3->addAnimation(size_animation(
                                m_items.at(8),
                                701,
                                QSizeF(211,281),
                                QSizeF(169,70),
                                QEasingCurve::OutExpo));
        ////////////////////
        m_group_anim_3->addAnimation(size_animation(
                                m_items.at(0),
                                701,
                                QSizeF(148,89),
                                QSizeF(314,220),
                                QEasingCurve::OutExpo));
        //////////////////
        m_group_anim_3->addAnimation(opacity_animation(
                m_items.at(1),701,0.0,1.0,QEasingCurve::OutExpo));
        m_group_anim_3->addAnimation(opacity_animation(
                m_items.at(2),701,0.0,1.0,QEasingCurve::OutExpo));
        m_group_anim_3->addAnimation(opacity_animation(
                m_items.at(3),701,0.0,1.0,QEasingCurve::OutExpo));
        m_group_anim_3->addAnimation(opacity_animation(
                m_items.at(4),701,0.0,1.0,QEasingCurve::OutExpo));
        m_group_anim_3->addAnimation(opacity_animation(
                m_items.at(5),701,0.0,1.0,QEasingCurve::OutExpo));
        m_group_anim_3->addAnimation(opacity_animation(
                m_items.at(6),701,0.0,1.0,QEasingCurve::OutExpo));
        m_group_anim_3->addAnimation(opacity_animation(
                m_items.at(7),701,0.0,1.0,QEasingCurve::OutExpo));
        /////////////// position change //////////
        m_group_anim_3->addAnimation(pos_animation(
                m_items.at(0),701,QPointF(42,139),
                QPointF(291,168),QEasingCurve::Linear));
        m_group_anim_3->addAnimation(pos_animation(
                m_items.at(8),701,QPointF(291,168),
                QPointF(42,139),QEasingCurve::Linear));
}

void Dialog::animate_and_show_2_page()
{
        m_items.at(8)->disconnect();
        connect(m_items.at(0), &MySquare::click,
                this, &Dialog::animate_and_show_1_page);
        remove_child_items(m_items.at(8));
        remove_child_items(m_items.at(0));
        //m_scene->addItem(m_items.at(8));
        m_items.at(8)->print_struct(item_struct_8_2_page);
        m_items.at(8)->initMySquare(item_struct_8_2_page);
        m_items.at(0)->initMySquare(item_struct_0_2_page);
        //QTimer::singleShot(4100, m_scene, SLOT(clear()));
        //m_scene->clear();
        //QTimer::singleShot(4330, this, SLOT(create_1_page_animation()));
        //create_1_page_animation();
        hide_first_page_arrows();
        connect(m_group_anim_2,SIGNAL(finished()),
                this,SLOT(show_second_page_arrows()));
        m_group_anim_2->start();
}

QPropertyAnimation* Dialog::pos_animation(MySquare* ptr,int duration,
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

QPropertyAnimation* Dialog::opacity_animation(MySquare* ptr,
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

QPropertyAnimation* Dialog::size_animation(MySquare* ptr,
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

void Dialog::remove_child_items(MySquare* item)
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


void Dialog::setup_1_page_items()
{
        QList<MySquare * > item1 ;
        m_items   =  item1 ;
        for (int i=0 ;i<9 ;++i)
        {
                m_items.append(new MySquare);
        }
        m_items.at(0)->set_item_size(314,220);
        m_items.at(1)->set_item_size(305,171);
        m_items.at(2)->set_item_size(250,155);
        m_items.at(3)->set_item_size(409,209);
        m_items.at(4)->set_item_size(169,70);
        m_items.at(5)->set_item_size(169,70);
        m_items.at(6)->set_item_size(169,70);
        m_items.at(7)->set_item_size(169,70);
        m_items.at(8)->set_item_size(169,70);
        m_items.at(0)->setPos(291,168);
        m_items.at(1)->setPos(106,423);
        m_items.at(2)->setPos(647,203);
        m_items.at(3)->setPos(489,414);
        m_items.at(4)->setPos(475,57);
        m_items.at(5)->setPos(259,57);
        m_items.at(6)->setPos(41,232);
        m_items.at(7)->setPos(42,328);
        m_items.at(8)->setPos(42,139);
        //m_items.at(0)->set_svg_image("instigate_design3.svg",QSizeF(286,203));
        m_items.at(1)->set_svg_image("barcode8.svg",QRectF(5,5,60,60));
        m_items.at(2)->set_svg_image("tools.svg",QRectF(16,15,32,35));
        m_items.at(3)->set_svg_image("settings21.svg",QRectF(17,17,44,47));
        m_items.at(4)->set_svg_image("newspaper11.svg",QRectF(15,16,36,39));
        m_items.at(5)->set_svg_image("address14.svg",QRectF(11,12,37,44));
        m_items.at(6)->set_svg_image("workers.svg",QRectF(12,15,38,46));
        m_items.at(7)->set_svg_image("businessman175.svg",QRectF(9,13,39,40));
        //m_items.at(8)->set_svg_image("image.svg",QRectF(14,16,35,37));
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
        QString str2_ = "<ul><li>System Development</li><li>System \
                         Verification</li><li>System Validation</li></ul>";
        QString str1_ = "<ul><li>CAD Application Framework</li><li>\
                         SW and HW IDE Framework</li><li>\
                         IP-XACT Front-End</li></ul>"; 
                         m_items.at(1)->set_text(str1,QRectF(64,22,286,203));
        m_items.at(2)->set_text(str2,QRectF(63,20,286,203));
        m_items.at(3)->set_text(str3,QRectF(71,23,286,203));
        m_items.at(4)->set_text(str4,QRectF(73,21,286,203));
        m_items.at(5)->set_text(str5,QRectF(64,21,286,203));
        m_items.at(6)->set_text(str6,QRectF(66,22,286,203));
        m_items.at(7)->set_text(str7,QRectF(63,22,286,203));
        //m_items.at(8)->set_text(str8,QRectF(61,0,286,203));
        //////////////////
        //m_items.at(8)->setZValue(1000);
        //m_items.at(0)->setZValue(999);
        /////////////////
        m_items.at(1)->set_text(str1_,QRectF(4,48,286,203));
        m_items.at(2)->set_text(str2_,QRectF(10,50,286,203));
        m_items.at(3)->set_text(str3_,QRectF(16,50,286,203));
        ////////////////
        QVariant null; // uninitialized QVariant == NULL or QVariant::invalid;
        item_struct_0 = MySquareStruct  { null,null,\
                null,null,null,QString("instigate_design3.svg"),\
                QSizeF(286,203), null, null, null, null, null };
        item_struct_8 = MySquareStruct { null,null,\
                null,null,null,QString("image.svg"),null,\
                QRectF(14,16,35,37), str8,QRectF(61,0,286,203), null, null };
        m_items.at(0)->initMySquare(item_struct_0);
        m_items.at(8)->initMySquare(item_struct_8);
        // create arrows
        QList<Arrow *> arrow_list1;
        m_ar_list = arrow_list1  ;
        Arrow *ar0 = new Arrow(m_items.at(0),m_items.at(1));
        m_ar_list.append(ar0);
        m_items.at(0)->add_arrow(ar0);
        m_items.at(1)->add_arrow(ar0);
        /////////////////
        Arrow *ar1 = new Arrow(m_items.at(0),m_items.at(2));
        m_ar_list.append(ar1);
        m_items.at(0)->add_arrow(ar1);
        m_items.at(2)->add_arrow(ar1);
        /////////////////
        Arrow *ar2 = new Arrow(m_items.at(0),m_items.at(3));
        m_ar_list.append(ar2);
        m_items.at(0)->add_arrow(ar2);
        m_items.at(3)->add_arrow(ar2);
        /////////////////
        Arrow *ar3 = new Arrow(m_items.at(0),m_items.at(4));
        m_ar_list.append(ar3);
        m_items.at(0)->add_arrow(ar3);
        m_items.at(4)->add_arrow(ar3);
        /////////////////
        Arrow *ar4 = new Arrow(m_items.at(0),m_items.at(5));
        m_ar_list.append(ar4);
        m_items.at(0)->add_arrow(ar4);
        m_items.at(5)->add_arrow(ar4);
        /////////////////
        Arrow *ar5 = new Arrow(m_items.at(0),m_items.at(6));
        m_ar_list.append(ar5);
        m_items.at(0)->add_arrow(ar5);
        m_items.at(6)->add_arrow(ar5);
        /////////////////
        Arrow *ar6 = new Arrow(m_items.at(0),m_items.at(7));
        m_ar_list.append(ar6);
        m_items.at(0)->add_arrow(ar6);
        m_items.at(7)->add_arrow(ar6);
        /////////////////
        Arrow *ar7 = new Arrow(m_items.at(0),m_items.at(8));
        m_ar_list.append(ar7);
        m_items.at(0)->add_arrow(ar7);
        m_items.at(8)->add_arrow(ar7);
        /////////////////
        Arrow *ar8 = new Arrow(m_items.at(2),m_items.at(3));
        m_ar_list.append(ar8);
        m_items.at(2)->add_arrow(ar8);
        m_items.at(3)->add_arrow(ar8);
        /////////////////
        Arrow *ar9 = new Arrow(m_items.at(1),m_items.at(3));
        m_ar_list.append(ar9);
        m_items.at(1)->add_arrow(ar9);
        m_items.at(3)->add_arrow(ar9);
        /////// add m_items in m_scene //////////
        for (int i=0 ;i<9 ;++i)
        {
                m_scene->addItem(m_items.at(i));
        }
        for( int i=0; i<m_ar_list.count(); ++i )
        { 
                m_scene->addItem(m_ar_list.at(i));
                m_ar_list.at(i)->update_position();
                //m_ar_list.at(i)->setZValue(-1000);
                //m_ar_list.at(i)->setOpacity(0.0);
        }

}
void Dialog::setup_2_page_items()
{
        ///////// setup Second Page Items ////
        QList<MySquare * > item2 ;
        m_items2  =  item2 ;
        for (int i=0 ;i<8 ;++i)
        {
                m_items2.append(new MySquare);
        }
        m_items2.at(0)->set_item_size(248,79);
        m_items2.at(1)->set_item_size(248,79);
        m_items2.at(2)->set_item_size(248,81);
        m_items2.at(3)->set_item_size(196,94);
        m_items2.at(4)->set_item_size(198,84);
        m_items2.at(5)->set_item_size(198,84);
        m_items2.at(6)->set_item_size(148,89);
        //m_items2.at(7)->set_item_size(211,281);
        //////////////////
        m_items2.at(0)->set_image("atmel.jpg",QRectF(12,15,226,41));
        m_items2.at(1)->set_image("xilinx.jpg",QRectF(34,6,186,63));
        m_items2.at(2)->set_image("exar.png",QRectF(18,2,212,77));
        m_items2.at(3)->set_image("uite.jpg",QRectF(21,11,151,66));
        m_items2.at(4)->set_image("logo_laflin.gif",QRectF(10,10,165,62));
        m_items2.at(5)->set_image("logo_conintec.jpg",QRectF(10,10,165,70));
        m_items2.at(6)->set_svg_image("instigate_design3.svg",QRectF(4,5,132,79));
        //m_items2.at(7)->set_svg_image("image.svg",QRectF(19,23,63,57));
        QString str2_8 = "<div  style='color:blue'><h3>\
                          Partners and <br>Customers</h3></div>";
        QString str2_8_ = "<p>Many of the partners and<br> customers\
                           cannot be listed<br> due to NDA. It is possible\
                           to<br> obtain more information via<br> special\
                           request, under<br> condition that the\
                           partner<br> approves it. <br></p>";
        //m_items2.at(7)->set_text(str2_8,QRectF(105,31,99,46));
        //m_items2.at(7)->set_text(str2_8_,QRectF(21,97,176,170));
        m_items2.at(0)->setPos(529,72);
        m_items2.at(1)->setPos(598,216);
        m_items2.at(2)->setPos(568,343);
        m_items2.at(3)->setPos(522,479);
        m_items2.at(4)->setPos(50,466);
        m_items2.at(5)->setPos(39,264);
        m_items2.at(6)->setPos(42,139);
        //m_items2.at(7)->setPos(291,168);
        //////// m_items.at(8) equal m_items2.at(7)  ////////
        QVariant null; // uninitialized QVariant == NULL or QVariant::invalid;
        item_struct_8_2_page = MySquareStruct  { null,null,\
                null,null,null,QString("image.svg"),null,\
                        QRectF(19,23,63,57), str2_8 ,QRectF(105,31,99,46),\
                        str2_8_, QRectF(21,97,176,170) };
        //m_items.at(8)->initMySquare(item_struct_8_2_page);
        m_items.at(8)->print_struct(item_struct_8_2_page);
        //////// m_items.at(0) equal m_items2.at(6)  ////////
        item_struct_0_2_page = MySquareStruct  { null,null,\
                null,null,null,QString("instigate_design3.svg"),null,\
                        QRectF(4,5,132,79), null, null, null, null };
        // create arrows
        QList<Arrow *> arrow_list2;
        m_ar2_list  = arrow_list2 ;
        //Arrow *ar2_0 = new Arrow(m_items.at(0),m_items.at(8));
        //m_ar2_list.append(ar2_0);
        //m_items.at(8)->add_arrow(ar2_0);
        //m_items.at(0)->add_arrow(ar2_0);
        ///////////////
        Arrow *ar2_1 = new Arrow(m_items.at(8),m_items2.at(5));
        m_ar2_list.append(ar2_1);
        m_items.at(8)->add_arrow(ar2_1);
        m_items2.at(5)->add_arrow(ar2_1);
        //////////////
        Arrow *ar2_2 = new Arrow(m_items.at(8),m_items2.at(4));
        m_ar2_list.append(ar2_2);
        m_items.at(8)->add_arrow(ar2_2);
        m_items2.at(4)->add_arrow(ar2_2);
        /////////////
        Arrow *ar2_3 = new Arrow(m_items.at(8),m_items2.at(3));
        m_ar2_list.append(ar2_3);
        m_items.at(8)->add_arrow(ar2_3);
        m_items2.at(3)->add_arrow(ar2_3);
        ////////////
        Arrow *ar2_4 = new Arrow(m_items.at(8),m_items2.at(2));
        m_ar2_list.append(ar2_4);
        m_items.at(8)->add_arrow(ar2_4);
        m_items2.at(2)->add_arrow(ar2_4);
        ////////////
        Arrow *ar2_5 = new Arrow(m_items.at(8),m_items2.at(1));
        m_ar2_list.append(ar2_5);
        m_items.at(8)->add_arrow(ar2_5);
        m_items2.at(1)->add_arrow(ar2_5);
        ////////////
        Arrow *ar2_6 = new Arrow(m_items.at(8),m_items2.at(0));
        m_ar2_list.append(ar2_6);
        m_items2.at(0)->add_arrow(ar2_6);
        m_items.at(8)->add_arrow(ar2_6);
        /////////// add second page m_items in m_scene /////////
        for (int i=0 ;i<7 ;++i)
        {
                m_scene->addItem(m_items2.at(i));
                m_items2.at(i)->setOpacity(0.000);
        }
        for( int i=0; i<m_ar2_list.count(); ++i )
        { 
                m_scene->addItem(m_ar2_list.at(i));
                m_ar2_list.at(i)->update_position();
                m_ar2_list.at(i)->setOpacity(0.0);
                //m_ar2_list.at(i)->setZValue(-1000);
                //m_ar2_list.at(i)->hide();
        }
}

void Dialog::show_first_page_arrows()
{
        qDebug() << "m_ar_list finished\n\n\n\n";
        qDebug() << "duration ====" << m_group_anim_2->currentTime();
        //if (m_group_anim_2->currentTime() == 1)
        {
                for( int i=0; i<m_ar_list.count(); ++i )
                { 
                        m_ar_list.at(i)->update_position();
                        m_ar_list.at(i)->show();
                        qDebug() << "m_ar_list finished\n\n\n\n";
                }
        }
}

void Dialog::show_second_page_arrows()
{
        qDebug() << "show_second_page_arrows appeared\n\n\n\n";
        qDebug() << "duration ====" << m_group_anim_2->currentTime();
        m_ar_list.at(7)->update_position();
        m_ar_list.at(7)->show();
        m_ar_list.at(7)->setOpacity(1.0);
        for( int i=0; i<m_ar2_list.count(); ++i )
        { 
            m_ar2_list.at(i)->update_position();
            m_ar2_list.at(i)->show();
            m_ar2_list.at(i)->setOpacity(1.0);
            qDebug() << "m_ar2_list showed";
        }
}

void Dialog::hide_first_page_arrows()
{
                for( int i=0; i<m_ar_list.count(); ++i )
                { 
                        m_ar_list.at(i)->update_position();
                        m_ar_list.at(i)->hide();
                }
}

void Dialog::hide_second_page_arrows()
{
                for( int i=0; i<m_ar2_list.count(); ++i )
                { 
                        m_ar2_list.at(i)->update_position();
                        m_ar2_list.at(i)->hide();
                }
}

Dialog::~Dialog()
{
        //delete ui;
}
