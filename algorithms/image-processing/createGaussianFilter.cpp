// Generate Gaussian filter

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// Function to create Gaussian filter
void FilterCreation(double GKernel[][5])
{
	// intialising standard deviation to 1.0
	double sigma = 1.0;
	double r, s = 2.0 * sigma * sigma;

	// sum is for normalization
	double sum = 0.0;

	// generating 5x5 kernel
	for (int x = -2; x <= 2; x++) {
		for (int y = -2; y <= 2; y++) {
			r = sqrt(x * x + y * y);
			GKernel[x + 2][y + 2] = (exp(-(r * r) / s)) / (M_PI * s);
			sum += GKernel[x + 2][y + 2];
		}
	}

	// normalising the Kernel
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			GKernel[i][j] /= sum;
}

int main()
{
	double GKernel[5][5];
	FilterCreation(GKernel);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			cout << GKernel[i][j] << "\t";
		cout << endl;
	}
}
