#include <vector>
#include <cmath>
#include <iostream>

#include "Color_RGB.h"

namespace ColorSpace {
	RGB RGB::averageOf(const std::vector<RGB> &cols, const bool s) {
		float r=0,g=0,b=0;

		for (auto col: cols) {
			col.setStandard(s);

			r += col.r, g += col.g, b += col.b;
		}

		return {
			r/cols.size(),
			g/cols.size(),
			b/cols.size(),
			s
		};
	}
	RGB RGB::lerp(RGB& a, RGB& b, float t, bool s) {
		if (s) {
			a.setStandard(true);
			b.setStandard(true);
		} else {
			a.setStandard(false);
			b.setStandard(false);
		}

		return {
			std::lerp(a.r, b.r, t),
			std::lerp(a.g, b.g, t),
			std::lerp(a.b, b.b, t),
			s
		};
	}

	[[nodiscard]] RGB RGB::asStandard() const {
		if (s) {
			std::cerr << "_asStandard() but value already standard";
			return {r, g, b, true};
		} // WARNING if already standard

		auto convert = [](float c) {
			if (c <= 0.0031308f)
				return 12.92f * c;
			else
				return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
		};
		return {convert(r), convert(g), convert(b), true};
	}

	[[nodiscard]] RGB RGB::asLinear() const {
		if (!s) {
			std::cerr << "_asLinear() but value already linear";
			return {r, g, b, false};
		} // WARNING if already linear

		auto convert = [](float c) {
			if (c <= 0.04045f)
				return c / 12.92f;
			else
				return std::pow((c + 0.055f) / 1.055f, 2.4f);
		};
		return {convert(r), convert(g), convert(b), false};
	}
}
