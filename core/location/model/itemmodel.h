#pragma once
#include "iitemmodel.h"

namespace Location
{
namespace Model
{

class Item : public IItem
{
public:
	Item(const QString& name, const QString& clipName, const Common::ID& id, const Common::PointF& position, 
		 const QImage& image, const QImage& imageForSearchPanel);

	const QString& name() const override;
	const QString& clipName() const override;
	const Common::ID& id() const override;
	const Common::PointF& position() const override;
	const QImage& image() const override;
	const QImage& imageForSearchPanel() const override;

	bool hitTest(const Common::PointF& point) const override;

private:
	bool transparentPixel(const Common::PointF& point) const;

private:
	const QString m_name;
	const QString m_clipName;
	const Common::ID m_id;
	const Common::PointF m_position;
	const QImage m_image;
	const QImage m_imageForSearchPanel;
};

}
}