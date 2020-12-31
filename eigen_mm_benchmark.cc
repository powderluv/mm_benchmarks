#include <iostream>
#include <Eigen/Dense>
#include <time.h>

using namespace Eigen;
using namespace std;

int main(int argc, const char * argv[]) {
    //RNG generator
    unsigned int seed = clock();
    srand(seed);
    int totalTimeEigen = 0;
    int warmupIters = 10;
    int Msize=1000, Nloops=20;

    MatrixXd m1=MatrixXd::Random(Msize,Msize);
    MatrixXd m2=MatrixXd::Random(Msize,Msize);

    cout << "Starting matrix multiplication test with " << Msize << " matrices" << endl;
    for (int i=0; i<Nloops+warmupIters; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        m1.noalias()=m1*m2;
        auto end = std::chrono::high_resolution_clock::now();
        if (i < warmupIters) continue;
        int eigenDuration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        totalTimeEigen += eigenDuration;
    }
    std::cout << "Eigen avg execution time (ms) = " << totalTimeEigen / Nloops << std::endl;
return 0;
}
