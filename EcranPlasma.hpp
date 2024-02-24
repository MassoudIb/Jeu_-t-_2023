/*
  Description : Le fichier header qui d�fini la classe EcranPlasma.

  Fichier:      EcranPlasma.hpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#pragma once
#include "ObjetInteractif.hpp"

class CarteDuMonde;

class EcranPlasma : public ObjetInteractif
{
public:
	EcranPlasma() :
		ObjetInteractif("ecran plasma", "C'est un �cran de cin�ma de qualit�.")
	{}

	string getDescription() const override { return description_; }
	void setDescription(const string& description) override { description_ = description; }
	string getNom() const override { return nom_; }
	void faireAction(CarteDuMonde& carte, Salle* salleCourante) override
	{
		cout << salleCourante->changerCouleur(Couleur::BLEU) +
			"Vous d�marrez l'�cran et appr�cier le film James Bond!\n" +
			salleCourante->changerCouleur(Couleur::BLANC);
	}
};