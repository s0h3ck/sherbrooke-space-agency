/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Health.cpp
*    @brief Implémentation des méthodes de la classe Health
*/

#include "Health.h"
#define VIE_MAX 400
Health::Health() {
	setObjectName("barVie");
	pointVie = VIE_MAX;
	setMinimum(0);
	setMaximum(VIE_MAX);
	setMaximumWidth(180);
	setFormat("Vie");
	setFont(QFont("Arial", 16));
	setTextVisible(true);
	setAlignment(Qt::AlignCenter);
	setValue(pointVie);
	setStyleSheet("QProgressBar#barVie {background-color: transparent; color: yellow; border: 1px solid yellow; border-radius: 5px;} QProgressBar#barVie::chunk{background-color: green; border-radius: 5px;} ");
}



void Health::removeHealth(int p_inc) {
	pointVie -= p_inc;
	setValue(pointVie);

	
	if (pointVie < 6 * VIE_MAX / 10)
	{
		setStyleSheet("QProgressBar#barVie {background-color: transparent; color: yellow; border: 1px solid yellow; border-radius: 5px;} QProgressBar#barVie::chunk{background-color: orange; border-radius: 5px;} ");
	}
	if (pointVie < VIE_MAX / 4)
	{
		setStyleSheet("QProgressBar#barVie {background-color: transparent; color: yellow; border: 1px solid yellow; border-radius: 5px;} QProgressBar#barVie::chunk{background-color: red; border-radius: 5px;} ");
	}
	

	repaint();
	if (pointVie <= 0)
	{
		emit estDetruit();
	}
}

void Health::addHealth(int p_inc) {
	pointVie += p_inc;
	if (pointVie > VIE_MAX)
		pointVie = VIE_MAX;
	setValue(pointVie);
	repaint();
}

void Health::resetHealth()
{
	pointVie = VIE_MAX;
	setValue(pointVie);
	setStyleSheet("QProgressBar#barVie {background-color: transparent; color: yellow; border: 1px solid yellow; border-radius: 5px;} QProgressBar#barVie::chunk{background-color: green; border-radius: 5px;} ");
	repaint();
}


int Health::getHealth() {
	return pointVie;
}