#include <memory>
#include <iostream>

#include <Eigen/Core>
#include "ExpectedInformationEstimator.h"
#include "MossbauerExperiment.h"

using namespace std;
using namespace Eigen;

int main(int argc, char **argv)
{
  // create the Mossbauer experiment
  // (dim, [# param interest], [index of PoI], [sigeps])
  auto experiment = make_shared<MossbauerExperiment>(3);

  auto estimator = make_shared<ExpectedInformationEstimator>(experiment);
  estimator->N = 100;  // outer Monte Carlo samples
  estimator->M1 = 100; // inner Monte Carlo samples
  estimator->M2 = 100; // inner Monte Carlo samples

  VectorXd design(3);
  design << -1, 0, 1;

  double EIG = estimator->Evaluate(design);

  cout << "EIG = " << EIG << endl;
  cout << "time = " << estimator->GetExecutionTime() << endl;

  return 0;
}
