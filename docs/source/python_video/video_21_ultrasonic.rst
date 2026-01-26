.. note::

    Bonjour et bienvenue dans la communauté SunFounder dédiée aux passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour développer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et à des aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et à des promotions spéciales lors des périodes de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Vidéo 21 : Utilisation d'un capteur ultrasonique HC-SR04 pour l'écholocalisation
=======================================================================================

Ce tutoriel explique comment créer un capteur de distance à ultrasons avec un Raspberry 
Pi en utilisant le capteur HC-SR04. La vidéo présente les principes de l'écholocalisation, 
introduit les composants nécessaires, montre la configuration du câblage et détaille étape 
par étape le processus de codage. L'accent est mis sur l'importance d'une synchronisation 
précise dans l'exécution du code pour obtenir des mesures de distance précises et sur 
l'application de bonnes pratiques d'ingénierie.

1. **Introduction à l'écholocalisation** : Utilisation du son pour détecter la position des objets, inspirée par les chauves-souris et les baleines.
2. **Présentation des composants** : Introduction au capteur ultrasonique HC-SR04 et connexion au Raspberry Pi.
3. **Configuration du câblage** : Connexion du capteur HC-SR04 aux broches GPIO du Raspberry Pi pour l'alimentation, la masse, le déclenchement et l'écho.
4. **Processus de codage** : Explication du code Python pour générer des impulsions ultrasoniques, activer le capteur et mesurer le temps de retour de l'écho.
5. **Considérations temporelles** : Importance d'une synchronisation précise pour mesurer la distance avec exactitude.
6. **Bonnes pratiques d'ingénierie** : Insistance sur la planification et la compréhension du code avant sa mise en œuvre.
7. **Attente du signal Echo** : Utilisation d'une boucle `while` pour attendre que la broche Echo passe à l'état haut.
8. **Enregistrement du temps de départ** : Capture de l'heure système lorsque la broche Echo passe à l'état haut pour marquer le début de la mesure.
9. **Mesure du temps de trajet du ping** : Calcul du temps de trajet du ping en déterminant la différence de temps entre l'état haut et bas de la broche Echo.
10. **Conversion des unités** : Multiplication du temps de trajet du ping par un million pour une meilleure lisibilité.
11. **Ajout d'un délai** : Introduction d'un délai après chaque mesure pour éviter les échos multiples.
12. **Calcul de la distance** : Utilisation de la vitesse du son et du temps de trajet du ping pour calculer la distance par rapport à la cible.


**Vidéo**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/SoAGLXoQ5XI?si=OPMqLtQ53hKNHs4j" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>