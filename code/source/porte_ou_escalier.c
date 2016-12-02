#include "total.h"

void deplacer_bout_couloir(){
  while(joueur.etat_avant == couloir){
    if(MAP[joueur.coordo_x-1][joueur.coordo_y].lieu == couloir || MAP[joueur.coordo_x-1][joueur.coordo_y].num_salle == joueur.SALLE+1){
      MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
      joueur.etat_avant = MAP[joueur.coordo_x-1][joueur.coordo_y].lieu;
      MAP[joueur.coordo_x-1][joueur.coordo_y].lieu = personnage;
      joueur.coordo_x--;
    }else if(MAP[joueur.coordo_x+1][joueur.coordo_y].lieu == couloir || MAP[joueur.coordo_x+1][joueur.coordo_y].num_salle == joueur.SALLE+1){
      MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
      joueur.etat_avant = MAP[joueur.coordo_x+1][joueur.coordo_y].lieu;
      MAP[joueur.coordo_x+1][joueur.coordo_y].lieu = personnage;
      joueur.coordo_x++;
    }else if(MAP[joueur.coordo_x][joueur.coordo_y-1].lieu == couloir || MAP[joueur.coordo_x][joueur.coordo_y-1].num_salle == joueur.SALLE+1){
      MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
      joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y-1].lieu;
      MAP[joueur.coordo_x][joueur.coordo_y-1].lieu = personnage;
      joueur.coordo_y--;
    }else if(MAP[joueur.coordo_x][joueur.coordo_y+1].lieu == couloir || MAP[joueur.coordo_x][joueur.coordo_y+1].num_salle == joueur.SALLE+1){
      MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
      joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y+1].lieu;
      MAP[joueur.coordo_x][joueur.coordo_y+1].lieu = personnage;
      joueur.coordo_y++;
    }
  }
  joueur.SALLE++;
}

void porte_escalier(WINDOW *chatfenetre,WINDOW *mapfenetre, int utilisateur){

  int choix = 0;
  int dep_reussi = 0;

  cbreak();
	keypad(stdscr,TRUE);
  timeout(0);

  if (joueur.etat_avant == porte){
    mvwprintw(chatfenetre,5,1,"voulez vous changer de salle ?");
    wattron(chatfenetre, COLOR_PAIR(2));
    mvwprintw(chatfenetre,7,1,"oui: appuier sur RIGHTWARDS ARROW");
    mvwprintw(chatfenetre,12,1,"x = %i et y = %i",MAP[joueur.coordo_x][joueur.coordo_y].xb,MAP[joueur.coordo_x][joueur.coordo_y].yb);
    wattroff(chatfenetre,COLOR_PAIR(2));
    wattron(chatfenetre, COLOR_PAIR(1));
    mvwprintw(chatfenetre,9,1,"non: appuier sur LEFTWARDS ARROW");
    wattroff(chatfenetre,COLOR_PAIR(1));
  }else if (joueur.etat_avant == uplevel){
    mvwprintw(chatfenetre,5,1,"voulez vous changer de stage ?");
    wattron(chatfenetre, COLOR_PAIR(2));
    mvwprintw(chatfenetre,7,1,"oui: appuier sur RIGHTWARDS ARROW");
    wattroff(chatfenetre,COLOR_PAIR(2));
    wattron(chatfenetre, COLOR_PAIR(1));
    mvwprintw(chatfenetre,9,1,"non: appuier sur LEFTWARDS ARROW");
    wattroff(chatfenetre,COLOR_PAIR(1));
  }
  wrefresh(chatfenetre);
  do{
    choix = getch();
  }while (choix != KEY_LEFT && choix != KEY_RIGHT);

  switch (choix) {

    case KEY_RIGHT: if (joueur.etat_avant == porte){

                      MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                      int temp_coordo_x = MAP[joueur.coordo_x][joueur.coordo_y].xb;
                      int temp_coordo_y = MAP[joueur.coordo_x][joueur.coordo_y].yb;
                      joueur.coordo_x = temp_coordo_x;
                      joueur.coordo_y = temp_coordo_y;
                      joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y].lieu;
                      MAP[joueur.coordo_x][joueur.coordo_y].lieu = personnage;

                      if(joueur.etat_avant == porte && MAP[joueur.coordo_x][joueur.coordo_y+1].lieu == sol){
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                        joueur.coordo_y++;
                        joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y].lieu;
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = personnage;
                      }else if(joueur.etat_avant == porte && MAP[joueur.coordo_x][joueur.coordo_y-1].lieu == sol){
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                        joueur.coordo_y--;
                        joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y].lieu;
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = personnage;
                      }else if(joueur.etat_avant == porte && MAP[joueur.coordo_x+1][joueur.coordo_y].lieu == sol){
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                        joueur.coordo_x++;
                        joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y].lieu;
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = personnage;
                      }else if(joueur.etat_avant == porte && MAP[joueur.coordo_x-1][joueur.coordo_y].lieu == sol){
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                        joueur.coordo_x--;
                        joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y].lieu;
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = personnage;
                      }
                      joueur.SALLE = MAP[joueur.coordo_x][joueur.coordo_y].num_salle+1;

                    }else if (joueur.etat_avant == uplevel){
                      joueur.STAGE = joueur.STAGE + 1;
                      init_map();
                      Placer_uplevel(MAP, mapfenetre);
                      Placer_perso(MAP, mapfenetre);
                      if(stage_cle == joueur.STAGE){
                        Placer_cle(MAP,mapfenetre);
                      }
                    }
                    affichage(MAP,mapfenetre);
                    wrefresh(mapfenetre);
                    break;
    case KEY_LEFT:
                    switch(deplacement){
                      case 5: MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                              joueur.etat_avant = MAP[joueur.coordo_x+1][joueur.coordo_y].lieu;
                              MAP[joueur.coordo_x+1][joueur.coordo_y].lieu = personnage;
                              joueur.coordo_x++;
                              wrefresh(mapfenetre);
                              break;
                      case 2:	MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                              joueur.etat_avant = MAP[joueur.coordo_x-1][joueur.coordo_y].lieu;
                              MAP[joueur.coordo_x-1][joueur.coordo_y].lieu = personnage;
                              joueur.coordo_x--;
                              wrefresh(mapfenetre);
                              break;
                      case 1: MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                              joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y+1].lieu;
                              MAP[joueur.coordo_x][joueur.coordo_y+1].lieu = personnage;
                              joueur.coordo_y++;
                              wrefresh(mapfenetre);
                              break;
                      case 3: MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                              joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y-1].lieu;
                              MAP[joueur.coordo_x][joueur.coordo_y-1].lieu = personnage;
                              joueur.coordo_y--;
                              wrefresh(mapfenetre);
                              break;
                    }
  }
  ecrire_chat(chatfenetre, MAP[joueur.coordo_x][joueur.coordo_y].lieu);
}
