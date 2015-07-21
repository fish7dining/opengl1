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
GLfloat COLOR_BLACK[4] = {0.0, 0.0, 0.0, 1.0};
GLfloat COLOR_WHITE[4] = {1.0, 1.0, 1.0, 1.0};
GLfloat COLOR_RED[4] = {1.0, 0.0, 0.0, 1.0};
GLfloat COLOR_YELLOW[4] = {1.0, 1.0, 0.0, 1.0};
GLfloat COLOR_BLUE[4] = {0.0, 0.0, 1.0, 1.0};
GLfloat COLOR_GREEN[4] = {0.0, 1.0, 0.0, 1.0};
GLfloat COLOR_ORANGE[4] = {1.0, 0.647, 0.0, 1.0};
GLfloat AXIS_LEN = 80.0;
float PI = 3.1415926;
float n_pyramid_r = 4.0;
float n_pyramid_h = 10.0;
float X_Y_Z_LEN = 5.0;
float A_CUBE_LEN = 30.0;
float CUBE_PER_ROTATE_ANGEL = 2.0;
float CUBE_NOW_ROTATE_ANGEL = 0.0;
int WHICH_ROTATION = 1;



GLfloat COLOR_OF_CUBE[9][4][4];








/*
    全局函数定义处
*/

void init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    init2();
}

//给某个角块的某个方向赋值上颜色（数据结构）
void q1(int x,int y,float color[4]){
    for(int i=0;i<4;++i)
        COLOR_OF_CUBE[x][y][i] = color[i];
}

void init2(void){
    q1(1,1,COLOR_RED); q1(1,2,COLOR_BLUE); q1(1,3,COLOR_YELLOW);
    q1(2,1,COLOR_ORANGE); q1(2,2,COLOR_BLUE); q1(2,3,COLOR_YELLOW);
    q1(3,1,COLOR_ORANGE); q1(3,2,COLOR_BLUE); q1(3,3,COLOR_WHITE);
    q1(4,1,COLOR_RED); q1(4,2,COLOR_BLUE); q1(4,3,COLOR_WHITE);
    q1(5,1,COLOR_RED); q1(5,2,COLOR_GREEN); q1(5,3,COLOR_YELLOW);
    q1(6,1,COLOR_ORANGE); q1(6,2,COLOR_GREEN); q1(6,3,COLOR_YELLOW);
    q1(7,1,COLOR_ORANGE); q1(7,2,COLOR_GREEN); q1(7,3,COLOR_WHITE);
    q1(8,1,COLOR_RED); q1(8,2,COLOR_GREEN); q1(8,3,COLOR_WHITE);
}






void reshape(int w, int h){
    int t = min (w,h);
    glViewport (0, 0,  t, t);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, 1.1, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(40.0, 40.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void spinDisplay(void){
    SPIN = SPIN + 2.0;
    if (SPIN > 360.0)
        SPIN = SPIN - 360.0;
    glutPostRedisplay();
}

void cube_rotate_Display(void){
    CUBE_NOW_ROTATE_ANGEL = CUBE_NOW_ROTATE_ANGEL += CUBE_PER_ROTATE_ANGEL;
    if(CUBE_NOW_ROTATE_ANGEL > 180.0)
        CUBE_NOW_ROTATE_ANGEL = CUBE_NOW_ROTATE_ANGEL - 180.0;
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
    glColor4fv(COLOR_BLACK);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(-AXIS_LEN*2/3, 0.0, 0.0);
        glVertex3f(AXIS_LEN, 0.0, 0.0);
    glEnd();
    glPushMatrix();
        glTranslatef(AXIS_LEN, 0.0, 0.0);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        glLineWidth(1.0);
        glColor4fv(COLOR_RED);
        draw_n_pyramid(10);
    glPopMatrix();

    //y axis
    glColor4fv(COLOR_BLACK);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, -AXIS_LEN*2/3, 0.0);
        glVertex3f(0.0, AXIS_LEN, 0.0);
    glEnd();
    glPushMatrix();
        glTranslatef(0.0, AXIS_LEN, 0.0);
        glRotatef(90.0, -1.0, 0.0, 0.0);
        glLineWidth(1.0);
        glColor4fv(COLOR_GREEN);
        draw_n_pyramid(10);
    glPopMatrix();

    //z axis
    glColor4fv(COLOR_BLACK);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, -AXIS_LEN*2/3);
        glVertex3f(0.0, 0.0, AXIS_LEN);
    glEnd();
    glPushMatrix();
        glTranslatef(0.0, 0.0, AXIS_LEN);
        glLineWidth(1.0);
        glColor4fv(COLOR_BLUE);
        draw_n_pyramid(10);
    glPopMatrix();
}

void typeXYZ(){
    glLineWidth(3.0);
    glColor4fv(COLOR_RED);
    glBegin(GL_LINES);
        glVertex3f(-X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(X_Y_Z_LEN, -X_Y_Z_LEN, 0.0);
        glVertex3f(X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(-X_Y_Z_LEN, -X_Y_Z_LEN, 0.0);
    glEnd();

    glTranslatef(2*X_Y_Z_LEN+X_Y_Z_LEN/2, 0.0, 0.0);
    glColor4fv(COLOR_GREEN);
    glBegin(GL_LINES);
        glVertex3f(-X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, -X_Y_Z_LEN, 0.0);
    glEnd();

    glTranslatef(2*X_Y_Z_LEN+X_Y_Z_LEN/2, 0.0, 0.0);
    glColor4fv(COLOR_BLUE);
    glBegin(GL_LINES);
        glVertex3f(-X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(X_Y_Z_LEN, X_Y_Z_LEN, 0.0);
        glVertex3f(-X_Y_Z_LEN, -X_Y_Z_LEN, 0.0);
        glVertex3f(-X_Y_Z_LEN, -X_Y_Z_LEN, 0.0);
        glVertex3f(X_Y_Z_LEN, -X_Y_Z_LEN, 0.0);
    glEnd();
}


















