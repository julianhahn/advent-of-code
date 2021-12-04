#include "iostream"
#include <fstream>
#include <string>
using namespace std;

int main(){
     ifstream inFile;
     
     inFile.open("input.txt");
     if(!inFile){
         cout << "Unable to open file";
         exit(1);
     }

     int x;
     while ( inFile >> x){
         cout << x;
     }
     return 0;
 }