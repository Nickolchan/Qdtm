//
// Created by valkevich on 30.01.17.
//

#ifndef QDTM_TASK_H
#define QDTM_TASK_H

#include <iostream>
#include <vector>

using namespace std;

enum MatrixType {
    CSR, Matrix
};

class Task {
public:
    Task(MatrixType mType = Matrix, int verticalSize = 100, int horizontalSize = 100);

// Параллельная реализация на основе Q-термов
    void QMPI();

// Максимально быстрая реализация на основе Q-детерминанта
    void QMPIOpenMP();

// Сравнение 2 матриц
    bool Compare();

    void PrintMatrixes();
private:
    pair<int, int> size;
    MatrixType matrixType;
    vector<vector<int>> matrixA, matrixB, result;

    void GenerateMatrix();




};


#endif //QDTM_TASK_H
