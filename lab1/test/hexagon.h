#ifndef HEXAGON_H
#define HEXAGON_H
#include "figure.h"

class Hexagon : public Figure
{
private:
    int _radius;
public:
    Hexagon(int xCenter, int yCenter, int radius);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QString GetArea() const;
    int GetRadius() const;
    void SetRadius(int radius);
    QString GetPerimeter() const;
};

#endif // HEXAGON_H
