#pragma once
#include <cmath>

float distance(float x1, float z1, float x2, float z2) {
	return std::abs(x1 - x2) + std::abs(z1 - z2);
}