#include "GL/glut.h"
#include "global.h"
#include "function.h"
#include "iostream"
#include "stdio.h"
using namespace std;




void typex(float L1){
    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, L1, L1);
        glVertex3f(0.0, -L1, -L1);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.0, L1, -L1);
        glVertex3f(0.0, -L1, L1);
    glEnd();
}
void typey(float L1){
    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
        glVertex3f(-L1, 0.0, -L1);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(L1, 0.0, -L1);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, L1);
    glEnd();
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

    //x axis
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(-35.0, 0.0, 0.0);
        glVertex3f(70.0, 0.0, 0.0);
    glEnd();
    glPushMatrix();
        glTranslatef(70.0, 0.0, 0.0);
        typex(3.0);
    glPopMatrix();

    //y axis
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, -35.0, 0.0);
        glVertex3f(0.0, 70.0, 0.0);
    glEnd();
    glPushMatrix();
        glTranslatef(0.0, 70.0, 0.0);
        typey(3.0);
    glPopMatrix();

    //z axis
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, -35.0);
        glVertex3f(0.0, 0.0, 70.0);
    glEnd();
    glPushMatrix();
        glTranslatef(0.0, 0.0, 70.0);
        typez(3.0);
    glPopMatrix();
}

//开始绘制
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 1.0, 1.0, 1.0);

    xyzAxis();

    glPopMatrix();
    glutSwapBuffers();
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











