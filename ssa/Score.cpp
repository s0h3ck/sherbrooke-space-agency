/**
*	 @author Team SSA_P16
*	 @date Avril-2016
*	 @version 1.6
*	 @name Score.cpp
*	 @brief implémentation des méthodes de la classe Score
*/ 
#include "Score.h"
#include <QFont>

Score::Score() : QGraphicsTextItem() {
	//Score initial 0
	score = 0;
	//Dessiner le texte
	setPlainText(QString("Score: ")+ QString::number(score));
	setDefaultTextColor(Qt::yellow);
	setPos(0, 20);
	setFont(QFont("Arial", 16));
}

void Score::augmenterScore(int p_inc){
	score += p_inc;
	setPlainText(QString("Score: ") + QString::number(score));
}

void Score::resetScore() 
{
	score = 0;
	setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
	return score;
}