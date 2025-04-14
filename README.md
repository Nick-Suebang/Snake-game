# Projet Snake

## Description
Ce projet est une implémentation du jeu classique Snake en C++ utilisant la bibliothèque SFML. Le joueur contrôle un serpent qui doit manger des pommes pour grandir tout en évitant les collisions avec les murs et son propre corps.

## Prérequis
- Visual Studio 2022
- SFML 2.5.1
- Windows SDK 10.0
- C++17 ou supérieur

## Installation
1. Cloner le repository
2. Ouvrir le projet dans Visual Studio 2022
3. Vérifier que les dépendances SFML sont correctement installées
4. Compiler et exécuter le projet

## Configuration du projet
Le projet est configuré pour :
- Architecture x64
- Mode Debug et Release
- Utilisation de SFML 2.5.1
- Character Set : Unicode

## Structure du projet
```
NickSuebang-TP03-Snake/
├── src/
│   ├── main.cpp           # Point d'entrée du programme
│   └── biblioJeu2D.h      # Bibliothèque de fonctions pour le jeu
├── packages/              # Dépendances SFML
└── assets/               # Ressources du jeu (images, sons, etc.)
```

## Contrôles
- Flèches directionnelles : Déplacer le serpent
- ESC : Quitter le jeu
- ESPACE : Pause/Reprendre

## Fonctionnalités
- Déplacement fluide du serpent
- Système de score
- Collision avec les murs et le corps du serpent
- Croissance du serpent après avoir mangé une pomme
- Système de pause
- Affichage du score

## Compilation
1. Sélectionner la configuration (Debug/Release)
2. Sélectionner la plateforme (x64)
3. Compiler le projet (F5 pour débugger, Ctrl+F5 pour exécuter)

## Dépendances
Le projet utilise SFML pour :
- Gestion des fenêtres
- Rendu graphique
- Gestion des entrées
- Gestion des collisions

## Support
En cas de problèmes :
1. Vérifier la version de Visual Studio
2. Vérifier l'installation de SFML
3. Vérifier les chemins d'inclusion des bibliothèques

## Auteur
Nick Suebang

## Licence
Ce projet est distribué sous licence MIT.
