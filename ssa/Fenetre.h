/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Fenetre.h
*    @brief Définition de la classe Fenetre
*/
#ifndef FENETRE_H
#define FENETRE_H

#include "Menu.h"

#include <QMainWindow>
#include <QWidget>

/**
 * @brief Classe de gestion de la fenêtre principal
 */
class Fenetre : public QMainWindow
{
	Q_OBJECT                            // Macro signal + slot

	public:
        Fenetre(QWidget *parent = 0);   // Constructeur
        ~Fenetre();                     // Destructeur

        void setLargeur(int largeur);   // Modifier la hauteur
        void setHauteur(int hauteur);   // Modifier la largeur
		
        int getLargeur(void);           // Obtenir la largeur
		int getHauteur(void);           // Obtenir la hauteur

        void changerDimensions(void);   // Changer les dimensions de la fenetre

    private slots:

	private:
		void creerMenu();               // Creer le menu
		void creerPeaufinage();         // Creer le peaufinage

		Menu * menu;                    // L'objet Menu

        int largeur;                    // largeur de la fenetre
		int hauteur;                    // hauteur de la fenetre
};

#endif //FENETRE_H