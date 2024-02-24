#include <GL/gl.h>
#include <GL/glut.h>
#include "triangle.h"

void keyboard(unsigned char key, int x0, int y0)
{
	switch (key)
    {
    case '1':
        Triangle::rotateY();
        glutPostRedisplay();
        break;
    case '2':
        glutPostRedisplay();
        break;
    }
	
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(200, 400);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cube");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    Triangle::rotateY();

    glutMainLoop();

    exit(EXIT_SUCCESS);
}