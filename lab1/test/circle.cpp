#include "circle.h"

Circle::Circle(int xCenter, int yCenter, int radius)
{
    _xCenter = xCenter;
    _yCenter = yCenter;
    _radius = radius;
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::white);
    painter->drawEllipse(_xCenter - _radius, _yCenter - _radius, _radius * 2, _radius * 2);
}

QRectF Circle::boundingRect() const
{
    return QRectF(_xCenter - _radius, _yCenter - _radius, _radius * 2, _radius * 2);
}

QString Circle::GetArea() const
{
    return QString::number(PI * pow(_radius, 2));
}

int Circle::GetRadius() const
{
    return _radius;
}

void Circle::SetRadius(int radius){
    _radius = radius;
}
QString Circle::GetPerimeter() const
{
    return QString::number(abs(2*PI*_radius));
}
