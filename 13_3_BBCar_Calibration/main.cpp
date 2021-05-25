#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin5(D12), pin6(D13);

BBCar car(pin5, pin6, servo_ticker);

int main() {
   // please contruct you own calibration table with each servo
   double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table0[] = {-15.147, -14.49, -11.712, -10.603, -4.863, 0.000, 6.059, 11.400, 14.031, 14.988, 15.368};
   double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table1[] = {-15.625, -14.988, -14.270, -11.321, -5.501, 0.000, 5.899, 11.480, 14.350, 15.386, 15.785};

   // first and fourth argument : length of table
   car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

   while (1) {
      car.goStraightCalib(5);
      ThisThread::sleep_for(5s);
      car.stop();
      ThisThread::sleep_for(5s);
   }
}