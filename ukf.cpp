#include <iostream>
#include "ukf.h"

UKF::UKF() {
  //TODO Auto-generated constructor stub
  Init();
  
}

UKF::~UKF() {
  //TODO Auto-generated destructor stub
  
}

void UKF::Init() {

  
}


/*******************************************************************************
 * Programming assignment functions: 
 *******************************************************************************/

void UKF::SigmaPointPrediction(MatrixXd* Xsig_out) {

  //set state dimension
  int n_x = 5;

  //set augmented dimension
  int n_aug = 7;

  //create example sigma point matrix
  MatrixXd Xsig_aug = MatrixXd(n_aug, 2 * n_aug + 1);
  Xsig_aug <<
    5.7441,  5.85768,   5.7441,   5.7441,   5.7441,   5.7441,   5.7441,   5.7441,   5.63052,   5.7441,   5.7441,   5.7441,   5.7441,   5.7441,   5.7441,
    1.38,  1.34566,  1.52806,     1.38,     1.38,     1.38,     1.38,     1.38,   1.41434,  1.23194,     1.38,     1.38,     1.38,     1.38,     1.38,
    2.2049,  2.28414,  2.24557,  2.29582,   2.2049,   2.2049,   2.2049,   2.2049,   2.12566,  2.16423,  2.11398,   2.2049,   2.2049,   2.2049,   2.2049,
    0.5015,  0.44339, 0.631886, 0.516923, 0.595227,   0.5015,   0.5015,   0.5015,   0.55961, 0.371114, 0.486077, 0.407773,   0.5015,   0.5015,   0.5015,
    0.3528, 0.299973, 0.462123, 0.376339,  0.48417, 0.418721,   0.3528,   0.3528,  0.405627, 0.243477, 0.329261,  0.22143, 0.286879,   0.3528,   0.3528,
    0,        0,        0,        0,        0,        0,  0.34641,        0,         0,        0,        0,        0,        0, -0.34641,        0,
    0,        0,        0,        0,        0,        0,        0,  0.34641,         0,        0,        0,        0,        0,        0, -0.34641;

  //create matrix with predicted sigma points as columns
  MatrixXd Xsig_pred = MatrixXd(n_x, 2 * n_aug + 1);

  double delta_t = 0.1; //time diff in sec
  /*******************************************************************************
   * Student part begin
   ******************************************************************************/
  // take out all the value to be more convenient to understand
  
  for(int i = 0; i < 2 * n_aug+1; i++){
    VactorXd x = Xsig_aug.col(i);
    float px = x(0);
    float py = x(1);
    float v = x(2);
    float phi = x(3);
    float phidot = x(4);
    float std_a = x(5);
    float std_yawdd = x(6);
    // predict the state
    if(phidot != 0){
      px += v / phidot * (sin(phi + phidot * delta_t) - sin(phi)) + 0.5 *delta_t*delta_t*cos(phi)*std_a;
      py += v / phidot * (-1* cos(phi + phidot * delta_t) + cos(phi)) + 0.5 *delta_t*delta_t*sin(phi)*std_a;
      v += delta_t*std_a;
      phi+= phidot*delta_t+0.5*delta_t*delta_t*std_yawdd;
      phidot += delta_t*std_yawdd;
    }
    else{
      px += v * cos(phi)*delta_t+0.5*delta_t*delta_t*cos(phi)*std_a;
      py += v * sin(phi)*delta_t+0.5*delta_t*delta_t*sin(phi)*std_a;
      v += delta_t * std_a;
      phi += 0.5 * delta_t * delta_t * std_yawdd;
      phidot += delta_t * std_yawdd;
    }
    x << px, py, v, phi, phidot;
    Xsig_pred.col(i) = x;
  }
  /*******************************************************************************
   * Student part end
   ******************************************************************************/

  //print result
  std::cout << "Xsig_pred = " << std::endl << Xsig_pred << std::endl;

  //write result
  *Xsig_out = Xsig_pred;
}
