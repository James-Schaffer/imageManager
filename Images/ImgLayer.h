//
// Created by student on 08/11/2025.
//

#ifndef IMGMANAGER_IMGLAYER_H
#define IMGMANAGER_IMGLAYER_H
#include "../Colors/ColorSpace.h"
#include "CImg.h"

namespace Images {
	template <class T> class ImgLayer {
	public:
		const std::array<int, 2> size;

		explicit ImgLayer(const std::array<int, 2>& _size ) : size(_size) {
			static_assert(std::is_base_of<ColorSpace::ColorSpace, T>::value, "Type not derived from ColorSpace");
		}

		 cimg_library::CImg<unsigned char> explortImgLayer(const char* fileName) {
			cimg_library::CImg<float> img(size[0], size[1], 1, 3);
			img.fill(0);                             // black background

			const unsigned char red[] = {1, 0, 0};
			img.draw_line(0, 0, 1, 1, red);      // draw a red diagonal line

			img.save(fileName);                  // 🧠 saves automatically as PNG#
			return img;
		}
	};
} // Images

#endif //IMGMANAGER_IMGLAYER_H