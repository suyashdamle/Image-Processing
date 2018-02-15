#include <iostream>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;
typedef struct _block{
  int r1,r2,c1,c2;
}block;

void wbcolor(Mat var1, block sq, char code){
  int c1=sq.c1;
  int c2=sq.c2;
  int r1=sq.r1;
  int r2=sq.r2;
 
  for(int i=r1;i<r2;i++){
    for(int j=c1;j<c2;j++){
      if(code=='W'){
	var1.at<Vec3b>(i,j)[1]=255;
	var1.at<Vec3b>(i,j)[0]=255;
	var1.at<Vec3b>(i,j)[2]=255;
      }
      else if(code=='B'){
	var1.at<Vec3b>(i,j)[1]=0;
	var1.at<Vec3b>(i,j)[0]=0;
	var1.at<Vec3b>(i,j)[2]=0;
      }
    }
  }
}


int main()
{
  block sq;
  Mat var1(800,800,CV_8UC3,Scalar(0,0,0));
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      sq.r1=i*80;
      sq.r2=sq.r1+80;
      sq.c1=j*80;
      sq.c2=sq.c1+80;
      if((i+j)%2==0){//black color needed
	wbcolor(var1,sq,'B');
      }
      else{
	wbcolor(var1,sq,'W');
      }
    }
  }
  namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow( "Display window", var1 );  
  waitKey();
    return 0;
}

	
