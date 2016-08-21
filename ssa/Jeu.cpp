/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Jeu.cpp
*    @brief Implémentation des méthodes de la classe Jeu
*/

#include "Jeu.h"	
#include <qthread.h>

Jeu::Jeu(QStackedWidget* p_Parent)
{
	//Création des items nécessaire
	//Layout
	parent = nullptr;
	mainLayout = new QGridLayout();
	infoLayout = new QGridLayout();
	//Scenes
	gameScene = new QGraphicsScene();
	infoScene = new QGraphicsScene();
	//Views
	gameView = new QGraphicsView();
    infoView = new QGraphicsView();

	//Gameplay Elements
	fichierScore = new QFile("Score.txt");
	joueur= new Joueur();
	scoreJoueur = new Score();
	vieJoueur = new Health();
	xpJoueur = new Experience();
	fpgaTimer = new QTimer();
	strNiveau = new QGraphicsTextItem();
	strTime = new QGraphicsTextItem();
	boutonRetour = new QPushButton("Fin Partie");
	fpga = new Communication();
	gameTime = new QTime(0,0,0);
	secondsTimer = new QTimer();
	ennemiTimer = new QTimer();
	updateTick = new QTimer();
	music = new QMediaPlayer;
	list = new QMediaPlaylist;
	GameIsOver = false;
	parent = p_Parent;
}

void Jeu::ajouterElement() 
{
	if (isFirstTime)
	{
		gameView->setStyleSheet("border: 2px solid yellow; border-radius: 4px;background-image: url(:images/spaceG.png);");
		infoView->setStyleSheet("background-color: transparent; border: 2px solid yellow; border-radius: 5px;");			
		//SetViews
		gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		gameView->setFixedSize(GAME_WIDTH, GAME_HEIGHT);
		infoView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		infoView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		infoView->setMaximumHeight(365);
		infoView->setMaximumWidth(180);
		//SetScenes
		gameScene->setSceneRect(0, 0, GAME_WIDTH, GAME_HEIGHT);
		infoScene->addItem(strNiveau);
		infoScene->addItem(strTime);
		strNiveau->setFont(QFont("Arial", 16));
		strNiveau->setPos(0, 0);
		strTime->setPlainText(gameTime->toString("mm:ss"));
		strTime->setDefaultTextColor(QColor(255, 255, 0));
		strTime->setFont(QFont("Arial", 16));
		strNiveau->setPos(0, 40);
		//Ajouter scoreJoueur a la scene
		infoScene->addItem(scoreJoueur);
		infoView->setScene(infoScene);	
		//Ajouter bouton retour
		boutonRetour->setMinimumHeight(10);
		boutonRetour->setMaximumWidth(180);
		boutonRetour->setObjectName("boutonRetour");
		QString styleSheetBoutonP = "QPushButton#boutonRetour {background-color: transparent; border: 2px solid yellow; font-size: 18px; color: yellow; padding: 6px; width: 150px; text-align: center; border-radius: 5px;}QPushButton#boutonRetour:hover {border: 4px solid yellow;font-size: 20px;}";
		boutonRetour->setStyleSheet(styleSheetBoutonP);
		connect(boutonRetour, SIGNAL(released()), this, SLOT(retour()));
		//InfoLayout ajouter le score et la barre d'experience
		infoLayout->addWidget(infoView, 1, 0);
		infoLayout->addWidget(vieJoueur, 2, 0);
		infoLayout->addWidget(xpJoueur, 3, 0);
		infoLayout->addWidget(boutonRetour, 0,0);
		//Ajouter la scene à la view
		gameView->setScene(gameScene);
		mainLayout->addWidget(gameView, 0, 0);
		mainLayout->addLayout(infoLayout, 0, 1);
		setLayout(mainLayout);
		show();
		//Demarrer musique
		list->setPlaybackMode(QMediaPlaylist::Loop);
		list->addMedia(QUrl("qrc:sound/bg.mp3"));
		list->setCurrentIndex(1);
		music->setPlaylist(list);
		music->play();
		music->setVolume(20);
	}
}

void Jeu::demarrerJeu() 
{
	if (!isFirstTime) //
	{
		//Gameplay Elements
		gameTime->setHMS(0, 0, 0);
		joueur = new Joueur();
		this->setEnabled(true);		
	}
	GameIsOver = false;
	music->play();
	secondsTimer->start(1000);
	//Ajouter un joueur à la scène	
	gameScene->addItem(joueur);
	joueur->setPos((gameView->width() / 2) - (joueur->pixmap().width() / 2), gameView->height() - joueur->pixmap().height() - 10);
	xpJoueur->resetXp();
	scoreJoueur->resetScore();
	vieJoueur->resetHealth();
	strNiveau->setPlainText("Niveau : " + QString::number(joueur->getLevel()));
	strNiveau->setDefaultTextColor(QColor(255, 255, 0));
	QObject::connect(secondsTimer, SIGNAL(timeout()), this ,SLOT(incSeconds()));
	QObject::connect(vieJoueur, SIGNAL(estDetruit()), this, SLOT(endGame()));
	QObject::connect(xpJoueur, SIGNAL(newLevel()), joueur, SLOT(addLevel()));
	connectionUpdate = QObject::connect(updateTick, SIGNAL(timeout()), this, SLOT(update()));
	//joueur focusable
	joueur->setFlag(QGraphicsItem::ItemIsFocusable);
	joueur->setFocus();
	infoView->setFocusPolicy(Qt::NoFocus);


	//Ajouter les ennemis	
	connectionEnnemi = QObject::connect(ennemiTimer, SIGNAL(timeout()), joueur, SLOT(spawn()));
	ennemiTimer->start(2000);
	QObject::connect(joueur, SIGNAL(changeDifficulty(int)), this, SLOT(setDifficulty(int)));
	//Controle à partir des phonemes
	QObject::connect(this, SIGNAL(phonLeft()), joueur, SLOT(moveLeft()));
	QObject::connect(this, SIGNAL(phonRight()), joueur, SLOT(moveRight()));
	QObject::connect(this, SIGNAL(phonShoot()), joueur, SLOT(tirer()));
	//Polling du fpga
	QObject::connect(fpgaTimer, SIGNAL(timeout()), this, SLOT(readFpga()));
	fpgaTimer->start(10);
	isFirstTime = false;
	updateTick->start(40);
}

Score* Jeu::getScore(){
	return scoreJoueur;
}

Health* Jeu::getHealth(){
	return vieJoueur;
}

Experience* Jeu::getExp() {
	return xpJoueur;
}

Joueur* Jeu::getJoueur() {
	return joueur;
}

void Jeu::gameOver()
{
	//Variables
	QString message;
	QMessageBox reply;
	QInputDialog * inputNom = new QInputDialog();
	QString nomDuJoueur = "";
	//Déconnection des signaux
	QObject::disconnect(connectionUpdate);
	QObject::disconnect(secondsTimer, SIGNAL(timeout()), this, SLOT(incSeconds()));
	QObject::disconnect(xpJoueur, SIGNAL(newLevel()), joueur, SLOT(addLevel()));
	QObject::disconnect(fpgaTimer, SIGNAL(timeout()), this, SLOT(readFpga()));
	//Connection du retor au menu
	QObject::connect(this, SIGNAL(retourMenu()), this->parent, SLOT(retour()));
	
	message = "Votre score : " + QString::number(scoreJoueur->getScore());

	this->setEnabled(false);
	gameScene->clear();
	if (scoreJoueur->getScore() != 0)
	{
		//Demander au joueur son nom
		nomDuJoueur = inputNom->getText(NULL, "Fin de la partie",
			"Votre Nom:", QLineEdit::Normal, "Joueur");

		if (nomDuJoueur.isEmpty())
		{
			nomDuJoueur = "Joueur";
		}
		//Ajouter à score.txt le score du joueur
		if (fichierScore->open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
		{
			QTextStream out(fichierScore);
			//out << nomDuJoueur << endl << QString::number(scoreJoueur->getScore()) << endl << gameTime->toString("mm:ss") << endl;
			if (fichierScore->pos() == 0)			//fichier vide
			{
				out << nomDuJoueur << endl << QString::number(scoreJoueur->getScore()) << endl << gameTime->toString("mm:ss");
			}
			else //fichier contient des donnees
			{
				out << endl << nomDuJoueur << endl << QString::number(scoreJoueur->getScore()) << endl << gameTime->toString("mm:ss");
			}
			fichierScore->close();
		}
	}
	
	//Demander au joueur si il veut recommencer
	reply.setWindowTitle(QStringLiteral("Réessayer?"));
	reply.setText(message);
	reply.setInformativeText(QStringLiteral("Réessayer?"));
	QAbstractButton *myYesButton = reply.addButton(trUtf8("Oui"), QMessageBox::YesRole);
	QAbstractButton *myNoButton = reply.addButton(trUtf8("Non"), QMessageBox::NoRole);
	reply.setIcon(QMessageBox::Question);
	reply.exec();
	//reply = QMessageBox::question(this,"Fin de la partie",message + "\nReessayer?",QMessageBox::Yes|QMessageBox::No);
	if (reply.clickedButton() == myYesButton)
	{
		ajouterElement();
		demarrerJeu();
	}
	else
	{
		music->stop();
		emit retourMenu();		
	}
}


void Jeu::setDifficulty(int newLevel)
{
	strNiveau->setPlainText("Niveau : " + QString::number(newLevel));
	if (2000 - 100 * newLevel > 500)
	{
		ennemiTimer->setInterval(2000 - (100*newLevel));
	}
	else
	{
		ennemiTimer->setInterval(500);
	}
}

void Jeu::readFpga()
{
	switch (fpga->lireBouton())
	{
	case 1:
		emit phonShoot();
		break;
	case 2:
		emit phonRight();
		break;
	case 8:
		emit phonLeft();
		break;
	default:
		break;
	}
}

void Jeu::incSeconds()
{
	*gameTime = gameTime->addSecs(1);
	strTime->setPlainText(gameTime->toString("mm:ss"));
}

void Jeu::retour()
{
	gameOver();
}

void Jeu::endGame()
{
	GameIsOver = true;
}

void Jeu::update()
{
	for (auto item : gameScene->items())  //Pour tous les items de la scene
	{
		if (GameIsOver)
		{
			break;
		}
		else if (Projectile *tempProj = dynamic_cast<Projectile*>(item))	//Si L'item est un projectile
		{
			if (tempProj->Move())
			{
				for (auto collider : tempProj->collidingItems())	//Pour tous les items qui contact le projectile
				{
					if (Ennemi *tempE = dynamic_cast<Ennemi*>(collider))	//Si l'item en contact est un ennemi
					{
						xpJoueur->addXp();
						scoreJoueur->augmenterScore(1);
						gameScene->removeItem(tempProj);
						tempE->diminuerVie();
					}
				}
			}
		}
		else if (ProjectileEnnemi *tempProjEnnemi = dynamic_cast<ProjectileEnnemi*>(item))	//Si l'item est un projectile ennemi
		{
			if (tempProjEnnemi->Move())
			{
				for (auto collider : tempProjEnnemi->collidingItems())
				{
					if (Joueur *tempPE = dynamic_cast<Joueur*>(collider))
					{
						gameScene->removeItem(tempProjEnnemi);
						joueur->WeaponDown();
						vieJoueur->removeHealth(DAMAGE);
					}
				}
			}
		}
		else if (Ennemi *tempEnnemi = dynamic_cast<Ennemi*>(item)) //si l'item est un ennemi
		{
			if (tempEnnemi->Move())
			{
				for (auto collider : tempEnnemi->collidingItems())	//pour les items en contact avec l'ennemi
				{
					if (Joueur *tempPE = dynamic_cast<Joueur*>(collider))	//si l'item en contact est le joueur 
					{		
						tempEnnemi->disconnect();
						gameScene->removeItem(tempEnnemi);
						//remove health from the player
						joueur->WeaponDown();
						vieJoueur->removeHealth(DAMAGE);
					}
				}
			}
		}
		else if (Items *tempItem = dynamic_cast<Items*>(item))	//si l'item est un Iems
		{
			if(tempItem->Move())
			{	
				for (auto collider : tempItem->collidingItems())	//Pour tous les items en contact
				{
					if (Joueur *tempPE = dynamic_cast<Joueur*>(collider))	//si l'item en contact est un Items
					{
						switch (tempItem->getType())
						{
						case HEALTH_BONUS:
							vieJoueur->addHealth(DAMAGE);
							break;
						case SCORE_BONUS:
							scoreJoueur->augmenterScore(SCORE_BOOST);
							break;
						case WEAPON_UP:
							joueur->WeaponUp();
							break;
						default:
							break;
						}
						gameScene->removeItem(tempItem);
					}
				}
			}
		}
	}

	if (GameIsOver)
	{
		gameOver();
	}
}