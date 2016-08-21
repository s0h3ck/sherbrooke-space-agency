#ifndef TABLEAUBORD_H
#define TABLEAUBORD_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QTableWidget>
#include <QIODevice>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QFile>
#include <QDebug>
#include <QList>
#include <QTime>
#include <QMessageBox>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


struct Row
{
	QString nom;
	unsigned int score;
	QTime temps;
};

class TableauBord : public QWidget
{
	Q_OBJECT
public:
	TableauBord(QStackedWidget *parent = 0);   // Constructeur
	~TableauBord();

	void readFile();

	private slots:
	void retour();
	void supprimerTableau();

private:
	QGridLayout * layout;           //
	QPushButton * boutonEffacer;
	QPushButton * boutonMenu;			// Bouton back
	QStackedWidget * parent;
	QTableWidget* table;
	QFile * file;

signals:
	void retourAuMenu();
};

#endif//TABLEAUBORD_H