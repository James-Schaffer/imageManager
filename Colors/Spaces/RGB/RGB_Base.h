#ifndef IMGMANAGER_RGB_BASE_H
#define IMGMANAGER_RGB_BASE_H

#include <array>
#include <memory>

#include "../../ColorSpace.h"

namespace ColorSpaces {
	//template <typename T>
	//concept Is_RGB_ColorSpace = requires {
	//		{ T::ID } -> std::convertible_to<const char*>;
	//} && (std::string_view(T::ID).starts_with("ColorSpace.RGB"));

	struct RGB_Base : public ColorSpace<3> {
	public:
		constexpr static const char* ID = "ColorSpace.RGB";
		bool isLinear;

		// Getters
		[[nodiscard]] float r() const { return channels[0]; }
		[[nodiscard]] float g() const { return channels[1]; }
		[[nodiscard]] float b() const { return channels[2]; }

		float& r() { return channels[0]; }
		float& g() { return channels[1]; }
		float& b() { return channels[2]; }


		// Deconstructor(s)
		virtual ~RGB_Base() = default; // default deconstructor

		// Constructor(s)
		RGB_Base() :
			ColorSpace(std::array<float, 3>{0,0,0}), isLinear(false) {}

		RGB_Base(float _r, float _g, float _b, bool _linear=false) :
			ColorSpace<3>(std::array<float, 3>{_r, _g, _b}), isLinear(_linear) {}

		explicit RGB_Base(std::array<float, 3> _channels, bool _linear=false) :
			ColorSpace<3>(_channels), isLinear(_linear) {}

		explicit RGB_Base(std::vector<float> _channels, bool _linear=false) :
			ColorSpace<3>(std::array{_channels[0], _channels[1], _channels[2]}), isLinear(_linear) {}

		// Operators
		RGB_Base& operator=(const RGB_Base& other) {
			channels=other.channels;
			isLinear=other.isLinear;
			return *this;
		}

		// Methods
		void setLinearity(bool target) {
			if (isLinear == target) {return;}

			auto newChannels = (target) ? asLinear() : asStandard();
			std::copy(newChannels.begin(), newChannels.end(), channels.begin());

			isLinear = target;
		}

		virtual std::array<float, 3> asLinear() const = 0;
		virtual std::array<float, 3> asStandard() const = 0;
	};
} // ColorSpaces

#endif //IMGMANAGER_RGB_BASE_H