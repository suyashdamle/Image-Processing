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

typedef struct _point{
  unsigned int i,j;
}point;


int isred(Mat G, int i, int j){
  if(G.at<Vec3b>(i,j)[2]>180 && G.at<Vec3b>(i,j)[0]<50 && G.at<Vec3b>(i,j)[1]<50)
    return 1;
  else return 0;
}

int main(){

  
  Mat src=imread("try4.jpg",1);
  Mat op(src.rows,src.cols,CV_8UC1,Scalar(0));
  int n_blobs;
  deque<point>Q;//double ended queue
  point r,u;
  int i1,i2,j1,j2;
  n_blobs=0;
  for(int i=0;i<src.rows;i++){
    for(int j=0;j<src.cols;j++){
      if(isred(src,i,j) && op.at<uchar>(i,j)==0) {//one new red discovered
	op.at<uchar>(i,j)=255;
	r.i=i;
	r.j=j;
	Q.push_back(r);
	n_blobs++;
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

  cout<<"NO OF BLOBS="<<n_blobs<<endl<<endl;
  namedWindow( "IP", WINDOW_NORMAL );
  imshow("IP",src);
  namedWindow( "OP", WINDOW_NORMAL );
  imshow("OP",op);
  waitKey(0);
  
  return 0;
}



 
 
	   
	 
	   
	 
	 
     
