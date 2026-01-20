.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Únete a otros apasionados y profundiza en el mundo de Raspberry Pi, Arduino y ESP32.

    **¿Por qué unirte?**

    - **Soporte Experto**: Resuelve problemas posventa y supera desafíos técnicos con el apoyo de nuestra comunidad y equipo.
    - **Aprende y Comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso Exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos especiales.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy.

FAQ
============

.. _faq_c_nowork:

¿El código en C no funciona?
----------------------------------

* Verifica si hay problemas en el cableado.
* Comprueba si el código está mostrando errores. En tal caso, consulta: :ref:`install_wiringpi`.
* Asegúrate de que el código haya sido compilado antes de ejecutarlo.
* Si las tres condiciones anteriores están bien, es posible que la versión de wiringPi (2.50) no sea compatible con tu Raspberry Pi 4B o versiones superiores. Consulta :ref:`install_wiringpi` para actualizar manualmente a la versión 2.52.


.. _faq_soc:

Si ``gpiozero`` no funciona.
-------------------------------------------------------------------------

Nuestro tutorial de Python sobre los GPIO de la Raspberry Pi 5 se basa en la 
biblioteca gpiozero, y ha sido exhaustivamente probado durante el proceso de diseño.

Sin embargo, modificaciones recientes en el kernel de Linux de Raspberry Pi OS 
[1] han cambiado la forma en que se manejan las llamadas al sistema GPIO, 
lo que ha provocado que la biblioteca original de Python no pueda acceder a 
los GPIO en la Raspberry Pi 5. Nuestros desarrolladores han informado de este 
problema a los desarrolladores de gpiozero, quienes ya están al tanto del 
problema y trabajan activamente en una actualización [2].

* [1] https://github.com/raspberrypi/linux/pull/6144
* [2] https://github.com/gpiozero/gpiozero/issues/1166

Mientras tanto, hemos encontrado una solución temporal. Al ejecutar el siguiente comando, los GPIO funcionarán normalmente.

.. code-block::

    sudo ln -s gpiochip0 /dev/gpiochip4

Esta solución será efectiva hasta que la biblioteca gpiozero publique una actualización adecuada.

