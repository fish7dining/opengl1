#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED




void init(void);  //��ʼ��
//void mouse(int button, int state, int x, int y);  //������
void keyboard(unsigned char key,int x,int y);  //����
void reshape(int w,int h);  //���ڸı�
void spinDisplay(void);  //��ת
void draw_n_pyramid(int n);  //����׶��
void xyzAxis(void);  //����ά������
void typeXYZ();  //����ά����ϵXYZ����
void init2(void);
void q1(int x,int y,float color[4]);
void cube_rotate_Display(void);


#endif // FUNCTION_H_INCLUDED
