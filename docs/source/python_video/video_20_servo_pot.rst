.. note::

    Bonjour et bienvenue dans la communauté SunFounder dédiée aux passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et surmontez les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des promotions spéciales lors des périodes de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !


Vidéo 20 : Contrôle de la position d’un servomoteur avec un potentiomètre
=======================================================================================

Cette vidéo montre comment contrôler la position d'un servomoteur à l'aide d'un potentiomètre et des broches GPIO du Raspberry Pi, en incluant des explications sur la configuration du circuit, le codage en Python, l'ADC, le PWM, les calculs mathématiques, la gestion des erreurs et l'importance des connexions.


#. **Configuration du circuit** : Révision du circuit d'entrée analogique de la leçon précédente en utilisant l'ADC0834 pour le Raspberry Pi.
#. **Installation du servomoteur** : Instructions pour l'ajout du servomoteur au circuit, y compris le câblage et les considérations d'alimentation.
#. **Comprendre l'ADC et le PWM** : Familiarisez-vous avec les concepts de convertisseur analogique-numérique (ADC) et de modulation de largeur d'impulsion (PWM).
#. **Lecture de signaux analogiques** : Découvrez comment lire les signaux analogiques provenant d'un potentiomètre connecté au Raspberry Pi.
#. **Calcul du pourcentage de PWM** : Apprenez la formule pour calculer le pourcentage de PWM à partir de la valeur du signal analogique obtenu.
#. **Contrôle d'un servomoteur** : Explorez le processus d'application du pourcentage de PWM calculé pour contrôler la position d'un servomoteur.
#. **Synchronisation** : Assurez la synchronisation entre la position du potentiomètre et celle du servomoteur pour un contrôle précis.
#. **Calculs mathématiques** : Explication des calculs mathématiques utilisés pour déterminer les valeurs de PWM basées sur les lectures du potentiomètre.
#. **Gestion des erreurs** : Implémentation de blocs try-except pour terminer correctement le programme et nettoyer les broches GPIO.
#. **Importance des connexions** : Comprenez l'importance d'établir des connexions fiables pour des lectures et des sorties précises.


**Vidéo**

.. raw:: html


    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/X6ZC-L02aEs?si=PXW8zKuYxtdiGJjE" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>

