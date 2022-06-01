#ifndef CARGO_H
#define CARGO_H

#include <QGraphicsItemGroup>
#include "Cart.h"


class Cargo : public QGraphicsRectItem
{
public:
    Cargo();
    Cargo(QPointF initPos, QGraphicsItem* parent);
};

#endif // CARGO_H
