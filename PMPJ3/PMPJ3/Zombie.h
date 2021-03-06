#pragma once
#include <iostream>
#include "GL/glut.h"
#include "area.h"


class Zombie {
public:
	Zombie() {
		static int t = 0;
		this->Zombie_ID = t;
		srand(time(NULL) + t++);
		int x = (rand() % WIDTH);
		int y = (rand() % HEIGHT);
		while (occupied[x][y] == 1) {
			int x = (rand() % WIDTH);
			int y = (rand() % HEIGHT);
		}
		pos_x = x;
		pos_y = y;
		life = true;
		Zombie_Dir = rand() % 4;
	}
	Zombie(const Zombie& z) {
      this->pos_x = z.pos_x;
      this->pos_y = z.pos_y;
	  this->life = z.life;
	  this->Zombie_Dir = z.Zombie_Dir;
	  this->life = z.life;
   }
	void zombie_die() {
		zombie_killed++;
		life = false;
	}
   void draw_zombie() {
		glPointSize(object_size);
		glBegin(GL_POINTS);
		glColor3f(1, 0, 0);
		glVertex2f(pos_x, pos_y);
		glEnd();
   }
   void move() {
	   if (life) {
		   int temp = rand() % 5;

		   if (temp == 0) Zombie_Dir = rand() % 4;
		   if (Zombie_Dir == 0) {
			   if ((pos_y + 1) < HEIGHT && occupied[pos_x][pos_y + 2] != 1)	   this->pos_y += 1;
			   else {
				   this->pos_y--; Zombie_Dir = rand() % 3 + 1;
			   }
		   }
		   else if (Zombie_Dir == 1) {
			   if ((pos_y - 1) > 0 && occupied[pos_x][pos_y - 2] != 1)   this->pos_y -= 1;
			   else {
				   this->pos_y++; Zombie_Dir = (rand() % 3 + 2) % 4;
			   }
		   }
		   else if (Zombie_Dir == 2) {
			   if ((pos_x - 1) > 0 && occupied[pos_x - 2][pos_y] != 1)   this->pos_x -= 1;
			   else {
				   this->pos_x++; Zombie_Dir = (rand() % 3 + 3) % 4;
			   }
		   }
		   else if (Zombie_Dir == 3) {
			   if ((pos_x + 1) < WIDTH && occupied[pos_x + 2][pos_y] != 1)  this->pos_x += 1;
			   else {
				   this->pos_x--;  Zombie_Dir = (rand() % 3 + 4) % 4;
			   }
		   }
	   }
   }
   int getX() { return pos_x; }
   int getY() { return pos_y; }
   bool exist() { 
	   if (life) return true;
	   else return false;
	 //  return life; 
   }

private:
   int pos_x;
   int pos_y;
   int Zombie_Dir;
   int Zombie_ID;
   int speed = 1;
   bool life;
};
