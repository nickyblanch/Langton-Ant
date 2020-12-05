#ifndef HAVEYOUSEENTHSISNAIL_CELL
#define HAVEYOUSEENTHSISNAIL_CELL
#include <stdio.h>
#include <iostream>
#include<string>

// AUTHOR: Nicolas Blanchard

// Declare an enumaration data type to store the Cell's color
enum CellColor {white, black};

// Declare the Cell Class
class Cell {
	/*
	The Cell class has four public member functions/variables.
		Cell() is the defauly constructor that initializes the color of the cell to white.
		get_color() returns the color of the cell. The return value is of type CellColor, an enumerated value.
		change_color() reverses the color of the cell.
		get_color_string() returns the color of the cell. The return valueis of type std::string. "0" is
			white, "1" is black.
	The Cell class has one private member variable.
		color is the current color of the cell. It is of type CellColor, an enumerated value.
	*/
public:
	// Declare default constructor to initialize color to white
	Cell();

	// Declare member function getter for the color (get_color). Returns CellColor
	CellColor get_color();

	// Declare a member to flip the color (change_color)
	void change_color();

	// Declare a member to print the string for this color.
	std::string get_color_string();
		// white = "0", black = "1"

private:
	// Declare the color of this cell (color) as type CellColor
	CellColor color;
};

#endif

