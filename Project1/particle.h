//#pragma once
//#include <Compl.h>
//#include <string>
//#include <string.h>
//#include <vector>
//using namespace std;
//
//
//
//#define mprot 10;
//# define kul 300;//10000.5;
//#define grav 0.05;
//class particle {
//public :
//	int x, y;
//	float weight;
//	float charge;
//	float forsex;
//	float forsey;
//	float speedx = 0;
//	float speedy = 0;
//	particle(int xx,int yy, string str) {
//		x = xx;
//		y = yy;
//		if (str == "proton") {
//			weight =mprot ;
//			charge =1;
//		}
//		if (str == "neutron") {
//			weight =mprot;
//			charge =0;
//		}
//		if (str == "electron") {
//			weight =1;
//			charge =-1;
//		}
//
//
//
//
//	}
//	void forse_calc(vector<particle> particles,int exept){
//forsex = 0;
//			forsey = 0;
//			
//		for (int i = 0; i < particles.size(); i++) {
//			if (i == exept)continue;
//			int delta_x = particles[i].x - x;
//			int delta_y = particles[i].y - y;
//			if((delta_y==0)&& (delta_x == 0)){
//				forsey += 0;
//				forsex += 0;
//				continue;
//			}
//			float Fk, Fn;
//			
//
//			Fk = ((particles[i].charge*charge) /( pow((pow(delta_x, 2)) + (pow(delta_y, 2)), 0.5)) )*kul;
//			Fn = ((particles[i].weight*weight) / (pow((pow(delta_x, 2)) + (pow(delta_y, 2)), 0.5))) *grav;
//
//		//printf_s("%f %f sili\n ", Fk, Fn);
//			forsey += ((Fk + Fn)*delta_y)/pow((delta_x*delta_x+ delta_y* delta_y),0.5);
//			forsex += ((Fk + Fn)*delta_x)/pow((delta_x*delta_x+ delta_y* delta_y),0.5);
//			//printf_s("%f %f\n", Fk, Fn);
//			//printf_s("%f %f projections\n ", forsex, forsey);
//			}
//		}
//
//
//
//
//	void move() {
//		printf_s("%d %d %f %f %f %f\n",x,y,speedx,speedy,forsex,forsey);
//		int xn = x;
//		int yn = y;
//		x = x + speedx + forsex / (2 * weight);
//		y = y + speedy + forsey / (2 * weight);
//		speedx = x - xn;
//		speedy = y - yn;
//		//printf_s("%f %f %f %f %f %f\n", x, y, speedx, speedy, forsex, forsey);
//	}
//	};
//
//
//
//
//
//
