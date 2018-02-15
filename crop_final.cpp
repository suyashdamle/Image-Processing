#include <iostream>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;
int avgr,avgg,avgb;
int bdry_l,bdry_u,bdry_lft,bdry_r;

int is_page(Mat ip,int i, int j){
  if(ip.at<Vec3b>(i,j)[2] < 0.7*avgr ||ip.at<Vec3b>(i,j)[0] < 0.7*avgb ||ip.at<Vec3b>(i,j)[1] < 0.7*avgg)
    return 0;
  else if(ip.at<Vec3b>(i,j)[2] > 1.4*avgr ||ip.at<Vec3b>(i,j)[0] > 1.4*avgb ||ip.at<Vec3b>(i,j)[1] > 1.4*avgg)
    return 0;
  else return 1;
}

int is_page(Mat ip, int data, char c){
  int sum=0;
  if(c=='R') {
    for (int col=0;col<ip.cols;col++){
      if(is_page(ip,data,col))
	sum++;
    }
    if(sum>0.5*ip.cols)
      return 1;
    return 0;
  }
  else if(c=='C'){
    for(int row=0;row<ip.rows;row++){
      if(is_page(ip,row,data))
	sum++;
    }
    if(sum>0.5*ip.rows)
      return 1;
    return 0;
  }
}


void crop_sides(Mat ip, int k){
  /*LOWER*/
  bdry_l=ip.rows;
  if(!is_page(ip,ip.rows-1,'R')){
    int row=ip.rows-1;
    while(row>0){
      if(is_page(ip,row,'R')){
	bdry_l=row+1;
	break;
      }
      row--;
    }
  }
  /*UPPER*/
  bdry_u=0;
  if(!is_page(ip,0,'R')){
    int row=0;
    while(row<ip.rows){
      if(is_page(ip,row,'R')){
	bdry_u=row;
	break;
      }
      row++;
    }
  }
  /*LEFT*/
  bdry_lft=0;
  if(!is_page(ip,0,'C')){
   int col=0;
    while(col<ip.cols){
      if(is_page(ip,col,'C')){
	bdry_lft=col;
	break;
      }
      col++;
    }
  }
  /*RIGHT*/
  bdry_r=ip.cols-1;
  if(!is_page(ip,ip.cols-1,'C')){
    int col=ip.cols-1;
    while(col>0){
      if(is_page(ip,col,'C')){
	bdry_r=col;
	break;
      }
      col--;
    }
  }

  


  /*GENERATING OUTPUT IMAGE-----NOT RESIZED*/
  int n_rows=bdry_l-bdry_u;
  int n_cols=bdry_r-bdry_lft;
  Mat op(n_rows,n_cols,CV_8UC3,Scalar(0,0,0));
  for (int i=bdry_u;i<bdry_l;i++){
    for(int j=bdry_lft;j<bdry_r;j++){
      op.at<Vec3b>(i-bdry_u,j-bdry_lft)[0]=ip.at<Vec3b>(i,j)[0];
      op.at<Vec3b>(i-bdry_u,j-bdry_lft)[1]=ip.at<Vec3b>(i,j)[1];
      op.at<Vec3b>(i-bdry_u,j-bdry_lft)[2]=ip.at<Vec3b>(i,j)[2];
    }
  }
  imwrite(format("op%d.jpg",k),op);

}


int main(){
  for(int k=1;k<=1;k++){
    Mat ip=imread(format("test%d.jpg",k),1);
  int sumr,sumg,sumb;
  sumr=sumb=sumg=0;
  for(int i=0.1*ip.rows;i<0.9*ip.rows;i++){
    for(int j=0.1*ip.cols;j<0.9*ip.cols;j++){
      sumr+=ip.at<Vec3b>(i,j)[2];
      sumb+=ip.at<Vec3b>(i,j)[0];
      sumg+=ip.at<Vec3b>(i,j)[1];
    }
  }

  avgr=float(sumr)/(ip.rows*ip.cols*0.64);
  avgg=float(sumg)/(ip.rows*ip.cols*0.64);
  avgb=float(sumb)/(ip.rows*ip.cols*0.64);


  crop_sides(ip,k);

    }

}

/* cv::Mat input_Mat = cv::imread( cv::format( "%s/image%03d.png", file_directory, i ), CV_LOAD_IMAGE_ANYCOLOR );
        cv::namedWindow ("input_image", CV_WINDOW_AUTOSIZE);
        cv::imshow( "input_image", input_Mat);*/
