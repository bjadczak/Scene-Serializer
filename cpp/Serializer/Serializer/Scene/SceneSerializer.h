#pragma once

#include <filesystem>
#include <exception>

#include "Scene.h"

namespace MG1
{
	struct SerializerException : public std::exception 
	{
		SerializerException(const char* message) : std::exception(message) { }
	};

	class SceneSerializer
	{
	public:
		Scene LoadScene(std::filesystem::path path);
		void SaveScene(const Scene& scene, std::filesystem::path path);

	private:
		nlohmann::json LoadAndValidate(std::filesystem::path);
	};
}
