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

static void dbread(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';'){
	std::ifstream file(filename.c_str(), ifstream::in);

	if (!file){
		string error = "no valid input file";
		CV_Error(CV_StsBadArg, error);
	}

	string line, path, label;
	while (getline(file, line))
	{
		stringstream liness(line);
		getline(liness, path, separator);
		getline(liness, label);
		if (!path.empty() && !label.empty()){
			images.push_back(imread(path, 0));
			labels.push_back(atoi(label.c_str()));
		}
	}
}

void FisherFaceTrainer(){

	vector<Mat> images;
	vector<int> labels;

	try{
		string filename = "C:\\csv.ext";
		dbread(filename, images, labels);

		cout << "size of the images is " << images.size() << endl;
		cout << "size of the labes is " << labels.size() << endl;
		cout << "Training begins...." << endl;
	}
	catch (cv::Exception& e){
		cerr << " Error opening the file " << e.msg << endl;
		exit(1);
	}

	//lbph face recognier model
	Ptr<FaceRecognizer> model = createFisherFaceRecognizer();

	//training images with relevant labels 
	model->train(images, labels);

	//save the data in yaml file
	model->save("C:/yaml/Fisherface.yml");

	cout << "training finished...." << endl;
}