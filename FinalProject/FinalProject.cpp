// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <opencv2\opencv.hpp>
#include <Windows.h>


int convImgMonochrome(cv::Mat img_src, std::string save_filename);
int gaussianBlur(cv::Mat img_src, std::string save_filename);
int homogeneusBlur(cv::Mat img_src, std::string save_filename);
cv::Mat loadImage(std::string filename);
int main(int argc, char* argv[])
{
	std::string success_message;

	// Detect if there are any command line args
	if (argc > 1) {
		for (int i = 0; i < argc; ++i) {
			if (i == 0) {
				continue;
			}
			else {

				// Command line argument for convert image
				if (strcmp(argv[i], "--convert") == 0) {
					cv::Mat buff = loadImage(argv[i + 1]);
					int result = convImgMonochrome(buff, argv[i + 2]);
					if (result > 0) {
						MessageBox(0, TEXT("Failed to converting image"), TEXT("Error"), MB_OK);
						std::cout << "Failed to converting image" << std::endl;
					}
					else {
						std::string save_path = argv[i + 2];
						success_message = "Successfull converting image.\nImage saved as " + save_path;
						MessageBox(NULL, TEXT("Successfull converting image."), TEXT("Success"), MB_ICONINFORMATION | MB_OK);
						std::cout << success_message << std::endl;
						char c = (char)cv::waitKey(10);
						system("pause");
					}
				}

				// Command line argument for add blur in image
				if (strcmp(argv[i], "--add-blur") == 0) {
					if (strcmp(argv[i + 1], "Gaussian Blur") == 0) {
						cv::Mat buff = loadImage(argv[i + 2]);
						int result = gaussianBlur(buff, argv[i + 3]);
						if (result > 0) {
							MessageBox(0, TEXT("Failed to process image"), TEXT("Error"), MB_OK);
							std::cout << "Failed to process image" << std::endl;
						}
						else {
							std::string save_path = argv[i + 3];
							success_message = "Successfull process image.\nImage saved as " + save_path;
							MessageBox(NULL, TEXT("Successfull process image."), TEXT("Success"), MB_ICONINFORMATION | MB_OK);
							std::cout << success_message << std::endl;
							char c = (char)cv::waitKey(10);
							system("pause");
						}
					}
					else if (strcmp(argv[i + 1], "Homogeneus Blur") == 0) {
						cv::Mat buff = loadImage(argv[i + 2]);
						int result = homogeneusBlur(buff, argv[i + 3]);
						if (result > 0) {
							MessageBox(0, TEXT("Failed to process image"), TEXT("Error"), MB_OK);
							std::cout << "Failed to process image" << std::endl;
						}
						else {
							std::string save_path = argv[i + 3];
							success_message = "Successfull process image.\nImage saved as " + save_path;
							MessageBox(NULL, TEXT("Successfull process image."), TEXT("Success"), MB_ICONINFORMATION | MB_OK);
							std::cout << success_message << std::endl;
							char c = (char)cv::waitKey(10);
							system("pause");
						}
					}
				}
			}
		}
	}
	
}

cv::Mat loadImage(std::string filename) {
	cv::Mat buff;
	buff = imread(filename, cv::IMREAD_COLOR);

	if (buff.empty()) {
		MessageBox(0, TEXT("Invalid image input"), TEXT("Error"), MB_OK);
		std::cout << "Invalid image input" << std::endl;
	}
	return buff;
}

int convImgMonochrome(cv::Mat img_src, std::string save_filename) {
	cv::Mat img_conv;
	cv::cvtColor(img_src, img_conv, cv::COLOR_BGR2GRAY);

	cv::imwrite(save_filename, img_conv);

	cv::namedWindow("Image Source", cv::WINDOW_NORMAL);
	cv::namedWindow("Result", cv::WINDOW_NORMAL);



	cv::imshow("Image Source", img_src);
	cv::imshow("Result", img_conv);

	return EXIT_SUCCESS;
}

int gaussianBlur(cv::Mat img_src, std::string save_filename) {
	cv::Mat img_gaussian;

	cv::GaussianBlur(img_src, img_gaussian, cv::Size(3, 3), 0);
	
	cv::imwrite(save_filename, img_gaussian);

	cv::namedWindow("Image Source", cv::WINDOW_NORMAL);
	cv::namedWindow("Result", cv::WINDOW_NORMAL);

	cv::imshow("Image Source", img_src);
	cv::imshow("Result", img_gaussian);

	return EXIT_SUCCESS;
}

int homogeneusBlur(cv::Mat img_src, std::string save_filename) {
	cv::Mat img_blur;

	cv::blur(img_src, img_blur, cv::Size(3, 3));

	cv::imwrite(save_filename, img_blur);

	cv::namedWindow("Image Source", cv::WINDOW_NORMAL);
	cv::namedWindow("Result", cv::WINDOW_NORMAL);

	cv::imshow("Image Source", img_src);
	cv::imshow("Result", img_blur);

	return EXIT_SUCCESS;
}



