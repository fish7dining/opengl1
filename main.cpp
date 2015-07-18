#include "GL/glut.h"
#include "global.h"
#include "function.h"
#include "iostream"
#include "stdio.h"
#include "math.h"
using namespace std;




void draw_a_cube(float c_up[3],float c_down[3],float c_front[3],float c_back[3],float c_left[3],float c_right[3]){
    glColor3fv(c_up);
    glBegin(GL_QUADS);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
    glEnd();

    glColor3fv(c_down);
    glBegin(GL_QUADS);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
    glEnd();

    glColor3fv(c_front);
    glBegin(GL_QUADS);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
    glEnd();

    glColor3fv(c_back);
    glBegin(GL_QUADS);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
    glEnd();

    glColor3fv(c_left);
    glBegin(GL_QUADS);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
    glEnd();

    glColor3fv(c_right);
    glBegin(GL_QUADS);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
    glEnd();


    glLineWidth(3.0);
    glColor3fv(COLOR_BLACK);
    glBegin(GL_LINE_LOOP);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
    glEnd();
}

void draw_MagicCube(int ope,float angel){
    if(fabs(angel)==0.0 || fabs(angel-90.0)==0.0){
        glPushMatrix();
        glTranslatef(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        draw_a_cube(COLOR_OF_CUBE[1][2], COLOR_WHITE, COLOR_OF_CUBE[1][1], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[1][3]);
        glPopMatrix();
    }
}


//开始绘制
void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(-AXIS_LEN, -AXIS_LEN, AXIS_LEN);
    typeXYZ();
    glPopMatrix();





    glPushMatrix();
    glRotatef(SPIN, 1.0, 1.0, 1.0);
    //----------------------------------------

    glPushMatrix();
        xyzAxis();
    glPopMatrix();
    glPushMatrix();
        draw_MagicCube(1, 0.0);
    glPopMatrix();



    //----------------------------------------
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}






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
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}











