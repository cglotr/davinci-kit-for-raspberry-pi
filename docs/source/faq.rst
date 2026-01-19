.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Remises spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

FAQ
============

.. _faq_c_nowork:

Le code C ne fonctionne pas ?
----------------------------------

* Vérifiez votre câblage pour détecter d'éventuels problèmes.
* Vérifiez si le code affiche des erreurs. Si c'est le cas, référez-vous à : :ref:`install_wiringpi`.
* Assurez-vous que le code a été compilé avant de le lancer.
* Si les trois points précédents sont corrects, il se peut que la version de votre wiringPi (2.50) ne soit pas compatible avec votre Raspberry Pi 4B ou supérieur. Consultez :ref:`install_wiringpi` pour le mettre à jour manuellement vers la version 2.52.

.. _faq_soc:

Si ``gpiozero`` ne fonctionne pas.
-------------------------------------------------------------------------

Notre tutoriel Python pour le GPIO du Raspberry Pi 5 est basé sur la bibliothèque 
gpiozero, et a été minutieusement testé durant la phase de conception.

Cependant, des modifications récentes du noyau Linux sur le Raspberry Pi OS [1] 
ont modifié la gestion des appels système GPIO, ce qui a empêché la bibliothèque 
Python originale d'accéder au GPIO sur le Raspberry Pi 5. Nos développeurs ont 
signalé ce problème aux responsables de la bibliothèque gpiozero, qui en sont 
conscients et travaillent activement sur une mise à jour [2].

* [1] https://github.com/raspberrypi/linux/pull/6144
* [2] https://github.com/gpiozero/gpiozero/issues/1166

En attendant,
nous avons trouvé une solution temporaire : en exécutant la commande ci-dessous, 
le GPIO fonctionnera normalement.

.. code-block::

    sudo ln -s gpiochip0 /dev/gpiochip4

Cette solution restera efficace jusqu'à ce que la bibliothèque gpiozero publie une mise à jour appropriée.
