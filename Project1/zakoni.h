#pragma once
#include <glut.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <dos.h>
#include<iostream>
#include<conio.h>
#define M_PI 3.14159265358979323846
#define WY 100
#define WX 100
#define wisota 2
#define dlina 10
void myInit(void);
void myDisplay(void);
#ifdef comp
extern float sinA;
extern float cosA;
extern float tgA;
extern float ktr;
extern float speed;
extern  float mass;
extern float G;
extern bool ch;
#else
float a;
float sinA;
float cosA;
float tgA;
float ktr;
float speed;
float mass;
float G;
bool ch;
#endif // comp
struct cord {
	float x;
	float y;
};
void dialog();
void Bigmenu();
inline void physics()
{	setlocale(LC_ALL, "Russian");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("My first programm OpenGL");
	dialog();
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	_getch();
}
inline void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0f, 0.0f, 1.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WX, 0, WY);
}
inline cord cordtranslated(float x, float y) {
	cord rez;
	float X = x;
	X = WY / cosA - X;
	rez.x = X * cosA - y * sinA;
	rez.y = X * sinA + y * cosA + WY / 20;
	return rez;
}
inline void interfase() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2d(0, WY / 20);
	glVertex2d(WX, WY / 20 + WY * tgA);
	glEnd();
}
inline void draw(float x0) {
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2d(cordtranslated(x0, 0 + wisota).x, cordtranslated(x0, 0 + wisota).y);
	glVertex2d(cordtranslated(x0 + dlina, 0 + wisota).x, cordtranslated(x0 + dlina, 0 + wisota).y);
	glVertex2d(cordtranslated(x0 + dlina, 0).x, cordtranslated(x0 + dlina, 0).y);
	glVertex2d(cordtranslated(x0, 0).x, cordtranslated(x0, 0).y);
	glEnd();
	if (cordtranslated(x0, 0).x <= 0) {
		Bigmenu();
	};
}
class brus {
public:float mass;
	   float xstart;
	   float x0=xstart;
	   float speed;
	   float speedt = speed;
	   brus(float masss, float x00) {
		   mass = masss; x0 = x00;
		   speed = 0;
	   }
	   brus(float masss, float x00, float speedd) { mass = masss; xstart = x00; speed = speedd; }
	   void move(float time, float a) {
		   x0 = xstart + speed * time + a * time*time / 2;
		  speedt = speed + a * time;
	   };
};
inline void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPolygonMode(GL_FRONT, GL_FILL);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2d(0, WY / 20);
	glVertex2d(WX, WY / 20 + WY * tgA);
	glEnd();
	float t = 0;
	brus perv(mass, 0, speed);
	float prev;
	while (true) {
		interfase();
		Sleep(10);
		t += 0.01;
		prev = perv.x0;
		perv.move(t, a);
		if (perv.x0<= prev) { 
			Sleep(10000);
			Bigmenu(); };
		draw(perv.x0);
		glFlush();
	}
}
inline void dialog() {
	printf_s("Введите массу бруска\n");
	std::cin >> mass;
	printf_s("Введите синус угла\n");
	std::cin >> sinA;
	printf_s("Введите Начальную скорость тележки\n");
	std::cin >> speed;
	printf_s("Введите ускорение свободного падения\n");
	std::cin >> G;
	printf_s("Введите коэффициент трения поверхности\n");
	std::cin >> ktr;
	cosA = pow(1 - sinA * sinA, 0.5);
	tgA = sinA / cosA;
	a = G * (sinA - ktr * cosA);
	_getch();
}
