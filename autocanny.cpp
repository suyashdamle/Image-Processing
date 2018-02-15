#include <iostream>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

int main(){
 namedWindow( "OP", WINDOW_AUTOSIZE );
 int LV;
 Mat src=imread("img.jpg",0);
 blur(src,src,Size(3,3));//blur( src_gray, detected_edges, Size(3,3) );

 while(1){
   createTrackbar("VAL","OP",&LV,255);
   Mat nxt(src.rows,src.cols,CV_8UC1,Scalar(0));
   Canny(src,nxt,LV,3,3);//Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );

   imshow("OP",nxt);
     waitKey(2);
 

     }
  return 0;
}

