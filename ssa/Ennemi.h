/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Ennemi.h
*    @brief Définition de la classe Ennemi
*/

#ifndef ENNEMI_H
#define ENNEMI_H

#include <QgraphicsScene>
#include <QObject>

#include "Vaisseau.h"
#include "ProjectileEnnemi.h"

#define POINTS 10
#define MOVE_SPEED 5
#define MOVE_TIME 50
#define SHOOT_TIME 500

//extern Jeu leJeu;

class Ennemi : public Vaisseau {
	Q_OBJECT
private:
	int vie;
	int directionEnnemi;
	QMetaObject::Connection shootConnect;
public:
	Ennemi();
	~Ennemi();
	bool Move();
	void diminuerVie();
public slots:
	void TirerProjectile();
	void disconnect();

};

#endif // ENNEMI_H

