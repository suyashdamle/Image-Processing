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
 int sr,sc,nr,nc;
 int VAL=2;
 //createTrackbar("X","OP",&VAL,5);
     //nr=VAL*(src.rows);
     // nc=VAL*(src.cols);
     Mat nxt(src.rows,src.cols,CV_8UC3,Scalar(0,0,0));
     for(int i=0;i<(src.rows)/VAL;i++){
       for(int j=0;j<(src.cols)/VAL;j++){
	 //sr=i*VAL;
	 // sc=j*VAL;
	 for(int m=i*VAL;m<i*VAL+VAL;m++){
	   for(int n=j*VAL;n<j*VAL+VAL;n++){
	     if(m<src.rows && n<src.cols){
	       nxt.at<Vec3b>(i,j)[0]+=src.at<Vec3b>(m,n)[0];
	       nxt.at<Vec3b>(i,j)[1]+=src.at<Vec3b>(m,n)[1];
	       nxt.at<Vec3b>(i,j)[2]+=src.at<Vec3b>(m,n)[2];
	     }
	   }
	 }
	 nxt.at<Vec3b>(i,j)[0]=nxt.at<Vec3b>(i,j)[0]/(VAL*VAL);
	 nxt.at<Vec3b>(i,j)[1]=nxt.at<Vec3b>(i,j)[1]/(VAL*VAL);
	 nxt.at<Vec3b>(i,j)[2]=nxt.at<Vec3b>(i,j)[2]/(VAL*VAL);
       }
     }
	 
     imshow("OP",nxt);
     waitKey(0);
 

   
  return 0;
}

   
