/**
*	 @author Team SSA_P16
*	 @date Avril-2016
*	 @version 1.6
*	 @name Projectile.cpp
*	 @brief Implémentation des méthodes de la classe Projectile
*/
 
#include "Projectile.h"
#include <QgraphicsScene>
#include <QTimer>
#include <QList>
#include "Ennemi.h"
#include "Score.h"
#include "Jeu.h"
#include "Items.h"

Projectile::Projectile()
{
	setRect(0, -15, 5, 25);
	setBrush(QBrush(Qt::green));
	setPen(QPen(Qt::green));
}


Projectile::~Projectile()
{
}


bool Projectile::Move() 
{
	setPos(x(), y() - 10);
	if ((pos().y() + rect().height())< 0){
		scene()->removeItem(this);
		delete this;
		return false;
	}
	else
	{
		return true;
	}
}
