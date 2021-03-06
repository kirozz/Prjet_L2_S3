
/**
 * \file debut_partie.c
 * \brief Programme regroupant les appels de fonction pour chaque début de partie
 * \author SEBILLE Florian
 * \version 1.0.1
 */

#include "total.h"

/**
 * \fn void debut_game(WINDOW *S_win, WINDOW *T_win)
 * \brief Fonction qui initialise la map et place les différents elements.
 *
 * \param S_win contenant la map.
 * \param T_win contenant le chat.
 */
void debut_game(WINDOW *S_win, WINDOW *T_win){
  init_map(S_win);
  Placer_uplevel();
  Placer_perso();
  Placer_food();
  if(joueur.STAGE == 1){
    joueur.addcle = 0;
    stage_cle = aleat(2,5);
    stage_medikit = aleat(2,5);
    joueur.LEVEL = 1;
    joueur.EXP = 1;
    joueur.HP = 20;
    joueur.ATT = 5;
    joueur.DEF = 12;
    joueur.FOOD = 10;
  }
  joueur.SALLE = 1;
  ecrire_chat(T_win, 2);
}
