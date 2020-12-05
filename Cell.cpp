#include "Cell.hpp"
#include <stdio.h>
#include <iostream>
#include <string>

// AUTHOR: Nicolas Blanchard

// Define default constructor for Cell class:
Cell::Cell() {
	color = white;
	return;
}


// Define the Cell class public member function get_color:
CellColor Cell::get_color() {
	return color;
}


// Define the Cell class public member function change_color:
void Cell::change_color() {
	if (color == white) {
		color = black;
	}
	else {
		color = white;
	}
}


// Define the Cell class public member function get_color_string:
std::string Cell::get_color_string() {
	if (color == white) {
		return "0";
	}
	else {
		return "1";
	}
}