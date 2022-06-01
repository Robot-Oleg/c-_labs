#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

#define PI 3.14

class Figure : public QGraphicsItem
{

protected:
    int _perimetr,
        _area,
        _width,
        _height,
        _xCenter,
        _yCenter;

public:
    Figure();
    void SetPerimetr(int perimetr);
    QString GetPerimeter() const;
    void SetArea(int area);
    QString GetArea() const;
    int GetXCenter() const;
    int GetYCenter() const;
    void SetXCenter(int xCenter);
    void SetYCenter(int yCenter);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // FIGURE_H
