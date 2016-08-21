/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Joueur.cpp
*    @brief Implémentation des méthodes de la classe Joueur
*/ 
#include "Joueur.h"
Joueur::Joueur() : Vaisseau()
{
	QPixmap vaisseauImg(":images/vaisseau.png");
	QPixmap vaisseau = vaisseauImg.scaled(QSize(120, 120), Qt::KeepAspectRatio);
	this->setPixmap(vaisseau);
	this->level = 1;
}

void Joueur::addLevel() 
{
	qDebug() << "addLevel()";
	level++;
	emit changeDifficulty(level);
}

int Joueur::getLevel()
{
	return level;
}