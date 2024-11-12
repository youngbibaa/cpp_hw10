#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
T findMax(const std::vector<T>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

template <typename T>
T findMin(const std::vector<T>& arr) {
    return *std::min_element(arr.begin(), arr.end());
}

template <typename T>
void bubbleSort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
int binarySearch(const std::vector<T>& arr, T value) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; 
}

template <typename T>
void replaceElement(std::vector<T>& arr, size_t index, T newValue) {
    if (index < arr.size()) {
        arr[index] = newValue;
    }
    else {
        std::cerr << "Ошибка: индекс вне диапазона\n";
    }
}

int main() {
    std::vector<int> arr = { 5, 3, 8, 1, 9, 2 };

    std::cout << "Максимум: " << findMax(arr) << "\n";
    std::cout << "Минимум: " << findMin(arr) << "\n";

    bubbleSort(arr);
    std::cout << "Отсортированный массив: ";
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    int value = 8;
    int index = binarySearch(arr, value);
    if (index != -1) {
        std::cout << "Элемент " << value << " найден на индексе " << index << "\n";
    }
    else {
        std::cout << "Элемент " << value << " не найден\n";
    }

    replaceElement(arr, 2, 10);
    std::cout << "Массив после замены элемента: ";
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
