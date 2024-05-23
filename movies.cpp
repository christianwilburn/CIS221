#include <iostream>
#include <algorithm>

using namespace std;

// Function to calculate the mode of an array
int calculateMode(int arr[], int size) {
    int maxCount = 0, mode = -1;

    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 0; j < size; ++j) {
            if (arr[j] == arr[i])
                ++count;
        }
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }

    return mode;
}

int main() {
    int numStudents;

    // Ask the user for the number of students surveyed
    cout << "Enter the number of students surveyed: ";
    cin >> numStudents;

    // Dynamically allocate an array to store the number of movies each student has seen
    int *watchedMovies = new int[numStudents];

    // Ask the user to enter the number of movies each student has seen
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter the number of movies seen by student " << i + 1 << ": ";
        cin >> watchedMovies[i];
    }

    // Calculate the average
    int totalMovies = 0;
    for (int i = 0; i < numStudents; ++i) {
        totalMovies += watchedMovies[i];
    }
    double average = static_cast<double>(totalMovies) / numStudents;

    // Calculate the median
    sort(watchedMovies, watchedMovies + numStudents);
    double median;
    if (numStudents % 2 == 0) {
        median = (watchedMovies[numStudents / 2 - 1] + watchedMovies[numStudents / 2]) / 2.0;
    } else {
        median = watchedMovies[numStudents / 2];
    }

    // Calculate the mode
    int mode = calculateMode(watchedMovies, numStudents);

    // Output the results
    cout << "Average number of movies seen: " << average << endl;
    cout << "Median number of movies seen: " << median << endl;
    cout << "Mode number of movies seen: " << mode << endl;

    // Free the dynamically allocated memory
    delete[] watchedMovies;

    return 0;
}