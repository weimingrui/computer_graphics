#include <GL/glut.h>

GLuint selectedIndex=0;	 //击中对象的ID

void drawobjects(GLenum mode)
{
	if(mode==GL_SELECT)
		glLoadName(1);   //接下来绘制的对象ID为1

	if(selectedIndex==1) //被选中
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(-0.5, 0.0, 0.0);
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();

	if(mode==GL_SELECT)
		glLoadName(2);   //接下来绘制的对象ID为2

	if(selectedIndex==2) //被选中
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
	mindepth=~mindepth;			// GLuint 的最大值

	// hit 产生的数据链
	GLuint *ptr, nums, zmin, zmax, name;
	ptr = buffer;
	
	selectedIndex = 0; //初始化为0
    for (int i = 0; i < hits; i++) 
	{
		// number of names for this hit
		// 在本程序中 nums=1
		nums = *ptr;	
		
        ptr++;	zmin = *ptr;	
		ptr++;	zmax = *ptr;
        
		// 在本程序中 nums=1, 无需循环
		ptr++;  name = *ptr;
		
		// 选择离视点最近的对象
		if(mindepth>zmin)
		{
			mindepth=zmin;
			selectedIndex=name;
		}
		
		// 下一个 hit
		ptr++;
	}

}

#define SIZE 512

void mouse(int button, int state, int x, int y)
{	
	GLuint selectBuf[SIZE];
	GLint hits;
	GLint viewport[4];
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) //鼠标左键按下进入选择模式
	{
		glGetIntegerv (GL_VIEWPORT, viewport); //获得当前的viewport,用于gluPickMatrix
		
		glSelectBuffer (SIZE, selectBuf);    //设定缓存
		glRenderMode(GL_SELECT); //进入选择模式
		
		glInitNames();  //初始化名称堆栈
		glPushName(-1); //名称缓冲区中放入id (没有绘制任何对象,所以用-1表示)
		
		glMatrixMode (GL_PROJECTION); 
		glPushMatrix (); //保存当前投影矩阵（因为后面重设视景体，把视景体设为鼠标附近）

		glLoadIdentity (); //把当前投影矩阵置为单位矩阵
		/* create 2x2 pixel picking region near cursor location */
		gluPickMatrix ((GLdouble) x, (GLdouble) (viewport[3] - y),
			2.0, 2.0, viewport);  //改变视图参数，使得只有靠近鼠标指针的对象位于新的视景体中
		glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); //重新设置视景体，跟绘制对象时候的状态保持一致

		drawobjects(GL_SELECT);		//在选择模式下重绘对象，这时候对象拥有ID
		
		glMatrixMode (GL_PROJECTION);
		glPopMatrix ();  //恢复原来的投影矩阵

		glMatrixMode(GL_MODELVIEW);  //恢复当前矩阵模式为Modelview
		
		hits = glRenderMode (GL_RENDER); //退出选择模式，得到击中对象个数
		processHits (hits, selectBuf);   //根据击中对象个数，和击中记录缓存，得到当前选中的对象
		
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