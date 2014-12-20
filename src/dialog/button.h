#ifndef BUTTON_H
#define BUTTON_H


#include <QGraphicsObject>
#include <QFont>


class Button : public QGraphicsObject
{

    Q_OBJECT
public:
    Button(const QString &label, qreal scale = 1.0);
    ~Button();


    virtual QRectF boundingRect() const;
signals:
    void clicked();
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void hoverEnterEvent( QGraphicsSceneMouseEvent * event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QFont font;
    QString label;
    QSizeF sizef;
};

#endif // BUTTON_H
