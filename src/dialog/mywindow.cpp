#include "mywindow.h"

#include "button.h"
#include <QPainter>
#include <QtDebug>


static const qreal TitleBarHeight = 35;
static const qreal ContentMargin = 15;

MyWindow::MyWindow(const QString &title, const QSizeF &size)
    :title(title),size(size)
{
    setFlags(ItemIsMovable);
}

MyWindow::~MyWindow()
{

}


QRectF MyWindow::boundingRect() const{
    return QRectF(QPointF(), size);
}

void MyWindow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rectf = boundingRect();
    QColor fillColor(Qt::black);
    fillColor.setAlphaF(0.8);
    painter->fillRect(rectf,fillColor);

    QColor penColor(Qt::white);
    penColor.setAlphaF(0.8);
    QPen pen(penColor);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawRect(rectf);


    painter->drawLine(0,TitleBarHeight,size.width(),TitleBarHeight);
    painter->drawText(QRectF(0,0,size.width(), TitleBarHeight),Qt::AlignCenter,title);
}


void MyWindow::setContent(const QString &content)
{
    QGraphicsTextItem *content_item = new QGraphicsTextItem(this);
    content_item->moveBy(ContentMargin,ContentMargin + TitleBarHeight);
    //content_item->setPlainText(content);
    content_item->setHtml(content);
    content_item->setDefaultTextColor(Qt::white);
    content_item->setTextWidth(this->size.width() - ContentMargin * 2);
}

void MyWindow::moveToCenter()
{
    moveBy( - size.width() / 2,-size.height() / 2);
}



void MyWindow::addCloseButton()
{
    Button *closeButton = new Button(tr("OK"));

    const qreal scale = 0.6;
    closeButton->setScale(scale);

    QSizeF closeButtonSize = closeButton->boundingRect().size();
    closeButtonSize *= scale;

    closeButton->setParentItem(this);
    closeButton->setPos(size.width() - closeButtonSize.width()  - ContentMargin,
                        size.height() - closeButtonSize.height() - ContentMargin);
    connect(closeButton, SIGNAL(clicked()), this, SLOT(disappear()));
}


void MyWindow::disappear()
{
    hide();
    qDebug()<<"disappear";
    deleteLater();
}
