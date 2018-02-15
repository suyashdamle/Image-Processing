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


Mat src,op;

int isred(Mat G, int i, int j){
  if(G.at<Vec3b>(i,j)[0]>100 && G.at<Vec3b>(i,j)[1]>100)
    return 1;
  else return 0;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata){
  
  if (event==EVENT_LBUTTONDOWN) {
  point beg;
  op=src.clone();
  //imshow("OP",src);
  
 
    beg.i=y;
    beg.j=x;
    deque<point>Q;//double ended queue
    point r,u;
    int i1,i2,j1,j2;
    r.i=beg.i;
    r.j=beg.j;
    Q.push_back(r);
    //	n_blobs++;
    while(!Q.empty()) {
      //BFS
      u=Q.front();
      Q.pop_front();
      i2=u.i;
      j2=u.j;
      //cout<<"ENT ";
      
      i1=i2;j1=j2-1;
      if(i1>0 && i1<src.rows && j1>0 && j1<src.cols) {
	if(isred(op,i1,j1)){
	  op.at<Vec3b>(i1,j1)[0]=0;
	  op.at<Vec3b>(i1,j1)[1]=0;
	  r.i=i1;
	  r.j=j1;
	  Q.push_back(r);
	}
      }
      
      
      i1=i2-1;j1=j2;
      if(i1>0 && i1<src.rows && j1>0 && j1<src.cols){
	if(isred(op,i1,j1)){
	  op.at<Vec3b>(i1,j1)[0]=0;
	  op.at<Vec3b>(i1,j1)[1]=0;
	  r.i=i1;
	  r.j=j1;
	  Q.push_back(r);
	}
      }
      
      i1=i2+1;j1=j2;
      if(i1>0 && i1<src.rows && j1>0 && j1<src.cols){
	if(isred(op,i1,j1)){
	  op.at<Vec3b>(i1,j1)[0]=0;
	  op.at<Vec3b>(i1,j1)[1]=0;
	  r.i=i1;
	  r.j=j1;
	  Q.push_back(r);
	}
      }
            
      i1=i2;j1=j2+1;
      if(i1>0 && i1<src.rows && j1>0 && j1<src.cols){
	if(isred(op,i1,j1)){
	  op.at<Vec3b>(i1,j1)[0]=0;
	  op.at<Vec3b>(i1,j1)[1]=0;
	  r.i=i1;
	  r.j=j1;
	  Q.push_back(r);
	}
      }
      
     
    }
    src=op.clone();
    imshow("IP",op);
    
   }
    
    
   
}









int main(){

  src=imread("draw.png",1);

  
  namedWindow( "IP",WINDOW_AUTOSIZE );
  imshow("IP",src);
  setMouseCallback("IP",CallBackFunc,NULL);
  //  CallBackFunc(0,0,0,0,NULL);
  waitKey(0);
  return 0;
}
