#include "functions.h"

int main() {

	//opening the file.
    ifstream file("input.txt");
    if (!file) {
        cerr << "Error opening input file";
        system("pause");
        return 1;
    }

	const int rows = 10, columns = 10;
    int array[rows][columns];

	// Initialize the array with zeros
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = 0;
        }
    }

	//reading the file into an array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            file >> array[i][j];
        }
    }

	/*cout << "Array Contents:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl; // Move to the next row
    }*/
	
	int option;
	bool continueMenu = true;
	while (continueMenu){
		cout << "\n[1]. Find a certain number" << endl
		 << "[2]. Modify a value" << endl
		 << "[3]. Add an integer" << endl
		 << "[4]. Replace with 0 or Remove" << endl
		 << "[5]. Exit" << endl
		 << "\nChoose an option: ";
		cin >> option;
		if (option < 1 || option > 5){
			cout << "Invalid input. "
				 << "Enter option: ";
			cin >> option;
		}

		switch (option){
			case 1:
				//user inputs a certain number to check if its in an array.
			    int certainNumberToFind;
			    cout << "Enter a number to find: ";
			    cin >> certainNumberToFind;
	
				//calling function to check the certain number throughout the array and returning the answer.
			    int rowIndex, columnIndex;
			    if (certainNumberFinder(array, rows, columns, certainNumberToFind, rowIndex, columnIndex)) {
			        cout << "Number present at index: [" << rowIndex <<"] ["<< columnIndex <<"]" << endl;
			    } 
				else {
			        cout << "Number not in array" << endl;
			    }
				break;
			
			case 2:
				//variables and questions for user inputs
				int rwIndex, colIndex, newValueForChange, oldValueThatChanged;
				try{
					cout << "Enter the index to change." << endl
					 	 << "Note: row and column cannot be above 9" << endl
					 	 << "row: ";
					cin >> rwIndex;
					if (rwIndex < 0 || rwIndex >= rows) {
				        throw runtime_error("Invalid row index.");
				    }
					cout << "column: ";
					cin >> colIndex;
					if (colIndex < 0 || colIndex >= columns) {
						throw runtime_error("Invalid column index.");
					}
					cout << "Enter a number to change the index: ";
				 	cin >> newValueForChange;
					
					//calling the function to modify user-chosen value.
					if (modifyValueInArray(array, rows, columns, rwIndex, colIndex, 
						newValueForChange, oldValueThatChanged)){
						cout << "The old number is " << oldValueThatChanged << endl;
						cout << "The new value is " << newValueForChange << endl;
					}
				}
				catch (const runtime_error &e){
					cerr << "Error: " << e.what() << endl;
				}
				break;
	
			case 3:
				try{
					//setting up variables and asking user a question.
					int newInteger;
					cout << "Enter an integer you would like to add to the array: ";
					cin >> newInteger;
					
					//calling the function to add a new integer to the array in a new place.
					if (addIntegerToArray(array, rows, columns, newInteger)){
						cout << "Here is the array with the added integer: " << endl
							 << "Array Contents:" << endl;
						//printing the array with the new integer that has been added
				        printArray(array, rows, columns);
					}
				}
				catch (const exception &e) {
				cerr << "Error: " << e.what() << endl;
				}
				break;
			case 4:
				int rowIndexToRR, columnIndexToRR, action;
				cout << "Enter the row and column index that you would like to replace or remove." << endl
				     << "Note: row and column cannot be above 9" << endl
					 << "Row: ";
				cin >> rowIndexToRR;
				cout << "Column: ";
				cin >> columnIndexToRR;
				cout << "Would you like to (1) replace or (2) remove?: ";
				cin >> action;
	
				if (toRemoveOrReplace(array, rows, columns, rowIndexToRR, columnIndexToRR, action)){
					cout << "Array Contents:" << endl;
				    if (action == 1){
						printArrayToReplace(array, rows, columns);
					}
					else{
						printArray(array, rows, columns);
					}
				}
				break;
			case 5:
	                continueMenu = false; //exit the loop
	                break;
	
			default:
				cout << "Invalid option. Please choose a valid option." << endl;
		}
	}
    return 0;
}