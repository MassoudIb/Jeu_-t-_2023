/*
  Description : Le fichier source qui permet l'implémentation de la classe Salle.

  Fichier:      Salle.cpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#include <iostream>
#include"Salle.hpp";
#include "ObjetInteractif.hpp"


string Salle::getDescriptionEtat()
{
	string description;

	if (!etatLumiere_)
	{
		description += changerCouleur(Couleur::MAUVE) + 
			" La salle est sombre et noire. Vous ne pouvez pas discerner aucun objet." +
			changerCouleur(Couleur::BLANC);
		description += " Vous pouvez seulement voir les accès aux autres salles.\n";
		getNomSallesVoisines();
	}
	
	else
	{
		description += changerCouleur(Couleur::JAUNE) + "\nLa salle est allumée!" 
			+ changerCouleur(Couleur::BLANC);
		cout << getDescription();
		if (not objetsInteractifs_.empty())
		{
			description += " Vous pouvez voir les objets interactifs suivants:";
			for (const auto& objet : objetsInteractifs_)
			{
				description += changerCouleur(Couleur::ROSE) +
				"\n- " + objet->getNom() + changerCouleur(Couleur::BLANC);
			}
		}
	}
	return description;
}

void Salle::ajouterObjetInteractif(shared_ptr<ObjetInteractif> objet)
{
	objetsInteractifs_.push_back(objet);
}

void Salle::ajouterConnection(shared_ptr<Salle> salle, Direction direction)
{
	connections_[direction].push_back(salle);
}

ObjetInteractif* Salle::getObjetInteractif(const string& nomObjet) const
{
	for (const auto& objet : objetsInteractifs_)
	{
		if (objet->getNom() == nomObjet)
		{
			return objet.get();
		}
	}
	return nullptr;
}

bool Salle::possedeObjetInteractif(const string& nomObjet) const
{
	for (const auto& objet : objetsInteractifs_)
	{
		if (objet->getNom() == nomObjet)
			return true;
	}

	return false;
}

vector<shared_ptr<Salle>>& Salle::getSallesConnectees()
{
	vector<shared_ptr<Salle>> sallesConnectees;

	for (const auto& pair : connections_)
	{
		const vector<shared_ptr<Salle>>& salles = pair.second;
		sallesConnectees.insert(sallesConnectees.end(), salles.begin(), salles.end());
	}
	return sallesConnectees;
}

bool Salle::possedeConnection(shared_ptr<Salle> salle) const
{
	// Vérification si la salle possede des connections
	return connections_.count(salle->getDirection()) > 0;
}

shared_ptr<Salle> Salle::getSalleVoisineEnDirection(Direction direction)
{
	switch (direction)
	{
		case Direction::NORD:
			if(not connections_[Direction::NORD].empty())
				return connections_[Direction::NORD].front();
			break;
		case Direction::EST:
			if (not connections_[Direction::EST].empty())
				return connections_[Direction::EST].front();
			break;
		case Direction::OUEST:
			if (not connections_[Direction::OUEST].empty())
				return connections_[Direction::OUEST].front();
			break;
		case Direction::SUD:
			if (not connections_[Direction::SUD].empty())
				return connections_[Direction::SUD].front();
			break;
	}

	return nullptr;
}

void Salle::getNomSallesVoisines()
{
	for (const auto& pair : connections_)
	{
		const vector<shared_ptr<Salle>>& salles = pair.second;
		if (not salles.empty())
		{
			string nomSalle = changerCouleur(Couleur::CYAN) + salles.front()->getNom() + changerCouleur(Couleur::BLANC);
			
			if (pair.first == Direction::NORD)
				cout << " • " + nomSalle << " se trouve au" + changerCouleur(Couleur::VERT) + " nord (N)" + changerCouleur(Couleur::BLANC) << endl;
			else if (pair.first == Direction::EST)
				cout << " • " + nomSalle << " se trouve à" + changerCouleur(Couleur::ROUGE) + " l'est (E)" + changerCouleur(Couleur::BLANC) << endl;
			else if (pair.first == Direction::OUEST)
				cout << " • " + nomSalle << " se trouve à" + changerCouleur(Couleur::BLEU) + " l'ouest (W)" + changerCouleur(Couleur::BLANC) << endl;
			else if (pair.first == Direction::SUD)
				cout << " • " + nomSalle << " se trouve au" + changerCouleur(Couleur::JAUNE) + " sud (S)" + changerCouleur(Couleur::BLANC)<< endl;
		}
	}
	cout << endl;
}