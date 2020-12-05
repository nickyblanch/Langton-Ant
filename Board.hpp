#ifndef HAVEYOUSEENTHSISNAIL_BOARD
#define HAVEYOUSEENTHSISNAIL_BOARD

#include <vector>
#include <fstream>
#include "Cell.hpp"
#include "Gary.hpp"

// AUTHOR: Nicolas Blanchard

class Board {
	/*
	The Board class stores six public member functions/variables:
		Board(unsigned int N) is the constructor, and accepts an unsigned int as a a parameter.
		move_gary(int steps) is responsible for moving Gary, and accepts the number of steps as an int input.
		print_board(unsigned int N) prints the representation of the board, including Gary's location and position, to the output file. It accepts
			the size of the board as an unsigned int input.
		setOutputFilename(std::string fileName) opens the file that the user wishes to log the board data in. It accepts a string as an input.
		board_vector is a vector of vectors of Cells, which stores all of the Cells that make up the board.
		board_size is the size of the board, as given by the user.
	The Board class stores four private member functions/variables:
		current_cell is a pointer to the cell that Gary is currently at.
		outputFile is the file object to which the Board data is being written.
		gary is an instance of the Gary class, and represents Gary the snail as he travels the board.
		orientation_strings is a vector of strings. This is created so that the enumerated orientation
			can be easily translated to strings, using indexing.
	*/
public:
	Board(unsigned int N);
	void move_gary(int steps);
	void print_board(unsigned int N);
	void setOutputFilename(std::string fileName);
	std::vector<std::vector<Cell>> board_vector;
	unsigned int board_size;

private:
	Cell* current_cell;
	std::ofstream outputFile;
	Gary gary;
	std::vector<std::string> orientation_strings = { "up ", "right ", "down ", "left "};
};
#endif
