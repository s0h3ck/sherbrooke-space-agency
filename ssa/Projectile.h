/**
*	 @author Team SSA_P16
*	 @date Avril-2016
*	 @version 1.6
*	 @name Projectile.h
*	 @brief Définition de la classe Projectile
*/ 
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsRectItem>
#include <QObject>

/**
 * @brief Classe de gestion des projectiles du joueur
 * @details Gestion du déplacement et des collision des projectiles
 * 			tirer par le joueur.
 */

class Projectile : public QObject, public QGraphicsRectItem {
	Q_OBJECT
private:
public:
	Projectile();
	~Projectile();
	bool Move();
};

#endif
