/*
  Description : Le fichier header qui défini la classe SuperOrdinateur.

  Fichier:      SuperOrdinateur.hpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/

#pragma once
#include "ObjetInteractif.hpp"

class CarteDuMonde;

class SuperOrdinateur : public ObjetInteractif
{
public:
	SuperOrdinateur() :
		ObjetInteractif("super ordinateur Intel i12", "C'est un ordinateur super sonic de jeux!")
	{}

	string getDescription() const override { return description_; }
	void setDescription(const string& description) override { description_ = description; }
	string getNom() const override { return nom_; }
	void faireAction(CarteDuMonde& carte, Salle* salleCourante) override
	{
		cout << salleCourante->changerCouleur(Couleur::BLEU) +
			"Vous démarrez l'ordi et apprécier le jeu Need For Speed !!!!!\n" +
			salleCourante->changerCouleur(Couleur::BLANC);
	}
};
