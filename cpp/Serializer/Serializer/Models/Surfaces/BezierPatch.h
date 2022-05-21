#pragma once

#include <Models/SceneObject.h>
#include <Models/PointRef.h>

namespace MG1
{
	class BezierPatch : public SceneObject
	{
	public:
		explicit BezierPatch() = default;

		std::vector<PointRef> controlPoints;
	};
}
