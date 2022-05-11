#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("C:/Users/dell/Desktop/images.jpg");
	imshow("input", src);
	waitKey(0);//图像一直显示 1 1ms显示
	
	destroyAllWindows;
	return 0;
}
