//
//
//#include"particle.h"
//#include <conio.h>
//#include <windows.h>
//
////#include <stdio.h>
//vector<particle> particles ;
//#include <glut.h>
//
//string s = "proton";
//
//void calc() {
//	for (int i = 0; i < particles.size(); i++) {
//		particles[i].forse_calc(particles, i);
//	}
//	for (int i = 0; i < particles.size(); i++) {
//		particles[i].move();
//
//	}
//}
//
//
//void draw() {
//	//glColor3f(1, 0, 0); 
//		/*glBegin(GL_LINES);
//
//		for (int i = 0; i < particles.size(); i++) {
//			glVertex2d(particles[i].x, particles[i].y);
//		}
//		glEnd;
//
//*/
//	glBegin(GL_POINTS);
//	for (int i = 0; i < particles.size(); i++) {
//		
//		//glColor3f(particles[i].colorR, particles[i].colorG, particles[i].colorB);
//		glVertex2i(particles[i].x, particles[i].y);
//	}
//	//glVertex2d(175.0, 95.0);
//	glEnd();
//
//
//
//}
//	void myInit(void)
//
//	{
//
//		//������������� ����� ���� ����
//
//		glClearColor(1.0, 1.0, 1.0, 0.0);
//
//		//������������� ���� ���������
//
//		glColor3f(1.0f, 0.0f, 1.0f);
//
//		// ������ point 4*4 �������
//
//		glPointSize(10.0);
//
//		// ��������� ������� ������� ���������
//
//		glMatrixMode(GL_PROJECTION);
//
//		glLoadIdentity();
//
//		gluOrtho2D(-700, 700, -350, 350);
//
//	}
//	void myDisplay(void) {
//
//		// ������� ����� �� �����
//
//		glClear(GL_COLOR_BUFFER_BIT);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		glPolygonMode(GL_FRONT, GL_FILL);
//
//		while (true) {
//			glClearColor(0.0, 0.0, 0.0, 0.0);
//			glClear(GL_COLOR_BUFFER_BIT);
//
//			calc();
//			draw();
//			Sleep(10);
//			glFlush();
//			//_getch();
//			
//		}
//		
//
//
//	}
//
//	int main(int argc, char **argv)
//	{	particles.push_back(particle(-80, 90, "proton"));
//	particles.push_back(particle(120, 102, "proton"));
//	particles.push_back(particle(200, 100, "proton"));
//	//particles.push_back(particle(200, 150, "proton"));
//	//particles.push_back(particle(200, 30, "prton"));
//		
//		
//		//�������������� ��������������
//		glutInit(&argc, argv);
//		//������������� ����� �����������
//		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//				//������������ ������ ����
//				glutInitWindowSize(1400, 700);
//		//������������� ��������� ���� �� ������
//		glutInitWindowPosition(0, 0);
//				//��������� �������� ����
//				glutCreateWindow("My first programm OpenGL");
//		myInit();
//
//		//������������ ������� ����������
//		glutDisplayFunc(myDisplay);
//
//		//������ � ����������� ����
//
//		glutMainLoop();
//
//	}