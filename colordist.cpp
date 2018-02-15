#include <iostream>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

int main(){
 Mat src=imread("blue.jpg",1);
 int rmax,gmax,bmax,max,scale;
 int G[256],R[256],B[256];
 for(int i=0;i<256;i++){
   G[i]=R[i]=B[i]=0;
 }


  for(int i=0;i<src.rows;i++){
    for(int j=0;j<src.cols;j++){
      B[src.at<Vec3b>(i,j)[0]]++;
      G[src.at<Vec3b>(i,j)[1]]++;
      R[src.at<Vec3b>(i,j)[2]]++;
    }
 }
  rmax=bmax=gmax=0;

  for(int i=0;i<256;i++){
    if(R[i]>rmax)
      rmax=R[i];
    if(B[i]>bmax)
      bmax=B[i];
    if(G[i]>gmax)
      gmax=G[i];
  }
 
 if(rmax>bmax){
   if(rmax>gmax)
     max=rmax;
   else
     max=gmax;
 }
 else if(bmax>rmax){
   if(bmax>gmax)
     max=bmax;
   else
     max=gmax;
 }
 scale=max/300;      //dividing by this scale
 cout<<"DONE="<<endl;
 


 int rowmax=(max)/scale+20;
 Mat op(rowmax,300,CV_8UC3,Scalar(0,0,0));
 for(int i=0;i<256;i++){
   op.at<Vec3b>(rowmax-B[i]/scale-5,i)[0]=255;//BLUE
   op.at<Vec3b>(rowmax-G[i]/scale-5,i)[1]=255;//GREEN
   op.at<Vec3b>(rowmax-R[i]/scale-5,i)[2]=255;//RED
 }
 namedWindow( "OP", WINDOW_NORMAL );
  imshow( "OP",op );
  waitKey(0);
}



 
 
 
