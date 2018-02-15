#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

int main()
{
  Mat var1(100,100,CV_8UC3,Scalar(0,0,0));



  
  for(int i=0;i<var1.rows/2;i++){//rows
    for(int j=0;j<var1.cols/2;j++){//cols
      var1.at<Vec3b>(i,j)[3]=255;
}
  }
  /*2*/
  for(int i=0;i<var1.rows/2;i++){//rows
    for(int j=var1.cols/2;j<var1.cols;j++){//cols
      var1.at<Vec3b>(i,j)[1]=255;
    }
  }

  /*3*/
  for(int i=var1.rows/2;i<var1.rows;i++){//rows
    for(int j=0;j<var1.cols/2;j++){//cols
      var1.at<Vec3b>(i,j)[2]=255;
}
  }

  /*4*/
  for(int i=var1.rows/2;i<var1.rows;i++){//rows
    for(int j=var1.cols/2;j<var1.cols;j++){//cols
      var1.at<Vec3b>(i,j)[1]=var1.at<Vec3b>(i,j)[2]=255/2;
}
  }

  
  namedWindow( "Display window", WINDOW_NORMAL );
    imshow( "Display window", var1 );  
  waitKey();
    return 0;

}
