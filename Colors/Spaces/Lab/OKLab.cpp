#include "OKLab.h"

#include <iostream>

namespace ColorSpaces {
	sRGB OKLab::assRGB() const {
		//if (L() <= 0.0001f) return sRGB{1,1,1};

		float l = L() + (a() * +0.3963377774f) + (b() * +0.2158037573f);
		float m = L() + (a() * -0.1055613458f) + (b() * -0.0638541728f);
		float s = L() + (a() * -0.0894841775f) + (b() * -1.2914855480f);

		l = std::max(l, 0.0f), m = std::max(m, 0.0f), s = std::max(s, 0.0f);
		l = powf(l, 3), m = powf(m, 3), s = powf(s, 3);

		//float r = l * +4.0767416621 + m * -3.3077115913 + s * +0.2309699292;
		//float g = l * -1.2684380046 + m * +2.6097574011 + s * -0.3413193965;
		//float b = l * -0.0041960863 + m * -0.7034186147 + s * +1.7076147010;

		float r = l * +3.9324466960f + m * -3.1906361981f + s * +0.2227948220f;
		float g = l * -1.2235420472f + m * +2.5733305457f + s * -0.3387757924f;
		float b = l * -0.0040475674f + m * -0.7035391171f + s * +1.7076231153f;


		//r = std::clamp(r, 0.0f, 1.0f), g = std::clamp(g, 0.0f, 1.0f), b = std::clamp(b, 0.0f, 1.0f);

		const auto tmp = [](float x) {
			return x < 0 || 1.0f < x;
		};
		if (tmp(r) || tmp(g) || tmp(b)) {
			r=0,g=0,b=0;
		};

		return sRGB{r, g, b, true};
	}

}
