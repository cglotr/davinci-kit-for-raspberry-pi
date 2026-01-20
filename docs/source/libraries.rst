.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Únete a otros apasionados y profundiza en el mundo de Raspberry Pi, Arduino y ESP32.

    **¿Por qué unirte?**

    - **Soporte Experto**: Resuelve problemas posventa y supera desafíos técnicos con el apoyo de nuestra comunidad y equipo.
    - **Aprende y Comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso Exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos especiales.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy.

Libraries
============

En la programación con Raspberry Pi se utilizan dos bibliotecas importantes:
wiringPi y RPi.GPIO. Raspberry Pi OS las instala de forma predeterminada,
por lo que puedes usarlas directamente.

RPi.GPIO
------------

Si eres usuario de Python, puedes programar los GPIO con la API que ofrece
RPi.GPIO.

RPi.GPIO es un módulo para controlar los canales GPIO de Raspberry Pi. Este paquete
proporciona una clase para controlar los GPIO en una Raspberry Pi. Para ejemplos y
documentación, visita: http://sourceforge.net/p/raspberry-gpio-python/wiki/Home/.

Para comprobar si RPi.GPIO está instalado o no, escribe en python:

.. raw:: html

    <run></run>

.. code-block:: 

    python

.. image:: img/image27.png


En la CLI de Python, introduce \"import RPi.GPIO\". Si no aparece ningún error, significa
que RPi.GPIO está instalado.


.. raw:: html

    <run></run>

.. code-block::

    import RPi.GPIO

.. image:: img/image28.png


Si quieres salir de la CLI de Python, escribe:


.. raw:: html

    <run></run>

.. code-block:: 

    exit()

.. image:: img/image29.png

.. _install_wiringpi:

Instalar y Comprobar WiringPi
-------------------------------------

``wiringPi`` es una biblioteca de lenguaje C para GPIO aplicada a Raspberry Pi. Cumple con GUN Lv3. Las funciones de wiringPi son
similares a las del sistema de cableado de Arduino. Esto permite que los usuarios
familiarizados con Arduino puedan usar wiringPi más fácilmente.

``wiringPi`` incluye muchos comandos GPIO que te permiten controlar todo
tipo de interfaces en Raspberry Pi. 

Ejecuta el siguiente comando para instalar la biblioteca ``wiringPi``.


.. raw:: html

   <run></run>

.. code-block::

    sudo apt-get update
    git clone https://github.com/WiringPi/WiringPi
    cd WiringPi 
    ./build

Puedes comprobar si la biblioteca wiringPi
se instaló correctamente con la siguiente instrucción.


.. raw:: html

    <run></run>

.. code-block::

    gpio -v

.. image:: img/image30.png

Comprueba los GPIO con el siguiente comando:

.. raw:: html

    <run></run>

.. code-block:: 

    gpio readall

.. image:: img/image31.png


Para más detalles sobre wiringPi, puedes consultar `WiringPi <https://github.com/WiringPi/WiringPi>`_.


.. _create_virtual:

Creación de un Entorno Virtual
----------------------------------------

Al usar Raspberry Pi u otros dispositivos similares, se recomienda instalar los paquetes con ``pip`` dentro de un entorno virtual. Esto ofrece aislamiento de dependencias, aumenta la seguridad del sistema, mantiene el sistema limpio y facilita la migración y el uso compartido de proyectos, simplificando la gestión de dependencias. Estos beneficios hacen que los entornos virtuales sean una herramienta extremadamente importante y útil en el desarrollo en Python.

A continuación se muestran los pasos para crear un entorno virtual:

**1. Crear un entorno virtual**

Primero, debes asegurarte de que tu sistema tenga Python instalado. Las versiones de Python 3.3 y posteriores incluyen el módulo ``venv`` para crear entornos virtuales, eliminando la necesidad de una instalación adicional. Si estás usando Python 2 o una versión anterior a Python 3.3, necesitarás instalar ``virtualenv``.

* Para Python 3:

Las versiones de Python 3.3 y posteriores pueden usar directamente el módulo ``venv``:

.. raw:: html

    <run></run>

.. code-block:: shell

    python3 -m venv myenv

Esto creará un entorno virtual llamado ``myenv`` en el directorio actual.

* Para Python 2:

Si aún estás usando Python 2, primero necesitas instalar ``virtualenv``:

.. raw:: html

    <run></run>

.. code-block:: shell

    pip install virtualenv

Luego, crea un entorno virtual:

.. raw:: html

    <run></run>

.. code-block:: shell

    virtualenv myenv

Esto también crea un entorno virtual llamado ``myenv`` en el directorio actual.

**2. Activar el Entorno Virtual**

Después de crear el entorno virtual, necesitas activarlo para poder usarlo.

.. note::

    Cada vez que reinicies la Raspberry Pi o abras una nueva terminal, deberás ejecutar nuevamente el siguiente comando para activar el entorno virtual.

.. raw:: html

    <run></run>

.. code-block:: shell

    source myenv/bin/activate

Una vez activado el entorno virtual, verás el nombre del entorno antes del símbolo del prompt de la línea de comandos, lo que indica que estás trabajando dentro del entorno virtual.


**3. Salir del Entorno Virtual**

Cuando hayas terminado tu trabajo y desees salir del entorno virtual, simplemente ejecuta:

.. raw:: html

    <run></run>

.. code-block:: shell

    deactivate

Esto te devolverá al entorno global de Python del sistema.

**4. Eliminar el Entorno Virtual**

Si ya no necesitas un entorno virtual en particular, simplemente puedes eliminar el directorio que contiene el entorno virtual:

.. raw:: html

    <run></run>

.. code-block:: shell

    rm -rf myenv