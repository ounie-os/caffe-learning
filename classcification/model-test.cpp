#include <vector>
#include <iostream>
#include <caffe/net.hpp>
#include <caffe/sgd_solvers.hpp>

using namespace caffe;
using namespace std;

int main(void)
{
	vector<int> shape(2);
	shape[0] = 1;
	shape[1] = 2;
	string proto("test.prototxt");
	Net<float> mlpnet(proto, TEST);
	
	mlpnet.CopyTrainedLayersFrom("simple_mlp_iter_20000.caffemodel");
	
	cout << mlpnet.num_inputs() << " - " << mlpnet.num_outputs() << endl;
	
	Blob<float>* input_layer_blob = mlpnet.input_blobs()[0];
	int num_channels_ = input_layer_blob->channels();
	cout << "num_channels_ = " << num_channels_ << endl;
	cout << "input blob count = " << input_layer_blob->count() << endl;
	
	float* input_data = input_layer_blob->mutable_cpu_data();
	input_data[0] = 0;
	input_data[1] = 1.0;
	
	input_layer_blob->Reshape(shape);
	mlpnet.Reshape();
	mlpnet.Forward();
	
	Blob<float>* output_layer = mlpnet.output_blobs()[0];
	cout << "output blob count = " << output_layer->count() << endl;
	cout << output_layer->shape_string() << endl;
	cout << "output[0] = " << output_layer->mutable_cpu_data()[0] << endl;
	cout << "output[1] = " << output_layer->mutable_cpu_data()[1] << endl;
	
	
	
	return 0;
}