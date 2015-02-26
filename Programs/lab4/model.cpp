#include "model.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    state = INIT;
    grid = new char*[height];
    visible = new char*[height];
    // For every row, create the array for that row
    for (int i = 0; i < height; i++) {
        grid[i] = new char[width];
        visible[i] = new char[width];
    }
    char letter = 'A';
    // Guarantee pairs of characters in the grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = letter;
            // Everything's invisible at first
            visible[i][j] = '_';
            // Every other iteration...
            if (j % 2 == 1) {
                letter++;
                if (letter > 'Z') {
                    letter = 'A';
                }
            }
        }
    }
    // Seed random number generator with time
    srand(time(0));
    // Randomize
    int otheri, otherj;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Pick a random spot in the grid
            otheri = rand() % height;
            otherj = rand() % width;
            // Swap grid[i][j] with grid[otheri][otherj]
            letter = grid[i][j];
            grid[i][j] = grid[otheri][otherj];
            grid[otheri][otherj] = letter;
        }
    }
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
    for (int i = 0; i < height; i++) {
        delete grid[i];
        delete visible[i];
    }
    delete grid;
    delete visible;
}
// TODO: Is the row/column valid?
// That is, is the row within the height, and is the column within the width?
// Return whether it is or isn't.
bool Model::valid(int row, int column) {
	return(visible[row][column]=='_' && row < getHeight() && column < getWidth());
}
bool Model::matched(int row, int column) {
    return (grid[row][column] == grid[lrow][lcol]);
}
// TODO: Flip a cell
void Model::flip(int row, int column) {
    // If the row and column are not valid, break out and don't do anything
   if (!valid(row, column)) { 
	return; }
	visible[row][column] = grid[row][column];
	
	cout << "state " << state;
	switch(state){
		case INIT:
			lastRow.clear();
			lastColumn.clear();
			state = FIRST;
			break;
		case FIRST:
			if (grid[row][column] != grid[lastRow[0]][lastColumn[0]]) {
				state = NO_MATCH;
			} else {
				state = INIT;
			}
			break;
		case NO_MATCH:
			visible[lastRow[1]][lastColumn[1]] = '_';
			visible[lastRow[0]][lastColumn[0]] = '_';
			lastRow.clear();
			lastColumn.clear();			
			state = FIRST;
			break;
	}
	
	cout << " -> " << state << endl;
	lastColumn.push_back(column);
	lastRow.push_back(row);
	/*int state;
	visible[row][column] = grid[row][column];
	state = check();
	if (state == 0)
	{
		if (matched(row, column) == true)
		{
			visible[row][column] = grid[row][column];
			visible[lrow][lcol] = grid[lrow][lcol];
		}
		if (matched(row, column) == false)
		{
			visible[row][column] = '_';
			visible[lrow][lcol] = '_';
		}
	}
	if (state == 1){
	lcol = column;
	lrow = row;
	}*/
}
int Model::check(){
	int num;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			if (visible[i][j] == grid[i][j])
				num++;
	}
	return num%2;
}
// If everything is visible, then it's game over
bool Model::gameOver() {
    // Assume the game is over
    bool isOver = true;
    // Loop through the grid and see if any element is not visible
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (visible[i][j] == '_') {
                isOver = false;
            }
        }
    }
    
    if (isOver) {
        // Set a nice game over message
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                visible[i][j] = '_';
            }
        }
        visible[2][3] = 'Y';
        visible[2][4] = 'O';
        visible[2][5] = 'U';
        visible[4][3] = 'W';
        visible[4][4] = 'I';
        visible[4][5] = 'N';
    }
    return isOver;
}
int Model::getWidth() {
    return width;
}
int Model::getHeight() {
    return height;
}
char Model::get(int row, int col) {
    return visible[row][col];
}
