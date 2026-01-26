.. note::

    Bonjour, bienvenue dans la communauté SunFounder dédiée aux passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et relevez les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et bénéficiez de contenus exclusifs.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos dernières nouveautés.
    - **Promotions festives et cadeaux** : Participez à des concours et à des promotions spéciales lors des périodes festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Vidéo 17 : Mélange de toutes les couleurs sur une LED RVB
=======================================================================================

Cette vidéo aborde la construction et la maîtrise du contrôle d'une LED RVB à l'aide d'un Raspberry Pi et d'une puce ADC0834. Elle commence par une introduction à la série de tutoriels, sponsorisée par SunFounder, mettant l'accent sur les projets Raspberry Pi. Dans l'épisode précédent, la tâche consistait à créer une LED dimmable, et l'objectif est maintenant de la remplacer par une LED RVB.

Le récapitulatif du circuit comprend l'utilisation de la puce ADC0834, de potentiomètres et de résistances pour la configuration de la LED RVB. Les instructions de câblage soulignent l'importance d'utiliser des fils de connexion droits pour une installation propre et assigner correctement les broches GPIO. Ensuite, la vidéo se concentre sur la programmation de la LED RVB en Python avec Thonny IDE, en modifiant le programme pour un contrôle PWM de chaque canal de couleur.

1. Introduction de la série de tutoriels sponsorisée par SunFounder pour les projets Raspberry Pi.
2. La tâche de l'épisode précédent était de créer une LED dimmable ; maintenant, il s'agit de la remplacer par une LED RVB.
3. Vue d'ensemble du circuit incluant la puce ADC0834, des potentiomètres et des résistances pour la configuration de la LED RVB.
4. Importance d'utiliser des fils de connexion droits pour une installation soignée et assignation des broches GPIO.
5. Programmation du contrôle de la LED RVB en utilisant Python et Thonny IDE pour la gestion PWM de chaque canal de couleur.
6. Configuration PWM sur le Raspberry Pi pour contrôler la LED RVB.
7. Initialisation de l'ADC0834 pour les lectures d'entrée analogique.
8. Lecture des valeurs analogiques de la puce ADC0834 pour déterminer la luminosité de la LED.
9. Conversion des valeurs analogiques en cycles de travail (duty cycle) pour un contrôle PWM précis.
10. Ajustement dynamique de la luminosité de la LED en fonction des valeurs d'entrée analogique.
11. Organisation du code et dépannage pour un contrôle efficace de la LED.

**Vidéo**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/7_XH4MbDPZ0?si=5UWA3VU-Z3mF5xu_" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>