.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

ライブラリ
============

Raspberry Pi でのプログラミングでは、**wiringPi** と **RPi.GPIO** という 2 つの重要なライブラリが使用されます。  
Raspberry Pi OS にはこれらがデフォルトでインストールされているため、そのまま使用できます。

RPi.GPIO
------------

Python ユーザーであれば、RPi.GPIO が提供する API を使って GPIO を制御できます。

RPi.GPIO は Raspberry Pi の GPIO チャンネルを制御するためのモジュールです。このパッケージは、Raspberry Pi の GPIO を制御するためのクラスを提供します。例やドキュメントについては、次のページを参照してください： http://sourceforge.net/p/raspberry-gpio-python/wiki/Home/ 。

RPi.GPIO がインストールされているかどうかを確認するには、Python を起動して次のように入力します：

.. raw:: html

    <run></run>

.. code-block:: 

    python

.. image:: img/image27.png


Python CLI で ``import RPi.GPIO`` と入力し、エラーが表示されなければ RPi.GPIO はインストールされています。


.. raw:: html

    <run></run>

.. code-block::

    import RPi.GPIO

.. image:: img/image28.png


Python CLI を終了するには、次のように入力します：


.. raw:: html

    <run></run>

.. code-block:: 

    exit()

.. image:: img/image29.png

.. _install_wiringpi:

wiringPi のインストールと確認
-------------------------------------

``wiringPi`` は Raspberry Pi 用の C 言語 GPIO ライブラリです。GUN Lv3 に準拠しています。wiringPi の関数は Arduino の wiring システムに似ており、Arduino に慣れたユーザーが簡単に使用できるようになっています。

``wiringPi`` には、Raspberry Pi のあらゆる種類のインターフェースを制御できる多数の GPIO コマンドが含まれています。 

以下のコマンドを実行して ``wiringPi`` ライブラリをインストールしてください。


.. raw:: html

   <run></run>

.. code-block::

    sudo apt-get update
    git clone https://github.com/WiringPi/WiringPi
    cd WiringPi 
    ./build

次のコマンドで wiringPi ライブラリが正しくインストールされているか確認できます。


.. raw:: html

    <run></run>

.. code-block::

    gpio -v

.. image:: img/image30.png

次のコマンドで GPIO の状態を確認できます：

.. raw:: html

    <run></run>

.. code-block:: 

    gpio readall

.. image:: img/image31.png


wiringPi の詳細については、`WiringPi <https://github.com/WiringPi/WiringPi>`_ を参照してください。


.. _create_virtual:

仮想環境の作成
---------------------------------------

Raspberry Pi などのデバイスで Python パッケージを ``pip`` でインストールする場合、仮想環境の使用が推奨されます。仮想環境は依存関係を分離し、システムの安全性を高め、システムをクリーンに保ち、プロジェクトの移行や共有を容易にすることで、依存関係の管理を簡素化します。これらの利点により、仮想環境は Python 開発において非常に重要で有用なツールとなります。

以下は仮想環境を作成する手順です：

**1. 仮想環境を作成する**

まず、システムに Python がインストールされていることを確認してください。Python 3.3 以降には ``venv`` モジュールが含まれており、別途インストールしなくても仮想環境を作成できます。Python 2 や Python 3.3 以前のバージョンを使用している場合は、``virtualenv`` をインストールする必要があります。

* Python 3 の場合：

Python 3.3 以降では、``venv`` モジュールを直接使用できます：

.. raw:: html

    <run></run>

.. code-block:: shell

    python3 -m venv myenv

これにより、現在のディレクトリに ``myenv`` という名前の仮想環境が作成されます。

* Python 2 の場合：

Python 2 を使用している場合は、まず ``virtualenv`` をインストールします：

.. raw:: html

    <run></run>

.. code-block:: shell

    pip install virtualenv

次に仮想環境を作成します：

.. raw:: html

    <run></run>

.. code-block:: shell

    virtualenv myenv

これでも、現在のディレクトリに ``myenv`` という名前の仮想環境が作成されます。

**2. 仮想環境を有効化する**

仮想環境を作成したら、それを有効化して使用します。

.. note::

    Raspberry Pi を再起動した場合や新しいターミナルを開いた場合は、毎回次のコマンドを実行して仮想環境を有効化する必要があります。

.. raw:: html

    <run></run>

.. code-block:: shell

    source myenv/bin/activate

仮想環境が有効になると、コマンドプロンプトの前に環境名が表示され、仮想環境内で作業していることが分かります。


**3. 仮想環境を終了する**

作業が完了して仮想環境を終了したい場合は、次のコマンドを実行します：

.. raw:: html

    <run></run>

.. code-block:: shell

    deactivate

これでシステムのグローバルな Python 環境に戻ります。

**4. 仮想環境を削除する**

特定の仮想環境が不要になった場合は、その仮想環境が含まれているディレクトリを削除するだけです：

.. raw:: html

    <run></run>

.. code-block:: shell

    rm -rf myenv