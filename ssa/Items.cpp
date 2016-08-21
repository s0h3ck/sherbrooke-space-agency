/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Items.cpp
*    @brief Implémentation des méthodes de la classe Items
*/ 

#include "Items.h"

Items::Items(int x, int y,int type)
{
	itemType = type;

	if (itemType == HEALTH_BONUS)
	{
		QPixmap coeurImg(":images/coeur.png");
		QPixmap coeur = coeurImg.scaled(QSize(50, 50), Qt::KeepAspectRatio);
		this->setPixmap(coeur);
	}
	if (itemType == SCORE_BONUS)
	{
		QPixmap lightningImg(":images/lightning.png");
		QPixmap lightning = lightningImg.scaled(QSize(50, 50), Qt::KeepAspectRatio);
		this->setPixmap(lightning);
	}
	if (itemType == WEAPON_UP)
	{
		QPixmap weaponImg(":images/weapon.png");
		QPixmap weapon = weaponImg.scaled(QSize(50, 50), Qt::KeepAspectRatio);
		this->setPixmap(weapon);
	}
	setPos(x, y);
}

int Items::getType()
{
	return itemType;
}

/**
 * @brief Déplacement et détection de collision des items
 * @details Lorsque l'item entre en contact avec le joueur
			celui-ci recoit le bonus lié à l'item
 */
bool Items::Move() 
{
	setPos(x(), y() + 10);
	if ((pos().y() + pixmap().height()) > scene()->height()) {
		scene()->removeItem(this);
		delete this;
		return false;
	}
	else
	{
		return true;
	}
}