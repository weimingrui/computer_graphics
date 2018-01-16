#include <GL/glut.h>

#include <math.h>

const int n = 20;
const GLfloat R = 0.1f;
const GLfloat Pi = 3.1415926536f;



void myDisplay(void)
{
	
	glClearColor(1.0,1.0,1.0,1.0);//设置背景为白色
    glClear(GL_COLOR_BUFFER_BIT);
	 int i;
	glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    for(i=0; i<n; ++i)
        glVertex2f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i));
    glEnd();//头  黄色

   
	glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,-0.1);
    glVertex2f(-0.2,-0.2);
    glVertex2f(-0.2,-0.5);
    glVertex2f(0.0,-0.6);
    glVertex2f(0.2,-0.5);
	glVertex2f(0.2,-0.2);
	glEnd();//身体  黑色
	glColor3f(0.0,1.0,0.0);//绿色
	glRectf(-0.2f, -0.2f, -0.1f, -0.1f);//左脚
	glBegin(GL_POLYGON);
	glVertex2f(-0.2,-0.5);
	glVertex2f(-0.1,-0.5);
	glVertex2f(-0.1,-0.6);
    glVertex2f(-0.2,-0.6);
	glEnd();//左脚
	glBegin(GL_POLYGON);
	glVertex2f(0.2,-0.5);
    glVertex2f(0.1,-0.5);
    glVertex2f(0.1,-0.6);
    glVertex2f(0.2,-0.6);
	glEnd();//右脚
	glBegin(GL_POLYGON);
	glVertex2f(0.1,-0.2);
    glVertex2f(0.2,-0.2);
    glVertex2f(0.2,-0.1);
    glVertex2f(0.1,-0.1);
	glEnd();//右脚
    glLineWidth(5.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(0.0,-0.6);
    glVertex2f(0.0,-0.7);
	glEnd();//尾巴
	glBegin(GL_LINES);
	glVertex2f(-0.06,0.06);
    glVertex2f(-0.02,0.06);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.02,0.06);
    glVertex2f(0.06,0.06);
	glEnd();//眼睛
	glFlush();


}

void reshape(int w, int h)
{
	glViewport(0, 0, 400, 400); //默认的glViewport的width等于窗口的宽度,height等于窗口的高度;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}


 


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("小乌龟");
    glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}