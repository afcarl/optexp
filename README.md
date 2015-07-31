# expdesign
Bayesian optimal experimental design

### Dependencies

* Eigen3, a header-only linear-algebra library (included as git submodule)
  * After cloning the repository, run `git submodule init` and `git submodule update`

### Building

* cd into `build/` and run `cmake ..` then `make -j4`. This produces Example-1 and Example2 executables.

### Examples
```c++
#include "ExpectedInformationEstimator.h"
#include "SimpleExperiment.h"

using namespace std;
using namespace Eigen;

int main(int argc, char **argv)
{
  // create the linear Gaussian experiment
  // (dim, # parameters of interest, sigeps)
  auto experiment = make_shared<SimpleExperiment>(4, 1, 0.4);

  auto estimator = make_shared<ExpectedInformationEstimator>(experiment);
  estimator->N = 100;  // outer Monte Carlo samples
  estimator->M1 = 100; // inner Monte Carlo samples
  estimator->M2 = 100; // inner Monte Carlo samples

  estimator->useMIS = true; // use Multiple Importance Sampling

  VectorXd design = VectorXd::Constant(1, 0.5); // input is 1-dimensional

  double EIG = estimator->Evaluate(design);

  cout << "design = " << design << endl;
  cout << "EIG = " << EIG << endl;
  cout << "time = " << estimator->GetExecutionTime() << endl;

  return 0;
}
```
Output:
```
MIS components (avg) = 5.304
design = 0.5
EIG = 1.94098
time = 0.478495
```