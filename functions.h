#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <cctype>
using namespace std;

//this is the function that prints the array.
//it doesn't print the trailing zeros. 
bool printArray(int array[][10], int rows, int columns){
	
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (array[i][j] != 0 || (i == rows - 1 && j == columns - 1)) {
				cout << array[i][j] << " ";
			}
		}
		cout << endl; //move to the next row
	}
	return false;
}

//this is the function that prints the basic array.
//this has trailing zeros.
bool printArrayToReplace(int array[][10], int rows, int columns){
	
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			cout << array[i][j] << " ";
		}
		cout << endl; //move to the next row
	}
	return false;
}

//this is the function that searches the array for a certain number that used asked to check.
//returns true if the number is in array otherwise returns false.
bool certainNumberFinder(int array[][10], int rows, int columns, int certainNumberToFind, int& rowIndex, int& columnIndex){
	int number;
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < columns; ++j){
			if (array[i][j] == certainNumberToFind){
				rowIndex = i;
				columnIndex = j;
				return true;
			}
		}
	}
	return false;
}

//this is the functino that gets the orignal value and saves it as old value. 
//the function also modifies that value to different number. which then is set as new value.
bool modifyValueInArray(int array[][10], int rows, int columns, int rwIndex, int colIndex, int newValueForChange, int& oldValueThatChanged){
	oldValueThatChanged = array[rwIndex][colIndex];
	array[rwIndex][colIndex] = newValueForChange;
	return true;   
}

bool addIntegerToArray(int array [][10], int rows, int columns, int newInteger){
	
	if (array == nullptr || rows <= 0 || columns <= 0) {
        throw invalid_argument ("Invalid array or dimensions.");
    }
    array[rows - 1][columns - 1] = newInteger;
    return true;
}

bool toRemoveOrReplace(int array[][10], int rows, int columns, int rowIndexToRR,
						int columnIndexToRR, int action){
	
    if (action == 1) {
        array[rowIndexToRR][columnIndexToRR] = 0;
    } 
		
	else if (action == 2) { 
		array[rowIndexToRR][columnIndexToRR] = NULL;
    }
    return true;
}