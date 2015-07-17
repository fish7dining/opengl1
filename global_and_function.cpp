#include "function.h"
#include "global.h"
#include "GL/glut.h"
#include "iostream"
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


/*
    全局函数定义处
*/

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
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
    cout<<ts<<endl;
    glOrtho(-ts/2, ts/2, -ts/2, ts, 0.0, ts);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, ts/2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void spinDisplay(void){
    SPIN = SPIN + 2.0;
    if (SPIN > 360.0)
        SPIN = SPIN - 360.0;
    glutPostRedisplay();
}




















