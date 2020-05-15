#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Mat srcMat=imread("etest.jpg");
	Mat dstMat;
	//srcMat.copyTo(dstMat);
	if (srcMat.type() == CV_8UC1) {
		equalizeHist(srcMat, dstMat);
	}
	else if (srcMat.type() == CV_8UC3) {
		Mat rgb[3];
		Mat image[3];
		split(srcMat, rgb);
		for (int i = 0; i < 3; i++) {
			equalizeHist(rgb[i], image[i]);
		}
		merge(image, 3, dstMat);
	}
	imshow("Ô­Í¼", srcMat);
	imshow("¾ùºâ»¯", dstMat);
	waitKey(0);
}