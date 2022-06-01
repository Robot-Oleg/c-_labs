#include "rectangle.h"

Rectangle::Rectangle(int width, int height, int xCenter, int yCenter)
{
    _width = width;
    _height = height;
    _xCenter = xCenter;
    _yCenter = yCenter;

}

QRectF Rectangle::boundingRect() const
{
    return QRectF(_xCenter - _width/2, _yCenter - _height/2, _width, _height);
}


int Rectangle::GetWidth() const
{
    return _width;
}

int Rectangle::GetHeight() const
{
    return _height;
}

void Rectangle::SetHeight(int height){
    _height = height;
}

void Rectangle::SetWidth(int width){
    _width = width;
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(_xCenter - _width/2, _yCenter - _height/2, _width, _height);
}

QString Rectangle::GetArea() const
{
   return QString::number(_width*_height);
}


QString Rectangle::GetPerimeter() const
{
    return QString::number((_width+_height)*2);
}
