/**
*	 @author Team SSA_P16
*	 @date Avril-2016
*	 @version 1.6
*	 @name ProjectileEnnemi.h
*	 @brief Définition de la classe ProjectileEnnemi
*/ 
#ifndef PROJECTILEENNEMI_H
#define PROJECTILEENNEMI_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QgraphicsScene>
#include <QTimer>
#include <QList>
#include "Vaisseau.h"
#include "Ennemi.h"
#include "Health.h"
#include "Jeu.h"

#include "Projectile.h"

/**
 * @brief Classe de gestion des projectiles ennemi
 * @details Les projectiles tirer par les ennemi, gestion
 * 			du déplacement et des collisions
 */
class ProjectileEnnemi : public QObject, public QGraphicsRectItem {
	Q_OBJECT
private:
public:
	ProjectileEnnemi();
	~ProjectileEnnemi();
	bool Move();
};

#endif
#pragma once
