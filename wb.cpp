#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

int main()
{
  Mat var1(200,400,CV_8UC1,Scalar(0));
  for(int i=0;i<var1.rows;i++){
    for(int j=0;j<var1.cols/2;j++){
      var1.at<uchar>(i,j)=255;
    }
  }
  for(int i=0;i<var1.rows;i++){
    for(int j=var1.cols/2;j<var1.cols;j++){
      var1.at<uchar>(i,j)=0;
    }
  }
  namedWindow( "Display window", WINDOW_NORMAL );
    imshow( "Display window", var1 );  
  waitKey();
    return 0;


}
