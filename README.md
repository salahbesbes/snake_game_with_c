# Snake game with SDL2 (C language)
My first Game made

# Motivation

This project is simple snake game made by SDL2. this is my very first own Game made, in this project i have learned the way game works, the logic behind any game, and how to build a game from scratch, in fact it's very funny project and I enjoy it.


# Technologies

Project is created with:

- SDL2 (with C)
- Makefile

# Feachers
- I have fun learning how To Create Makefile
- I found it realy hard to debug this game using VSCode Debugger, but My best friend is `Printf()`

# ScreenShots

|<image src="screenShot1.PNG" />|<image src="screenShot2.PNG" />|
|--|--|

<br>
<br>

# install On Windows

## Requirement onwindow


|MinGw|[download](https://sourceforge.net/projects/mingw/)|
|--|--|
|gcc| <image src="mingw.PNG"  />|


## Clone repo

    git clone https://github.com/salahbesbes/XO_game_with_c
## Compile Game

     gcc -Isrc/Include -Lsrc/lib -o main ./*.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
## Run Game
     ./main.exe


# install On Ubuntu

 ## Requirement
  |||
  |--|--|
  |compiler | gcc |
  | engine | [SDL2](https://www.libsdl.org/release/SDL2-2.0.20.zip) + [SDL2_image](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.5.zip) | 

  ## Install GCC
    sudo apt update -y
    sudo apt install unzip -y
    sudo apt install build-essential -y
 ## Install [SDL2](https://www.libsdl.org/download-2.0.php).zip
    unzip filename.zip -d ~
    ​cd ~/SDL2-folder
    ​./configure
    ​make all
    ​sudo make install
 ## Install [SDL2_image](https://www.libsdl.org/projects/SDL_image/).zip
    unzip filename.zip -d ~
    ​cd ~/SDL2_image-folder
    ​./configure
    ​make all
    ​sudo make install
    
## Clone repo
    git clone https://github.com/salahbesbes/snake_game_with_c.git
## Compile Game
     make 
## Run Game
    ./main



Licence [SDL_gfx](https://sourceforge.net/projects/sdl2gfx/)
