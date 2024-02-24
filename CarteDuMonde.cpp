/*
  Description : Le fichier source qui permet l'implémentation de la classe CarteDuMonde.

  Fichier:      CarteDuMonde.cpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/

#include "CarteDuMonde.hpp"

void CarteDuMonde::ajouterSalle(shared_ptr<Salle> salle)
{
    listeSalles_.push_back(salle);
}

shared_ptr<Salle> CarteDuMonde::getSalle(const string& nom)
{
    for (const auto& salle : listeSalles_)
        if (salle->getNom() == nom)
            return salle;
    // Si la salle n'est pas trouvé, return nullptr
    return nullptr;
}
