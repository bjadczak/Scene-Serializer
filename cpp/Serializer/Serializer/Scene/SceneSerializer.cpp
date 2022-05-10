#include "pch.h"
#include "SceneSerializer.h"

#include <valijson/adapters/nlohmann_json_adapter.hpp>
#include <valijson/utils/nlohmann_json_utils.hpp>
#include <valijson/schema.hpp>
#include <valijson/schema_parser.hpp>
#include <valijson/validator.hpp>

namespace MG1
{
	Scene SceneSerializer::LoadScene(std::filesystem::path path)
	{
		// load the json file
		nlohmann::json document;
		if (!valijson::utils::loadDocument(path.string(), document))
		{
			throw std::exception("Loading the json file failed");
		}

		// validate against schema
		// parse
		Scene resultScene;

		for (auto& point : document["points"])
		{
			//Point p = point;

			resultScene.points.push_back(point);
		}

		for (auto& element : document["geometry"])
		{
			auto elementType = element["objectType"].get<std::string>();
			
			if (elementType == "torus")
			{
				Torus t = element;
				resultScene.tori.push_back(t);
			}
			else if (elementType == "bezierC0")
			{
				BezierC0 b = element;
				resultScene.bezierC0.push_back(b);
			}
			else if (elementType == "bezierC2")
			{
				BezierC2 b = element;
				resultScene.bezierC2.push_back(b);
			}
			else if (elementType == "interpolatedC2")
			{
				InterpolatedC2 b = element;
				resultScene.interpolatedC2.push_back(b);
			}
		}

		return resultScene;
	}
	
	void SceneSerializer::SaveScene(const Scene& scene, std::filesystem::path path)
	{
	}
}
