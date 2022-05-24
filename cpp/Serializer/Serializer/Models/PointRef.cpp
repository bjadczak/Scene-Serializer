#include "pch.h"
#include "PointRef.h"

#include <Scene/SerializerException.h>

namespace MG1
{
	PointRef::PointRef(uint32_t id)
		: m_id(id)
	{
	}
	
	Point* PointRef::GetPoint() const
	{
		auto result = Point::s_pointMap.find(m_id);

		if (result == Point::s_pointMap.end())
		{
			return nullptr;
		}

		return result->second;
	}
}
