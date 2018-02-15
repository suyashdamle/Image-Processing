#include <iostream>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;
int main(){
  Mat src=imread("img.jpg",0);
  Mat flt(src.rows,src.cols,CV_8UC3,Scalar(0,0,0));
  int val=10;
  
  while(1){
    namedWindow( "OP", WINDOW_AUTOSIZE );
    createTrackbar("VAL","OP",&val,25);
    for(int i=0;i<src.rows;i++){
      for(int j=0;j<src.cols;j++){
	src.at<Vec3b>(i,j)[1]=src.at<Vec3b>(i,j)[1]+val*10;
	src.at<Vec3b>(i,j)[2]=src.at<Vec3b>(i,j)[2]+val*10;
      }
    }
    imshow("OP",src);
    waitKey(2);
  }
}
	
	
      
