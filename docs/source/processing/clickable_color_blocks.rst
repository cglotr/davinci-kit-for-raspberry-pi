.. note::

    Bonjour, bienvenue dans la communauté SunFounder dédiée aux passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez vos problèmes après-vente et relevez vos défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et à des promotions spéciales lors des périodes de fête.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Blocs de Couleurs Cliquables
================================

Nous avons déjà essayé de dessiner un point cliquable pour contrôler la LED, alors allons plus loin et dessinons 3 carrés colorés pour ajuster les couleurs RVB !

.. image:: img/colorful_square.png

**Câblage**

.. image:: img/image61.png

**Code**

.. code-block:: arduino

    import processing.io.*; // utiliser la bibliothèque GPIO

    int[] pins = { 17, 18, 27 };

    void setup() {
        for (int i = 0; i < pins.length; i++) {
            GPIO.pinMode(pins[i], GPIO.OUTPUT);
        }
        size(300, 100);
        background(255);
    }

    void draw() {
        fill(255, 0, 0);
        rect(0, 0, width/3, height);

        fill(0,255,0);
        rect(width/3, 0, 2*width/3, height);

        fill(0,0,255);
        rect(2*width/3, 0, width, height);
    }

    void mouseClicked() {
        for (int i = 0; i < pins.length; i++) {
            GPIO.digitalWrite(pins[i],GPIO.LOW);
        }
        if (mouseX<width/3){
            GPIO.digitalWrite(pins[0],GPIO.HIGH);
        }else if (mouseX>width/3&&mouseX<2*width/3){
            GPIO.digitalWrite(pins[1],GPIO.HIGH);
        }else if (mouseX>2*width/3){
            GPIO.digitalWrite(pins[2],GPIO.HIGH);
        }        
    }

**Comment ça fonctionne ?**

Ce projet est très similaire au :ref:`clickable_dot`, à la différence qu'il affine les conditions de détermination de l'événement de clic de la souris.

On dessine d'abord trois blocs de couleur dans la fonction ``draw()``, puis on détermine quel bloc de couleur a été cliqué en se basant sur la valeur de ``mouseX`` (la coordonnée X de la souris). Ensuite, on allume la couleur correspondante de la LED RVB.

**Et si on allait plus loin ?**

En utilisant l'addition des couleurs, nous pouvons faire afficher sept couleurs différentes à la LED RVB : ajouter du rouge au vert donne du jaune ; combiner les trois couleurs primaires donne du blanc. Maintenant, c'est à vous d'essayer !

Pour plus d'informations, veuillez consulter la `Processing Reference <https://processing.org/reference/>`_.
