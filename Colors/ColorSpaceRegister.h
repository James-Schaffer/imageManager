#ifndef IMGMANAGER_COLORSPACEREGISTER_H
#define IMGMANAGER_COLORSPACEREGISTER_H
#include <array>
#include <map>
#include <string>

#include "ColorSpace.h"
#include "RGB.h"
#include "XYZ/XYZ.h"


namespace ColorSpaces::Registry {
	// From -> {TO}
	const std::map<std::string, std::map<std::string, std::array<std::array<float, 3>, 3>>> COLORSPACE_CONVERSION_MATRICIES = {
		{ "LinearRGB", {
			{"XYZ", {{{0.4124, 0.3576, 0.1805}, {0.2126, 0.7152, 0.0722}, {0.0193, 0.1192, 0.9505} }}},
		}},
		{ "XYZ", {
			{"LinearRGB", {{{3.2406255, -1.5372080, -0.4986286}, {-0.9689307, 1.8757561, 0.0415175}, {0.0557101, -0.2040211, 1.0569959} }}},
		}},
	};
}

#endif //IMGMANAGER_COLORSPACEREGISTER_H