#include "total.h"

int fin_game(WINDOW *chat_Win,WINDOW *map_Win,WINDOW *stat_Win){
	int startx, starty, width, height;
	WINDOW *fin_Win;
	WINDOW *rejouer_Win;
	cbreak();
	keypad(stdscr,TRUE);
	timeout(0);
	int choix;
	height = 15;
	width = 90;
	startx = 39;
	starty = 2;
  effacer_fenetre(map_Win);
	wborder(map_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
	wrefresh(map_Win);
	delwin(map_Win);
	fin_Win=create_newwin(height,width,starty,startx,"FIN");
	if(joueur.etat_avant == arriver && joueur.addcle == 1){
		mvwprintw(fin_Win,4,30,"félicitation, vous n'etes pas trop nul");
		mvwprintw(fin_Win,6,27,"Vous avez reussi a atteindre l'arriver avec la clé");
	}else if(mort == 1){
		mvwprintw(fin_Win,4,32,"Dommage, vous etes trop nul");
		mvwprintw(fin_Win,6,30,"Vous etes mort comme une merde");
	}
	wrefresh(fin_Win);
	height = 15;
	width = 90;
	startx = 39;
	starty = 18;
	rejouer_Win=create_newwin(height,width,starty,startx,"REJOUER");
	mvwprintw(rejouer_Win,4,18,"Vous avez gagner la partie voulez vous rejouer ou quitter");
	mvwprintw(rejouer_Win,9,17,"LEFTWARDS ARROW: QUITTER");
	mvwprintw(rejouer_Win,9,52,"RIGHTWARDS ARROW: REJOUER");
	wrefresh(rejouer_Win);
	do{
		choix = getch();
	}while(choix != KEY_RIGHT && choix != KEY_LEFT);
	if(choix == KEY_RIGHT){
    effacer_fenetre(stat_Win);
    effacer_fenetre(chat_Win);
    effacer_fenetre(rejouer_Win);
		wborder(rejouer_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
		wrefresh(rejouer_Win);
		delwin(rejouer_Win);
		effacer_fenetre(fin_Win);
		wborder(fin_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
		wrefresh(fin_Win);
		delwin(fin_Win);
		mort = 0;
		height = 31;
    width = 90;
    starty = 2 ;
    startx = 39 ;
		map_Win=create_newwin(height,width,starty,startx,"Map");
	}
  if(choix == KEY_RIGHT){
    return 1;
  }else return 0;
}