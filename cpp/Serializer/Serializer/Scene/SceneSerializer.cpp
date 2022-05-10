#include "pch.h"
#include "SceneSerializer.h"

#include <valijson/adapters/nlohmann_json_adapter.hpp>
#include <valijson/utils/nlohmann_json_utils.hpp>
#include <valijson/schema.hpp>
#include <valijson/schema_parser.hpp>
#include <valijson/validator.hpp>

#include <Resources/Schema.h>

namespace MG1
{
	Scene SceneSerializer::LoadScene(std::filesystem::path path)
	{
		auto document = LoadAndValidate(path);

		Scene resultScene;

		for (auto& point : document["points"])
		{
			resultScene.points.push_back(point);
		}

		for (auto& element : document["geometry"])
		{
			auto elementType = element["objectType"].get<std::string>();
			
			// TODO: could be done smarter than this massive conditional block
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
		// TODO: write the damn method
	}
	
	nlohmann::json SceneSerializer::LoadAndValidate(std::filesystem::path path)
	{
		nlohmann::json document;
		
		if (!valijson::utils::loadDocument(path.string(), document))
		{
			throw SerializerException("Loading the json file failed");
		}

		// TODO: think about how the schema file is included - pasting it with every update seems unnecessary
		nlohmann::json schemaJson = nlohmann::json::parse(g_schema);

		valijson::Schema schema;
		valijson::SchemaParser parser;
		valijson::adapters::NlohmannJsonAdapter schemaAdapter(schemaJson);
		parser.populateSchema(schemaAdapter, schema);

		valijson::Validator validator;
		valijson::adapters::NlohmannJsonAdapter sceneAdapter(document);
		valijson::ValidationResults validationResults;
		if (!validator.validate(schema, sceneAdapter, &validationResults))
		{
			throw SerializerException("Scene file is corrupted.");
		}

		return document;
	}
}
