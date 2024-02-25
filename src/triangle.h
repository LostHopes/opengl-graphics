#ifndef TRIANGLE_H
#include <GL/gl.h>
#include <GL/glut.h>


void transform3D();
void transform2D();

void multiply(double a[4][4], double b[4][4], double c[4][4]);
void multiplyF(double a[3][4], double b[4][4], double c[3][4]);

void projection();
void system3D();

void build();
void rebuild();

void rotateX(double angle);
void rotateY(double angle);
void rotateZ(double angle);
void transpose();
void scale();
void image();

void symmetryXY();
void symmetryXZ();
void symmetryYZ();

#endif // TRIANGLE_H