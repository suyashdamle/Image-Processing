#include <iostream>
#include <stdio.h>
#include <math.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;


int main(){
  int bysum,bxsum,L;
  Mat src=imread("im.jpg",0);
   
  namedWindow( "OP", WINDOW_NORMAL );
  Mat op(src.rows,src.cols,CV_8UC1,Scalar(255));
  namedWindow( "IP", WINDOW_NORMAL );
  imshow("IP",src);
  int VAL=0;
  while(1){
    createTrackbar("VAL","OP",&VAL,255);
    for(int i=0;i<src.rows;i++){
      for(int j=0;j<src.cols;j++){
      
      bxsum=bysum=0;
      if(i-1>0 && i+1 <src.rows){
      bxsum=src.at<uchar>(i+1,j)/2-src.at<uchar>(i-1,j)/2;
      }

      if(j-1>0 && j+1 < src.cols){
	bysum=src.at<uchar>(i,j-1)/2-src.at<uchar>(i,j+1)/2;
      }
      op.at<uchar>(i,j)=255-sqrt(bxsum*bxsum + bysum*bysum);
      L=255-op.at<uchar>(i,j);
      if(L>VAL)	
	op.at<uchar>(i,j)=0;
      else
	op.at<uchar>(i,j)=255;
      
	
    }
  }
  
   
    imshow("OP",op);
    waitKey(2);
  }

      return 0;

}
      
	
      
	
