#include <iostream>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

int main(){
 namedWindow( "OP", WINDOW_AUTOSIZE );
  Mat src=imread("img.jpg",1);
      int VAL;
    int sr,sc,nr,nc;
    VAL=1;
  while(1){
     createTrackbar("X","OP",&VAL,5);
       nr=VAL*(src.rows);
       nc=VAL*(src.cols);
       Mat nxt(5*(src.rows),5*src.cols,CV_8UC3,Scalar(0,0,0));
       for(int i=0;i<nr;i++){
	 for(int j=0;j<nc;j++){
	   sr=i/VAL;
	   sc=j/VAL;
	   nxt.at<Vec3b>(i,j)[0]=src.at<Vec3b>(sr,sc)[0];
	   nxt.at<Vec3b>(i,j)[1]=src.at<Vec3b>(sr,sc)[1];
	   nxt.at<Vec3b>(i,j)[2]=src.at<Vec3b>(sr,sc)[2];
	 }
       }
       imshow("OP",nxt);
     waitKey(2);
 

     }
  return 0;
}
