#include <memory>
#include <iostream>

#include <Eigen/Core>
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
  estimator->N = 500; // outer Monte Carlo samples
  estimator->M1 = 50; // inner Monte Carlo samples
  estimator->M2 = 50; // inner Monte Carlo samples

  estimator->useMIS = true; // use Multiple Importance Sampling

  VectorXd design = VectorXd::Constant(1, 0.5); // input is 1-dimensional

  double EIG = estimator->Evaluate(design);

  cout << "design = " << design << endl;
  cout << "EIG = " << EIG << endl;
  cout << "time = " << estimator->GetExecutionTime() << endl;

  return 0;
}
