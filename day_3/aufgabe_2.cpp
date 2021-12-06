#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/**
 * @brief
 * find the most common bit in the given entry list.
 * @param entries 
 * @param position the most left bit is the position 0, the most right is the position entries[0].size() 
 * @return int returns 0 or 1
 */
int findMostCommonOnBit(vector<vector<int>> entries, int position){
    //loop through all entries
        int sum_zero = 0, sum_one = 0;
        for (int j = 0; j < entries.size(); j++)
        {
            //look for the most common
            // -48 because ASCII starts at 48
            if(entries[j][position] == 1)
                sum_one++;
            else
                sum_zero++;
            //push that to the int vector */
        }
        return sum_zero > sum_one ? 0: 1;
}

void print2Dvector(vector<vector<int>> input){
    for(vector<int> entry : input){
        for( int bit : entry)
                cout << bit;
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    //read input
    ifstream file ("input.txt");
    vector<vector<int>> entries;
    string input;

    while(file >> input){
        // creates a vector that automatically? created a vector an fills it with the chars from the starting pointer of the string
        vector<char> charEntry ( input.begin(), input.end());
        vector<int> entry;
        for (char charBit : charEntry)
            entry.push_back(((int)charBit)-48);
        entries.push_back(entry);
    }

    const int bitLenght = entries[0].size();

    //calculate the oxygen generator rating 
    vector<vector<int>> matchingNumbers;
    //deep copy the entries vector
    for (vector<int> number : entries){
        vector<int> newEntry;
        for (char bit: number)
            newEntry.push_back(bit);
        matchingNumbers.push_back(newEntry);
    }
    
    for (int i = 0; i < 1; i++)
    {
        // get the most common for the current bit;
        int current_common = findMostCommonOnBit(matchingNumbers, i);
        // loop through all numbers and remove the numbers that dont match the bit
        cout << "current_common " << current_common << endl;
        int count =0;
        int size=matchingNumbers.size();
        for(int j = 0; j < size; j++){
            cout << "current first: " << matchingNumbers[j][i] << endl;
            if(matchingNumbers[j][i] != current_common){
                for(int bit : matchingNumbers[j])
                    cout << bit;
                cout << endl;
                matchingNumbers.erase(matchingNumbers.begin()+j);
            }
            count++;
        }
        cout << count;
        //print2Dvector(matchingNumbers);
    }

    //calculate the CO2 scrubber rating.
    /* code */
    return 0;
}
