#include "button.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>



static QRectF buttonRect(0,0,189,46);
static QColor ReverseColor(const QColor &color){
    int r = 0xFF - color.red();
    int g = 0xFF - color.green();
    int b = 0xFF - color.blue();
    return QColor::fromRgb(r, g, b);
}

Button::Button(const QString &label, qreal scale)
    :label(label),sizef(buttonRect.size() * scale)
{
    setFlags(ItemIsFocusable);
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::LeftButton);
}

Button::~Button()
{

}



QRectF Button::boundingRect() const
{
    return QRectF(QPointF(),sizef);
}

void Button::hoverEnterEvent(QGraphicsSceneMouseEvent *event)
{
    setFocus(Qt::MouseFocusReason);
}


void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     event->accept();
}



void Button::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}


void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rectf = boundingRect();
    QColor textColor,edgeColor,boxColor;
    textColor = edgeColor = Qt::white;
    boxColor = Qt::black;

    if(hasFocus())
    {
        textColor = ReverseColor(textColor);;
        boxColor = ReverseColor(boxColor);
    }

    boxColor.setAlphaF(0.8);

    painter->fillRect(rectf,boxColor);


    QPen pen(edgeColor);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawRect(rectf);

    pen.setColor(textColor);
    painter->setPen(pen);
    //painter->setFont(this->font());
    painter->drawText(rectf,Qt::AlignCenter,label);



}
