#include <cstdio>
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>>
#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include <iostream>
#include<stdio.h>
#include<string.h>
# define PI 3.14159265358979323846

using namespace std;

GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 2;
GLfloat speed2 = 4;
float xn=0;
float yq;
float xm;
float yp;
float s,t;
float c,v;
float m,n;
float k,l,q,w;
float _rain = 0.0;

bool rainday = false;



void update(int value) {

    if(position1 > 1200)
        position1 = -10;

    position1 += speed;


     if(position2 > 1200)
        position2 = -10;

    position2 += speed2;


	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}

void init() {
   glClearColor(0.1f, 0.0f, 0.0f, 1.0f);

}
void grass(int a, int b)
{
    glBegin(GL_POLYGON);
    glColor3f(0,255,0);
    glVertex2i(a+50, b+0);
    glVertex2i(a+50, b+35);
    glVertex2i(a+35, b+10);
    glVertex2i(a+25, b+40);
    glVertex2i(a+15, b+11);
    glVertex2i(a+15, b+37);
    glVertex2i(a+10, b+5);
    glVertex2i(a+10, b+40);
    glVertex2i(a+0, b+0);
    glEnd();
}


void day(int x, int y)

{
    ///sky
    glBegin(GL_QUADS);
	glColor3ub(175, 238, 238);
	glVertex2i(q+0,w+500);
	glVertex2i(q+0,w+700);
    glVertex2i(q+1200,w+700);
	glVertex2i(q+1200,w+500);
	glEnd();


    ///sun
	int i7;
    GLint x7= 1050;
    GLint y7= 640;
    GLfloat radius7 =30;
    int triangleAmount7 = 30;

    GLfloat twicePi7 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0);
    glVertex2f(q+x7, w+y7);
    for(i7 = 0; i7 <= triangleAmount7; i7++)
    {
        glVertex2f(
            q+x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
            w+y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
        );
    }
    glEnd();
}


void roaddevider(GLint x1,GLint x2,GLint x3,GLint x4)
{
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
    glVertex2i(x1,155);
	glVertex2i(x2,145);
	glVertex2i(x3,145);
	glVertex2i(x4,155);
	glEnd();
}

void wheel (int a, int b)
{
    int i;
    GLint x= a+20;
    GLint y= b+65;
    GLfloat radius =12;
    int triangleAmount = 10;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

}

void car1(int a, int b)
{
    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(a+300, b+90);
    glVertex2i(a+450, b+90);
    glVertex2i(a+450, b+120);
    glVertex2i(a+300, b+120);

    glVertex2i(a+300, b+120);
    glVertex2i(a+340, b+145);
    glVertex2i(a+380, b+145);
    glVertex2i(a+410, b+120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(a+302, b+122);
    glVertex2i(a+342, b+143);
    glVertex2i(a+378, b+143);
    glVertex2i(a+406, b+122);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(a+360, b+120);
    glVertex2i(a+360, b+145);
    glVertex2i(a+355, b+145);
    glVertex2i(a+355, b+120);
    glEnd();



}
void car2(int a, int b)
{
    glBegin(GL_QUADS);
    glColor3f(0,0,255);
    glVertex2i(a+300, b+90);
    glVertex2i(a+450, b+90);
    glVertex2i(a+450, b+120);
    glVertex2i(a+300, b+120);

    glVertex2i(a+300, b+120);
    glVertex2i(a+340, b+145);
    glVertex2i(a+380, b+145);
    glVertex2i(a+410, b+120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(a+302, b+122);
    glVertex2i(a+342, b+143);
    glVertex2i(a+378, b+143);
    glVertex2i(a+406, b+122);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,255);
    glVertex2i(a+360, b+120);
    glVertex2i(a+360, b+145);
    glVertex2i(a+355, b+145);
    glVertex2i(a+355, b+120);
    glEnd();

}
void Car3(int a)
{
    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(a+570, 170);
    glVertex2i(a+720, 170);
    glVertex2i(a+720, 200);
    glVertex2i(a+570,200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(a+585, 200);
    glVertex2i(a+625, 225);
    glVertex2i(a+665, 225);
    glVertex2i(a+695, 200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(a+595, 200);
    glVertex2i(a+625, 222);
    glVertex2i(a+665, 222);
    glVertex2i(a+685, 200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(a+640, 200);
    glVertex2i(a+640, 225);
    glVertex2i(a+645, 225);
    glVertex2i(a+645, 200);
    glEnd();

}

void lamp(int a, int b)
{
    int i16;
    GLint x16= 1115;
    GLint y16= 370;
    GLfloat radius16 =16;
    int triangleAmount16 = 30;

    GLfloat twicePi16 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x16, b+y16);
    for(i16 = 0; i16 <= triangleAmount16; i16++)
    {
        glVertex2f(
            a+x16 + (radius16 * cos(i16*  twicePi16 / triangleAmount16)),
            b+y16 + (radius16 * sin(i16* twicePi16 / triangleAmount16))
        );
    }
    glEnd();

    int i15;
    GLint x15= 915;
    GLint y15= 370;
    GLfloat radius15 =15;
    int triangleAmount15 = 30;

    GLfloat twicePi15 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x15, b+y15);
    for(i15 = 0; i15 <= triangleAmount15; i15++)
    {
        glVertex2f(
            a+x15 + (radius15 * cos(i15*  twicePi15 / triangleAmount15)),
            b+y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15))
        );
    }
    glEnd();

	int i14;
    GLint x14= 715;
    GLint y14= 370;
    GLfloat radius14 =15;
    int triangleAmount14 = 30;

    GLfloat twicePi14 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x14, b+y14);
    for(i14 = 0; i14 <= triangleAmount14; i14++)
    {
        glVertex2f(
            a+x14 + (radius14 * cos(i14 *  twicePi14 / triangleAmount14)),
            b+y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14))
        );
    }
    glEnd();

    int i13;
    GLint x13= 515;
    GLint y13= 370;
    GLfloat radius13 =15;
    int triangleAmount13 = 30;

    GLfloat twicePi13 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x13, b+y13);
    for(i13 = 0; i13 <= triangleAmount13; i13++)
    {
        glVertex2f(
            a+x13 + (radius13 * cos(i13 *  twicePi13 / triangleAmount13)),
            b+y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13))
        );
    }
    glEnd();
    int i12;
    GLint x12= 315;
    GLint y12= 370;
    GLfloat radius12 =15;
    int triangleAmount12 = 30;

    GLfloat twicePi12 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x12, b+y12);
    for(i12 = 0; i12 <= triangleAmount12; i12++)
    {
        glVertex2f(
            a+x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
            b+y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12))
        );
    }
    glEnd();
    int i11;
    GLint x11= 115;
    GLint y11= 370;
    GLfloat radius11 =15;
    int triangleAmount11 = 30;

    GLfloat twicePi11 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x11, b+y11);
    for(i11 = 0; i11 <= triangleAmount11; i11++)
    {
        glVertex2f(
            a+x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
            b+y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
        );
    }
    glEnd();



}
void tree(int x, int y)
{
    ///BIG tree
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(x+445, y+340);
    glVertex2i(x+492, y+440);
	glVertex2i(x+540, y+340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(x+445, y+360);
    glVertex2i(x+492, y+460);
	glVertex2i(x+540, y+360);
	glEnd();

	glColor3f(0.4, 0.5, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(x+497, y+340);
    glVertex2i(x+486, y+340);
    glVertex2i(x+486, y+250);
    glVertex2i(x+497, y+250);
    glEnd();

}

void carmove()
{
    	if(xn>1200.0)
	{
		xn= -850.0;
	}
    xn+=0.0005;


        if(xm<-600.0)
	{
		xm=900.0;
	}
    xm-=0.0005;


}

void myDisplay(void)
{
    ///glClear(GL_COLOR_BUFFER_BIT);
    ///glLoadIdentity();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 255, 255);
    glPointSize(5.0);
    ///moon
	int i8;
    GLint x8= 1100;
    GLint y8= 640;
    GLfloat radius8 =30;
    int triangleAmount8 = 30;

    GLfloat twicePi8 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x8, y8);
    for(i8 = 0; i8 <= triangleAmount8; i8++)
    {
        glVertex2f(
            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
            y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
        );
    }
    glEnd();


day(q,w);
	///sea
	glBegin(GL_QUADS);
	glColor3ub(70, 130, 180);
	glVertex2i(0,350);
	glVertex2i(0,510);
	glVertex2i(1200,510);
	glVertex2i(1200,350);
	glEnd();

	///Beach
	glBegin(GL_QUADS);
	glColor3ub(238, 221, 130);
	glVertex2i(0,370);
	glVertex2i(0,300);
	glVertex2i(1200,300);
	glVertex2i(1200,370);
	glEnd();
    ///ship
    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
    glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	glColor3ub(168 ,168 ,168);
	glVertex2i(100,490);
	glVertex2i(100,470);
	glVertex2i(200,470);
	glVertex2i(230,490);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(77, 77, 77);
	glVertex2i(110,510);
	glVertex2i(110,490);
	glVertex2i(190,490);
	glVertex2i(180,510);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(250, 0, 0);
	glVertex2i(120,505);
	glVertex2i(120,500);
	glVertex2i(130,500);
	glVertex2i(130,505);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(250, 0, 0);
	glVertex2i(140,505);
	glVertex2i(140,500);
	glVertex2i(150,500);
	glVertex2i(150,505);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(250, 0, 0);
	glVertex2i(160,505);
	glVertex2i(160,500);
	glVertex2i(170,500);
	glVertex2i(170,505);
	glEnd();

    glPopMatrix();
	///ship2
    glPushMatrix();
    glTranslatef(-position1,0.0f, 0.0f);
    glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	glColor3ub(168 ,168 ,168);
	glVertex2i(780,460);
	glVertex2i(800,440);
	glVertex2i(1000,440);
	glVertex2i(1000,460);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(77, 77, 77);
	glVertex2i(830,480);
	glVertex2i(810,460);
	glVertex2i(990,460);
	glVertex2i(985,480);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2i(840,475);
	glVertex2i(840,465);
	glVertex2i(860,465);
	glVertex2i(860,475);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2i(880,475);
	glVertex2i(880,465);
	glVertex2i(900,465);
	glVertex2i(900,475);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2i(920,475);
	glVertex2i(920,465);
	glVertex2i(940,465);
	glVertex2i(940,475);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2i(960,475);
	glVertex2i(960,465);
	glVertex2i(980,465);
	glVertex2i(980,475);
	glEnd();

    glPopMatrix();

	///stars
	glColor3ub(175, 238, 238);
	glBegin(GL_POINTS);
	glVertex2i(250,650);
	glVertex2i(260,640);
    glVertex2i(220,670);
	glVertex2i(210,660);

    glVertex2i(280,650);
	glVertex2i(290,640);
    glVertex2i(250,670);
	glVertex2i(240,660);

    glVertex2i(320,650);
	glVertex2i(310,640);
    glVertex2i(280,670);
	glVertex2i(270,660);

    glVertex2i(350,650);
	glVertex2i(360,640);
    glVertex2i(320,670);
	glVertex2i(310,660);

    glVertex2i(380,650);
	glVertex2i(390,640);
    glVertex2i(350,670);
	glVertex2i(340,660);

    glVertex2i(420,650);
	glVertex2i(410,640);
    glVertex2i(480,670);
	glVertex2i(470,660);

    glVertex2i(650,650);
	glVertex2i(660,640);
    glVertex2i(620,670);
	glVertex2i(610,660);

    glVertex2i(680,650);
	glVertex2i(690,640);
    glVertex2i(650,670);
	glVertex2i(640,660);

    glVertex2i(720,650);
	glVertex2i(710,640);
    glVertex2i(780,670);
	glVertex2i(770,660);

	glEnd();

	///cloud
	glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
	int i;
    GLint x= 50;
    GLint y= 640;
    GLfloat radius =30;
    int triangleAmount = 30;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    int i3;
    GLint x3= 90;
    GLint y3= 660;
    GLfloat radius3 =30;
    int triangleAmount3 = 30;

    GLfloat twicePi3 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x3, y3);
    for(i3 = 0; i3 <= triangleAmount; i3++)
    {
        glVertex2f(
            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
            y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
        );
    }
    glEnd();

    int i4;
    GLint x4= 140;
    GLint y4= 660;
    GLfloat radius4 =30;
    int triangleAmount4 = 30;

    GLfloat twicePi4 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x4, y4);
    for(i4 = 0; i4 <= triangleAmount4; i4++)
    {
        glVertex2f(
            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
            y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
        );
    }
    glEnd();

    int i5;
    GLint x5= 90;
    GLint y5= 620;
    GLfloat radius5 =30;
    int triangleAmount5 = 30;

    GLfloat twicePi5 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x5, y5);
    for(i5 = 0; i5 <= triangleAmount5; i5++)
    {
        glVertex2f(
            x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
            y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5))
        );
    }
    glEnd();

    int i6;
    GLint x6= 130;
    GLint y6= 630;
    GLfloat radius6 =30;
    int triangleAmount6 = 30;

    GLfloat twicePi6 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x6, y6);
    for(i6 = 0; i6 <= triangleAmount6; i6++)
    {
        glVertex2f(
            x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
            y6 + (radius6 * sin(i6 * twicePi6 / triangleAmount6))
        );
    }
    glEnd();
    glPopMatrix();

    ///bird
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    glBegin(GL_LINES);
	glColor3ub(0,0,0);
    glVertex2i(180, 650);
    glVertex2i(200, 640);
    glVertex2i(180, 630);
    glVertex2i(200, 640);
    glEnd();


    glBegin(GL_LINES);
	glColor3ub(0,0,0);
    glVertex2i(190, 665);
    glVertex2i(210, 655);
    glVertex2i(190, 645);
    glVertex2i(210, 655);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(0,0,0);
    glVertex2i(220, 665);
    glVertex2i(240, 655);
    glVertex2i(220, 645);
    glVertex2i(240, 655);
    glEnd();



    glPushMatrix();
    glTranslatef(+30, -30, 0);

    glPushMatrix();
    glBegin(GL_LINES);
	glColor3ub(0,0,0);
    glVertex2i(250, 680);
    glVertex2i(270, 670);
    glVertex2i(250, 660);
    glVertex2i(270, 670);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+0, -60, 0);

    glPushMatrix();
    glBegin(GL_LINES);
	glColor3ub(0,0,0);
    glVertex2i(250, 680);
    glVertex2i(270, 670);
    glVertex2i(250, 660);
    glVertex2i(270, 670);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    ///MUD
    glBegin(GL_QUADS);
	glColor3ub(205 ,133, 0);
	glVertex2i(0,0);
	glVertex2i(0,30);
	glVertex2i(1200,30);
	glVertex2i(1200,0);
	glEnd();


    ///tree
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(50, 350);
    glVertex2i(70, 380);
    glVertex2i(90, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(50, 340);
    glVertex2i(70, 370);
    glVertex2i(90, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(65,340);
	glVertex2i(75,340);
	glVertex2i(75,310);
	glVertex2i(65,310);
	glEnd();
    ///lamp1
	glBegin(GL_QUADS);
	glColor3ub(32, 32, 32);
	glVertex2i(112,360);
	glVertex2i(118,360);
	glVertex2i(118,310);
	glVertex2i(112,310);
	glEnd();

    int i11;
    GLint x11= 115;
    GLint y11= 370;
    GLfloat radius11 =15;
    int triangleAmount11 = 30;

    GLfloat twicePi11 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x11, y11);
    for(i11 = 0; i11 <= triangleAmount11; i11++)
    {
        glVertex2f(
            x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
            y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
        );
    }
    glEnd();

    ///tree1
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(150, 350);
    glVertex2i(170, 380);
    glVertex2i(190, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(150, 340);
    glVertex2i(170, 370);
    glVertex2i(190, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(165,340);
	glVertex2i(175,340);
	glVertex2i(175,310);
	glVertex2i(165,310);
	glEnd();


    ///tree2
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(250, 350);
    glVertex2i(270, 380);
    glVertex2i(290, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(250, 340);
    glVertex2i(270, 370);
    glVertex2i(290, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(265,340);
	glVertex2i(275,340);
	glVertex2i(275,310);
	glVertex2i(265,310);
	glEnd();

	///lamp2
	glBegin(GL_QUADS);
	glColor3ub(32, 32, 32);
	glVertex2i(312,360);
	glVertex2i(318,360);
	glVertex2i(318,310);
	glVertex2i(312,310);
	glEnd();

	int i12;
    GLint x12= 315;
    GLint y12= 370;
    GLfloat radius12 =15;
    int triangleAmount12 = 30;

    GLfloat twicePi12 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x12, y12);
    for(i12 = 0; i12 <= triangleAmount12; i12++)
    {
        glVertex2f(
            x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
            y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12))
        );
    }
    glEnd();
    ///tree3
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(350, 350);
    glVertex2i(370, 380);
    glVertex2i(390, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(350, 340);
    glVertex2i(370, 370);
    glVertex2i(390, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(365,340);
	glVertex2i(375,340);
	glVertex2i(375,310);
	glVertex2i(365,310);
	glEnd();

    ///tree4
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(450, 350);
    glVertex2i(470, 380);
    glVertex2i(490, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(450, 340);
    glVertex2i(470, 370);
    glVertex2i(490, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(465,340);
	glVertex2i(475,340);
	glVertex2i(475,310);
	glVertex2i(465,310);
	glEnd();

	///lamp3
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(512,360);
	glVertex2i(518,360);
	glVertex2i(518,310);
	glVertex2i(512,310);
	glEnd();

	int i13;
    GLint x13= 515;
    GLint y13= 370;
    GLfloat radius13 =15;
    int triangleAmount13 = 30;

    GLfloat twicePi13 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x13, y13);
    for(i13 = 0; i13 <= triangleAmount13; i13++)
    {
        glVertex2f(
            x13 + (radius13 * cos(i13 *  twicePi13 / triangleAmount13)),
            y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13))
        );
    }
    glEnd();

	///tree5
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(550, 350);
    glVertex2i(570, 380);
    glVertex2i(590, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(550, 340);
    glVertex2i(570, 370);
    glVertex2i(590, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(565,340);
	glVertex2i(575,340);
	glVertex2i(575,310);
	glVertex2i(565,310);
	glEnd();

    ///tree6
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(650, 350);
    glVertex2i(670, 380);
    glVertex2i(690, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(650, 340);
    glVertex2i(670, 370);
    glVertex2i(690, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(665,340);
	glVertex2i(675,340);
	glVertex2i(675,310);
	glVertex2i(665,310);
	glEnd();

	///lamp4
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(712,360);
	glVertex2i(718,360);
	glVertex2i(718,310);
	glVertex2i(712,310);
	glEnd();


	int i14;
    GLint x14= 715;
    GLint y14= 370;
    GLfloat radius14 =15;
    int triangleAmount14 = 30;

    GLfloat twicePi14 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x14, y14);
    for(i14 = 0; i14 <= triangleAmount14; i14++)
    {
        glVertex2f(
            x14 + (radius14 * cos(i14 *  twicePi14 / triangleAmount14)),
            y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14))
        );
    }
    glEnd();
    ///tree7
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(750, 350);
    glVertex2i(770, 380);
    glVertex2i(790, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(750, 340);
    glVertex2i(770, 370);
    glVertex2i(790, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(765,340);
	glVertex2i(775,340);
	glVertex2i(775,310);
	glVertex2i(765,310);
	glEnd();

    ///tree8
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(850, 350);
    glVertex2i(870, 380);
    glVertex2i(890, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(850, 340);
    glVertex2i(870, 370);
    glVertex2i(890, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(865,340);
	glVertex2i(875,340);
	glVertex2i(875,310);
	glVertex2i(865,310);
	glEnd();

    ///lamp5
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(912,360);
	glVertex2i(918,360);
	glVertex2i(918,310);
	glVertex2i(912,310);
	glEnd();


	int i15;
    GLint x15= 915;
    GLint y15= 370;
    GLfloat radius15 =15;
    int triangleAmount15 = 30;

    GLfloat twicePi15 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x15, y15);
    for(i15 = 0; i15 <= triangleAmount15; i15++)
    {
        glVertex2f(
            x15 + (radius15 * cos(i15 *  twicePi15 / triangleAmount15)),
            y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15))
        );
    }
    glEnd();

    ///tree9
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(950, 350);
    glVertex2i(970, 380);
    glVertex2i(990, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(950, 340);
    glVertex2i(970, 370);
    glVertex2i(990, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(965,340);
	glVertex2i(975,340);
	glVertex2i(975,310);
	glVertex2i(965,310);
	glEnd();

       ///tree10
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(1050, 350);
    glVertex2i(1070, 380);
    glVertex2i(1090, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(1050, 340);
    glVertex2i(1070, 370);
    glVertex2i(1090, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(1065,340);
	glVertex2i(1075,340);
	glVertex2i(1075,310);
	glVertex2i(1065,310);
	glEnd();

	///lamp6
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(1112,380);
	glVertex2i(1118,380);
	glVertex2i(1118,310);
	glVertex2i(1112,310);
	glEnd();

	for (c=0; c<=1200; c+=40)
{
    grass(c,v+290);
}

    ///footpath
    glBegin(GL_QUADS);
	glColor3ub(139 ,126, 102);
	glVertex2i(0,300);
	glVertex2i(0,250);
	glVertex2i(1200,250);
	glVertex2i(1200,300);
	glEnd();

	///road
    glBegin(GL_QUADS);
	glColor3ub(106, 108, 109);
	glVertex2i(0,250);
	glVertex2i(0,50);
	glVertex2i(1200,50);
	glVertex2i(1200,250);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2i(0,260);
	glVertex2i(0,250);
	glVertex2i(1200,250);
	glVertex2i(1200,260);
	glEnd();

    ///white border
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2i(0,50);
	glVertex2i(0,30);
	glVertex2i(1200,30);
	glVertex2i(1200,50);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2i(100,50);
	glVertex2i(100,30);
	glVertex2i(200,30);
	glVertex2i(200,50);


    glVertex2i(300,50);
	glVertex2i(300,30);
	glVertex2i(400,30);
	glVertex2i(400,50);

    glVertex2i(500,50);
	glVertex2i(500,30);
	glVertex2i(600,30);
	glVertex2i(600,50);

    glVertex2i(700,50);
	glVertex2i(700,30);
	glVertex2i(800,30);
	glVertex2i(800,50);

    glVertex2i(900,50);
	glVertex2i(900,30);
	glVertex2i(1000,30);
	glVertex2i(1000,50);

    glVertex2i(1100,50);
	glVertex2i(1100,30);
	glVertex2i(1200,30);
	glVertex2i(1200,50);

    glVertex2i(0,260);
	glVertex2i(0,250);
	glVertex2i(50,250);
	glVertex2i(50,260);

    glVertex2i(100,260);
	glVertex2i(100,250);
	glVertex2i(150,250);
	glVertex2i(150,260);

    glVertex2i(200,260);
	glVertex2i(200,250);
	glVertex2i(250,250);
	glVertex2i(250,260);

    glVertex2i(300,260);
	glVertex2i(300,250);
	glVertex2i(350,250);
	glVertex2i(350,260);

    glVertex2i(400,260);
	glVertex2i(400,250);
	glVertex2i(450,250);
	glVertex2i(450,260);

	glVertex2i(500,260);
	glVertex2i(500,250);
	glVertex2i(550,250);
	glVertex2i(550,260);

	glVertex2i(600,260);
	glVertex2i(600,250);
	glVertex2i(650,250);
	glVertex2i(650,260);

	glVertex2i(700,260);
	glVertex2i(700,250);
	glVertex2i(750,250);
	glVertex2i(750,260);

	glVertex2i(800,260);
	glVertex2i(800,250);
	glVertex2i(850,250);
	glVertex2i(850,260);

	glVertex2i(900,260);
	glVertex2i(900,250);
	glVertex2i(950,250);
	glVertex2i(950,260);

	glVertex2i(1000,260);
	glVertex2i(1000,250);
	glVertex2i(1050,250);
	glVertex2i(1050,260);

	glVertex2i(1100,260);
	glVertex2i(1100,250);
	glVertex2i(1150,250);
	glVertex2i(1150,260);
	glEnd();


	///Roadside wall
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2i(0,310);
	glVertex2i(0,300);
	glVertex2i(1200,300);
	glVertex2i(1200,310);

	glEnd();


GLint xx;


for (xx = 0; xx <= 1200; xx += 50)
{
roaddevider(xx,xx,xx+30,xx+30);
}

car1(xn,yq);
wheel(xn+320,yq+30);
wheel(xn+400,yq+30);

car2(xn+400,yq-30);
wheel(xn+720,yq);
wheel(xn+800,yq);

Car3(xm);
wheel(xm+580,yp+115);
wheel(xm+670,yp+115);



	int i16;
    GLint x16= 1115;
    GLint y16= 370;
    GLfloat radius16 =16;
    int triangleAmount16 = 30;

    GLfloat twicePi16 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x16, y16);
    for(i16 = 0; i16 <= triangleAmount16; i16++)
    {
        glVertex2f(
            x16 + (radius16 * cos(i16 *  twicePi16 / triangleAmount16)),
            y16 + (radius16 * sin(i16 * twicePi16 / triangleAmount16))
        );
    }
    glEnd();

tree(s-470,t+50);
tree(s+700,t+50);
tree(s+650,t+50);
for (c=0; c<=1200; c+=40)
{
    grass(c,v);
}
lamp(q,w);
    ///shop1
    glBegin(GL_QUADS);
	glColor3ub(139 ,126, 102);
	glVertex2i(10,0);
	glVertex2i(10,130);
	glVertex2i(100,130);
	glVertex2i(100,0);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(255,0,0);
	glVertex2i(5,130);
	glVertex2i(5,140);
	glVertex2i(105,140);
	glVertex2i(105,130);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(0,0,255);
	glVertex2i(20,0);
	glVertex2i(20,120);
	glVertex2i(90,120);
	glVertex2i(90,0);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2i(52,0);
	glVertex2i(52,120);
	glVertex2i(58,120);
	glVertex2i(58,0);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2i(20,58);
	glVertex2i(20,52);
	glVertex2i(90,52);
	glVertex2i(90,58);
	glEnd();
	///shop2
    glBegin(GL_QUADS);
	glColor3ub(139 ,58 ,98);
	glVertex2i(200,0);
	glVertex2i(200,130);
	glVertex2i(380,130);
	glVertex2i(380,0);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(255,193 ,193);
	glVertex2i(195,130);
	glVertex2i(195,140);
	glVertex2i(385,140);
	glVertex2i(385,130);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(0,0,255);
	glVertex2i(210,0);
	glVertex2i(210,120);
	glVertex2i(370,120);
	glVertex2i(370,0);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2i(252,0);
	glVertex2i(252,120);
	glVertex2i(258,120);
	glVertex2i(258,0);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2i(312,0);
	glVertex2i(312,120);
	glVertex2i(318,120);
	glVertex2i(318,0);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2i(210,52);
	glVertex2i(210,58);
	glVertex2i(370,58);
	glVertex2i(370,52);
	glEnd();

    ///shop3
    glBegin(GL_QUADS);
	glColor3ub(205 ,186 ,150);
	glVertex2i(700,0);
	glVertex2i(700,130);
	glVertex2i(880,130);
	glVertex2i(880,0);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(255, 255 ,0);
	glVertex2i(695,130);
	glVertex2i(695,140);
	glVertex2i(885,140);
	glVertex2i(885,130);
	glEnd();

	    glBegin(GL_QUADS);
	glColor3ub(0,0,255);
	glVertex2i(710,0);
	glVertex2i(710,120);
	glVertex2i(870,120);
	glVertex2i(870,0);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2i(752,0);
	glVertex2i(752,120);
	glVertex2i(758,120);
	glVertex2i(758,0);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2i(812,0);
	glVertex2i(812,120);
	glVertex2i(818,120);
	glVertex2i(818,0);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2i(710,52);
	glVertex2i(710,58);
	glVertex2i(870,58);
	glVertex2i(870,52);
	glEnd();
	///shop4
    glBegin(GL_QUADS);
	glColor3ub(205 ,186 ,150);
	glVertex2i(900,300);
	glVertex2i(900,430);
	glVertex2i(1080,430);
	glVertex2i(1080,300);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(255, 255 ,0);
	glVertex2i(895,430);
	glVertex2i(895,440);
	glVertex2i(1085,440);
	glVertex2i(1085,430);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(0,0,255);
	glVertex2i(910,300);
	glVertex2i(910,420);
	glVertex2i(1070,420);
	glVertex2i(1070,300);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2i(952,300);
	glVertex2i(952,420);
	glVertex2i(958,420);
	glVertex2i(958,300);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2i(1012,300);
	glVertex2i(1012,420);
	glVertex2i(1018,420);
	glVertex2i(1018,300);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2i(910,352);
	glVertex2i(910,358);
	glVertex2i(1070,358);
	glVertex2i(1070,352);
	glEnd();

glFlush ();
}

void Rain(int value){

if(rainday){

    _rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1200;i++)
    {
        int x=rand(),y=rand();
        x%=1200; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	//glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();

}
}

void handleKeypress(unsigned char key, int x, int y) {

if (key == 'n')
{
    q=2000;
glutPostRedisplay();
}
else if (key == 'd')
{
       q=0;
glutPostRedisplay();
}

 if (key == 'r')
 {

        rainday = true;
        Rain(_rain);

        glutPostRedisplay();

 }
else if (key == 'e')
{
        rainday = false;

		glutPostRedisplay();
 }


}

void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1200.0, 0.0, 700.0);
}


int main(int argc, char** argv)
{
    cout << endl << "*********BEACH SIDE ROAD ********" << endl << endl;

    cout << "Press R : For Rain " << endl << endl;
    cout << "Press E : For Stop Rain" << endl << endl;
    cout << "Press N : For Night " << endl << endl;
    cout << "Press D : For Day" << endl << endl;

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1200, 1200);
glutInitWindowPosition (50, 50);
glutCreateWindow ("BEACH SIDE ROAD");
glutDisplayFunc(myDisplay);
glutKeyboardFunc(handleKeypress);
glutIdleFunc(carmove);
glutTimerFunc(1000, update, 0);
myInit ();
init();
glutMainLoop();
}
