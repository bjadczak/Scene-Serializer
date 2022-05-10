#include "pch.h"
#include "PointRef.h"

namespace MG1
{
	PointRef::PointRef(uint32_t id)
		: m_id(id)
	{
		if (Point::s_pointMap.find(id) == Point::s_pointMap.end())
		{
			m_id = -1;
		}
	}
	
	std::shared_ptr<Point> PointRef::GetPoint() const
	{
		auto result = Point::s_pointMap.find(m_id);

		if (result == Point::s_pointMap.end())
		{
			return nullptr;
		}

		return result->second;
	}
}
