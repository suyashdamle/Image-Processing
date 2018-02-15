#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

#define k_size 3


void gaussian(Mat src,Mat op);
int tokeep(Mat G, short int **ang,int i,int j);

int main(){
  int bysum,bxsum,L;
  Mat src=imread("img.jpg",0);
  Mat op(src.rows,src.cols,CV_8UC1,Scalar(0));
  Mat Sobop(src.rows,src.cols,CV_8UC1,Scalar(0));

  gaussian(src,Sobop);
  gaussian(Sobop,Sobop);
  gaussian(Sobop,Sobop);
  gaussian(Sobop,Sobop);
  gaussian(Sobop,Sobop);

  

  Mat src1=src.clone();//now contains src
  src=Sobop.clone();



  //Sobel
  
  int Kx[3][3]={{-1,0,1},
		 {-2,0,2},
		 {-1,0,1}};
  int Ky[3][3]={{1,2,1},
		{0,0,0},
		{-1,-2,-1}};

  int bsumy,bsumx;
  float th;
  
  //namedWindow( "IP", WINDOW_AUTOSIZE );
  //imshow("IP",src);


  Mat G(src.rows,src.cols,CV_8UC1,Scalar(0));
  for(int i=0;i<=src.rows-k_size;i++) {
    for(int j=0;j<=src.cols-k_size;j++){
      //working for rectangle beginning at pixel(i,j)
      bsumx=0;
      bsumy=0;
      for(int l=i;l<i+k_size;l++){
	for(int m=j;m<j+k_size;m++){
	  bsumx+=src.at<uchar>(l,m)*Kx[l-i][m-j];
	  bsumy+=src.at<uchar>(l,m)*Ky[l-i][m-j];
	}
      }
      G.at<uchar>(i+k_size/2,j+k_size/2)=sqrt(bsumx*bsumx+bsumy*bsumy);
    }
  }


  
  namedWindow( "SOBEL", WINDOW_NORMAL );
  imshow("SOBEL",G);

  for(int i=0;i<=src.rows-k_size;i++) {
    for(int j=0;j<=src.cols-k_size;j++) {
      //working for rectangle beginning at pixel(i,j)
      bsumx=0;
      bsumy=0;
      for(int l=i;l<i+k_size;l++){
	for(int m=j;m<j+k_size;m++){
	  bsumx+=src.at<uchar>(l,m)*Kx[l-i][m-j];
	  bsumy+=src.at<uchar>(l,m)*Ky[l-i][m-j];
	}
      }

      if(bsumx==0)
	th=0;
      else{
      th=atan(bsumy/bsumx)*(180/3.14);
      if (th<0)
	th=180+th;
      //angle approximation
      if (th>=0 && th<=22)
	th=0;
      if(th>22 && th<=67)
	th=45;
      if(th>67 && th<=112)
	th=90;
      if(th>112)
	th=135;
	    
      }

      
      int ans=0;
 if(th==0){
    if(G.at<uchar>(i,j)>G.at<uchar>(i,j-1) && G.at<uchar>(i,j)>G.at<uchar>(i,j+1))
      ans= 1;
  }
  if(th==45){
    if(G.at<uchar>(i,j)>G.at<uchar>(i+1,j+1) && G.at<uchar>(i,j)>G.at<uchar>(i-1,j-1))
      ans= 1;
    
  }
  if(th==90){
    if(G.at<uchar>(i,j)>G.at<uchar>(i-1,j) && G.at<uchar>(i,j)>G.at<uchar>(i+1,j))
      ans= 1;
    
  }
  if(th==135){
    if(G.at<uchar>(i,j)>G.at<uchar>(i-1,j+1) && G.at<uchar>(i,j)>G.at<uchar>(i+1,j-1))
      ans= 1;
    
  }
  
  if (ans==0)
    op.at<uchar>(i,j)=0;
  else op.at<uchar>(i,j)=G.at<uchar>(i,j);
    }
  }

  namedWindow( "OP", WINDOW_NORMAL );
  Mat op2(src.rows,src.cols,CV_8UC1,Scalar(0));
  int LV,HV;
  LV=HV=150;
  while(1){
     createTrackbar("LVAL","OP",&LV,255);
     createTrackbar("HVAL","OP",&HV,255);
     for(int i=0;i<G.rows;i++){
       for(int j=0;j<G.cols;j++){
	 if(op.at<uchar>(i,j) > LV && op.at<uchar>(i,j) < HV)
	   op2.at<uchar>(i,j)=255;
	 else op2.at<uchar>(i,j) =0;
       }
     }
     
     
     
     imshow("OP",op2);
    waitKey(2);
   }
    return 0;
}






 










void gaussian(Mat src,Mat op){ 
  int K[k_size][k_size]={{1,2,1},
			 {2,4,2},
			 {1,2,1}};;    
  int rsum,gsum,bsum;
 
  for(int i=0;i<=src.rows-k_size;i++){
    for(int j=0;j<=src.cols-k_size;j++){
      //working for rectangle beginning at pixel(i,j)
      rsum=bsum=gsum=0;
      for(int l=i;l<i+k_size;l++){
	for(int m=j;m<j+k_size;m++){
	  bsum+=src.at<uchar>(l,m)*K[l-i][m-j];
	}
      }
      op.at<uchar>(i+k_size/2,j+k_size/2)=bsum/16;
    }
  }
}


