#include "locationresourceprovider.h"

namespace Resources
{

static QString convert(int locationId)
{
	if (locationId == 1)
	{
		return "Room_001_Livingroom_all";
	}
	else if(locationId == 2)
	{
		return "Room_003_Kitchen_all";
	}

	Q_ASSERT(!"Unexpected location id");
	return "";
}

LocationResourceProvider::LocationResourceProvider(int locationId)
	: m_locationId(convert(locationId))
{
}

static bool exists(const QString& path)
{
	Q_ASSERT(!path.isEmpty());
	QFile file(path);
	return file.open(QIODevice::ReadOnly);
}

QByteArray LocationResourceProvider::descriptionXML() const 
{
	const QString xmlPath = path(m_locationId + ".xml");
	Q_ASSERT(exists(xmlPath));

	QFile xmlFile(xmlPath);
	xmlFile.open(QIODevice::ReadOnly);
	Q_ASSERT(xmlFile.isOpen());

	return xmlFile.readAll();
}

QImage LocationResourceProvider::mainImage() const 
{
	if (maskImageExists(m_locationId))
	{
		return applyMaskImage(m_locationId);
	}

	return image(m_locationId);
}

QImage LocationResourceProvider::searchPanelImage() const 
{
	return image(m_locationId + "_list");
}

QImage LocationResourceProvider::backgroundImage() const 
{
	const QRect backgroundImageRect = QRect(QPoint(0, 0), QSize(946, 800));

	return mainImage().copy(backgroundImageRect);
}

QImage LocationResourceProvider::image(const QString& name) const
{
	const QString imgPath = imagePath(name);
	Q_ASSERT(exists(imgPath));
	return QImage(imgPath);
}

QString LocationResourceProvider::imagePath(const QString& name) const
{
	const QString pngImgPath = path(name + ".png");
	const QString jpegImgPath = path(name + ".jpg");

	if (exists(pngImgPath))
	{
		return pngImgPath;
	}
	else if (exists(jpegImgPath))
	{
		return jpegImgPath;
	}

	return "";
}

bool LocationResourceProvider::maskImageExists(const QString& name) const
{
	const QString mask = maskImagePath(name);
	return !mask.isEmpty();
}

QString LocationResourceProvider::maskImagePath(const QString& name) const
{
	return imagePath(name + "_");
}

QImage LocationResourceProvider::applyMaskImage(const QString& name) const
{
	Q_ASSERT(maskImageExists(name));

	QImage source(imagePath(name));
	const QImage mask(maskImagePath(name));

	source.setAlphaChannel(mask);

	return source;
}

QString LocationResourceProvider::path(const QString& suffix) const
{
	return QString(":/data/%1/%2").arg(m_locationId).arg(suffix);
}

}