# Einzelprojekt "Hexxagon" - Jonas Otto

Dieses Repository wird genutzt um die Implementierung des Spiels "Hexxagon" zu versionieren.

## Build instructions
* Install dependencies
  * Generic C++ build tools
    ```bash
    sudo apt install git cmake g++  
    ```
  * Networking
      [Libwebsockets](https://github.com/warmcat/libwebsockets)
      ```bash
      sudo apt install libssl-dev
      git clone https://github.com/warmcat/libwebsockets.git
      cd libwebsockets
      cmake .
      make -j$(nproc)
      sudo make install
      sudo ldconfig
      ```
      
      WebsocketCPP (forked from [SoPra-Team-10/Network](https://github.com/SoPra-Team-10/Network))
      ```bash
      git clone https://github.com/ottojo/WebsocketCPP
      cd WebsocketCPP
      mkdir build && cd build
      cmake ..
      make -j$(nproc)
      sudo make install
      sudo ldconfig
      ```
      
  * Graphics: [SFML](https://www.sfml-dev.org/)
      ```bash
      sudo apt install libudev-dev libopenal-dev libvorbis-dev libflac-dev libxrandr-dev libfreetype6-dev
      git clone SFML
      cd SFML
      cmake .
      make -j$(nproc)
      sudo make install
      sudo ldconfig
    
      ```
  
  * GUI: [TGUI](https://tgui.eu/)
      ```bash
      git clone https://github.com/texus/TGUI.git
      cd TGUI
      cmake .
      make -j$(nproc)
      sudo apt-get update
      sudo apt-get install libtgui-dev
      sudo ldconfig
      ```
  
* Get the source code
    ```bash
    git clone --recursive https://github.com/ottojo/Hexxagon.git
    ```
* build
    ```bash
    cd Hexxagon
    cmake .
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