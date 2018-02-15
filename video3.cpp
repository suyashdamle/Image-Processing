#include <iostream>
#include <stdio.h>
#include<deque>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

typedef struct _point{
  unsigned int i,j;
}point;


Mat src;
int h_hi,h_lo,s_hi,s_lo,v_hi,v_lo;



void th_callback(int , void*){
  namedWindow( "OP", WINDOW_NORMAL );
  Mat op(src.rows,src.cols,CV_8UC3,Scalar(0,0,0));
  inRange(src,(v_lo,s_lo,h_lo),(v_hi,s_hi,h_hi),op);
  namedWindow("OP",WINDOW_NORMAL);
  imshow("OP",op);
}


int main(){
  src=imread("img.jpg",1);
  //cvtColor(src,src,CV_RGB2HSV);
    
  namedWindow("IP",WINDOW_NORMAL);
  imshow("IP",src);
  namedWindow("RED",WINDOW_NORMAL);
  // namedWindow("BLUE",WINDOW_NORMAL);
  //namedWindow("GREEN",WINDOW_NORMAL);
  createTrackbar("r_hi","RED",&h_hi,180,th_callback);
  createTrackbar("r_lo","RED",&h_hi,180,th_callback);
  createTrackbar("g_hi","RED",&s_hi,255,th_callback);
  createTrackbar("g_lo","RED",&s_lo,255,th_callback);
  createTrackbar("b_hi","RED",&v_hi,255,th_callback);
  createTrackbar("b_lo","RED",&v_lo,255,th_callback);

  
  
   th_callback(0,0);
  
  while(1){
    int ans;
    ans=waitKey(100);
    if((char)ans==13)  //ENTER key
      break;
  }
  return 0;
}
