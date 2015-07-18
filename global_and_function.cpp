#include "function.h"
#include "global.h"
#include "GL/glut.h"
#include "iostream"
#include "math.h"
using namespace std;



/*
    全局变量定义处
*/
GLfloat SPIN = 0.0;
GLfloat COLOR_BLACK[3] = {0.0, 0.0, 0.0};
GLfloat COLOR_WHITE[3] = {1.0, 1.0, 1.0};
GLfloat COLOR_RED[3] = {1.0, 0.0, 0.0};
GLfloat COLOR_GREEN[3] = {0.0, 1.0, 0.0};
GLfloat COLOR_BLUE[3] = {0.0, 0.0, 1.0};
GLfloat COLOR_YELLOW[3] = {1.0, 1.0, 0.0};
GLfloat AXIS_LEN = 70.0;
float PI = 3.1415926;
float n_pyramid_r = 4.0;
float n_pyramid_h = 10.0;
float X_Y_Z_LEN = 5.0;








/*
    全局函数定义处
*/

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glFrontFace(GL_CCW);
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
            cout<<'a'<<endl;
            break;
        case 'b':
            cout<<'b'<<endl;
            break;
        default:
            break;
    }
}

void reshape(int w, int h){
    int t = min (w,h);
    glViewport (0, 0,  t, t);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ts = (float)t;
    glOrtho(-100, 100, -100, 100, 0.0, 200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void spinDisplay(void){
    SPIN = SPIN + 2.0;
    if (SPIN > 360.0)
        SPIN = SPIN - 360.0;
    glutPostRedisplay();
}

void draw_n_pyramid(int n){
    float temp1 = 2*PI/n;

    for(int i=0;i<n;++i){
        glBegin(GL_TRIANGLES);
            glVertex3f( n_pyramid_r*cos(temp1*i), n_pyramid_r*sin(temp1*i), 0.0 );
            glVertex3f( n_pyramid_r*cos(temp1*(i+1)), n_pyramid_r*sin(temp1*(i+1)), 0.0 );
            glVertex3f( 0.0, 0.0, n_pyramid_h );
        glEnd();
    }
    glBegin(GL_POLYGON);
        for(int i=n-1;i>=0;--i)
            glVertex3f( n_pyramid_r*cos(temp1*i), n_pyramid_r*sin(temp1*i), 0.0 );
    glEnd();
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
        glColor3fv(COLOR_YELLOW);
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
        glColor3fv(COLOR_BLUE);
        draw_n_pyramid(10);
    glPopMatrix();
}

void typeXYZ(){
    glLineWidth(3.0);
    glColor3fv(COLOR_RED);
    glBegin(GL_LINES);
        glVertex3f(-X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(X_Y_Z_LEN, -X_Y_Z_LEN, 0.0);
        glVertex3f(X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(-X_Y_Z_LEN, -X_Y_Z_LEN, 0.0);
    glEnd();

    glTranslatef(2*X_Y_Z_LEN+X_Y_Z_LEN/2, 0.0, 0.0);
    glColor3fv(COLOR_YELLOW);
    glBegin(GL_LINES);
        glVertex3f(-X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, -X_Y_Z_LEN, 0.0);
    glEnd();

    glTranslatef(2*X_Y_Z_LEN+X_Y_Z_LEN/2, 0.0, 0.0);
    glColor3fv(COLOR_BLUE);
    glBegin(GL_LINES);
        glVertex3f(-X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(-X_Y_Z_LEN, -X_Y_Z_LEN, 0.0);
        glVertex3f(-X_Y_Z_LEN, -X_Y_Z_LEN, 0.0);
        glVertex3f(X_Y_Z_LEN, -X_Y_Z_LEN, 0.0);
    glEnd();
}


















