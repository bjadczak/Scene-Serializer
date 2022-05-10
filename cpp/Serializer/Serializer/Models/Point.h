#pragma once

#include <map>
#include <memory>

#include "SceneObject.h"

#include <Serializable.h>
#include <Utils/Float3.h>

namespace MG1
{
	class Point : public SceneObject
	{
	public:
		explicit Point();
		Point(const Point& other) = default;

		virtual bool SetId(uint32_t id) override;

		Float3 position;

		friend void to_json(nlohmann::json& j, const Point& p);
		friend void from_json(const nlohmann::json& j, Point& p);

		friend class PointRef;

	protected:
		static std::map<uint32_t, std::shared_ptr<Point>> s_pointMap;
	};
}
