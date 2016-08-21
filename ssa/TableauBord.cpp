#include "TableauBord.h"
#include <QTableWidget>
#include <QLabel>
#include <QTextStream>

TableauBord::TableauBord(QStackedWidget *parent)
{
	table = new QTableWidget();
	layout = new QGridLayout;
	QLabel *titrePointage;
	titrePointage = new QLabel("Pointages");
	titrePointage->setStyleSheet("margin-bottom: 20px; font-size: 40px; font-style: bold; font-family: Impact; color: yellow;");

	boutonEffacer = new QPushButton("Effacer les pointages");
	boutonEffacer->setMinimumHeight(50);
	boutonEffacer->setMaximumWidth(200);
	boutonEffacer->setObjectName("boutonEffacer");
	boutonEffacer->setStyleSheet("QPushButton#boutonEffacer {margin-top: 20px; background-color: transparent; border: 2px solid yellow; font-size: 18px; color: yellow; height: 58px; width: 190px; text-align: center;}QPushButton#boutonEffacer:hover{border: 4px solid yellow; font-size: 20px;}");

	boutonMenu = new QPushButton("Retour au menu");
	boutonMenu->setMinimumHeight(50);
	boutonMenu->setMaximumWidth(200);
	boutonMenu->setObjectName("boutonRetour");
	boutonMenu->setStyleSheet("QPushButton#boutonRetour {margin-top: 20px; background-color: transparent; border: 2px solid yellow; font-size: 18px; color: yellow; height: 58px; width: 190px; text-align: center;}QPushButton#boutonRetour:hover{border: 4px solid yellow; font-size: 20px;}");
	
	layout->addWidget(titrePointage, 0, 0, 1, 2, Qt::AlignCenter);
	layout->addWidget(table, 1, 0, 1, 2);
	layout->addWidget(boutonEffacer, 2, 0, Qt::AlignCenter);
	layout->addWidget(boutonMenu, 2, 1, Qt::AlignCenter);
	setLayout(layout);

	this->parent = parent;
	connect(boutonEffacer, SIGNAL(released()), this, SLOT(supprimerTableau()));
	connect(boutonMenu, SIGNAL(released()), this, SLOT(retour()));
	connect(this, SIGNAL(retourAuMenu()), parent, SLOT(retour()));

	
}

#include <QHeaderView>

bool triage(const  Row & r1, const Row & r2);

void TableauBord::readFile()
{
	table->setColumnCount(3);
	table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	table->setHorizontalHeaderLabels(QString("NOM DU JOUEUR;POINTAGE;TEMPS").split(";"));
	table->setObjectName("Table");
	table->setStyleSheet("QTableWidget#Table {selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 1,stop: 0 black, stop: 1 transparent); background-color: white; color: black; border: 3px solid white;  border-radius: 5px;}");
	table->horizontalHeader()->setStretchLastSection(true);
	QHeaderView  * header = table->horizontalHeader();
	header->setSectionResizeMode(QHeaderView::Stretch);
	file = new QFile("Score.txt");
	if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
	{
		// si n'a pas de fichier, faire un qqch
	}

	Row r;
	std::vector<Row> v;

	QTextStream in(file);
	in.flush();
	QString line;
	QString nom, score, temps;
	int ligne = 0;

	while (!in.atEnd()) {
		//qDebug() << "Hello" << nom << score << temps;
		in >> nom;
		in >> score;
		in >> temps;

		ligne += 1;

		QTime time;
		r.nom = nom;
		r.score = score.toInt();
		r.temps = time.fromString(temps, "mm:ss");
		v.push_back(r);
	}

	std::sort(v.begin(), v.end(), triage);
	//qDebug() << "Ligne : " << ligne;
	//qDebug() << "count : " << table->rowCount();

	// Path ... beurK!
	int count = table->rowCount();
	if (count != 0)
	{
		for (int i =count; i >0; i--)
		{
			//qDebug() << "I : " << i;
			//qDebug() << "delete";
			table->removeRow(i);
		}
	}
	// --- Fin du path

	for (int i = 0; i < ligne; i++)
	{
		//qDebug() << "I : " << i;
		//qDebug() << "Est-ce que je suis ? ";
		table->insertRow(i);
		table->setItem(i, 0, new QTableWidgetItem(v.at(i).nom));
		table->item(i, 0)->setFlags(table->item(i, 0)->flags() & ~Qt::ItemIsEditable);
		table->setItem(i, 1, new QTableWidgetItem(QString::number(v.at(i).score)));
		table->item(i, 1)->setFlags(table->item(i, 0)->flags() & ~Qt::ItemIsEditable);
		//qDebug() << "Score : " << table->item(i, 1)->text();
		table->setItem(i, 2, new QTableWidgetItem(v.at(i).temps.toString()));
		table->item(i, 2)->setFlags(table->item(i, 0)->flags() & ~Qt::ItemIsEditable);
		//qDebug() << "R : " << v.at(i).nom << QString::number(v.at(i).score) << v.at(i).temps.toString();
		
	}
	table->removeRow(ligne);
	file->close();
}

bool triage(const Row & r1, const Row & r2)
{
	//qDebug() << "triage";
	if (r1.score == r2.score)
		return r1.temps < r2.temps;
	return r1.score > r2.score;
}

TableauBord::~TableauBord()
{
}


void TableauBord::retour()
{
	file->close();
	int count = table->rowCount();
	for (int i = 0; i < count; i++)
	{
		//qDebug() << "I : " << i;
		//qDebug() << "delete";
		table->removeRow(i);
	}
	emit retourAuMenu();
}

void TableauBord::supprimerTableau()
{
	//QMessageBox::StandardButton reply;
	//reply = QMessageBox::question(this, "Suppression des pointages", "Voulez-vous vraiment supprimer les pointages?", QMessageBox::Yes | QMessageBox::No);
	QMessageBox reply;
	reply.setWindowTitle("Suppression des pointages");
	reply.setText("Voulez-vous vraiment supprimer les pointages?");
	QAbstractButton *myYesButton = reply.addButton(trUtf8("Oui"), QMessageBox::YesRole);
	QAbstractButton *myNoButton = reply.addButton(trUtf8("Non"), QMessageBox::NoRole);
	reply.setIcon(QMessageBox::Question);
	reply.exec();
	
	if (reply.clickedButton() == myYesButton)
	{
		file->open(QIODevice::ReadWrite | QFile::Truncate | QFile::Text);
		file->close();
		readFile();
	}
}