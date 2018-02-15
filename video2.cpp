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



int isred(Mat G, int i, int j){
  if(G.at<Vec3b>(i,j)[2]>90 && G.at<Vec3b>(i,j)[0]<60 && G.at<Vec3b>(i,j)[1]<60)
    return 1;
  else return 0;
}




int main(){
  namedWindow("OP",WINDOW_NORMAL);
  namedWindow("IP",WINDOW_NORMAL);
  VideoCapture vid(0);
  //Mat img;
  // int LV=200;
  while(vid.isOpened()) {
    Mat src;
    vid>>src;
    Mat op(src.rows,src.cols,CV_8UC1,Scalar(0));
    
    deque<point>Q;//double ended queue
    point r,u;
    int i1,i2,j1,j2;
    for(int i=0;i<src.rows;i++){
      for(int j=0;j<src.cols;j++){
	if(isred(src,i,j) && op.at<uchar>(i,j)==0) {//one new red discovered
	  op.at<uchar>(i,j)=255;
	  r.i=i;
	  r.j=j;
	  Q.push_back(r);
	  while(!Q.empty()) {
	    //BFS
	    u=Q.front();
	    Q.pop_front();
	    i2=u.i;
	  j2=u.j;
	  
	  i1=i2-1;j1=j2-1;
	  if(i1>0 && i1<src.rows && j1>0 && j1<src.cols){
	    if(isred(src,i1,j1) && op.at<uchar>(i1,j1)==0) {
	      //cout<<"ENT1 ";
	      op.at<uchar>(i1,j1)=255;
	      r.i=i1;
	      r.j=j1;
	      Q.push_back(r);
	    }
	  }
	  
	  i1=i2;j1=j2-1;
	  if(i1>0 && i1<src.rows && j1>0 && j1<src.cols){
	    if(isred(src,i1,j1) && op.at<uchar>(i1,j1)==0){
	      // cout<<"ENT2 ";
	      op.at<uchar>(i1,j1)=255;
	      r.i=i1;
	      r.j=j1;
	      Q.push_back(r);
	    }
	  }
	  
	  i1=i2+1;j1=j2-1;
	  if(i1>0 && i1<src.rows && j1>0 && j1<src.cols){
	    if(isred(src,i1,j1) && op.at<uchar>(i1,j1)==0){
	      op.at<uchar>(i1,j1)=255;
	      r.i=i1;
	      r.j=j1;
	      Q.push_back(r);
	    }
	  }
	  
	  i1=i2-1;j1=j2;
	  if(i1>0 && i1<src.rows && j1>0 && j1<src.cols){
	    if(isred(src,i1,j1) && op.at<uchar>(i1,j1)==0){
	      op.at<uchar>(i1,j1)=255;
	      r.i=i1;
	      r.j=j1;
	      Q.push_back(r);
	    }
	  }
	 
	 i1=i2+1;j1=j2;
	 if(i1>0 && i1<src.rows && j1>0 && j1<src.cols){
	   if(isred(src,i1,j1) && op.at<uchar>(i1,j1)==0){
	     op.at<uchar>(i1,j1)=255;
	     r.i=i1;
	     r.j=j1;
	     Q.push_back(r);
	   }
	 }
	 
	 i1=i2-1;j1=j2+1;
	 if(i1>0 && i1<src.rows && j1>0 && j1<src.cols){
	   if(isred(src,i1,j1) && op.at<uchar>(i1,j1)==0){
	     // cout<<"ENT4 ";
	     op.at<uchar>(i1,j1)=255;
	     r.i=i1;
	     r.j=j1;
	     Q.push_back(r);
	   }
	 }
	 
	 i1=i2;j1=j2+1;
	 if(i1>0 && i1<src.rows && j1>0 && j1<src.cols){
	   if(isred(src,i1,j1) && op.at<uchar>(i1,j1)==0){
	     op.at<uchar>(i1,j1)=255;
	     r.i=i1;
	     r.j=j1;
	     Q.push_back(r);
	   }
	 }

	 i1=i2+1;j1=j2+1;
	 if(i1>0 && i1<src.rows && j1>0 && j1<src.cols){
	   if(isred(src,i1,j1) && op.at<uchar>(i1,j1)==0){
	     op.at<uchar>(i1,j1)=255;
	     r.i=i1;
	     r.j=j1;
	     Q.push_back(r);
	   }
	 }
	  }
	  
	  
	}
      }
    }
    imshow("IP",src);
    imshow("OP",op);
    waitKey(20);
    
  }
  
}

