#include "hexagon.h"


Hexagon::Hexagon(int xCenter, int yCenter, int radius)
{
   _xCenter = xCenter;
   _yCenter = yCenter;
   _radius = radius;
}
void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QPoint points[6] = {
        QPoint((int) (_xCenter + _radius * cos(0 * PI / 180)),
            (int) (_yCenter + _radius * sin(0 * PI / 180))
        ),
        QPoint((int) (_xCenter + _radius * cos(60 * PI / 180)),
            (int) (_yCenter + _radius * sin(60 * PI / 180))
        ),
        QPoint((int) (_xCenter + _radius * cos(120 * PI / 180)),
            (int) (_yCenter + _radius * sin(120 * PI / 180))
        ),
        QPoint((int) (_xCenter + _radius * cos(180 * PI / 180)),
            (int) (_yCenter + _radius * sin(180 * PI / 180))
        ),
        QPoint((int) (_xCenter + _radius * cos(240 * PI / 180)),
            (int) (_yCenter + _radius * sin(240 * PI / 180))
        ),
        QPoint((int) (_xCenter + _radius * cos(300 * PI / 180)),
            (int) (_yCenter + _radius * sin(300 * PI / 180))
        ),
    };
    painter->setPen(Qt::black);
    painter->setBrush(Qt::blue);

    painter->drawPolygon(points, 6);
}
QRectF Hexagon::boundingRect() const
{
    return QRectF(_xCenter - _radius, _yCenter - _radius, _radius * 2, _radius * 2);
}
QString Hexagon::GetArea() const
{
    return QString::number(3 * sqrt(3) / 2 * pow(_radius, 2));
}
int Hexagon::GetRadius() const
{
    return _radius;
}
void Hexagon::SetRadius(int radius){
    _radius = radius;
}
QString Hexagon::GetPerimeter() const
{
    return QString::number(abs(6 * _radius));
}
