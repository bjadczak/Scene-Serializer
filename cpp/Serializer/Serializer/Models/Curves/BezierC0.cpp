#include "pch.h"
#include "BezierC0.h"

#include <iterator>
#include <nlohmann/json.hpp>

namespace MG1
{
	void to_json(nlohmann::json& j, const BezierC0& p)
	{
		auto points = nlohmann::json::array();
		
		std::transform(
			p.controlPoints.begin(), p.controlPoints.end(),
			std::back_inserter(points),
			[](const PointRef& point) { return nlohmann::json{ { "id", point.GetId() } }; }
		);

		j = {
			{ "objectType", "bezierC0" },
			{ "id", p.m_id },
			{ "name", p.name },
			{ "controlPoints", points }
		};
	}
	
	void from_json(const nlohmann::json& j, BezierC0& p)
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