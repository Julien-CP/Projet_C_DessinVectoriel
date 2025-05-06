# Éditeur de Dessin Vectoriel ASCII - Projet C

Projet réalisé dans le cadre du cours *Algorithmique et structure de données* — L1 Informatique à EFREI Paris

## Présentation

Ce projet est un éditeur de dessin vectoriel réalisé en C, permettant de tracer différentes formes géométriques dans une interface textuelle à base de caractères. Il a été conçu en binôme dans le cadre du cours de programmation en L1 à l'EFREI Paris.

## Membres du projet

- Julien CHAN PENG
- Adrien ASSOUAD

## Objectifs du projet

- Comprendre le principe du dessin vectoriel
- Implémenter une application console interactive en C
- Travailler la gestion mémoire avec des structures complexes et des pointeurs
- Découper un projet en modules (fichiers `.c`)
- Appliquer les bonnes pratiques en C (allocation/désallocation mémoire, modularité)

## Fonctionnalités principales

- Menu interactif avec les options :
  - Ajouter une forme
  - Afficher la liste des formes
  - Supprimer une forme
  - Tracer le dessin (affichage ASCII)
- Formes supportées :
  - Point
  - Ligne
  - Carré
  - Rectangle
  - Cercle
  - Polygone
- Affichage ASCII :
  - `.` représente l’espace vide
  - `#` représente une forme
- Gestion mémoire :
  - Structures dynamiques pour chaque forme
  - Zone de dessin allouée dynamiquement
  - Gestion de la mémoire via pointeurs et fonctions `create_`, `delete_`

## Architecture du projet

Le projet est divisé en plusieurs fichiers pour une meilleure clarté :
- `main.c` : point d'entrée, gestion du menu
- `commandes.c` : logiques d'interaction utilisateur
- `shape.c` / `formes.c` : gestion des formes
- `pixels.c` : gestion du rendu ASCII
- `area.c` : zone de dessin (area)
- `id.c` : attribution d'identifiants uniques

## Remarques
Sous Windows, remplacer system("clear") par system("cls") si nécessaire

## Résultats obtenus
Quelques exemples de résultats générés avec succès :
- Un point placé aux coordonnées (5, 8) affiché avec précision
- Lignes, rectangles, cercles et polygones correctement dessinés en ASCII
- Superposition de formes sur le calque ASCII
- Affichage propre de l’espace de dessin, mise à jour dynamique
- Suppression correcte des formes et libération de la mémoire

## Limite(s) connue(s)
La saisie n’est pas sécurisée : une entrée incorrecte peut provoquer un crash
Certaines fonctions comme l’aide (option E du menu) ne sont pas encore implémentées

## Apprentissage et conclusion
Ce projet a été très formateur. Il nous a permis de :
- Approfondir notre maîtrise du langage C, en particulier sur la gestion de la mémoire
- Comprendre le fonctionnement du dessin vectoriel
- Organiser un programme en plusieurs fichiers avec une architecture claire
- Travailler la communication et la répartition du travail en binôme
