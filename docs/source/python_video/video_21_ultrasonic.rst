.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Profundiza en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte Experto**: Resuelve problemas post-venta y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y Comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Preestrenos Exclusivos**: Accede antes que nadie a anuncios de nuevos productos y avances.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y Sorteos Festivos**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? ¡Haz clic en [|link_sf_facebook|] y únete hoy mismo!


Video 21: Uso de un Sensor Ultrasónico HC-SR04 para Ecolocación
=======================================================================================

Este tutorial cubre el proceso para crear un sensor de distancia ultrasónico con un Raspberry Pi utilizando el sensor HC-SR04. 
En este video se explican los principios de la ecolocación, se presentan los componentes necesarios, se demuestra la configuración del cableado 
y se recorre el proceso de programación paso a paso. 
Se enfatiza la importancia de la precisión en la ejecución del código para obtener mediciones de distancia exactas y promueve buenas prácticas de ingeniería.

1. **Introducción a la Ecolocación**: Uso del sonido para detectar la posición de objetos, inspirado en murciélagos y ballenas.
2. **Descripción de Componentes**: Introducción al sensor ultrasónico HC-SR04 y su conexión al Raspberry Pi.
3. **Configuración de Cableado**: Conexión del sensor HC-SR04 a los pines GPIO del Raspberry Pi para alimentación, tierra, disparador y eco.
4. **Proceso de Programación**: Recorrido del código en Python para generar pulsos ultrasónicos, activar el sensor y medir el tiempo de retorno del eco.
5. **Consideraciones de Tiempo**: Importancia de la precisión en el tiempo para una medición de distancia exacta.
6. **Buenas Prácticas de Ingeniería**: Subrayar la planificación y comprensión del código antes de la implementación.
7. **Esperando el Pin de Eco**: Utilización de un bucle while para esperar que el pin de eco se active.
8. **Registro del Tiempo de Inicio**: Captura del tiempo del sistema cuando el pin de eco se activa para marcar el inicio de la medición.
9. **Medición del Tiempo de Viaje del Pulso**: Cálculo del tiempo de viaje del pulso determinando la diferencia entre la activación y desactivación del pin de eco.
10. **Conversión de Unidades**: Multiplicación del tiempo de viaje del pulso por un millón para mejorar su legibilidad.
11. **Añadir Retraso**: Introducción de un retraso después de cada medición para evitar ecos múltiples.
12. **Cálculo de la Distancia**: Uso de la velocidad del sonido y del tiempo de viaje del pulso para calcular la distancia al objetivo.


**Video**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/SoAGLXoQ5XI?si=OPMqLtQ53hKNHs4j" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>