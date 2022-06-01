#include "pentagon.h"

Pentagon::Pentagon(int xCenter, int yCenter, int radius)
{
    _xCenter = xCenter;
    _yCenter = yCenter;
    _radius = radius;
}
void Pentagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QPoint points[5] = {
        QPoint((int) (_xCenter + _radius * cos(54 * PI / 180)),
            (int) (_yCenter + _radius * sin(54 * PI / 180))
        ),
        QPoint((int) (_xCenter + _radius * cos(126 * PI / 180)),
            (int) (_yCenter + _radius * sin(126 * PI / 180))
        ),
        QPoint((int) (_xCenter + _radius * cos(198 * PI / 180)),
            (int) (_yCenter + _radius * sin(198 * PI / 180))
        ),
        QPoint((int) (_xCenter + _radius * cos(270 * PI / 180)),
            (int) (_yCenter + _radius * sin(270 * PI / 180))
        ),
        QPoint((int) (_xCenter + _radius * cos(342 * PI / 180)),
            (int) (_yCenter + _radius * sin(342 * PI / 180))
        ),
    };
    painter->setPen(Qt::black);
    painter->setBrush(Qt::yellow);
    painter->drawPolygon(points, 5);
}
QRectF Pentagon::boundingRect() const
{
    return QRectF(_xCenter - _radius, _yCenter - _radius, _radius * 2, _radius * 2);
}
QString Pentagon::GetArea() const
{
    return QString::number(5 / 2 * pow(_radius, 2) * sin(2 * PI / 5));
}
int Pentagon::GetRadius() const
{
    return _radius;
}
void Pentagon::SetRadius(int radius){
    _radius = radius;
}
QString Pentagon::GetPerimeter() const
{
    return QString::number(abs(5 * sqrt((5 - sqrt(5)) / 2) * _radius));
}
