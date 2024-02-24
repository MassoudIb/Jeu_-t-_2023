/*
  Description : Le fichier header qui permet de définir la classe Jeu.

  Fichier:      Jeu.hpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/
#pragma once
#include <functional>

#include "CarteDuMonde.hpp"
#include "ObjetInteractif.hpp"
#include "BoutonRouge.hpp"
#include "BoutonLumiere.hpp"

using CommandeAction = function<void()>;

// pour gérer l'intéraction avec le joueur et le jeu.
namespace interaction
{
	class Jeu
	{
	public:

		Jeu() :
			carte_(),
			salleCourante_(nullptr),
			jeuTermine_(false)
		{}
		~Jeu() {}

		void initialiserCarteDuMonde();
		void initialiserObjets();
		void traiterCommande();
		void commencer();

		void afficherDescriptionJeu();
		void afficherDescriptionSalleCourante();
		void afficherCaractere();
		void afficherCommandeInconnue();
		void afficherNePeutSeDeplacer();


		// Les actions possibles
		void use(const string& nomObjet);
		void look(const string& nomObjet);
		void look();
		void actionLook();
		void actionUse();
		void actionDeplacer(string commande);
		void quitter();
		void deplacer(Direction direction);


	private:
		CarteDuMonde carte_;
		shared_ptr<Salle> salleCourante_;
		bool jeuTermine_ ;
		unordered_map<string, shared_ptr<ObjetInteractif>> motCleDesObjets_;
	};
}