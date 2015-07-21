#include "GL/glut.h"
#include "global.h"
#include "function.h"
#include "iostream"
#include "stdio.h"
#include "math.h"
using namespace std;


bool mouseLeftDown;
float mouseX, mouseY;
float AngleX, AngleY;
float lastAngleX, lastAngleY;



void draw_a_cube(float c_up[4],float c_down[4],float c_front[4],float c_back[4],float c_left[4],float c_right[4]){
    glLineWidth(3.0);
    glColor4fv(COLOR_BLACK);
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





    glBegin(GL_QUADS);
        glColor4fv(c_up);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glColor4fv(COLOR_BLACK);
        glColor4fv(c_down);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);

        glColor4fv(c_front);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);

        glColor4fv(c_back);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);

        glColor4fv(c_left);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(-A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);

        glColor4fv(c_right);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, -A_CUBE_LEN/2, -A_CUBE_LEN/2);
        glVertex3f(A_CUBE_LEN/2, A_CUBE_LEN/2, -A_CUBE_LEN/2);
    glEnd();



}

void draw_MagicCube(int ope,float angel){
    if( ope==1){
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



//¿ªÊ¼»æÖÆ
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(-AXIS_LEN*4/5, -AXIS_LEN*4/5, AXIS_LEN*4/5);
        typeXYZ();
    glPopMatrix();

    glPushMatrix();
    glRotatef(AngleY, 0.0, 1.0, 0.0);
    glRotatef(AngleX, 1.0, 0.0, 0.0);
    //glRotatef(AngleY, sin(lastAngleY), cos(lastAngleY), 0.0);
    //glRotatef(AngleX, sin(lastAngleX), cos(lastAngleX), 0.0);
    //----------------------------------------

    glPushMatrix();
        xyzAxis();
    glPopMatrix();
    glPushMatrix();
        draw_MagicCube(WHICH_ROTATION, CUBE_NOW_ROTATE_ANGEL);
    glPopMatrix();

    //----------------------------------------
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}









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

int SPEED = 10;

void a_90_degree(int angel){
    glutPostRedisplay();
    angel += CUBE_PER_ROTATE_ANGEL;
    CUBE_NOW_ROTATE_ANGEL += CUBE_PER_ROTATE_ANGEL;
    if( angel<90.0 ){
        glutTimerFunc(SPEED, a_90_degree, angel);
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
        glutTimerFunc(SPEED, a_180_degree, angel);
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
        glutTimerFunc(SPEED, a_minus_90_degree, angel);
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

//rotate cw 90 degrees
void rot1(int kind){ //1:up 2:front 3:right

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
    glutTimerFunc(SPEED, a_90_degree, 0.0);
}

//rotate cw 180 degrees
void rot2(int kind){ //1:up 2:front 3:right

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
    glutTimerFunc(SPEED, a_180_degree, 0.0);
}

//rotate ccw 90 degrees
void rot3(int kind){ //1:up 2:front 3:right
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
    glutTimerFunc(SPEED, a_minus_90_degree, 0.0);
}



void keyboard(unsigned char key,int x,int y){
    cout<<"q w e : U1 U2 U3"<<endl;
    cout<<"a s d : F1 F2 F3"<<endl;
    cout<<"z x c : R1 R2 R3"<<endl;
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
            cout<<"esc"<<endl;
            init2();
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
        lastAngleX = AngleX;
        lastAngleY = AngleY;
        AngleY += (x-mouseX);
        AngleX += (y-mouseY);
        mouseX = x;
        mouseY = y;
    }
    glutPostRedisplay();
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
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}











