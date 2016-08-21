/**
*	 @author Team SSA_P16
*	 @date Avril-2016
*	 @version 1.6
*	 @name Vaisseau.cpp
*	 @brief Implémentation des méthodes de Vaisseau
*/ 
#include "Vaisseau.h"
#include "Ennemi.h"
#include "Projectile.h"
#include <QGraphicsScene>

Vaisseau::Vaisseau()
{
	weaponLevel = 0;
	QObject::connect(this, SIGNAL(keyLeft()), this, SLOT(moveLeft()));
	QObject::connect(this, SIGNAL(keyRight()),this, SLOT(moveRight()));
	QObject::connect(this, SIGNAL(keyShoot()), this, SLOT(tirer()));
}

void Vaisseau::spawn() 
{
	Ennemi *ennemi = new Ennemi();
	scene()->addItem(ennemi);
}

void Vaisseau::keyPressEvent(QKeyEvent *eventKey)
{
	if (eventKey->key() == Qt::Key_Left) {
		emit keyLeft();
	}
	else if (eventKey->key() == Qt::Key_Right) {
		emit keyRight();
	}
	else if (eventKey->key() == Qt::Key_Up) {
		emit keyShoot();
	}
}

void Vaisseau::TirerProjectile() {

	
	if (weaponLevel == 2)
	{
		Projectile *projObj2 = new Projectile();
		projObj2->setPos((x() + 31 + (this->pixmap().width() / 2)) - (projObj2->rect().width() / 2), y() + 27);
		scene()->addItem(projObj2);

		Projectile *projObj1 = new Projectile();
		projObj1->setPos((x()- 30 + (this->pixmap().width() / 2)) - (projObj1->rect().width() / 2), y() + 27);
		scene()->addItem(projObj1);

		Projectile *projObj = new Projectile();
		projObj->setPos((x() + 1 + (this->pixmap().width() / 2)) - (projObj->rect().width() / 2), y());
		scene()->addItem(projObj);
	}
	else if (weaponLevel == 1)
	{
		Projectile *projObj1 = new Projectile();
		projObj1->setPos((x() - 30+ (this->pixmap().width() / 2)) - (projObj1->rect().width() / 2), y() + 27);
		scene()->addItem(projObj1);

		Projectile *projObj = new Projectile();
		projObj->setPos((x() + 1 + (this->pixmap().width() / 2)) - (projObj->rect().width() / 2), y());
		scene()->addItem(projObj);
	}
	else
	{
		Projectile *projObj = new Projectile();
		projObj->setPos((x() + 1 + (this->pixmap().width() / 2)) - (projObj->rect().width() / 2), y());
		scene()->addItem(projObj);
	}

}

void Vaisseau::moveLeft()
{
	if (pos().x() > 0)
		setPos(x() - 20, y());
}

void Vaisseau::moveRight()
{
	if ((pos().x() + this->pixmap().width()) < scene()->width())
		setPos(x() + 20, y());
}

void Vaisseau::tirer()
{
	QList<QGraphicsItem *> colliding_items = collidingItems();
	if (colliding_items.empty())
	{
		TirerProjectile();
	}
	for (int i = 0, n = colliding_items.size(); i < n; ++i)
	{
		if ((typeid(*(colliding_items[i])) == typeid(Vaisseau)))
		{
			TirerProjectile();
		}
	}
}

void Vaisseau::WeaponUp() {
	if (weaponLevel < 2)
	{
		weaponLevel++;
	}
}
void Vaisseau::WeaponDown() {
	if (weaponLevel > 0)
	{
		weaponLevel--;
	}
}

int Vaisseau::getWeaponLevel()
{
	return weaponLevel;
}