#include <iostream>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;
int main(){
	 int C=-5;
	Mat bw,bin;
	Mat src=imread("op37.jpg",1);
	cvtColor(src,bw,CV_BGR2GRAY);
	adaptiveThreshold(bw,bin, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY,11,C);
	namedWindow( "Image", CV_WINDOW_NORMAL );
  imshow("Image",bin);
  waitKey(0);
}

