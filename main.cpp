#include "GL/glut.h"
#include "global.h"
#include "function.h"
#include "iostream"
#include "stdio.h"
#include "math.h"
using namespace std;


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (700, 700);
    glutInitWindowPosition (0, 0);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}











