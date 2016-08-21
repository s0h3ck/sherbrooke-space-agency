/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Experience.cpp
*    @brief Implémentation des méthodes de la classe Experience
*/
#include "Experience.h"
#include <QDebug>
Experience::Experience()
{
	experiencePoint = 0;
	maximum = 10;
	setObjectName("barXP");
	setMinimum(0);
	setMaximum(maximum);
	setMaximumWidth(180);
	setFormat("Xp");
	setFont(QFont("Arial", 16));
	setTextVisible(true);
	setAlignment(Qt::AlignCenter);	
	setValue(experiencePoint);
	setStyleSheet("QProgressBar#barXP {background-color: transparent; color: yellow; border: 1px solid yellow; border-radius: 5px;} QProgressBar#barXP::chunk{color: black; background-color: blue; border-radius: 5px;}");

}

void Experience::addXp() 
{
	experiencePoint += 2;
	setValue(experiencePoint);
	qDebug() << " Lev :" << maximum;
	qDebug() << " Exp :" << experiencePoint;

	if (experiencePoint <= maximum/2 )
	{
		setStyleSheet("QProgressBar#barXP {background-color: transparent; color: yellow; border: 1px solid yellow; border-radius: 5px;} QProgressBar#barXP::chunk{color: black; background-color: blue; border-radius: 5px;}");
	}
	else
	{
		setStyleSheet("QProgressBar#barXP {background-color: transparent; color: yellow; border: 1px solid yellow; border-radius: 5px;} QProgressBar#barXP::chunk{color: white; background-color: blue; border-radius: 5px;}");
	}

	repaint();

	if (experiencePoint >= maximum)
	{
		setMinimum(0);
		experiencePoint = 0;
		setValue(0); 	setStyleSheet("QProgressBar#barXP {background-color: transparent; color: yellow; border: 1px solid yellow; border-radius: 5px;} QProgressBar#barXP::chunk{color: black; background-color: blue; border-radius: 5px;}");
		maximum = calculatemaximum();
		emit newLevel();
		setMaximum(maximum);
	}
}

int Experience::getExperiencePoint()
{
	return experiencePoint;
}

int Experience::calculatemaximum() 
{
	return maximum * 2;
}

void Experience::resetXp()
{
	setStyleSheet("QProgressBar#barXP {background-color: transparent; color: yellow; border: 1px solid yellow; border-radius: 5px;} QProgressBar#barXP::chunk{color: black; background-color: blue; border-radius: 5px;}");
	experiencePoint = 0;
	maximum = 10;
	setMinimum(0);
	setMaximum(maximum);
	setValue(experiencePoint);
	repaint();
}