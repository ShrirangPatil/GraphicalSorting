/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: SHRIRANG
 *
 * Created on April 3, 2018, 7:56 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 30


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
//15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
int arra[10];
int z;
char str[128];
char str0[128];
char str1[128];
char str2[128];
int width=600, height=300;
//int index = 0;s

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
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}
void bubbleSort(int j)
{
        int temp;
        if(arra[j+1]<arra[j])
        {
                temp = arra[j];
                arra[j] = arra[j+1];
                arra[j+1] = temp;
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
void Welcome(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
        glLoadIdentity();
        glClearColor(0.0,0.0,0.0,1.0);
        glColor3f(1,0,0);
        drawBitmapText("Welcome TO",200,100,0);
        drawBitmapText("Graphical Sorting Application",150,130,0);
        glColor3f(0,0,1);
        drawBitmapText("By",width-200,height-60,0);
        drawBitmapText("Shrirang Patil",width-200,height-40,0);
        drawBitmapText("Basavaraj Bevoor",width-200,height-20,0);
        glFlush();
        glColor3f(1.0,1.0,1.0);
        sleep(6);
        //return 0;
}

void MergeSort(void)
{
	Welcome();
	int arr[MAX],temp[MAX],i,j,k,n=z,size,l1,h1,l2,h2;
	int index = 0;
	int u;
	for(i=0;i<n;i++)
		arr[i] = arra[i];

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	drawBitmapText("Merge Sort",200,100,0);
	for(u=0;u<n;u++)
		index += snprintf(&str[index], 128-index, "%d  ", arr[u]);
	drawBitmapText(str,200,200,0);
        glFlush();
        sleep(3);
	str[0] = '\0';
	index = 0;
	//printf("Enter the number of elements : ");
	//scanf("%d",&n);

	for(i=0;i<n;i++)
		arr[i] = arra[i];

	//printf("Unsorted list is : ");
	//for( i = 0 ; i<n ; i++)
		//printf("%d ", arr[i]);

	/*l1 lower bound of first pair and so on*/
	for(size=1; size < n; size=size*2 )
	{
		l1=0;
		k=0;  /*Index for temp array*/
		while( l1+size < n)
		{
			h1=l1+size-1;
			l2=h1+1;
			h2=l2+size-1;
			/* h2 exceeds the limlt of arr */
			if( h2>=n ) 
				h2=n-1;
			
			/*Merge the two pairs with lower limits l1 and l2*/
			i=l1;
			j=l2;
			
			while(i<=h1 && j<=h2 )
			{
				if( arr[i] <= arr[j] )
					temp[k++]=arr[i++];
				else
					temp[k++]=arr[j++];
			}
			
			while(i<=h1)
				temp[k++]=arr[i++];
			while(j<=h2)
				temp[k++]=arr[j++];
			/**Merging completed**/
			/*Take the next two pairs for merging */
			l1=h2+1; 
		}/*End of while*/

		/*any pair left */
		for(i=l1; k<n; i++) 
			temp[k++]=arr[i];

		for(i=0;i<n;i++)
			arr[i]=temp[i];

		printf("\nSize=%d \nElements are : ",size);
		//for( i = 0 ; i<n ; i++)
			//printf("%d ", arr[i]);
		//for(u=0;u<n;u++)
			//arra[u] = arr[u];
		int o;
		o= 0;
		/*//for(o=0;o<size+1;o++)
			for(u=0;u<n;u++)
				index += snprintf(&str[index], 128-index, "%d  ", arr[u]);
		//puts(str);
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
        	glColor3f(0,1,1);
		drawBitmapText(str,200,200,0);
        	glFlush();
        	sleep(3);
        	str[0] = '\0';
        	index = 0;*/
        	//glClear(GL_COLOR_BUFFER_BIT);
		//glLoadIdentity();
        	for(u=0;u<n;u+=size)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glLoadIdentity();
			drawBitmapText("Sorting...",200,100,0);
			glColor3f(0,1,1);
			for(o=0;o<size && o+u < n;o++)
			index += snprintf(&str[index], 128-index, "%d  ", arr[u+o]);
		//puts(str);
			puts(str);
			drawBitmapText(str,200,200,0);
        		glFlush();
       			//str[0] = '\0';
       			//index = 0;
       			
        		sleep(2);
        	}
        	str[0] = '\0';
        	index = 0;
		
	}/*End of for loop */
	
	//printf("Sorted list is :\n");
	for( i = 0 ; i<n ; i++)
		printf("%d ", arr[i]);
        str[0] = '\0';
	for(u=0;u<n;u++)
		index += snprintf(&str[index], 128-index, "%d  ", arr[u]);
	//puts(str);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
       	glColor3f(1,1,1);
       	drawBitmapText("Sorted",200,100,0);
	drawBitmapText(str,200,200,0);
       	glFlush();
       	sleep(5);
        str[0] = '\0';
	//printf("\n");
	_exit(0);

}
void Insertion(void)
{ 
	Welcome();
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
                index += snprintf(&str[index], 128-index, "%d   ", arra[i]);
        }
        drawBitmapText("Insertion Sort",200,100,0);
        drawBitmapText(str,200,k,0);
        glFlush();
        sleep(3);
        index = 0;
        for(m= 1;m<=z-1;m++)
	{
		char s[18] = "Sorting";
        	int w = 7;
		int v = arra[m];
		n = m-1;
		while(n>=0 && arra[n] > v)
		{
			int temp = n;
			glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(1,0,1);
			drawBitmapText(s,200,100,0);
			arra[temp+1] = arra[temp];
			temp = temp-1;
			arra[temp+1] = v;
			for(i=0;i<=n;i++)
				index1 += snprintf(&str1[index1], 128-index1, "%d   ", arra[i]);
			//printf("str1\n");
			//puts(str1);
			glLoadIdentity();
        		glColor3f(0,0,1);
        		drawBitmapText(str1,200,200+20,0);
        		n = temp;
        		for(i=n+2;i<z;i++)
				index2 += snprintf(&str2[index2], 128-index2, "%d   ", arra[i]);
			//printf("str2\n");
			//puts(str2);
			glLoadIdentity();
                	glColor3f(1,0,1);
                	drawBitmapText(str2,200+index1*10,k,0);
                	glFlush();
                	sleep(1.5);
                	//i=0;
        		str1[0]= '\0';
        		str2[0]= '\0';
        		index1 = 0;
        		index2 = 0;
                        if(w < 10)
                        {
                		s[w]='.';
               			w+=1;
                	}
               		else{
               		}
		}
		arra[n+1] = v;
                
        }
        glClear(GL_COLOR_BUFFER_BIT); 
        glLoadIdentity();
        glColor3f(1,1,1);
        drawBitmapText("Sorted list",200,100,0);
        for (i=0; i<z; i++){
                index += snprintf(&str[index], 128-index, "%d   ", arra[i]);
        }
        drawBitmapText(str,200,k,0);
        glFlush();
        sleep(5);
        _exit(0);
}
void Bubble(void)
{
	Welcome(); 
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
                index += snprintf(&str[index], 128-index, "%d   ", arra[i]);
        }
        drawBitmapText("Bubble Sort",200,100,0);
        drawBitmapText(str,200,k,0);
        glFlush();
        sleep(3);
        index = 0;
        for(m= 0;m<=z-2;m++)
        {
	      	char s[18] = "Sorting";
		int w = 7;
                for(n=0;n<=z-2-m;n++)
                {
                	for (i=0; i<n; i++){
                                index += snprintf(&str0[index], 128-index, "%d  ", arra[i]);
                        }
                        glClear(GL_COLOR_BUFFER_BIT);
                        drawBitmapText(s,200,100,0);
                        glLoadIdentity();
                        glColor3f(1,1,0);
                        //if(str0[0] != '\0')
                        	drawBitmapText(str0,200,k,0);
                        bubbleSort(n);
                        index1 += snprintf(&str1[index1], 128-index1, "%d  ", arra[n]);
        		index1 += snprintf(&str1[index1], 128-index1, "%d  ", arra[n+1]);
        		glLoadIdentity();
        		glColor3f(1,0,0);
        		drawBitmapText(str1,200+index*10,200-20,0);
        		
                        for (i=n+2; i<z; i++){
                                index2 += snprintf(&str2[index2], 128-index2, "%d  ", arra[i]);
                        }
                        glLoadIdentity();
                        glColor3f(1,1,0);
                        drawBitmapText(str2,200+(index+index1)*10,k,0);
                        glFlush();
                        sleep(1.5);
                        index = 0;
                        index1 = 0;
                        index2 = 0;
                        str0[0]= '\0';
                        str1[0]= '\0';
                        str2[0]= '\0';
                        if(w < 10){
                        	s[w]='.';
                        	w+=1;
                        }
                        else{
                        }
                }
                s[0] = '\0';
        }
        glClear(GL_COLOR_BUFFER_BIT); 
        glLoadIdentity();
        glColor3f(1,1,1);
        drawBitmapText("Sorted list",200,100,0);
        for (i=0; i<z; i++){
                index += snprintf(&str[index], 128-index, "%d  ", arra[i]);
        }
        drawBitmapText(str,200,k,0);
        glFlush();
        
        sleep(5);
        _exit(0);
}
int main(int argc, char* argv[])
{
        int i;
        int choice;
        printf("Enter the length of array\n");
        scanf("%d",&z);
        if(z <= 15){
	        if(z>5)
	        {
	        	width = (z*100)/2+200;
	        }
	        for(i=0;i<z;i++)
	                scanf("%d",&arra[i]);
	        printf("1Bubble Sort\n2:Insertion Sort\n3:Merge Sort\t");
	        scanf("%d",&choice);
	                        

	        if(choice == 1)
	        {
		        glutInit(&argc, argv); 
		        glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
		        
		        /*glutInitWindowSize(600,300);
		        glutInitWindowPosition(300,300);
		        glutCreateWindow("Welcome");
		        glutDisplayFunc(Welcome);
		        glutReshapeFunc(reshape);*/
		     
		        glutInitWindowSize(width,height); 
		        glutInitWindowPosition(0,0); 
		        glutCreateWindow("Sorting Algorithms"); 
			glutDisplayFunc(Bubble);
		        glutReshapeFunc(reshape);
		        
		        //glutSetWindow(1);
		        //glutPostRedisplay();
		        //glutKeyboardFunc(keyboardPress);
		         
		        glutMainLoop();
	        }
		else if(choice == 2)	
		{
			glutInit(&argc, argv); 
		        glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);  
		        glutInitWindowSize(width,height); 
		        glutInitWindowPosition(100,100); 
		        glutCreateWindow("Sorting Algorithms"); 

		        glutDisplayFunc(Insertion);
		        glutReshapeFunc(reshape); 
		        glutMainLoop();
		}
		else
		{
			//printf("Not Yet Implemented");
			glutInit(&argc, argv); 
		        glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);  
		        glutInitWindowSize(width,height); 
		        glutInitWindowPosition(100,100); 
		        glutCreateWindow("Sorting Algorithms"); 

		        glutDisplayFunc(MergeSort);
		        glutReshapeFunc(reshape); 
		        glutMainLoop();
			//MergeSort();
		}
	}
	else
	{
		printf("For large value of numbers Sortiong Application won't work properly\n");
	}
return 0;
}

