#include <iostream>
#include <cstdlib>
#include "biblioJeu2D.h"

using namespace std;

const int LARGEUR = 30;
const int HAUTEUR = 20;

struct Couleur 
{
    int r;
    int g;
    int b;
};

struct Position 
{
    int x;
    int y;
};

struct Serpent 
{
    Position corps[LARGEUR * HAUTEUR];
    int longueur;
    Couleur couleurs[LARGEUR * HAUTEUR];
    Position direction;
};

void InitialiserSerpent(Serpent& serpent) 
{
    serpent.longueur = 3;
    serpent.corps[0] = { rand() % LARGEUR, rand() % HAUTEUR };

    // Direction initiale aléatoire
    int dir{ rand() % 4 };
    if (dir == 0)
    {
        serpent.direction = { 1, 0 };
    }
    else if (dir == 1)
    {
        serpent.direction = { -1, 0 };
    }
    else if (dir == 2)
    {
        serpent.direction = { 0, 1 };
    }
    else
    {
        serpent.direction = { 0, -1 };
    }

    for (int i{ 1 }; i < serpent.longueur; i++)
    {
        serpent.corps[i].x = serpent.corps[0].x - i * serpent.direction.x;
        serpent.corps[i].y = serpent.corps[0].y - i * serpent.direction.y;
    }

    for (int i{ 0 }; i < serpent.longueur; i++)
    {
        serpent.couleurs[i] = { rand() % 256, rand() % 256, rand() % 256 };
    }
}

void EffacerQueue(const Serpent& serpent) 
{
    ColorerCellule(serpent.corps[serpent.longueur - 1].x, serpent.corps[serpent.longueur - 1].y, 0, 0, 0);
}

void DeplacerSerpent(Serpent& serpent)
{
    EffacerQueue(serpent);

    for (int i{ serpent.longueur - 1 }; i > 0; i--)
    {
        serpent.corps[i] = serpent.corps[i - 1];
    }

    serpent.corps[0].x += serpent.direction.x;
    serpent.corps[0].y += serpent.direction.y;

    if (serpent.corps[0].x >= LARGEUR)
    {
        serpent.corps[0].x = 0;
    }
    if (serpent.corps[0].x < 0)
    {
        serpent.corps[0].x = LARGEUR - 1;
    }
    if (serpent.corps[0].y >= HAUTEUR)
    {
        serpent.corps[0].y = 0;
    }
    if (serpent.corps[0].y < 0)
    {
        serpent.corps[0].y = HAUTEUR - 1;
    }

    // Changer couleur du serpent
    for (int i{ 0 }; i < serpent.longueur; i++)
    {
        serpent.couleurs[i] = { rand() % 256, rand() % 256, rand() % 256 };
    }
}

void AgrandirSerpent(Serpent& serpent) 
{
    serpent.corps[serpent.longueur] = serpent.corps[serpent.longueur - 1];
    serpent.couleurs[serpent.longueur] = { rand() % 256, rand() % 256, rand() % 256 };
    serpent.longueur++;
}

bool CollisionAvecSoi(const Serpent& serpent) 
{
    for (int i{ 1 }; i < serpent.longueur; i++) 
    {
        if (serpent.corps[0].x == serpent.corps[i].x && serpent.corps[0].y == serpent.corps[i].y) 
        {
            return true;
        }
    }
    return false;
}

void LireDirection(Serpent& serpent) 
{
    if (FlecheHautEstAppuyee() && serpent.direction.y == 0)
    {
        serpent.direction = { 0, -1 };
    }
    else if (FlecheBasEstAppuyee() && serpent.direction.y == 0)
    {
        serpent.direction = { 0, 1 };
    }
    else if (FlecheGaucheEstAppuyee() && serpent.direction.x == 0)
    {
        serpent.direction = { -1, 0 };
    }
    if (FlecheDroiteEstAppuyee() && serpent.direction.x == 0)
    {
        serpent.direction = { 1, 0 };
    }
}

void AfficherSerpent(const Serpent& serpent) 
{
    for (int i{ 0 }; i < serpent.longueur; i++)
    {
        ColorerCellule(serpent.corps[i].x, serpent.corps[i].y, serpent.couleurs[i].r, serpent.couleurs[i].g, serpent.couleurs[i].b);
    }
    // Colorer la tête en blanc
    ColorerCellule(serpent.corps[0].x, serpent.corps[0].y, 255, 255, 255);
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    srand((unsigned int(time(0))));
    if (!InitialiserFenetre(LARGEUR, HAUTEUR, "Jeu Snake")) 
    {
        cout << "Erreur lors de l'initialisation de la fenêtre!" << endl;
        return -1;
    }

    Serpent serpent;
    InitialiserSerpent(serpent);
    int tempsDepuisDernierMouvement{ 0 };
    int tempsDepuisDerniereCroissance{ 0 };

    while (FenetreEstActive()) 
    {
        int deltaTemps = TempsEcouleMicrosecondes();
        tempsDepuisDernierMouvement += deltaTemps;
        tempsDepuisDerniereCroissance += deltaTemps;

        LireDirection(serpent);

        if (tempsDepuisDernierMouvement >= 250000) 
        {
            DeplacerSerpent(serpent);
            tempsDepuisDernierMouvement = 0;
        }

        if (tempsDepuisDerniereCroissance >= 1000000) 
        {
            AgrandirSerpent(serpent);
            tempsDepuisDerniereCroissance = 0;
        }

        if (CollisionAvecSoi(serpent)) {
            cout << "------------------------------------------------\n"
                 << "             Game Over! Score: " << serpent.longueur
                 << "\n------------------------------------------------" << endl;
            break;
        }

        AfficherSerpent(serpent);
    }

    return 0;
}