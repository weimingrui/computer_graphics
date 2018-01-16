#include "windows.h" 
#include <GL/gl.h> 
#include <GL/glaux.h> 
   
void myinit(void);  
void CALLBACK myReshape(GLsizei w, GLsizei h); 
void CALLBACK display(void); 
   
void myinit(void) 
{  
   
/* 
设置材质的各种光的颜色成分反射比率
*/ 
    
GLfloat mat_ambient[]={0.8,0.8,0.8,1.0};  
    
GLfloat mat_diffuse[]={0.8,0.0,0.8,1.0};    
/* 
紫色
 
*/  
    
GLfloat mat_specular[] = { 1.0, 0.0, 1.0, 1.0 };  
/* 
亮紫色
 
*/ 
    
GLfloat mat_shininess[] = { 50.0 }; 
   
    
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; 
   
    
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);  
    
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); 
    
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
    
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); 
   
   
glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
   
    
glEnable(GL_LIGHTING); 
    
glEnable(GL_LIGHT0); 
    
glDepthFunc(GL_LESS);  
    
glEnable(GL_DEPTH_TEST); 
} 
   
void CALLBACK display(void) 
{  
    
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    
auxSolidSphere(1.0); 
    
glFlush(); 
} 
   
void CALLBACK myReshape(GLsizei w, GLsizei h) 
{  
    
glViewport(0, 0, w, h);  
    
glMatrixMode(GL_PROJECTION); 
    
glLoadIdentity(); 
    
if (w <= h)  
    
glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w, 
        
1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0); 
    
else  
    
glOrtho (-1.5*(GLfloat)w/(GLfloat)h,  
        
1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0); 
    
glMatrixMode(GL_MODELVIEW); 
    
glLoadIdentity(); 
} 
   
void main(void) 
{  
    
auxInitDisplayMode (AUX_SINGLE | AUX_RGBA | AUX_DEPTH16); 
    
auxInitPosition (0, 0, 500, 500); 
    
auxInitWindow ("Lighting_1 "); 
    
myinit();  
    
auxReshapeFunc (myReshape); 
    
auxMainLoop(display); 
}  
