// RUN: %cladclang %s -lm -I%S/../../include -oJacobian.out 2>&1 | FileCheck %s
// RUN: ./Jacobian.out | FileCheck -check-prefix=CHECK-EXEC %s

//CHECK-NOT: {{.*error|warning|note:.*}}

#include "clad/Differentiator/Differentiator.h"
#include <cmath>

void f_1(double a, double b, double c, double output[]) {
  output[0] = a * a * a;
  output[1] = a * a * a + b * b * b;
  output[2] = c * c * 10 - a * a;
}

void f_1_jac(double a, double b, double c, double output[], double *_result);
//CHECK: f_1_jac(double a, double b, double c, double output[], double *jacobianMatrix) {
//CHECK-NEXT:  double _t0;
//CHECK-NEXT:  double _t1;
//CHECK-NEXT:  double _t2;
//CHECK-NEXT:  double _t3;
//CHECK-NEXT:  double _t4;
//CHECK-NEXT:  double _t5;
//CHECK-NEXT:  double _t6;
//CHECK-NEXT:  double _t7;
//CHECK-NEXT:  double _t8;
//CHECK-NEXT:  double _t9;
//CHECK-NEXT:  double _t10;
//CHECK-NEXT:  double _t11;
//CHECK-NEXT:  double _t12;
//CHECK-NEXT:  double _t13;
//CHECK-NEXT:  double _t14;
//CHECK-NEXT:  double _t15;
//CHECK-NEXT:  _t2 = a;
//CHECK-NEXT:  _t1 = a;
//CHECK-NEXT:  _t3 = _t2 * _t1;
//CHECK-NEXT:  _t0 = a;
//CHECK-NEXT:  output[0] = a * a * a;
//CHECK-NEXT:  _t6 = a;
//CHECK-NEXT:  _t5 = a;
//CHECK-NEXT:  _t7 = _t6 * _t5;
//CHECK-NEXT:  _t4 = a;
//CHECK-NEXT:  _t10 = b;
//CHECK-NEXT:  _t9 = b;
//CHECK-NEXT:  _t11 = _t10 * _t9;
//CHECK-NEXT:  _t8 = b;
//CHECK-NEXT:  output[1] = a * a * a + b * b * b;
//CHECK-NEXT:  _t13 = c;
//CHECK-NEXT:  _t12 = c;
//CHECK-NEXT:  _t15 = a;
//CHECK-NEXT:  _t14 = a;
//CHECK-NEXT:  output[2] = c * c * 10 - a * a;
//CHECK-NEXT:  {
//CHECK-NEXT:    double _r12 = 1 * 10;
//CHECK-NEXT:    double _r13 = _r12 * _t12;
//CHECK-NEXT:    jacobianMatrix[8UL] += _r13;
//CHECK-NEXT:    double _r14 = _t13 * _r12;
//CHECK-NEXT:    jacobianMatrix[8UL] += _r14;
//CHECK-NEXT:    double _r15 = -1 * _t14;
//CHECK-NEXT:    jacobianMatrix[6UL] += _r15;
//CHECK-NEXT:    double _r16 = _t15 * -1;
//CHECK-NEXT:    jacobianMatrix[6UL] += _r16;
//CHECK-NEXT:  }
//CHECK-NEXT:  {
//CHECK-NEXT:    double _r4 = 1 * _t4;
//CHECK-NEXT:    double _r5 = _r4 * _t5;
//CHECK-NEXT:    jacobianMatrix[3UL] += _r5;
//CHECK-NEXT:    double _r6 = _t6 * _r4;
//CHECK-NEXT:    jacobianMatrix[3UL] += _r6;
//CHECK-NEXT:    double _r7 = _t7 * 1;
//CHECK-NEXT:    jacobianMatrix[3UL] += _r7;
//CHECK-NEXT:    double _r8 = 1 * _t8;
//CHECK-NEXT:    double _r9 = _r8 * _t9;
//CHECK-NEXT:    jacobianMatrix[4UL] += _r9;
//CHECK-NEXT:    double _r10 = _t10 * _r8;
//CHECK-NEXT:    jacobianMatrix[4UL] += _r10;
//CHECK-NEXT:    double _r11 = _t11 * 1;
//CHECK-NEXT:    jacobianMatrix[4UL] += _r11;
//CHECK-NEXT:  }
//CHECK-NEXT:  {
//CHECK-NEXT:    double _r0 = 1 * _t0;
//CHECK-NEXT:    double _r1 = _r0 * _t1;
//CHECK-NEXT:    jacobianMatrix[0UL] += _r1;
//CHECK-NEXT:    double _r2 = _t2 * _r0;
//CHECK-NEXT:    jacobianMatrix[0UL] += _r2;
//CHECK-NEXT:    double _r3 = _t3 * 1;
//CHECK-NEXT:    jacobianMatrix[0UL] += _r3;
//CHECK-NEXT:  }
//CHECK-NEXT:}


void f_3(double x, double y, double z, double *_result) {
  double constant = 42;

  _result[0] = sin(x) * constant;
  _result[1] = sin(y) * constant;
  _result[2] = sin(z) * constant;
}

void f_3_jac(double x, double y, double z, double *_result, double *jacobianMatrix);
//CHECK: void f_3_jac(double x, double y, double z, double *_result, double *jacobianMatrix) {
//CHECK-NEXT:  double _d_constant = 0;
//CHECK-NEXT:  double _t0;
//CHECK-NEXT:  double _t1;
//CHECK-NEXT:  double _t2;
//CHECK-NEXT:  double _t3;
//CHECK-NEXT:  double _t4;
//CHECK-NEXT:  double _t5;
//CHECK-NEXT:  double _t6;
//CHECK-NEXT:  double _t7;
//CHECK-NEXT:  double _t8;
//CHECK-NEXT:  double constant = 42;
//CHECK-NEXT:  _t1 = x;
//CHECK-NEXT:  _t2 = sin(_t1);
//CHECK-NEXT:  _t0 = constant;
//CHECK-NEXT:  _result[0] = sin(x) * constant;
//CHECK-NEXT:  _t4 = y;
//CHECK-NEXT:  _t5 = sin(_t4);
//CHECK-NEXT:  _t3 = constant;
//CHECK-NEXT:  _result[1] = sin(y) * constant;
//CHECK-NEXT:  _t7 = z;
//CHECK-NEXT:  _t8 = sin(_t7);
//CHECK-NEXT:  _t6 = constant;
//CHECK-NEXT:  _result[2] = sin(z) * constant;
//CHECK-NEXT:  {
//CHECK-NEXT:    double _r6 = 1 * _t6;
// CHECK-NEXT:   double _r7 = _r6 * clad::custom_derivatives{{(::std)?}}::sin_pushforward(_t7, 1.).pushforward;
//CHECK-NEXT:    jacobianMatrix[8UL] += _r7;
//CHECK-NEXT:    double _r8 = _t8 * 1;
//CHECK-NEXT:  }
//CHECK-NEXT:  {
//CHECK-NEXT:    double _r3 = 1 * _t3;
// CHECK-NEXT:   double _r4 = _r3 * clad::custom_derivatives{{(::std)?}}::sin_pushforward(_t4, 1.).pushforward;
//CHECK-NEXT:    jacobianMatrix[4UL] += _r4;
//CHECK-NEXT:    double _r5 = _t5 * 1;
//CHECK-NEXT:  }
//CHECK-NEXT:  {
//CHECK-NEXT:    double _r0 = 1 * _t0;
// CHECK-NEXT:   double _r1 = _r0 * clad::custom_derivatives{{(::std)?}}::sin_pushforward(_t1, 1.).pushforward;
//CHECK-NEXT:    jacobianMatrix[0UL] += _r1;
//CHECK-NEXT:    double _r2 = _t2 * 1;
//CHECK-NEXT:  }
//CHECK-NEXT:}

double multiply(double x, double y) { return x * y; }
//CHECK: void multiply_pullback(double x, double y, double _d_y0, clad::array_ref<double> _d_x, clad::array_ref<double> _d_y) {
//CHECK-NEXT:    double _t0;
//CHECK-NEXT:    double _t1;
//CHECK-NEXT:    _t1 = x;
//CHECK-NEXT:    _t0 = y;
//CHECK-NEXT:    double multiply_return = _t1 * _t0;
//CHECK-NEXT:    goto _label0;
//CHECK-NEXT:  _label0:
//CHECK-NEXT:    {
//CHECK-NEXT:        double _r0 = _d_y0 * _t0;
//CHECK-NEXT:        * _d_x += _r0;
//CHECK-NEXT:        double _r1 = _t1 * _d_y0;
//CHECK-NEXT:        * _d_y += _r1;
//CHECK-NEXT:    }
//CHECK-NEXT:}

void f_4(double x, double y, double z, double *_result) {
  double constant = 42;

  _result[0] = multiply(x, y) * constant;
  _result[1] = multiply(y, z) * constant;
  _result[2] = multiply(z, x) * constant;
}

void f_4_jac(double x, double y, double z, double *_result, double *jacobianMatrix);
//CHECK: void f_4_jac(double x, double y, double z, double *_result, double *jacobianMatrix) {
//CHECK-NEXT:    double _d_constant = 0;
//CHECK-NEXT:    double _t0;
//CHECK-NEXT:    double _t1;
//CHECK-NEXT:    double _t2;
//CHECK-NEXT:    double _t3;
//CHECK-NEXT:    double _t4;
//CHECK-NEXT:    double _t5;
//CHECK-NEXT:    double _t6;
//CHECK-NEXT:    double _t7;
//CHECK-NEXT:    double _t8;
//CHECK-NEXT:    double _t9;
//CHECK-NEXT:    double _t10;
//CHECK-NEXT:    double _t11;
//CHECK-NEXT:    double constant = 42;
//CHECK-NEXT:    _t1 = x;
//CHECK-NEXT:    _t2 = y;
//CHECK-NEXT:    _t3 = multiply(_t1, _t2);
//CHECK-NEXT:    _t0 = constant;
//CHECK-NEXT:    _result[0] = multiply(x, y) * constant;
//CHECK-NEXT:    _t5 = y;
//CHECK-NEXT:    _t6 = z;
//CHECK-NEXT:    _t7 = multiply(_t5, _t6);
//CHECK-NEXT:    _t4 = constant;
//CHECK-NEXT:    _result[1] = multiply(y, z) * constant;
//CHECK-NEXT:    _t9 = z;
//CHECK-NEXT:    _t10 = x;
//CHECK-NEXT:    _t11 = multiply(_t9, _t10);
//CHECK-NEXT:    _t8 = constant;
//CHECK-NEXT:    _result[2] = multiply(z, x) * constant;
//CHECK-NEXT:    {
//CHECK-NEXT:        double _r8 = 1 * _t8;
//CHECK-NEXT:        double _jac4 = 0.;
//CHECK-NEXT:        double _jac5 = 0.;
//CHECK-NEXT:        multiply_pullback(_t9, _t10, _r8, &_jac4, &_jac5);
//CHECK-NEXT:        double _r9 = _jac4;
//CHECK-NEXT:        jacobianMatrix[8UL] += _r9;
//CHECK-NEXT:        double _r10 = _jac5;
//CHECK-NEXT:        jacobianMatrix[6UL] += _r10;
//CHECK-NEXT:        double _r11 = _t11 * 1;
//CHECK-NEXT:    }
//CHECK-NEXT:    {
//CHECK-NEXT:        double _r4 = 1 * _t4;
//CHECK-NEXT:        double _jac2 = 0.;
//CHECK-NEXT:        double _jac3 = 0.;
//CHECK-NEXT:        multiply_pullback(_t5, _t6, _r4, &_jac2, &_jac3);
//CHECK-NEXT:        double _r5 = _jac2;
//CHECK-NEXT:        jacobianMatrix[4UL] += _r5;
//CHECK-NEXT:        double _r6 = _jac3;
//CHECK-NEXT:        jacobianMatrix[5UL] += _r6;
//CHECK-NEXT:        double _r7 = _t7 * 1;
//CHECK-NEXT:    }
//CHECK-NEXT:    {
//CHECK-NEXT:        double _r0 = 1 * _t0;
//CHECK-NEXT:        double _jac0 = 0.;
//CHECK-NEXT:        double _jac1 = 0.;
//CHECK-NEXT:        multiply_pullback(_t1, _t2, _r0, &_jac0, &_jac1);
//CHECK-NEXT:        double _r1 = _jac0;
//CHECK-NEXT:        jacobianMatrix[0UL] += _r1;
//CHECK-NEXT:        double _r2 = _jac1;
//CHECK-NEXT:        jacobianMatrix[1UL] += _r2;
//CHECK-NEXT:        double _r3 = _t3 * 1;
//CHECK-NEXT:    }
//CHECK-NEXT:}

void f_1_jac_0(double a, double b, double c, double output[], double *jacobianMatrix);
// CHECK: void f_1_jac_0(double a, double b, double c, double output[], double *jacobianMatrix) {
// CHECK-NEXT:  double _d_b = 0;
// CHECK-NEXT:  double _d_c = 0;
// CHECK-NEXT:  double _t0;
// CHECK-NEXT:  double _t1;
// CHECK-NEXT:  double _t2;
// CHECK-NEXT:  double _t3;
// CHECK-NEXT:  double _t4;
// CHECK-NEXT:  double _t5;
// CHECK-NEXT:  double _t6;
// CHECK-NEXT:  double _t7;
// CHECK-NEXT:  double _t8;
// CHECK-NEXT:  double _t9;
// CHECK-NEXT:  double _t10;
// CHECK-NEXT:  double _t11;
// CHECK-NEXT:  double _t12;
// CHECK-NEXT:  double _t13;
// CHECK-NEXT:  double _t14;
// CHECK-NEXT:  double _t15;
// CHECK-NEXT:  _t2 = a;
// CHECK-NEXT:  _t1 = a;
// CHECK-NEXT:  _t3 = _t2 * _t1;
// CHECK-NEXT:  _t0 = a;
// CHECK-NEXT:  output[0] = a * a * a;
// CHECK-NEXT:  _t6 = a;
// CHECK-NEXT:  _t5 = a;
// CHECK-NEXT:  _t7 = _t6 * _t5;
// CHECK-NEXT:  _t4 = a;
// CHECK-NEXT:  _t10 = b;
// CHECK-NEXT:  _t9 = b;
// CHECK-NEXT:  _t11 = _t10 * _t9;
// CHECK-NEXT:  _t8 = b;
// CHECK-NEXT:  output[1] = a * a * a + b * b * b;
// CHECK-NEXT:  _t13 = c;
// CHECK-NEXT:  _t12 = c;
// CHECK-NEXT:  _t15 = a;
// CHECK-NEXT:  _t14 = a;
// CHECK-NEXT:  output[2] = c * c * 10 - a * a;
// CHECK-NEXT:  {
// CHECK-NEXT:    double _r12 = 1 * 10;
// CHECK-NEXT:    double _r13 = _r12 * _t12;
// CHECK-NEXT:    double _r14 = _t13 * _r12;
// CHECK-NEXT:    double _r15 = -1 * _t14;
// CHECK-NEXT:    jacobianMatrix[2UL] += _r15;
// CHECK-NEXT:    double _r16 = _t15 * -1;
// CHECK-NEXT:    jacobianMatrix[2UL] += _r16;
// CHECK-NEXT:  }
// CHECK-NEXT:  {
// CHECK-NEXT:    double _r4 = 1 * _t4;
// CHECK-NEXT:    double _r5 = _r4 * _t5;
// CHECK-NEXT:    jacobianMatrix[1UL] += _r5;
// CHECK-NEXT:    double _r6 = _t6 * _r4;
// CHECK-NEXT:    jacobianMatrix[1UL] += _r6;
// CHECK-NEXT:    double _r7 = _t7 * 1;
// CHECK-NEXT:    jacobianMatrix[1UL] += _r7;
// CHECK-NEXT:    double _r8 = 1 * _t8;
// CHECK-NEXT:    double _r9 = _r8 * _t9;
// CHECK-NEXT:    double _r10 = _t10 * _r8;
// CHECK-NEXT:    double _r11 = _t11 * 1;
// CHECK-NEXT:  }
// CHECK-NEXT:  {
// CHECK-NEXT:    double _r0 = 1 * _t0;
// CHECK-NEXT:    double _r1 = _r0 * _t1;
// CHECK-NEXT:    jacobianMatrix[0UL] += _r1;
// CHECK-NEXT:    double _r2 = _t2 * _r0;
// CHECK-NEXT:    jacobianMatrix[0UL] += _r2;
// CHECK-NEXT:    double _r3 = _t3 * 1;
// CHECK-NEXT:    jacobianMatrix[0UL] += _r3;
// CHECK-NEXT:  }
// CHECK-NEXT:}

void f_5(float a[3], float output[]){
  output[0]=a[0]*a[1];
  output[1]=a[1]*a[2];
  output[2]=a[0]*a[2];
}
void f_5_jac(float a[3], float output[], float *jacobianMatrix);
// CHECK: void f_5_jac(float a[3], float output[], float *jacobianMatrix) {
// CHECK-NEXT:     float _t0;
// CHECK-NEXT:     float _t1;
// CHECK-NEXT:     float _t2;
// CHECK-NEXT:     float _t3;
// CHECK-NEXT:     float _t4;
// CHECK-NEXT:     float _t5;
// CHECK-NEXT:     _t1 = a[0];
// CHECK-NEXT:     _t0 = a[1];
// CHECK-NEXT:     output[0] = a[0] * a[1];
// CHECK-NEXT:     _t3 = a[1];
// CHECK-NEXT:     _t2 = a[2];
// CHECK-NEXT:     output[1] = a[1] * a[2];
// CHECK-NEXT:     _t5 = a[0];
// CHECK-NEXT:     _t4 = a[2];
// CHECK-NEXT:     output[2] = a[0] * a[2];
// CHECK-NEXT:     {
// CHECK-NEXT:         float _r4 = 1 * _t4;
// CHECK-NEXT:         jacobianMatrix[6UL] += _r4;
// CHECK-NEXT:         float _r5 = _t5 * 1;
// CHECK-NEXT:         jacobianMatrix[8UL] += _r5;
// CHECK-NEXT:     }
// CHECK-NEXT:     {
// CHECK-NEXT:         float _r2 = 1 * _t2;
// CHECK-NEXT:         jacobianMatrix[4UL] += _r2;
// CHECK-NEXT:         float _r3 = _t3 * 1;
// CHECK-NEXT:         jacobianMatrix[5UL] += _r3;
// CHECK-NEXT:     }
// CHECK-NEXT:     {
// CHECK-NEXT:         float _r0 = 1 * _t0;
// CHECK-NEXT:         jacobianMatrix[0UL] += _r0;
// CHECK-NEXT:         float _r1 = _t1 * 1;
// CHECK-NEXT:         jacobianMatrix[1UL] += _r1;
// CHECK-NEXT:     }
// CHECK-NEXT: }

void f_6(float a[1], float b, float output[]) {
    output[0] = a[0] * a[0] * a[0];
    output[1] = a[0] * a[0] * a[0] + b * b * b;
    output[2] = 2 * (a[0] + b);
}
void f_6_jac(float a[1], float b, float output[], float *jacobianMatrix);
// CHECK: void f_6_jac(float a[1], float b, float output[], float *jacobianMatrix) {
// CHECK-NEXT:     float _t0;
// CHECK-NEXT:     float _t1;
// CHECK-NEXT:     float _t2;
// CHECK-NEXT:     float _t3;
// CHECK-NEXT:     float _t4;
// CHECK-NEXT:     float _t5;
// CHECK-NEXT:     float _t6;
// CHECK-NEXT:     float _t7;
// CHECK-NEXT:     float _t8;
// CHECK-NEXT:     float _t9;
// CHECK-NEXT:     float _t10;
// CHECK-NEXT:     float _t11;
// CHECK-NEXT:     float _t12;
// CHECK-NEXT:     _t2 = a[0];
// CHECK-NEXT:     _t1 = a[0];
// CHECK-NEXT:     _t3 = _t2 * _t1;
// CHECK-NEXT:     _t0 = a[0];
// CHECK-NEXT:     output[0] = a[0] * a[0] * a[0];
// CHECK-NEXT:     _t6 = a[0];
// CHECK-NEXT:     _t5 = a[0];
// CHECK-NEXT:     _t7 = _t6 * _t5;
// CHECK-NEXT:     _t4 = a[0];
// CHECK-NEXT:     _t10 = b;
// CHECK-NEXT:     _t9 = b;
// CHECK-NEXT:     _t11 = _t10 * _t9;
// CHECK-NEXT:     _t8 = b;
// CHECK-NEXT:     output[1] = a[0] * a[0] * a[0] + b * b * b;
// CHECK-NEXT:     _t12 = (a[0] + b);
// CHECK-NEXT:     output[2] = 2 * (a[0] + b);
// CHECK-NEXT:     {
// CHECK-NEXT:         float _r12 = 1 * _t12;
// CHECK-NEXT:         float _r13 = 2 * 1;
// CHECK-NEXT:         jacobianMatrix[4UL] += _r13;
// CHECK-NEXT:         jacobianMatrix[5UL] += _r13;
// CHECK-NEXT:     }
// CHECK-NEXT:     {
// CHECK-NEXT:         float _r4 = 1 * _t4;
// CHECK-NEXT:         float _r5 = _r4 * _t5;
// CHECK-NEXT:         jacobianMatrix[2UL] += _r5;
// CHECK-NEXT:         float _r6 = _t6 * _r4;
// CHECK-NEXT:         jacobianMatrix[2UL] += _r6;
// CHECK-NEXT:         float _r7 = _t7 * 1;
// CHECK-NEXT:         jacobianMatrix[2UL] += _r7;
// CHECK-NEXT:         float _r8 = 1 * _t8;
// CHECK-NEXT:         float _r9 = _r8 * _t9;
// CHECK-NEXT:         jacobianMatrix[3UL] += _r9;
// CHECK-NEXT:         float _r10 = _t10 * _r8;
// CHECK-NEXT:         jacobianMatrix[3UL] += _r10;
// CHECK-NEXT:         float _r11 = _t11 * 1;
// CHECK-NEXT:         jacobianMatrix[3UL] += _r11;
// CHECK-NEXT:     }
// CHECK-NEXT:     {
// CHECK-NEXT:         float _r0 = 1 * _t0;
// CHECK-NEXT:         float _r1 = _r0 * _t1;
// CHECK-NEXT:         jacobianMatrix[0UL] += _r1;
// CHECK-NEXT:         float _r2 = _t2 * _r0;
// CHECK-NEXT:         jacobianMatrix[0UL] += _r2;
// CHECK-NEXT:         float _r3 = _t3 * 1;
// CHECK-NEXT:         jacobianMatrix[0UL] += _r3;
// CHECK-NEXT:     }
// CHECK-NEXT: }


#define TEST(F, x, y, z) { \
  result[0] = 0; result[1] = 0; result[2] = 0;\
  result[3] = 0; result[4] = 0; result[5] = 0;\
  result[6] = 0; result[7] = 0; result[8] = 0;\
  outputarr[0] = 0; outputarr[1] = 1; outputarr[2] = 0;\
  auto j = clad::jacobian(F);\
  j.execute(x, y, z, outputarr, result);\
  printf("Result is = {%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f}\n",\
  result[0], result[1], result[2],\
  result[3], result[4], result[5],\
  result[6], result[7], result[8]);\
  F##_jac(x, y, z, outputarr, result);\
}

#define TEST_F_1_SINGLE_PARAM(x, y, z) { \
  result[0] = 0; result[1] = 0; result[2] = 0;\
  outputarr[0] = 0; outputarr[1] = 1; outputarr[2] = 0;\
  auto j = clad::jacobian(f_1,"a");\
  j.execute(x, y, z, outputarr, result);\
  printf("Result is = {%.2f, %.2f, %.2f}\n",\
  result[0], result[1], result[2]);\
}


int main() {
  double result[10];
  double outputarr[9];
  TEST(f_1, 1, 2, 3); // CHECK-EXEC: Result is = {3.00, 0.00, 0.00, 3.00, 12.00, 0.00, -2.00, 0.00, 60.00}
  TEST(f_3, 1, 2, 3); // CHECK-EXEC: Result is = {22.69, 0.00, 0.00, 0.00, -17.48, 0.00, 0.00, 0.00, -41.58}
  TEST(f_4, 1, 2, 3); // CHECK-EXEC: Result is = {84.00, 42.00, 0.00, 0.00, 126.00, 84.00, 126.00, 0.00, 42.00}
  TEST_F_1_SINGLE_PARAM(1, 2, 3); // CHECK-EXEC: Result is = {3.00, 3.00, -2.00}


  auto d_f_5 = clad::jacobian(f_5);
  float a5[3]={3,4,5};
  float op5[3]={0};
  float jc5[9]={0};
  d_f_5.execute(a5,op5,jc5);
  printf("Result is = {%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f}\n", jc5[0],jc5[1],jc5[2],jc5[3],jc5[4],jc5[5],jc5[6],jc5[7],jc5[8]);
  //CHECK-EXEC: Result is = {4.00, 3.00, 0.00, 0.00, 5.00, 4.00, 5.00, 0.00, 3.00}

  auto d_f_6 = clad::jacobian(f_6);
  float a6[1]={3};float b6=5;
  float op6[3]={0};
  float jc6[6]={0};
  d_f_6.execute(a6,b6,op6,jc6);
  printf("Result is = {%.2f, %.2f, %.2f, %.2f, %.2f, %.2f}\n", jc6[0],jc6[1],jc6[2],jc6[3],jc6[4],jc6[5]);
  //CHECK-EXEC: Result is = {27.00, 0.00, 27.00, 75.00, 2.00, 2.00}
}
