#include <iostream>
#include <stdio.h>
#include<deque>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
 #include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;


CascadeClassifier face_cscd;

Mat img;
int main(){
  int count_person=0;
  vector<Rect>face1;
  vector<Rect>face2;
  //face2[0].x=face2[0].y=face2[1].x=face1[1].y=1000;
  
   VideoCapture vid(0);
  //int LV=150;
  if(!face_cscd.load("haarcascade_frontalface_alt.xml")){
    cout<<"NOT LOADED"<<endl;
  }
  while(vid.isOpened()) {
     
     int count=0;
     while(count<12){
       vid>>img;
       count ++;
       }
     //  Mat img=imread("faces.jpg");
     
     face_cscd.detectMultiScale(img,face1,1.3, 2);
     
     for(int i=0;i<face1.size();i++){
       /*  if(face2[0].x > face1[].x)
	 count_person++;*/
       Point p1(face1[i].x,face1[i].y);
       Point p2(face1[i].x+face1[i].height,face1[i].y+face1[i].width);
       rectangle(img,p1,p2,Scalar(0,0,255),2);
     }
    
     
     
     namedWindow("IP",WINDOW_NORMAL);
     imshow("IP",img);
     //face2[0].x=face1[0].x;
     //cout<<"NO. OF PERSONS="<<count_person<<endl;
     waitKey(2);
    
     }
   
}
