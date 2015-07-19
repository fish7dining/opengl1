#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED




void init(void);  //初始化
void mouse(int button, int state, int x, int y);  //鼠标操作
void keyboard(unsigned char key,int x,int y);  //键盘
void reshape(int w,int h);  //窗口改变
void spinDisplay(void);  //旋转
void draw_n_pyramid(int n);  //画立锥体
void xyzAxis(void);  //画三维坐标轴
void typeXYZ();  //画三维坐标系XYZ标语
void init2(void);
void q1(int x,int y,float color[4]);
void cube_rotate_Display(void);


#endif // FUNCTION_H_INCLUDED
