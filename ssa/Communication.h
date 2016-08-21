/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Communication.h
*    @brief Définition de la classe Communication
*/

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <iostream>
#include "CommunicationFPGA.h"

#define NREG_LECT1 0 // fpga -> PC   // donnee de trame
#define NREG_LECT2 2 // fpga -> PC   // STATUT du décodeur manchester
#define NREG_ECRI  3 // pc -> fpga   // adresse dans le tampon de trame 

class Communication
{
public:
	Communication();
	~Communication();

	void lireRegistre(int registre);
	void ecrireRegistre();
	void afficherRegistre();
	void afficherMessageErreur();
	bool estOk();


	int lireBouton();
	void afficherBoutons();

private:
	int donrx;
	int statuttrame;
	bool statutport;
	int dontx;
	int trame[32];
	int adresse_dans_Trame;

	CommunicationFPGA port;

	int valeur_bouton;
	int bouton[4];

};

#endif//COMMUNICATION_H