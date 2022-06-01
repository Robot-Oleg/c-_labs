#include "Cart.h"
#include "Cargo.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QPainter>

Rect::Rect()
{
    //setPixmap(QPixmap(":/images/cargo.png"));
    int cart_heigth = 50;
    int cart_width = 100;
    int diameter = 30;
    setRect(0,0,100,50);
    QGraphicsEllipseItem *wheel1 = new QGraphicsEllipseItem(x(), y()+cart_heigth-diameter/2, diameter, diameter,this);
    QGraphicsEllipseItem *wheel2 = new QGraphicsEllipseItem(x()+cart_width-diameter, y()+cart_heigth-diameter/2, diameter, diameter, this);
//    wheel1->setParentItem(this);
//    wheel2->setParentItem(this);

//    wheel1->setPos(0,0);
//    wheel2->setPos(10,10);

}

void Rect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        setPos(x()-20,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+20,y());
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-20);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+20);
    }
    else if (event->key() == Qt::Key_E){
        foreach(QGraphicsItem* item, collidingItems()){
           item->setParentItem(this);
           item->setPos(item->mapFromParent(0,0));
        }
    }
    else if (event->key() == Qt::Key_R){
        foreach(QGraphicsItem* item, collidingItems()){
           item->setParentItem(0);
           item->setPos(item->mapFromParent(-10,-10));
        }
    }
}
