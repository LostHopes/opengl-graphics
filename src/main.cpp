#include <GL/glut.h>


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(200, 400);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cube");
    
    exit(EXIT_SUCCESS);
}
