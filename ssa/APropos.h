/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Options.h
*    @brief Définition de la classe Options
*/ 
#ifndef APROPOS_H
#define APROPOS_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

#include <QStackedWidget>

/**
 * @brief Classe du menu A Propos
 * @details À implémenter, options à venir
 *          -Volume
 *          -Nom du joueur
 *          -Difficulté de départ
 */
class APropos : public QWidget
{
    Q_OBJECT

    public:
        APropos(QStackedWidget *parent = 0);   // Constructeur
        ~APropos();                     // Destructeur
	
	private slots:
        void retour();
    
    private:
        QGridLayout * layout;           //
        QPushButton * bouton;			// Bouton back
        QStackedWidget * parent;

    signals:
        void retourAuMenu();
};

#endif//OPTIONS_H