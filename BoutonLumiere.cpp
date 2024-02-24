/*
  Description : Le fichier source qui permet l'implémentation de la classe BoutonLumiere.

  Fichier:      BoutonLumiere.cpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/

#pragma once
#include "BoutonLumiere.hpp"

void BoutonLumiere::faireAction(CarteDuMonde& carte, Salle* salleCourante)
{
    shared_ptr<Salle> salon = carte.getSalle("Salon");
    if (salleCourante->getNom() == "Couloir")
    {
        if (estAllume())
        {
            eteindre();
            salon->setEtatLumiere(false);
            cout << salle_->changerCouleur(Couleur::MAUVE) +
                "Vous éteignez la lumière dans le salon."
                + salle_->changerCouleur(Couleur::BLANC) << endl;
        }
        else
        {
            allumer();
            salon->setEtatLumiere(true);
            cout << salle_->changerCouleur(Couleur::JAUNE) +
                "Vous allumez la lumière dans le salon."
                + salle_->changerCouleur(Couleur::BLANC) << endl;
        }
    }

    else if(salleCourante->getNom() == "Salon")
        cout << "Vous ne pouvez pas contrôler la lumière depuis cette salle.\n"
             << "Vous devez vous déplacer au couloir pour pouvoir allumer la lumière ici!\n";
    
    else
    {
        if (estAllume())
        {
            eteindre();
            salleCourante->setEtatLumiere(false);
            cout << salle_->changerCouleur(Couleur::MAUVE) +
                "Vous éteignez la lumière dans cette salle."
                + salle_->changerCouleur(Couleur::BLANC) << endl;
        }
        else
        {
            allumer();
            salleCourante->setEtatLumiere(true);
            cout << salle_->changerCouleur(Couleur::JAUNE) +
                "Vous allumez la lumière dans cette salle."
                + salle_->changerCouleur(Couleur::BLANC) << endl;
        }
    }
}