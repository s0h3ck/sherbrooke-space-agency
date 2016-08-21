/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Health.h
*    @brief Définition de la classe Health
*/

#ifndef HEALTH_H
#define HEALTH_H

#include <QProgressBar>
#include <QObject>
/**
 * @brief Class de gestion de la vie du joueur
 * @details Permet d'enlever ou redonner de la vie au joeur
 * 			Émet le signal estDetruit lorsque la vie tombe à 0
 */
class Health : public QProgressBar {
	Q_OBJECT
private:
	int pointVie;
public:
	Health();
	void removeHealth(int p_inc);
	void addHealth(int p_inc);
	int  getHealth();
	void resetHealth();
signals:
	void estDetruit();
};

#endif