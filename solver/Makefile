CAFFE_ROOT = /home/share/caffe

all:
	g++ -o solverapp solver.cpp -I${CAFFE_ROOT}/include -DCPU_ONLY -I${CAFFE_ROOT}/.build_release/src -I/opt/OpenBLAS/include/ -L${CAFFE_ROOT}/build/lib -lcaffe -lglog -lboost_system -lprotobuf -Wl,-rpath=${CAFFE_ROOT}/build/lib
