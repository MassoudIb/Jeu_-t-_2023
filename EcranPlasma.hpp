/*
  Description : Le fichier header qui défini la classe EcranPlasma.

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
		ObjetInteractif("ecran plasma", "C'est un écran de cinéma de qualité.")
	{}

	string getDescription() const override { return description_; }
	void setDescription(const string& description) override { description_ = description; }
	string getNom() const override { return nom_; }
	void faireAction(CarteDuMonde& carte, Salle* salleCourante) override
	{
		cout << salleCourante->changerCouleur(Couleur::BLEU) +
			"Vous démarrez l'écran et apprécier le film James Bond!\n" +
			salleCourante->changerCouleur(Couleur::BLANC);
	}
};