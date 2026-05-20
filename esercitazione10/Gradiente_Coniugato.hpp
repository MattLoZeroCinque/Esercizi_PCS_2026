#include <iostream>
#include <Eigen/Eigen>


double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues();
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}


int Gradiente_Coniugato(unsigned int n) 
{
  const double tol = 1.0e-15;

  Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

  if (abs(B.determinant()) < tol)
    return -1;

  Eigen::MatrixXd A = B.transpose() * B;
  Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);

  Eigen::VectorXd b = A * x_ex;

  Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
  Eigen::VectorXd res = b - A * x;
  Eigen::VectorXd p = res;
  
  const double res_norm_0 = res.norm();
  const unsigned int it_max = 150;
  unsigned int it = 0;
  const double res_tol = 1.0e-15;

  std::cout.precision(4);
  std::cout<< std::scientific<< "Matrix Cond: "<< condA(A)<< std::endl;

  while (it < it_max &&
         res.norm() > res_tol * res_norm_0)
  {
    const double alpha_k = ((p.transpose() * res) / (p.transpose() * A * p)).value();
    x = x + (alpha_k * p);
    res = b - A * x;
    const double beta_k = ((p.transpose() * A * res) / (p.transpose() * A * p)).value();
    p = res - (beta_k * p);
    it++;
  }

  const auto err_rel = (x_ex.norm() == 0.0) ? (x - x_ex).norm() :
                                              (x - x_ex).norm() / x_ex.norm();

  std::cout.precision(4);
  std::cout<< std::scientific<< "Iterazioni"<< "   /   "<< "Iterazioni Massime"<< std::endl;
  std::cout<< std::scientific<< it<< "  /  "<< it_max<< std::endl;
  std::cout<< std::scientific<< "Residuo"<< "   /   "<< "Tolleranza Residuo"<< std::endl;
  std::cout<< std::scientific<< res.norm() / res_norm_0<< "  /  "<< res_tol<< std::endl;
  std::cout<< std::scientific<< "Errore_Relativo"<< std::endl;
  std::cout<< std::scientific<< err_rel<< std::endl;
  
  std::cout<< std::scientific<< "La soluzione del metodo è: "<< std::endl;
  std::cout<< std::scientific<< x << std::endl;
 
  return 0;
}
