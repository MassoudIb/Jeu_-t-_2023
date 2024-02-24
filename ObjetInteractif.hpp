/*
  Description : Le fichier header qui défini la classe ObjetInteractif.

  Fichier:      ObjetInteractif.hpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <unordered_set>
#include "CarteDuMonde.hpp"

using namespace std;

class CarteDuMonde;
class Salle;

class   ObjetInteractif 
{
public:
	ObjetInteractif(const string& nom, const string& description):
		nom_(nom),
		description_(description)
	{}

	virtual string getDescription() const = 0;
	virtual void setDescription(const string& description) = 0;
	virtual string getNom() const = 0;
	virtual void faireAction(CarteDuMonde& carte, Salle* salleCourante) = 0;

	const unordered_set<string>& getMotsCles() const { return motsCles_; }
	void setMotCles(initializer_list<string> motCles)
	{
		motsCles_.clear();
		for (const string& mot : motCles)
			motsCles_.insert(mot);
	}

protected:
	string nom_, description_;
	unordered_set<string> motsCles_;
};