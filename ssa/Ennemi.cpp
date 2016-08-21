/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Ennemi.cpp
*    @brief Implémentation des méthodes de la classe Ennemi
*/

#include "Ennemi.h"
#include <stdlib.h>
#include <QTimer>
#include <QMovie>
#include <QLabel>
#include <ctime>


Ennemi::Ennemi() //: Vaisseau()
{
	 QPixmap ennemiImg(":images/ennemi.gif");
	 QPixmap ennemi = ennemiImg.scaled(QSize(60, 60), Qt::KeepAspectRatio);
	 setPixmap(ennemi);
	 vie = 1;

	int random_posX = rand() % GAME_WIDTH - (2*this->pixmap().width());
	if (random_posX > this->pixmap().width())
	{
		setPos(random_posX, 0);
	}
	else
	{
		setPos(this->pixmap().width(), 0);
	}

	//Connect Tirer
	QTimer *projTimer = new QTimer();
	shootConnect = QTimer::connect(projTimer, SIGNAL(timeout()), this, SLOT(TirerProjectile()));
	projTimer->start(SHOOT_TIME);

	srand(time(NULL));
	directionEnnemi = rand() % 3;
}

Ennemi::~Ennemi()
{
	disconnect();
}

//Slots
void Ennemi::TirerProjectile() 
{
	int randNum = rand() & 3;
	if( randNum == 1){
			ProjectileEnnemi *projObj = new ProjectileEnnemi();
			projObj->setPos((x() + (this->pixmap().width() / 2)) - (projObj->rect().width() / 2), y()+ this->pixmap().height());
			scene()->addItem(projObj);
		}
}







/**
 * @brief Déplacement vers le bas et vérification de collision
 * @details si il y a collision entre un ennemi et un projectile
 * 			l'ennemi est détruit * 
 */
bool Ennemi::Move() 
{
	switch (directionEnnemi)
	{
	case 0:
		setPos(x(), y() + MOVE_SPEED);
		break;
	case 1:
		if (x() + 3 * MOVE_SPEED / 5 < GAME_WIDTH - pixmap().width())
		{
			setPos(x() + 3 * MOVE_SPEED / 5, y() + MOVE_SPEED);
		}
		else
		{
			directionEnnemi = 2;
		}
		break;
	case 2:
		if (x() - 3 * MOVE_SPEED / 5 > 0)
		{
			setPos(x() - 3 * MOVE_SPEED / 5, y() + MOVE_SPEED);
		}
		else
		{
			directionEnnemi = 1;
		}
		break;
	}
	if ((pos().y() + pixmap().height()) > scene()->height() || vie <= 0) {
		scene()->removeItem(this);
		delete this;
		return false;
	}
	else
	{
		return true;
	}
}

void Ennemi::diminuerVie()
{
	vie--;
	if (vie == 0)
	{
		if (rand() % 10 == 5)
		{
			/*if (getWeaponLevel() == 2 && leJeu->getHealth()->getHealth() == 100) //MAX CANNONS && MAX HP (juste des score++)
			{
				Items * item = new Items(this->pos().x(), this->pos().y(), 0);
				scene()->addItem(item);
			}
			else if (getWeaponLevel() == 2) //MAX CANNONS (no Item_Cannon)
			{
				Items * item = new Items(this->pos().x(), this->pos().y(), rand() % 2);
				scene()->addItem(item);
			}
			else if (leJeu->getHealth()->getHealth() == 100) //MAX HEALTH (no HP BONUS)
			{
				int itemNum = rand() % 2;
				if (itemNum == 1)
				{
					itemNum++;
				}
				Items * item = new Items(this->pos().x(), this->pos().y(), itemNum);
				scene()->addItem(item);
			}
			else //TOUS LES ITEMS
			{
				Items * item = new Items(this->pos().x(), this->pos().y(), rand() % 3);
				scene()->addItem(item);
			}*/
			Items * item = new Items(this->pos().x(), this->pos().y(), rand() % 3);
			scene()->addItem(item);
		}
	}
}

void Ennemi::disconnect()
{
	QObject::disconnect(shootConnect);
}