#pragma once
#include "intersection.h"

namespace Location
{
namespace Template
{

class Intersections
{
public:
	void add(const Intersection& intersection);
	bool contains(const Intersection& intersection) const;

private:
	QList<Intersection> m_intersections;
};

}
}