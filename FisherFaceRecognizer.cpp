
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

String FisherFaceRecog() {

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

	int img_width = images[0].cols;
	int img_height = images[0].rows;

	cout << "start recognizing..." << endl;

	string classifier = "C:\\opencv2.4.13\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml";
	CascadeClassifier face_cascade;
	face_cascade.load(classifier);


	Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
	model->load("C:/yaml/Fisherface.yml");

	string window = "face detection";

	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		cout << "exit" << endl;
		exit(1);

	}
	
	namedWindow(window, 1);
	long count = 0;

	while (true)
	{
		vector<Rect> faces;
		Mat frame;
		Mat graySacleFrame;
		Mat original;

		cap >> frame;
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
			std::string frameset = std::to_string(count);
			std::string faceset = std::to_string(faces.size());

			int width = 0, height = 0;

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

				label = model->predict(face_resized);

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

			}


			putText(original, "Frames: " + frameset, Point(30, 60), CV_FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
			putText(original, "Person: " + Pname, Point(30, 90), CV_FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
			//display to the winodw
			cv::imshow(window, original);

		}
		if (waitKey(30) >= 0) break;
	}
}
