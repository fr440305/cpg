rem This batch file is using g++ in Cygwin for compiling the sources.
rem Make sure the g++ has been installed in this computer.

@ cls
@ g++ -std=c++11 -o ./a.exe ./SquareMatrix.cpp ./main.cpp
@ a.exe