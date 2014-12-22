#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QGraphicsObject>

class MyWindow : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit MyWindow(const QString &title, const QSizeF &size);
    ~MyWindow();
    virtual QRectF boundingRect() const;

    void setContent(const QString &content);
    void moveToCenter();
    void addCloseButton();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QString title;
    QSizeF size;
private slots:
    void disappear();
};

#endif // MYWINDOW_H
