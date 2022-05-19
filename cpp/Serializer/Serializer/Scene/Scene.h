#pragma once

#include <vector>

#include <Models/BezierC0.h>
#include <Models/BezierC2.h>
#include <Models/InterpolatedC2.h>
#include <Models/Point.h>
#include <Models/Torus.h>

namespace MG1
{
	class Scene
	{
	public:
		explicit Scene() = default;

		std::vector<Point> points;
		std::vector<Torus> tori;

		std::vector<BezierC0> bezierC0;
		std::vector<BezierC2> bezierC2;
		std::vector<InterpolatedC2> interpolatedC2;

		friend class SceneSerializer;
	};
}
