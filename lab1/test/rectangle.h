#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle(int width, int height, int xCenter, int yCenter);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString GetArea() const;
    QString GetPerimeter() const;
    int GetWidth() const;
    int GetHeight() const;
    void SetHeight(int height);
    void SetWidth(int width);

};

#endif // RECTANGLE_H
