# Langton-Ant
This program simulates Langton's Ant, an ant who follows very specific instructions for movement.
	Instead of an ant, our situation has Gary moving around on a square board of odd dimensions.
	The rules, simply described, are as follows:
	(1) Gary begins in the center cell on the board, facing upward. All cells are initially white.
	(2) If Gary is on a white square, he turns 90 deg clockwise and moves forward one unit.
	(3) If Gary is on a block square, he turns 90 deg anticlockwise and moves forward one unit.
 
The included .hpp files implement a variety of user-defined classes required to solve this problem.
The included FindGary.cpp file uses the classes to simulate Langton's Ant's movement.
The output of the algorithm is printed to the standard output unless a file is provided as a command
line argument (see documentation in code), in which case the output will be printed to a file.
