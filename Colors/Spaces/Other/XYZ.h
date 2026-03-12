#ifndef IMGMANAGER_XYZ_H
#define IMGMANAGER_XYZ_H
#include <array>
#include <vector>
#include "../../ColorSpace.h"

namespace ColorSpaces {
	struct XYZ : public ColorSpace<3> {
	public:
		constexpr static const char* ID = "ColorSpace.XYZ.CIE_XYZ";

		// Getters
		[[nodiscard]] float x() const { return channels[0]; }
		[[nodiscard]] float y() const { return channels[1]; }
		[[nodiscard]] float z() const { return channels[2]; }

		float& x() { return channels[0]; }
		float& y() { return channels[1]; }
		float& z() { return channels[2]; }


		// Deconstructor(s)
		virtual ~XYZ() = default; // default deconstructor

		// Constructor(s)
		XYZ() :
			ColorSpace(std::array<float, 3>{0,0,0}) {}

		XYZ(float _x, float _y, float _z) :
			ColorSpace<3>(std::array<float, 3>{_x, _y, _z}) {}

		explicit XYZ(std::array<float, 3> _channels) :
			ColorSpace<3>(_channels) {}

		explicit XYZ(std::vector<float> _channels) :
			ColorSpace<3>(std::array{_channels[0], _channels[1], _channels[2]}) {}

		// Operators
		XYZ& operator=(const XYZ& other) {
			channels=other.channels;
			return *this;
		}

		// Methods
	};
}

#endif //IMGMANAGER_XYZ_H