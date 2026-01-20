.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Bibliotheken
============

Bei der Programmierung mit dem Raspberry Pi werden zwei wichtige Bibliotheken verwendet,
nämlich wiringPi und RPi.GPIO. Das Raspberry Pi OS installiert sie standardmäßig,
sodass Sie sie direkt verwenden können.

RPi.GPIO
------------

Wenn Sie Python verwenden, können Sie die GPIOs mit der von
RPi.GPIO bereitgestellten API programmieren.

RPi.GPIO ist ein Modul zur Steuerung der GPIO-Kanäle des Raspberry Pi. Dieses Paket
stellt eine Klasse zur Verfügung, mit der die GPIOs auf einem Raspberry Pi gesteuert
werden können. Beispiele und Dokumentationen finden Sie unter:
http://sourceforge.net/p/raspberry-gpio-python/wiki/Home/.

Um zu testen, ob RPi.GPIO installiert ist, geben Sie in Python Folgendes ein:

.. raw:: html

    <run></run>

.. code-block:: 

    python

.. image:: img/image27.png


Geben Sie in der Python-CLI „import RPi.GPIO“ ein. Wenn keine Fehlermeldung erscheint,
bedeutet dies, dass RPi.GPIO installiert ist.


.. raw:: html

    <run></run>

.. code-block::

    import RPi.GPIO

.. image:: img/image28.png


Wenn Sie die Python-CLI verlassen möchten, geben Sie Folgendes ein:


.. raw:: html

    <run></run>

.. code-block:: 

    exit()

.. image:: img/image29.png

.. _install_wiringpi:

Installieren und Überprüfen von WiringPi
-------------------------------------

``wiringPi`` ist eine in C geschriebene GPIO-Bibliothek für den Raspberry Pi. Sie entspricht
der GNU Lv3-Lizenz. Die Funktionen von wiringPi sind denen des Arduino-Wiring-Systems
ähnlich. Dadurch können Benutzer, die mit Arduino vertraut sind, wiringPi leichter verwenden.

``wiringPi`` enthält zahlreiche GPIO-Befehle, mit denen Sie alle Arten von Schnittstellen
auf dem Raspberry Pi steuern können. 

Bitte führen Sie die folgenden Befehle aus, um die ``wiringPi``-Bibliothek zu installieren.


.. raw:: html

   <run></run>

.. code-block::

    sudo apt-get update
    git clone https://github.com/WiringPi/WiringPi
    cd WiringPi 
    ./build

Sie können mit dem folgenden Befehl testen, ob die wiringPi-Bibliothek
erfolgreich installiert wurde.


.. raw:: html

    <run></run>

.. code-block::

    gpio -v

.. image:: img/image30.png

Überprüfen Sie die GPIOs mit dem folgenden Befehl:

.. raw:: html

    <run></run>

.. code-block:: 

    gpio readall

.. image:: img/image31.png


Weitere Details zu wiringPi finden Sie unter `WiringPi <https://github.com/WiringPi/WiringPi>`_.


.. _create_virtual:

Erstellen einer virtuellen Umgebung
----------------------------------------

Bei der Verwendung eines Raspberry Pi oder ähnlicher Geräte wird empfohlen, Pakete mit ``pip`` in einer virtuellen Umgebung zu installieren. Dies ermöglicht eine Isolation von Abhängigkeiten, erhöht die Systemsicherheit, hält das System sauber und erleichtert die Migration und Weitergabe von Projekten, wodurch die Verwaltung von Abhängigkeiten vereinfacht wird. Diese Vorteile machen virtuelle Umgebungen zu einem äußerst wichtigen und nützlichen Werkzeug in der Python-Entwicklung.

Nachfolgend finden Sie die Schritte zum Erstellen einer virtuellen Umgebung:

**1. Erstellen einer virtuellen Umgebung**

Zunächst müssen Sie sicherstellen, dass auf Ihrem System Python installiert ist. Python ab Version 3.3 enthält bereits das Modul ``venv`` zur Erstellung virtueller Umgebungen, sodass keine separate Installation erforderlich ist. Wenn Sie Python 2 oder eine Version vor Python 3.3 verwenden, müssen Sie ``virtualenv`` installieren.

* Für Python 3:

Python-Versionen ab 3.3 können direkt das Modul ``venv`` verwenden:

.. raw:: html

    <run></run>

.. code-block:: shell

    python3 -m venv myenv

Dadurch wird im aktuellen Verzeichnis eine virtuelle Umgebung mit dem Namen ``myenv`` erstellt.

* Für Python 2:

Wenn Sie noch Python 2 verwenden, müssen Sie zunächst ``virtualenv`` installieren:

.. raw:: html

    <run></run>

.. code-block:: shell

    pip install virtualenv

Erstellen Sie anschließend eine virtuelle Umgebung:

.. raw:: html

    <run></run>

.. code-block:: shell

    virtualenv myenv

Auch hier wird im aktuellen Verzeichnis eine virtuelle Umgebung mit dem Namen ``myenv`` erstellt.

**2. Aktivieren der virtuellen Umgebung**

Nach dem Erstellen der virtuellen Umgebung müssen Sie diese aktivieren, um sie zu verwenden.

.. note::

    Jedes Mal, wenn Sie den Raspberry Pi neu starten oder ein neues Terminal öffnen, müssen Sie den folgenden Befehl erneut ausführen, um die virtuelle Umgebung zu aktivieren.

.. raw:: html

    <run></run>

.. code-block:: shell

    source myenv/bin/activate

Sobald die virtuelle Umgebung aktiviert ist, sehen Sie den Namen der Umgebung vor der Eingabeaufforderung, was anzeigt, dass Sie innerhalb der virtuellen Umgebung arbeiten.


**3. Beenden der virtuellen Umgebung**

Wenn Sie Ihre Arbeit abgeschlossen haben und die virtuelle Umgebung verlassen möchten, führen Sie einfach Folgendes aus:

.. raw:: html

    <run></run>

.. code-block:: shell

    deactivate

Dadurch kehren Sie zur globalen Python-Umgebung des Systems zurück.

**4. Löschen der virtuellen Umgebung**

Wenn Sie eine bestimmte virtuelle Umgebung nicht mehr benötigen, können Sie einfach das Verzeichnis löschen, das die virtuelle Umgebung enthält:

.. raw:: html

    <run></run>

.. code-block:: shell

    rm -rf myenv