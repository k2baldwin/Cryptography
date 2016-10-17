Cryptography Program:

This program pipes in a string of integers from the input text file.
Each integer, or pair of integers, corresponds to an index in the alphabet.

EX:
0=a
1=b
2=c
.
.
12 = m

The program decodes the string of ints into all possible letter outputs.
The program will list the number of possible decodings for the given input.
If small enough, the program will also list all of the possible decodings.

EX:
input = 1234
number of possible decodings = 3
possible decodings:
bcde
mde
bxe

The program can handle multiple inputs if they are seperated by carriage return

To make the executable for this class, navigate to /cryptography_xyz and run:
g++ baldwin.cpp -Wall -o decoder

To run the executable, the command will be:
./decoder < xinput.txt
