CAFFE_ROOT = /home/share/caffe

BLAS = -I/opt/OpenBLAS/include -L/opt/OpenBLAS/lib -lopenblas
	
all:
	g++ -o app net_demo.cpp -I${CAFFE_ROOT}/include -DCPU_ONLY -I${CAFFE_ROOT}/.build_release/src -I/opt/OpenBLAS/include/ -L${CAFFE_ROOT}/build/lib -lcaffe -lglog -lboost_system -lprotobuf -Wl,-rpath=${CAFFE_ROOT}/build/lib
