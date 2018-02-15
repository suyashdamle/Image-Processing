#include <iostream>
#include <stdio.h>
#include<deque>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;



int main(){
  namedWindow("IP",WINDOW_NORMAL);
  VideoCapture vid(0);
  int ans;
  Mat img;
  int LV=200;
  while(vid.isOpened()) {
    vid>>img;
    cvtColor(img,img,CV_RGB2GRAY);
	     //blur(src,src,Size(3,3));
     Canny(img,img,LV,3,3);
    imshow("IP",img);
    ans=waitKey(2);
    if((char)ans=='q' || char(ans)=='Q'){
      imwrite("MYIMG.jpg",img);
    }
  }
  return 0;
}
    
