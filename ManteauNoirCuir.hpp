/*
  Description : Le fichier header qui défini la classe ManteauNoirCuir.

  Fichier:      ManteauNoirCuir.hpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#pragma once
#include "ObjetInteractif.hpp"

class CarteDuMonde;

class ManteauNoirCuir : public ObjetInteractif
{
public:
	ManteauNoirCuir() :
		ObjetInteractif("manteau noir cuir", "C'est un manteau noir en cuir de bonne qualité pour l'hiver.")
	{}

	string getDescription() const override { return description_; }
	void setDescription(const string& description) override { description_ = description; }
	string getNom() const override { return nom_; }
	void faireAction(CarteDuMonde& carte, Salle* salleCourante) override 
	{
		cout << salleCourante->changerCouleur(Couleur::BLEU) +
			"Vous avez utilisé le manteau de cuire noir! Il est très chique!\n" +
			salleCourante->changerCouleur(Couleur::BLANC);
	}
};