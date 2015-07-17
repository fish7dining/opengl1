#include "GL/glut.h"
#include "global.h"
#include "function.h"
#include "iostream"
#include "stdio.h"
#include "math.h"
using namespace std;




void draw_n_pyramid(int n){
    float temp1 = 2*PI/n;

    for(int i=0;i<n;++i){
        glBegin(GL_TRIANGLES);
            glVertex3f( n_pyramid_r*cos(temp1*i), n_pyramid_r*sin(temp1*i), 0.0 );
            glVertex3f( n_pyramid_r*cos(temp1*(i+1)), n_pyramid_r*sin(temp1*(i+1)), 0.0 );
            glVertex3f( 0.0, 0.0, n_pyramid_h );
        glEnd();
    }
}


void xyzAxis(void){

    //x axis
    glColor3fv(COLOR_WHITE);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(-AXIS_LEN/2, 0.0, 0.0);
        glVertex3f(AXIS_LEN, 0.0, 0.0);
    glEnd();
    glPushMatrix();
        glTranslatef(AXIS_LEN, 0.0, 0.0);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        glLineWidth(1.0);
        glColor3fv(COLOR_RED);
        draw_n_pyramid(10);
    glPopMatrix();

    //y axis
    glColor3fv(COLOR_WHITE);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, -AXIS_LEN/2, 0.0);
        glVertex3f(0.0, AXIS_LEN, 0.0);
    glEnd();
    glPushMatrix();
        glTranslatef(0.0, AXIS_LEN, 0.0);
        glRotatef(90.0, -1.0, 0.0, 0.0);
        glLineWidth(1.0);
        glColor3fv(COLOR_BLUE);
        draw_n_pyramid(10);
    glPopMatrix();

    //z axis
    glColor3fv(COLOR_WHITE);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, -AXIS_LEN/2);
        glVertex3f(0.0, 0.0, AXIS_LEN);
    glEnd();
    glPushMatrix();
        glTranslatef(0.0, 0.0, AXIS_LEN);
        glLineWidth(1.0);
        glColor3fv(COLOR_YELLOW);
        draw_n_pyramid(10);
    glPopMatrix();
}

//开始绘制
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(SPIN, 1.0, 1.0, 1.0);

    xyzAxis();

    glPopMatrix();
    glutSwapBuffers();
}






int main(int argc, char** argv)
{
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











