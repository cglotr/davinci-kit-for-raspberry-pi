.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

コードのダウンロード
===============================

このキットで使用されるすべてのサンプルプログラムは、公式 GitHub リポジトリに保存されています。  
以下のコマンドを使用して、プロジェクト全体を Raspberry Pi にダウンロードしてください。

リポジトリをクローンする
------------------------------------

#. Raspberry Pi にログインして、次のコマンドを実行します：

   .. raw:: html
   
       <run></run>
   
   .. code-block:: bash
   
      cd ~/
      git clone https://github.com/sunfounder/davinci-kit-for-raspberry-pi.git --depth 1

#. プロジェクトのディレクトリに入ります：

   .. raw:: html
   
       <run></run>
   
   .. code-block:: bash
   
      cd ~/davinci-kit-for-raspberry-pi/

#. ファイル一覧を表示します：

   .. raw:: html
   
       <run></run>
   
   .. code-block:: bash
   
      ls

#. 次のような構成が表示されます：

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

プロジェクト構成の概要
--------------------------

各フォルダの簡単な説明は以下のとおりです：

* **c/**  

  Raspberry Pi で C 言語によるプログラミングを行いたいユーザー向けの C 言語サンプルとライブラリです。

* **datasheet/**  

  プロジェクトで使用されているハードウェア部品のデータシート、仕様書、および参考資料が含まれています。

* **iot/**  

  Blynk プラットフォームとの接続、センサーのデモ、通信モジュールなど、IoT 関連のサンプルが含まれています。

* **nodejs/**

  Raspberry Pi 上で JavaScript ベースの開発を行うユーザー向けの Node.js サンプルです。

* **python-pi5/**  

  **Raspberry Pi 5** 向けに最適化された ``GPIO Zero`` ライブラリを使用した Python サンプルです。

* **python/**  

  ``RPi.GPIO`` ライブラリを使用した Python のサンプルプログラムで、ほとんどの Raspberry Pi ボードに対応しています。

* **scratch/** 

  グラフィカルプログラミングを学ぶ初心者向けの Scratch サンプルです。

* **README.md**  

  リポジトリの基本情報および一般的な使用方法が記載されています。

これで、お好みのプログラミング言語やプロジェクトタイプに対応するフォルダに移動して、サンプルを実行できるようになります。
