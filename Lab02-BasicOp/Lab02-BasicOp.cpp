// Lab02-BasicOp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/cvconfig.h>
#include <opencv2/imgproc.hpp>
#include <iostream>

	using namespace std;
	using namespace cv;

	void drawImage(IplImage *img)
	{
		cvRectangle(img, cvPoint(0, 0), cvPoint(200, 200), CV_RGB(60, 200, 60), -1);
	}

	int _tmain(int argc, _TCHAR* argv[])
	{
		Mat img = imread("C:\\opencv\\sources\\samples\\data\\ml.png");
		Mat hsv;
		Mat img2;
		Mat result1;
		Mat result2;
		cvtColor(img, hsv, COLOR_BGR2HSV);


		Scalar minGreen = Scalar(40, 100, 100);
		Scalar maxGreen = Scalar(80, 255, 255);

		namedWindow("Image");
		imshow("Image", img);
		waitKey();

		inRange(hsv, minGreen, maxGreen, result1);


		bitwise_and(img, img, result2, result1);

		imshow("Image", img);
		namedWindow("hsv");
		imshow("hsv", hsv);
		namedWindow("Result");
		imshow("Result", result2);
		waitKey();

		return 0;
	}

