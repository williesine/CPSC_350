# CPSC350 - 01
## SPRING 2022
###### Willie Sine
###### 2371198
###### wsine@chapman.edu
###### Assignment 2: Tutnese Translation Continued (USING A LATE DAY)

###### SOURCE FILES
###### Model.cpp
###### Translator.cpp
###### FileProcessor.cpp
###### main.cpp

###### HEADER FILES
###### Model.h
###### Translator.h
###### FileProcessor.h

###### Assignment 2 outlays three classes that are used to translate english to a cryptographic language, Tutnese, and vice versa*. Model.cpp handles the character translation, Translator.cpp instantiates a Model object, in order to handle the translation of words/sentences, FileProcessor.cpp outlays the writer and reader of the input/output files and handles accordingly. Main.cpp is the driver file for all the source files, using the command line to accept file name arguments, which error catches if improper inputs are provided.

###### Will compile, however nothing gets output to the ofile when the 4th command line prompt is T2E (the program gets stuck in (I believe) an infinite loop internally and wasn't able to figure out why) I believe it's in my translateTutWord() method in Translator.cpp, E2T still works obviously

###### Outside Resources: Zybooks, c++ STL (string & char methods), Prof German in Office Hours
