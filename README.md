# Overview

![test](https://imgur.com/a/bbqtTBl)

TrieDump parses a .txt file and stores each word into a trie data structure (see https://en.wikipedia.org/wiki/Trie). It then dumps the
data associated with the newly built trie into a specified output .txt file.

# Components

* [Main.c](Main.c): Acts as a main driver by making necessary function calls.

* [TrieDump.c](TrieDump.c): Contains the meat of the program. Include functions like createTrie(), destroyTrie(), and writeTrie(), that are essential to program.

* [TrieDump.h](TrieDump.h): Defines the TrieNode struct and the functions that are used in TrieDump.c.

# Build & Run

* To compile: 
      `gcc Main.c TrieDump.c`

* To run:
      `./a.out yourInput.txt yourOutput.txt`
