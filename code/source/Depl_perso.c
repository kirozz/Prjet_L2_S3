#include "total.h"

int test_depl(t_cellule MAP [x] [y], int c,t_joueur joueur){
 
 	t_joueur temp_joueur;
 	temp_joueur = joueur;
 	switch(c){
 		case KEY_UP:	if(MAP[temp_joueur.coordo_x+1][temp_joueur.coordo_y].lieu == mur){
 										return 0;
 									}else{
 										return 1;
 									}
 		case KEY_DOWN:	if(MAP[temp_joueur.coordo_x-1][temp_joueur.coordo_y].lieu == mur){
 											return 0;
 										}else{
 											return 1;
 										}
 	case KEY_LEFT:	if(MAP[temp_joueur.coordo_x][temp_joueur.coordo_y-1].lieu == mur){
 										return 0;
 										}else{
 											return 1;
 										}
 		case KEY_RIGHT:	if(MAP[temp_joueur.coordo_x][temp_joueur.coordo_y+1].lieu == mur){
 											return 0;
 										}else{
 											return 1;
 										}
 	}
 	return 0;
  }

void Depl_perso(t_cellule MAP [x] [y],t_joueur *joueur, int *ligne, WINDOW *fenetre){
	cbreak();
	keypad(stdscr,TRUE);
	t_joueur temp_joueur;
 	temp_joueur = *joueur;
   	int c;
	c = getch();
	if(c!=ERR){
		switch(c){
			case KEY_UP:	if(test_depl(MAP, c, temp_joueur)){
 											ecrire_chat(fenetre,&(*ligne), MAP[temp_joueur.coordo_x+1][temp_joueur.coordo_y].lieu);
 											MAP[temp_joueur.coordo_x+1][temp_joueur.coordo_y].lieu = personnage;
 											MAP[temp_joueur.coordo_x][temp_joueur.coordo_y].lieu = sol;
											temp_joueur.coordo_x++;
 										}
 										break;
 			case KEY_DOWN:	if(test_depl(MAP, c, temp_joueur)){
 												ecrire_chat(fenetre,&(*ligne), MAP[temp_joueur.coordo_x-1][temp_joueur.coordo_y].lieu);
 												MAP[temp_joueur.coordo_x-1][temp_joueur.coordo_y].lieu = personnage;
 												MAP[temp_joueur.coordo_x][temp_joueur.coordo_y].lieu = sol;
												temp_joueur.coordo_x--;
 										}
 										break;
 			case KEY_LEFT:	if(test_depl(MAP, c, temp_joueur)){
 												ecrire_chat(fenetre,&(*ligne), MAP[temp_joueur.coordo_x][temp_joueur.coordo_y-1].lieu);
 												MAP[temp_joueur.coordo_x][temp_joueur.coordo_y-1].lieu = personnage;
 												MAP[temp_joueur.coordo_x][temp_joueur.coordo_y].lieu = sol;
 												temp_joueur.coordo_y--;
 										}
 										break;
 			case KEY_RIGHT: if(test_depl(MAP, c, temp_joueur)){
 												ecrire_chat(fenetre,&(*ligne), MAP[temp_joueur.coordo_x][temp_joueur.coordo_y+1].lieu);
 												MAP[temp_joueur.coordo_x][temp_joueur.coordo_y+1].lieu = personnage;
 												MAP[temp_joueur.coordo_x][temp_joueur.coordo_y].lieu = sol;
 												temp_joueur.coordo_y++;
 											}
 											break;
		}
	}
	*joueur = temp_joueur;
}
	
