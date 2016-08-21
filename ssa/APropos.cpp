/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Options.cpp
*    @brief Implémentation des méthodes de la classe Options
*/ 
#include "APropos.h"
#include <QLabel>

APropos::APropos(QStackedWidget *parent)
{
	layout = new QGridLayout;

	QLabel *titreAPropos;
	titreAPropos = new QLabel(QStringLiteral("À Propos"));
	titreAPropos->setStyleSheet("font-size: 40px; font-style: bold; font-family: Impact; color: yellow;");

	bouton = new QPushButton("Retour au menu");
	bouton->setObjectName("boutonRetour");
	bouton->setMinimumHeight(50);
	bouton->setMaximumWidth(200);
	bouton->setStyleSheet("QPushButton#boutonRetour {background-color: transparent; border: 2px solid yellow; font-size: 18px; color: yellow; height: 58px; width: 190px; text-align: center;}QPushButton#boutonRetour:hover{border: 4px solid yellow; font-size: 20px;}");


	QPixmap aPropos(":images/APropos.png");
	QLabel *imageAPropos;
	imageAPropos = new QLabel;
	imageAPropos->setPixmap(aPropos);

	layout->addWidget(titreAPropos);
	layout->addWidget(imageAPropos);
	layout->addWidget(bouton);
	layout->setAlignment(titreAPropos, Qt::AlignCenter);
	layout->setAlignment(bouton, Qt::AlignCenter);
	layout->setAlignment(imageAPropos, Qt::AlignCenter);

	setLayout(layout);
	this->parent = parent;
	connect(bouton, SIGNAL(released()), this, SLOT(retour()));
	connect(this, SIGNAL(retourAuMenu()), parent, SLOT(retour()));
}

APropos::~APropos()
{
	
}

void APropos::retour()
{
    emit retourAuMenu();
}