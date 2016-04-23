#include <QPainter>
#include <math.h>

#include "canvas.h"

Canvas::Canvas(QWidget *parent)
	: QFrame(parent),
	  wMin(0, 0), 
	  wMax(1, 1)
{
	initDone = false;
}

Canvas::~Canvas()
{
}

QSize Canvas::minimumSizeHint() const
{
	return QSize(200, 200);
}

QSize Canvas::sizeHint() const
{
	return QSize(640, 480);
}

void Canvas::setWorld(const QPointF &min, const QPointF &max)
{
	wMin.rx() = min.x();
	wMin.ry() = min.y();

	wMax.rx() = max.x();
	wMax.ry() = max.y();

	initDone = true;
}

void Canvas::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QPainterPath pp;
	QPoint dc;

	// white background with black border
	painter.fillRect(QRect(0, 0, width() - 1, height() - 1), Qt::white);
	painter.setPen(Qt::black);
	painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

	if (!initDone)
		return;
	
	// draw axis of abscissas 
	dc = WC_to_DC(QPointF(wMin.x(), 0));
	pp.moveTo(dc);

	dc = WC_to_DC(QPointF(wMax.x(), 0));
	pp.lineTo(dc);

	dc = WC_to_DC(QPointF(0, wMin.y()));
	pp.moveTo(dc);

	dc = WC_to_DC(QPointF(0, wMax.y()));
	pp.lineTo(dc);

	painter.setPen(Qt::blue);
	painter.drawPath(pp);

	// clear old path
	pp = QPainterPath();

	// now draw sine function
	const int N = width() / 8;

	float dx = (wMax.x() - wMin.x()) / N;
	float x = wMin.x(), y = sin(x);

	dc = WC_to_DC(QPointF(x, y));
	pp.moveTo(dc);

	for (int i = 0; i <= N; i++) {
		x += dx;
		y = sin(x);

		dc = WC_to_DC(QPointF(x, y));
		pp.lineTo(dc);
	}

	painter.setPen(Qt::red);
	painter.drawPath(pp);
}

QPoint Canvas::WC_to_DC(const QPointF &wc)
{
	float wx0 = wMin.x(), wx1 = wMax.x();
	float wy0 = wMin.y(), wy1 = wMax.y();

	int dx0 = 1, dx1 = width() - 2;
	int dy0 = height() - 2, dy1 = 1;

	int x = (wc.x() - wx0) / (wx1 - wx0) * (dx1 - dx0) + dx0;
	int y = (wc.y() - wy0) / (wy1 - wy0) * (dy1 - dy0) + dy0;

	return QPoint(x, y);
}

QPointF Canvas::DC_to_WC(const QPoint &dc)
{
	// TODO
	return QPointF(0, 0);
}
