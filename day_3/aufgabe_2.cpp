#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
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

// 1*2^0 + 0*2^1 + 1*2^2
int binaryToDecimal(vector<int> binary){
    int sum = 0;
    int potenz = 0;
    for (int i = binary.size()-1; i >= 0; i--)
    {
        sum += binary[i] * pow(2, potenz);
        potenz++;
    }
    return sum;
}

void print2Dvector(vector<vector<int>> input){
    for(vector<int> entry : input){
        for( int bit : entry)
                cout << bit;
        cout << endl;
    }
}

vector<vector<int>> filterList(vector<vector<int>> input, int bit, bool most_common){
    //if only one is left, the result is found
    if(input.size() == 1){
        return input;
    }
    // check the input for most common
    vector<vector<int>> matchingNumbers;
    int current_common = findMostCommonOnBit(input, bit);
    for(vector<int> number: input){
        if( most_common && number[bit] == current_common) matchingNumbers.push_back(number);
        else if( !most_common && number[bit] != current_common) matchingNumbers.push_back(number);
    }
    return filterList(matchingNumbers, ++bit, most_common);
}

int main(int argc, char const *argv[])
{
    ifstream file ("input_2.txt");
    vector<vector<int>> entries;
    string input;

    //read input
    while(file >> input){
        // creates a vector that automatically? created a vector an fills it with the chars from the starting pointer of the string
        vector<char> charEntry ( input.begin(), input.end());
        vector<int> entry;
        for (char charBit : charEntry)
            entry.push_back(((int)charBit)-48);
        entries.push_back(entry);
    }

    //calculate the oxygen generator rating
    vector<int> binary_oxygen = filterList(entries, 0, true)[0];
    vector<int> binary_co2 = filterList(entries, 0, false)[0];
    int oxygen = binaryToDecimal(binary_oxygen);
    int co2 = binaryToDecimal(binary_co2);
    cout << oxygen*co2;
    return 0;
}
