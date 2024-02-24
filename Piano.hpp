/*
  Description : Le fichier header qui défini la classe Piano.

  Fichier:      Piano.hpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#pragma once
#include "ObjetInteractif.hpp"

class CarteDuMonde;

class Piano : public ObjetInteractif
{
public:
	Piano() :
		ObjetInteractif("vieux piano electrique", "C'est un piano noir Yamaha avec 69 clés des années 1990.")
	{}

	string getDescription() const override { return description_; }
	void setDescription(const string& description) override { description_ = description; }
	string getNom() const override { return nom_; }
	void faireAction(CarteDuMonde& carte, Salle* salleCourante) override
	{
		cout << salleCourante->changerCouleur(Couleur::BLEU) +
			"Vous jouez sur le piano! Il ne sonne pas très bien!\n" +
			salleCourante->changerCouleur(Couleur::BLANC);
	}
};