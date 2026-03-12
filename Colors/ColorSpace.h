#ifndef IMGMANAGER_COLORSPACE_H
#define IMGMANAGER_COLORSPACE_H

#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

namespace ColorSpaces {
	// Check if T is a color space
	template <typename T>
	concept Is_ColorSpace = requires {
		{ T::ID } -> std::convertible_to<const char*>;
	} && (std::string_view(T::ID).starts_with("ColorSpace"));

	// Colorspace abstract class, N channels
	template <int N>
	struct ColorSpace {
	public:
		constexpr static const char* ID = "ColorSpace";

		// Deconstructor(s)
		virtual ~ColorSpace() = default;

		// Constructor(s)
		ColorSpace() {channels.fill(0.0f);}
		explicit ColorSpace(std::array<float, N> _channels) : channels(_channels) {}
		explicit ColorSpace(std::vector<float> _channels) {
			std::copy_n(_channels.begin(), N, channels.begin());
		}

		[[nodiscard]] static int size() {return N;};
		[[nodiscard]] std::string asString() {
			return std::to_string(channels[0]) + "," +
				std::to_string(channels[1]) + "," +
				std::to_string(channels[2]);
		}

	protected:
		// Stores all values for color spaces (e.g. r,g,b or h,s,v)
		std::array<float, N> channels;

		// Access functions (for array-like access of channels)
		[[nodiscard]] float at(int i) const {
			return channels[i];
		}

		template <Is_ColorSpace T>
		friend T averageOf(const std::vector<T> cols);
	};

	// Methods
	template <Is_ColorSpace T>
	[[nodiscard]] static T averageOf(const std::vector<T> cols) {
		if (cols.empty()) return {};
		if (cols.size() == 1) return cols[0];

		const int COL_NUMB = cols.size();
		const int CHANNEL_NUMB = cols[0].size();

		std::vector<float> new_channels(CHANNEL_NUMB);

		for (int i = 0; i < CHANNEL_NUMB; i++) {
			for (auto& col: cols) {
				new_channels[i] += col.at(i);
			}

			new_channels[i] /= COL_NUMB;
		}

		return T(new_channels);
	}

	template <Is_ColorSpace T>
	[[nodiscard]] static T lerp(const T &a, const T &b, float t) {
		const int CHANNEL_NUMB = a.size();
		std::pmr::vector<float> new_channels(CHANNEL_NUMB);

		for (int i = 0; i < CHANNEL_NUMB; i++) {
			new_channels[i] = std::lerp(a.channels[0], b.channels[0], t);
		}

		return T(new_channels);
	}
}
#endif //IMGMANAGER_COLORSPACE_H