#include "triangle.h"
#include <math.h>

const int size = 4;
const int width = 400, height = 400;
double c = 30;
double F[3][4];
double Pr[4][4];

double F1[3][4], F_new[3][4], F_pr[3][4];

double T[4][4];
double cx = width / 2, cy = height / 2;

void transform3D() {}

void transform2D() {}

void multiply(double a[4][4], double b[4][4], double c[4][4])
{
	double s;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			s = 0;
			for (int k = 0; k < size; k++)
			{
				s += a[i][k] * b[k][j];
			}
			c[i][j] = s;
		}
	}
}

void multiplyF(double a[3][4], double b[4][4], double c[3][4])
{
	double s;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size; j++)
		{
			s = 0;
			for (int k = 0; k < size; k++)
			{
				s += a[i][k] * b[k][j];
			}
			c[i][j] = s;
		}
	}
}

void projection()
{
	double phi, teta;
	phi = -29 * M_PI / 180;
	teta = 26 * M_PI / 180;

	Pr[0][0] = cos(phi);
	Pr[0][1] = sin(phi) * sin(teta);
	Pr[0][2] = 0;
	Pr[0][3] = 0;

	Pr[1][0] = 0;
	Pr[1][1] = cos(teta);
	Pr[1][2] = 0;
	Pr[1][3] = 0;

	Pr[2][0] = sin(phi);
	Pr[2][1] = -cos(phi) * sin(teta);
	Pr[2][2] = 0;
	Pr[2][3] = 0;

	Pr[3][0] = 0;
	Pr[3][1] = 0;
	Pr[3][2] = 0;
	Pr[3][3] = 1;
}

void system3D()
{
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, width, 0.0, height);

	double S[4][4] = {
		{0, 0, 0, 1},
		{7, 0, 0, 1},
		{0, 7, 0, 1},
		{0, 0, 7, 1}};

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

void build()
{
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
		glVertex2d(F[i][0], F[i][1]);
	}

	glEnd();
}

void rebuild()
{
	multiply(F, T, F_new);
	multiply(F_new, Pr, F_pr);
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

void rotateX(double angle) {}

void rotateY(double angle)
{
	angle = angle * M_PI / 180;

	T[0][0] = cos(angle);
	T[0][1] = 0;
	T[0][2] = -sin(angle);
	T[0][3] = 0;

	T[1][0] = 0;
	T[1][1] = 1;
	T[1][2] = 0;
	T[1][3] = 0;

	T[2][0] = sin(angle);
	T[2][1] = 0;
	T[2][2] = cos(angle);
	T[2][3] = 0;

	T[3][0] = 0;
	T[3][1] = 0;
	T[3][2] = 0;
	T[3][3] = 1;
}

void rotateZ(double angle) {}

void transpose() {}

void scale() {}

void symmetryXY() {}

void symmetryXZ() {}

void symmetryYZ() {}

void image()
{
	F[0][0] = 1;
	F[0][1] = 1;
	F[0][2] = 0;
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