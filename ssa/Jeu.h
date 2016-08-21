/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Jeu.h
*    @brief Définition de la classe Jeu
*/
#ifndef JEU_H
#define JEU_H

#include <QGridLayout>
#include <QTime>
#include <QTimer>
#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QMessagebox>
#include <QMediaPlayer>
#include <Qmediaplaylist>
#include <Qstackedwidget>
#include <QFile>
#include <QInputDialog>
#include <QTextStream>
#include <QPushButton>
#include <QString>

#include "Vaisseau.h"
#include "Joueur.h"
#include "Score.h"
#include "Health.h"
#include "Experience.h"
#include "Ennemi.h"
#include "Communication.h"
#include "Items.h"

#define GAME_WIDTH 500
#define GAME_HEIGHT 500
#define DAMAGE 10
#define SCORE_BOOST 10


/**
 * @brief Classe de gestion de la logique et des éléments du jeu
 * @details Cette classe contient tous les éléments graphiques et logiques 
 			qui permette au jeu de se dérouler.
 * 
 */

class Jeu : public QWidget {
	Q_OBJECT
private:
	QStackedWidget* parent;
	QGridLayout *mainLayout;
	QGridLayout *infoLayout;

	QGraphicsScene *gameScene;
	QGraphicsScene *infoScene; 

	QGraphicsView *gameView;
	QGraphicsView *infoView;

	QMetaObject::Connection connectionEnnemi;
	QMetaObject::Connection connectionUpdate;

	QFile * fichierScore;
	Joueur * joueur;
	Score * scoreJoueur;
	Health * vieJoueur;
	Experience * xpJoueur;
	QGraphicsTextItem * strNiveau;
	QGraphicsTextItem * strTime;
	Communication* fpga;
	QTime* gameTime;
	QMediaPlayer* music;
	QMediaPlaylist* list;
	QPushButton* boutonRetour;
	bool isFirstTime;
	bool GameIsOver;


	QTimer* ennemiTimer;
	QTimer* fpgaTimer;
	QTimer* secondsTimer;
	QTimer* updateTick;

public:
	Jeu(QStackedWidget* p_Parent);
	void demarrerJeu();
	void ajouterElement();
	Joueur* getJoueur();
	Score* getScore();
	Health* getHealth();
	Experience* getExp();
	void gameOver();
public slots:
	void endGame();
	void setDifficulty(int newlevel);
	void readFpga();
	void incSeconds();
	void retour();
	void update();
signals:
	void phonLeft();
	void phonRight();
	void phonShoot();
	void retourMenu();
};
#endif