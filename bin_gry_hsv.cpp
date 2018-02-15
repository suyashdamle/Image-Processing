#include <iostream>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include "opencv2/objdetect/objdetect.hpp"



using namespace cv;
using namespace std;

int main(){
  
  Mat src=imread("img.jpg",1);
  Mat src2(src.rows,src.cols,CV_8UC1,Scalar(0));
  Mat src3(src.rows,src.cols,CV_8UC1,Scalar(0));
  Mat src4(src.rows,src.cols,CV_8UC1,Scalar(0));
  
  namedWindow( "ORIGINAL", WINDOW_AUTOSIZE );
  namedWindow( "GRAY", WINDOW_AUTOSIZE );
  namedWindow( "BINARY", WINDOW_AUTOSIZE );
  namedWindow( "CONVERTED", WINDOW_AUTOSIZE );
  
  imshow( "ORIGINAL", src );  
  for(int i=0;i<src.rows;i++){
    for(int j=0;j<src.cols;j++){
      src2.at<uchar>(i,j)=(src.at<Vec3b>(i,j)[0]+src.at<Vec3b>(i,j)[1]+src.at<Vec3b>(i,j)[2])/3;
      src3.at<uchar>(i,j)=(src2.at<uchar>(i,j)<150)?0:255;
    }
  }
  imshow("GRAY",src2);
  imshow("BINARY",src3);

  
  /*Using convert function*/
  cvtColor(src,src4,CV_BGR2HSV);//or CV_BGR2HSV or CV_RGB2GRAY or CV_HSV2BGR
  imshow("CONVERTED",src4);

  
  waitKey(0);
  return 0;
}
