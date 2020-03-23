#include <iostream>
#include <vector>
using namespace std;

void magicSquare(vector<vector<int> > & matrix, int n){

	//use the siamese method to develop a magic square matrix
	int numCells = n * n;

	//start position
	//i represents the row while j represents the column 
	int i = 0, j = n/2; 

	//put numbers in increasing order starting at the top middle and moving up and right throught the matrix
	//once one diagonal row is complete, you move to the cell one below the current cell and continue
	for(int currentNum = 1; currentNum <= numCells; currentNum++){
		matrix[i][j] = currentNum;
		i--;
		j++;

		if(currentNum%n == 0){
			i+=2;
			j--;
		}
		//account for out of bounds
		else{
			if(j == n){
				j-=n;
			}
			else if(i < 0){
				i+=n;
			}
		}
	}
}

void magicSquareVar(vector<vector<int> > & matrix, int n){

	//use a variation of the siamese method to develop a magic square matrix
	int numCells = n * n;

	//start position
	//i represents the row while j represents the column 
	int i = (n/2)-1, j = n/2; 

	//this variation starts one cell above the middle cell and moves up and right 
	//once one diagonal row is complete, you move to the cell two spaces above the current cell and continue
	for(int currentNum = 1; currentNum <= numCells; currentNum++){
		matrix[i][j] = currentNum;

		if(currentNum%n == 0){

			//account for if the element is out of bounds (one or two cells)
			if(i == 1){
				i = n-1;
			}
			else if(i == 0){
				i = n-2;
			}
			else{
				i-=2;
			}
		}

		//account for out of bounds
		if(currentNum%n != 0){
			i--;
			j++;

			if(j == n){
				j-=n;
			}
			else if(i < 0){
				i+=n;
			}
		}
	}
	
}

void reflect(vector<vector<int> > & matrix, int n){
	//Swap elements above the diagonal with the elements below it
	for(int i=0; i<n-1; i++){
    	for(int j=0; j<n-1-i; j++){ 
           swap(matrix[i][j], matrix[n-1-j][n-1-i]);  
		}
	}	
}

void rotate(vector<vector<int> > & matrix, int n){
	//rotating the matrix 90 degrees
	//i represents the rows and j represents the columns 
    for (int i = 0; i < n/2; i++){
        for (int j = i; j < n-i-1; j++){
            //temp = current element
            int temp = matrix[i][j];
 
            //move the elements from the right to the top
            matrix[i][j] = matrix[j][n-1-i];
 
            //move the element from the bottom to the right
            matrix[j][n-1-i] = matrix[n-1-i][n-1-j];
 
            //move the element from the left to the bottom 
            matrix[n-1-i][n-1-j] = matrix[n-1-j][i];
 
            //temp = left
            matrix[n-1-j][i] = temp;
        }
    }
}

void printSums(vector<vector<int> > &matrix, int n){
	//go through and sum the rows of the matrix using a for loop
	cout<< "\nChecking the sums of every row: ";
	for(int i = 0; i < matrix.size(); i++){
		int sum = 0;
		for(int j = 0; j < matrix.size(); j++){
			sum += matrix[i][j];
		}
		cout<< sum<< " ";
	}
	//go through and sum the columns of the matrix using a for loop
	cout<< "\nChecking the sums of every column: ";
	for(int i = 0; i < matrix[0].size(); i++){
		int sum = 0;
		for(int j = 0; j < matrix[0].size(); j++){
			sum += matrix[j][i];
		}
		cout<< sum<< " ";
	}

	//go through and sum the diagonals of the matrix using a for loop
 	cout<< "\nChecking the sums of every diagonal: ";

 	//top left to botton right
 	int diagonalPosition = 0;
 	for(int i = 0; i < matrix.size(); i++){
		diagonalPosition += matrix[i][i];
 	}
 	cout<< diagonalPosition<< " ";

 	//top right to bottom left
 	diagonalPosition = 0;
 	for(int i = 0, j = matrix.size() - 1; i < matrix.size(); i++, j--){
		diagonalPosition += matrix[i][j];
 	}
 	cout<< diagonalPosition<< "\n";
}

void printMagicSquare(vector<vector<int> > &matrix, int n){
	//print the magic square matrix
	//i represents the rows while j represents the columns 
	for (int i=0; i<n; i++) {
    	for (int j=0; j<n; j++){
     		printf(" %3d", matrix[i][j]);
    	}
    	printf("\n");
 	}
	//print the sums for that matrix
    printSums(matrix, n);
}

int main(){

	//get the size of the matrix from the user
	bool works = false;
	int n;
	printf("Enter the size of a magic square: ");

	//check that the user unputs an odd number from 3-15
	while(works == false){
		//scan in user input
		scanf("%d", &n);
		//check to see if the input is too big or too small
		if(n > 2 && n < 16){
			//check to see if the input is odd
			if(n%2 == 1){
				works = true;
			}
			//else print an erorr message
			else{
				printf("Error, please enter an odd number 3-15\n");
			}
		}
		else{
			printf("Error, please enter an odd number 3-15\n");
		}
	}

	vector<vector<int> > matrix(n, vector<int> (n, 0));

	//create a magic square matrix for the user specified size
	magicSquare(matrix, n);  

  	//print results for magic square #1
  	cout<< "\nMagic Square #1 is: \n\n";
  	printMagicSquare(matrix, n);

  	//print results for magic square #2
  	//reflects the matrix
  	cout<< "\nMagic Square #2 is: \n\n";
  	reflect(matrix, n);
  	printMagicSquare(matrix, n);

  	//flips the matrix back to the original
  	reflect(matrix, n);

  	//print results for magic square #3
  	//rotates the matrix 90 degrees
  	cout<< "\nMagic Square #3 is: \n\n";
  	rotate(matrix, n);
  	printMagicSquare(matrix, n);

  	//print results for magic square #4
  	//reflects the matrix
  	cout<< "\nMagic Square #4 is: \n\n";
  	reflect(matrix, n);
  	printMagicSquare(matrix, n);

  	//flips the matrix back to the original
  	reflect(matrix, n);

  	//print results for magic square #5
  	cout<< "\nMagic Square #5 is: \n\n";
  	rotate(matrix, n);
  	printMagicSquare(matrix, n);

  	//print results for magic square #6
  	cout<< "\nMagic Square #6 is: \n\n";
  	reflect(matrix, n);
  	printMagicSquare(matrix, n);

  	//flips the matrix back to the original
  	reflect(matrix, n);

  	//print results for magic square #7
  	cout<< "\nMagic Square #7 is: \n\n";
  	rotate(matrix, n);
  	printMagicSquare(matrix, n);

  	//print results for magic square #8
  	cout<< "\nMagic Square #8 is: \n\n";
  	reflect(matrix, n);
  	printMagicSquare(matrix, n);


  	//n = 3 will only have 8 magic squares so there is only a need to print the other 2 if n > 3
  	if(n > 3){

  		//since I can no longer get the magic squares by roatating and reflecting,
  		//I will create the matrix using a different variation of the siamese method

  		vector<vector<int> > matrix2(n, vector<int> (n, 0));

  		//print results for magic square #9
  		//use the variation of the siamese method to calculate the last 2 magic squares
  		cout<< "\nMagic Square #9 is: \n\n";
  		magicSquareVar(matrix2, n);
  		printMagicSquare(matrix2, n);

  		//print results for magic square #10
  		cout<< "\nMagic Square #10 is: \n\n";
  		reflect(matrix2, n);
  		printMagicSquare(matrix2, n);

  	}
	return 0;
}