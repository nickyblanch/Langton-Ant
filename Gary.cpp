#include "Gary.hpp"
#include <string>
#include <iostream>

// AUTHOR: Nicolas Blanchard

// Define the overloaded constructor for the Gary class
Gary::Gary(unsigned int N) {
	// Construct Gary with his initial position at N/2, N/2 (center of board),
	// with current orientation upward.
	x_position = N / 2;
	y_position = N / 2;
	// Gary must initially be oriented left, so that when he takes his first step, he goes up the board.
	current_orientation = up;
	// Initialize board_size
	board_size = N;
}


// Define the default constructor for the Gary class
Gary::Gary() {
	x_position = 0;
	y_position = 0;
	current_orientation = up;
	board_size = 0;
}


// Define the function that returns Gary's current orientation
orientation Gary::get_orientation() {
	return current_orientation;
}


// Define the function that returns Gary's current column
unsigned int Gary::get_col() {
	return x_position;
}


// Define the function that returns Gary's current row
unsigned int Gary::get_row() {
	return y_position;
}


// Define the function that moves Gary around the board, and updates Gary's position, orientation,
// and the color of his current cell.
void Gary::move(Cell* current_cell) {
	// Update orientation
	// RECALL: white = 0, black = 1 in the enumeration
	std::string current_color = (current_cell->get_color_string());

	switch (current_orientation) {
	case up:
		if (current_color.compare("0") == 0) {
			current_orientation = right;
		}
		else {
			current_orientation = left;
		}
		break;
	case right:
		if (current_color.compare("0") == 0) {
			current_orientation = down;
		}
		else {
			current_orientation = up;
		}
		break;
	case left:
		if (current_color.compare("0") == 0) {
			current_orientation = up;
		}
		else {
			current_orientation = down;
		}
		break;
	case down:
		if (current_color.compare("0") == 0) {
			current_orientation = left;
		}
		else {
			current_orientation = right;
		}
		break;
	default:
		break;
	}

	// Change the cell color
	current_cell->change_color();

	// Update position:
	switch (current_orientation) {
	case up:
		y_position -= 1;
		break;
	case right:
		x_position += 1;
		break;
	case down:
		y_position += 1;
		break;
	case left:
		x_position -= 1;
		break;
	default:
		break;
	}

	// Check if Gary needs to wrap around to the other side of the board
	if (x_position > board_size) {
		// Gary has wrapped around from the left side of the board to the largest unsigned int value
		// Place Gary at the right side of the board
		x_position = board_size - 1;
	}
	else if (x_position > board_size - 1) {
		// Gary has gone off the right side of the board
		// Place Gary at the left side of the board
		x_position = 0;
	}
	if (y_position > board_size) {
		// Gary has wrapped around from the bottom side of the board to the largest unsigned int value
		// Place Gary at the top side of the board
		y_position = board_size - 1;
	}
	else if (y_position > board_size - 1) {
		// Gary has gone off the top side of the board
		// Place Gary at the bottom side of the board
		y_position = 0;
	}
}