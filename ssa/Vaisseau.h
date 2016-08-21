/**
*	 @author Team SSA_P16
*	 @date Mars-2016
*	 @version 0.1
*	 @brief Définition de la classe Vaisseau. Décris tout les objets qui intéragisse avec
*	 l'environnement ( Joueur, ennemie, allié, npc etc.)
*/

#ifndef VAISSEAU_H
#define VAISSEAU_H

//#include <QGraphicsRectItem>
/**
*	 @author Team SSA_P16
*	 @date Avril-2016
*	 @version 1.6
*	 @name Vaisseau.h
*	 @brief Définition de la classe vaisseau
*/ 

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>

/**
 * @brief Classe de gestion d'un Vaisseau
 * @details Un Vaisseau est un object graphique qui 
 * 			peut se déplacer dans l'aire de jeu.
 * 			La gestion des touches et des niveaux d'armes des déplacements 
 * 			et l'apparition des ennemis est contrôlé par le vaisseau
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