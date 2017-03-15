//
// Created by valkevich on 30.01.17.
//

#include "Task.h"

#define RAND_RANGE 100
#define density 0.2

void ResizeMatrix(vector<vector<int>> &matrix, pair<int, int> size) {
    matrix.resize(size.first);
    for (int i = 0; i < size.first; i++)
        matrix[i].resize(size.second);
}

Task::Task(MatrixType mType, int verticalSize, int horizontalSize) {
    matrixType = mType;
    size = make_pair(verticalSize, horizontalSize);

    switch (matrixType) {
        CSR:
        {
            matrixA.resize(3);
            matrixB.resize(3);

        };
        Matrix:
        {
            matrixA.resize(size.first);
            for (int i = 0; i < size.first; i++)
                matrixA[i].resize(size.second);
            matrixB.resize(size.first);
            for (int i = 0; i < size.first; i++)
                matrixB[i].resize(size.second);

        };
    }
    GenerateMatrix();

}

void Task::GenerateMatrix() {
    srand(time(0));
    switch (matrixType)
        CSR:
        {
            matrixA[2].push_back(0);
            int index = 0;
            for (int i = 0; i < size.first; i++) {
                int random_number = rand() % RAND_RANGE + 1;
                while (random_number <= size.second) {
                    index++;
                    matrixA[1].push_back(random_number);
                    random_number += rand() % RAND_RANGE + 1;
                }
                matrixA[2].push_back(index);
            }
            matrixA[0].resize(index + 1);
            for (int i = 0; i < index + 1; i++) {
                matrixA[0][i] = rand() % 1000;
            }
        };
    Matrix:
    {

        int iterations = size.first * size.second * density;
        for (int i = 0; i < iterations; i++) {
            matrixA[rand() % size.first][rand() % size.second] = rand() % 1000;
            matrixB[rand() % size.first][rand() % size.second] = rand() % 1000;
        }
    };
}

void Task::PrintMatrixes() {
    for (int i = 0; i < size.first; i++) {
        for (int j = 0; j < size.second; j++)
            cout << matrixA[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
        for (int i = 0; i < size.first; i++) {
            for (int j = 0; j < size.second; j++)
                cout << matrixB[i][j] << ' ';
            cout << endl;
        }

    }

//    bool Task::Compare();
//    for (int i = 0; i < size.first; i++)
//        for (int j = 0; j < size.second; j++)



