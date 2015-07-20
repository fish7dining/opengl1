#include "GL/glut.h"
#include "global.h"
#include "function.h"
#include "iostream"
#include "stdio.h"
#include "math.h"
using namespace std;




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
    if(fabs(angel)==0.0 || fabs(angel-90.0)==0.0){
        glTranslatef(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
        draw_a_cube(COLOR_OF_CUBE[1][2], COLOR_WHITE, COLOR_OF_CUBE[1][1], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[1][3]);
        glTranslatef(0.0, 0.0, -A_CUBE_LEN);
        draw_a_cube(COLOR_OF_CUBE[2][2], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[2][1], COLOR_WHITE, COLOR_OF_CUBE[2][3]);
        glTranslatef(-A_CUBE_LEN, 0.0, 0.0);
        draw_a_cube(COLOR_OF_CUBE[3][2], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[3][1], COLOR_OF_CUBE[3][3], COLOR_WHITE);
        glTranslatef(0.0, 0.0, A_CUBE_LEN);
        draw_a_cube(COLOR_OF_CUBE[4][2], COLOR_WHITE, COLOR_OF_CUBE[4][1], COLOR_WHITE, COLOR_OF_CUBE[1][4], COLOR_WHITE);

        glTranslatef(A_CUBE_LEN, -A_CUBE_LEN, 0.0);
        draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[5][2], COLOR_OF_CUBE[5][1], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[5][3]);
        glTranslatef(0.0, 0.0, -A_CUBE_LEN);
        draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[6][2], COLOR_WHITE, COLOR_OF_CUBE[6][1], COLOR_WHITE, COLOR_OF_CUBE[6][3]);
        glTranslatef(-A_CUBE_LEN, 0.0, 0.0);
        draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[7][2], COLOR_WHITE, COLOR_OF_CUBE[7][1], COLOR_OF_CUBE[7][3], COLOR_WHITE);
        glTranslatef(0.0, 0.0, A_CUBE_LEN);
        draw_a_cube(COLOR_WHITE, COLOR_OF_CUBE[8][2], COLOR_OF_CUBE[8][1], COLOR_WHITE, COLOR_OF_CUBE[8][3], COLOR_WHITE);
    }
    else{
        switch(ope){
        case 1:  //U cw
            glPushMatrix();
                glRotatef(angel, 0.0, 1.0, 0.0);
                glTranslatef(A_CUBE_LEN/2, A_CUBE_LEN/2, A_CUBE_LEN/2);
                draw_a_cube(COLOR_OF_CUBE[1][2], COLOR_WHITE, COLOR_OF_CUBE[1][1], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[1][3]);
                glTranslatef(0.0, 0.0, -A_CUBE_LEN);
                draw_a_cube(COLOR_OF_CUBE[2][2], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[2][1], COLOR_WHITE, COLOR_OF_CUBE[2][3]);
                glTranslatef(-A_CUBE_LEN, 0.0, 0.0);
                draw_a_cube(COLOR_OF_CUBE[3][2], COLOR_WHITE, COLOR_WHITE, COLOR_OF_CUBE[3][1], COLOR_OF_CUBE[3][3], COLOR_WHITE);
                glTranslatef(0.0, 0.0, A_CUBE_LEN);
                draw_a_cube(COLOR_OF_CUBE[4][2], COLOR_WHITE, COLOR_OF_CUBE[4][1], COLOR_WHITE, COLOR_OF_CUBE[4][1], COLOR_WHITE);
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
            break;
        case 2:  //F cw
            break;
        case 3:  //R cw
            break;
        default:
            break;
        }
    }
}



//开始绘制
void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(-AXIS_LEN*4/5, -AXIS_LEN*4/5, AXIS_LEN*4/5);
        typeXYZ();
    glPopMatrix();

    glPushMatrix();
    glRotatef(SPIN, 0.0, 1.0, 0.0);
    //----------------------------------------

    glPushMatrix();
        xyzAxis();
    glPopMatrix();
    glPushMatrix();
        draw_MagicCube(1, CUBE_NOW_ROTATE_ANGEL);
    glPopMatrix();

    //----------------------------------------
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}







void a_90_degree(int angel){
    glutPostRedisplay();
    angel += CUBE_PER_ROTATE_ANGEL;
    CUBE_NOW_ROTATE_ANGEL += CUBE_PER_ROTATE_ANGEL;
    if( fabs(angel)<=90.0 ){
        glutTimerFunc(30, a_90_degree, angel);
    }
}


void U1(){
    CUBE_NOW_ROTATE_ANGEL = 0.0;
    glutTimerFunc(30, a_90_degree, 0.0);
}
void U2(){
    CUBE_NOW_ROTATE_ANGEL = 0.0;
    glutTimerFunc(30, a_90_degree, 0.0);
    glutTimerFunc(30, a_90_degree, 0.0);
}
void U3(){
    CUBE_PER_ROTATE_ANGEL = -CUBE_PER_ROTATE_ANGEL;
    CUBE_NOW_ROTATE_ANGEL = 0.0;
    glutTimerFunc(30, a_90_degree, 0.0);
}


void keyboard(unsigned char key,int x,int y){
    switch(key){
        case 'a':
            U1();
            cout<<'U1'<<endl;
            break;
        case 'b':
            U2();
            cout<<'U2'<<endl;
            break;
        case 'c':
            U3();
            cout<<'U3'<<endl;
            break;
        case 'd':
            cout<<'F1'<<endl;
            break;
        case 'e':
            cout<<'F2'<<endl;
            break;
        case 'f':
            cout<<'F3'<<endl;
            break;
        case 'g':
            cout<<'R1'<<endl;
            break;
        case 'h':
            cout<<'R2'<<endl;
            break;
        case 'i':
            cout<<'R3'<<endl;
            break;
        default:
            break;
    }
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











