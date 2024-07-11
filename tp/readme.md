# Compilation-INF4048-2024

## Introduction

Bienvenue dans le dépôt GitHub pour le projet de compilation . Ce projet vise à implémenter un compilateur pour un langage de programmation simple, avec des fonctionnalités telles que l'analyse lexicale, l'analyse syntaxique et la génération de code.

## Description du Projet

Ce projet consiste à développer un compilateur en utilisant les outils Flex et Bison. Le compilateur prend en charge les expressions arithmétiques, les affectations de variables et les instructions d'impression.

### Fonctionnalités

- **Analyse Lexicale** : Utilisation de Flex pour identifier les tokens dans le code source.
- **Analyse Syntaxique** : Utilisation de Bison pour analyser la structure syntaxique du code source.
- **Génération de Code** : Génération de code assembleur à partir du code source.

### dépendances:
pour que tout fonctionne bien dans ce projet , vous devez avoir les outils suivants installés dans votre machine:
- gcc
- flex
- bison

## architecture
- L'énoncé de chaque exercice se trouve dans le fichier pdf [**seminaireTraduction-Compilation.pdf**](./seminaireTraduction-Compilation.pdf)
- les corrections de chaque exercices sont dans les dossiers correspondants à chaque tp
- le dossier [**damv_language_anglaise**](./damv_language/) est la version anglase du langage
- le dossier [**damv_language**](./damv_language/) est la version EWONDO du langage

### Fichiers Principaux

- `lexer.l` : Fichier Flex pour l'analyse lexicale.
- `parser.y` : Fichier Bison pour l'analyse syntaxique.

## Utilisation

pour utiliser le langage créé, vous devez écrire le code source dans le ficier `commande.davm` ensuite exécuter le fichier `compilateur.sh` 
Le compilateur prend en entrée un fichier texte contenant le code source du langage. Voici un exemple de code source supporté par le compilateur :



Voici le code Markdown pour la description du fichier README.md :

## Contribuer

Les contributions sont les bienvenues ! Si vous avez des suggestions ou des améliorations, n'hésitez pas à ouvrir une issue ou à soumettre une pull request.

## Licence

Ce projet est sous licence MIT.


Vous pouvez copier modifier ou partager ce code