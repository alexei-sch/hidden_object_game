#pragma once
#include "core/location/locationid.h"

namespace Gui
{
using Location::LocationId;

class StickerButton : public QWidget
{
	Q_OBJECT

public:
	StickerButton(const Location::LocationId& id, QWidget* parent);

public:
	Q_SIGNAL void clicked(const LocationId& id);

protected:
	void mousePressEvent(QMouseEvent* event) override;

private:
	const LocationId m_id;
};

}