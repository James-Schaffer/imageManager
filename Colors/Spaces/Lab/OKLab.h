#ifndef IMGMANAGER_OKLAB_H
#define IMGMANAGER_OKLAB_H
#include "LAB_Base.h"
#include "../RGB/sRGB.h"


namespace ColorSpaces {
	struct OKLab final : public LAB_Base {
	public:
		constexpr static const char* ID = "ColorSpace.LAB.OKLab";
		using LAB_Base::LAB_Base;

		// Conversion methods
		sRGB assRGB() const;
	};
}

#endif //IMGMANAGER_OKLAB_H