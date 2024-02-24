/*
  Description : Le programme permet d'initialiser la carte du jeu et d'impl�menter 
                les int�ractions possibles avec le joueur.

  Fichier:      Jeu.cpp
  Auteur:       Massoud Ibrahim
  Date:         29 juin 2023
*/

#include <iostream>
#include "Jeu.hpp"
#include "ManteauNoirCuir.hpp"
#include "Piano.hpp"
#include "Refrigerateur.hpp"
#include "EcranPlasma.hpp"
#include "SuperOrdinateur.hpp"


void interaction::Jeu::initialiserCarteDuMonde()
{
    // Cr�ation des salles
    shared_ptr<Salle> entree        = make_shared<Salle>("Entr�e", "Vous �tes dans l'entr�e. Il y a un tapis sur le sol.", true);
    shared_ptr<Salle> salon         = make_shared<Salle>("Salon", "Vous �tes dans le salon. Le salon est grand et il vous intrigue.", false);
    shared_ptr<Salle> couloir       = make_shared<Salle>("Couloir", "Vous �tes dans le couloir.",  true);
    shared_ptr<Salle> petiteChambre = make_shared<Salle>("Petite Chambre", "Vous �tes dans une petite chambre. Elle n'a rien de sp�cial autre que d'�tre petite.", true);
    shared_ptr<Salle> cuisine       = make_shared<Salle>("Cuisine", "Vous �tes dans la cuisine. Elle est tr�s jaune 'beurre' comme la mode d'une certaine �poque.", true);
    shared_ptr<Salle> salleDeJeu    = make_shared<Salle>("Salle de Jeu", "Vous �tes dans la salle de jeu. Elle est bleu avec un super ordinateur et de la lumi�re RGB.", true);
    shared_ptr<Salle> cinema        = make_shared<Salle>("Cinema", "Vous �tes dans la salle de cinema. Il y a un grand �cran sp�cial.", true);
    shared_ptr<Salle> couloirSecret = make_shared<Salle>("Couloir Secret", "Vous �tes dans le couloir secret. Il est sombre et rempli de secrets.", false);
    shared_ptr<Salle> sauna         = make_shared<Salle>("Sauna", "Vous �tes dans la salle de sauna. Il y a beaucoup de vapeur chaude avec une fragance au citron!", true);
    shared_ptr<Salle> piscine       = make_shared<Salle>("Piscine", "Vous �tes dans la salle de piscine. Il y a un bain tourbillon", true);
    shared_ptr<Salle> salleR        = make_shared<Salle>("Salle R", "Vous �tes dans la salle secr�te R.", true);

    // Faire les connections entre les diff�rentes salles du monde.
    entree->ajouterConnection(salon, Direction::EST);
    entree->ajouterConnection(salleDeJeu, Direction::OUEST);
    entree->ajouterConnection(couloir, Direction::NORD);

    salon->ajouterConnection(entree, Direction::OUEST);

    salleDeJeu->ajouterConnection(entree, Direction::EST);
    salleDeJeu->ajouterConnection(cinema, Direction::SUD);
    salleDeJeu->ajouterConnection(petiteChambre, Direction::NORD);
    salleDeJeu->ajouterConnection(sauna, Direction::OUEST);

    cinema->ajouterConnection(salleDeJeu, Direction::NORD);
    cinema->ajouterConnection(couloirSecret, Direction::OUEST);

    couloirSecret->ajouterConnection(cinema, Direction::EST);
    couloirSecret->ajouterConnection(sauna, Direction::NORD);

    sauna->ajouterConnection(couloirSecret, Direction::SUD);
    sauna->ajouterConnection(piscine, Direction::NORD);
    sauna->ajouterConnection(salleDeJeu, Direction::EST);

    piscine->ajouterConnection(sauna, Direction::SUD);
    piscine->ajouterConnection(petiteChambre, Direction::EST);

    couloir->ajouterConnection(entree, Direction::SUD);
    couloir->ajouterConnection(cuisine, Direction::NORD);
    couloir->ajouterConnection(petiteChambre, Direction::OUEST);

    petiteChambre->ajouterConnection(couloir, Direction::EST);
    petiteChambre->ajouterConnection(salleDeJeu, Direction::SUD);
    petiteChambre->ajouterConnection(piscine, Direction::OUEST);

    cuisine->ajouterConnection(couloir, Direction::SUD);

    // Initialisation de l'accessibilit� des salles
    entree->setAccessible(true);
    salon->setAccessible(true);
    couloir->setAccessible(true);
    petiteChambre->setAccessible(true);
    cuisine->setAccessible(true);
    salleDeJeu->setAccessible(true);
    cinema->setAccessible(true);
    couloirSecret->setAccessible(true);
    sauna->setAccessible(true);
    piscine->setAccessible(true);
    // La seule salle qui est false car il faut appuyer le bouton rouge
    // depuis le salon pour la rendre accessible !
    salleR->setAccessible(false);


    // Ajout des salles � la carte du monde parfait
    carte_.ajouterSalle(entree);
    carte_.ajouterSalle(salon);
    carte_.ajouterSalle(couloir);
    carte_.ajouterSalle(petiteChambre);
    carte_.ajouterSalle(cuisine);
    carte_.ajouterSalle(salleDeJeu);
    carte_.ajouterSalle(cinema);
    carte_.ajouterSalle(couloirSecret);
    carte_.ajouterSalle(sauna);
    carte_.ajouterSalle(piscine);
    carte_.ajouterSalle(salleR);

    salleCourante_ = entree;
    initialiserObjets();
}

void interaction::Jeu::initialiserObjets()
{
    shared_ptr<ObjetInteractif> boutonRouge     = make_shared<BoutonRouge>();
    shared_ptr<ObjetInteractif> boutonLumiere   = make_shared<BoutonLumiere>();
    shared_ptr<ObjetInteractif> manteauNoirCuir = make_shared<ManteauNoirCuir>();
    shared_ptr<ObjetInteractif> piano           = make_shared<Piano>();
    shared_ptr<ObjetInteractif> refrigerateur   = make_shared<Refrigerateur>();
    shared_ptr<ObjetInteractif> ecran           = make_shared<EcranPlasma>();
    shared_ptr<ObjetInteractif> ordinateur      = make_shared<SuperOrdinateur>();

    manteauNoirCuir->setMotCles({"manteau", "cuir", "noir", "manteau noir", "manteau cuir", "leatherstuff"});
    piano->setMotCles({"vieux piano", "piano", "electrique", "piano electrique", "vieux piano electrique"});
    refrigerateur->setMotCles({ "refrigerateur Samsung", "refrigerateur", "Samsung", "frigo", "food"});
    ecran->setMotCles({ "ecran plasma", "ecran", "plasma", "TV"});
    ordinateur->setMotCles({ "super ordinateur Intel i12", "super ordinateur", "super", "ordinateur", "Intel"});
    boutonLumiere->setMotCles({"interrupteur", "lumiere", "light switch", "interrupteur de lumiere"});
    boutonRouge->setMotCles({"bouton rouge", "un bouton", "le bouton" });

    auto ajouterObjetMotCles = [&](shared_ptr<ObjetInteractif> objet) {
        for (auto&& motcle : objet->getMotsCles())
            motCleDesObjets_[motcle] = objet;
    };

    ajouterObjetMotCles(manteauNoirCuir);
    ajouterObjetMotCles(piano);
    ajouterObjetMotCles(ecran);
    ajouterObjetMotCles(ordinateur);
    ajouterObjetMotCles(refrigerateur);
    ajouterObjetMotCles(boutonLumiere);
    ajouterObjetMotCles(boutonRouge);

    carte_.getSalle("Entr�e")->ajouterObjetInteractif(boutonLumiere);
    carte_.getSalle("Entr�e")->ajouterObjetInteractif(manteauNoirCuir);
    carte_.getSalle("Salon")->ajouterObjetInteractif(boutonRouge);
    carte_.getSalle("Salon")->ajouterObjetInteractif(piano);
    carte_.getSalle("Couloir")->ajouterObjetInteractif(boutonLumiere);
    carte_.getSalle("Cuisine")->ajouterObjetInteractif(boutonLumiere);
    carte_.getSalle("Cuisine")->ajouterObjetInteractif(refrigerateur);
    carte_.getSalle("Cinema")->ajouterObjetInteractif(boutonLumiere);
    carte_.getSalle("Cinema")->ajouterObjetInteractif(ecran);
    carte_.getSalle("Salle de Jeu")->ajouterObjetInteractif(ordinateur);
    carte_.getSalle("Salle de Jeu")->ajouterObjetInteractif(boutonLumiere);
    carte_.getSalle("Piscine")->ajouterObjetInteractif(boutonLumiere);
    carte_.getSalle("Petite Chambre")->ajouterObjetInteractif(boutonLumiere);
}

void interaction::Jeu::commencer()
{
    afficherDescriptionJeu();
    initialiserCarteDuMonde();
    afficherDescriptionSalleCourante();
    salleCourante_->getNomSallesVoisines();
    while (not jeuTermine_) 
        traiterCommande();
}

void interaction::Jeu::afficherDescriptionJeu()
{
    cout << ">>>>>>> INF1015 Jeu �t� 2023 Livrable final <<<<<<<\n"
         << ">�>�>�> > JEU DE L'ANN�E EDITION MASSOUD < <�<�<�<\n\n"
         << "Les commandes possibles:\n"
         << salleCourante_->changerCouleur(Couleur::VERT)   + " � N: pour aller au nord\n"
         << salleCourante_->changerCouleur(Couleur::ROUGE)  + " � S: pour aller au sud\n"
         << salleCourante_->changerCouleur(Couleur::JAUNE)  + " � E: pour aller � l'est\n"
         << salleCourante_->changerCouleur(Couleur::BLEU)   + " � W: pour aller � l'ouest\n"
         << salleCourante_->changerCouleur(Couleur::ROSE)   + " � look: pour avoir la description de la salle courante\n"
         << salleCourante_->changerCouleur(Couleur::ROSE)   + " � look nomObjet: pour avoir la description d'un objet.\n"
         << salleCourante_->changerCouleur(Couleur::CYAN)   + " � use nomObjet : pour utiliser un objet!\n"
         << salleCourante_->changerCouleur(Couleur::VERT) 
         << "    (!!) Il est possible d'utiliser les commandes 'look' et 'use' avec des mots-cl�s intuitifs\n"
         << "    Par exemple: 'use light' ou 'use switch' ou m�me 'look lumiere'! \n"
         << salleCourante_->changerCouleur(Couleur::JAUNE)
         << "    � savoir: 'use light' peut �tre utilis� autant de fois que voulu pour contr�ler la lumi�re!\n"
         << salleCourante_->changerCouleur(Couleur::ORANGE) + " � quitter: pour quitter le jeu\n\n" + salleCourante_->changerCouleur(Couleur::BLANC);
}

void interaction::Jeu::afficherDescriptionSalleCourante()
{
    cout << "\n- - - " + salleCourante_->getNom() + " - - -\n"
         << salleCourante_->getDescriptionEtat() << endl;

    vector<shared_ptr<ObjetInteractif>> objetsInteractifs = salleCourante_->getObjetsInteractifs();
}

void interaction::Jeu::afficherCaractere()
{
    cout <<  "> ";
}

void interaction::Jeu::afficherCommandeInconnue()
{
    cout << "Commande inconnue" << endl;
}

void interaction::Jeu::afficherNePeutSeDeplacer()
{
    cout << "Vous ne pouvez pas aller dans cette direction." << endl;
}

void interaction::Jeu::quitter()
{
    cout << "\n\nJeu termin�. Merci d'avoir jou�!\n"
        << "- - - - - - - Fin - - - - - - -\n\n";
}

void interaction::Jeu::use(const string& nomObjet)
{      
    for (const auto& mot : motCleDesObjets_)
    {
        if (mot.first.find(nomObjet) != string::npos)
        {
            mot.second->faireAction(carte_, salleCourante_.get());
            return;
        }
    }
    cout << "L'objet interactif \"" << nomObjet << "\" n'a pas �t� trouv� dans cette salle." << endl;
}

void interaction::Jeu::look()
{ 
    afficherDescriptionSalleCourante();  
}

void interaction::Jeu::look(const string& nomObjet)
{
    for (const auto& mot : motCleDesObjets_)
    {
        if (mot.first.find(nomObjet) != string::npos)
        {
            if (salleCourante_->getNom() == "Couloir" && mot.second->getNom() == "interrupteur de lumiere")
            {
                cout << "Cet interrupteur permet d'allumer la lumi�re dans le salon.\n";
            }
            else
                cout << mot.second->getDescription() << endl;
            return;
        }
    }

    cout << "Il n'y a pas de '" << nomObjet << "'. Entrez un nom valide d'objet int�ractif ou �criver seulement la commande 'look' pour avoir la description de la salle courante." << endl;
}

void interaction::Jeu::actionLook()
{
    if (cin.peek() == '\n')
        look();

    else
    {
        cin >> ws;
        string nomObjet;
        getline(cin, nomObjet);
        look(nomObjet);
    }
}

void interaction::Jeu::actionUse()
{
    if (cin.peek() == '\n')
        cout << "Vous n'avez pas saisi un objet. La commande use doit �tre utilis�e avec un nom d'objet ou un mot-cl�." << endl;

    else
    {
        cin >> ws;
        string nomObjet;
        getline(cin, nomObjet);
        use(nomObjet);
    }
}

void interaction::Jeu::actionDeplacer(string commande)
{
    Direction direction;
    if (commande == "N")
        direction = Direction::NORD;
    else if (commande == "S")
        direction = Direction::SUD;
    else if (commande == "E")
        direction = Direction::EST;
    else if (commande == "W")
        direction = Direction::OUEST;

    deplacer(direction);
    salleCourante_->getNomSallesVoisines();
}

void interaction::Jeu::deplacer(Direction direction)
{
    shared_ptr<Salle> salleVoisine = salleCourante_->getSalleVoisineEnDirection(direction);

    if (salleVoisine != nullptr)
    {
        salleCourante_ = salleVoisine;
        afficherDescriptionSalleCourante();
    }
    else
        afficherNePeutSeDeplacer();
}

void interaction::Jeu::traiterCommande()
{
    afficherCaractere();
    string commande;
    cin >> commande;
    unordered_map<string, CommandeAction> actions =
    {
        {"quitter", [this]() {quitter(); }},
        {"look",    [this]() {actionLook(); }},
        {"use",     [this]() {actionUse(); }},
        {"N",       [this]() {actionDeplacer("N"); }},
        {"E",       [this]() {actionDeplacer("E"); }},
        {"W",       [this]() {actionDeplacer("W"); }},
        {"S",       [this]() {actionDeplacer("S"); }}
    };

    auto it = actions.find(commande);
    if (it != actions.end())
        it->second();
    else
        afficherCommandeInconnue();
}