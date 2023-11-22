#define NDEBUG // we must define this _before_ we include cassert
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

const int SLICE_STEP = 500; // The amount used when incrementing track sorting slices in each step
const int MAX_SLICE = 6500; // The maximum size of the tracks sorting slice (inclusive)

// Reuse your implementation from last week as a starting point.

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
    return out;
}

istream& operator>> (istream& in, Length& length)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the value of length has been read from in: first minutes, then ':', then seconds
*/
    // use your implementation of last week
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
    // use your implementation of last week
    return false;
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
    // use your implementation of last week
    return false;
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
    // use your implementation of last week
    return false;
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
    // use your implementation of last week
}

void insertion_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    // use your implementation of last week
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
    // use your implementation of last week
    return 0;
}

void selection_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    // use your implementation of last week
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
    // use your implementation of last week
    return false;
}

void bubble_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    // use your implementation of last week
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
    // use your implementation of last week
    return false;
}

void push_up ( vector<El>& data, int elem )
{// Precondition:
    assert (0 <= elem && elem < ssize (data) && is_a_heap (data, make_slice (0,elem)));
/*  Postcondition:
    is_a_heap (data, make_slice (0, elem+1))
*/
    // use your implementation of last week
}

void build_heap ( vector<El>& data )
{// Precondition:
    assert (true );
/*  Postcondition:
    is_a_heap (data, make_slice (0, ssize (data)))
*/
    // use your implementation of last week
}

bool largest_child (const vector<El>& data, int parent, int unsorted, El& child, int& which)
{// Precondition:
    assert (0 <= unsorted && unsorted < ssize (data));
    assert (0 <= parent && parent < ssize (data));
/*  Postcondition:
    result is true only if the element at parent in data has one or two unsorted child elements;
    only in that case the value of the largest child is child and its index position is which
*/
    // use your implementation of last week
    return false;
}

void push_down (vector<El>& data, int unsorted)
{// Precondition:
    assert (is_a_heap (data, make_slice (1,unsorted)));
/*  Postcondition:
    is_a_heap (data, make_slice (0,unsorted+1))
*/
    // use your implementation of last week
}

void pick_heap (vector<El>& data)
{// Precondition:
    assert (is_a_heap (data, make_slice (data)));
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement < and ==)
*/
    // use your implementation of last week
}

void heap_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement < and ==)
*/
    // use your implementation of last week
}

/**********************************************************************************************************
 *
 * main function:
 *
 *********************************************************************************************************/
void generate_csv (const vector<Track>& tracks, ofstream& os)
{// Precondition:
    assert (os.is_open());
    assert (ssize(tracks) >= MAX_SLICE);
/*  Postcondition:
    A CSV file has been written to `os` based on measuring the amount of operations needed to sort growing slices of `tracks`
*/
    // implement this function
}

#ifndef TESTING
int main ()
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the program has generated the csvs of measurements obtained by sorting growing slices of the music databases
*/
    ifstream tracks_file("Tracks.txt");
    ifstream sorted_file("Tracks_sorted.txt");
    ifstream random_file("Tracks_random.txt");
    ifstream reverse_file("Tracks_reverse.txt");
    ofstream tracks_csv("measurements_tracks.csv");
    ofstream sorted_csv("measurements_sorted.csv");
    ofstream random_csv("measurements_random.csv");
    ofstream reverse_csv("measurements_reverse.csv");

    if(!tracks_file.is_open()) {
        cout << "Failed to open Tracks.txt" << endl;
        return 1;
    } else if(!sorted_file.is_open()) {
        cout << "Failed to open Tracks_sorted.txt" << endl;
        return 1;
    } else if(!random_file.is_open()) {
        cout << "Failed to open Tracks_random.txt" << endl;
        return 1;
    } else if(!reverse_file.is_open()) {
        cout << "Failed to open Tracks_reverse.txt" << endl;
        return 1;
    }

    vector<Track> tracks;
    vector<Track> sorted;
    vector<Track> random;
    vector<Track> reverse;
    Track track;

    cout << "Loading databases..." << endl;
    while(tracks_file >> track) {
        tracks.push_back(track);
    }

    while(sorted_file >> track) {
        sorted.push_back(track);
    }

    while(random_file >> track) {
        random.push_back(track);
    }

    while(reverse_file >> track) {
        reverse.push_back(track);
    }

    cout << "Generating Tracks.txt measurements..." << endl;
    generate_csv(tracks, tracks_csv);
    cout << "Generating Tracks_sorted.txt measurements..." << endl;
    generate_csv(sorted, sorted_csv);
    cout << "Generating Tracks_random.txt measurements..." << endl;
    generate_csv(random, random_csv);
    cout << "Generating Tracks_reverse.txt measurements..." << endl;
    generate_csv(reverse, reverse_csv);

    return 0;
}
#endif
