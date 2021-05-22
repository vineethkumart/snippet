/* 2D arrays and matrices are very important for my understanding
I haven't practiced this ever. Practice this well

Mainly:
1. Understand about the positions thouroughly
2. Understand about printing different positions corners etc.,
3. Understand about transposing to different patterns
*/


// Printing and the loops
for (uin32_t i = 0; i < N; i++) 
    for (uin32_t j = 0; j < N; j++)
        
    0   1   2   3

0   00  01  02  03 

1   10  11  12  13

2   20  21  22  23

3   30  31  32  33

a[i][j] -> Row wise
a[j][i] -> Column wise

i : 0 -> N
j : i -> N
Upper triangle including diagonal

i : 0 -> N
j : 0 -> i
Lower triangle including diagonal



Print matrix in diagonal fashion
--------------------------------
LR
void print_diag(char a[][N])
{
    for (uint32_t i = 0; i < N; i++) {
        for (int32_t j = i; j >= 0 ; j--)
            std::cout << a[j][i-j] << " ";
        std::cout << endl;
    }
    
     for (uint32_t i = 1; i < N; i++) {
        for (int32_t j = N-1; j >= i ; j--)
            std::cout << a[j][N-1-j+i] << " ";
        std::cout << endl;
     }
}
RL
void print_diag(char a[][N])
{
    for (uint32_t i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << a[j][i-j];
        }
        std::cout << endl;
    }
    
    for (uint32_t i = 1; i < N; i++) {
        for (int j = i; j < N; j++) {
            std::cout << a[j][N-1-j+i];
        }
        std::cout << endl;
    }
}

diagonal spiral
---------------
void print_diag(char a[][N])
{
    for (uint32_t i = 0; i < N; i++) {
        if (!(i%2)) {
            for (int32_t j = i; j >= 0 ; j--)
                std::cout << a[j][i-j] << " ";
        } else {
            for (int j = 0; j <= i; j++)
                std::cout << a[j][i-j]<< " ";;
        }
        std::cout << endl;
    }
    
    for (uint32_t i = 1; i < N; i++) {
        if (i%2) {
            for (int32_t j = N-1; j >= i ; j--)
                std::cout << a[j][N-1-j+i] << " ";
        } else {
            for (int j = i; j < N; j++)
                std::cout << a[j][N-1-j+i]<< " ";;
        }
        std::cout << endl;
    }
}


spiral
------
void print_spiral(char a[][N])
{
    for (uint32_t row = 0; row < (N/2); row++) {
        // L -> R
        for (uint32_t i = row; i < N-row; i++)
            std::cout << a[row][i] << " ";
        std::cout << endl;
        
        // T -> B
        for (uint32_t i = row+1; i < N-row; i++)
            std::cout << a[i][N-1-row] << " ";
        std::cout << endl;
        
        // R -> L
        for (uint32_t i = row+1; i < N-row; i++)
            std::cout << a[N-1-row][N-1-i] << " ";
        std::cout << endl;
            
        // B -> T
        for (uint32_t i = row+1; i < N-1-row; i++)
            std::cout << a[N-1-i][row] << " ";
        std::cout << endl;
    }
}




Transpose
----------
a[i][j] = a[j][i] for uppder triangle

for (uin32_t i = 0; i < N; i++)
    for (uin32_t j = i+1; j < N; j++)  // for (j = 0; j < i; j++) also is correct
        swap(a[i][j], a[j][i])


Rotate 90 anti-clockwise
------------------------
Input:
Matrix:
 1  2  3
 4  5  6
 7  8  9
Output:
 3  6  9 
 2  5  8 
 1  4  7 

Soln1
A. Transpose the Matrix
B. Swap rows i, N-1-i

Soln2
Rotate the Matrix in layers, for a 4x4 matrix, rotate the outer layer or size 4 and then the innter layer of size 2
--> There are (N/2) layers
--> For Each layer do (N-layer) number of elements to rotate and 4 rotations each time(4 corners)

for (uint32_t i = 0; i < (N/2); i++)
    for (uint32_t j = i; j < N-i-1; j++) {
        uint32_t temp = a[i][j];
        // top left with top right
        a[i][j] = a[j][N-i-1];
        
        // top right with bottom right
        a[j][N-i-1] = a[N-i-1][N-j-1];

        // bottom right with bottom left
        a[N-i-1][N-j-1] = a[N-j-1][i];

        // bottom left with temp
        a[N-j-1][i] = temp;
    }


Rotate 90 clockwise
-------------------
Input:
1 2 3 
4 5 6
7 8 9  
Output:
7 4 1 
8 5 2
9 6 3
Soln:
A. Transpose and Swap i'th and N-i'th columns

Soln2:
for (uint32_t i = 0; i < (N/2); i++)
    for (uint32_t j = i; j < N-i-1; j++) {
        uint32_t temp = a[i][j];
        
        // top left bottom left
        a[i][j] = a[N-1-j][i];
        
        // bottom left with bottom right
        a[N-1-j][i] = a[N-i-1][N-j-1];

        // bottom right top right 
        a[N-i-1][N-j-1] = a[j][N-1-i];

        // bottom left with temp
        a[j][N-1-i] = temp;
    }
