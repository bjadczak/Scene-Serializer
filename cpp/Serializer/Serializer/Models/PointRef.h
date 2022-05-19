#pragma once

#include "Point.h"

#include <memory>

namespace MG1
{
	class PointRef
	{
	public:
		PointRef(uint32_t id);

		inline uint32_t GetId() const { return m_id; }
		Point* GetPoint() const;

	protected:
		uint32_t m_id;
	};
}