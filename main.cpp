#include <iostream>
#include <random>
//Метод Гауса, вектор невяски до 19 февраля
using namespace std;


void printMatrix(int matrix_size, double** matrix){
    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    int count_i = 0;
    int count_j = 0;

    //RANDOM
    mt19937 gen;
    gen.seed(random_device()());
    uniform_int_distribution<mt19937::result_type> dist;
    int matrix_size;
    cin >> matrix_size;
    cout << endl;


    //MAKING MATRIX
    double** matrix = new double*[matrix_size];
    double* b = new double[matrix_size];
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
    printMatrix(matrix_size, matrix);



    //METHOD GAUSA(PREOBRAZOVANIE STROK)
    while (true)
    {
        double coef = 1;
        bool flag = false; //ведущий элемент или нет
        if(count_i < 5){
            if(count_j < 5){
                if(matrix[count_i][count_j] != 1 && flag == false){
                    coef = 1 / matrix[count_i][count_j];
                    flag = true;
                }
                 
            }
        }
    }
    

    //CLEAN OUR MEMORY
    for (int i = 0; i < matrix_size; i++){
        delete [] matrix[i];
    }
    delete [] matrix; 
    return 0;
}
