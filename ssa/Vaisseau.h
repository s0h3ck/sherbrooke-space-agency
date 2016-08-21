/**
*	 @author Team SSA_P16
*	 @date Mars-2016
*	 @version 0.1
*	 @brief D�finition de la classe Vaisseau. D�cris tout les objets qui int�ragisse avec
*	 l'environnement ( Joueur, ennemie, alli�, npc etc.)
*/

#ifndef VAISSEAU_H
#define VAISSEAU_H

//#include <QGraphicsRectItem>
/**
*	 @author Team SSA_P16
*	 @date Avril-2016
*	 @version 1.6
*	 @name Vaisseau.h
*	 @brief D�finition de la classe vaisseau
*/ 

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>

/**
 * @brief Classe de gestion d'un Vaisseau
 * @details Un Vaisseau est un object graphique qui 
 * 			peut se d�placer dans l'aire de jeu.
 * 			La gestion des touches et des niveaux d'armes des d�placements 
 * 			et l'apparition des ennemis est contr�l� par le vaisseau
 */
class Vaisseau : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

private:
	int weaponLevel;
public:
	Vaisseau();
	void keyPressEvent(QKeyEvent *eventKey);
	void TirerProjectile();
	void WeaponUp();
	void WeaponDown();
	int getWeaponLevel(); 
public slots:
	void spawn();
	void moveLeft();
	void moveRight();
	void tirer();
signals:
	void keyLeft();
	void keyRight();
	void keyShoot();
};

#endif