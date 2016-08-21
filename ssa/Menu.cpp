/**
*    @author Team SSA_P16
*    @date Avril-2016
*    @version 1.6
*    @name Menu.cpp
*    @brief Implémentation des méthodes de la classe Menu
*/ 

#include "Menu.h"

Menu::Menu(QWidget*)
{
    // Creation du menu
    creerMenu();
}

Menu::~Menu()
{
    delete titre;               // Suppression du titre
    delete boutonJouer;         // Suppression du bouton Jouer
    delete boutonScore;         // Suppression du bouton Score
	delete boutonAPropos;       // Suppression du bouton Options
    delete boutonQuitter;       // Suppression du bouton Quitter
}

QWidget* Menu::getMenu()
{
    return menu;
}

void Menu::creerMenu()
{
    creerTitre();               // Titre              
    creerBoutonsMenu();         // Boutons du menu

    creerWidgetMenu();          // Cree le widget du menu    

	aProposWidget = new APropos(this);

	setObjectName("bg");
	setStyleSheet("#bg {background-image: url(:images/space.png);}");
	

	//Créer les widget
	jeuWidget = new Jeu(this);
	commentWidget = new CommentJouer(this);
	scoreWidget = new TableauBord(this);
    // Ajout des widgets dans QStackedWidget
    addWidget(menu);          

	addWidget(jeuWidget);
	addWidget(commentWidget);
    addWidget(scoreWidget);
    addWidget(aProposWidget);

    setCurrentWidget(menu);
}

void Menu::creerTitre()
{
	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
	//effect->offset(2.0,2.0);
	effect->setBlurRadius(10);

	

	titre = new QLabel("Sherbrooke Space Agency"); // Creer le titre du menu
	titre->setStyleSheet("font-size: 50px; font-style: bold; font-family: Impact; color: yellow; ");
	titre->setGraphicsEffect(effect);
}

void Menu::creerBoutonsMenu()
{
	// Menu Jouer
	boutonJouer = new QPushButton("Jouer", this);
	boutonJouer->setShortcut(QKeySequence::New);
	boutonJouer->setObjectName("boutonJouer");
	boutonJouer->setMinimumHeight(50);
	boutonJouer->setMaximumWidth(200);
	QString styleSheetBoutonJ = "QPushButton#boutonJouer {margin-top: 30px; border: 1px solid yellow; font-size: 18px; color: yellow; height: 58px; width: 190px; text-align: center; } QPushButton#boutonJouer:hover{border: 4px solid yellow; font-size: 20px;}";
	boutonJouer->setStyleSheet(styleSheetBoutonJ);
	// Menu Pointage
	boutonScore = new QPushButton("Pointage", this);
	boutonJouer->setShortcut(QKeySequence::Find);
	boutonScore->setObjectName("boutonPointage");
	boutonScore->setMinimumHeight(50);
	boutonScore->setMaximumWidth(200);
	QString styleSheetBoutonP = "QPushButton#boutonPointage {margin-top: 15px; border: 1px solid yellow; font-size: 18px; color: yellow; height: 58px; width: 190px; text-align: center;}QPushButton#boutonPointage:hover {border: 4px solid yellow; font-size: 20px;}";
	boutonScore->setStyleSheet(styleSheetBoutonP);
	// Menu Comment Jouer
	boutonCJouer = new QPushButton("Comment jouer?", this);
	boutonCJouer->setShortcut(QKeySequence::Find);
	boutonCJouer->setObjectName("boutonCJouer");
	boutonCJouer->setMinimumHeight(50);
	boutonCJouer->setMaximumWidth(200);
	boutonCJouer->setStyleSheet("QPushButton#boutonCJouer {margin-top: 15px; border: 1px solid yellow; font-size: 18px; color: yellow; height: 58px; width: 190px; text-align: center;}QPushButton#boutonCJouer:hover {border: 4px solid yellow; font-size: 20px;}");
	// Menu A Propos
	boutonAPropos = new QPushButton(QStringLiteral("À propos"), this);
	boutonAPropos->setShortcut(QKeySequence::Find);
	boutonAPropos->setObjectName("boutonAPropos");
	boutonAPropos->setMinimumHeight(50);
	boutonAPropos->setMaximumWidth(200);
	boutonAPropos->setStyleSheet("QPushButton#boutonAPropos {margin-top: 15px; border: 1px solid yellow; font-size: 18px; color: yellow; height: 58px; width: 190px; text-align: center;}QPushButton#boutonAPropos:hover {border: 4px solid yellow; font-size: 20px;}");

	// Menu Quitter
	boutonQuitter = new QPushButton("Quitter", this);
	boutonQuitter->setShortcut(QKeySequence::Close);
	boutonQuitter->setObjectName("boutonQuitter");
	boutonQuitter->setStatusTip(tr("Quitter le jeu"));
	boutonQuitter->setMinimumHeight(50);
	boutonQuitter->setMaximumWidth(200);
	boutonQuitter->setStyleSheet("QPushButton#boutonQuitter {margin-top: 15px; border: 1px solid yellow; font-size: 18px; color: yellow; height: 58px; width: 190px; text-align: center;}QPushButton#boutonQuitter:hover {border: 4px solid yellow; font-size: 20px;}");
	// Connect signal-slots
	connect(boutonJouer, SIGNAL(released()), this, SLOT(jouer()));
	connect(boutonCJouer, SIGNAL(released()), this, SLOT(commentJouer()));
	connect(boutonScore, SIGNAL(released()), this, SLOT(score()));
	connect(boutonAPropos, SIGNAL(released()), this, SLOT(aPropos()));
	connect(boutonQuitter, SIGNAL(released()), this, SLOT(quitter()));
}

void Menu::creerWidgetMenu()
{
	menu = new QWidget;
	layoutMenu = new QVBoxLayout;
	layoutMenu->addWidget(titre);
	layoutMenu->addWidget(boutonJouer);
	layoutMenu->addWidget(boutonCJouer);
	layoutMenu->addWidget(boutonScore);
	layoutMenu->addWidget(boutonAPropos);
	layoutMenu->addWidget(boutonQuitter);
	layoutMenu->setAlignment(Qt::AlignCenter);
	layoutMenu->setAlignment(boutonJouer, Qt::AlignCenter);
	layoutMenu->setAlignment(boutonCJouer, Qt::AlignCenter);
	layoutMenu->setAlignment(boutonScore, Qt::AlignCenter);
	layoutMenu->setAlignment(boutonAPropos, Qt::AlignCenter);
	layoutMenu->setAlignment(boutonQuitter, Qt::AlignCenter);
	menu->setLayout(layoutMenu);
}


// "Slots" --------------------------------------------------------------------
void Menu::jouer()
{
    qDebug() << "Jouer";
    setCurrentWidget(jeuWidget);
	jeuWidget->ajouterElement();
	jeuWidget->demarrerJeu();
}

void Menu::commentJouer()
{
    qDebug() << "Comment jouer?";
    setCurrentWidget(commentWidget);
}

void Menu::score()
{
	qDebug() << "Score";
	scoreWidget->readFile();
	setCurrentWidget(scoreWidget);
}

void Menu::aPropos()
{
    qDebug() << "A Propos";
    setCurrentWidget(aProposWidget);
}

void Menu::quitter()
{
    qDebug() << "Quitter";
    exit(0);
}

void Menu::retour()
{
    setCurrentWidget(menu);
}