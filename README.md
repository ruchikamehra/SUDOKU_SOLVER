# SUDOKU_SOLVER
PROJECT : SUDOKU 

 Sudoku is a logic-based, combinatorial, number-placement puzzle. The main objective is to fill a 9X9 grid with digits so that the column, each row, and each of the nine 3X3 subgrids that compose the grid contain all the digits from 1 to 9.

In the game of sudoku, you don't have to repeat the numbers. Only use each number once in each row, column, and grid.
The sudoku puzzle is solved if the squares in each unit are filled with the permutations of the digits 1 to 9.

Your program will have the following function:

•	the first function void enter_sudoko(int su[][9]): will take the input sudoku from the user. the blank spaces will be indicated by 0's.

•	bool check_sudoko(int su[0][9]): This function checks whether the input given user by is correct or not, i.e.., it checks that there should not be a repetition of numbers from 1 to 9 in any row, column, or any 3x3 subgrid. If there is a repetition of a number in any row, column, or 3x3 subgrid then it returns false and the user will be asked to input values again.

•	bool unfilled_space(int su[][9], int &row, int & col) : This function will check for the zero's (i.e the blank spaces).if there is a zero in the specific row and column it will return true otherwise false. x is the integer from 1 to 9.

•	A number can be invalid if it is already in the same row, the same column, or the same box. To check this, we will be using the three different functions that check these three conditions. The row and the column mentioned here is the block which is zero.

•	bool checkrow(int su[][9],int x,int row) : this function will check if we find the same x in the similar row, we return false othewise true. 

•	bool checkcol(int su[][9], int x, int col): this function will check if we find the same x in the similar column, we will return false otherwise true.

•	bool checkbox(int su[][9],int row1,int col1,int x) : this function will check if we found the same x in the particular 3*3 matrix.

•	bool check_condition(int su[][9],int row,int col,int x) : this function will check that if all the above three functions i.e checkrow(),checkcol() and checkbox() have returned true . if it is true, then check_condition will return true otherwise false.

•	bool sudoku(int su[][9]): In this function, the backtracking method will be applied. the process will work as:
1.try and solve the puzzle by placing the number.
2. after placing the number try and recursively fill the other spots.
3. if the puzzle is solved, return true and print the result sudoku puzzle.
4. otherwise, remove the number (su[row][col]=0) because it didn't lead to a solution, and try to recursively solve the puzzle with the next number.
the for loop inside the function with x initialised as 1 will 
call and check all the three function checkrow(),checkcol(),and checkbox().
if every condition is satisfied then, the function will return true otherwise false.

inside the main() function, we have defined a 2d array with 9 rows and 9 columns making it 81 square/boxes.
enter_sudoku(su) function will be called for the user to enter the input sudoku. Then if the check_sudoko() function returns true then sudoku(su) function will be called if function returns true, then the final sudoku board will be printed. If sudoku(su) function returns false, then it prints the error message and will ask the user to again input the sudoku and the whole game will start and finally after every checking every condition final sudoku will be printed.

