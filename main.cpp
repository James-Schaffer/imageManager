//
// Created by student on 03/11/2025.
//

#include <iostream>

#include "Colors/ColorSpace.h"
#include "Colors/Color_RGB.h"
#include "Images/ImgLayer.h"

int main() {
	Images::ImgLayer<ColorSpace::RGB> newImg(std::array<int, 2>({100, 100}));

	std::cout << newImg.size[0] << ' ' << newImg.size[1] << '\n';

	return 0;
}
