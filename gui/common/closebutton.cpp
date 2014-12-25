#include "closebutton.h"
#include "resources/resourceprovider.h"

namespace Gui
{
using namespace Resources;

CloseButton::CloseButton(QWidget* parent)
	: QWidget(parent)
	, m_image(ResourceProvider::closeButton())
{
	resize(m_image.size());
	setCursor(Qt::PointingHandCursor);
}

void CloseButton::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		Q_EMIT clicked();
	}	

}

void CloseButton::paintEvent(QPaintEvent*)
{
	QPainter painter;
	painter.begin(this);

	painter.drawImage(0, 0, m_image);

	painter.end();
}

}