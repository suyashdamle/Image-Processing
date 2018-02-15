#include <iostream>
#include <stdio.h>
#include<deque>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
 #include <opencv2/objdetect/objdetect.hpp>
#include<string>
#include<sstream>
using namespace cv;
using namespace std;


CascadeClassifier face_cscd;

Mat img;
int main(){
  int count_person=0;
  vector<Rect>face1;
  vector<Rect>face2;
  //face2[0].x=face2[1].x=1000;
  int prev=1000;
  VideoCapture vid("video.mp4");
  //int LV=150;
  if(!face_cscd.load("haarcascade_frontalface_alt.xml")){
    cout<<"NOT LOADED"<<endl;
  }
  while(vid.isOpened()) {
     
     int count=0;
     while(count<10){
       vid>>img;
       count ++;
       }
     // Mat img=imread("faces.jpg");
     
     face_cscd.detectMultiScale(img,face1,1.3, 7);
     
     for(int i=0;i<face1.size();i++){
       if(prev > face1[i].x){
	   count_person++;
	   prev=face1[i].x;
       }
       else
	 prev = face1[i].x;
	 
       Point p1(face1[i].x,face1[i].y);
       Point p2(face1[i].x+face1[i].height,face1[i].y+face1[i].width);
       rectangle(img,p1,p2,Scalar(0,255,0),2);
     }
    
     // cout<<"DONE"<<endl;
     
     namedWindow("IP",WINDOW_AUTOSIZE);
     
     Point P(100,200);
     cout<<"NO. OF PERSONS="<<count_person<<endl;
     char c=(char)(count_person)+'0';
     cout<<c<<endl;
     string out=("NO. OF VISITORS=");out[16]=c;out[17]='\0';
     putText(img,out,P,FONT_HERSHEY_DUPLEX,2,Scalar(255,255,255),3);
     imshow("IP",img);
     waitKey(10);
    
     }
   
}
