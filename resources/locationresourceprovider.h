#pragma once
#include "ilocationresourceprovider.h"

namespace Resources
{

class LocationResourceProvider : public ILocationResourceProvider
{
public:
	LocationResourceProvider(int locationId);

	QByteArray descriptionXML() const override;
	QImage mainImage() const override;
	QImage searchPanelImage() const override;
	QImage backgroundImage() const override;

private:
	QString path(const QString& suffix) const;
	QString imagePath(const QString& name) const;
	QString maskImagePath(const QString& name) const;
	QImage image(const QString& name) const;
	QImage applyMaskImage(const QString& name) const;
	bool maskImageExists(const QString& name) const;


private:
	const QString m_locationId;
};

}