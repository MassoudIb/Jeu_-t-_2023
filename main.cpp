/*
  Description : Le programme permet de commencer le jeu associé à la carte du monde.

  Fichier:      main.cpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#include "cppitertools/range.hpp"
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp" 
#include "debogage_memoire.hpp"  

#include "Jeu.hpp"

using namespace iter;

int main()
{
	interaction::Jeu jeu;
	jeu.commencer();
}