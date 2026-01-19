.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l’univers du Raspberry Pi, Arduino et ESP32 avec d’autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d’experts** : Résolvez vos problèmes après-vente et relevez des défis techniques avec l’aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et bénéficiez d’aperçus privilégiés.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions spéciales et à des tirages au sort.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

.. _show_number_processing:

Show Number
=============================================

Dans cette leçon, nous utilisons Processing pour contrôler un afficheur 7 segments 
afin d’afficher un chiffre de 0 à 9 ainsi que les lettres de A à F.

**Câblage**

.. image:: img/image125.png

**Code**

.. code-block:: arduino

    import processing.io.*;

    int SDI = 17;   // Entrée de données série
    int RCLK = 18;  // Entrée de l'horloge de mémoire (STCP)
    int SRCLK = 27; // Entrée de l'horloge du registre de décalage (SHCP)

	int[] SegCode= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

	void hc595_shift(int dat){
        int i;

	  for(i=0;i<8;i++){
		int n=(0x80 & (dat << i)); 
		if ( n==0){
                GPIO.digitalWrite(SDI, 0);
            } else {
                GPIO.digitalWrite(SDI, 1);
            }
            GPIO.digitalWrite(SRCLK, 1);
            delay(1);
            GPIO.digitalWrite(SRCLK, 0);
        }

        GPIO.digitalWrite(RCLK, 1);
        delay(1);
        GPIO.digitalWrite(RCLK, 0);
    }

    void setup() {
        size(400, 200);
        frameRate(10);
        
        GPIO.pinMode(SDI, GPIO.OUTPUT); 
        GPIO.pinMode(RCLK, GPIO.OUTPUT); 
        GPIO.pinMode(SRCLK, GPIO.OUTPUT); 
      
        GPIO.digitalWrite(SDI, 0);
        GPIO.digitalWrite(RCLK, 0);
        GPIO.digitalWrite(SRCLK, 0);
        
		fill(0,25,88);
		textAlign(CENTER,CENTER);
		textSize(height*0.8);
    }

    void draw() {

        background(255);
		int number = (frameCount%100)/10;
		text(number, width/2, height/2);
        hc595_shift(SegCode[number]);
    }

**Comment ça fonctionne ?**

Importez ``processing.io.*`` et utilisez la bibliothèque de fonctions GPIO pour contrôler les broches de l’afficheur numérique.

Définissez le tableau ``SegCode = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71}``, qui représente les codes des segments de 0 à F en Hexadécimal (cathode commune).

La fonction ``setup()`` configure les trois broches SDI, RCLK et SRCLK comme sorties, et initialise les données à 0.

La fonction ``hc595_shift(int dat)`` permet de transférer les valeurs du tableau ``SegCode`` vers le circuit intégré 74HC595.

.. code::

	void hc595_shift(int dat){
        int i;

	  for(i=0;i<8;i++){
		int n=(0x80 & (dat << i));
		if ( n==0){
                GPIO.digitalWrite(SDI, 0);
            } else {
                GPIO.digitalWrite(SDI, 1);
            }
            GPIO.digitalWrite(SRCLK, 1);
            delay(1);
            GPIO.digitalWrite(SRCLK, 0);
        }

		GPIO.digitalWrite(RCLK, 1);
		delay(1);
		GPIO.digitalWrite(RCLK, 0);
	}
 
``n = (0x80 & (dat << i))`` signifie que ``dat`` est décalé de ``i`` bits vers la gauche, puis l'opération ``&`` est effectuée avec 0x80.

La règle de l'opérateur ``&`` est que le résultat est 1 lorsque les deux bits comparés valent 1, sinon le résultat est 0.

Par exemple, supposons ``dat = 0x3f`` et ``i = 2`` (0011 1111 << 2 devient 1111 1100), alors 1111 1100 & 1000 0000 (0x80) = 1000 0000.

Enfin, la valeur de ``dat`` est affectée bit par bit à ``SDI`` (DS).

``digitalWrite(SRCLK, 1)`` : lorsque SRCLK génère une impulsion montante (passage de 0 à 1), les données sont transférées du registre DS au registre de décalage ;

``digitalWrite(RCLK, 1)`` : lorsque RCLK génère une impulsion montante (passage de 0 à 1), les données sont transférées du registre de décalage au registre de stockage.

.. code::

	fill(0,25,88);
	textAlign(CENTER,CENTER);
	textSize(height*0.8);

* ``fill()`` : Définit la couleur utilisée pour remplir les formes.
* ``textAlign(CENTER, CENTER)`` : Définit l'alignement du texte. Les paramètres ``LEFT``, ``CENTER`` et ``RIGHT`` déterminent l'affichage du texte par rapport aux valeurs x et y passées en paramètres de la fonction ``text()``.
* ``textSize()`` : Définit la taille actuelle de la police. Cette taille sera appliquée à tous les appels ultérieurs de la fonction ``text()``. La taille de la police est mesurée en pixels.

Ces fonctions permettent de personnaliser le style du texte affiché dans Processing.

.. code::

	void draw() {

		background(255);
		int number = (frameCount%100)/10;
		text(number, width/2, height/2);
		hc595_shift(SegCode[number]);
	}

La variable ``frameCount`` agit comme une base de temps, et est liée à ``frameRate``.
Par défaut, ``frameRate`` est de 60, ce qui signifie que ``frameCount`` s'incrémente 60 fois par seconde.

Ainsi, nous pouvons utiliser Processing et l'afficheur 7 segments pour afficher simultanément les chiffres de 0 à 9 et les lettres de A à F.

Pour plus d'informations, consultez la `Processing Reference <https://processing.org/reference/>`_.
