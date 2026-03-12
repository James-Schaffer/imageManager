#include "RGB_Base.h"
#include "sRGB.h"

#include <cmath>
#include <iostream>
#include <memory>

namespace ColorSpaces {
	std::array<float, 3> sRGB::asLinear() const {
		if (isLinear) {
			return {r(),g(),b()};
		}

		const auto convert = [](float c) {
			if (c <= 0.04045f)
				return c / 12.92f;
			else
				return std::pow((c + 0.055f) / 1.055f, 2.4f);
		};

		return {convert(r()), convert(g()), convert(b())};
	}

	std::array<float, 3> sRGB::asStandard() const {
		if (!isLinear) {
			//std::cout << "asStandard: already standard, returning " << r() << ", " << g() << ", " << b() << std::endl;
			return {r(),g(),b()};
		}
		const auto convert = [](float c) {
			if (c <= 0.0031308f)
				return c * 12.92f;
			else
				return 1.055f * std::pow(c, 1.0f/2.4f) - 0.055f;
		};

		return {convert(r()), convert(g()), convert(b())};
	}
}
