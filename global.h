#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include "GL/glut.h"


extern GLfloat SPIN;  //旋转角度

extern GLfloat COLOR_BLACK[4];  //黑色
extern GLfloat COLOR_WHITE[4];  //白色
extern GLfloat COLOR_RED[4];  //红色
extern GLfloat COLOR_GREEN[4];  //绿色
extern GLfloat COLOR_YELLOW[4];  //黄色
extern GLfloat COLOR_BLUE[4];  //蓝色

extern GLfloat AXIS_LEN;  //坐标轴正部分长度
extern float PI;
extern float n_pyramid_r;  //圆锥体底部的正多边形的半径
extern float n_pyramid_h;  //圆锥体的高度
extern float X_Y_Z_LEN;  //X Y Z三个字母的的边长
extern float A_CUBE_LEN;  //二阶魔角块的边长
extern float CUBE_PER_ROTATE_ANGEL;  //每次旋转的角度
extern float CUBE_NOW_ROTATE_ANGEL;  //当前旋转的角度
extern int WHICH_ROTATION;

extern GLfloat COLOR_OF_CUBE[9][4][4];  //储存二阶魔方顔色信息

#endif // GLOBAL_H_INCLUDED
