#include <vector>
#include <iostream>
#include <caffe/net.hpp>

using namespace caffe;
using namespace std;

int main(void)
{
	float loss = 0;
	string proto("train.prototxt");
	Net<float> nn(proto, TRAIN);
	vector<string> bn = nn.blob_names();
	for (int i = 0; i < bn.size(); i++)
	{
		cout << "Blob #" << i << " : "<< bn[i] << endl;
	}
	
	nn.Forward(&loss);
	
	printf("%f\n", loss);
	
	return 0;
}