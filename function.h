#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED




void init(void);  //初始化
void reshape(int w,int h);  //窗口改变

void typeXYZ();  //画三维坐标系XYZ标语
void draw_n_pyramid(int n);  //画立锥体
void xyzAxis(void);  //画三维坐标轴

void q1(int x,int y,float color[4]);  //give a color to a face.
void colorInit(void);  //initialize the color the MagicCube
void draw_a_cube_face(int whichFace, int kind);  //kind[1,2:line,quads]
void draw_a_cube(float c_up[4],float c_down[4],float c_front[4],float c_back[4],float c_left[4],float c_right[4]);
void draw_MagicCube(int ope,float angel);  //ope[1,2,3:up,front,right]

void tempToA(float temp[4], int x, int y);  // move temp -> color(x,y)
void ATotemp(int x, int y, float temp[4]);
void AToA(int x1, int y1, int x2, int y2);  // move color(x1,y1) -> color(x2,y2)
void a_up_90_degree_color_change();
void a_front_90_degree_color_change();
void a_right_90_degree_color_change();
void a_90_degree(int angel);
void a_180_degree(int angel);
void a_minus_90_degree(int angel);
void rot1(int kind);  //rotate 90 degrees   [1,2,3 : up,front,right]
void rot2(int kind);  //rotate 180 degrees   [1,2,3 : up,front,right]
void rot3(int kind);  //rotate -90 degrees   [1,2,3 : up,front,right]

void keyboard(unsigned char key,int x,int y);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

void display();




#endif // FUNCTION_H_INCLUDED
