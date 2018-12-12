# ImgProc : A Lightweight Image Processing Tools
an open source project [![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badges/)

## Description
ImgProc is a lightweight software image processing tools available only on Windows 64-bit platform. This software able to perform
simple image processing technique such as converting image to grayscale, noise reduction using gaussian blur and homogeneous blur.

## Requirements
1. Windows 64-bit
2. OpenCV Library (more information [click here](https://opencv.org/)
3. Visual Studio 2017 + Visual C++ build tools

## Download Installer
Instead of build the software by yourself to get the binaries, you can download installer package for this project [here](https://sourceforge.net/projects/imgproc/files/imgproc-setup-alpha-release-100.zip/download)

## Build source code
Get the source code: </br>
```git clone https://github.com/faizainur/imgproc```</br></br>
To build this software, you need Visual Studio 2017 with Visual C++ Build Tools installed on your computer.</br>
### Step
1. Open source code directory
2. Open ```FinalProject.sln``` file
3. Navigate to ```Build``` menu and click ```Build``` or simply press ```Ctrl + Shift + B```</br></br>
After build finished, you can find the binaries file inside ```<source-code-dir>\x64\<Debug | Release>```. Please copy ```dll```s files
(get the ```dll```s files [here](https://drive.google.com/file/d/12FJsw-BUbXrprhTwl99OwVylhVrUT6UL/view?usp=sharing)) to the binaries directory.
## Troubleshooting
1. Build failed</br>
This problem occurs might be caused by Build Tools failed to find dependencies in your computer. Please make sure that
any dependencies needed as shown above installed/available in your computer.

2. Program won't to start</br>
This problem occurs when the ```dll```s file needed is not found. Please copy all ```dll```s to installation/binaries directory

## Wiki
For further information, look at [Wiki](https://github.com/faizainur/imgproc/wiki)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details
