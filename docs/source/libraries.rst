.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto da esperti**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni un accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi**: Partecipa a promozioni speciali e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

Librerie
============

Nella programmazione con Raspberry Pi vengono utilizzate due librerie importanti:
wiringPi e RPi.GPIO. Raspberry Pi OS le installa per impostazione predefinita,
quindi puoi usarle direttamente.

RPi.GPIO
------------

Se utilizzi Python, puoi programmare i GPIO tramite le API fornite da
RPi.GPIO.

RPi.GPIO è un modulo per controllare i canali GPIO del Raspberry Pi. Questo
pacchetto fornisce una classe per controllare i GPIO su Raspberry Pi. Per esempi
e documentazione, visita:
http://sourceforge.net/p/raspberry-gpio-python/wiki/Home/.

Per verificare se RPi.GPIO è installato o meno, digita in python:

.. raw:: html

    <run></run>

.. code-block:: 

    python

.. image:: img/image27.png


Nel prompt Python, inserisci \"import RPi.GPIO\". Se non viene visualizzato
alcun messaggio di errore, significa che RPi.GPIO è installato.


.. raw:: html

    <run></run>

.. code-block::

    import RPi.GPIO

.. image:: img/image28.png


Se vuoi uscire dal prompt Python, digita:


.. raw:: html

    <run></run>

.. code-block:: 

    exit()

.. image:: img/image29.png

.. _install_wiringpi:

Installare e Verificare WiringPi
-------------------------------------

``wiringPi`` è una libreria GPIO in linguaggio C utilizzata su Raspberry Pi.
È conforme alla licenza GNU Lv3. Le funzioni di wiringPi sono simili a quelle
del sistema di wiring di Arduino. Questo consente agli utenti che hanno
familiarità con Arduino di utilizzare wiringPi più facilmente.

``wiringPi`` include numerosi comandi GPIO che permettono di controllare
tutti i tipi di interfacce su Raspberry Pi.

Esegui il seguente comando per installare la libreria ``wiringPi``.


.. raw:: html

   <run></run>

.. code-block::

    sudo apt-get update
    git clone https://github.com/WiringPi/WiringPi
    cd WiringPi 
    ./build

Puoi verificare se la libreria wiringPi è stata installata correttamente
utilizzando il seguente comando.


.. raw:: html

    <run></run>

.. code-block::

    gpio -v

.. image:: img/image30.png

Controlla i GPIO con il seguente comando:

.. raw:: html

    <run></run>

.. code-block:: 

    gpio readall

.. image:: img/image31.png


Per maggiori dettagli su wiringPi, puoi fare riferimento a
`WiringPi <https://github.com/WiringPi/WiringPi>`_.


.. _create_virtual:

Creare un Ambiente Virtuale
----------------------------------------

Quando si utilizza un Raspberry Pi o dispositivi simili, è consigliato installare i pacchetti con ``pip`` all’interno di un ambiente virtuale. Questo approccio offre l’isolamento delle dipendenze, aumenta la sicurezza del sistema, mantiene il sistema pulito e facilita la migrazione e la condivisione dei progetti, semplificando la gestione delle dipendenze. Questi vantaggi rendono gli ambienti virtuali uno strumento estremamente importante e utile nello sviluppo Python.

Di seguito sono riportati i passaggi per creare un ambiente virtuale:

**1. Creare un ambiente virtuale**

Per prima cosa, assicurati che Python sia installato nel tuo sistema. Python versione 3.3 e successive includono il modulo ``venv`` per creare ambienti virtuali, eliminando la necessità di installazioni separate. Se stai utilizzando Python 2 o una versione precedente alla 3.3, dovrai installare ``virtualenv``.

* Per Python 3:

Python 3.3 e versioni successive possono utilizzare direttamente il modulo ``venv``:

.. raw:: html

    <run></run>

.. code-block:: shell

    python3 -m venv myenv

Questo creerà un ambiente virtuale chiamato ``myenv`` nella directory corrente.

* Per Python 2:

Se stai ancora utilizzando Python 2, devi prima installare ``virtualenv``:

.. raw:: html

    <run></run>

.. code-block:: shell

    pip install virtualenv

Successivamente, crea un ambiente virtuale:

.. raw:: html

    <run></run>

.. code-block:: shell

    virtualenv myenv

Anche questo creerà un ambiente virtuale chiamato ``myenv`` nella directory corrente.

**2. Attivare l’Ambiente Virtuale**

Dopo aver creato l’ambiente virtuale, è necessario attivarlo per poterlo utilizzare.

.. note::

    Ogni volta che riavvii il Raspberry Pi o apri un nuovo terminale, dovrai eseguire nuovamente il seguente comando per attivare l’ambiente virtuale.

.. raw:: html

    <run></run>

.. code-block:: shell

    source myenv/bin/activate

Una volta attivato l’ambiente virtuale, vedrai il nome dell’ambiente prima del prompt della riga di comando, indicando che stai lavorando all’interno dell’ambiente virtuale.


**3. Uscire dall’Ambiente Virtuale**

Quando hai completato il tuo lavoro e desideri uscire dall’ambiente virtuale, esegui semplicemente:

.. raw:: html

    <run></run>

.. code-block:: shell

    deactivate

Questo ti riporterà all’ambiente Python globale del sistema.

**4. Eliminare l’Ambiente Virtuale**

Se non hai più bisogno di un determinato ambiente virtuale, puoi semplicemente eliminare la directory che contiene l’ambiente virtuale:

.. raw:: html

    <run></run>

.. code-block:: shell

    rm -rf myenv