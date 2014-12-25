#pragma once

namespace Resources
{

class ILocationResourceProvider
{
public:
	virtual ~ILocationResourceProvider() {};

	virtual QByteArray descriptionXML() const = 0;
	virtual QImage mainImage() const = 0;
	virtual QImage searchPanelImage() const = 0;
	virtual QImage backgroundImage() const = 0;

};

}