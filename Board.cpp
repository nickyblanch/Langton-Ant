#include "Board.hpp"
#include <iostream>
#include <vector>

// AUTHOR: Nicolas Blanchard

// Define the constructor for the Board class
Board::Board(unsigned int N) {
	// Check to ensure that N is odd
	if (N % 2 == 0) {
		std::cout << "Board dimension must be an odd number!! Got " << N << " and adding 1 to equal " << N + 1 << std::endl;
		N += 1;
	}

	// Initialize the vector of cell vectors
	board_vector.resize(N);
	for (unsigned int i = 0; i < N; i++) {
		board_vector[i].resize(N);
	}

	// Initialize the current position of Gary
	current_cell = &(board_vector[N / 2][N / 2]);

	// Initialize the size of the board
	board_size = N;

	// Initialize Gary
	Gary* gary_temp = new Gary(N);
	gary = *gary_temp;
	free(gary_temp);
}


// Define the function that moves Gary one cell forward
void Board::move_gary(int steps) {
	// Print initial board
	print_board(board_size);
	for (int i = 0; i < steps; i++) {
		gary.move(current_cell);
		// Update current cell (within the Board object)
		current_cell = &(board_vector[gary.get_row()][gary.get_col()]);
		// Print board
		print_board(board_size);
	}
	outputFile.close();
}


// Define the function that sets the filename where the data is written to
void Board::setOutputFilename(std::string fileName) {
	outputFile.open(fileName);
}


// Define the function that prints the data to the file (the data printed includes
// Gary's position and orientation at each step of his journey)
void Board::print_board(unsigned int N) {
	// If provided with a file
	if (outputFile.is_open()) {
		outputFile << "[Gary Location] {" << gary.y_position << ", " << gary.x_position << "} [Gary Orientation] " << orientation_strings[gary.get_orientation()];
		for (unsigned int i = 0; i < N; i++) {
			outputFile << "[Row " << i << "] ";
			for (unsigned int j = 0; j < N; j++) {
				outputFile << board_vector[i][j].get_color_string() << " ";
			}
		}
		outputFile << std::endl;
	}
	else {
		std::cout << "[Gary Location] {" << gary.y_position << ", " << gary.x_position << "} [Gary Orientation] " << orientation_strings[gary.get_orientation()];
		for (unsigned int i = 0; i < N; i++) {
			std::cout << "[Row " << i << "] ";
			for (unsigned int j = 0; j < N; j++) {
				std::cout << board_vector[i][j].get_color_string() << " ";
			}
		}
		std::cout << std::endl;
	}
	
}