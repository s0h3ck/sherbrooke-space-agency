/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Joueur.h
*    @brief D�finition de la classe Joueur
*/ 

#ifndef JOUEUR_H
#define JOUEUR_H

#include "Vaisseau.h"
#include "Projectile.h"
#include <qdebug.h>

/**
 * @brief Classe de gestion d'un Joueur
 * @details Un joueur est un Vaisseau 
 * 			qui peux accumuler de l'exp�rience pour changer de niveau
 * 			le niveau est directement li� � la difficult� du jeu
 */	
class Joueur : public Vaisseau {
	Q_OBJECT
private:
	int level;
public:
	Joueur();
	int getLevel();
public slots:
	void addLevel();
signals:
	void changeDifficulty(int newLevel);
};
#endif // !JOUEUR_H
