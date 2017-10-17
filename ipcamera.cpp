#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	const std::string videoStreamAddress = "http://128.61.56.129:8080/video";

	VideoCapture cap; // open the default camera
	cap.open(videoStreamAddress);

	if (!cap.isOpened()) // check if we succeeded
		return -1;
	Mat edges;
	namedWindow("IpCam stream", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		imshow("IpCam stream", frame);
		if (waitKey(30) >= 0)
			break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}
