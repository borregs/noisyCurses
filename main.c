/*
 * noisyCurses - main.c
 * 
 * Copyright 2017 Borregs <borregs@yopmail.com>
 * Official Clone Repository: 'https://github.com/borregs/noisyCurses/'
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

typedef struct {
	char t[50];
    char a[50];
    char al[50];		
    int s;
    int m;
} cancion;


int fexists(char []);

void choices(WINDOW *m, int hl,cancion n[]);

int nplaying(cancion);
//cancion setCancion();

//void guardarCancion(cancion,char []);

void lector(char [],WINDOW *);

int main(int argc, char **argv)
{


	WINDOW *w,*np,*ctrl;
	int yy=0,xx=0;
		
	initscr();	
	
	cbreak();
	//noecho();
	keypad(stdscr,1);
	
	do{
	clear();
	
	getmaxyx(stdscr,yy,xx);
	box(stdscr,'*','*');
	
	w=subwin(stdscr,yy-10,xx-8,2,4);
	box(w,0,0);
	
	np=subwin(stdscr,6,xx-8,yy-8,4);
	box(np,0,0);
	
	ctrl=subwin(stdscr,yy/4,xx/2,25,40);
	box(ctrl,0,0);
	
	mvwprintw(stdscr,0,xx/2-12,"NoisyCurses - By Borregs");
	mvwprintw(np,0,4,"En Reproduccion:");
	mvwprintw(ctrl,10,4,">");
	mvwprintw(ctrl,9,4,">>");
	mvwprintw(ctrl,1,2,"-| Ingresa Pista a Reproducir |-");


	mvwaddstr(w,0,4, "Lista de Reproduccion:");


	lector("wav.lst",w);
	
	
	
	}while(1);
	endwin();
	return 0;
}
void lector(char arch[],WINDOW *m){
	FILE *f;
	WINDOW *opcion;
	cancion n[5];
	int np=0,hl=0,c=0,a=2,b=2,x=0,xx=0,yy=0;
	char linea[1024],ch;
	
	getmaxyx(stdscr,yy,xx);
	
	if(fexists(arch))
		f=fopen(arch,"r");
	else{
		perror("No existe el archivo");
		return;
	}
	do{
				
        fgets(n[x].a,sizeof(n[x].a),f);
        n[x].a[strlen(n[x].a)-1]='\0';
		
		if(feof(f))
			break;
			
        fgets(n[x].al,sizeof(n[x].al),f);
        n[x].al[strlen(n[x].al)-1]='\0';		

		fgets(n[x].t,sizeof(n[x].t),f);
		n[x].t[strlen(n[x].t)-1]='\0';

		fgets(linea,sizeof(linea),f);
		n[x].m=atoi(linea);


		fgets(linea,sizeof(linea),f);
		n[x].s=atoi(linea);		
		
		mvprintw(4+x,7,"%d)",x+1);
		mvprintw(4+x,24-(strlen(n[x].t)/2),"%s", n[x].t);
		mvprintw(4+x,55-(strlen(n[x].a)/2),"%s",n[x].a);
		mvprintw(4+x,10+((xx/2)-(strlen(n[x].al)/2)),"%s",n[x].al);
		mvprintw(4+x,xx-12,"%d:%d",n[x].m,n[x].s);
		
		
		x++;
		
		}while(1);
		
		
		mvprintw(23+yy/4,xx/2-29,"                             ");
		mvscanw(23+yy/4,xx/2-29,"%d",&hl);
		mvprintw(26,42,"-| Reproduciendo pista %d) |-            ",hl-1);
		wattron(stdscr,A_REVERSE);
		mvprintw(27,42,">>> %s - %s",n[hl-1].t,n[hl-1].a);
		switch(hl){
			case 1:
				system("aplay 1.wav 2>log.txt &");
				mvprintw(3+hl,xx-29,"*");
			break;
			case 2:
				system("aplay 2.wav 2>log.txt &");
				mvprintw(3+hl,xx-29,"*");
			break;
			case 3:
				system("aplay 3.wav 2>log.txt &");
				mvprintw(3+hl,xx-29,"*");
			break;
			case 4:
				system("aplay 4.wav 2>log.txt &");
				mvprintw(3+hl,xx-29,"*");
			break;
			case 5:
				system("aplay 5.wav 2>log.txt &");
				mvprintw(3+hl,xx-29,"*");
			break;
			}
		
		np=nplaying(n[hl-1]);
		wattroff(stdscr,A_REVERSE);
		
		fclose(f);
	}
int fexists(char archivo[])
{      
	FILE *f = fopen(archivo, "r");
          if(f != NULL){
                    fclose(f);
                            return 1;
                                }
              return 0;
}
int nplaying(cancion np){
	
	unsigned int t=time(0)+1;
	int l,m,xx=0,yy=0,x=0,y=0;
	float uo;
	
	getmaxyx(stdscr,yy,xx);
	wrefresh(stdscr);
	
	
	for(x=0;x<=np.m;x++){
		for(y=0;y<60;y++){
			if(y>9)
				mvprintw(yy-7,8,"[0%d:%d]/[0%d:%d]",x,y,np.m,np.s);
			else
				mvprintw(yy-7,8,"[0%d:0%d]/[0%d:%d]",x,y,np.m,np.s);
			
			mvprintw(yy-6,8,"[");
			mvprintw(yy-6,110,"]");
			
			
			l=((np.m*60)+np.s);
			m=((x*60)+y);
			uo=((m*100)/l)/1.00;
			
			mvprintw(yy-6,9+uo,"=");
			if(uo)
			mvprintw(yy-6,8+uo,"=");
			mvprintw(yy-5,107,"%.0f%%",uo);
			if(y<31)
			mvprintw(yy-5,8,"%s - %s",np.t,np.a);
			else
			mvprintw(yy-5,8,"    %s       ",np.al);
			system("sleep 1");
			refresh();
			if(y==np.s&&x==np.m)
				break;
		}	
	}
	
	return 0;
	
	}
void choices(WINDOW *m, int hl,cancion n[]){
	
	int a=2,b=2,x;
	box(m,0,0);
	
	for(x=0;x<4;x++){
		if(hl==x+1){
			wattron(m,A_REVERSE);
			mvwprintw(m,b,a,"%s",n[x+1].t);
			wattroff(m,A_REVERSE);
			}
		else
			mvwprintw(m,b,a,"%s",n[x+1].t);
		b++;}
	wrefresh(m);
	}
