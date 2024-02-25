#include <GL/gl.h>
#include <GL/glut.h>
#include "triangle.h"

void keyboard(unsigned char key, int x0, int y0)
{
	switch (key)
    {
    case '1':
        rotateY(-90.0);
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
    projection();
    system3D();
    image();
    build();
    rebuild();
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

    glutMainLoop();

    exit(EXIT_SUCCESS);
}