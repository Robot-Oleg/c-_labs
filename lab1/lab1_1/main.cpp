#include <QApplication>
#include <QGraphicsScene>
#include "Cart.h"
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // create an item to put into the scene
    Rect *cart = new Rect();
    Cargo *cargo = new Cargo();



    //add the item to the scene
    scene->addItem(cart);
    scene->addItem(cargo);

    //make item focusable
    cart->setFlag(QGraphicsItem::ItemIsFocusable);
    cart->setFocus();

    //add a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    cart->setPos(view->width()/2,view->height()/2);
//    cargo->setPos(cart->x()+50,cart->y());

    return a.exec();
}
