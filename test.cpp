#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main ( int argc, char** argv )
{

    cv::Mat a;
    a = (cv::Mat_<int>(13,2) <<  1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6);
    for(int i=0; i<13; i++){
     for(int j=0; j<2; i++){
      std::cout << a.at<int>(i,j);
     }
    std::cout <<std::endl;
    }
   return 0;
}
