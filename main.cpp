/*
    Programme : JEU DU 51
    But : A partir d'un lancé de dé simulé par le programme et selon le niveau de difficulté choisi par le joueur, 
          il doit atteindre le score cible en fonction du niveau choisi sans le dépasser 
          et sans dépasser le nombre de manche qui lui est attribué.
          Une partie est composée de manches. Chaque manche correspond à un lancer de dé par le joueur.  
          En fin de partie l’utilisateur se voit proposer deux choix, soit rejouer un partie ou non. 

          Déroulement d’une manche :          																				                                                                                                       
          Le joueur lance le dé.
          Les points associés à la face ‘tirée’ sont ajoutés au score du joueur.
          Si le score du joueur est égale au score cible, la manche et la partie sont terminées, le joueur gagne la partie.
          Si le score du joueur est supérieur au score cible, la manche et la partie sont terminées, le joueur perd la partie. 
          Si le nombre de manche maximum est atteint, alors la manche et la partie sont terminés.

          Pendant une manche, le joueur a deux possibilités : 																	
           - garder les points gagnés de la manche précédentes. 															
           - rejeter les points gagnés de la manche précédentes.  																
           - abandonner la partie.
    Date de dernière modification : 24/10/2022     
    Auteurs : El Mahdi Dirchaoui / Laborde Romain
    Nous certifions être les auteurs de ce code source et attestons ne pas avoir utilisé d'extraits de code
    provenant d'internet. Ce code source s'appuie uniquement sur les notions de programmation vues dans le
    cadre du module R1.01 - Initiation au développement.
*/

#include <iostream>
#include "game-tools.h"
using namespace std;

int main (void)
{
    // VARIABLES
    const string MESSAGE_ERREUR_SAISI = "Saisie incorrect ! Veuillez saisir la lettre en muniscule en [] precedent votre choix " ; // Le message en cas d'erreur de saisie   
    const string MESSAGE_ARRET_JEU = "Le programme va s'arreter ... A bientot ! "; // Le message a afficher lors de l'arret du jeu 

    unsigned int scoreActuel = 0 ; // La valeur du score actuel de la manche en cours
    unsigned short int mancheEnCours = 0 ; // La valeur de la manche en cours 
    unsigned int pointManchePrecedente = 0 ; // La valeur des points de la manche precedente   
    unsigned int pointMancheEnCours = 0 ; // La valeur des points de la manche en cours 
    
    unsigned short int scoreCible ; // La valeur du score cible a atteindre pour la partie
    unsigned short int nombreMancheMax ; //La valeur du nombre de manche maximmum  
    unsigned short int nombreFaceDe ; // La valeur du nombre de face du de 
    unsigned int valeurDuDe ; // La valeur aleatoire du de 

    string choixInitialisationPartieSaisi ; // Le choix de l'initialisation saisi par l'utilisateur 
    string choixNiveauDifficulteSaisi ; // Le choix de niveau de difficulte saisi par l'utilisateur 
    string choixSaisiManche ; // La valeur du choix saisi par l'utilisateur lors de la manche 
    string choixSaisiRejouer ; // la valeur du choix de rejouer la partie saisi par l'utilisateur 
    string niveauDifficulte ; // Le niveau de difficulte choisi par l'utilisateur à afiicher 

    Couleur couleurMessageErreur = rouge ; // La couleur du texte du message d'erreur

    // TRAITEMENTS
    // INITIALISER LA PARTIE  

    // Afficher principe du jeu
    cout << "__________________ JEU DU 51____________________\n>> Principe du jeu : \nUne partie se deroule en plusieurs manches."<< endl ;
    cout << "Chaque manche correspond a un lancer du de.\nLe but est d atteindre le score cible indique dans un nombre de manche limitee pour gagne." << endl ;
    cout <<"> Si vous atteignez le score cible dans le nombre de manche qui vous est attribue vous gagnez.\n> Si vous depassez le score cible, vous perdez." << endl;
    cout <<"> Si vous depassez le nombre de manche maximal, vous perdez. " << endl ;
    cout <<"Le score cible et les faces du de ainsi que les manches seront differents en fonction du niveau de difficulte." << endl ;
    cout <<"A partir de la deuxieme manche vous aurez la possibilite de garder ou rejeter les points de la manche precedente. "<< endl ;
    cout <<"A tout moment vous avez egalement la possibilite d abandonner la partie." << endl << endl;
    cout << "________________________________________________" << endl << endl;
    cout <<">> Important :\nPour chaque saisie qui vous sera demandee, \nveuillez saisir la lettre en minuscule presente entre [ ] qui precedera votre choix. " << endl;
    cout <<"> Exemple : [ g ] - garder les points manche precedente, vous devez saisir la lettre g en minuscule. " << endl <<endl ;
    cout << "________________________________________________" <<endl << endl; 
    cout <<">> Initialisation de la partie : \nLa partie est preconfigurer sur le niveau facile \n> Le nombre de face du de est 6\n> Le score cible a atteindre est 51" <<endl ;
    cout <<"> Vous avez 17 manches" << endl << endl ;

    // Saisir et vérifier choix initialisation partie
    while (true)
    {
        // Afficher les choix d'initialisation
        cout <<"Vos choix :\n  [ d ] - demarrer la partie niveau facile\n  [ c ] - changer niveau difficulte " << endl ;
        
        // (clavier) >> saisirChoixInitialisationPartie >> choixInitialisationPartieSaisi
        cout <<"Saisir votre choix : " ;
        cin >> choixInitialisationPartieSaisi ;

        if ( choixInitialisationPartieSaisi == "d" || choixInitialisationPartieSaisi == "c" )
        {
            break;
        }

        // MESSAGE_ERREUR_SAISI >> afficherMessageErreurSaisi >> (ecran)
        cout << "________________________________________________" <<endl << endl;    
        afficherTexteEnCouleur(MESSAGE_ERREUR_SAISI, couleurMessageErreur, true);
    }
    
    // Traiter le choix saisi pour parametrer la partie 
    if ( choixInitialisationPartieSaisi == "d" )
    {
        // choixInitialisationPartieSaisi >> parametrerPartieFacile >> scoreCible, nombreMancheMax, nombreFaceDe, niveauDifficulte
        scoreCible = 51 ;
        nombreMancheMax = 17;
        nombreFaceDe = 6;
        niveauDifficulte = "facile" ;
    }
    else
    {
        // Afficher les caracteristique de niveau de difficulte 
        cout << "________________________________________________" << endl;
        cout <<">> Niveau de difficulte :\nNormal \n> Le nombre de face du de est 8\n> Le score cible a atteindre est 41\n> Vous avez 11 manches " <<endl;
        cout << "Expert\n> Le nombre de face du de est 12\n> Le score cible a atteindre est 31\n> Vous avez 6 manches " << endl;

        // Saisir et vérifier choix niveau difficulté
        while (true)
        {
            // Afficher les choix de niveau de difficulté
            cout << "Vos choix :\n  [ n ] - niveau de difficulte normal\n  [ e ] - niveau de difficulte expert" <<endl;
            
            // (clavier) >> saisirChoixNiveauDifficulte >> choixNiveauDifficulteSaisi
            cout <<"Saisir votre choix : " ;    
            cin >> choixNiveauDifficulteSaisi ;

            if ( choixNiveauDifficulteSaisi == "n" || choixNiveauDifficulteSaisi == "e" )
            {
                break;
            }

            cout << "________________________________________________" << endl <<endl;
            // MESSAGE_ERREUR_SAISI >> afficherMessageErreurSaisi >> (ecran)
            afficherTexteEnCouleur(MESSAGE_ERREUR_SAISI, couleurMessageErreur, true);
        }
        

        // choixNiveauDifficulteSaisi >> parametrerPartie >> scoreCible, nombreMancheMax, nombreFaceDe, niveauDifficulte
        if (choixNiveauDifficulteSaisi == "n")
        {
            scoreCible = 41 ;
            nombreMancheMax = 11;
            nombreFaceDe = 8;
            niveauDifficulte = "normal" ;
        }
        else
        {
            scoreCible = 31 ;
            nombreMancheMax = 6;
            nombreFaceDe = 12;
            niveauDifficulte = "expert" ;
        }
    }

    // niveauDifficulte >> afiicherMessageFinInitialisation >> (ecran) 
    cout << endl << "Lancement de la partie en mode " << niveauDifficulte << "..." << endl;   
    pause(2);

    // LANCER LA PARTIE
    while (true)
    {
        // Lancer les manches
        do
        {
            // nombreFaceDe >> genererValeurDuDe >> valeurDuDe
            valeurDuDe = random(1,nombreFaceDe);

            // valeurDuDe, mancheEnCours, pointManchePrécédente, pointMancheEnCours >> parametrerInfosManche >> mancheEnCours, pointManchePrecedente, pointMancheEnCours
            mancheEnCours ++;
            pointManchePrecedente = pointMancheEnCours;
            pointMancheEnCours = valeurDuDe;
            
            effacer();
            // scoreCible, scoreActuel, valeurDuDe, nombreMancheMax, mancheEnCours, pointManchePrecedente, pointMancheEnCours >> afficherInfosManche >> (ecran)
            cout << "________________________________________________" << endl << endl;
            cout << "-- Manche en cours - " << mancheEnCours << " -- Score Actuel - " << scoreActuel << " -- Score cible - " << scoreCible << "--" << endl;
            cout << "> Points manche precedente --> " << pointManchePrecedente << endl;
            cout << "> Face du de --> " << valeurDuDe << endl;
            cout << "> Points manche actuel --> " << pointMancheEnCours << endl;
            cout << "> Score AVEC les points manche precedente --> " << (scoreActuel + pointMancheEnCours) << endl;
            cout << "> Score SANS les points manche precedente --> " << ((scoreActuel + pointMancheEnCours) - pointManchePrecedente) << endl;
            cout << "> Manches restantes --> " << (nombreMancheMax - mancheEnCours) << endl;

            // Afficher et saisir les choix manches
            if (mancheEnCours == 1)
            {
                // Saisir et vérifier les choix manche 1
                while (true)
                {
                    // Afficher les choix de la manche 1
                    cout << "Vos choix : " << endl;
                    cout << "  [ c ] - continuer la partie" << endl;
                    cout << "  [ a ] - abandonner la partie" << endl;

                    // (clavier) >> saisirChoixManche1 >> choixSaisiManche
                    cout << "Saisir votre choix : ";
                    cin >> choixSaisiManche;

                    if ( choixSaisiManche == "c" || choixSaisiManche == "a")
                    {
                        break;
                    }

                    cout << "________________________________________________" << endl << endl;
                    // MESSAGE_ERREUR_SAISI >> afficherMessageErreurSaisi >> (ecran)
                    afficherTexteEnCouleur(MESSAGE_ERREUR_SAISI, couleurMessageErreur, true);
                }
                
            }
            else if (mancheEnCours > 1 && mancheEnCours < nombreMancheMax && (scoreActuel + pointMancheEnCours - pointManchePrecedente) <= scoreCible)
            {
                // Saisir et vérifier les choix manches restantes
                while (true)
                {
                    // Afficher les choix manches 
                    cout << "Vos choix : " << endl;
                    cout << "  [ g ] - garder points manche precedente" << endl;
                    cout << "  [ r ] - rejeter points manche precedente" << endl;
                    cout << "  [ a ] - abandonner la partie" << endl;

                    // (clavier) >> saisirChoixManche >> choixSaisiManche
                    cout << "Saisir votre choix : ";
                    cin >> choixSaisiManche;

                    if ( choixSaisiManche == "g" || choixSaisiManche == "r" || choixSaisiManche == "a")
                    {
                        break;
                    }

                    cout << "________________________________________________" << endl << endl;
                    // MESSAGE_ERREUR_SAISI >> afficherMessageErreurSaisi >> (ecran)
                    afficherTexteEnCouleur(MESSAGE_ERREUR_SAISI, couleurMessageErreur, true);
                }
            }

            // mancheEnCours,choixSaisiManche,pointManchePrecedente,pointMoncheEnCours,nombreMancheMax,scoreCible,scoreActuel >> mettreAJourScoreActuel >> scoreActuel
            if ( mancheEnCours == nombreMancheMax || choixSaisiManche == "a" )
            {
                scoreActuel = scoreActuel;
            }
            else if (mancheEnCours < nombreMancheMax && (scoreActuel + pointMancheEnCours - pointManchePrecedente > scoreCible || choixSaisiManche == "r" ) )
            {
                scoreActuel = scoreActuel + pointMancheEnCours - pointManchePrecedente ;
            }
            else if (choixSaisiManche == "c" || choixSaisiManche == "g" )
            {
                scoreActuel = scoreActuel + pointMancheEnCours; 
            }
    
        } while (scoreActuel < scoreCible && mancheEnCours != nombreMancheMax && choixSaisiManche != "a");
    
        // Afiicher informations fin de partie 
        cout << "  " <<endl;
        cout << "__________________FIN DE PARTIE_________________" << endl << endl; 

        // Afiicher message fin de partie 
        if (scoreActuel == scoreCible)
        {
            cout << "Bien joue ! Vous avez gagne en atteignant le score cible. " << endl;
            cout << "Est-ce que vous etes si bon que ca ..! Rejouer une partie ? " << endl;
        }
        else if (scoreActuel > scoreCible)
        {
            cout << "Dommage vous avez perdu en depassant le score cible. " << endl;
            cout << "On dit qu'il ne faut jamais rester sur un echec. " << endl;
            cout << "Alors partant pour une autre partie ?" << endl;
        }
        else if (mancheEnCours == nombreMancheMax)
        {
            cout << "Domamge vous avez perdu en atteignant le nombre maximal de manche. " << endl;
            cout << "Moi je dis sa vaut le coup de retenter votre chance. "<< endl;
            cout << "Alors partant pour une autre partie ?" << endl;
        }
        else if (choixSaisiManche == "a")
        {
            cout << "Vous abandonnez deja ..!" << endl;
            cout << "Aller une derniere partie ? " << endl;
        }
    
        // Saisir et verifier choix rejouer la partie 
        while (true)
        {
            // Afficher les choix pour rejouer la partie                   
            cout << "Vos choix : " << endl;
            cout << "  [ o ] - oui " << endl;
            cout << "  [ n ] - non " << endl;

            // (clavier) >> saisirChoixRejouerPartie >> choixSaisiRejouer
            cout << "Saisir votre choix : ";
            cin >> choixSaisiRejouer;

            if ( choixSaisiRejouer == "o" || choixSaisiRejouer == "n" )
            {
                break;
            }

            cout << "________________________________________________" << endl << endl;
            // MESSAGE_ERREUR_SAISI >> afficherMessageErreurSaisi >> (ecran)
            afficherTexteEnCouleur(MESSAGE_ERREUR_SAISI, couleurMessageErreur, true);
        }

        if ( choixSaisiRejouer == "n")
        {
            break;
        }
        
        // mancheEnCours,scoreActuel,pointMancheEnCours,choixSaisiManche,pointManchePrecedente >> reinitialiserInfoManche >> mancheEnCours,scoreActuel,pointMancheEnCours,choixSaisiManche,pointManchePrecedente 
        choixSaisiManche = "";
        mancheEnCours = 0 ;
        scoreActuel = 0 ;
        pointMancheEnCours = 0 ;
        pointManchePrecedente = 0 ;
    }

    // ARRETER LE JEU 
    effacer();
    // MESSAGE_ARRET_JEU >> afficherMessageArretJeu >> (ecran) 
    cout <<  MESSAGE_ARRET_JEU  << endl;
    cout << "________________________________________________" << endl;
    
    pause(1);
    effacer();
    return 0;
}
