.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

Libraries
============

Two important libraries are used in programming with Raspberry Pi, and
they are wiringPi and RPi.GPIO. The Raspberry Pi OS installs them by
default, so you can use them directly.

RPi.GPIO
------------

If you are a Python user, you can program GPIOs with API provided by
RPi.GPIO.

RPi.GPIO is a module to control Raspberry Pi GPIO channels. This package
provides a class to control the GPIO on a Raspberry Pi. For examples and
documents, visit: http://sourceforge.net/p/raspberry-gpio-python/wiki/Home/.

Test whether RPi.GPIO is installed or not, type in python:

.. raw:: html

    <run></run>

.. code-block:: 

    python

.. image:: img/image27.png


In Python CLI, input \"import RPi.GPIO\", If no error prompts, it means
RPi.GPIO is installed.


.. raw:: html

    <run></run>

.. code-block::

    import RPi.GPIO

.. image:: img/image28.png


If you want to quit python CLI, type in:


.. raw:: html

    <run></run>

.. code-block:: 

    exit()

.. image:: img/image29.png

.. _install_wiringpi:

Install and Check the WiringPi
-------------------------------------

``wiringPi`` is a C language GPIO library applied to the Raspberry Pi. It complies with GUN Lv3. The functions in wiringPi are
similar to those in the wiring system of Arduino. They enable the users
familiar with Arduino to use wiringPi more easily.

``wiringPi`` includes lots of GPIO commands which enable you to control all
kinds of interfaces on Raspberry Pi. 

Please run the following command to install ``wiringPi`` library.


.. raw:: html

   <run></run>

.. code-block::

    sudo apt-get update
    git clone https://github.com/WiringPi/WiringPi
    cd WiringPi 
    ./build

You can test whether the wiringPi
library is installed successfully or not by the following instruction.


.. raw:: html

    <run></run>

.. code-block::

    gpio -v

.. image:: img/image30.png

Check the GPIO with the following command:

.. raw:: html

    <run></run>

.. code-block:: 

    gpio readall

.. image:: img/image31.png


For more details about wiringPi, you can refer to `WiringPi <https://github.com/WiringPi/WiringPi>`_.


.. _create_virtual:

Creating a Virtual Environment
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

When using Raspberry Pi or similar devices, it is recommended to install packages with ``pip`` in a virtual environment. It offers dependency isolation, increases system security, maintains system cleanliness, and facilitates project migration and sharing, simplifying dependency management. These benefits make virtual environments an extremely important and useful tool in Python development.

Below are the steps to create a virtual environment:

**1. Create a virtual environment**

Firstly, you need to ensure that your system has Python installed. Python version 3.3 and later come with the ``venv`` module to create virtual environments, eliminating the need for separate installation. If you are using Python 2 or a version before Python 3.3, you will need to install ``virtualenv``.

* For Python 3:

Python 3.3 and later versions can directly use the ``venv`` module:

.. raw:: html

    <run></run>

.. code-block:: shell

    python3 -m venv myenv

This will create a virtual environment named ``myenv`` in the current directory.

* For Python 2:

If you are still using Python 2, you first need to install ``virtualenv``:

.. raw:: html

    <run></run>

.. code-block:: shell

    pip install virtualenv

Then, create a virtual environment:

.. raw:: html

    <run></run>

.. code-block:: shell

    virtualenv myenv

This also creates a virtual environment named ``myenv`` in the current directory.

**2. Activating the Virtual Environment**

After creating the virtual environment, you need to activate it for use.

.. note::

    Each time you restart the Raspberry Pi, or open a new terminal, you will need to run the following command again to activate the virtual environment.

.. raw:: html

    <run></run>

.. code-block:: shell

    source myenv/bin/activate

Once the virtual environment is activated, you will see the environment name before the command line prompt, indicating you are working within the virtual environment.


**3. Exiting the Virtual Environment**

When you have completed your work and wish to exit the virtual environment, simply run:

.. raw:: html

    <run></run>

.. code-block:: shell

    deactivate

This will return you to the system's global Python environment.

**4. Deleting the Virtual Environment**

If you no longer need a particular virtual environment, you can simply delete the directory containing the virtual environment:

.. raw:: html

    <run></run>

.. code-block:: shell

    rm -rf myenv