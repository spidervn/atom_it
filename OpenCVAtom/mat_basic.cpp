
int main() {
	Mat A, C;									// Create just the header parts
	A = imread(argv[1], CV_LOAD_IMAGE_COLOR);	// here we'll know the method used (allocate matrix)

	MAT B(A);									// Use the copy constructor

	C = A;										// Assigment operator 

	Mat D(A, Rect(10, 10, 100, 100));
	Mat E = A(Range::all(), Range(1,3));

	Mat F = A.clone();
	Mat G;

	A.copyTo(G);

	/*
		@Storing Methods:
			$this is about how you store the pixel value.
			Each of the color components has its own valid domains. 

		@Creating a Mat object explicitly		
	 */

	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
	cout << "M = " << end << " " << M << endl << endl;

	int sz[3] = {2, 2, 2};
	Mat L(3, sz, CV_8UC(1), Scalar::all(0));

	IplImage* img = cvLoadImage("greatwave.png", 1);
	Mat mtx(img);			// Convert IplImage* -> Mat

	M.create(4, 4, CV_8UC(2));
	cout << "M = " << endl << " " << M << endl << endl;

	Mat E = Mat::eye(4, 4, CV_64F);
	cout << "E = " << endl << " " << E << endl << endl;

	Mat O = Mat::ones(2, 2, CV_32F);
	cout << "O = " << endl << " " << 0 << endl << endl;

	Mat Z = Mat::zeros(3, 3, CV_8CV1);
	cout << "Z = " << endl << " " << Z << endl << endl;

	// For small matrics you may use comma seperated initializers 
	Mat C = (Mat_<double>(3,3)) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cout << "C = " << endl << " " << C << endl << endl;

	Mat rowClone = C.row(1).clone();
	cout << "RowClone = " << endl << " " << RowClone << endl << endl;

	Mat R = Mat(3, 2, CV_8UC3);
	randu(R, Scalar::all(0), Scalar::all(255));

}

void outputFormatting() {
	cout << "R (default) = " << endl << R << endl << endl;

	cout << "R (python) = " << endl << format(R, "python") << endl << endl;

	// CSV
	cout << "R(CSV) = " << endl << format(R, "csv") << endl << endl;

	// Numpy
	cout << "R (numpy) = " << endl << format(R, "numpy") << endl << endl;

	// C
	cout << "R (C) = " << endl << format(R, "C") << endl << endl;
}

void outputOfOtherCommonItems() {
	//2D point 
	Point2f P(5, 1);
	cout << "Point (2D) = " << P << endl << endl;

	//3D point 
	Point3f P3f(2, 6, 7);
	cout << "Point (3D) = " << P3f << endl << endl;

	//cvMat 
	vector<float> v;
	v.push_back((float) CV_PI);
	v.push_back(2);
	v.push_back(3.01f);

	cout << "Vector of floats via Mat = " << Mat(v) << endl << endl;

	//vector
	vector<Point2f> vPoints(20);
	for (size_t i = 0;i<vPoints.size();i++) {
		vPoints[i] = Point2f((float)(i*5), (float)(i%7));
	}

	cout << "A vector of 2D points = " << vPoints << endl << endl;
}