#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include "GL/glut.h"


extern GLfloat SPIN;  //旋转角度

extern GLfloat COLOR_BLACK[3];  //黑色
extern GLfloat COLOR_WHITE[3];  //白色
extern GLfloat COLOR_RED[3];  //红色
extern GLfloat COLOR_GREEN[3];  //绿色
extern GLfloat COLOR_YELLOW[3];  //黄色
extern GLfloat COLOR_BLUE[3];  //蓝色

extern GLfloat AXIS_LEN;  //坐标轴正部分长度
extern float PI;
extern float n_pyramid_r;  //圆锥体底部的正多边形的半径
extern float n_pyramid_h;  //圆锥体的高度
extern float X_Y_Z_LEN;  //X Y Z三个字母的的边长
extern float A_CUBE_LEN;  //二阶魔角块的边长

extern GLfloat COLOR_OF_CUBE[9][4][3];  //储存二阶魔方顔色信息

#endif // GLOBAL_H_INCLUDED
