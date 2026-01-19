.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions spéciales pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _download_code:

Télécharger le code
===============================

Tous les programmes d’exemple utilisés dans ce kit sont stockés dans notre dépôt GitHub officiel.  
Utilisez la commande suivante pour télécharger le projet complet sur votre Raspberry Pi.

Cloner le dépôt
--------------------------

#. Connectez-vous à votre Raspberry Pi et exécutez :

   .. raw:: html
   
       <run></run>
   
   .. code-block:: bash
   
      cd ~/
      git clone https://github.com/sunfounder/davinci-kit-for-raspberry-pi.git --depth 1

#. Entrez dans le répertoire du projet :

   .. raw:: html
   
       <run></run>
   
   .. code-block:: bash
   
      cd ~/davinci-kit-for-raspberry-pi/

#. Listez les fichiers :

   .. raw:: html
   
       <run></run>
   
   .. code-block:: bash
   
      ls

#. Vous verrez une structure similaire à celle-ci :

   .. code-block:: text
   
      davinci-kit-for-raspberry-pi/
      ├── c/
      ├── datasheet
      ├── iot/
      ├── nodejs/
      ├── python-pi5/
      ├── python/
      ├── scratch/
      └── README.md

Aperçu de la structure du projet
-------------------------------------------------

Voici une brève présentation de chaque dossier :

* **c/**  

  Exemples et bibliothèques en langage C pour les utilisateurs qui préfèrent programmer en C sur Raspberry Pi.

* **datasheet/**  

  Fiches techniques, spécifications et documents de référence pour les composants matériels utilisés dans le projet.

* **iot/**  

  Exemples liés à l’IoT, incluant la connectivité avec la plateforme Blynk, des démonstrations de capteurs et des modules de communication.

* **nodejs/**

  Exemples Node.js pour les utilisateurs développant des projets basés sur JavaScript sur Raspberry Pi.

* **python-pi5/**  

  Exemples Python écrits avec la bibliothèque ``GPIO Zero``, spécifiquement optimisés pour le **Raspberry Pi 5**.

* **python/**  

  Programmes d’exemple Python écrits avec la bibliothèque ``RPi.GPIO``, adaptés à la plupart des cartes Raspberry Pi.

* **scratch/** 

  Exemples de programmation Scratch conçus pour les débutants apprenant la programmation graphique.

* **README.md**  

  Informations de base sur le dépôt et instructions générales.

Vous pouvez maintenant entrer dans le dossier correspondant à votre langage de programmation ou type de projet préféré et commencer à exécuter les exemples.
