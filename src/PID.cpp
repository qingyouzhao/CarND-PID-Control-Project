#include "PID.h"
#include <iostream>
#include <cmath>
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  i_error = 0;
  p_error = 0;
  d_error = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  d_error = cte - p_error;
  p_error = cte;
  i_error += i_error;

  std::cout << "P part: " << -Kp * p_error << std::endl;
  std::cout << "I part: " << -Ki * i_error << std::endl;
  std::cout << "D part: " << -Kd * d_error << std::endl;
  std::cout << "Total Error : " << TotalError() << std::endl;
}

double PID::TotalError() const {
  /**
   * TODO: Calculate and return the total error
   */
  return -Kp * p_error - Kd * d_error - Ki * i_error;  // TODO: Add your total error calc here!
}

double PID::ClampedError() const
{
  double error = TotalError();
  return error < -1.0 ? -1.0 : (error > 1.0 ? 1.0 : error);
}

double PID::GetSteer() const
{
  return ClampedError();
}

double PID::GetThrottle() const
{
  // throttle should be a mapping between 0.1 and 0.3 based on the current error value
  // if our error is big, we should not throttle too much
  return 0.1 + 0.2 * exp(-fabs(TotalError()) * 30);
}