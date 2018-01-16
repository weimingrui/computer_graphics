#include <GL/glut.h> 
#include <stdlib.h> 
static int spin = 0;  
/*  
Initialize material property, light source, lighting model, 
 *  
and depth buffer. 
 */  

void init(void)  
{  
   
glClearColor (1.0, 1.0, 1.0, 0.0); 
   
glShadeModel (GL_SMOOTH); 
   
glEnable(GL_LIGHTING);  
   
glEnable(GL_LIGHT0);  
//这里使用了LIGHT0的默认值
  
  
   
   
glEnable(GL_DEPTH_TEST); 
}  
/*  
Here is where the light position is reset after the modeling 
 *  
transformation (glRotated) is called.  
This places the 
 *  
light at a new position in world coordinates.  
The cube 
 *  
represents the position of the light. 
*/  
 static GLfloat position[] = { 0.0, 0.0, 10.5, 1.0 }; 
 GLuint choose;	 //击中对象的ID
#define BALL 1
#define TEA 2
GLfloat fAspect;

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;
static GLdouble viewer[] = {0.0,0.0,5.0};

static GLfloat a = 1.0;
static GLfloat b = 1.0;

static GLfloat axRot = 0.0f;
static GLfloat ayRot = 0.0f;
static GLfloat bxRot = 0.0f;
static GLfloat byRot = 0.0f;
static GLfloat azRot = 0.0f;
static GLfloat bzRot = 0.0f;

static GLfloat lookatx=0.0;
static GLfloat lookaty=0.0;
static GLfloat lookatz=5.0;
static GLfloat scalefx=1.0;
static GLfloat scalefy=1.0;
static GLfloat scalefz=1.0;
static GLfloat centy=0.0;
static GLfloat centx=0.0;
static GLfloat centz=0.0;

void balls()
{   
	GLUquadricObj *cylinder_obj1;
	GLUquadricObj *cylinder_obj2;
	cylinder_obj1=gluNewQuadric();  
	cylinder_obj2=gluNewQuadric(); 

	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

	glTranslatef(axRot-0.8, ayRot-0.5, azRot+0.0);//两个球
	glutSolidSphere(0.5, 50, 50);

	glTranslatef(0.0, 1.0, 0.0);
	glutSolidSphere(1.0, 50, 50);

		//画耳朵
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.8, 0.8, 0.0);
	gluCylinder(cylinder_obj1, 0.3, 0.3, 0.05, 100, 50);
	gluDisk(cylinder_obj2,0,0.3,100,50);

	glTranslatef(-1.6, 0.0, 0.0);
	gluCylinder(cylinder_obj1, 0.3, 0.3, 0.05, 100, 50);
	gluDisk(cylinder_obj2,0,0.3,100,50);
}
GLfloat no_mat[] = {0.0,0.0,0.0,1.0};
GLfloat mat_grey_ambient[] = {0.5,0.5,0.5,1.0};
GLfloat mat_red_ambient[] = {0.0,0.0,1.0,1.0};
GLfloat mat_diffuse[] = {0.8,0.2,0.5,1.0};
GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
GLfloat no_shininess[] = {0.0};
GLfloat low_shininess[] = {5.0};
GLfloat high_shininess[] = {100.0};
GLfloat mat_emission[] = {0.3,0.2,0.2,0.0};

void display(void) 
{  
   
 glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 glPushMatrix (); 

 gluLookAt (0.0, 0.0,5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  // 效果和glTranslatef (0.0, 0.0, -5.0);一样
 
 glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,high_shininess);
glMaterialfv(GL_FRONT,GL_EMISSION,no_mat);
glColorMaterial(GL_FRONT,GL_AMBIENT);
   /*
glPushMatrix (); // 光源与WireCube模型
  
 glRotated ((GLdouble) spin, 1.0, 0.0, 0.0); //同时旋转光源以及WireCube 
 glLightfv (GL_LIGHT0, GL_POSITION, position);   
//光源是几何物体，通过ModelView变换可以移动旋转它
  
  
 glTranslated (0.0, 0.0, 1.5); 
 glDisable (GL_LIGHTING); 
 glColor3f (0.0, 1.0, 1.0);  
 glutWireCube (0.1);  
// WireCube模拟代表光源的位置
 
  
 glEnable (GL_LIGHTING); 
 glPopMatrix ();  
   
 glutSolidTorus (0.275, 0.85, 8, 15); 
 glPopMatrix (); 
 glFlush (); //*/
 
glPushMatrix (); // 光源与WireCube模型
  
 glRotated ((GLdouble) spin, 1.0, 0.0, 0.0); //同时旋转光源以及WireCube 
 glLightfv (GL_LIGHT0, GL_POSITION, position);   
//光源是几何物体，通过ModelView变换可以移动旋转它
  
 
 glTranslated (0.0, 0.0,5.0); 
 glDisable (GL_LIGHTING); 
 glColor3f (0.0, 1.0, 1.0);  
 glutWireCube (0.2);  
// WireCube模拟代表光源的位置 
 glEnable (GL_LIGHTING); 
 glPopMatrix ();  
  glTranslated (0.0, 0.0, 2.5); //物体中心点
 // glutSolidTorus (0.275, 0.85, 8, 15); 
 glutSolidTeapot (0.275); //设计物体

 glPopMatrix (); 
 //balls();
 glFlush (); 
}  
void reshape (int w, int h) 
{  
 glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
 glMatrixMode (GL_PROJECTION); 
 glLoadIdentity();  
 gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0); 
 glMatrixMode(GL_MODELVIEW); 
 glLoadIdentity(); 
}  
void mouse(int button, int state, int x, int y) 
{  
 switch (button) {  
 case GLUT_LEFT_BUTTON: 
  if (state == GLUT_DOWN) { 
            
spin = (spin + 30) % 360; 
            
glutPostRedisplay(); 
  }  
  break; 
 default: 
  break; 
 } 
}  
void keyboard(unsigned char key, int x, int y) 
{ 
 switch (key) { 
 case 27: 
  exit(0); 
  break; 
 } 
}  
void keys(unsigned char key,int x,int y)
{
	if(key=='1')position[0]-=1.0;
	if(key=='2')position[0]+=1.0;
	if(key=='3')position[1]-=1.0;
	if(key=='4')position[1]+=1.0;
	if(key=='5')position[2]-=1.0;
	if(key=='6')position[2]+=1.0;
	if(key=='7')position[3]-=1.0;
	if(key=='8')position[3]+=1.0;
	display();
}
int main(int argc, char** argv) 
{  
 glutInit(&argc, argv);  
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 
 glutInitWindowSize (500, 500);  
 glutInitWindowPosition (100, 100); 
 glutCreateWindow (argv[0]); 
 init ();  
 glutKeyboardFunc(keys);
 glutDisplayFunc(display);  
 glutReshapeFunc(reshape); 
 glutMouseFunc(mouse);  
 //glutKeyboardFunc(keyboard); 
 glutMainLoop(); 
 return 0; 
}  
