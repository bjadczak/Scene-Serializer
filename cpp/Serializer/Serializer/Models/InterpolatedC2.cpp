#include "pch.h"
#include "InterpolatedC2.h"

#include <nlohmann/json.hpp>

namespace MG1
{
	void to_json(nlohmann::json& j, const InterpolatedC2& p)
	{
		auto points = nlohmann::json::array();

		for (auto& point : p.controlPoints)
		{
			nlohmann::json pointRef = { { "id", point.GetId() } };

			points.push_back(pointRef);
		}

		j = {
			{ "objectType", "bezierC0" },
			{ "id", p.m_id },
			{ "name", p.name },
			{ "controlPoints", points }
		};
	}

	void from_json(const nlohmann::json& j, InterpolatedC2& p)
	{
		if (j.contains("name"))
		{
			p.name = j["name"];
		}

		p.controlPoints.clear();

		for (auto& pointRef : j["controlPoints"])
		{
			auto id = pointRef["id"].get<uint32_t>();
			auto ref = PointRef(id);
			p.controlPoints.push_back(ref);
		}

		p.SetId(j["id"].get<uint32_t>());
	}
}
