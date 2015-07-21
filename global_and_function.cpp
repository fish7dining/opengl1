#include "function.h"
#include "global.h"
#include "GL/glut.h"
#include "iostream"
#include "math.h"
using namespace std;



/*---- environment ---------*/
float View_Volume_Len = 100.0;
float Camera_Pos_X = 0.0;
float Camera_Pos_Y = 0.0;
float Camera_Pos_Z = 100.0;

/*---- color ---------*/
GLfloat COLOR_BLACK[4] = {0.0, 0.0, 0.0, 1.0};  //black
GLfloat COLOR_WHITE[4] = {1.0, 1.0, 1.0, 1.0}; //white
GLfloat COLOR_RED[4] = {1.0, 0.0, 0.0, 1.0};  //red
GLfloat COLOR_YELLOW[4] = {1.0, 1.0, 0.0, 1.0};  //yellow
GLfloat COLOR_GREEN[4] = {0.0, 1.0, 0.0, 1.0};  //green
GLfloat COLOR_BLUE[4] = {0.0, 0.0, 1.0, 1.0};  //blue
GLfloat COLOR_ORANGE[4] = {1.0, 0.528, 0.0, 1.0};  //orange

/*---- math ---------*/
float PI = 3.1415926;

/*---- letter X,Y,Z ---------*/
float X_Y_Z_LEN = 5.0;  //X Y Z三个字母的的边长

/*---- axis ---------*/
float AXIS_WIDTH = 3.0;  //the width of axis
float AXIS_LEN = 80.0;  //坐标轴正部分长度
float n_pyramid_r = 4.0;  //圆锥体底部的正多边形的半径
float n_pyramid_h = 10.0;  //圆锥体的高度

/*---- cube ---------*/
float COLOR_OF_CUBE[9][4][4];  //储存二阶魔方顔色信息
float CUBE_PER_ROTATE_ANGEL = 2.0;  //每次旋转的角度
float CUBE_NOW_ROTATE_ANGEL = 0.0;  //当前旋转的角度
float A_CUBE_LEN = 30.0;  //二阶魔角块的边长
float A_CUBE_LINE_WIDTH = 2.0;

/*---- rotation ---------*/
int WHICH_ROTATION = 1;  //1,2,3:up,front,right
int ROTATION_SPEED = 2;

/*---- mouse ---------*/
bool mouseLeftDown;
float mouseX, mouseY;
float AngleX, AngleY;
















/*---- environment settings ---------*/
void init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    colorInit();
}

void reshape(int w, int h){
    int t = min (w,h);
    glViewport (0, 0,  t, t);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-View_Volume_Len, View_Volume_Len, \
            -View_Volume_Len, View_Volume_Len, \
            1.1, 2*View_Volume_Len);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(Camera_Pos_X, Camera_Pos_Y, Camera_Pos_Z, \
              0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}




/*---- axis and letter X,Y,Z---------*/
void typeXYZ(){
    glPushMatrix();
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
    glPopMatrix();
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
    glLineWidth(AXIS_WIDTH);
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
    glLineWidth(AXIS_WIDTH);
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
    glLineWidth(AXIS_WIDTH);
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




/*---- draw the MagicCube ---------*/
void q1(int x,int y,float color[4]){  //give a color to a face.
    for(int i=0;i<4;++i)
        COLOR_OF_CUBE[x][y][i] = color[i];
}

void colorInit(void){  //initialize the color the MagicCube
    q1(1,1,COLOR_RED); q1(1,2,COLOR_BLUE); q1(1,3,COLOR_YELLOW);
    q1(2,1,COLOR_ORANGE); q1(2,2,COLOR_BLUE); q1(2,3,COLOR_YELLOW);
    q1(3,1,COLOR_ORANGE); q1(3,2,COLOR_BLUE); q1(3,3,COLOR_WHITE);
    q1(4,1,COLOR_RED); q1(4,2,COLOR_BLUE); q1(4,3,COLOR_WHITE);
    q1(5,1,COLOR_RED); q1(5,2,COLOR_GREEN); q1(5,3,COLOR_YELLOW);
    q1(6,1,COLOR_ORANGE); q1(6,2,COLOR_GREEN); q1(6,3,COLOR_YELLOW);
    q1(7,1,COLOR_ORANGE); q1(7,2,COLOR_GREEN); q1(7,3,COLOR_WHITE);
    q1(8,1,COLOR_RED); q1(8,2,COLOR_GREEN); q1(8,3,COLOR_WHITE);
}

void draw_a_cube_face(int whichFace, int kind){  //kind[1,2:line,quads]
    if(kind==1)
        glBegin(GL_LINE_LOOP);
    else
        glBegin(GL_QUADS);
    switch(whichFace){
        case 1:
            glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
            glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
            glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
            glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
            break;
        case 2:
            glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
            glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
            glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
            glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
            break;
        case 3:
            glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
            glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
            glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
            glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
            break;
        case 4:
            glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
            glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
            glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
            glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
            break;
        case 5:
            glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
            glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
            glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
            glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
            break;
        case 6:
            glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
            glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
            glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
            glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
            break;
        default:
            break;
    }
    glEnd();
}

void draw_a_cube(float c_up[4],float c_down[4],float c_front[4],float c_back[4],float c_left[4],float c_right[4]){
    //draw line FrameWork
    glLineWidth(A_CUBE_LINE_WIDTH);
    glColor4fv(COLOR_BLACK);
    draw_a_cube_face(1,1);
    draw_a_cube_face(2,1);
    draw_a_cube_face(3,1);
    draw_a_cube_face(4,1);
    draw_a_cube_face(5,1);
    draw_a_cube_face(6,1);

    //fill the color
    glColor4fv(c_up);
    draw_a_cube_face(1,2);
    glColor4fv(c_down);
    draw_a_cube_face(2,2);
    glColor4fv(c_front);
    draw_a_cube_face(3,2);
    glColor4fv(c_back);
    draw_a_cube_face(4,2);
    glColor4fv(c_left);
    draw_a_cube_face(5,2);
    glColor4fv(c_right);
    draw_a_cube_face(6,2);
}

void draw_MagicCube(int ope,float angel){  //ope[1,2,3:up,front,right]
    if( ope==1 ){
        glPushMatrix();
            glRotatef(angel, 0.0, 1.0, 0.0);
            glTranslatef(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
            draw_a_cube(COLOR_OF_CUBE[1][2], COLOR_WHITE, COLOR_OF_CUBE[1][1], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[1][3]);
            glTranslatef(0.0, 0.0, -A_CUBE_LEN);
            draw_a_cube(COLOR_OF_CUBE[2][2], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[2][1], COLOR_WHITE, COLOR_OF_CUBE[2][3]);
            glTranslatef(-A_CUBE_LEN, 0.0, 0.0);
            draw_a_cube(COLOR_OF_CUBE[3][2], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[3][1], COLOR_OF_CUBE[3][3], COLOR_WHITE);
            glTranslatef(0.0, 0.0, A_CUBE_LEN);
            draw_a_cube(COLOR_OF_CUBE[4][2], COLOR_WHITE, COLOR_OF_CUBE[4][1], COLOR_WHITE, COLOR_OF_CUBE[4][3], COLOR_WHITE);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[5][2], COLOR_OF_CUBE[5][1], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[5][3]);
            glTranslatef(0.0, 0.0, -A_CUBE_LEN);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[6][2], COLOR_WHITE, COLOR_OF_CUBE[6][1], COLOR_WHITE, COLOR_OF_CUBE[6][3]);
            glTranslatef(-A_CUBE_LEN, 0.0, 0.0);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[7][2], COLOR_WHITE, COLOR_OF_CUBE[7][1], COLOR_OF_CUBE[7][3], COLOR_WHITE);
            glTranslatef(0.0, 0.0, A_CUBE_LEN);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[8][2], COLOR_OF_CUBE[8][1], COLOR_WHITE, COLOR_OF_CUBE[8][3], COLOR_WHITE);
        glPopMatrix();
    }
    else if( ope==2 ){
        glPushMatrix();
            glRotatef(angel, 0.0, 0.0, -1.0);
            glTranslatef(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
            draw_a_cube(COLOR_OF_CUBE[1][2], COLOR_WHITE, COLOR_OF_CUBE[1][1], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[1][3]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
            draw_a_cube(COLOR_OF_CUBE[2][2], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[2][1], COLOR_WHITE, COLOR_OF_CUBE[2][3]);
            glTranslatef(-A_CUBE_LEN, 0.0, 0.0);
            draw_a_cube(COLOR_OF_CUBE[3][2], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[3][1], COLOR_OF_CUBE[3][3], COLOR_WHITE);
        glPopMatrix();
        glPushMatrix();
            glRotatef(angel, 0.0, 0.0, -1.0);
            glTranslatef(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
            draw_a_cube(COLOR_OF_CUBE[4][2], COLOR_WHITE, COLOR_OF_CUBE[4][1], COLOR_WHITE, COLOR_OF_CUBE[4][3], COLOR_WHITE);
        glPopMatrix();

        glPushMatrix();
            glRotatef(angel, 0.0, 0.0, -1.0);
            glTranslatef(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[5][2], COLOR_OF_CUBE[5][1], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[5][3]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[6][2], COLOR_WHITE, COLOR_OF_CUBE[6][1], COLOR_WHITE, COLOR_OF_CUBE[6][3]);
            glTranslatef(-A_CUBE_LEN, 0.0, 0.0);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[7][2], COLOR_WHITE, COLOR_OF_CUBE[7][1], COLOR_OF_CUBE[7][3], COLOR_WHITE);
        glPopMatrix();
        glPushMatrix();
            glRotatef(angel, 0.0, 0.0, -1.0);
            glTranslatef(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[8][2], COLOR_OF_CUBE[8][1], COLOR_WHITE, COLOR_OF_CUBE[8][3], COLOR_WHITE);
        glPopMatrix();
    }
    else{
        glPushMatrix();
            glRotatef(angel, -1.0, 0.0, 0.0);
            glTranslatef(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
            draw_a_cube(COLOR_OF_CUBE[1][2], COLOR_WHITE, COLOR_OF_CUBE[1][1], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[1][3]);
            glTranslatef(0.0, 0.0, -A_CUBE_LEN);
            draw_a_cube(COLOR_OF_CUBE[2][2], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[2][1], COLOR_WHITE, COLOR_OF_CUBE[2][3]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
            draw_a_cube(COLOR_OF_CUBE[3][2], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[3][1], COLOR_OF_CUBE[3][3], COLOR_WHITE);
            glTranslatef(0.0, 0.0, A_CUBE_LEN);
            draw_a_cube(COLOR_OF_CUBE[4][2], COLOR_WHITE, COLOR_OF_CUBE[4][1], COLOR_WHITE, COLOR_OF_CUBE[4][3], COLOR_WHITE);
        glPopMatrix();

        glPushMatrix();
            glRotatef(angel, -1.0, 0.0, 0.0);
            glTranslatef(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[5][2], COLOR_OF_CUBE[5][1], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[5][3]);
            glTranslatef(0.0, 0.0, -A_CUBE_LEN);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[6][2], COLOR_WHITE, COLOR_OF_CUBE[6][1], COLOR_WHITE, COLOR_OF_CUBE[6][3]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[7][2], COLOR_WHITE, COLOR_OF_CUBE[7][1], COLOR_OF_CUBE[7][3], COLOR_WHITE);
            glTranslatef(0.0, 0.0, A_CUBE_LEN);
            draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[8][2], COLOR_OF_CUBE[8][1], COLOR_WHITE, COLOR_OF_CUBE[8][3], COLOR_WHITE);
        glPopMatrix();
    }
}





/*---- Rotations of the MagicCube ---------*/
void tempToA(float temp[4], int x, int y){ // move temp -> color(x,y)
    COLOR_OF_CUBE[x][y][0] = temp[0];
    COLOR_OF_CUBE[x][y][1] = temp[1];
    COLOR_OF_CUBE[x][y][2] = temp[2];
    COLOR_OF_CUBE[x][y][3] = temp[3];
}

void ATotemp(int x, int y, float temp[4]){
    temp[0] = COLOR_OF_CUBE[x][y][0];
    temp[1] = COLOR_OF_CUBE[x][y][1];
    temp[2] = COLOR_OF_CUBE[x][y][2];
    temp[3] = COLOR_OF_CUBE[x][y][3];
}

void AToA(int x1, int y1, int x2, int y2){ // move color(x1,y1) -> color(x2,y2)
    float temps[4];
    ATotemp(x1, y1, temps);
    tempToA(temps, x2, y2);
}

void a_up_90_degree_color_change(){
    float t1[4], t2[4], t3[4];
    ATotemp(1, 1, t1);  ATotemp(1, 2, t2);  ATotemp(1, 3, t3);
    AToA(4, 3, 1, 1);  AToA(4, 2, 1, 2);  AToA(4, 1, 1, 3);
    AToA(3, 3, 4, 1);  AToA(3, 2, 4, 2);  AToA(3, 1, 4, 3);
    AToA(2, 3, 3, 1);  AToA(2, 2, 3, 2);  AToA(2, 1, 3, 3);
    tempToA(t1, 2, 3);  tempToA(t2, 2, 2);  tempToA(t3, 2, 1);
}

void a_front_90_degree_color_change(){
    float t1[4], t2[4], t3[4];
    ATotemp(1, 1, t1);  ATotemp(1, 2, t2);  ATotemp(1, 3, t3);
    AToA(4, 1, 1, 1);  AToA(4, 3, 1, 2);  AToA(4, 2, 1, 3);
    AToA(8, 1, 4, 1);  AToA(8, 3, 4, 2);  AToA(8, 2, 4, 3);
    AToA(5, 1, 8, 1);  AToA(5, 3, 8, 2);  AToA(5, 2, 8, 3);
    tempToA(t1, 5, 1);  tempToA(t2, 5, 3);  tempToA(t3, 5, 2);
}

void a_right_90_degree_color_change(){
    float t1[4], t2[4], t3[4];
    ATotemp(1, 1, t1);  ATotemp(1, 2, t2);  ATotemp(1, 3, t3);
    AToA(5, 2, 1, 1);  AToA(5, 1, 1, 2);  AToA(5, 3, 1, 3);
    AToA(6, 2, 5, 1);  AToA(6, 1, 5, 2);  AToA(6, 3, 5, 3);
    AToA(2, 2, 6, 1);  AToA(2, 1, 6, 2);  AToA(2, 3, 6, 3);
    tempToA(t1, 2, 2);  tempToA(t2, 2, 1);  tempToA(t3, 2, 3);
}

void a_90_degree(int angel){
    glutPostRedisplay();
    angel += CUBE_PER_ROTATE_ANGEL;
    CUBE_NOW_ROTATE_ANGEL += CUBE_PER_ROTATE_ANGEL;
    if( angel<90.0 ){
        glutTimerFunc(ROTATION_SPEED, a_90_degree, angel);
    }
    else{
        switch(WHICH_ROTATION){
            case 1:
                a_up_90_degree_color_change();
                CUBE_NOW_ROTATE_ANGEL = 0.0;
                glutPostRedisplay();
                break;
            case 2:
                a_front_90_degree_color_change();
                CUBE_NOW_ROTATE_ANGEL = 0.0;
                glutPostRedisplay();
                break;
            case 3:
                a_right_90_degree_color_change();
                CUBE_NOW_ROTATE_ANGEL = 0.0;
                glutPostRedisplay();
                break;
            default:
                break;
        }
    }
}

void a_180_degree(int angel){
    glutPostRedisplay();
    angel += CUBE_PER_ROTATE_ANGEL;
    CUBE_NOW_ROTATE_ANGEL += CUBE_PER_ROTATE_ANGEL;
    if( angel<180.0 ){
        glutTimerFunc(ROTATION_SPEED, a_180_degree, angel);
    }
    else{
        switch(WHICH_ROTATION){
            case 1:
                a_up_90_degree_color_change();
                a_up_90_degree_color_change();
                CUBE_NOW_ROTATE_ANGEL = 0.0;
                glutPostRedisplay();
                break;
            case 2:
                a_front_90_degree_color_change();
                a_front_90_degree_color_change();
                CUBE_NOW_ROTATE_ANGEL = 0.0;
                glutPostRedisplay();
                break;
            case 3:
                a_right_90_degree_color_change();
                a_right_90_degree_color_change();
                CUBE_NOW_ROTATE_ANGEL = 0.0;
                glutPostRedisplay();
                break;
            default:
                break;
        }
    }
}

void a_minus_90_degree(int angel){
    glutPostRedisplay();
    angel -= CUBE_PER_ROTATE_ANGEL;
    CUBE_NOW_ROTATE_ANGEL -= CUBE_PER_ROTATE_ANGEL;
    if( fabs(angel)<90.0 ){
        glutTimerFunc(ROTATION_SPEED, a_minus_90_degree, angel);
    }
    else{
        switch(WHICH_ROTATION){
            case 1:
                a_up_90_degree_color_change();
                a_up_90_degree_color_change();
                a_up_90_degree_color_change();
                CUBE_NOW_ROTATE_ANGEL = 0.0;
                glutPostRedisplay();
                break;
            case 2:
                a_front_90_degree_color_change();
                a_front_90_degree_color_change();
                a_front_90_degree_color_change();
                CUBE_NOW_ROTATE_ANGEL = 0.0;
                glutPostRedisplay();
                break;
            case 3:
                a_right_90_degree_color_change();
                a_right_90_degree_color_change();
                a_right_90_degree_color_change();
                CUBE_NOW_ROTATE_ANGEL = 0.0;
                glutPostRedisplay();
                break;
            default:
                break;
        }
    }
}

void rot1(int kind){ //rotate 90 degrees   [1,2,3 : up,front,right]
    CUBE_NOW_ROTATE_ANGEL = 0.0;
    switch( kind ){
        case 1:
            WHICH_ROTATION = 1;
            break;
        case 2:
            WHICH_ROTATION = 2;
            break;
        case 3:
            WHICH_ROTATION = 3;
            break;
        default:
            break;
    }
    glutTimerFunc(ROTATION_SPEED, a_90_degree, 0.0);
}

void rot2(int kind){ //rotate 180 degrees   [1,2,3 : up,front,right]

    CUBE_NOW_ROTATE_ANGEL = 0.0;
    switch( kind ){
        case 1:
            WHICH_ROTATION = 1;
            break;
        case 2:
            WHICH_ROTATION = 2;
            break;
        case 3:
            WHICH_ROTATION = 3;
            break;
        default:
            break;
    }
    glutTimerFunc(ROTATION_SPEED, a_180_degree, 0.0);
}

void rot3(int kind){ //rotate -90 degrees   [1,2,3 : up,front,right]
    CUBE_NOW_ROTATE_ANGEL = 0.0;
    switch( kind ){
        case 1:
            WHICH_ROTATION = 1;
            break;
        case 2:
            WHICH_ROTATION = 2;
            break;
        case 3:
            WHICH_ROTATION = 3;
            break;
        default:
            break;
    }
    glutTimerFunc(ROTATION_SPEED, a_minus_90_degree, 0.0);
}





/*---- Interaction with people ---------*/
void keyboard(unsigned char key,int x,int y){
    cout<<"q w e : U1 U2 U3"<<endl;
    cout<<"a s d : F1 F2 F3"<<endl;
    cout<<"z x c : R1 R2 R3"<<endl;
    cout<<"ESC to clear"<<endl;
    switch(key){
        case 'q':
            cout<<"U1"<<endl;
            rot1(1);
            break;
        case 'w':
            cout<<"U2"<<endl;
            rot2(1);
            break;
        case 'e':
            cout<<"U3"<<endl;
            rot3(1);
            break;
        case 'a':
            cout<<"F1"<<endl;
            rot1(2);
            break;
        case 's':
            cout<<"F2"<<endl;
            rot2(2);
            break;
        case 'd':
            cout<<"F3"<<endl;
            rot3(2);
            break;
        case 'z':
            cout<<"R1"<<endl;
            rot1(3);
            break;
        case 'x':
            cout<<"R2"<<endl;
            rot2(3);
            break;
        case 'c':
            cout<<"R3"<<endl;
            rot3(3);
            break;
        case 27:
            cout<<"ESC"<<endl;
            colorInit();
            glutPostRedisplay();
        default:
            break;
    }
}

void mouse(int button, int state, int x, int y){
    mouseX = x,  mouseY = y;
    if( button==GLUT_LEFT_BUTTON ){
        if( state==GLUT_DOWN )
            mouseLeftDown = true;
        else if( state==GLUT_UP )
            mouseLeftDown = false;
    }
}

void mouseMotion(int x, int y){
    if(mouseLeftDown){
        AngleY += (x-mouseX);
        AngleX += (y-mouseY);
        mouseX = x;
        mouseY = y;
    }
    glutPostRedisplay();
}





/*---- Main Display ---------*/
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(-AXIS_LEN*4/5, -AXIS_LEN*4/5, AXIS_LEN*4/5);
        typeXYZ();
    glPopMatrix();

    glPushMatrix();
        glRotatef(AngleX, 1.0, 0.0, 0.0);
        glRotatef(AngleY, 0.0, 1.0, 0.0);
        /*----------------------------------------*/
        glPushMatrix();
            xyzAxis();
        glPopMatrix();
        glPushMatrix();
            draw_MagicCube(WHICH_ROTATION, CUBE_NOW_ROTATE_ANGEL);
        glPopMatrix();
        /*----------------------------------------*/
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}




















