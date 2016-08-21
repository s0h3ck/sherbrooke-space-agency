/**
*	 @author Team SSA_P16
*	 @date Avril-2016
*	 @version 1.6
*	 @name ProjectileEnnemi.cpp
*	 @brief Implémentation des méthodes de la classe ProjectileEnnemi
*/ 

#include "ProjectileEnnemi.h"

ProjectileEnnemi::ProjectileEnnemi()
{
	setRect(0, 0, 15, 15);
	setBrush(QBrush(Qt::red));
	setPen(QPen(Qt::red));
}

ProjectileEnnemi::~ProjectileEnnemi()
{
}

bool ProjectileEnnemi::Move() {
	setPos(x(), y() + 10);
	if ((pos().y() + rect().height()) > GAME_HEIGHT) {
		scene()->removeItem(this);
		delete this;
		return false;
	}
	else
	{
		return true;
	}
}