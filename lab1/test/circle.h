#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle : public Figure
{
private:
    int _radius;
public:
    Circle(int xCenter, int yCenter, int radius);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QString GetArea() const;
    int GetRadius() const;
    void SetRadius(int radius);
    QString GetPerimeter() const;
};

#endif // CIRCLE_H
