/*
 * Author: Pawan Bhandari
 * Assignment Title: Assignment 3.1: How to Pick a Pivot
 * Assignment Description: Apply the following rules for picking a pivot to sort
 *            a list of integers using the quick sort algorithm and analyze the
 *            number of comparisons required for each strategy.
 *              Pivoting Rules
 *                   1. Using the first element of the array as the pivot element.
 *                   2. Using the final element of the given array as the pivot element.
 *                   3. Using a random element of the given array as the pivot element.
 *                   4. Using the “median-of-three” pivot rule.
 * Due Date: 05/30/2022
 * Date Created: 05/26/2022
 * Date Last Modified:05/30/2022
 */

// Uses C++-2011 standard

/*
 * Data Abstraction:
 *       4 vectors are initialized for storing the integers from input file
 *       Input file stream is opened and vectors are populated
 *
 * Input:
 *       Files in the same relative path as the program that contains the list of integers
 *          QuickSort10k.txt
 *          QuickSort10kR.txt
 *          QuickSort10kSemi2k.txt
 *          QuickSort10kSemi4k.txt
 *
 * Process:
 *       Input file stream is opened to read from inputFileName
 *       vectors corresponding to each input file are populated
 *       Sort these vectors by calling the quickSort function
 *                  which implement different pivot rules
 *
 * Output:
 *      Number of comparisons during each sort is printed in the console
 *
 * Assumptions:
 *      Input files are present in same path and named correctly
 *      Input file contains integer values only on each line (no special characters and whitespaces)
 */

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//** function declarations
void quickSort(vector<int>* vec, int leftPointer, int rightPointer, string pivotRule, int& count);
int partition(vector<int>* v, int l, int r, string pivotRule);
int findPivot(vector<int>* vec, int l, int r, string pivotRule);
int pickMedianOfThree(vector<int>* vec, int l, int r);
void populateInputVector(vector<int>* vec, string sourceFile);
void writeSortedVectorToOutputFile(vector<int>* vec, string outPutFile);
void printVector(vector<int> vec, string name);
//**

int main(int argc, char** argv)
{
    // Initialize comparison counters for each sort
    int firstPivotRandomComparisons = 0;
    int firstPivotReverseComparisons = 0;
    int firstPivotSemi2SortedComparisons = 0;
    int firstPivotSemi4SortedComparisons = 0;
    int finalPivotRandomComparisons = 0;
    int finalPivotReverseComparisons = 0;
    int finalPivotSemi2SortedComparisons = 0;
    int finalPivotSemi4SortedComparisons = 0;
    int randomPivotRandomComparisons = 0;
    int randomPivotReverseComparisons = 0;
    int randomPivotSemi2SortedComparisons = 0;
    int randomPivotSemi4SortedComparisons = 0;
    int medianPivotRandomComparisons = 0;
    int medianPivotReverseComparisons = 0;
    int medianPivotSemi2SortedComparisons = 0;
    int medianPivotSemi4SortedComparisons = 0;

    cout << "Sorting in progress using first element as pivot. Please wait..." << endl;

    // begin sorting using first as a pivot rule
    //  initializing vectors to hold the list of integers from each input file
    vector<int> random10kFirst;
    vector<int> reverse10kFirst;
    vector<int> semi2Sorted10kFirst;
    vector<int> semi4Sorted10kFirst;

    // read the integers from input file to its corresponding vector for first as pivot rule
    populateInputVector(&random10kFirst, "QuickSort10k.txt");
    populateInputVector(&reverse10kFirst, "QuickSort10kR.txt");
    populateInputVector(&semi2Sorted10kFirst, "QuickSort10kSemi2k.txt");
    populateInputVector(&semi4Sorted10kFirst, "QuickSort10kSemi4k.txt");

    //**sort by using first element as pivot calling the quicksort function
    //  by passing the "first" pivot rule as a parameter
    quickSort(&random10kFirst, 0, random10kFirst.size() - 1, "first", firstPivotRandomComparisons);
    quickSort(&reverse10kFirst, 0, reverse10kFirst.size() - 1, "first", firstPivotReverseComparisons);
    quickSort(&semi2Sorted10kFirst, 0, semi2Sorted10kFirst.size() - 1, "first", firstPivotSemi2SortedComparisons);
    quickSort(&semi4Sorted10kFirst, 0, semi4Sorted10kFirst.size() - 1, "first", firstPivotSemi4SortedComparisons);

    cout << "Comparisons w/first as pivot on random 10k numbers = " << firstPivotRandomComparisons << endl;
    cout << "Comparisons w/first as pivot on reverse 10k numbers = " << firstPivotReverseComparisons << endl;
    cout << "Comparisons w/first as pivot on semi-2k-sorted numbers = " << firstPivotSemi2SortedComparisons << endl;
    cout << "Comparisons w/first as pivot on semi-4k-sorted numbers = " << firstPivotSemi4SortedComparisons << endl;
    cout << endl;
    // end sorting using first as a pivot rule

    cout << "Sorting in progress using final element as pivot. Please wait..." << endl;

    // begin sorting using final as a pivot rule
    //  initializing vectors to hold the list of integers from each input file
    vector<int> random10kFinal;
    vector<int> reverse10kFinal;
    vector<int> semi2Sorted10kFinal;
    vector<int> semi4Sorted10kFinal;

    // read the integers from input file to its corresponding vector for final as pivot rule
    populateInputVector(&random10kFinal, "QuickSort10k.txt");
    populateInputVector(&reverse10kFinal, "QuickSort10kR.txt");
    populateInputVector(&semi2Sorted10kFinal, "QuickSort10kSemi2k.txt");
    populateInputVector(&semi4Sorted10kFinal, "QuickSort10kSemi4k.txt");

    //**sort by using final element as pivot calling the quicksort function
    //  by passing the "final" pivot rule as a parameter
    quickSort(&random10kFinal, 0, random10kFinal.size() - 1, "final", finalPivotRandomComparisons);
    quickSort(&reverse10kFinal, 0, reverse10kFinal.size() - 1, "final", finalPivotReverseComparisons);
    quickSort(&semi2Sorted10kFinal, 0, semi2Sorted10kFinal.size() - 1, "final", finalPivotSemi2SortedComparisons);
    quickSort(&semi4Sorted10kFinal, 0, semi4Sorted10kFinal.size() - 1, "final", finalPivotSemi4SortedComparisons);

    cout << "Comparisons w/final as pivot on random 10k numbers = " << finalPivotRandomComparisons << endl;
    cout << "Comparisons w/final as pivot on reverse 10k numbers = " << finalPivotReverseComparisons << endl;
    cout << "Comparisons w/final as pivot on semi-2k-sorted numbers = " << finalPivotSemi2SortedComparisons << endl;
    cout << "Comparisons w/final as pivot on semi-4k-sorted numbers = " << finalPivotSemi4SortedComparisons << endl;
    cout << endl;
    // end sorting using final as a pivot rule

    cout << "Sorting in progress using random element as pivot. Please wait..." << endl;

    // begin sorting using random as a pivot rule
    // initializing vectors to hold the list of integers from each input file
    vector<int> random10kRandom;
    vector<int> reverse10Random;
    vector<int> semi2Sorted10kRandom;
    vector<int> semi4Sorted10kRandom;

    // read the integers from input file to its corresponding vector for random as pivot rule
    populateInputVector(&random10kRandom, "QuickSort10k.txt");
    populateInputVector(&reverse10Random, "QuickSort10kR.txt");
    populateInputVector(&semi2Sorted10kRandom, "QuickSort10kSemi2k.txt");
    populateInputVector(&semi4Sorted10kRandom, "QuickSort10kSemi4k.txt");

    //**sort by using random element as pivot calling the quicksort function
    //  by passing the "random" pivot rule as a parameter
    quickSort(&random10kRandom, 0, random10kRandom.size() - 1, "random", randomPivotRandomComparisons);
    quickSort(&reverse10Random, 0, reverse10Random.size() - 1, "random", randomPivotReverseComparisons);
    quickSort(&semi2Sorted10kRandom, 0, semi2Sorted10kRandom.size() - 1, "random", randomPivotSemi2SortedComparisons);
    quickSort(&semi4Sorted10kRandom, 0, semi4Sorted10kRandom.size() - 1, "random", randomPivotSemi4SortedComparisons);

    cout << "Comparisons w/random as pivot on random 10k numbers = " << randomPivotRandomComparisons << endl;
    cout << "Comparisons w/random as pivot on reverse 10k numbers = " << randomPivotReverseComparisons << endl;
    cout << "Comparisons w/random as pivot on semi-2k-sorted numbers = " << randomPivotSemi2SortedComparisons << endl;
    cout << "Comparisons w/random as pivot on semi-4k-sorted numbers = " << randomPivotSemi4SortedComparisons << endl;
    cout << endl;
    // end sorting using random as a pivot rule

    cout << "Sorting in progress using median element as pivot. Please wait..." << endl;

    // begin sorting using median as a pivot rule
    // initializing vectors to hold the list of integers from each input file
    vector<int> random10kMedian;
    vector<int> reverse10Median;
    vector<int> semi2Sorted10kMedian;
    vector<int> semi4Sorted10kMedian;

    // read the integers from input file to its corresponding vector for median as pivot rule
    populateInputVector(&random10kMedian, "QuickSort10k.txt");
    populateInputVector(&reverse10Median, "QuickSort10kR.txt");
    populateInputVector(&semi2Sorted10kMedian, "QuickSort10kSemi2k.txt");
    populateInputVector(&semi4Sorted10kMedian, "QuickSort10kSemi4k.txt");

    //**sort by using median element as pivot calling the quicksort function
    //  by passing the "median" pivot rule as a parameter
    quickSort(&random10kMedian, 0, random10kMedian.size() - 1, "median", medianPivotRandomComparisons);
    quickSort(&reverse10Median, 0, reverse10Median.size() - 1, "median", medianPivotReverseComparisons);
    quickSort(&semi2Sorted10kMedian, 0, semi2Sorted10kMedian.size() - 1, "median", medianPivotSemi2SortedComparisons);
    quickSort(&semi4Sorted10kMedian, 0, semi4Sorted10kMedian.size() - 1, "median", medianPivotSemi4SortedComparisons);

    cout << "Comparisons w/median as pivot on random 10k numbers = " << medianPivotRandomComparisons << endl;
    cout << "Comparisons w/median as pivot on reverse 10k numbers = " << medianPivotReverseComparisons << endl;
    cout << "Comparisons w/median as pivot on semi-2k-sorted numbers = " << medianPivotSemi2SortedComparisons << endl;
    cout << "Comparisons w/median as pivot on semi-4k-sorted numbers = " << medianPivotSemi4SortedComparisons << endl;
    cout << endl;
    // end sorting using median as a pivot rule

    // write Sorted Vector to output files
    // optional step, not required to get comparison count
    writeSortedVectorToOutputFile(&random10kRandom, "QuickSort10k_Sorted_random.txt");
    writeSortedVectorToOutputFile(&reverse10Random, "QuickSort10kR_Sorted_random.txt");
    writeSortedVectorToOutputFile(&semi2Sorted10kRandom, "QuickSort10kSemi2k_Sorted_random.txt");
    writeSortedVectorToOutputFile(&semi4Sorted10kRandom, "QuickSort10kSemi4k_Sorted_random.txt");

    return 0;
}

//*************************************************************************************
// description: sorts the integer vector using QuickSort using the specified          *
//              pivot rule and counts the number of comparisons                       *
// return: void                                                                       *
// precondition: input vector contains integer elements                               *
// postcondition: sorts the integer vector                                            *
//*************************************************************************************
void quickSort(vector<int>* vec, int leftPointer, int rightPointer, string pivotRule, int& count)
{
    if(leftPointer >= rightPointer) {
        return;
    }

    count = count + (rightPointer - leftPointer);

    int sortedPivotIndex = partition(vec, leftPointer, rightPointer, pivotRule);
    quickSort(vec, leftPointer, sortedPivotIndex - 1, pivotRule, count);
    quickSort(vec, sortedPivotIndex + 1, rightPointer, pivotRule, count);
}

//*************************************************************************************
// description: places the pivot element determined using specified pivot             *
//              rule into its sorted position                                         *
// return: index of the sorted pivot element as a integer                             *
// precondition: input vector contains integer elements and pivotRule is valid        *
// postcondition: returns index of pivot once sorted                                  *
//*************************************************************************************
int partition(vector<int>* v, int l, int r, string pivotRule)
{

    int pivotIndex = findPivot(v, l, r, pivotRule);
    int pivot = (*v).at(pivotIndex);
    int sortedPivotPosition = 0;

    if(pivotRule != "first") {
        swap((*v).at(l), (*v).at(pivotIndex));
    }

    int i = l + 1;

    for(int j = l + 1; j <= r; j++) {
        if((*v).at(j) < pivot) {
            swap((*v).at(j), (*v).at(i));
            i++;
        }
    }
    sortedPivotPosition = i - 1;
    swap((*v).at(l), (*v).at(sortedPivotPosition));
    // cout << ", Pivot: " << pivot << ", sortedPivotPosition: " << sortedPivotPosition << endl;
    // printVector(*v, "pivot in correct position");
    // cout << endl;
    return sortedPivotPosition;
}

//*************************************************************************************
// description: determines pivot element as per rule specified                        *
// return: index of pivot element before its sorted as an integer                     *
// precondition: input vector contains integer elements and pivotRule is valid        *
// postcondition: returns the initial index of pivot before it is sorted              *
//*************************************************************************************
int findPivot(vector<int>* vec, int l, int r, string pivotRule)
{
    // printVector(*vec, "input vector to find pivt");
    int pivotIndex = 0;
    if(pivotRule == "first") {
        pivotIndex = l;
    } else if(pivotRule == "final") {
        pivotIndex = r;
    } else if(pivotRule == "random") {
        srand(time(0));
        pivotIndex = l + (rand() % (r - l + 1));
    } else if(pivotRule == "median") {
        pivotIndex = pickMedianOfThree(vec, l, r);
    } else {
        cout << "Please specify one of the following pivot rules: " << endl;
        cout << "first" << endl << "final" << endl << "random" << endl << "median" << endl;
    }
    // cout << "pivotIndex is: " << pivotIndex;
    // cout << "pivot is: " << (*vec).at(pivotIndex) << endl;
    return pivotIndex;
}

//*************************************************************************************
// description: applies median-of-three rule on the input vector and finds its index  *
// return: index of median element which is either first, final or mid element        *
// precondition: input vector contains integer elements                               *
// postcondition: returns median element index as an integer                          *
//*************************************************************************************
int pickMedianOfThree(vector<int>* vec, int l, int r)
{
    int midIndex = (r - l + 1) / 2; // will be updated to correct value
    int medianIndex = 0;

    int firstElement = (*vec).at(l);
    int finalElement = (*vec).at(r);

    if((r - l + 1) % 2 == 0) {
        midIndex = l + (((r - l + 1) / 2) - 1);
    } else {
        midIndex = l + ((r - l + 1) / 2);
    }

    int midElement = (*vec).at(midIndex);

    // when first element is median
    if(((firstElement >= finalElement) && (firstElement <= midElement)) ||
        ((firstElement <= finalElement) && (firstElement >= midElement))) {
        medianIndex = l;
    }
    // when mid element is median
    if(((midElement >= firstElement) && (midElement <= finalElement)) ||
        ((midElement <= firstElement) && (midElement >= finalElement))) {
        medianIndex = midIndex;
    }
    // when final element is median
    if(((finalElement >= firstElement) && (finalElement <= midElement)) ||
        ((finalElement <= firstElement) && (finalElement >= midElement))) {
        medianIndex = r;
    }

    return medianIndex;
}

//*************************************************************************************
// description: reads inputfile and pushes each integer from the file to the vector   *
// return: void                                                                       *
// precondition: input file exists and contains only integer elements                 *
// postcondition: all integers from input file are pushed to the vector               *
//*************************************************************************************
void populateInputVector(vector<int>* vec, string sourceFile)
{
    ifstream inputFile(sourceFile);
    if(inputFile.is_open()) {
        string line;
        int lineNumber = 1;
        while(getline(inputFile, line)) {
            // handling cases where input file may have non integer values in a line
            try {
                (*vec).push_back(stoi(line));
                lineNumber++;
            } catch(std::invalid_argument&) {
                cout << "Invalid data in input file, please make sure input file contains integers only" << endl;
                return;
            }
        }
        inputFile.close();
    } else {
        cout << "Unable to open file :( " << sourceFile << endl;
    }
}

//*************************************************************************************
// description: writes the sorted list of integer to the output file in same path     *
// return: void                                                                       *
// precondition: outputfile can be opened                                             *
// postcondition: sorted list is written to outputfile                                *
//*************************************************************************************
void writeSortedVectorToOutputFile(vector<int>* vec, string outPutFile)
{
    ofstream outputData;
    outputData.open(outPutFile);

    if(!outputData) {
        cerr << "Unable to open file!" << endl;
        exit(1);
    }

    for(int i = 0; i < (*vec).size(); i++) {
        outputData << (*vec).at(i) << endl;
    }
    outputData.close();
}

//*************************************************************************************
// description: prints the elements of vector in the console                          *
// return: void                                                                       *
// precondition: vector of integers                                                   *
// postcondition: prints elements of vector in the console                            *
//*************************************************************************************
void printVector(vector<int> vec, string name)
{
    cout << name << ": {";
    for(int i = 0; i < vec.size(); i++) {
        if(i == vec.size() - 1) {
            cout << vec[i];
        } else {
            cout << vec[i] << ", ";
        }
    }
    cout << "}" << endl << endl;
}

/* Web References
 *      https://www.softwaretestinghelp.com/random-number-generator-cpp/
 *      https://www.youtube.com/watch?v=JvcqtZk2mng&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=22
 */