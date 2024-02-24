/*
  Description : Le fichier header qui permet de définir la classe CarteDuMonde.

  Fichier:      CarteDuMonde.hpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#pragma once
#include "Salle.hpp"

class CarteDuMonde
{
public:
	CarteDuMonde() = default;
	~CarteDuMonde() {}

	void ajouterSalle(shared_ptr<Salle> salle);
	shared_ptr<Salle> getSalle(const string& nom);
	shared_ptr<Salle> getSalleDepart() { return salleDepart_; }

private:
	vector<shared_ptr<Salle>> listeSalles_;
	shared_ptr<Salle> salleDepart_;
};
