/*
  Description : Le fichier header qui d�fini la classe Refrigerateur.

  Fichier:      Refrigerateur.hpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#pragma once
#include "ObjetInteractif.hpp"

class CarteDuMonde;

class Refrigerateur : public ObjetInteractif
{
public:
	Refrigerateur() :
		ObjetInteractif("refrigerateur Samsung", "C'est un frigo styl� de couleur aluminium brillante.")
	{}

	string getDescription() const override { return description_; }
	void setDescription(const string& description) override { description_ = description; }
	string getNom() const override { return nom_; }
	void faireAction(CarteDuMonde& carte, Salle* salleCourante) override
	{
		cout << salleCourante->changerCouleur(Couleur::BLEU) +
			"Vous ouvrez le frigo! Il y a des sushis pr�par�s avec de la cr�me glac� et du chocolat!!\n" +
			salleCourante->changerCouleur(Couleur::BLANC);
	}
};