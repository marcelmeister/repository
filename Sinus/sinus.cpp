#include <QPushButton> 
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <stdio.h>

#include "sinus.h"
#include "canvas.h"

Sinus::Sinus(QWidget *parent)
	: QWidget(parent)
{
	viewport = new Canvas();
	btnDrawSin = new QPushButton("&Draw Sinus");

	ledMinX = new QLineEdit("0");
	lblMinX = new QLabel("World MinX");
	lblMinX->setBuddy(ledMinX);

	ledMinY = new QLineEdit("0");
	lblMinY = new QLabel("World MinY");
	lblMinY->setBuddy(ledMinY);

	ledMaxX = new QLineEdit("1");
	lblMaxX = new QLabel("World MaxX");
	lblMaxX->setBuddy(ledMaxX);

	ledMaxY = new QLineEdit("1");
	lblMaxY = new QLabel("World MaxY");
	lblMaxY->setBuddy(ledMaxY);

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->setColumnStretch(0, 3);

	mainLayout->addWidget(viewport, 0, 0, 1, 3);
	mainLayout->addWidget(lblMinX, 2, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMinX, 2, 2);
	mainLayout->addWidget(lblMinY, 3, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMinY, 3, 2);
	mainLayout->addWidget(lblMaxX, 4, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMaxX, 4, 2);
	mainLayout->addWidget(lblMaxY, 5, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMaxY, 5, 2);
	mainLayout->addWidget(btnDrawSin, 7, 1, 1, 2, Qt::AlignRight);

	setLayout(mainLayout);
	
	connect(btnDrawSin, SIGNAL(clicked()), this, SLOT(drawBtnPressed()));
}

Sinus::~Sinus()
{
}

void Sinus::drawBtnPressed()
{
	QPointF min, max;

	min.setX(ledMinX->text().toFloat());
	min.setY(ledMinY->text().toFloat());

	max.setX(ledMaxX->text().toFloat());
	max.setY(ledMaxY->text().toFloat());

	viewport->setWorld(min, max);

	update();

	printf("Button wurde gedrueckt, Welt: %f, %f bis %f, %f!\n", 
		min.x(), min.y(), max.x(), max.y());
}
