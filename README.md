
# Block-Drop OpenGL Game

The project "Block Drop" is centered around interactive game where players get to engage in fun experience.
Players get to:
    * Encounter the falling blocks from top of the screen within the given range.
    * Change the direction of bottom block. (L,R,U,D,Stop)
    * Consume the falling blocks before they reach to the bottom (border is represented in the game).
    * Consumption of red block means addition of 1 point and yellow block means additional 2 points.
    * Failure in consuming red blocks means loosing the game.
(For more engagin and fun experience, background music is also added.)

## Image demonstration of the Game:

## The game platform was installed locally by these process:
    Freeglut was setup on CodeBlocks.
    Downloading CodeBlocks:
    * The CodeBlocks was downloaded from https://www.codeblocks.org/downloads/binaries/
    * Windows XP / Vista / 7 / 8.x / 10 was clicked
    * Then codeblocks-20.03mingw-setup.exe was installed locally on computer.
    Notepad ++ was also installed to edit the files.
    *freeglut was installed from 
    * https://www.transmissionzero.co.uk/files/software/development/GLUT/freeglut-MinGW.zip 

## Setup OpenGL 
    * Extracting all files 
    (freeglut files appears)
    * Navigated to C:\Users\user\Downloads\freeglut\bin\x64 and copy freeglut.dll and pasted to windows.
    * Again, navigating to C:\Users\user\Downloads\freeglut\include\GL and copying it to CodeBlocks include folder inside MinGW
    * The process was repeated for lib folder as well. 
    * Then upon share folder inside the CodeBlocks, navigating to template folder there is glut.cbp file and was edited with the help of notepad++.
    * Replacing all the glut32 with freeglut.
    * Then wizard folder, and glut folder editing the wizard file and replacing the glut32 again.
    (To check if the CodeBlocks runs properly, main.cpp file must be executed after setting up the path.) 

    

