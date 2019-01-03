/* 
Eigen tutorial
*/

#include<iostream>
#include"Eigen/Dense"

using namespace std;
using namespace Eigen;

int main(){
  // matrix pro
  Matrix3d m;
  m << 1, 2, 3, 4, 5, 6, 7, 8, 9;
  // cout<<m.prod();
  ptrdiff_t i, j;
  m.minCoeff(&i, &j);
  cout<<"The position of minimum"<<m<<"is at"<<i<<"and"<<j;
  Array22d m_array;
  m_array << 1,  2, 3, 4;
  cout << m_array;
  // block
  for(int i = 0; i < m.rows(); ++i){
    cout<< m.block(0, 0, i, i)<<endl<<endl;
  }
  // cols and rows
  // initilization for vector to join.
  Vector2d v1;
  Vector3d v2;
  v1 << 1, 2;
  v2 << v1, 1;
  cout<<"Here is vector 1 \n"<<v1<<endl<<"Here is vector 2 \n"<<v2<<endl;
  // constant
  // m.Constant(1);
  cout<<"This is m constant:"<<endl<<m.Constant(12)<<endl;
  ArrayXXf table(10, 4);
  table.col(0) = ArrayXf::LinSpaced(10, 0, 90);
  table.col(1) = M_PI / 180 * table.col(0);
  table.col(2) = table.col(1).sin();
  table.col(3) = table.col(1).cos();
  cout << "  Degrees   Radians      Sine    Cosine\n";
  cout << table << std::endl;
  // construct a identity matrix
  const int size = 6;
  MatrixXd m1(size, size);
  m1 <<
    MatrixXd::Zero(size/2, size/2), MatrixXd::Identity(size/2, size/2),
    MatrixXd::Identity(size/2, size/2), MatrixXd::Zero(size/2, size/2);
  cout<<m1<<endl;
  
  m1.topLeftCorner(size/2, size/2).setRandom();
  m1.bottomRightCorner(size/2, size/2).setConstant(12);
  cout<<m1<<endl;
  // norm operation
  cout<<"This is m: \n"<<m<<endl;
  cout<<"m.norm: \n"<<m.norm()<<endl;
  cout<<"square norm: \n"<<m.squaredNorm()<<endl;
  Matrix3d test_m = Matrix3d::Random();
  cout<<(m - test_m).squaredNorm()<<endl;
  // Argumax for every column of m.
  cout<<m.colwise().maxCoeff();
  // boolean reduction
  cout<<"boolean reduction:m>3 \n"<<(m_array>3).count()<<endl;
  // matrix boolean reduction
  cout<<"Matrix boolean reduction for m<3 \n"<<(m.array() > 3).count()<<endl;
  // get the argmax.
  MatrixXd::Index ind_x, ind_y;
  m.maxCoeff(&ind_x, &ind_y);
  cout<<"The index of the Max value is ("<<ind_x<<","<<ind_y<<")"<<endl;
  cout<<"Patrial Reduction to find out the max sum of each columns."<<endl;
  MatrixXd::Index max_index;
  double max_value;
  max_value = m.colwise().sum().maxCoeff(&max_index);
  cout<<max_value<<" at index "<<max_index<<endl;
  // v.diagonal
  Matrix2d k;
  k = v1.asDiagonal();
  cout<<"try diagonal\n"<< k;
  // broadcast
  cout<<"Original m: \n"<<m<<endl;
  m.colwise()+=v2;
  cout<<"Broardcasting m: \n"<<m<<endl;
  // find the neariest neighbor of vector v2 in m
  cout<<"find the neariest neighbor of vector v2 in m:\n"<<(m.colwise() - v2).colwise().squaredNorm().maxCoeff();
  // v2 mu <<endl;
  cout<<"M matrix: \n"<<m<<endl<<"v2:\n"<<v2<<endl;
  cout<<"sum of the matrix \n"<< (m * v2.asDiagonal()).rowwise().sum()<<"\n";
  // try init with a value
  MatrixXd samem = MatrixXd::Constant(3, 3, 1.23);
  cout<<"same value m: \n"<<samem<<endl;
  VectorXd weights = VectorXd(10);
  weights = VectorXd::Constant(10, 1.2);
  cout<<"vector with same value: \n"<<weights<<endl;
  cout<<"calculate P possiblity\n";
  cout<<(m.colwise() - v2).array().sqrt().matrix().rowwise().sum()<<endl;
  cout<<"v2 * v2.T\n"<<v2 * v2.transpose();
  cout<<(m.colwise() -v2) * (m.colwise() - v2).transpose();
  cout<<"here is the top left corner \n"<<m.topLeftCorner(2, 3)<<endl;
  cout<<"here is the top left corner norm \n"<<m.topLeftCorner(2, 3).colwise().norm()<<endl;
  //Calculate phi
  ArrayXd phi;
  phi = m.row(1).array() / m.row(0).array();
  cout<<"calculate phi:\n"<<phi;
  // Atan2
  ArrayXd v = ArrayXd::LinSpaced(5,0,1);
  cout << phi.atan() << endl;
  // cout<<"Atan2 on matrix: \n"<<m.col(0).atan();
  cout<<"Try to use col \n"<<(m.col(1).array() / m.col(0).array()).tan();
}
