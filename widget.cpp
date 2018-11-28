#include "widget.h"

#define expr x

const int X_COORD = 50;// X - ����������� ] ������
const int Y_COORD = 50;// Y - ����������� ] ���� �������
const float ITERATIONS = 0.00005;// ���������� ������� (��� ������ ��� �����)

int x_off = X_COORD / 2;// ������
int y_off = Y_COORD / 2;// ��� ���������

Widget::Widget(QWidget *parent)
    : QGLWidget(parent)
{
    resize(300,300);
}

void Widget::initializeGL()
{
   qglClearColor(Qt::white);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_FLAT);
   glEnable(GL_CULL_FACE);
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void Widget::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, nHeight, nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void drawgrid(float SERIF_OFFSET, float SERIF_DISTANCE) {
    glBegin(GL_LINES);
        //������ �����
        glColor3f(0.0, 0.0, 0.0);

        //������ ������������ ���
        //�����������
        glVertex2f(0.0, Y_COORD / 2);
        glVertex2f(X_COORD, Y_COORD / 2);
        //������� �� �����������
        int p = X_COORD / 2;
        for(int i = X_COORD / 2; i < X_COORD; i += SERIF_DISTANCE, p -= SERIF_DISTANCE) {
            glVertex2f(i, Y_COORD / 2);
            glVertex2f(i, Y_COORD / 2 + SERIF_OFFSET);

            glVertex2f(p, Y_COORD / 2);
            glVertex2f(p, Y_COORD / 2 + SERIF_OFFSET);
        }
        //���������
        int t = Y_COORD / 2;
        glVertex2f(X_COORD / 2, Y_COORD);
        glVertex2f(X_COORD / 2, 0.0);
        //������� �� ���������
        for(int i = Y_COORD / 2; i < Y_COORD; i += SERIF_DISTANCE, t -= SERIF_DISTANCE) {
            glVertex2f(X_COORD / 2, i);
            glVertex2f(Y_COORD / 2 + SERIF_OFFSET, i);

            glVertex2f(X_COORD / 2, t);
            glVertex2f(Y_COORD / 2 + SERIF_OFFSET, t);
        }
    glEnd();
}

void drawfunc() {
    //������ ������
    glBegin(GL_POINTS);
        float j = 0;
        glColor3f(0.8, 0.0, 0.8);
        for(float x = -X_COORD * 2; x < X_COORD * 2; x += ITERATIONS) {
            //��������������� ����������
            j = expr;
            glVertex2f(x_off + x, y_off + j);//�� ������� x � y!! ��� ������ �� ����!
        }
    glEnd();
}

void Widget::paintGL() // ���������
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������� ������ ����������� � �������

//   glMatrixMode(GL_MODELVIEW); // ������������� ��������� � ���������� ������� �������������
//   glLoadIdentity();           // ��������� ��������� ������� �������������

//   QColor halfGreen(0, 128, 0, 255);
//   qglColor(halfGreen);
//   glBegin(GL_QUADS);
//   glVertex3f(0.5, 0.5, 0.5);
//   glVertex3f(-0.5, 0.5, 0.5);
//   glVertex3f(-0.5, -0.5, 0.5);
//   glVertex3f(0.5, -0.5, 0.5);

   drawgrid(0.3, 5);
   drawfunc();




   glEnd();

}
