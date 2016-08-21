/**
*@author Team SSA_P16
*@date Avril-2016
*@version 1.6
*@name CommentJouer.cpp
*@brief Implémentation des méthodes de la classe ComentJouer
*/
#include "CommentJouer.h"
CommentJouer::CommentJouer(QStackedWidget *parent)
{
	layout = new QGridLayout;
	
	QLabel *titreCJouer;
	titreCJouer = new QLabel("Comment jouer?");
	titreCJouer->setStyleSheet("font-size: 40px; font-style: bold; font-family: Impact; color: yellow;");
	
	bouton = new QPushButton("Retour au menu");
	bouton->setObjectName("boutonRetour");
	bouton->setMinimumHeight(50);
	bouton->setMaximumWidth(200);
	bouton->setStyleSheet("QPushButton#boutonRetour {background-color: transparent; border: 2px solid yellow; font-size: 18px; color: yellow; height: 58px; width: 190px; text-align: center;}QPushButton#boutonRetour:hover{border: 4px solid yellow; font-size: 20px;}");


	QPixmap cJouer(":images/commentJouer.png");
	QLabel *imageCJouer;
	imageCJouer = new QLabel;
	imageCJouer->setPixmap(cJouer);
	
	layout->addWidget(titreCJouer);
	layout->addWidget(imageCJouer);
	layout->addWidget(bouton);
	layout->setAlignment(titreCJouer, Qt::AlignCenter);
	layout->setAlignment(bouton, Qt::AlignCenter);
	layout->setAlignment(imageCJouer, Qt::AlignCenter);
	
	setLayout(layout);
	this->parent = parent;
	connect(bouton, SIGNAL(released()), this, SLOT(retour()));
	connect(this, SIGNAL(retourAuMenu()), parent, SLOT(retour()));
}
CommentJouer::~CommentJouer()
{
}
void CommentJouer::retour()
{
	emit retourAuMenu();
}