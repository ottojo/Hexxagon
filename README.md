# Einzelprojekt "Hexxagon" - Jonas Otto

Dieses Repository wird genutzt um die Implementierung des Spiels "Hexxagon" zu versionieren.

## Build instructions
* Install dependencies
  * Networking
      [Libwebsockets](https://github.com/warmcat/libwebsockets)
      ```bash
      sudo apt install libwebsockets libwebsockets-dev
      sudo ldconfig
      ```
      
      WebsocketCPP (forked from [SoPra-Team-10/Network](https://github.com/SoPra-Team-10/Network))
      ```bash
      git clone git@github.com:ottojo/WebsocketCPP.git
      cd WebsocketCPP
      mkdir build && cd build
      cmake ..
      make -j$(nproc)
      sudo make install
      sudo ldconfig
      ```
      
  * Graphics: [SFML](https://www.sfml-dev.org/)
      ```bash
        sudo apt-get install libsfml-dev
      ```
  
  * GUI: [TGUI](https://tgui.eu/)
      ```bash
      sudo add-apt-repository ppa:texus/tgui-0.8
      sudo apt-get update
      sudo apt-get install libtgui-dev
      sudo ldconfig
      ```
  
* Get the source code
    ```bash
    git clone --recursive git@github.com:ottojo/Hexxagon.git
    ```
* build
    ```bash
    cd Hexxagon
    mkdir build && cd build
    cmake ..
    make -j$(nproc)
    ```
  
* execute
    ```bash
    ./Hexxagon
    ```

* run unit tests

    (requires [googletest](https://github.com/google/googletest) to be installed to build)
    ```bash
    ./unitTests
    ```
  
* build HTML documentation
    In main repository folder, execute `doxygen`. Documentation will be generated to `doc/html/index.html`.