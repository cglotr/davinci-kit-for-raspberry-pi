.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Remises spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Bibliothèques
=========================

Deux bibliothèques importantes sont utilisées pour la programmation avec le Raspberry Pi :  
wiringPi et RPi.GPIO. Le système Raspberry Pi OS les installe par défaut, vous pouvez donc les utiliser directement.

RPi.GPIO
------------

Si vous êtes un utilisateur Python, vous pouvez programmer les GPIO à l’aide des API fournies par RPi.GPIO.

RPi.GPIO est un module permettant de contrôler les canaux GPIO du Raspberry Pi. Ce paquet fournit une classe pour contrôler les GPIO sur un Raspberry Pi.  
Pour des exemples et de la documentation, veuillez consulter : http://sourceforge.net/p/raspberry-gpio-python/wiki/Home/.

Pour vérifier si RPi.GPIO est installé, tapez dans Python :

.. raw:: html

    <run></run>

.. code-block:: 

    python

.. image:: img/image27.png


Dans l’interface en ligne de commande Python, saisissez « import RPi.GPIO ».  
S’il n’y a aucun message d’erreur, cela signifie que RPi.GPIO est installé.


.. raw:: html

    <run></run>

.. code-block::

    import RPi.GPIO

.. image:: img/image28.png


Si vous souhaitez quitter l’interface Python, tapez :


.. raw:: html

    <run></run>

.. code-block:: 

    exit()

.. image:: img/image29.png

.. _install_wiringpi:

Installer et vérifier WiringPi
-------------------------------------

``wiringPi`` est une bibliothèque GPIO en langage C appliquée au Raspberry Pi.  
Elle est conforme à la licence GNU Lv3. Les fonctions de wiringPi sont similaires à celles du système de câblage d’Arduino, ce qui permet aux utilisateurs familiers avec Arduino d’utiliser wiringPi plus facilement.

``wiringPi`` inclut de nombreuses commandes GPIO qui vous permettent de contrôler toutes sortes d’interfaces sur le Raspberry Pi. 

Veuillez exécuter les commandes suivantes pour installer la bibliothèque ``wiringPi``.


.. raw:: html

   <run></run>

.. code-block::

    sudo apt-get update
    git clone https://github.com/WiringPi/WiringPi
    cd WiringPi 
    ./build

Vous pouvez tester si la bibliothèque wiringPi est installée correctement à l’aide de la commande suivante.


.. raw:: html

    <run></run>

.. code-block::

    gpio -v

.. image:: img/image30.png

Vérifiez les GPIO avec la commande suivante :

.. raw:: html

    <run></run>

.. code-block:: 

    gpio readall

.. image:: img/image31.png


Pour plus de détails sur wiringPi, vous pouvez consulter `WiringPi <https://github.com/WiringPi/WiringPi>`_.


.. _create_virtual:

Créer un environnement virtuel
----------------------------------------

Lors de l’utilisation d’un Raspberry Pi ou d’appareils similaires, il est recommandé d’installer les paquets avec ``pip`` dans un environnement virtuel. Cela permet l’isolation des dépendances, améliore la sécurité du système, maintient la propreté du système et facilite la migration et le partage des projets, simplifiant ainsi la gestion des dépendances. Ces avantages font des environnements virtuels un outil extrêmement important et utile dans le développement Python.

Voici les étapes pour créer un environnement virtuel :

**1. Créer un environnement virtuel**

Tout d’abord, vous devez vous assurer que Python est installé sur votre système. Les versions Python 3.3 et ultérieures incluent le module ``venv`` pour créer des environnements virtuels, ce qui évite toute installation supplémentaire. Si vous utilisez Python 2 ou une version antérieure à Python 3.3, vous devrez installer ``virtualenv``.

* Pour Python 3 :

Les versions Python 3.3 et ultérieures peuvent utiliser directement le module ``venv`` :

.. raw:: html

    <run></run>

.. code-block:: shell

    python3 -m venv myenv

Cela créera un environnement virtuel nommé ``myenv`` dans le répertoire courant.

* Pour Python 2 :

Si vous utilisez encore Python 2, vous devez d’abord installer ``virtualenv`` :

.. raw:: html

    <run></run>

.. code-block:: shell

    pip install virtualenv

Ensuite, créez un environnement virtuel :

.. raw:: html

    <run></run>

.. code-block:: shell

    virtualenv myenv

Cela crée également un environnement virtuel nommé ``myenv`` dans le répertoire courant.

**2. Activer l’environnement virtuel**

Après avoir créé l’environnement virtuel, vous devez l’activer pour l’utiliser.

.. note::

    Chaque fois que vous redémarrez le Raspberry Pi ou ouvrez un nouveau terminal, vous devrez exécuter à nouveau la commande suivante pour activer l’environnement virtuel.

.. raw:: html

    <run></run>

.. code-block:: shell

    source myenv/bin/activate

Une fois l’environnement virtuel activé, vous verrez le nom de l’environnement apparaître avant l’invite de commande, indiquant que vous travaillez dans l’environnement virtuel.


**3. Quitter l’environnement virtuel**

Lorsque vous avez terminé votre travail et souhaitez quitter l’environnement virtuel, exécutez simplement :

.. raw:: html

    <run></run>

.. code-block:: shell

    deactivate

Cela vous ramènera à l’environnement Python global du système.

**4. Supprimer l’environnement virtuel**

Si vous n’avez plus besoin d’un environnement virtuel particulier, vous pouvez simplement supprimer le répertoire contenant l’environnement virtuel :

.. raw:: html

    <run></run>

.. code-block:: shell

    rm -rf myenv