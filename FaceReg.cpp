
/*
* Copyright (c) 2011. Philipp Wagner <bytefish[at]gmx[dot]de>.
* Released to public domain under terms of the BSD Simplified license.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the
*     documentation and/or other materials provided with the distribution.
*   * Neither the name of the organization nor the names of its contributors
*     may be used to endorse or promote products derived from this software
*     without specific prior written permission.
*
*   See <http://www.opensource.org/licenses/bsd-license>
*/
#include <opencv2/core/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>


#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include<time.h>
using namespace cv;
using namespace std;

static void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
	std::ifstream file(filename.c_str(), ifstream::in);
	if (!file) {
		string error_message = "No valid input file was given, please check the given filename.";
		CV_Error(CV_StsBadArg, error_message);
	}
	string line, path, classlabel;
	while (getline(file, line)) {
		stringstream liness(line);
		getline(liness, path, separator);
		getline(liness, classlabel);
		if (!path.empty() && !classlabel.empty()) {
			images.push_back(imread(path, 0));
			/*Mat m = imread(path, 0);
			if (m.empty()) {
			cerr << path << " could not be read!" << endl; return;
			}
			images.push_back(m);*/
			labels.push_back(atoi(classlabel.c_str()));
		}
	}
}

string g_listname_t[] =
{
	"ruby",
	"jasmine",
	"simran"
};

String FaceRecog() {

	// Check for valid command line arguments, print usage
	// if no arguments were given.
	//if (argc != 4) {
	//    cout << "usage: " << argv[0] << " </path/to/haar_cascade> </path/to/csv.ext> </path/to/device id>" << endl;
	//    cout << "\t </path/to/haar_cascade> -- Path to the Haar Cascade for face detection." << endl;
	//    cout << "\t </path/to/csv.ext> -- Path to the CSV file with the face database." << endl;
	//    cout << "\t <device id> -- The webcam device id to grab frames from." << endl;
	//    exit(1);
	//}
	//// Get the path to your CSV:
	//string fn_haar = string(argv[1]);
	//string fn_csv = string(argv[2]);
	//int deviceId = atoi(argv[3]);
	//// Get the path to your CSV:
	// please set the correct path based on your folder
	string fn_haar = "C:\\opencv2.4.13\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml";
	string fn_csv = "C:\\csv.ext";
	int deviceId = 0;			// here is my webcam Id. 
	int detect_check = -1;
	int label = -1;
	// These vectors hold the images and corresponding labels:
	vector<Mat> images;
	vector<int> labels;
	// Read in the data (fails if no valid input filename is given, but you'll get an error message):
	try {
		read_csv(fn_csv, images, labels);
	}
	catch (cv::Exception& e) {
		cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl;
		// nothing more we can do
		exit(1);
	}
	// Get the height from the first image. We'll need this
	// later in code to reshape the images to their original
	// size AND we need to reshape incoming faces to this size:
	//	int im_width = images[0].cols;
	//	int im_height = images[0].rows;
	int img_width = images[0].cols;
	int img_height = images[0].rows;

	cout << "size of the images is " << images.size() << endl;
	cout << "size of the labes is " << labels.size() << endl;
	cout << "Training begins...." << endl;
	// Create a FaceRecognizer and train it on the given images:
	//cv::createFisherFaceRecognizer(0, 9000.0);
	Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
	model->train(images, labels);
	// That's it for learning the Face Recognition model. You now
	// need to create the classifier for the task of Face Detection.
	// We are going to use the haar cascade you have specified in the
	// command line arguments:
	//


	cout << "size of the images is " << images.size() << endl;
	cout << "size of the labes is " << labels.size() << endl;
	cout << "Training ends...." << endl;
	CascadeClassifier face_cascade;
	face_cascade.load(fn_haar);

	string window = "face detection";

	VideoCapture cap(0);
	//VideoCapture cap("C:/Users/lsf-admin/Pictures/Camera Roll/video000.mp4");

	if (!cap.isOpened())
	{
		cout << "exit" << endl;
		exit(1);

	}

	//double fps = cap.get(CV_CAP_PROP_FPS);
	//cout << " Frames per seconds " << fps << endl;
	namedWindow(window, 20000);
	long count = 0;

	while (true)
	{
		vector<Rect> faces;
		Mat frame;
		Mat graySacleFrame;
		Mat original;

		cap >> frame;
		//cap.read(frame);
		count = count + 1;//count frames;

		if (!frame.empty()){

			//clone from original frame
			original = frame.clone();

			//convert image to gray scale and equalize
			cvtColor(original, graySacleFrame, CV_BGR2GRAY);
			//equalizeHist(graySacleFrame, graySacleFrame);

			//detect face in gray image
			face_cascade.detectMultiScale(graySacleFrame, faces, 1.1, 3, 0, cv::Size(90, 90));

			//number of faces detected
			//cout << faces.size() << " faces detected" << endl;
			std::string frameset = std::to_string(count);
			std::string faceset = std::to_string(faces.size());

			int width = 0, height = 0;

			//region of interest
			//cv::Rect roi;

			//person name
			string Pname = "";

			for (int i = 0; i < faces.size(); i++)
			{
				//region of interest
				Rect face_i = faces[i];

				//crop the roi from grya image
				Mat face = graySacleFrame(face_i);

				//resizing the cropped image to suit to database image sizes
				Mat face_resized;
				cv::resize(face, face_resized, Size(img_width, img_height), 1.0, 1.0, INTER_CUBIC);

				//recognizing what faces detected
				//int label = -1; double confidence = 0;
				label = model->predict(face_resized);
				//cout << " confidencde " << confidence << endl;

				//drawing green rectagle in recognize face
				rectangle(original, face_i, CV_RGB(0, 255, 0), 1);
				string text = "Detected";
				if (label >= 0 && label <= 2){
					//string text = format("Person is  = %d", label);
					Pname = g_listname_t[label];
				}
				else{
					Pname = "unknown";
					cout << "unknown person";
				}


				int pos_x = max(face_i.tl().x - 10, 0);
				int pos_y = max(face_i.tl().y - 10, 0);

				//name the person who is in the image
				putText(original, text, Point(pos_x, pos_y), FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
				//cv::imwrite("E:/FDB/"+frameset+".jpg", cropImg);

			}


			putText(original, "Frames: " + frameset, Point(30, 60), CV_FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
			putText(original, "Person: " + Pname, Point(30, 90), CV_FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
			//display to the winodw
			cv::imshow(window, original);

			//cout << "model infor " << model->getDouble("threshold") << endl;
			if (label >= 0){
				waitKey();
				//system("notepad.exe test.txt");
				label = -1;
				destroyWindow("face detection");
				return Pname;
			}

		}
		if (waitKey(30) >= 0) break;
	}
}
