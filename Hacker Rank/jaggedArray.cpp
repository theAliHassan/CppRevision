#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

// Function to read size from input
int readSize() {
    int size;
    cin >> size;
    if (size <= 0)
        throw invalid_argument("Size of Jagged Array must be positive");
    return size;
}

// Function to read query count from input
int readQueryCount() {
    int queryCount;
    cin >> queryCount;
    if (queryCount < 0)
        throw invalid_argument("Number of Queries must be non-negative");
    return queryCount;
}

// Function to parse string into vector of integers
vector<int> parseString(const string& str) {
    if (str.empty())
        throw invalid_argument("Input String is empty");

    stringstream ss(str);
    vector<int> list;
    int num;
    while (ss >> num)
        list.push_back(num);
    return list;
}

// Function to populate jagged array from input
vector<vector<int>> populateJaggedArray(const int sizeJagged) {
    vector<vector<int>> jaggedArray(sizeJagged);
    cin.ignore();
    for (int i = 0; i < sizeJagged; i++) {
        string str;
        getline(cin, str);
        vector<int> input = parseString(str);
        if (!input.empty())
            jaggedArray[i] = input;
        else
            throw invalid_argument("Empty String Returned by Parser");
    }
    return jaggedArray;
}

// Function to retrieve queries from input
vector<int> getQueries(const int queryCount, const vector<vector<int>>& arr) {
    vector<int> result;
    int x, y;
    for (int i = 0; i < queryCount; i++) {
        cin >> x >> y;
        if (x < 0 || x >= arr.size() || y < 0 || y >= arr[x].size())
            throw out_of_range("Out of Bounds Access");
        result.push_back(arr[x][y+1]);
    }
    return result;
}

// Function to print query results
void printQueries(const vector<int>& result) {
    for (int num : result)
        cout << num << endl;
}

int main() {
    try {
        // Read size and query count
        int sizeJagged = readSize();
        int queryCount = readQueryCount();

        // Populate jagged array
        vector<vector<int>> jaggedArray = populateJaggedArray(sizeJagged);

        // Retrieve queries
        vector<int> result = getQueries(queryCount, jaggedArray);

        // Print query results
        printQueries(result);
    }
    catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        return 1; // Exit with error status
    }

    return 0;
}
