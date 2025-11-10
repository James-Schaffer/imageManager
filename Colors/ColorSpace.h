#ifndef IMGMANAGER_COLORSPACE_H
#define IMGMANAGER_COLORSPACE_H

#include <string>

namespace ColorSpace {
	class RGB; // Declares RGB first as used as a universal color space for passing values between color spaces

	// Colorspace abstract class
	class ColorSpace {
	public:
		virtual ~ColorSpace() = default; // default deconstructor

		virtual std::string name() const = 0;
		virtual RGB toRGB() const = 0;
		virtual void fromRGB(RGB rgb) = 0;
	};
}
#endif //IMGMANAGER_COLORSPACE_H