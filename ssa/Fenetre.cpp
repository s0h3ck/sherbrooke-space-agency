/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Fenetre.cpp
*    @brief Implémentation des méthodes de la classe Fenetre
*/
#include "Fenetre.h"

Fenetre::Fenetre(QWidget*) : largeur(700), hauteur(525)
{
	creerMenu();                // Creation du Menu
	creerPeaufinage();          // Creation des parametres de notre fenetre
}

Fenetre::~Fenetre()
{
    delete menu;                // Suppression du menu
}

void Fenetre::creerMenu()
{
	menu = new Menu();          // Creer notre menu
    setCentralWidget(menu);     // Placer le menu comme centralWidget
}

void Fenetre::creerPeaufinage()
{
	setWindowTitle("Sherbrooke Space Agency (SSA)");
	setMinimumSize(700, 525);
	setMaximumSize(2560, 1440); // Taille maximal des ecrans chez Danick :p
    resize(largeur, hauteur);
}

// "Setteurs" -----------------------------------------------------------------
void Fenetre::setLargeur(int largeur)
{
    this->largeur = largeur;    // "Set" la largeur de la fenetre
}

void Fenetre::setHauteur(int hauteur)
{
    this->hauteur = hauteur;    // "Set" la hauteur de la fenetre
}

// "Getteurs" -----------------------------------------------------------------
int Fenetre::getLargeur(void)
{
    return largeur;             // Retourne la largeur de la fenetre
}

int Fenetre::getHauteur(void)
{
    return hauteur;             // Retourne la hauteur de la fenetre
}

void Fenetre::changerDimensions(void)
{
    resize(largeur, hauteur);   // Redimensionne la fenetre
}