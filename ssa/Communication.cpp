/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Communication.h
*    @brief Implémentation de la classe Communication
*/

/**
* @brief Communication, classe de gestion de la communication FPGA
* @details Permet de lire le registre1 et le registre des boutons du Basys2
*/

#include "Communication.h"

#include <qdebug.h>

Communication::Communication()
{
	donrx = 0;
	statuttrame = 0;
	statutport = 0;
	dontx = 0;
	trame[32] = { 0 };
	adresse_dans_Trame = 0;
	valeur_bouton = 0;
	bouton[4] = { 0 };
}

Communication::~Communication()
{
	port.~CommunicationFPGA();
	// Destructeur non implemente
}

void Communication::lireRegistre(int registre)
{
	for (adresse_dans_Trame = 0; adresse_dans_Trame < 8; adresse_dans_Trame++)
	{
		statutport = port.lireRegistre(registre, trame[adresse_dans_Trame]);      // lecture contenu de cette adresse
	}
}

void Communication::ecrireRegistre()
{
	// Fonction non implementee
}

void Communication::afficherRegistre()
{
	std::cout << std::endl << "Affichage de la trame recue ..." << std::endl;
	for (adresse_dans_Trame = 0; adresse_dans_Trame < 8; adresse_dans_Trame++)
	{
		std::cout << adresse_dans_Trame << ": " << trame[adresse_dans_Trame] << " /" << std::endl;
	}
}

void Communication::afficherMessageErreur()
{
	std::cout << port.messageErreur() << std::endl;
}

bool Communication::estOk()
{
	if (port.estOk())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
* @brief Lecture des boutons
* @details Lecture du registre de boutons du Basys2, une valeur 1 indique un bouton appuyé

* @param numero la position du bouton à lire (entre 0 et 3)
* @return true pour bouton appuyé false sinon
*/
int Communication::lireBouton()
{
	int masque = 1;
	port.lireRegistre(BTN, valeur_bouton);


	if (port.estOk()) //La connection est existante
	{
		if (valeur_bouton != 15) //On est pas en état initial
		{
			qDebug() << "Valeur FPGA : " << QString::number(valeur_bouton);
			return valeur_bouton;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		qDebug() << "Fpga non connecté";
		return 0;
	}


}

void Communication::afficherBoutons()
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << bouton[i] << std::endl;
	}

}