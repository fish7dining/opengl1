#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include "GL/glut.h"




/*---- environment ---------*/
extern float View_Volume_Len;
extern float Camera_Pos_X;
extern float Camera_Pos_Y;
extern float Camera_Pos_Z;

/*---- color ---------*/
extern GLfloat COLOR_BLACK[4];  //black
extern GLfloat COLOR_WHITE[4];  //white
extern GLfloat COLOR_RED[4];  //red
extern GLfloat COLOR_YELLOW[4];  //yellow
extern GLfloat COLOR_GREEN[4];  //green
extern GLfloat COLOR_BLUE[4];  //blue
extern GLfloat COLOR_ORANGE[4];  //orange

/*---- math ---------*/
extern float PI;

/*---- letter X,Y,Z ---------*/
extern float X_Y_Z_LEN;  //X Y Z三个字母的的边长

/*---- axis ---------*/
extern GLfloat AXIS_LEN;  //坐标轴正部分长度
extern float n_pyramid_r;  //圆锥体底部的正多边形的半径
extern float n_pyramid_h;  //圆锥体的高度

/*---- cube ---------*/
extern GLfloat COLOR_OF_CUBE[9][4][4];  //储存二阶魔方顔色信息
extern float CUBE_PER_ROTATE_ANGEL;  //每次旋转的角度
extern float CUBE_NOW_ROTATE_ANGEL;  //当前旋转的角度
extern float A_CUBE_LEN;  //二阶魔角块的边长
extern float A_CUBE_LINE_WIDTH;

/*---- rotation ---------*/
extern int WHICH_ROTATION;  //1,2,3:up,front,right
extern int ROTATION_SPEED;

/*---- mouse ---------*/
extern bool mouseLeftDown;
extern float mouseX, mouseY;
extern float AngleX, AngleY;





#endif // GLOBAL_H_INCLUDED
