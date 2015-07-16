#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
using namespace std;

static GLfloat spin = 0.0;


void typex(){

}
void typey(){

}
void typez(float L1){
    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
        glVertex3f(-L1, L1, 0.0);
        glVertex3f(L1, L1, 0.0);
        glVertex3f(-L1, -L1, 0.0);
        glVertex3f(L1, -L1, 0.0);
    glEnd();
}
void xyzAxis(void){
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2.0);

    //x axis
    glBegin(GL_LINES);
        glVertex3f(-15.0, 0.0, 0.0);
        glVertex3f(40.0, 0.0, 0.0);
    glEnd();

    //y axis
    glBegin(GL_LINES);
        glVertex3f(0.0, -15.0, 0.0);
        glVertex3f(0.0, 40.0, 0.0);
    glEnd();

    //z axis
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, -15.0);
        glVertex3f(0.0, 0.0, 40.0);
    glEnd();
    glPushMatrix();
        glTranslatef(0.0, 0.0, 40.0);
        typez(1.0);
    glPopMatrix();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 1.0, 1.0, 1.0);

    xyzAxis();

    glPopMatrix();
    glutSwapBuffers();
}

void spinDisplay(void){
    spin = spin + 2.0;
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
}

void reshape(int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, 1.0, 101.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 51.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void mouse(int button, int state, int x, int y){
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}
void keyboard(unsigned char key,int x,int y){
    switch(key){
        case 'a':
            break;
        case 'b':
            break;
        default:
            break;
    }
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}











