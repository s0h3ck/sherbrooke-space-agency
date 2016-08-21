/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name main.cpp
*    @brief Point d'entré du programme 
*/ 
#include <QtWidgets/QApplication>
#include <QgraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QTimer>

#include "Communication.h"
#include "Jeu.h"
#include "Vaisseau.h"
#include "Score.h"
#include "Health.h"
#include "Fenetre.h"

/**
 * @brief Point d'entré du programme
 * @details Affichage de la fenêtre qui contient l'application
 */

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);
	Fenetre* jeu = new Fenetre();
	jeu->show();
	return app.exec();
}