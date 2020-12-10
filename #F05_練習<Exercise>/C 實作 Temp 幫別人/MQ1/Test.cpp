// This program finds all solutions to the magic square for a 3X3     
// square where each column, row and diagonal sum is equal

#include <iostream>
using namespace std;
#define SQUARE_SIZE 9

int anyLine = 0;
int currLine = 0;
int numSolutions = 0;


// swap two values in the square.
void swap(int arr[], int idxa, int idxb) {
    int tmp = arr[idxa];
    arr[idxa] = arr[idxb];
    arr[idxb] = tmp;
}

void printArray(int arr[]) {
    for (int i = 0; i < SQUARE_SIZE; i++)
    {
        cout << arr[i] << " ";
        if ((i + 1) % 3 == 0)
            cout << endl;
    }
    cout << endl;
}

void solve(int arr[], int pos) {
    // if (pos == 8) {

    // } else {
        for (int i = 0; i < 9; i++) {
            //if (i == pos) continue;

            //swap(arr, pos, i);
            solve(arr, pos+1);
        }
        printArray(arr);
    //}
}

int main()
{
    int arr[SQUARE_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    solve(arr, 0);
    //cout << "number of solutions is: " << numSolutions << endl;

    return 0;
}