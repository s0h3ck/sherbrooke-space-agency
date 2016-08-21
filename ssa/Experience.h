/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Experience.h
*    @brief Définition de la classe Experience
*/
#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <QProgressBar>

/**
 * @brief classe de gestion des points d'expériences
 * @details L'xp permet au joueur de changer de niveau
 * 			et au jeu d'augmenter la difficulté
 */
class Experience : public QProgressBar {
	Q_OBJECT
private:
	int experiencePoint;
	int level;
	int maximum;
	int calculatemaximum();
public:
	Experience();
	void addXp();
	int getExperiencePoint();
	void resetXp();
signals:
	void newLevel();
};

#endif