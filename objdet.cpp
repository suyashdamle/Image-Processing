#include <iostream>
#include <stdio.h>
#include<deque>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;


int main(){

  //vector<vector<Point> >contour;
  //vector<Vec4i>hir;
  
 
  //VideoCapture vid(0);
  int ans;
  Mat img;
  Mat tepl;
  //int LV=150;
   //while(vid.isOpened()) {
   //vid>>img;
  img=imread("img.jpg",1);
  tepl=imread("imgt.jpg",1);
  int res_col=img.cols-tepl.cols+1;
  int res_row=img.rows-tepl.rows+1;
  namedWindow("IP",WINDOW_AUTOSIZE);
  namedWindow("TEMPL",WINDOW_AUTOSIZE);
  namedWindow("OP",WINDOW_AUTOSIZE);

  imshow("IP",img);
  imshow("TEMPL",tepl);
  Mat op(res_row,res_col,CV_32FC1,Scalar(0));
  // op=img.clone();
  matchTemplate(img,tepl,op,CV_TM_SQDIFF_NORMED);

  double minVal; double maxVal; Point minLoc; Point maxLoc;
  Point matchLoc;
 
  
  minMaxLoc( op, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
 matchLoc=minLoc;
 // rectangle(op,matchLoc,Point(matchLoc.x+tepl.cols,matchLoc.y+tepl.rows),Scalar(0,0,0),1,8,0);

  rectangle(img,matchLoc,Point(matchLoc.x+tepl.cols,matchLoc.y+tepl.rows),Scalar(0,0,0),2);
  imshow("OP",img);
  waitKey(0);
}
  

  
