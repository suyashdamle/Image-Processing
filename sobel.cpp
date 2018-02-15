#include <iostream>
#include <stdio.h>
#include <math.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

#define k_size 3

int main(){
  int Kx[3][3]={{-1,0,1},
		 {-2,0,2},
		 {-1,0,1}};
  int Ky[3][3]={{1,2,1},
		{0,0,0},
		{-1,-2,-1}};

  int rsumx,gsumx,bsumx;
  int rsumy,gsumy,bsumy;
  
  Mat src=imread("img.jpg",1);
  //namedWindow( "IP", WINDOW_AUTOSIZE );
  //imshow("IP",src);
  
    Mat G(src.rows,src.cols,CV_8UC3,Scalar(0,0,0));
    for(int i=0;i<=src.rows-k_size;i++){
      for(int j=0;j<=src.cols-k_size;j++){
      //working for rectangle beginning at pixel(i,j)
	rsumx=bsumx=gsumx=0;
	rsumy=bsumy=gsumy=0;
	for(int l=i;l<i+k_size;l++){
	  for(int m=j;m<j+k_size;m++){
	    bsumx+=src.at<Vec3b>(l,m)[0]*Kx[l-i][m-j];
	    gsumx+=src.at<Vec3b>(l,m)[1]*Kx[l-i][m-j];
	    rsumx+=src.at<Vec3b>(l,m)[2]*Kx[l-i][m-j];
	    bsumy+=src.at<Vec3b>(l,m)[0]*Ky[l-i][m-j];
	    gsumy+=src.at<Vec3b>(l,m)[1]*Ky[l-i][m-j];
	    rsumy+=src.at<Vec3b>(l,m)[2]*Ky[l-i][m-j];
	  }
	}
	G.at<Vec3b>(i+k_size/2,j+k_size/2)[0]=sqrt(bsumx*bsumx+bsumy*bsumy);
	G.at<Vec3b>(i+k_size/2,j+k_size/2)[1]=sqrt(gsumx*gsumx+gsumy*gsumy);
	G.at<Vec3b>(i+k_size/2,j+k_size/2)[2]=sqrt(rsumx*rsumx+rsumy*rsumy);
      }
    }
    namedWindow( "OP", WINDOW_NORMAL );
    imshow("OP",G);
    waitKey(0);
    return 0;
}

  
