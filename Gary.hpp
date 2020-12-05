#ifndef HAVEYOUSEENTHSISNAIL_GARY
#define HAVEYOUSEENTHSISNAIL_GARY
#include "Cell.hpp"
#include <vector>

// AUTHOR: Nicolas Blanchard

enum orientation {up, right, down, left};

class Gary {
	/*
	The Gary class stores six public member functions/variables:
		Gary(unsigned int N) is an overloaded constructor that accepts the size of the board, an unsigned int, as a parameter.
		Gary() is the default constructor.
		get_orientation() returns the current orientation og Gary. The return value is of type orientation, an enumerated value.
		get_col() returns Gary's current column, an unsigned int.
		get_row() returns Gary's current row, an unsigned int.
		move(Cell* current_cell) accepts a pointer to Gary's current cell as an argument. It is responsible for actually moving 
			Gary on the board. This function updates Gary's position, updates Gary's orientation, and changes the color of the Cell Gary is on.
	The Gary class stores four private member variables:
		x_position is Gary's current x position on the board (column). It is an unsigned int.
		y_position is Gary's current y position on the board (row). It is an unsigned int.
		current_orientation is Gary's current orientation. It is of type orientation, an enumerated value.
		board_size is the size of the board. It is an unsigned int.
	*/
public:
	Gary(unsigned int N);
	Gary();
	orientation get_orientation();
	unsigned int get_col();
	unsigned int get_row();
	void move(Cell* current_cell);
private:
	unsigned int x_position;
	unsigned int y_position;
	orientation current_orientation;
	unsigned int board_size;
};
#endif
