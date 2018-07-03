/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: SHRIRANG
 *
 * Created on March 3, 2018, 7:56 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <unistd.h>


/*
 * 
 */
/*void drawStrokeText(char*string,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	 // glScalef(0.09f,-0.08f,z);
  
	  for (c=string; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}*/
int arra[10];
int z;
void bubbleSort(int j){
    int temp;
    if(arra[j+1]<arra[j])
    {
        temp = arra[j];
        arra[j] = arra[j+1];
        arra[j+1] = temp;
    }
}
void drawBitmapText(char *string,float x,float y,float z) 
{  /*Available fonts in bitmapText
    * GLUT_BITMAP_8_BY_13
    * GLUT_BITMAP_9_BY_15
    * GLUT_BITMAP_TIMES_ROMAN_10
    * GLUT_BITMAP_TIMES_ROMAN_24
    * GLUT_BITMAP_HELVETICA_10
    * GLUT_BITMAP_HELVETICA_12
    * GLUT_BITMAP_HELVETICA_18
    */
	char *c;
	glRasterPos3f(x, y,z);

	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
	}
}
void init()
{
	glClearColor(0.0,0.0,0.0,0.0); 
}


void reshape(int w,int h) 
{ 
 
    glViewport(0,0,w,h); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0,w,h,0); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 

}
void render(void)
{ 
    int k=200;
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity();
    int m, n;
    char str[128];
    int i=0;
    int index = 0;
    for (i=0; i<z; i++){
        index += snprintf(&str[index], 128-index, "%d  ", arra[i]);
    }
    drawBitmapText("Bubble Sorting",200,100,0);
    drawBitmapText(str,200,k,0);
    glFlush();
    sleep(3);
    for(m= 0;m<=z-2;m++)
    {
        for(n=0;n<=z-2-m;n++)
        {
            bubbleSort(n);
            i=0;
            index = 0;
            for (i=0; i<z; i++){
                index += snprintf(&str[index], 128-index, "%d  ", arra[i]);
            }
            glClear(GL_COLOR_BUFFER_BIT); 
            glLoadIdentity();
            glColor3f(1,1,0);
            drawBitmapText(str,200,k,0);
            //glutSwapBuffers();
            glFlush();
            sleep(1);
            //k+=30;
        }
    }
}


int main(int argc, char* argv[])
{
    int i;
    int choice;
    printf("Enter the length of array\n");
    scanf("%d",&z);
    for(i=0;i<z;i++)
        scanf("%d",&arra[i]);
    //printf("\t1:Bubble Sort\n\t2:Selection Sort\n\t3:Merge Sort\n\n");
    //scanf("%d",choice);
            

    
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);  
    glutInitWindowSize(500,500); 
    glutInitWindowPosition(100,100); 
    glutCreateWindow("OpenGL Fonts"); 

    glutDisplayFunc(render);
    glutReshapeFunc(reshape); 
    glutMainLoop(); 
	return 0;
}


