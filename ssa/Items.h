/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Items.h
*    @brief Définition de la classe Items
*/ 

#ifndef ITEMS_H
#define ITEMS_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>
#include "Joueur.h"
#include "Jeu.h"
#define HEALTH_BONUS 0
#define SCORE_BONUS 1
#define WEAPON_UP 2

/**
 * @brief Classe de gestion des items 
 * @details Gestion des items pouvant apparaitre sur l'aire de jeu
 */
class Items : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
private:
	int itemType;
public:
	Items(int x, int y, int type);
	int getType();
	bool Move();

};

#endif