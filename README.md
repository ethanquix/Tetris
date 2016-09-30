# Tetris

Tetris clone made in C with ncurses library for the graphic part.

Featuring
----------
    You can change keys, map size, level (see "Options")
    Easily add new tetriminos (see "Tetriminos")
    Fast and without lag playable Tetris
    Great colors !
![Tetris](https://raw.githubusercontent.com/ethanquix/ressources/master/gif/tetris.gif)

Options
----------
    Usage: ./tetris [options]
    Options:
    --help                 Display this help
    -l --level={num}       Start Tetris at level num
    -kl --key-left={K}     Move tetrimino on LEFT with key K
    -kr --key-right={K}    Move tetrimino on RIGHT with key K
    -kt --key-turn={K}     Turn tetrimino with key K
    -kd --key-drop={K}     Set default DROP on key K
    -kq --key-quit={K}     Quit program when press key K
    -kp --key-pause={K}    Pause and restart game when press key K
    --map-size={row,col}   Set game size at row, col
    -w --without-next      Hide next tetrimino
    -d --debug             Debug mode

Tetriminos
----------
    Juste create a fine_name.tetrimino in "tetriminos/" folder with :
    -On the first line A B C where A is the Width, B the Height and C the Color
    -On the B next lines, your tetrimino where "*" is a block
    
Installation
----------
    git https://github.com/ethanquix/Tetris.git
    cd Tetris
    make re
Usage
----------

    ./tetris
    ./tetris -d

> [dimitriwyzlic.com](http://dimitriwyzlic.com) &nbsp;&middot;&nbsp;
> GitHub [@ethanquix](https://github.com/ethanquix) &nbsp;&middot;&nbsp;
> Linkedin [Dimitri Wyzlic](www.linkedin.com/in/dimitriwyzlic)
