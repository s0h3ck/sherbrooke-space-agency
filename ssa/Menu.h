/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Menu.h
*    @brief Définition de la classe Menu
*/ 

#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QAction>
#include<QGraphicsDropShadowEffect>

// Pour le debogage
#include <QDebug>

#include "Jeu.h"
#include "CommentJouer.h"
#include "APropos.h"
#include "TableauBord.h"

/**
 * @brief Classe de gestion du menu
 * @details Contient un QStackedWidget avec 
            avec tous les QWidgets à afficher.
            Les méthodes et signals permettent de choisir 
            le widget à afficher.
 */
class Menu : public QStackedWidget
{
    Q_OBJECT

	public:
        Menu(QWidget *parent = 0);  // Constructeur
		~Menu();                    // Destructeur

        QWidget* getMenu();         // Retourne le menu
    
    private slots:
        void jouer();               // Fente jouer
        void commentJouer();        // Fente comment jouer
        void score();               // Fente score
        void aPropos();             // Fente options
        void quitter();             // Fente quitter
        void retour();              // Retour fenetre menu

	private:
        void creerMenu();           // Creer le menu
        void creerWidgetMenu();     // Creer la gestion des layouts
        void creerTitre();          // Creer titre
        void creerBoutonsMenu();    // Creer les boutons

        QWidget * menu;             // Widget du menu
        QVBoxLayout * layoutMenu;   // Layout du menu
        Jeu * jeuWidget;			// Widget du jeu
		CommentJouer * commentWidget;	//Widget de l'aide
		APropos * aProposWidget;    // Widget Options
		TableauBord *scoreWidget;

        QLabel * titre;             // Titre du jeu

		QPushButton * boutonJouer;  // Bouton Jouer
        QPushButton * boutonCJouer; // Bouton CommentJouer
        QPushButton * boutonScore;  // Bouton Score
        QPushButton * boutonAPropos;// Bouton Options
        QPushButton * boutonQuitter;// Bouton Quitter
};

#endif //MENU_H