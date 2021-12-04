#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* onyl works for one string at one line without whitespace, because the file >> expects a string witout whitepsace*/ 
    ifstream file ("input.txt");
    vector<int> entries;
    string input;

    while(file >> input){
        int number = (int) input;
        entries.push_back(number);
    }

    //12
    // loop through all bytes
    for (int i = 0; i < 5; i++)
    {
        vector<int> most_commons;
        //loop through all entries
        int sum_zero = 0, sum_one = 0;
        for (int j = 0; j < 1; j++)
        {
            cout << entries[j].at(i)<<endl;
            //look for the most common
            if((int) entries[j].at(i) == 1)
                sum_one++;
            else
                sum_zero++;
            //push that to the int vector
        }
        sum_zero > sum_one ? most_commons.push_back(0) : most_commons.push_back(1);
        for( int digit : most_commons){
            cout << digit;
        }
    }
    return 0;
}

int getNumber(int number, int position){
    
}
