#ifndef IMGMANAGER_COLORSPACE_SRGB_H
#define IMGMANAGER_COLORSPACE_SRGB_H

#include <memory>

#include "RGB_Base.h"

namespace ColorSpaces {
	struct sRGB final : public RGB_Base {
	public:
		constexpr static const char* ID = "ColorSpace.RGB.sRGB";
		using RGB_Base::RGB_Base;

		// Class methods
		std::array<float, 3> asLinear() const override;
		std::array<float, 3> asStandard() const override;

		// Conversion methods
		sRGB assRGB() const {return *this;}
	};
}

#endif //IMGMANAGER_COLORSPACE_SRGB_H