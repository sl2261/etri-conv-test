#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

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
    kernel = (cv::Mat_<float>(3, 3) << 0, 0, 0, 0, 0, 0, 0, 0, 0);
    // Run 2D filter
    cv::filter2D(src, dst, -1 , kernel, cv::Point( -1, -1 ), 0, cv::BORDER_DEFAULT );

    cv::namedWindow( "filter2D Demo", cv::WINDOW_AUTOSIZE );
    cv::imshow( "filter2D Demo", dst );

    cv::waitKey(0);
    return 0;
}
