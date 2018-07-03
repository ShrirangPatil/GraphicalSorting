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
#include <stdlib.h>


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
char str[128];
char str0[128];
char str1[128];
char str2[128];
//int index = 0;

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
void bubbleSort(int j){
        int temp;
        if(arra[j+1]<arra[j])
        {
                temp = arra[j];
                arra[j] = arra[j+1];
                arra[j+1] = temp;
        }
        /*index += snprintf(&str[index], 128-index, "%d  ", arra[j]);
        index += snprintf(&str[index], 128-index, "%d  ", arra[j]);
        glLoadIdentity();
        glColor3f(1,1,0);
        drawBitmapText(str,200,200+index*3,0);*/
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
void Bubble(void)
{ 
        int k=200;
        glClear(GL_COLOR_BUFFER_BIT); 
        glLoadIdentity();
        int m, n;
        //char str[128];
        int i=0;
        int index = 0;
        int index1 = 0;
        int index2 = 0;
        for (i=0; i<z; i++){
                index += snprintf(&str[index], 128-index, "%d  ", arra[i]);
        }
        drawBitmapText("Bubble Sorting",200,100,0);
        drawBitmapText(str,200,k,0);
        glFlush();
        sleep(3);
        index = 0;
        for(m= 0;m<=z-1;m++)
        {
                for(n=0;n<=z-2-m;n++)
                {
                	for (i=0; i<n; i++){
                                index += snprintf(&str0[index], 128-index, "%d  ", arra[i]);
                        }
                        glClear(GL_COLOR_BUFFER_BIT);
                        //printf("str0\t");
                        //puts(str0);
                        glLoadIdentity();
                        glColor3f(1,1,0);
                        if(str0[0] != '\0')
                        	drawBitmapText(str0,200,k,0);
                        
                        
                        /*index1 += snprintf(&str1[index1], 128-index1, "%d  ", arra[n]);
        		index1 += snprintf(&str1[index1], 128-index1, "%d  ", arra[n+1]);
        		printf("str1\t");
        		puts(str1);
        		glLoadIdentity();
        		glColor3f(1,0,0);
        		drawBitmapText(str1,200+index*10,200,0);*/
                        bubbleSort(n);
                        /*index1 = 0;
                        index1 = 0;
                        index1 += snprintf(&str1[index1], 128-index1, "%d  ", arra[n]);
        		index1 += snprintf(&str1[index1], 128-index1, "%d  ", arra[n+1]);*/
                        index1 += snprintf(&str1[index1], 128-index1, "%d  ", arra[n]);
        		index1 += snprintf(&str1[index1], 128-index1, "%d  ", arra[n+1]);
        		//printf("str1\t");
        		//puts(str1);
        		glLoadIdentity();
        		glColor3f(1,0,0);
        		drawBitmapText(str1,200+index*10,200,0);
        		
                        for (i=n+2; i<z; i++){
                                index2 += snprintf(&str2[index2], 128-index2, "%d  ", arra[i]);
                        }
                        //printf("str2\t");
                        //puts(str2);
                        //glClear(GL_COLOR_BUFFER_BIT); 
                        glLoadIdentity();
                        glColor3f(1,1,0);
                        drawBitmapText(str2,200+(index+index1)*10,k,0);
                        //glutSwapBuffers();
                        glFlush();
                        sleep(1);
                        //k+=30;
                        //glClear(GL_COLOR_BUFFER_BIT);
                        i=0;
                        index = 0;
                        index1 = 0;
                        index2 = 0;
                        str0[0]= '\0';
                        str1[0]= '\0';
                        str2[0]= '\0';
                }
        }
        sleep(5);
        _exit(0);
}


int main(int argc, char* argv[])
{
        int i;
        int choice;
        printf("Enter the length of array\n");
        scanf("%d",&z);
        for(i=0;i<z;i++)
                scanf("%d",&arra[i]);
        printf("1Bubble Sort\n2:Selection Sort\n3:Merge Sort\t");
        scanf("%d",&choice);
                        

        if(choice == 1)
        {
	        glutInit(&argc, argv); 
	        glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);  
	        glutInitWindowSize(1000,1000); 
	        glutInitWindowPosition(100,100); 
	        glutCreateWindow("OpenGL Fonts"); 

	        glutDisplayFunc(Bubble);
	        glutReshapeFunc(reshape); 
	        glutMainLoop();
        }
	else 	
	{
		printf("Not Yet Implemented\n");
	}
return 0;
}

