.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino & ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Scaricare il Codice
==================================

Tutti i programmi di esempio utilizzati in questo kit sono archiviati nel nostro repository ufficiale su GitHub.  
Usa il seguente comando per scaricare l’intero progetto sul tuo Raspberry Pi.

Clonare il Repository
-------------------------------

#. Accedi al tuo Raspberry Pi ed esegui:

   .. raw:: html
   
       <run></run>
   
   .. code-block:: bash
   
      cd ~/
      git clone https://github.com/sunfounder/davinci-kit-for-raspberry-pi.git --depth 1

#. Entra nella directory del progetto:

   .. raw:: html
   
       <run></run>
   
   .. code-block:: bash
   
      cd ~/davinci-kit-for-raspberry-pi/

#. Elenca i file:

   .. raw:: html
   
       <run></run>
   
   .. code-block:: bash
   
      ls

#. Vedrai una struttura simile alla seguente:

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

Panoramica della Struttura del Progetto
----------------------------------------------------

Ecco una breve introduzione a ciascuna cartella:

* **c/**  

  Esempi e librerie in linguaggio C per gli utenti che preferiscono programmare in C su Raspberry Pi.

* **datasheet/**  

  Datasheet, specifiche e documenti di riferimento per i componenti hardware utilizzati nel progetto.

* **iot/**  

  Esempi relativi all’IoT, inclusa la connettività con la piattaforma Blynk, dimostrazioni di sensori e moduli di comunicazione.

* **nodejs/**

  Esempi Node.js per gli utenti che sviluppano progetti basati su JavaScript su Raspberry Pi.

* **python-pi5/**  

  Esempi Python scritti utilizzando la libreria ``GPIO Zero``, ottimizzati specificamente per **Raspberry Pi 5**.

* **python/**  

  Programmi di esempio Python scritti utilizzando la libreria ``RPi.GPIO``, adatti alla maggior parte delle schede Raspberry Pi.

* **scratch/** 

  Esempi di programmazione Scratch progettati per i principianti che imparano la programmazione grafica.

* **README.md**  

  Informazioni di base sul repository e istruzioni generali.

Ora puoi entrare nella cartella corrispondente al linguaggio di programmazione o al tipo di progetto che preferisci e iniziare a eseguire gli esempi.
