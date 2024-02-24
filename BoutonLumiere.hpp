/*
  Description : Le fichier header qui défini la classe BoutonLumiere.

  Fichier:      BoutonLumiere.hpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#pragma once
#include "ObjetInteractif.hpp"
#include <memory>

class CarteDuMonde;
class Salle;

class BoutonLumiere : public ObjetInteractif
{
public:
	BoutonLumiere() :
		ObjetInteractif("interrupteur de lumiere",  "Cette interrupteur permet d'allumer la lumière dans cette salle."),
		salle_(nullptr),
		allume_()
	{}

	string getDescription() const override { return description_; }
    void setDescription(const string& description) override { description_ = description; }
	string getNom() const override { return nom_; }
    void faireAction(CarteDuMonde& carte, Salle* salleCourante) override;

	void allumer() { allume_ = true; }
	void eteindre() { allume_ = false; }
	bool estAllume() const { return allume_; }
	Salle* getSalle() const { return salle_; }

private:
	Salle* salle_;
	bool allume_;
};