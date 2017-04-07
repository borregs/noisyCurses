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

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

	typedef struct{
		char t[150];
		int m,s;
		char a[150];
	}cancion;

cancion n;

void listado(){
	
	FILE *in;
	int min=0,sec=0,x=0;
	char titulo[150],artista[150];
		
		
	in=fopen("wav.lst","r");
		
	while(!feof(in)){
		
		fscanf(in,"%s %s %d %d",artista,titulo,&min,&sec);
		cancion n[x]={titulo,min,sec,artista};
		x++;
		
	}
		
	fclose(in);


	};
int main(int argc, char **argv)
{


	WINDOW *w,*np;
	int yy=0,xx=0;
	
	initscr();	
	getmaxyx(stdscr,yy,xx);
	box(stdscr,'*','*');

	w=subwin(stdscr,yy-10,xx-8,2,4);
	box(w,0,0);
	
	np=subwin(stdscr,6,xx-8,yy-8,4);
	box(np,0,0);
	
	mvwprintw(stdscr,0,xx/2-12,"NoisyCurses - By Borregs");
	mvwprintw(np,0,4,"En Reproduccion:");
	
	


	waddstr(w, "00:00\tTitulo\tAutista\t");
	getch();
	
	listado();
	
	getch();
	endwin();
	return 0;
}
