#include "stickerbutton.h"

namespace Gui
{

StickerButton::StickerButton(const LocationId& id, QWidget* parent)
	: QWidget(parent)
	, m_id(id)
{
	resize(43, 43);
	setCursor(Qt::PointingHandCursor);
}

void StickerButton::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		Q_EMIT clicked(m_id);
	}	
}

}