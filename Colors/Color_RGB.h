#ifndef IMGMANAGER_COLORSPACE_RGB_H
#define IMGMANAGER_COLORSPACE_RGB_H
#include <vector>

#include "ColorSpace.h"

namespace ColorSpace {
	class RGB : public ColorSpace {
	private:
		bool s;
	public:
		float r,g,b;
		RGB(float _r, float _g, float _b, bool _s=true) : r(_r), g(_g), b(_b), s(_s) {}

		[[nodiscard]] bool getStandard() const {
			return s;
		}
		void setStandard(const bool _s) {
			if (_s) {
				fromRGB(asStandard());
			} else {
				fromRGB(asLinear());
			}
			s = _s;
		}
		[[nodiscard]] RGB asStandard() const;
		[[nodiscard]] RGB asLinear() const;


		[[nodiscard]] std::string name() const override {return (s) ? "sRGB" : "LinearRGB";}

		[[nodiscard]] RGB toRGB() const override {
			return asStandard();
		}
		void fromRGB(const RGB rgb) override {
			r = (rgb.r);
			g = (rgb.g);
			b = (rgb.b);
			s = false;
		}

		[[nodiscard]] static RGB averageOf(const std::vector<RGB> &cols, bool s=true);
		[[nodiscard]] static RGB lerp(RGB& a, RGB& b, float t, bool s=true);
	};
}

#endif //IMGMANAGER_COLORSPACE_RGB_H