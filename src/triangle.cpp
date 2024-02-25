#include "triangle.h"
#include <math.h>

void Triangle::transform3D(){}

void Triangle::transform2D(){}

void Triangle::multiply(double a[4][4], double b[4][4], double c[4][4]){
    double s;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			s = 0;
			for (int k = 0; k < 4; k++)
			{
				s = s + a[i][k] * b[k][j];
			}
			c[i][j] = s;
		}
	}
}

void Triangle::multiplyF(double a[3][4], double b[4][4], double c[3][4]){
    double s;

	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			s = 0;
			for (size_t k = 0; k < 4; k++)
			{
				s = s + a[i][k] * b[k][j];
			}
			c[i][j] = s;
		}
	}
}

void Triangle::projection(){
	
}

void Triangle::system3D(){
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, width, 0.0, height);

	double S[4][4] = {
		{0, 0, 0, 1},
		{7, 0, 0, 1},
		{0, 7, 0, 1},
		{0, 0, 7, 1}
	};

	double S_pr[4][4], S1[4][4];
	double x, y, x_ek, y_ek;

	multiply(S, Pr, S_pr);

	for (int i = 0; i < size - 1; i++)
	{
		x = Pr[i][0];
		y = S_pr[i][1];

		x_ek = c * x + cx;
		y_ek = c * y + cy;

		S1[i][0] = x_ek;
		S1[i][1] = y_ek;
	}

	glColor3d(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINES);

	glVertex2d(S1[0][0], S1[0][1]);
	glVertex2d(S1[1][0], S1[1][1]);

	glVertex2d(S1[0][0], S1[0][1]);
	glVertex2d(S1[2][0], S1[2][1]);

	glVertex2d(S1[0][0], S1[0][1]);
	glVertex2d(S1[3][0], S1[3][1]);
	
	glEnd();
}

void Triangle::build(){
	multiplyF(F, Pr, F_pr);
	double x, y, x_ek, y_ek;

	for (int i = 0; i < size - 1; i++)
	{
		x = F_pr[i][0];
		y = F_pr[i][1];

		x_ek = c * x + cx;
		y_ek = c * y + cy;

		F[i][0] = x_ek;
		F[i][1] = y_ek;
	}

	glColor3d(1, 0, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(3);
	glBegin(GL_POLYGON);

	for (int i = 0; i < size - 1; i++)
	{
		glVertex2d(F[i][0], F1[i][1]);
	}

	glEnd();
	
}

void Triangle::rebuild(){
	multiplyF(F, T, F_new);
	multiplyF(F_new, Pr, F_pr);
	double x, y, x_ek, y_ek;

	for (int i = 0; i < size - 1; i++)
	{
		x = F_pr[i][0];
		y = F_pr[i][1];

		x_ek = c * x + cx;
		y_ek = c * y + cy;

		F[i][0] = x_ek;
		F1[i][1] = y_ek;
	}

	glColor3d(0, 0, 1);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(3);
	glBegin(GL_POLYGON);

	for (int i = 0; i < size - 1; i++)
	{
		glVertex2d(F1[i][0], F1[i][1]);
	}
	
	glEnd();
	
}

void Triangle::rotateX(){}

void Triangle::rotateY(double angle)
{
	angle = angle * M_PI / 180;

	T[0][0] = cos(angle);
	T[0][1] = 0;
	T[0][2] = -sin(angle);
	T[0][3] = 0;

	T[1][0] = 0;
	T[1][2] = 0;
	T[1][3] = 0;

	T[2][0] = sin(angle);
	T[2][1] = 0;
	T[2][2] = cos(angle);
	T[1][3] = 0;

	T[3][0] = 0;
	T[3][1] = 0;
	T[3][2] = 0;
	T[3][3] = 1;	
}

void Triangle::rotateZ(){}

void Triangle::transpose(){}

void Triangle::scale(){}

void Triangle::symmetryXY(){}

void Triangle::symmetryXZ(){}

void Triangle::symmetryYZ(){}

void Triangle::image() {
	F[0][0] = 1; 
	F[0][1] = 1;
	F[0][2] = 1;
	F[0][3] = 1;

	F[1][0] = 5;
	F[1][1] = 1;
	F[1][2] = 0;
	F[1][3] = 1;

	F[2][0] = 3;
	F[2][1] = 5;
	F[2][2] = 0;
	F[2][3] = 1;
}