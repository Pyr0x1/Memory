Memory
======

<a href="http://it.tinypic.com?ref=fdrk03" target="_blank"><img src="http://i61.tinypic.com/fdrk03.png" border="0" alt="Image and video hosting by TinyPic"></a>

A simple memory game written in C++ with the SDL library.

Compilation / Installation (currently tested only on linux)
======

You'll need the SDL library version 2 plus a couple of extensions in order to succesfully compile the game. They can be easily installed on Ubuntu by using the following command:

```bash
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

When you have satisfied all the dependencies, simply run

```bash
make
```
and then, if no errors are displayed, you can run the game with

```bash
./Memory
```

Instructions
======

Memorize the movements performed by the CPU square and reproduce the sequence. For each correct sequence the level will increase by one and the new sequence will be longer. To reproduce the sequence use the arrow keys.

Changelog
======

Version 0.1:

* First release version.