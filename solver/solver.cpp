#include <vector>
#include <iostream>
#include <caffe/net.hpp>
#include <caffe/sgd_solvers.hpp>

using namespace caffe;
using namespace std;

int main(void)
{
	string proto("solver.prototxt");
	SGDSolver<float> nn(proto);
	
	nn.Solve();

	return 0;
}