#include "intersections.h"

namespace Location
{
namespace Template
{

void Intersections::add(const Intersection& intersection)
{
	m_intersections << intersection;
}

bool Intersections::contains(const Intersection& intersection) const
{
	return m_intersections.contains(intersection);
}

}
}