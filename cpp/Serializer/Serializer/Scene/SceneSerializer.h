#pragma once

#include <filesystem>

#include "Scene.h"

namespace MG1
{
	class SceneSerializer
	{
	public:
		Scene LoadScene(std::filesystem::path path);
		void SaveScene(const Scene& scene, std::filesystem::path path);
	};
}
