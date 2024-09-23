#include <bits/stdc++.h>

using namespace std;

// Function to perform merge sort on a portion of the vector
// Parameters:
// - inputVector: Reference to the vector of integers to be sorted
// - tempVector: Temporary vector used for merging
// - lowIndex: Starting index of the portion to be sorted
// - highIndex: Ending index of the portion to be sorted
void mergeSort(vector<int> &inputVector, vector<int> &tempVector, int lowIndex, int highIndex)
{
    // Base case: if the portion has one or no elements, return
    if (highIndex - lowIndex <= 1) {
        return;
    }

    int leftIndex, rightIndex, mergeIndex, midIndex;

    // Calculate the midpoint of the current portion
    midIndex = lowIndex + (highIndex - lowIndex) / 2;

    // Recursively sort the two halves
    mergeSort(inputVector, tempVector, lowIndex, midIndex);
    mergeSort(inputVector, tempVector, midIndex, highIndex);

    // Merge the sorted halves into the temporary vector
    for (leftIndex = lowIndex, rightIndex = midIndex, mergeIndex = lowIndex; mergeIndex < highIndex; mergeIndex++) {
        if (leftIndex < midIndex && rightIndex < highIndex) {
            if (inputVector[leftIndex] < inputVector[rightIndex]) {
                tempVector[mergeIndex] = inputVector[leftIndex++]; // Take from the left half
            }
            else {
                tempVector[mergeIndex] = inputVector[rightIndex++]; // Take from the right half
            }
        }
        else if (leftIndex < midIndex) {
            tempVector[mergeIndex] = inputVector[leftIndex++]; // Copy remaining elements from the left half
        }
        else {
            tempVector[mergeIndex] = inputVector[rightIndex++]; // Copy remaining elements from the right half
        }
    }

    // Copy the sorted elements back into the original vector
    for (mergeIndex = lowIndex; mergeIndex < highIndex; mergeIndex++) {
        inputVector[mergeIndex] = tempVector[mergeIndex];
    }
}

// Function to initiate merge sort on the entire vector
// Parameters:
// - inputVector: Reference to the vector of integers to be sorted
void mergeSort(vector<int> &inputVector)
{
    vector<int> tempVector(inputVector.size()); // Temporary vector for merging
    mergeSort(inputVector, tempVector, 0, inputVector.size()); // Call the recursive merge sort
}

// Main function to handle input/output and initiate sorting
int main()
{
    // Optimize input/output
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    int numElements; // Variable for the number of elements in the vector

    // Read the number of elements
    cin >> numElements;

    vector<int> inputVector(numElements); // Vector to hold the input integers

    // Read the elements into the vector
    for (auto &element : inputVector) {
        cin >> element;
    }

    // Perform merge sort on the vector
    mergeSort(inputVector);

    // Output the sorted vector
    for (auto element : inputVector) {
        cout << element << " ";
    }

    return 0; // Indicate that the program ended successfully
}
