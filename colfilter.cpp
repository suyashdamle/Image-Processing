#include <iostream>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

int main(){
  int RMAX,RMIN,RTOL,RVAL;RMAX=255;
  int GMAX,GMIN,GTOL,GVAL;GMAX=0;
  int BMAX,BMIN,BTOL,BVAL;BMAX=0;
  namedWindow( "OP", WINDOW_AUTOSIZE );
  RTOL=BTOL=GTOL=255;
  RVAL=BVAL=GVAL=100;
  Mat src=imread("img.jpg",1);
  Mat flt(src.rows,src.cols,CV_8UC3,Scalar(0,0,0));
  while(1){
     createTrackbar("RVAL","OP",&RVAL,255);
     createTrackbar("GVAL","OP",&GVAL,255);
     createTrackbar("BVAL","OP",&BVAL,255);
     createTrackbar("RTOL","OP",&RTOL,255);
     createTrackbar("GTOL","OP",&GTOL,255);
     createTrackbar("BTOL","OP",&BTOL,255);
     
     RMIN=RVAL-RTOL;
     RMAX=RVAL+RTOL;
     GMIN=GVAL-GTOL;
     GMAX=GVAL+GTOL;
     BMIN=BVAL-BTOL;
     BMAX=BVAL+BTOL;
  for(int i=0;i<src.rows;i++){
    for(int j=0;j<src.cols;j++){
      if(src.at<Vec3b>(i,j)[2] < RMAX && src.at<Vec3b>(i,j)[2] > RMIN &&
	 src.at<Vec3b>(i,j)[0] < BMAX && src.at<Vec3b>(i,j)[0] > BMIN &&
	 src.at<Vec3b>(i,j)[1] < GMAX && src.at<Vec3b>(i,j)[1] > GMIN) {
	
	flt.at<Vec3b>(i,j)[2]=src.at<Vec3b>(i,j)[2];
	flt.at<Vec3b>(i,j)[0]=src.at<Vec3b>(i,j)[0];
	flt.at<Vec3b>(i,j)[1]=src.at<Vec3b>(i,j)[1];
	
      
      }

      else{
	flt.at<Vec3b>(i,j)[2]=0;
	flt.at<Vec3b>(i,j)[0]=0;
	flt.at<Vec3b>(i,j)[1]=0;
      }
	
    }
  }
  imshow( "OP",flt );

  waitKey(2);
  }
}
