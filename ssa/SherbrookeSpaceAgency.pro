TEMPLATE     = vcapp
TARGET       = main
CONFIG      += warn_on qt debug_and_release windows
HEADERS     += CommentJouer.h\
               Communication.h\
               CommunicationFPGA.h\
			   Ennemi.h\
			   Experience.h\
			   Fenetre.h\
			   Health.h\
			   Items.h\
			   Jeu.h\
			   Joueur.h\
			   Menu.h\
			   APropos.h\
			   Projectile.h\
			   ProjectileEnnemi.h\
			   Score.h\
			   TableauBord.h\
			   Vaisseau.h
SOURCES     += main.cpp\
               CommentJouer.cpp\
               Communication.cpp\
			   Ennemi.cpp\
			   Experience.cpp\
			   Fenetre.cpp\
			   Health.cpp\
			   Items.cpp\
			   Jeu.cpp\
			   Joueur.cpp\
			   Menu.cpp\
			   APropos.cpp\
			   Projectile.cpp\
			   ProjectileEnnemi.cpp\
			   Score.cpp\
			   TableauBord.cpp\
			   Vaisseau.cpp
INCLUDEPATH += 
LIBS	    += CommunicationFPGA.lib
QT += widgets multimedia
RESOURCES += ssaresource.qrc
RC_ICONS = iconSSA.ico