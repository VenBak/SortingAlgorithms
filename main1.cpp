#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

struct Length
{
	int minutes;							// #minutes (0..)
	int seconds;							// #seconds (0..59)
};

struct Track
{
	string artist;                          // name of artist
	string cd;                              // cd title
	int    year;                            // year of appearance (if known)
	int    track;							// track number
	string title;                           // track title
	string tags;                            // tags
	Length time;							// playing time
	string country;                         // main countr(y/ies) of artist
};

/**********************************************************************************************************
 *
 * input and output code from prior week:
 *
 *********************************************************************************************************/
ostream& operator<< (ostream& out, const Length length)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the value of length is shown via out in the format: minutes, ':', seconds (two digits)
*/

    // use your implementation of last week
    if(length.seconds < 10){
        out << length.minutes << ":0" << length.seconds;
    }
    else{
        out << length.minutes << ":" << length.seconds;
    }
    return out;
}

istream& operator>> (istream& in, Length& length)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the value of length has been read from in: first minutes, then ':', then seconds
*/
    // use your implementation of last week
    char bin;
    in >> length.minutes >> bin >> length.seconds;
    return in;
}

ostream& operator<< (ostream& out, const Track& track)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the value of track is shown via out.
*/
    return out << track.artist << " - " << track.track << ". " << track.title
        << " (" << track.cd << ", " << track.year << ") [" << track.time << "]";
}

istream& operator>> (istream& in, Track& track)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the content of the first 8 lines from in have been read and are stored in the corresponding members of track.
    The following (empty) line from in has also been read.
*/
    // use your implementation of last week
    getline(in, track.artist);
    getline(in, track.cd);
    in >> track.year;
    in >> track.track;
    in.ignore();
    getline(in, track.title);
    getline(in, track.tags);
    in >> track.time;
    in.ignore();
    getline(in, track.country);
    string emptyLine;
    getline(in, emptyLine);
    return in;
}

/**********************************************************************************************************
 *
 * (slice) helper function:
 *
 *********************************************************************************************************/
typedef Track El;                           // as explained in lecture, define algorithms on El

struct Slice
{  int from;     // from >= 0
   int length;   // length >= 0
};

Slice make_slice (int from, int length)
{// Precondition:
    assert (from >= 0 && length >= 0);
/*  post-condition:
    return slice with given from and length
*/
    Slice s = { from, length};
    return s;
}

Slice make_slice (const vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns the slice for the entire vector data.
*/
    Slice s = { 0, static_cast<int>( ssize (data) ) };
    return s;
}

bool valid_slice (Slice s)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if all selector values of s are not negative.
*/
    return 0 <= s.from && 0 <= s.length;
}
bool valid_slice (const vector<El>& data, Slice s)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if s is a valid slice for data
*/
    return valid_slice (s) && s.from + s.length <= ssize (data);
}

int first (Slice s)
{// Precondition:
    assert (valid_slice (s));
/*  Postcondition:
    result is index of first element in s (s.from)
*/
    return s.from;
}

int last (Slice s)
{// Precondition:
    assert (valid_slice (s));
/*  Postcondition:
    result is index of last element in s (s.from + s.length - 1)
*/
    return s.from + s.length - 1;
}

/**********************************************************************************************************
 *
 * compare operators:
 *
 *********************************************************************************************************/
bool operator== (const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if all selector values of a are equal to their counterparts of b
*/
    // implement this function
    return a.artist == b.artist &&
           a.cd == b.cd &&
           a.year == b.year &&
           a.track == b.track &&
           a.title == b.title &&
           a.tags == b.tags &&
           a.time.minutes == b.time.minutes &&
           a.country == b.country;
}

bool operator!= (const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if any selector values of a are not equal to their counterparts of b
*/
    return !(a == b);
}

bool operator< (const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    check the assignment for the proper definition of < on Tracks
*/
    // implement this function
    if (a.artist != b.artist) {
        return a.artist < b.artist;
    } else if (a.cd != b.cd) {
        return a.cd < b.cd;
    } else if (a.year != b.year) {
        return a.year < b.year;
    } else {
        return a.track < b.track;
    }
}

bool operator>(const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if a does not precede b according to the ordering < on Tracks (don't forget to implement operator<)
*/
	return b < a;
}

bool operator<=(const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if a < b or a == b according to their definitions on Tracks (don't forget to implement operator< and operator==)
*/
	return a < b || a == b;
}

bool operator>=(const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if a > b or a == b according to their definitions on Tracks (don't forget to implement operator< and operator==)
*/
	return a > b || a == b;
}

bool is_sorted (const vector<El>& data, Slice s)
{// pre-condition:
    assert (valid_slice (data, s));
/*  post-condition:
    result is true if data.at(first (s)) <= data.at(first (s) + 1) ... data.at(last(s)-1) <= data.at(last(s))
*/
    // implement this function
    for (int i = s.from; i < last(s); ++i) {
        if (data.at(i) > data.at(i + 1)) {
            return false;
        }
    }
    return true;
}

/**********************************************************************************************************
 *
 * insertion sort algorithm:
 *
 *********************************************************************************************************/
void insert (vector<El>& data, Slice s)
{// Precondition:
    assert (valid_slice (data,s));
    assert (is_sorted (data, s));
    assert (last (s) < ssize (data) - 1);
/*  Postcondition:
    data.at (last (s)+1) is moved in data.at (first (s))...data.at (last (s)+1) and is_sorted (data, make_slice (s.from s.length+1))
*/
    // implement this function
    int i = last(s);
    while (i >= s.from && data[i] > data[i + 1]) {
        swap(data[i], data[i + 1]);
        --i;
    }
}

void insertion_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    // implement this function
    for (int i = 1; i < ssize(data); ++i) {
        insert(data, make_slice(0, i));
    }
}

/**********************************************************************************************************
 *
 * selection sort algorithm:
 *
 *********************************************************************************************************/
int max_value_at (const vector<El>& data, Slice s)
{// Precondition:
    assert (valid_slice (data, s));
    assert (s.length > 0);
/*  Postcondition:
    data.at (result) is the maximum of every element in data.at (first (s)) ... data.at (last (s))
*/
    // implement this function
    int maxIndex = s.from;
    for (int i = s.from + 1; i <= last(s); ++i) {
        if (data[i] > data[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void selection_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    // implement this function
    for (int i = 0; i < ssize(data) - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < ssize(data); ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        swap(data[i], data[minIndex]);
    }
}

/**********************************************************************************************************
 *
 * bubble sort algorithm:
 *
 *********************************************************************************************************/
bool bubble (vector<El>& data, Slice unsorted)
{// Precondition:
    assert (valid_slice (data, unsorted));
/*  Postcondition:
    immediate pairs in data with slice unsorted are swapped if left element is larger than right element, and result is
    true only if this is done at least once (don't forget to implement operator< and operator==)
*/
    // implement this function
    bool swapped = false;
    for (int i = first(unsorted); i < last(unsorted); ++i) {
        if (data[i] > data[i + 1]) {
            swap(data[i], data[i + 1]);
            swapped = true;
        }
    }
    return swapped;

}

void bubble_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    // implement this function
    Slice unsorted = make_slice(0, ssize(data) - 1);
    while (bubble(data, unsorted)) {
        unsorted.length--;
    }
}

/**********************************************************************************************************
 *
 * heap sort algorithm:
 *
 *********************************************************************************************************/
int left_sibling (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the left sibling of an element at index i in a heap structured array/vector
*/
    return i-1;
}

int right_sibling (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the right sibling of an element at index i in a heap structured array/vector
*/
    return i+1;
}

int parent (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the parent of an element at index i in a heap structured array/vector
*/
    return (i-1) / 2;
}

int left_child (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the left child of an element at index i in a heap structured array/vector
*/
    return 2*(i+1)-1;
}

int right_child (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the right child of an element at index i in a heap structured array/vector
*/
    return 2*(i+1);
}

bool is_a_heap (const vector<El>& data, Slice s)
{// Precondition:
    assert (valid_slice (data,s));
/*  Postcondition:
    result is true only if all existing children in slice s of data have a value that is not greater than their parent
*/
    // implement this function
    for (int i = first(s); i <= last(s); ++i) {
        int leftChildIdx = left_child(i);
        int rightChildIdx = right_child(i);

        if (leftChildIdx <= last(s) && data.at(leftChildIdx) > data.at(i)) {
            return false;
        }

        if (rightChildIdx <= last(s) && data.at(rightChildIdx) > data.at(i)) {
            return false;
        }
    }
    return true;
}

void push_up ( vector<El>& data, int elem )
{// Precondition:
    assert (0 <= elem && elem < ssize (data) && is_a_heap (data, make_slice (0,elem)));
/*  Postcondition:
    is_a_heap (data, make_slice (0, elem+1))
*/
    // implement this function
    int current = elem;
    while (current > 0 && data.at(current) > data.at(parent(current))) {
        swap(data.at(current), data.at(parent(current)));
        current = parent(current);
    }
}

bool largest_child (const vector<El>& data, int parent, int unsorted, El& child, int& which)
{// Precondition:
    assert (0 <= unsorted && unsorted < ssize (data));
    assert (0 <= parent && parent < ssize (data));
/*  Postcondition:
    result is true only if the element at parent in data has one or two unsorted child elements;
    only in that case the value of the largest child is child and its index position is which
*/
    // implement this function
    int leftChildIdx = left_child(parent);
    int rightChildIdx = right_child(parent);

    if (leftChildIdx <= unsorted && rightChildIdx <= unsorted) {
        if (data.at(leftChildIdx) > data.at(rightChildIdx)) {
            child = data.at(leftChildIdx);
            which = leftChildIdx;
        } else {
            child = data.at(rightChildIdx);
            which = rightChildIdx;
        }
        return true;
    } else if (leftChildIdx <= unsorted) {
        child = data.at(leftChildIdx);
        which = leftChildIdx;
        return true;
    } else if (rightChildIdx <= unsorted) {
        child = data.at(rightChildIdx);
        which = rightChildIdx;
        return true;
    }
    return false;
}

void push_down (vector<El>& data, int unsorted)
{// Precondition:
    assert (is_a_heap (data, make_slice (1,unsorted)));
/*  Postcondition:
    is_a_heap (data, make_slice (0,unsorted+1))
*/
    // implement this function
//    int largestChildIdx;
//    El largestChild;
//
//    while (largest_child(data, parent, unsorted, largestChild, largestChildIdx)) {
//        if (data[parent] < largestChild) {
//            swap(data[parent], data[largestChildIdx]);
//            parent = largestChildIdx;
//        } else {
//            break;
//        }
//    }
    int i = 0;

    int j = 0;

    El child;
    while(largest_child(data, i, unsorted, child, j) && data.at(i) < child) {
        
        swap(data.at(i), data.at(j));
        
        i = j;
    }
}

void build_heap ( vector<El>& data )
{// Precondition:
    assert (true );
/*  Postcondition:
    is_a_heap (data, make_slice (0, ssize (data)))
*/
    // implement this function
    for (int i = 1; i < ssize(data); i++) {
        push_up(data, i);
    }
}

void pick_heap (vector<El>& data)
{// Precondition:
    assert (is_a_heap (data, make_slice (data)));
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement < and ==)
*/
    // implement this function
    for(int unsorted = size(data) - 1; unsorted > 0; unsorted--) {

    swap(data.at(0), data.at(unsorted));

    push_down(data, unsorted - 1);

    }
}

void heap_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement < and ==)
*/
    // implement this function
    build_heap(data);
    pick_heap(data, ssize(data) - 1);
}

/**********************************************************************************************************
 *
 * main function:
 *
 *********************************************************************************************************/
enum SortAlgorithm
{
    InsertionSort,
    SelectionSort,
    BubbleSort,
    HeapSort
};

const int SORT_ALGORITHMS = HeapSort + 1;
const string SORT_ALGORITHM_NAMES[SORT_ALGORITHMS] = {
    "Insertion sort",
    "Selection sort",
    "Bubble sort",
    "Heap sort"
};

bool load_database (string filename, vector<El>& database)
{// Precondition:
    assert (true);
/*  Postcondition:
    `database` contains database loaded from file `filename` and return value is true if no errors occurred.
    return value is false otherwise.
*/
    ifstream database_file(filename);
    El element;

    if(!database_file.is_open()) {
        return false;
    }

    while(database_file >> element) {
        database.push_back(element);
    }

    return true;
}

SortAlgorithm get_sort_algorithm()
{// Precondition:
    assert (true);
/*  Postcondition:
    return value is the user chosen sorting algorithm.
*/
    int choice;

    do {
        cout << "\nSelect a sorting algorithm" << endl;
        for(int i = 1; i <= SORT_ALGORITHMS; i++) {
            cout << i << ". " << SORT_ALGORITHM_NAMES[i - 1] << endl;
        }

        cout << "> ";
        cin >> choice;

        if(choice < 1 || choice > SORT_ALGORITHMS) {
            cout << "Invalid sorting algorithm" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while(choice < 1 || choice > SORT_ALGORITHMS);

    return static_cast<SortAlgorithm>(choice - 1);
}

#ifndef TESTING
int main()
{// Precondition:
    assert (true) ;
/*  Postcondition:
    The music database "Tracks.txt" has been read (if present and correctly formatted).
    The sorted database has been printed according to the user selected sorting algorithm.
*/
    vector<El> database;

    if(!load_database("Tracks.txt", database)) {
        cout << "Error: could not open Tracks.txt" << endl;
        return 1;
    }

    cout << "Loaded " << ssize(database) << " element(s) from database" << endl;
    SortAlgorithm algorithm = get_sort_algorithm();
    cout << "Sorting database using " << SORT_ALGORITHM_NAMES[algorithm] << endl;

    switch(algorithm)
    {
        case InsertionSort:
            insertion_sort(database);
            break;
        case SelectionSort:
            selection_sort(database);
            break;
        case BubbleSort:
            bubble_sort(database);
            break;
        case HeapSort:
            heap_sort(database);
            break;
    }

    cout << "Showing sorted database:" << endl;
    for(int i = 0; i < ssize(database); i++) {
        cout << database.at(i) << endl;
    }

	return 0;
}
#endif
