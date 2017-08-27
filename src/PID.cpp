#include "PID.h"

#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    cout << "Init [Kp, Ki, Kd]=" << Kp << "," << Ki << "," << Kd << endl;
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    p_error = 0;
    i_error = 0;
    d_error = 0;
    iter = 0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
    iter++;
    cout << "AVG Error: " << i_error / iter << endl;
}

double PID::TotalError() {
    double rslt = - Kp * p_error - Ki * i_error - Kd * d_error;
    return rslt;
}

