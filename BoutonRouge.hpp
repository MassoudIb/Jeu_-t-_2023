/*
  Description : Le fichier header qui défini la classe BoutonRouge.

  Fichier:      BoutonRouge.hpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#pragma once
#include "ObjetInteractif.hpp"

class CarteDuMonde;

class BoutonRouge: public ObjetInteractif 
{
public:
	BoutonRouge():
		ObjetInteractif("bouton rouge", "Un bouton rouge permettant d'avoir accès à la salle R à l'est du couloir !") 
	{}

	string getDescription() const override { return description_; }
	void setDescription(const string& description) override { description_ = description; }
	string getNom() const override { return nom_; }
	void faireAction(CarteDuMonde& carte, Salle* salleCourante) override;
};