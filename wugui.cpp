#include <GL/glut.h>

#include <math.h>

const int n = 20;
const GLfloat R = 0.1f;
const GLfloat Pi = 3.1415926536f;



void myDisplay(void)
{
	
	glClearColor(1.0,1.0,1.0,1.0);//���ñ���Ϊ��ɫ
    glClear(GL_COLOR_BUFFER_BIT);
	 int i;
	glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    for(i=0; i<n; ++i)
        glVertex2f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i));
    glEnd();//ͷ  ��ɫ

   
	glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,-0.1);
    glVertex2f(-0.2,-0.2);
    glVertex2f(-0.2,-0.5);
    glVertex2f(0.0,-0.6);
    glVertex2f(0.2,-0.5);
	glVertex2f(0.2,-0.2);
	glEnd();//����  ��ɫ
	glColor3f(0.0,1.0,0.0);//��ɫ
	glRectf(-0.2f, -0.2f, -0.1f, -0.1f);//���
	glBegin(GL_POLYGON);
	glVertex2f(-0.2,-0.5);
	glVertex2f(-0.1,-0.5);
	glVertex2f(-0.1,-0.6);
    glVertex2f(-0.2,-0.6);
	glEnd();//���
	glBegin(GL_POLYGON);
	glVertex2f(0.2,-0.5);
    glVertex2f(0.1,-0.5);
    glVertex2f(0.1,-0.6);
    glVertex2f(0.2,-0.6);
	glEnd();//�ҽ�
	glBegin(GL_POLYGON);
	glVertex2f(0.1,-0.2);
    glVertex2f(0.2,-0.2);
    glVertex2f(0.2,-0.1);
    glVertex2f(0.1,-0.1);
	glEnd();//�ҽ�
    glLineWidth(5.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(0.0,-0.6);
    glVertex2f(0.0,-0.7);
	glEnd();//β��
	glBegin(GL_LINES);
	glVertex2f(-0.06,0.06);
    glVertex2f(-0.02,0.06);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.02,0.06);
    glVertex2f(0.06,0.06);
	glEnd();//�۾�
	glFlush();


}

void reshape(int w, int h)
{
	glViewport(0, 0, 400, 400); //Ĭ�ϵ�glViewport��width���ڴ��ڵĿ��,height���ڴ��ڵĸ߶�;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}


 


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("С�ڹ�");
    glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}