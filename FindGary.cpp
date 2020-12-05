/*
COURSE: ECE 275
INSTRUCTOR: Connor Fuhrman
DATE: 10/20/20, Fall 20 semester
AUTHOR: Nicolas Blanchard, 23400428
INPUTS:
	This program accepts up to three command line arguments as input, with the third
	being optional. After the executable path, the first command line arguments is the
	size of the board (unsigned long int). The next command line argument is the number
	of steps (unsigned long int). The last, optional, command line arguments is the name
	of the file to which the board data will be written (std::string).
OUTPUTS:
	This program outputs the current position and orientation of Gary, as well as the state
	of each cell on the board, to a .txt file. By defauly, this file is called 'name_placeholder.txt'
	unless otherwise specified via command line argument. 
SUMMARY:
	This program simulates Langton's Ant, an ant who follows very specific instructions for movement.
	Instead of an ant, our situation has Gary moving around on a square board of odd dimensions.
	The rules, simply described, are as follows:
	(1) Gary begins in the center cell on the board, facing upward. All cells are initially white.
	(2) If Gary is on a white square, he turns 90 deg clockwise and moves forward one unit.
	(3) If Gary is on a block square, he turns 90 deg anticlockwise and moves forward one unit.
*/

#include "Cell.hpp"
#include "Board.hpp"
#include "Gary.hpp"
#include <string>

int main(int argc, char** argv) {
	// Get command line arguments
	unsigned int boardSize = std::stoi((argv[1]));
	unsigned int numberSteps = std::stoi((argv[2]));

	Board B (boardSize);
	if (argc > 3) {
		// If a file name is supplied:
		B.setOutputFilename(argv[3]);
	}

	// Move Gary!
	B.move_gary(numberSteps);

	// Done
	return 0;
}
