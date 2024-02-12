#include <iostream>
#include <random>
//Метод Гауса, вектор невяски
using namespace std;


int main(){
    //RANDOM
    mt19937 gen;
    gen.seed(random_device()());
    uniform_int_distribution<mt19937::result_type> dist;
    int matrix_size;
    cin >> matrix_size;
    cout << endl;


    //MAKING MATRIX
    double** matrix = new double*[matrix_size];
    for (int i = 0; i < matrix_size; i++){
        matrix[i] = new double[matrix_size];
    }
    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
            cin >> matrix[i][j];
            cout << endl;
        }
    }

    //PRINT
    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    //CLEAN OUR MEMORY
    for (int i = 0; i < matrix_size; i++){
        delete [] matrix[i];
    }
    delete [] matrix; 
    return 0;
}