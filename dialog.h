#ifndef DIALOG_H
#define DIALOG_H
#include<iostream>
#include<QDebug>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include<QTimer>
#include<QHBoxLayout>
#include<QGraphicsView>
#include<QPushButton>
#include <QDialog>
#include<QtCore>
#include<QtGui>
#include<QLineF>
#include <iterator>
#include <typeinfo>
#include <QAbstractAnimation>
#include"mysquare.h"
#include"arrow.h"
#include"mygraphicsview.h"
//#include"mygraphicsscene.h"

class Dialog : public QDialog
{
Q_OBJECT
public:
        explicit Dialog(QWidget *parent = 0);
        QPropertyAnimation* pos_animation(MySquare* ptr,
                        int duration,QPointF startValue,
                        QPointF endValue, QEasingCurve easing);
        QPropertyAnimation* opacity_animation(MySquare* ptr,
                        int duration,qreal startValue,
                        qreal endValue, QEasingCurve easing);
        QPropertyAnimation* size_animation(MySquare* ptr,
                        int duration,QSizeF startValue,
                        QSizeF endValue, QEasingCurve easing);
        void remove_child_items(MySquare* item);
        void setup_1_page_items();
        void setup_2_page_items();
        void create_1_page_animation();
        void create_2_page_animation();
        ~Dialog();
public slots:
        void show_first_page();
        void animate_and_show_1_page();
        void animate_and_show_2_page();
        void show_first_page_arrows();
        void show_second_page_arrows();
        void hide_first_page_arrows();
        void hide_second_page_arrows();
private:
        QGraphicsScene* m_scene;
        //MyGraphicsScene* m_scene;
        QList<MySquare* > m_items;
        QList<MySquare* > m_items2;
        QParallelAnimationGroup* m_group_anim_1;
        QParallelAnimationGroup* m_group_anim_2;
        QParallelAnimationGroup* m_group_anim_3;
        QParallelAnimationGroup* m_group_anim_4;
        MySquareStruct m_item_struct_0;
        MySquareStruct m_item_struct_8;
        MySquareStruct m_item_struct_0_2_page;
        MySquareStruct m_item_struct_8_2_page;
        QList<Arrow *> m_ar_list;
        QList<Arrow *> m_ar2_list;
};

#endif // DIALOG_H
