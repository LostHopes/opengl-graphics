#include <GL/gl.h>
#include <GL/glut.h>

class Triangle
{
private:
    const int size = 4;
    int width = 400, height = 400;
    double c = 30;
    double F[3][4];
    double Pr[4][4];

    double F1[3][4] , F_new[3][4], F_pr[3][4];

    double T[4][4];
    double cx = width / 2, cy = height / 2;

public:
    void transform3D();
    void transform2D();

    void multiply(double a[4][4], double b[4][4], double c[4][4]);
    void multiplyF(double a[3][4], double b[4][4], double c[3][4]);

    void projection();
    void system3D();

    void build();
    void rebuild();

    void rotateX();
    void rotateY(double angle);
    void rotateZ();
    void transpose();
    void scale();
    void image();

    void symmetryXY();
    void symmetryXZ();
    void symmetryYZ();
};