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

typedef struct {
	char t[50];
    char a[50];
    char al[50];		
    int s;
    int m;
} cancion;


int fexists(char []); 

//void choices(WINDOW *m, int hl,cancion n[]);

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

	getch();

	do{
	clear();
	
	getmaxyx(stdscr,yy,xx);
	box(stdscr,'*','*');
	
	w=subwin(stdscr,yy-10,xx-8,2,4);
	box(w,0,0);
	
	np=subwin(stdscr,6,xx-8,yy-8,4);
	box(np,0,0);
	
	ctrl=subwin(stdscr,yy/4,xx/2,20,(xx/2)-20);
	box(ctrl,0,0);
	
	mvwprintw(stdscr,0,xx/2-12,"NoisyCurses - By Borregs");
	mvwprintw(np,0,4,"En Reproduccion:" );
	mvwprintw(ctrl,8,4,">");
	mvwprintw(ctrl,7,4,">>");
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
	cancion n[7];
	int np=0,hl=0,c=0,a=2,b=2,x=0,xx=0,yy=0;
	char linea[1024],ch;
	
	getmaxyx(stdscr,yy,xx);
	
	if(fexists(arch))					
		f=fopen(arch,"r");				//Si el archivo existe se abre para lectura
	else{							//sino
		perror("No existe el archivo");			//print Error o Imprime Eroor
		return;
	}
	do{
				
        fgets(n[x].a,sizeof(n[x].a),f);
        n[x].a[strlen(n[x].a)-1]='\0';
	//Se lee una linea del archivo de listado de canciones y se le assigna su valor a el artista 

		if(feof(f))
			break;
		        //Si ya se acabo el Archivo entonces break.	
		
        fgets(n[x].al,sizeof(n[x].al),f);
        n[x].al[strlen(n[x].al)-1]='\0';		
	//Se lee siguiente linea del archivo de listado de canciones  y se le assigna su valor a el album
		
		fgets(n[x].t,sizeof(n[x].t),f);
		n[x].t[strlen(n[x].t)-1]='\0';
		//Se lee siguiente linea del archivo de listado de canciones  y se le assigna su valor a el titulo. 
		fgets(linea,sizeof(linea),f);
		n[x].m=atoi(linea);
		//Se lee siguiente linea del archivo como una palabra.
		//Si la palabra contiene charecteres numericos los parsa a integros y se le assigna su valor a los minutos.

		fgets(linea,sizeof(linea),f);
		n[x].s=atoi(linea);		
		//Se lee siguiente linea del archivo como una palabra.
		//Si la palabra contiene charecteres numericos los parsa a integros y se le assigna su valor a los segundos.
		
		mvprintw(4+x,24-(strlen(n[x].t)/2),"%s",n[x].t);
		mvprintw(4+x,52-(strlen(n[x].a)/2),"%s",n[x].a);
		mvprintw(4+x,22+((xx/2)-(strlen(n[x].al)/2)),"%s",n[x].al);
		mvprintw(4+x,7,"%d)",x+1);
		mvprintw(4+x,xx-12,"%d:%d",n[x].m,n[x].s);
		//imprime el listado de canciones.

		x++;
		
		}while(1);
		
		
		mvprintw(23+yy/4,xx/2-29,"                             ");
		mvscanw(27,xx/2-13,"%d",&hl);
		mvprintw(21,49,"-| Reproduciendo pista %d) |-            ",hl-1);
		wattron(stdscr,A_REVERSE);
		//Ncurses, esta funcion basicamente Prende.atributo(macro COLORES_INVERTIDOS).
		//atributo inverso prendido para todo nuevo texto desplegado
	
		mvprintw(26,53,">>> %s - %s",n[hl-1].t,n[hl-1].a);
		switch(hl){
			case 1:
				system("aplay 1.wav 2>>log.txt &");
				mvprintw(3+hl,xx-18,"*");
			break;
			case 2:
				system("aplay 2.wav 2>>log.txt &");
				mvprintw(3+hl,xx-18,"*");
			break;
			case 3:
				system("aplay 3.wav 2>>log.txt &");
				mvprintw(3+hl,xx-18,"*");
			break;
			case 4:
				system("aplay 4.wav 2>>log.txt &");
				mvprintw(3+hl,xx-18,"*");
			break;
			case 5:
				system("aplay 5.wav 2>>log.txt &");
				mvprintw(3+hl,xx-18,"*");
			break;
			case 6:
	                        system("aplay 6.wav 2>>log.txt &");
                                mvprintw(3+hl,xx-18,"*");
			break;
			case 7:
                                system("aplay 7.wav 2>>log.txt &");
                                mvprintw(3+hl,xx-18,"*");
			break;
			}
		np=nplaying(n[hl-1]);
		wattroff(stdscr,A_REVERSE);//Ncurses, apagar atributo inverso.
		
		fclose(f);//Cierra el archivo wav.lst

	}
int fexists(char archivo[])//Si el archivo existe se abre para lectura, sino break
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
			//usando los segundos pasados y la duracion de la cancion determina el porcentaje. 
		
			mvprintw(yy-6,9+uo,"=");
			if(uo)
			mvprintw(yy-6,8+uo,"=");
			mvprintw(yy-5,107,"%.0f%%",uo);
			if(y<31)
			mvprintw(yy-5,8,"%s - %s",np.t,np.a);
			else
			mvprintw(yy-5,8,"    %s       ",np.al);
			system("sleep 1");//espera un segundo...
			refresh();
			if(y==np.s&&x==np.m)
				break;
		}	
	}
	
	return 0;
	
	}
