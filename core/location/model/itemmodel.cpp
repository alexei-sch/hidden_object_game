#include "itemmodel.h"

namespace Location
{
namespace Model
{
using namespace Common;

Item::Item(const QString& name, const QString& clipName, const ID& id, const PointF& position, 
		   const QImage& image, const QImage& imageForSearchPanel)
	: m_name(name)
	, m_clipName(clipName)
	, m_id(id)
	, m_position(position)
	, m_image(image)
	, m_imageForSearchPanel(imageForSearchPanel)
{
	Q_ASSERT(!m_name.isEmpty());
	Q_ASSERT(!m_clipName.isEmpty());
	Q_ASSERT(m_id >= 0);
	Q_ASSERT(!m_position.isNull());
	Q_ASSERT(!m_image.isNull());
	Q_ASSERT(!m_imageForSearchPanel.isNull());
}

const QString& Item::name() const 
{
	return m_name;
}

const QString& Item::clipName() const 
{
	return m_clipName;
}

const ID& Item::id() const 
{
	return m_id;
}

const PointF& Item::position() const 
{
	return m_position;
}

const QImage& Item::image() const 
{
	return m_image;
}

const QImage& Item::imageForSearchPanel() const 
{
	return m_imageForSearchPanel;
}

bool Item::hitTest(const Common::PointF& point) const 
{
	const QRectF rect(position(), image().size());
	if (!rect.contains(point))
	{
		return false;
	}

	return transparentPixel(point);
}

bool Item::transparentPixel(const Common::PointF& point) const
{
	const QPointF translatedPoint = point - position();
	const QRgb color = m_image.pixel(translatedPoint.toPoint());

	return qAlpha(color) != 0;
}

}
}