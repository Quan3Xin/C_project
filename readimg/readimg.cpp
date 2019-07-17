#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>

using  namespace cv;
using  namespace std;

int main()
{
    Mat A,C ;
    A = imread("123.png");
    Mat B(A);

    C = A;
    /*
    imshow("A",A);
    imshow("B",B);
    imshow("C",C);
    imshow("M", M);
    Mat M(4, 4, CV_8UC(2));
    
    for(int i =0 ; i<M.rows; i++){
        for (int j=0; j<M.cols;j++){
            M.at<u_char>(i, j) = i*j/20;
        }
    }
   cout << "m = " << endl << ""<<C<<endl<<endl;
    int idx = 0;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    for( ; idx >= 0; idx = hierarchy[idx][0] )
    {
        Scalar color( rand()&255, rand()&255, rand()&255 );
        drawContours( dst, contours, idx, color, FILLED, 8, hierarchy );
    }
    namedWindow( "Components", 1 );
    imshow( "Components", dst );
    */
    Point a = Point(0,0);
    Point b = Point(A.cols / 2, A.rows /2 );
    Mat dst = Mat::zeros(A.rows, A.cols, CV_8UC3);
    Rect select;
    //rectangle(dst,select, Scalar(0,0,255), 3,8,0);
    circle(dst, b, 30, Scalar(0,0,255));
    //circle(dst,select, Scalar(0,0,255), 3,8,0);
    //line(dst, a,b,Scalar(0,0,255));
    
    imshow("m", dst);
    waitKey();
    return 0;
}
