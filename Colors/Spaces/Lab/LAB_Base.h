//
// Created by student on 20/11/2025.
//

#ifndef IMGMANAGER_LAB_BASE_H
#define IMGMANAGER_LAB_BASE_H
#include <array>
#include <string_view>
#include "../../ColorSpace.h"


namespace ColorSpaces {
	//template <typename T>
	//concept Is_LAB_ColorSpace = requires {
	//	{ T::ID } -> std::convertible_to<const char*>;
	//} && (std::string_view(T::ID).starts_with("ColorSpace.LAB"));

	struct LAB_Base : public ColorSpace<3> {
	public:
		constexpr static const char* ID = "ColorSpace.LAB";

		// Getters
		[[nodiscard]] float L() const { return channels[0]; }
		[[nodiscard]] float a() const { return channels[1]; }
		[[nodiscard]] float b() const { return channels[2]; }

		float& L() { return channels[0]; }
		float& a() { return channels[1]; }
		float& b() { return channels[2]; }


		// Deconstructor(s)
		virtual ~LAB_Base() = default; // default deconstructor

		// Constructor(s)
		using ColorSpace::ColorSpace;
		LAB_Base(float _L, float _a, float _b) :
			ColorSpace<3>(std::array<float, 3>{_L, _a, _b}) {}
		/*
		LAB_Base() :
			ColorSpace(std::array<float, 3>{0,0,0}) {}

		LAB_Base(float _L, float _a, float _b) :
			ColorSpace<3>(std::array<float, 3>{_L, _a, _b}) {}

		explicit LAB_Base(std::array<float, 3> _channels) :
			ColorSpace<3>(_channels) {}

		explicit LAB_Base(std::vector<float> _channels) :
			ColorSpace<3>(std::array{_channels[0], _channels[1], _channels[2]}) {}
		*/

		// Operators
		LAB_Base& operator=(const LAB_Base& other) {
			channels=other.channels;
			return *this;
		}

		// Methods
	};
} // ColorSpaces


#endif //IMGMANAGER_LAB_BASE_H
