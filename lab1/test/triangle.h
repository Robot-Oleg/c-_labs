#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"

class Triangle : public Figure
{
private:
    int _radius;
public:
    Triangle(int xCentre, int yCenter, int radius);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QString GetArea() const;
    int GetRadius() const;
    void SetRadius(int radius);
    QString GetPerimeter() const;
};

#endif // TRIANGLE_H
