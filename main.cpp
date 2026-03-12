#include <format>
#include <iostream>

#include "Colors/ColorSpace.h"
#include "Colors/Spaces/Lab/OKLab.h"
#include "Colors/Spaces/RGB/sRGB.h"
#include "Images/ImgLayer.h"

int main() {
	/*
	std::vector<ColorSpaces::sRGB> data_1;
	data_1 = std::vector(5, ColorSpaces::sRGB{});

	data_1[0] = ColorSpaces::sRGB{
		static_cast<float>(9)/static_cast<float>(10),
		static_cast<float>(9)/static_cast<float>(10),
		1
	};

	std::cout << "R: " << data_1[0].r() << ", G: " << data_1[0].g() << ", B: " << data_1[0].b() << std::endl;

	return 0;

	int size[] = {10, 10};
	std::vector<std::vector<ColorSpaces::sRGB>> data;

	data = std::vector(size[0], std::vector(size[1], ColorSpaces::sRGB()));

	for (int x=0; x<size[0]; x++) {
		for (int y=0; y<size[1]; y++) {
			data[x][y] = ColorSpaces::sRGB(
				static_cast<float>(y)/static_cast<float>(size[1]),
				static_cast<float>(x)/static_cast<float>(size[0]),
				1
			);

			std::cout << x << "," << y << " : " << static_cast<float>(y)/size[1] << ", " << static_cast<float>(x)/size[0] << std::endl;
			std::cout << data[x][y].asString() << std::endl;
		}
	}


	std::cout << data[9][9].asString() << std::endl;

	std::cout << data[9][9].assRGB().asString() << std::endl;

	std::cout << data[9][9].assRGB().asString() << std::endl;

	std::cout << "R: " << data[9][9].r() << ", G: " << data[9][9].g() << ", B: " << data[9][9].b() << std::endl;

	std::cout << ColorSpaces::sRGB(data[9][9].assRGB().asStandard()).asString() << std::endl;


	std::cout << "TEST TEST TEST ##########" << std::endl;

	ColorSpaces::OKLab test(0.57, -0.06, 0.06);

	std::cout << "rgb : " << ColorSpaces::sRGB(test.assRGB().asStandard()).asString() << " | okLab : " << test.asString() << std::endl;

	Images::ImgLayer<ColorSpaces::sRGB> x({20,20});
	Images::ImgLayer<ColorSpaces::OKLab> y({20,20});

	x.fill(test.assRGB());
	y.fill(test);

	x.exportImgLayer("test_0_1.bmp");
	y.exportImgLayer("test_0_2.bmp");
	*/

	//Images::ImgLayer<ColorSpaces::sRGB> x({100,100});
	//x.test01();
	//x.exportImgLayer("rgb.bmp");

	// height & cube width
	int h = 100, w = 100;

	float h_inverse = 1.0f / h;
	float w_inverse = 1.0f / w;

	Images::ImgLayer<ColorSpaces::OKLab> q({w,w});

	for (int z=0; z <h; z++) {

		// render layer
		for (int x=0; x<w; x++) {
			for (int y=0; y<w; y++) {
				q.data[x][y] = ColorSpaces::OKLab(
					(z*h_inverse/0.9f),
					(static_cast<float>(x)*w_inverse*0.8f) -0.4f,
					(static_cast<float>(y)*w_inverse*0.8f) -0.4f
				);

				// std::cout << x << "," << y << " : " << q.data[x][y].asString() << std::endl;
				// std::cout << q.data[x][y].asString() << std::endl;
				// std::cout << q.data[x][y].assRGB().asString() << std::endl;
			}
		}
		q.exportImgLayer(std::format("out/OKLab_{}.bmp", z).c_str());
	}

	return 0;
}
