#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int binaryVectorToInt( vector<int> input){
    int sum = 0;
    int exponent = 0;
    for (int i = input.size()-1; i >=0 ; i--)
    {
        sum += input[i] *  pow(2, exponent);
        exponent++;
    }
    return sum;
}

vector<int> flipBits( vector<int> input){
    vector<int> output;
    for( int bit : input )  bit == 1 ? output.push_back(0) : output.push_back(1);
    return output;
}

int main(int argc, char const *argv[])
{
    /* onyl works for one string at one line without whitespace, because the file >> expects a string witout whitepsace*/ 
    ifstream file ("input_2.txt");
    vector<vector<char>> entries;
    string input;

    while(file >> input){
        // creates a vector that automatically? created a vector an fills it with the chars from the starting pointer of the string
        vector<char> entry ( input.begin(), input.end());        
        entries.push_back(entry);
    }

    //12
    // loop through all bytes
    cout << "entries size: " << entries.size() << endl;
    vector<int> most_commons;
    for (int i = 0; i < entries[0].size(); i++)
    {
        //loop through all entries
        int sum_zero = 0, sum_one = 0;
        for (int j = 0; j < entries.size(); j++)
        {
            //look for the most common
            // -48 because ASCII starts at 48
            if((int) entries[j][i] -48 == 1)
                sum_one++;
            else
                sum_zero++;
            //push that to the int vector */
        }
        sum_zero > sum_one ? most_commons.push_back(0) : most_commons.push_back(1);
    }
    for( int digit : most_commons){
        cout << digit;
    }
    cout << endl;
    int gamma = binaryVectorToInt(most_commons);
    int epsilon = binaryVectorToInt(flipBits(most_commons));
    cout << " gamma: " << gamma << " elphi: " << epsilon<< " result: " << gamma*epsilon <<endl;
    return 0;
}