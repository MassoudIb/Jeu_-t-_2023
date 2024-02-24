/*
  Description : Le fichier source qui permet l'implémentation de la classe BoutonRouge.

  Fichier:      BoutonRouge.cpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#pragma once
#include "BoutonRouge.hpp"


void BoutonRouge::faireAction(CarteDuMonde& carte, Salle* salleCourante) 
{
	if (salleCourante->getNom() == "Salon") {
		shared_ptr<Salle> salleR = carte.getSalle("Salle R");
		shared_ptr<Salle> couloir = carte.getSalle("Couloir");
		salleR->setAccessible(true);
		couloir->ajouterConnection(salleR, Direction::EST);
		salleR->ajouterConnection(couloir, Direction::OUEST);
		cout << salleCourante->changerCouleur(Couleur::ROUGE) +
			"Vous avez utilisé le Bouton Rouge." +
			salleCourante->changerCouleur(Couleur::VERT) +
			"La Salle R est maintenant déverrouillée et accessible!"
			+ salleCourante->changerCouleur(Couleur::BLANC) << endl;
	}
	else
		cout << "Le Bouton Rouge ne peut être utilisé que dans le Salon." << endl;
}
