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
  return 0;
}
