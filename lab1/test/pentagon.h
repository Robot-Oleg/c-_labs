#ifndef PENTAGON_H
#define PENTAGON_H
#include "figure.h"

class Pentagon : public Figure
{
private:
    int _radius;
public:
    Pentagon(int xCenter, int yCenter, int radius);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QString GetArea() const;
    int GetRadius() const;
    void SetRadius(int radius);
    QString GetPerimeter() const;

};

#endif // PENTAGON_H
