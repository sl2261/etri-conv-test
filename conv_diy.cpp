#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int your_conv( cv::Mat src, cv::Mat dst, cv::Mat kernel, int stride, int paddin )
{
    int src_height = src.rows;
    int src_width = src.cols;

    int kernel_height = kernel.rows;
    int kernel_width = kernel.cols;
 
    int dst_height = (src_height+2*paddin-kernel)/stride + 1;
    int dst_width = (src_width+2*paddin-kernel)/stride + 1;

    // src.ptr<unsigned char>(i)[ calculate INDEX ]
     for(int i=0; i<dst_height; i++){
      for(int j=0; j<dst_width; j++){
       for(int k=0; k<kernel_height; k++){
        for(int l=0; l<kernel_width; l++){ 
         dst.at<Vec3b>(i,j)[0] =dst.at<Vec3b>(i,j)[0]+ src.at<Vec3b>(l,k)[0]*kernel.at<Vec3b>(l+i,k+j)[0];
         dst.at<Vec3b>(i,j)[1] =dst.at<Vec3b>(i,j)[1]+ src.at<Vec3b>(l,k)[1]*kernel.at<Vec3b>(l+i,k+j)[1];
         dst.at<Vec3b>(i,j)[2] =dst.at<Vec3b>(i,j([2]+ src.at<Vec3b>(l,k)[2]*kernel.at<Vec3b>(l+i,k+j)[2];
        }
       }
      }
     }

    // if success
    return 0;

    // if fail - in the case of wrong parameters...
    // return -1
}

int main ( int argc, char** argv )
{
    if (argc < 2) {
        std::cout << "no filename given." << std::endl;
        std::cout << "usage: " << argv[0] << " image" << std::endl;
        return -1;
    }

    cv::Mat src, kernel, dst;

    // Load an image
    src = cv::imread( argv[1] );
    if( !src.data )  { return -1; }

    // Make filter
    kernel = (cv::Mat_<float>(3, 3) << 0, -1, -1, -1, 8, -1, -1, -1, -1);


    // Run 2D filter
    //cv::filter2D(src, dst, -1 , kernel, cv::Point( -1, -1 ), 0, cv::BORDER_DEFAULT );

    // ---------------------------
    your_conv(src,dst,kernel,1,0);
    // ---------------------------

    cv::namedWindow( "filter2D Demo", cv::WINDOW_AUTOSIZE );
    cv::imshow( "filter2D Demo", dst );

    cv::waitKey(0);
    return 0;
}
