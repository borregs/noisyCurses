/*
 * noisyCurses - main.c
 * 
 * Copyright 2017 Borregs <borregs@yopmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "global.h"
#include "nplaying.h"
#include "lector.h"
#include "aplayer.h"



int main(int argc, char **argv)
{


	WINDOW *w,*np,*ctrl;
	int yy=0,xx=0;
		
	initscr();
	
	cbreak();
	//noecho();
	keypad(stdscr,1);	
	//nodelay(stdscr,TRUE);
//	getch();
	system("sleep 1");
	getch();
	do{
	clear();
	
	getmaxyx(stdscr,yy,xx);
	box(stdscr,'*','*');
	
	w=subwin(stdscr,yy-10,xx-8,2,4);
	box(w,0,0);
	
	np=subwin(stdscr,7,xx-8,yy-8,4);
	box(np,0,0);
	
	ctrl=subwin(stdscr,yy/4,xx/2,yy/2,((xx/2)-(xx/4)));
	box(ctrl,0,0);
	
	mvwprintw(stdscr,0,xx/2-12,"NoisyCurses - By Borregs");
	mvwprintw(np,0,4,"En Reproduccion:" );
	mvwprintw(ctrl,8,4,">");
	mvwprintw(ctrl,7,4,">>");
	mvwprintw(ctrl,1,2,"-| Ingresa Pista a Reproducir |-");
	mvwaddstr(w,0,4, "Lista de Reproduccion:");

	lector("wav.lst",ctrl,np,w);
	
	}while(1);
	endwin();
		return 0;
}
