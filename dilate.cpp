#include <iostream>
#include <stdio.h>
//#include <math.h>
#include <stdlib.h>
#include<deque>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

int main(){
  Mat src=imread("noise.jpg",1);
  Mat op(src.rows,src.cols,CV_8UC1,Scalar(0));
  
  //to binary
  for(int i=0;i<src.rows;i++){
    for(int j=0;j<src.cols;j++){
      int avg=(src.at<Vec3b>(i,j)[0]+src.at<Vec3b>(i,j)[1]+src.at<Vec3b>(i,j)[2])/3;
      op.at<uchar>(i,j)=(avg<50)?0:255;
    }
  }

  // eroding
  int i1,j1;
  int flag=0;
  Mat op2(src.rows,src.cols,CV_8UC1,Scalar(0));
  for(int i=0;i<src.rows;i++){
    for(int j=0;j<src.cols;j++){
      flag=0;
      for(int m=i-1;m<=i+1;m++){
	for(int n=j-1;n<=j+1;n++){
	  if(m>0 && n>0 && m<src.rows && n<src.cols && flag==0 && op.at<uchar>(m,n)==255){
	    op2.at<uchar>(i,j)=255;
	    flag=1;
	  }

	}
      }
    }
  }
	  
     


 
  namedWindow( "IP", WINDOW_NORMAL );
  namedWindow( "OP", WINDOW_NORMAL );
  namedWindow( "OP2", WINDOW_NORMAL );
  imshow("IP",src);
  imshow("OP",op);
  imshow("OP2",op2);
  waitKey(0);

  return 0;
}
