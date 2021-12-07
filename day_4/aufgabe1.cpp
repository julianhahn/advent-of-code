#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

namespace std {
    class field{
        public:
            bool checked = false;
            int value = 0;
    };

    class board {
        public: 
            vector<vector<field>> boardFields;
            void markField(int value){
                for(vector<field> row: boardFields){
                    for(field current : row){
                        if(current.value == value)
                            current.checked = true;
                    }
                }
            }
            bool hasWon(){
                bool winning;
                //check every horizontal
                for(vector<field> row : boardFields){
                    // jede Reihe könnte man neu gewinnen
                    winning = true;
                    // ist aber ein feld falsch, kann man mit der Reihe schon aufhören
                    for(field current : row){
                        if(current.checked == false){
                            winning = false;
                            break;
                        }
                    }
                }
                //check every vertical
                for(int col = 0; col < boardFields[0].size(); col++){
                    //jede spalte könnte gewinnen
                    winning = true;
                    for (int row = 0; row < boardFields.size(); row++)
                    {
                        if(boardFields[row][col].checked == false){
                            winning = false;
                            break;
                        }
                    }
                    
                }
                return winning;
            }
            void initializeField(){
                for (int rowCount = 0; rowCount < 5; rowCount++)
                {
                    vector<field> row;
                    for (int collumCount = 0; collumCount < 5; collumCount++)
                    {
                        field newField;
                        row.push_back(newField);
                    }
                    boardFields.push_back(row);
                }
            }
    };
}


int main(int argc, char const *argv[])
{
    ifstream file ("boards_test.txt");
    vector<board> boards;
    string input;
    
    int numberCount = 0;
    int rowCount = 0;
    int collumCount = 0;
    board currentBoard;
    currentBoard.initializeField();

    //read single numbers from input and fill board
    while(file >> input){
        
        //after 5 numbers one row is finished
        //after 25 numbers a table is finished and a  new one must be created
        if(numberCount != 0 && numberCount % 25 == 0){
            boards.push_back(currentBoard);
            currentBoard = board();
            currentBoard.initializeField();
            rowCount = 0;
        }

        if(numberCount == 20){
            cout << "hallo";
        }
        //write to the baord
        currentBoard.boardFields[rowCount][collumCount].value = stoi(input);
        
        //then increase the counter
        if( collumCount < 4){
            collumCount++;
        }
        else if(rowCount < 4){
            collumCount= 0;
            rowCount++;
        }
        else{
            rowCount = 0;
            collumCount =0;
        }
        
        numberCount++;
    }
    boards.push_back(currentBoard);
    
    // finished to build the boards
    // now read the markings and evaluate if someone has won!

    


    return 0;
}


