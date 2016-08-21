/**
*	 @author Team SSA_P16
*	 @date Avril-2016
*	 @version 1.6
*	 @name Score.h
*	 @brief Définition de la classe Score
*/ 
#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
/**
 * @brief Classe de gestion du score du joueur
 * @details Permet d'incrémenter le score 
 * 			et de le réinitialiser 
 * 			À implémenter:
 * 			-Enregistrement du score dans un fichier
 */		
class Score : public QGraphicsTextItem {
public:
	Score();
	void augmenterScore(int p_inc);
	void resetScore();
	int getScore();
private:
	int score;
};

#endif //SCORE_H