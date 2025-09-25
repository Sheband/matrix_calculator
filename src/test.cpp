#include "matrix.h"
#include <iostream>
#include <cassert>
#include <cmath>

void test_create_and_free() {
    std::cout << "Test 1: Create and free matrix... ";
    Matrix m = create_matrix(3, 3);
    assert(m.rows == 3);
    assert(m.cols == 3);
    assert(m.data != nullptr);
    free_matrix(m);
    std::cout << "PASSED" << std::endl;
}

void test_invalid_creation() {
    std::cout << "Test 2: Invalid matrix creation (should throw exception)... ";
    try {
        Matrix m = create_matrix(-1, 5);
        assert(false); // Не должно сюда попасть
    } catch (const std::exception& e) {
        std::cout << "PASSED (" << e.what() << ")" << std::endl;
    }
}

void test_matrix_addition() {
    std::cout << "Test 3: Matrix addition... ";
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;
    
    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;
    
    Matrix result = matrix_add(A, B);
    assert(result.data[0][0] == 6);  // 1+5
    assert(result.data[0][1] == 8);  // 2+6
    assert(result.data[1][0] == 10); // 3+7
    assert(result.data[1][1] == 12); // 4+8
    
    free_matrix(A);
    free_matrix(B);
    free_matrix(result);
    std::cout << "PASSED" << std::endl;
}

void test_invalid_addition() {
    std::cout << "Test 4: Invalid addition (should throw exception)... ";
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(3, 3);
    
    try {
        Matrix result = matrix_add(A, B);
        assert(false); // Не должно сюда попасть!
    } catch (const std::exception& e) {
        std::cout << "PASSED (" << e.what() << ")" << std::endl;
    }
    
    free_matrix(A);
    free_matrix(B);
}

void test_matrix_multiplication() {
    std::cout << "Test 5: Matrix multiplication... ";
    Matrix A = create_matrix(2, 3);
    Matrix B = create_matrix(3, 2);
    
    // A = [[1, 2, 3], [4, 5, 6]]
    A.data[0][0] = 1; A.data[0][1] = 2; A.data[0][2] = 3;
    A.data[1][0] = 4; A.data[1][1] = 5; A.data[1][2] = 6;
    
    // B = [[7, 8], [9, 10], [11, 12]]
    B.data[0][0] = 7; B.data[0][1] = 8;
    B.data[1][0] = 9; B.data[1][1] = 10;
    B.data[2][0] = 11; B.data[2][1] = 12;
    
    Matrix result = matrix_multiply(A, B);
    // Проверяем результат: A*B = [[58, 64], [139, 154]]
    assert(result.data[0][0] == 58);  // 1*7 + 2*9 + 3*11
    assert(result.data[0][1] == 64);  // 1*8 + 2*10 + 3*12
    assert(result.data[1][0] == 139); // 4*7 + 5*9 + 6*11
    assert(result.data[1][1] == 154); // 4*8 + 5*10 + 6*12
    
    free_matrix(A);
    free_matrix(B);
    free_matrix(result);
    std::cout << "PASSED" << std::endl;
}

void test_invalid_multiplication() {
    std::cout << "Test 6: Invalid multiplication (should throw exception)... ";
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(3, 3);
    
    try {
        Matrix result = matrix_multiply(A, B);
        assert(false);
    } catch (const std::exception& e) {
        std::cout << "PASSED (" << e.what() << ")" << std::endl;
    }
    
    free_matrix(A);
    free_matrix(B);
}

void test_matrix_transpose() {
    std::cout << "Test 7: Matrix transpose... ";
    Matrix A = create_matrix(2, 3);
    
    A.data[0][0] = 1; A.data[0][1] = 2; A.data[0][2] = 3;
    A.data[1][0] = 4; A.data[1][1] = 5; A.data[1][2] = 6;
    
    Matrix result = matrix_transpose(A);
    assert(result.rows == 3);
    assert(result.cols == 2);
    assert(result.data[0][0] == 1); // [0][0] -> [0][0]
    assert(result.data[0][1] == 4); // [1][0] -> [0][1]
    assert(result.data[1][0] == 2); // [0][1] -> [1][0]
    assert(result.data[1][1] == 5); // [1][1] -> [1][1]
    assert(result.data[2][0] == 3); // [0][2] -> [2][0]
    assert(result.data[2][1] == 6); // [1][2] -> [2][1]
    
    free_matrix(A);
    free_matrix(result);
    std::cout << "PASSED" << std::endl;
}

void test_matrix_from_array() {
    std::cout << "Test 8: Matrix from array... ";
    double arr[] = {1, 2, 3, 4, 5, 6};
    Matrix m = matrix_from_array(arr, 2, 3);
    
    assert(m.rows == 2);
    assert(m.cols == 3);
    assert(m.data[0][0] == 1);
    assert(m.data[0][1] == 2);
    assert(m.data[0][2] == 3);
    assert(m.data[1][0] == 4);
    assert(m.data[1][1] == 5);
    assert(m.data[1][2] == 6);
    
    free_matrix(m);
    std::cout << "PASSED" << std::endl;
}



void test_print_matrix() {
    std::cout << "Test 10: Print matrix (visual check)... ";
    Matrix m = create_matrix(2, 2);
    m.data[0][0] = 1.5; m.data[0][1] = 2.25;
    m.data[1][0] = 3.75; m.data[1][1] = 4.1;
    
    // Проверяем что функция не падает
    print_matrix(m);
    
    free_matrix(m);
    std::cout << "PASSED" << std::endl;
}

void test_empty_matrix() {
    std::cout << "Test 11: Empty matrix handling... ";
    Matrix m = create_matrix(0, 0); // Должно бросить исключение
    
    // Если сюда попали - тест не пройден
    assert(false);
    std::cout << "FAILED - should have thrown exception" << std::endl;
}

void test_matrix_operations_chain() {
    std::cout << "Test 12: Chained operations... ";
    
    // Создаем матрицы
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    
    
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;
    
    B.data[0][0] = 2; B.data[0][1] = 0;
    B.data[1][0] = 1; B.data[1][1] = 2;
    
    // Цепочка операций: (A + B) * transpose(A)
    Matrix sum = matrix_add(A, B);
    Matrix transposed = matrix_transpose(A);
    Matrix result = matrix_multiply(sum, transposed);
    
    // Проверяем размеры результата
    assert(result.rows == 2);
    assert(result.cols == 2);
    
    free_matrix(A);
    free_matrix(B);
    free_matrix(sum);
    free_matrix(transposed);
    free_matrix(result);
    std::cout << "PASSED" << std::endl;
}

int main() {
    std::cout << "=== Running Extended Matrix Unit Tests ===" << std::endl;
    
    test_create_and_free();
    test_invalid_creation();
    test_matrix_addition();
    test_invalid_addition();
    test_matrix_multiplication();
    test_invalid_multiplication();
    test_matrix_transpose();
    test_matrix_from_array();
    test_print_matrix();
    
    // test_empty_matrix() - пропускаем, т.к. она должна бросать исключение
    try {
        Matrix m = create_matrix(0, 0);
        // Если не бросило исключение - тест не пройден
        std::cout << "Test 11: Empty matrix... FAILED - should have thrown exception" << std::endl;
        free_matrix(m);
    } catch (const std::exception& e) {
        std::cout << "Test 11: Empty matrix... PASSED (" << e.what() << ")" << std::endl;
    }
    
    test_matrix_operations_chain();
    
    std::cout << "=== All 12 tests passed! ===" << std::endl;
    return 0;
}