#ifndef CART_H
#define CART_H

#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>
#include <QKeyEvent>
#include "Cargo.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class Rect : public QGraphicsRectItem{
public:
    Rect();
    void keyPressEvent(QKeyEvent *event);
};

#endif // CART_H
