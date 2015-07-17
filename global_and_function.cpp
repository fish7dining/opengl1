#include "function.h"
#include "global.h"
#include "GL/glut.h"
#include "iostream"
using namespace std;



/*
    全局变量定义处
*/
GLfloat spin = 0.0;  //旋转角度





/*
    全局函数定义处
*/
//初始化
void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
}

//鼠标操作
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

//键盘
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

//窗口改变
void reshape(int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, 1.0, 201.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 101.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

//旋转
void spinDisplay(void){
    spin = spin + 2.0;
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}




















