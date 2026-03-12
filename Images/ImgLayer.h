//
// Created by student on 08/11/2025.
//

#ifndef IMGMANAGER_IMGLAYER_H
#define IMGMANAGER_IMGLAYER_H
#include <array>

#include "../Colors/ColorSpace.h"
#include "CImg.h"

namespace Images {
	template <ColorSpaces::Is_ColorSpace T> class ImgLayer {
	public:
		const std::array<int, 2> size;

		// 0,0 = top left | list of columns | [x][y] | outer vector = width, inner = height
		std::vector<std::vector<T>> data;

		explicit ImgLayer(const std::array<int, 2>& _size ) : size(_size) {
			data = std::vector(size[0], std::vector<T>(size[1], T()));
		}

		void fill(T col) {
			for (int x=0; x<size[0]; x++) {
				for (int y=0; y<size[1]; y++) {
					data[x][y] = col;
				}
			}
		}

		// returns {x, y}
		[[nodiscard]] std::array<int, 2> convert_1d_2d(const int i) const {
			if (i>=size[0]*size[1]) return {-1, -1};
			return {i/size[1], i%size[1]};
		};

		 cimg_library::CImg<float> exportImgLayer(const char* fileName) {
			cimg_library::CImg<float> img(size[0], size[1], 1, 3);

			//img.fill(0); // black background

			//int i=0;
			std::array<float, 3> pxl;
			cimg_forXY(img, x, y) {


				//std::cout << data[x][y].isLinear << std::endl;
				//std::array<float, 3> tmp = data[x][y].assRGB().asStandard();
				//std::cout << tmp[0] << ", " << tmp[1] << ", " << tmp[2] << std::endl;
				//std::cout << "Def: " << data[x][y].asString() << " / assRGB: " << data[x][y].assRGB().asString() << " / assRGB.asStandard: " << ColorSpaces::sRGB(data[x][y].assRGB().asStandard()).asString() << std::endl;

				pxl=data[x][y].assRGB().asStandard();

				for (int i=0; i<3; i++) {
					img(x,y,0,i) = pxl[i] * 255.0f;
					//std::cout << pxl[i] << std::endl;
				}

				//std::cout << std::endl;
			}

			auto x = img.save_bmp(fileName);
			return img;
		}
	};
} // Images

#endif //IMGMANAGER_IMGLAYER_H