#include <iostream>
#include <cstdlib>

// Function to dynamically allocate an array and read values
double* allocateAndReadArray(int n) {
    double* vet = (double*) malloc(n * sizeof(double));
    if (vet == nullptr) {
        std::cerr << "Error: Memory allocation failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter " << n << " real numbers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> vet[i];
    }

    return vet;
}

// Function 2: Sort the array using insertion sort
void sortArray(double* arr, int n) {
    for (int i = 1; i < n; ++i) {
        double key = arr[i];
        int j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


// Function to display the sorted array
void displayArray(const double* vet, int n) {
    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << vet[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return EXIT_FAILURE;
    }

    int n = std::atoi(argv[1]);
    if (n <= 0) {
        std::cerr << "Error: n must be a positive integer!" << std::endl;
        return EXIT_FAILURE;
    }

    double* array = allocateAndReadArray(n);
    sortArray(array, n);
    displayArray(array, n);

    free(array); // Free the allocated memory
    return EXIT_SUCCESS;
}