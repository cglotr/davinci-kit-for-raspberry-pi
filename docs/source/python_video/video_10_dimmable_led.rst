.. note::

    Ciao, benvenuto nella Community di SunFounder per gli appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Unisciti a noi per esplorare in profondità Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anticipo agli annunci di nuovi prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a promozioni e omaggi in occasione delle festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!


Video 10: Creare un LED Dimmerabile con Due Pulsanti
=======================================================================================

Questo tutorial guida alla costruzione di un circuito LED dimmerabile usando i pin 
GPIO del Raspberry Pi, concentrandosi sul controllo fluido della 
luminosità. Paul McQuarter dimostra passo passo il processo, dalla configurazione 
del circuito all'implementazione del codice. Nella sezione dedicata al Raspberry Pi, 
spiega come costruire il circuito utilizzando i pin GPIO e i pulsanti per il controllo, 
insieme alla programmazione in Python per il controllo della PWM (Modulazione di Larghezza 
di Impulso). Il video esplora le sfumature della PWM, sottolineando le variazioni non lineari 
del ciclo di lavoro per ottenere transizioni di luminosità più omogenee e affrontando i problemi di sincronizzazione tra la frequenza della PWM e il tasso di scansione della fotocamera. Introduce inoltre il concetto di scala esponenziale per ottenere un controllo fluido e preciso della luminosità. Vengono approfonditi concetti matematici come logaritmi ed esponenti, illustrando la loro applicazione nel codice per il controllo della luminosità del LED. Sono forniti consigli per la risoluzione dei problemi e il miglioramento del codice per garantire prestazioni ottimali.

1. **Configurazione del circuito**: Spiegazione e dimostrazione della costruzione di circuiti LED dimmerabili con i pin GPIO del Raspberry Pi, utilizzando pulsanti per il controllo.
2. **Programmazione Python**: Guida al codice Python per implementare il controllo PWM e la scala esponenziale per il controllo della luminosità del LED.
3. **Principi della PWM**: Comprendere il ciclo di lavoro della PWM e la sua applicazione nel controllo della luminosità del LED.
4. **Scala esponenziale**: Utilizzo della scala esponenziale nel codice per ottenere un controllo della luminosità fluido e lineare.
5. **Concetto logaritmico**: Applicazione dei logaritmi per determinare la costante necessaria per un numero specifico di pressioni dei pulsanti per la regolazione della luminosità.
6. **Regolazione non lineare della luminosità**: Esplorare le variazioni non lineari del ciclo di lavoro per transizioni di luminosità più morbide.
7. **Problemi di sincronizzazione**: Affrontare i problemi di sincronizzazione tra la frequenza della PWM e il tasso di scansione della fotocamera.
8. **Risoluzione dei problemi e perfezionamento**: Tecniche per il debug del codice e il miglioramento della funzionalità di dimming del LED per prestazioni ottimali.

**Video**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/2QAn1e8U5ho?si=1aWOugdV2_4pIO9N" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>


