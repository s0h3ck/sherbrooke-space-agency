/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name CommentJouer.h
*    @brief D�finition de la classe ComentJouer
*/
#ifndef COMMENTJOUER_H
#define COMMENTJOUER_H
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QStackedWidget>
#include <QLabel>
/**
* @brief Classe de gestion des options
* @details � impl�menter, options � venir
*          -Volume
*          -Nom du joueur
*          -Difficult� de d�part
*/
class CommentJouer : public QWidget
{
	Q_OBJECT
public:
	CommentJouer(QStackedWidget *parent = 0);   // Constructeur
	~CommentJouer();                     // Destructeur
private slots:
	void retour();
private:
	QGridLayout * layout;           //
	QPushButton * bouton;           // Bouton back
	QStackedWidget * parent;
signals:
	void retourAuMenu();
};
#endif//CommentJouer_H