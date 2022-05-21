#pragma once

#include <filesystem>
#include <exception>

#include "Scene.h"

namespace MG1
{
    //std:exception nie powinno miec konstruktora z const char* (rozszerzenie MSVC)
	struct SerializerException : public std::runtime_error
	{
		SerializerException(const char* message) : std::runtime_error(message) { }
	};

	class SceneSerializer
	{
	public:
		Scene& LoadScene(std::filesystem::path path);
		void SaveScene(std::filesystem::path path);

	private:
		nlohmann::json LoadAndValidate(std::filesystem::path);
	};
}
