#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Mesh2Cloud.h"
#include <Eigen/Dense>
using namespace std;


int main(int argc, char* argv[])
{
	string filename;
	
	if (argc < 2) {
		cout << "Usage: ./convert <file name>" << endl;
		cout << "Use test data." << endl;
		filename = "../data/input.obj";
	}
	else {
		filename = argv[1];
	}

	
	clock_t t1 = clock();
	Mesh2Cloud converter;
	converter.convert(filename);
	clock_t t2 = clock();

	cout <<  "Time: " << double(t2 - t1)/ CLOCKS_PER_SEC << " s \n";

	return 0;
}



