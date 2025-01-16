/*
 * Implementation of Merge Sort algorithm to sort numbers in descending order
 * Equipo 5 

 * Autores: 
 *Lorena Abigail Solís de los Santos - A01746602
 *Andrea Doce Murillo - A01799931
 *Carlos Alberto Zamudio Velázquez - A01799283

 *Fecha de creación: 11/01/2025
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Merges two sorted subarrays into one
 * @param numbers - Vector to sort
 * @param left - Starting index of first subarray
 * @param middle - Ending index of first subarray
 * @param right - Ending index of second subarray
 */
void mergeArrays(vector<double> &numbers, int left, int middle, int right) {
    // Static buffer to avoid repeated allocations
    static vector<double> temp;
    temp.resize(right - left + 1);
    
    // Initialize indices for both subarrays and temp array
    int leftIndex = left;
    int rightIndex = middle + 1;
    int tempIndex = 0;
    
    // Merge elements in descending order
    while (leftIndex <= middle && rightIndex <= right) {
        const double& leftValue = numbers[leftIndex];
        const double& rightValue = numbers[rightIndex];
        // Use >= to maintain stability in the sort
        temp[tempIndex++] = (leftValue >= rightValue) ? numbers[leftIndex++] : numbers[rightIndex++];
    }
    
    // Copy remaining elements from left subarray, if any
    while (leftIndex <= middle) {
        temp[tempIndex++] = numbers[leftIndex++];
    }
    
    // Copy remaining elements from right subarray, if any
    while (rightIndex <= right) {
        temp[tempIndex++] = numbers[rightIndex++];
    }
    
    // Copy merged elements back to original array
    copy(temp.begin(), temp.begin() + tempIndex, numbers.begin() + left);
}

/**
 * Implements the recursive part of Merge Sort algorithm
 * @param numbers - Vector to sort
 * @param left - Starting index of subarray
 * @param right - Ending index of subarray
 */
void recursiveSort(vector<double> &numbers, int left, int right) {
    // Base case: single element or invalid range
    if (left >= right) {
        return;
    }
    
    // Calculate middle point avoiding overflow
    int middle = left + (right - left) / 2;
    // Recursively sort left and right halves
    recursiveSort(numbers, left, middle);
    recursiveSort(numbers, middle + 1, right);
    // Merge the sorted halves
    mergeArrays(numbers, left, middle, right);
}

/**
 * Sorts a vector of numbers in descending order using Merge Sort
 * @param numbers - Vector to sort
 */
void sortNumbers(vector<double> &numbers) {
    recursiveSort(numbers, 0, numbers.size() - 1);
}

int main() {
    int testCases;
    cout << "Ingrese el número de casos de prueba: ";
    cin >> testCases;

    for (int caseNumber = 1; caseNumber <= testCases; caseNumber++) {
        cout << "\nCaso de prueba " << caseNumber << ":" << endl;
        cout << "Ingrese el número de valores a ordenar: ";
        
        int numberCount;
        cin >> numberCount;

        cout << "\nIngrese " << numberCount << " valores (reales o enteros), uno por línea:" << endl;
        
        vector<double> numbers(numberCount);
        for (int i = 0; i < numberCount; i++) {
            cin >> numbers[i];
        }

        if (numberCount > 0) {
            sortNumbers(numbers);
            cout << "\nResultado:" << endl;
            cout << "Valores ordenados de mayor a menor: " << endl;
            for (const double& number : numbers) {
                cout << number << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}