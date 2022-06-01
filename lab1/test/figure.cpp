#include "figure.h"

Figure::Figure(){
    this->setFlag(QGraphicsItem::ItemIsSelectable);
}

int Figure::GetXCenter() const
{
    return _xCenter;
}

int Figure::GetYCenter() const
{
    return _xCenter;
}

void Figure::SetXCenter(int xCenter){
    _xCenter = xCenter;
}

void Figure::SetYCenter(int yCenter){
    _yCenter = yCenter;
}


void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    if (event->button() == Qt::LeftButton) {
        setSelected(true);
    }
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
}
