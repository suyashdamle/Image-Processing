#include <iostream>
#include <stdio.h>
#include<deque>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

# define THD 1             //threshold on max dist abt. a line segment      
# define THL 31          //threshold on the min no of points to be present for it to be called a "line"


int main(){
  int ptdist;
  Mat src=imread("human.jpg",0);
  Mat op(src.rows,src.cols,CV_8UC1,Scalar(0));
  //to binary
  for(int i=0;i<src.rows;i++){
    for(int j=0;j<src.cols;j++){
      int avg=src.at<uchar>(i,j);
      op.at<uchar>(i,j)=(avg<150)?0:255;
    }
  }

  src=op.clone();
  namedWindow("IP",WINDOW_NORMAL);

  
  int maxd=sqrt(src.rows*src.rows + src.cols*src.cols);
  short int data[maxd][180];
  for(int i=0;i<maxd;i++){
    for (int j=0;j<180;j++){
      data[i][j]=0;
    }
  }

  for(int m=0;m<src.rows;m++){//row no
    for(int n=0;n<src.cols;n++) {//col no
      if(src.at<uchar>(m,n)==255){//this point "exists" in the image
	for(int i=0;i<maxd;i++){//perp dist
	  for(int j=0;j<180;j++){   //generate data[i][(3.14*j)/180] 
	    ptdist=abs(n*cos(j*3.14/180)+m*sin(j*3.14/180)-i);
	    if(ptdist<THD)
	      data[i][j]++;
	  }
	}
      }
    }
  }

  //cout<<"DONE2"<<endl<<endl;
  Mat op2(src.rows,src.cols,CV_8UC1,Scalar(0));
  op=op2.clone();
  
  for (int i=0;i<maxd; i++){//perp dist
    for (int j=0;j<180;j++){//angle
      if(data[i][j]>=THL) {         //retain
	//cout<<"CRSD:"<<i<<","<<j<<endl;
	for(int m=0;m<src.rows;m++){//row
	  for (int n=0;n<src.cols;n++){//col
	    
	    // if(src.at<uchar>(m,n)==255){//this point "exists" in the image
	      
	      ptdist=abs(n*cos(j*3.14/180)+m*sin(j*3.14/180)-i);
	      if(ptdist<THD)
		op.at<uchar>(m,n)=255;
	    }
	  }
	//}
      }
      
    }
  }
  
  
  imshow("IP",src);  
  namedWindow("OP",WINDOW_NORMAL);
  imshow("OP",op);
  
  waitKey(0);
  return 0;
}

	  
  

  
