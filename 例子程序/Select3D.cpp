#include <GL/glut.h>

GLuint selectedIndex=0;	 //���ж����ID

void drawobjects(GLenum mode)
{
	if(mode==GL_SELECT)
		glLoadName(1);   //���������ƵĶ���IDΪ1

	if(selectedIndex==1) //��ѡ��
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(-0.5, 0.0, 0.0);
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();

	if(mode==GL_SELECT)
		glLoadName(2);   //���������ƵĶ���IDΪ2

	if(selectedIndex==2) //��ѡ��
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(0.0, 1.0, 0.0);

	glPushMatrix();
	glTranslatef(0.5, 0.0, 0.0);
	glutSolidTeapot(0.5);
	glPopMatrix();

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawobjects(GL_RENDER);
		
	glutSwapBuffers();
}

void myinit()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void processHits (GLint hits, GLuint buffer[])
{
	GLuint mindepth=0;
	mindepth=~mindepth;			// GLuint �����ֵ

	// hit ������������
	GLuint *ptr, nums, zmin, zmax, name;
	ptr = buffer;
	
	selectedIndex = 0; //��ʼ��Ϊ0
    for (int i = 0; i < hits; i++) 
	{
		// number of names for this hit
		// �ڱ������� nums=1
		nums = *ptr;	
		
        ptr++;	zmin = *ptr;	
		ptr++;	zmax = *ptr;
        
		// �ڱ������� nums=1, ����ѭ��
		ptr++;  name = *ptr;
		
		// ѡ�����ӵ�����Ķ���
		if(mindepth>zmin)
		{
			mindepth=zmin;
			selectedIndex=name;
		}
		
		// ��һ�� hit
		ptr++;
	}

}

#define SIZE 512

void mouse(int button, int state, int x, int y)
{	
	GLuint selectBuf[SIZE];
	GLint hits;
	GLint viewport[4];
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) //���������½���ѡ��ģʽ
	{
		glGetIntegerv (GL_VIEWPORT, viewport); //��õ�ǰ��viewport,����gluPickMatrix
		
		glSelectBuffer (SIZE, selectBuf);    //�趨����
		glRenderMode(GL_SELECT); //����ѡ��ģʽ
		
		glInitNames();  //��ʼ�����ƶ�ջ
		glPushName(-1); //���ƻ������з���id (û�л����κζ���,������-1��ʾ)
		
		glMatrixMode (GL_PROJECTION); 
		glPushMatrix (); //���浱ǰͶӰ������Ϊ���������Ӿ��壬���Ӿ�����Ϊ��긽����

		glLoadIdentity (); //�ѵ�ǰͶӰ������Ϊ��λ����
		/* create 2x2 pixel picking region near cursor location */
		gluPickMatrix ((GLdouble) x, (GLdouble) (viewport[3] - y),
			2.0, 2.0, viewport);  //�ı���ͼ������ʹ��ֻ�п������ָ��Ķ���λ���µ��Ӿ�����
		glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); //���������Ӿ��壬�����ƶ���ʱ���״̬����һ��

		drawobjects(GL_SELECT);		//��ѡ��ģʽ���ػ������ʱ�����ӵ��ID
		
		glMatrixMode (GL_PROJECTION);
		glPopMatrix ();  //�ָ�ԭ����ͶӰ����

		glMatrixMode(GL_MODELVIEW);  //�ָ���ǰ����ģʽΪModelview
		
		hits = glRenderMode (GL_RENDER); //�˳�ѡ��ģʽ���õ����ж������
		processHits (hits, selectBuf);   //���ݻ��ж���������ͻ��м�¼���棬�õ���ǰѡ�еĶ���
		
		glutPostRedisplay();
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);      
	glutInitWindowSize(500,500);    	
	glutInitWindowPosition(0,0); 
	glutCreateWindow("Select 3D");     
	glutDisplayFunc(display); 
    glutMouseFunc (mouse);
	glutReshapeFunc(reshape); 
	myinit(); 
	glutMainLoop();
	return 1;
}