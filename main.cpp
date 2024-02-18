#include <iostream>
// Метод Гауса, вектор невязки до 19 февраля
using namespace std;

void printMatrix(int matrix_size, double **matrix, double *b)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "| " << b[i] << endl;
    }
    cout << endl;
}

void zeroTo(int matrix_size, double **matrix, double *b)
{
    for (int i = 0; i < matrix_size; i++)
    {
        if (matrix[i][0] != 0)
        {
            for (int j = 0; j < matrix_size; j++)
            {
                matrix[0][j] += matrix[i][j];
            }
            b[0] += b[i];
            break;
        }
    }
}

bool verificationOfCorrectness(int matrix_size, double **matrix, double *b)
{
    int flag = 0;
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            if (matrix[i][j] == 0)
                flag++;
        }
        if (flag == matrix_size && b[i] != 0)
        {
            cout << "There are no solutions" << endl;
            return false;
        }
        flag = 0;
    }
    return true;
    cout << endl;
}

int main()
{

    int count_i = 0; // FOR METHOD GAUSA
    int count_j = 0;
    bool flag = false; // ДЛЯ ВЫЧЕТАНИЯ СТРОКИ
    int matrix_size;
    cin >> matrix_size;
    cout << endl;
    double coef = 1;
    int main_elem_count = 0;

    // MAKING MATRIX
    double **matrix = new double *[matrix_size];
    double **copy_matrix = new double *[matrix_size];
    double *b = new double[matrix_size];
    double *copy_b = new double[matrix_size];
    double *X = new double[matrix_size];

    for (int i = 0; i < matrix_size; i++)
    {
        matrix[i] = new double[matrix_size];
        copy_matrix[i] = new double[matrix_size];
        cout << "b[" << i << "] = ";
        cin >> b[i];
        copy_b[i] = b[i];
        cout << endl;
    }
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
            copy_matrix[i][j] = matrix[i][j];
            cout << endl;
        }
    }
    if (matrix[0][0] == 0)
        zeroTo(matrix_size, matrix, b);

    // PRINT
    printMatrix(matrix_size, matrix, b);

    // METHOD GAUSA(PREOBRAZOVANIE STROK)
    while (main_elem_count < matrix_size)
    {
        if (matrix[main_elem_count][main_elem_count] == 0)
            main_elem_count++;

        if (count_i == main_elem_count && count_j == main_elem_count && matrix[main_elem_count][main_elem_count] != 0)
        { // PREVRASHENIE STROKI MAIN ELEMENT TAK SHTOBI MAIN ELEM == 1
            if (matrix[count_i][count_j] != 0)
                coef = 1 / matrix[count_i][count_j];
            b[count_i] *= coef;
        }
        if (count_i == main_elem_count && coef != 1.0)
            matrix[count_i][count_j] *= coef;

        // ВЫСЧИТЫВАНИЕ ОСТАЛЬНЫХ СТРОК
        if (count_i > main_elem_count && flag == false)
        {
            if (matrix[count_i][main_elem_count] != 0)
            {
                flag = true;
                coef = matrix[count_i][main_elem_count] / matrix[main_elem_count][main_elem_count];
                b[count_i] = b[count_i] - b[main_elem_count] * coef;
            }
        }
        if (flag == true)
        {
            matrix[count_i][count_j] = matrix[count_i][count_j] - matrix[main_elem_count][count_j] * coef;
        }

        // PEREHOD NA NEXT ELEM
        count_j++;
        if (count_j >= matrix_size)
        {
            count_j = main_elem_count;
            count_i++;
            flag = false;
            if (count_i >= matrix_size)
            {
                printMatrix(matrix_size, matrix, b);
                main_elem_count++;
                count_i = main_elem_count;
                count_j = main_elem_count;
                coef = 1;
            }
        }
    }

    // OBRATNO
    main_elem_count = matrix_size - 1;
    count_i = matrix_size - 1;
    count_j = matrix_size - 1;
    while (main_elem_count > 0)
    {
        if (matrix[main_elem_count][main_elem_count] == 0)
            main_elem_count--;

        // ВЫСЧИТЫВАНИЕ ОСТАЛЬНЫХ СТРОК
        if (count_i < main_elem_count && flag == false)
        {
            if (matrix[count_i][main_elem_count] != 0)
            {
                flag = true;
                coef = matrix[count_i][main_elem_count] / matrix[main_elem_count][main_elem_count];
                b[count_i] = b[count_i] - b[main_elem_count] * coef;
            }
        }
        if (flag == true)
        {
            matrix[count_i][count_j] = matrix[count_i][count_j] - matrix[main_elem_count][count_j] * coef;
        }

        // PEREHOD NA NEXT ELEM
        count_j--;
        if (count_j < 0)
        {
            count_j = main_elem_count;
            count_i--;
            flag = false;
            if (count_i < 0)
            {
                printMatrix(matrix_size, matrix, b);
                main_elem_count--;
                count_i = main_elem_count;
                count_j = main_elem_count;
                coef = 1;
            }
        }
    }

    // VECTOR NEVYAZKI
    if (verificationOfCorrectness(matrix_size, matrix, b) == true)
    {
        double *vecNev = new double[matrix_size];
        for (int i = 0; i < matrix_size; i++)
            vecNev[i] = 0;
        for (int i = 0; i < matrix_size; i++)
        {
            for (int j = 0; j < matrix_size; j++)
            {
                vecNev[i] -= copy_matrix[i][j] * b[i];
            }
        }
        cout << "VECTOR NEVYAZKI = (";
        for (int i = 0; i < matrix_size; i++)
        {
            vecNev[i] += copy_b[i];
            if (i != matrix_size - 1)
                cout << vecNev[i] << " ";
            else
                cout << vecNev[i] << ")T" << endl;
        }
        delete[] vecNev;
    }

    // CLEAN OUR MEMORY
    for (int i = 0; i < matrix_size; i++)
    {
        delete[] matrix[i];
        delete[] copy_matrix[i];
    }
    delete[] copy_b;
    delete[] X;
    delete[] b;
    delete[] matrix;
    delete[] copy_matrix;
    return 0;
    delete[] matrix;
    return 0;
}
