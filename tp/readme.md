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

### Fichiers Principaux

- `lexer.l` : Fichier Flex pour l'analyse lexicale.
- `parser.y` : Fichier Bison pour l'analyse syntaxique.
- `main.c` : Fichier C principal pour l'intégration de Flex et Bison.
- `Makefile` : Fichier pour automatiser la compilation et l'exécution du projet.

## Installation

Pour cloner et exécuter ce projet, suivez les étapes ci-dessous :

1. Clonez le dépôt :
    ```sh
    git clone https://github.com/dekelshoot/Compilation-inf4048-2024.git
    cd Compilation-inf4048-2024
    ```

2. Compilez le projet :
    ```sh
    make
    ```

3. Exécutez le compilateur :
    ```sh
    ./compiler input_file.txt
    ```

## Utilisation

Le compilateur prend en entrée un fichier texte contenant le code source du langage. Voici un exemple de code source supporté par le compilateur :

