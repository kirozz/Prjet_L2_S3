
#include "total.h"

int Placer_perso(WINDOW *fenetre){

  int i,max_i,j,max_j,taille_salle;
  taille_salle = 0;
  getmaxyx(fenetre,max_i,max_j);

  for(i = 1; i < max_i -1; i++){
    for(j = 1; j < max_j -1; j++){
      if(MAP[i][j].num_salle == 0){
      	if(MAP[i][j].lieu == sol){
          taille_salle++;
        }
      }
    }
  }

  int pos_perso = aleat(0,taille_salle);
  taille_salle = 0;

  for(i = 1; i < max_i -1; i++){
  	for(j = 1; j < max_j -1; j++){
    	if(MAP[i][j].num_salle == 0){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
          if(taille_salle == pos_perso){
            joueur.coordo_x=i;
            joueur.coordo_y=j;
            joueur.etat_avant = 2;
            MAP[i][j].lieu=personnage;
          }
				}
  		}
		}
  }
  for(i = 1; i < max_i -1; i++){ // test pour verifier que le perso est placer sinon on recommence la fonction
    for(j = 1; j < max_j -1; j++){
      if(MAP[i][j].num_salle == 0){
        if(MAP[i][j].lieu==personnage){
          return 1;
        }
      }
    }
  }
  Placer_perso(fenetre);
}

int Placer_uplevel(WINDOW *fenetre){

    int i,max_i,j,max_j,taille_salle;
    taille_salle = 0;
    getmaxyx(fenetre,max_i,max_j);

  for(i = 1; i < max_i -1; i++){
  	for(j = 1; j < max_j -1; j++){
    	if(MAP[i][j].num_salle == nombre_salle-1){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
				}
  		}
		}
  }

  int pos_uplevel = aleat(0,taille_salle);
  taille_salle = 0;

  for(i = 1; i < max_i -1; i++){
  	for(j = 1; j < max_j -1; j++){
    	if(MAP[i][j].num_salle == nombre_salle-1){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
          if(taille_salle == pos_uplevel){
            if(joueur.STAGE == 5){
              MAP[i][j].lieu=arriver;
            }else{
              if(MAP[i][j+1].lieu==porte){
                MAP[i][j-1].lieu=uplevel;
              }else if(MAP[i][j-1].lieu==porte){
                MAP[i][j+1].lieu=uplevel;
              }else if(MAP[i+1][j].lieu==porte){
                MAP[i-1][j].lieu=uplevel;
              }else if(MAP[i-1][j].lieu==porte){
                MAP[i+1][j].lieu=uplevel;
              }else MAP[i][j].lieu=uplevel;
            }
          }
				}
  		}
		}
  }
  for(i = 1; i < max_i -1; i++){ // test pour verifier que uplevel ou l'arriver est placer sinon on recommence la fonction
    for(j = 1; j < max_j -1; j++){
      if(MAP[i][j].num_salle == nombre_salle-1){
        if(MAP[i][j].lieu==uplevel || MAP[i][j].lieu==arriver){
          return 1;
        }
      }
    }
  }
  Placer_uplevel(fenetre);
	return 0;
}

int Placer_cle(WINDOW *fenetre){

    int i,max_i,j,max_j,salle,taille_salle;
    salle = aleat(1,nombre_salle-2);
    taille_salle = 0;
    getmaxyx(fenetre,max_i,max_j);

  for(i = 1; i < max_i -1; i++){
  	for(j = 1; j < max_j -1; j++){
    	if(MAP[i][j].num_salle == salle){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
				}
  		}
		}
  }

  int pos_cle = aleat(0,taille_salle);
  taille_salle = 0;

  for(i = 1; i < max_i -1; i++){
  	for(j = 1; j < max_j -1; j++){
    	if(MAP[i][j].num_salle == salle){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
          if(taille_salle == pos_cle && joueur.addcle == 0){
            if(MAP[i][j+1].lieu==porte){
              MAP[i][j-1].lieu=cle;
            }else if(MAP[i][j-1].lieu==porte){
              MAP[i][j+1].lieu=cle;
            }else if(MAP[i+1][j].lieu==porte){
              MAP[i-1][j].lieu=cle;
            }else if(MAP[i-1][j].lieu==porte){
              MAP[i+1][j].lieu=cle;
            }else MAP[i][j].lieu=cle;
          }
				}
  		}
		}
  }
  for(i = 1; i < max_i -1; i++){ // test pour verifier que la clé est placer sinon on recommence la fonction
    for(j = 1; j < max_j -1; j++){
      if(MAP[i][j].num_salle == salle){
        if(MAP[i][j].lieu==cle){
          return 1;
        }
      }
    }
  }
  Placer_cle(fenetre);
	return 0;
}