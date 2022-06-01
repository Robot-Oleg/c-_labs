#include "triangle.h"

Triangle::Triangle(int xCenter, int yCenter, int radius)
{
    _xCenter = xCenter;
    _yCenter = yCenter;
    _radius = radius;
}
void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QPoint points[3] = {
        QPoint((int) (_xCenter + _radius * cos(30 * PI / 180)),
            (int) (_yCenter + _radius * sin(30 * PI / 180))
        ),
        QPoint((int) (_xCenter + _radius * cos(150 * PI / 180)),
            (int) (_yCenter + _radius * sin(150 * PI / 180))
        ),
        QPoint((int) (_xCenter + _radius * cos(270 * PI / 180)),
            (int) (_yCenter + _radius * sin(270 * PI / 180))
        ),
    };
    painter->setPen(Qt::black);
    painter->setBrush(Qt::red);
    painter->drawPolygon(points, 3);

}

QRectF Triangle::boundingRect() const
{
    return QRectF(_xCenter - _radius, _yCenter - _radius, _radius * 2, _radius * 2);
}

QString Triangle::GetArea() const
{
    return QString::number(3 * sqrt(3) * pow(_radius, 2) / 4);
}
int Triangle::GetRadius() const
{
    return _radius;
}
void Triangle::SetRadius(int radius){
    _radius = radius;
}
QString Triangle::GetPerimeter() const
{
    return QString::number(abs(3 * sqrt(3) * _radius));
}
