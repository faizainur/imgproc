// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <iostream>
#include <opencv2\opencv.hpp>
#include <Windows.h>

// Function prototype
int convImgMonochrome(cv::Mat img_src, std::string save_filename);
int gaussianBlur(cv::Mat img_src, std::string save_filename);
int homogeneusBlur(cv::Mat img_src, std::string save_filename);
int invertImage(cv::Mat img_src, std::string save_filename);
cv::Mat loadImage(std::string filename);
void mainMenu();
void help();


int main(int argc, char* argv[])
{
	std::string success_message;
	std::string filename_buff;
	std::string save_filename_buff;
	cv::Mat buff;
	int result;


	// Detect if there are any command line args
	if (argc > 1) {
		for (int i = 0; i < argc; ++i) {
			if (i == 0) {
				continue;
			}
			else {
				// Command line argument for convert image
				if (strcmp(argv[i], "--convert") == 0) {
					buff = loadImage(argv[i + 1]);
					result = convImgMonochrome(buff, argv[i + 2]);
					if (result > 0) {
						MessageBox(0, TEXT("Failed to converting image"), TEXT("Error"), MB_OK);
						std::cout << "Failed to converting image" << std::endl;
					}
					else {
						std::string save_path = argv[i + 2];
						success_message = "Successfull process image.\nResult Image saved as " + save_filename_buff;
						MessageBox(NULL, TEXT("Successfull converting image."), TEXT("Success"), MB_ICONINFORMATION | MB_OK);
						std::cout << success_message << "\n[CTRL + C] to exit" << std::endl;
						cv::waitKey(0);
					}
				}

				// Command line argument for add blur in image
				if (strcmp(argv[i], "--add-blur") == 0) {
					if (strcmp(argv[i + 1], "Gaussian Blur") == 0) {
						buff = loadImage(argv[i + 2]);
						result = gaussianBlur(buff, argv[i + 3]);
						if (result > 0) {
							MessageBox(0, TEXT("Failed to process image"), TEXT("Error"), MB_OK);
							std::cout << "Failed to process image" << std::endl;
						}
						else {
							std::string save_path = argv[i + 3];
							success_message = "Successfull process image.\nResult Image saved as " + save_filename_buff;
							MessageBox(NULL, TEXT("Successfull process image."), TEXT("Success"), MB_ICONINFORMATION | MB_OK);
							std::cout << success_message << "\n[CTRL + C] to exit" << std::endl;
							cv::waitKey(0);
						}
					}
					else if (strcmp(argv[i + 1], "Homogeneous Blur") == 0) {
						buff = loadImage(argv[i + 2]);
						result = homogeneusBlur(buff, argv[i + 3]);
						if (result > 0) {
							MessageBox(0, TEXT("Failed to process image"), TEXT("Error"), MB_OK);
							std::cout << "Failed to process image" << std::endl;
						}
						else {
							std::string save_path = argv[i + 3];
							success_message = "Successfull process image.\nResult Image saved as " + save_filename_buff;
							MessageBox(NULL, TEXT("Successfull process image."), TEXT("Success"), MB_ICONINFORMATION | MB_OK);
							std::cout << success_message << "\n[CTRL + C] to exit" << std::endl;
							cv::waitKey(0);
						}
					}
				}

				if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
					help();
				}

				// Command line argument for invert image
				if (strcmp(argv[i], "--threshold") == 0) {
					std::cout << "This action still under development" << std::endl;

					// Under development
					/*cv::Mat buff = loadImage(argv[i + 1]);
					result = invertImage(buff, argv[i + 2]);
					if (result > 0) {
						MessageBox(0, TEXT("Failed to process image"), TEXT("Error"), MB_OK);
						std::cout << "Failed to process image" << std::endl;
					}
					else {
						std::string save_path = argv[i + 3];
						success_message = "Successfull process image.\nImage saved as " + save_path;
						MessageBox(NULL, TEXT("Successfull process image."), TEXT("Success"), MB_ICONINFORMATION | MB_OK);
						std::cout << success_message << "([CTRL + C] to exit" << std::endl;
						char c = (char)cv::waitKey(10);
					}*/
				}
			}
		}
	}
	else {
		

		int choice, count = 0;
		while (count = 1) {
			mainMenu();
			printf("#please type the single number of the menu you choose,\n");
			printf(" and then press enter to select it\n\n");
			printf("Your Choice : ");

			scanf_s("%d", &choice);

			switch (choice) {
			case 1:
				system("cls");
				std::cout << "Enter input filename : " << std::endl;
				std::cin >> filename_buff;
				std::cout << "Enter output filename : " << std::endl;
				std::cin >> save_filename_buff;

				buff = loadImage(filename_buff);
				result = convImgMonochrome(buff, save_filename_buff);
				if (result > 0) {
					MessageBox(0, TEXT("Failed to converting image"), TEXT("Error"), MB_OK);
					std::cout << "Failed to converting image" << std::endl;
				}
				else {
					success_message = "Successfull process image.\nResult Image saved as " + save_filename_buff;
					MessageBox(NULL, TEXT("Successfull converting image."), TEXT("Success"), MB_ICONINFORMATION | MB_OK);
					std::cout << success_message << "\n[CTRL + C] to exit" << std::endl;
					printf("\n\tThank You For Using Our Program!\n\n");
					printf("PRESS ENTER TO EXIT...\n");
					count = 1;
					system("pause");
					cv::destroyAllWindows();
				}
				count = 1;
				break;

			case 2:
				system("cls");
				std::cout << "Enter input filename : " << std::endl;
				std::cin >> filename_buff;
				std::cout << "Enter output filename : " << std::endl;
				std::cin >> save_filename_buff;

				buff = loadImage(filename_buff);
				result = gaussianBlur(buff, save_filename_buff);
				if (result > 0) {
					MessageBox(0, TEXT("Failed to process image"), TEXT("Error"), MB_OK);
					std::cout << "Failed to process image" << std::endl;
				}
				else {
					success_message = "Successfull process image.\nResult Image saved as " + save_filename_buff;
					MessageBox(NULL, TEXT("Successfull process image."), TEXT("Success"), MB_ICONINFORMATION | MB_OK);
					std::cout << success_message << "\n[CTRL + C] to exit" << std::endl;
					printf("\n\tThank You For Using Our Program!\n\n");
					printf("PRESS ENTER TO EXIT...\n");
					count = 1;
					system("pause");
					cv::destroyAllWindows();
				}
				count = 1;
				break;

			case 3:
				system("cls");
				std::cout << "Enter input filename : " << std::endl;
				std::cin >> filename_buff;
				std::cout << "Enter output filename : " << std::endl;
				std::cin >> save_filename_buff;

				buff = loadImage(filename_buff);
				result = homogeneusBlur(buff, save_filename_buff);
				if (result > 0) {
					MessageBox(0, TEXT("Failed to process image"), TEXT("Error"), MB_OK);
					std::cout << "Failed to process image" << std::endl;
				}
				else {
					success_message = "Successfull process image.\nResult Image saved as " + save_filename_buff;
					MessageBox(NULL, TEXT("Successfull process image."), TEXT("Success"), MB_ICONINFORMATION | MB_OK);
					std::cout << success_message << "\n[CTRL + C] to exit" << std::endl;
					printf("\n\tThank You For Using Our Program!\n\n");
					printf("PRESS ENTER TO EXIT...\n");
					count = 1;
					system("pause");
					cv::destroyAllWindows();
				}
				break;

			case 4:
				system("cls");
				help();
				count = 1;
				break;

			case 5:
				break;

			default:
				printf("please only input number between 1 to 5\n");
				printf("as shown in menu...\n");
				printf("PRESS ENTER TO GO BACK TO MAIN MENU...\n");
				system("pause");
				count = 1;
				break;

			}
		}
	}
	return 0;
}

cv::Mat loadImage(std::string filename) {
	cv::Mat buff;
	buff = imread(filename, cv::IMREAD_COLOR); // Load image

	// Check if invalid image
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

	cv::namedWindow("Image Source", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Result", cv::WINDOW_AUTOSIZE);



	cv::imshow("Image Source", img_src);
	cv::imshow("Result", img_conv);

	return EXIT_SUCCESS;
}

int gaussianBlur(cv::Mat img_src, std::string save_filename) {
	cv::Mat img_gaussian;

	cv::GaussianBlur(img_src, img_gaussian, cv::Size(3, 3), 0);
	
	cv::imwrite(save_filename, img_gaussian);

	cv::namedWindow("Image Source", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Result", cv::WINDOW_AUTOSIZE);

	cv::imshow("Image Source", img_src);
	cv::imshow("Result", img_gaussian);

	return EXIT_SUCCESS;
}

int homogeneusBlur(cv::Mat img_src, std::string save_filename) {
	cv::Mat img_blur;

	cv::blur(img_src, img_blur, cv::Size(3, 3));

	cv::imwrite(save_filename, img_blur);

	cv::namedWindow("Image Source", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Result", cv::WINDOW_AUTOSIZE);

	cv::imshow("Image Source", img_src);
	cv::imshow("Result", img_blur);
	
	
	return EXIT_SUCCESS;
}

int invertImage(cv::Mat img_src, std::string save_filename) {

	// TODO : Thresholding image algorithm

	cv::Mat img_invert;

	cv::threshold(img_src, img_invert, 0.5, 1.0, cv::THRESH_BINARY_INV);

	cv::imwrite(save_filename, img_invert);

	cv::namedWindow("Image Source", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Result", cv::WINDOW_AUTOSIZE);

	cv::imshow("Image Source", img_src);
	cv::imshow("Result", img_invert);

	return EXIT_SUCCESS;
}

void mainMenu() {
	printf("\n                                                                            \n");
	printf("                                  |=======|                                   \n");
	printf("                                  |=======|                                   \n");
	printf("             ___                  |=======|                  ___              \n");
	printf("            |   |              ___ ------- ____             |   |             \n");
	printf("          __|   |___         /                  )        ___|   |___          \n");
	printf("         | _     _  )       (    - ------- -    /       (  _     _  |         \n");
	printf("         |/ |   | |/         |  / |       | |  /         |/ |   | |/          \n");
	printf("     ______ |___|____________| /__|_______|_| /_____________|___|_______      \n");
	printf("     ------------------------|/-------------|/---------------------------     \n");
	printf("    |                                                                    |    \n");
	printf("    | MonoChrome Image Converter (Command Windows) by Faiz A.R / Surya A |    \n");
	printf("    |                by Faiz Ainur Rofiq / Surya Asmoro Y.P.             |    \n");
	printf("    |____________________________________________________________________|    \n");
	printf("     --------------------------------------------------------------------     \n");
	printf("            |   |              == MAIN MENU ==              |   |             \n");
	printf("            |   )           1. Convert Image                |   )             \n");
	printf("            |  /            2. Gaussian Blur                |  /              \n");
	printf("            | /             3. Homogeneous Blur             | /               \n");
	printf("            |/              4. Help                         |/                \n");
	printf("    _____________________________________________________________________     \n");
	printf("    _________________________________________________             _______     \n");
	printf("                                                     |  5. Exit  /            \n");
	printf("                                                      -----------             \n");
	printf("                                                                              \n");
	printf("                                                                              \n");
	printf("                                                                              \n");

}

void help() {

	printf("\n");
	printf("  =========================                                                    \n");
	printf(" |           HELP          |                                                   \n");
	printf("  ========================= -----------------------------------------------    \n");
	printf("  Command line args : imgproc [actions] [option] [input] [output]              \n\n");
	printf("  1. Convert Image (--convert)                                                  \n");
	printf("     you may convert images in .jpg format into a monochrome one.              \n");
	printf("                                                                               \n");
	printf("     -How to Use                                                               \n");
	printf("      choose 'Convert Image' menu from main menu, and then                     \n");
	printf("      write out your images filename  in your pc or removables.                \n");
	printf("                                                                               \n");
	printf("      press enter, and we'll convert your image into black white color!        \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("  2. Gaussian Blur (--add-blur [Gaussian Blur])                                \n");
	printf("     you may blurring your image with Gaussian Blur!                           \n");
	printf("                                                                               \n");
	printf("     -How to Use                                                               \n");
	printf("      choose 'Gaussian Blur' menu from main menu, and then                     \n");
	printf("      write out your images filename  in your pc or removables.                \n");
	printf("                                                                               \n");
	printf("      press enter, and we'll give gaussian blur's touch to your image!         \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("  3. Homogeneous Blur (--add-blur [Homogeneous Blur])                          \n");
	printf("     you may blurring your image with Homogeneous Blur!                        \n");
	printf("                                                                               \n");
	printf("     -How to Use                                                               \n");
	printf("     choose 'Homogeneous Blur' menu from main menu, and then                   \n");
	printf("     write out your images filename  in your pc or removables.                 \n");
	printf("                                                                               \n");
	printf("     press enter, and we'll give Homogeneous blur's touch to your image!       \n");
	printf("                                                                               \n\n");
	printf("   Example command line args :                                                 \n");
	printf("           imgproc --convert img.jpg output.jpg                                \n\n");
	printf("   ATTENTION!                                                                  \n");
	printf("   -Make sure the filename of the input is right, before blaming the program.  \n");
	printf("   -This program is free to use, not for sale.                                 \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	system("pause");
	system("cls");
}

