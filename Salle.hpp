/*
  Description : Le fichier header qui permet de définir la classe Salle.

  Fichier:      Salle.hpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

#include "Direction.hpp";
#include "Couleur.hpp"

class ObjetInteractif;

using namespace std;

class Salle
{
public:
	Salle(const string& nom, const string& description, bool etatLumiere = false):
		nom_(nom), 
		description_(description),
		etatLumiere_(etatLumiere)
	{}
	~Salle() = default;

	string getNom() { return nom_; };
	string getDescription() { return description_; }
	string getDescriptionEtat();
	void setDescription(const string& description) { description_ = description; }
	Direction getDirection() const { return direction_; }
	void ajouterConnection(shared_ptr<Salle> salle, Direction direction);
	vector<shared_ptr<Salle>>& getSallesConnectees();
	bool possedeConnection(shared_ptr<Salle> salle) const;
	shared_ptr<Salle> getSalleVoisineEnDirection(Direction direction);
	void getNomSallesVoisines();

	void ajouterObjetInteractif(shared_ptr<ObjetInteractif> objet);
	vector<shared_ptr<ObjetInteractif>> getObjetsInteractifs() const { return objetsInteractifs_; };
	ObjetInteractif* getObjetInteractif(const string& nomObjet) const;
	bool possedeObjetInteractif(const string& nomObjet) const;

	bool estAccessible() { return accessible_; }
	void setAccessible(bool valeur) { accessible_ = valeur; }

	bool getEtatLumiere() const { return etatLumiere_; }
	void setEtatLumiere(bool etat) { etatLumiere_ = etat; }
	
	string changerCouleur(Couleur couleur) 
	{										
		switch (couleur)
		{
		case Couleur::BLANC:
			return "\033[1;97m";
			break;
		case Couleur::VERT:
			return "\033[1;92m";
			break;
		case Couleur::CYAN:
			return "\033[1;96m";
			break;
		case Couleur::JAUNE:
			return "\033[38;5;226m";
			break;
		case Couleur::ROUGE:
			return "\033[1;91m";
			break;
		case Couleur::BLEU:
			return "\033[1;94m";
			break;
		case Couleur::ORANGE:
			return "\033[38;5;214m";
			break;
		case Couleur::ROSE:
			return "\033[38;5;213m";
			break;
		case Couleur::MAUVE:
			return "\033[38;5;128m";
			break;
		}
	}

private:
	string nom_;
	string description_;
	Direction direction_;
	unordered_map<Direction, vector<shared_ptr<Salle>>> connections_;
	vector<shared_ptr<ObjetInteractif>> objetsInteractifs_;
	bool accessible_;
	bool etatLumiere_;
};