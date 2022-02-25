#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

class Game {
    public:
        string line = "-----------";
        string row1 = " 1 | 2 | 3 ";
        string row2 = " 4 | 5 | 6 ";
        string row3 = " 7 | 8 | 9 ";
        char turn = 'x';
        vector<int> available_answer = {1,2,3,4,5,6,7,8,9};

        void Play() {
            cout<<endl<<"Tic-Tac-toe!"<<endl;
            cout<<endl<<"Type a number from 1 to 9 to put a symbol, starting with x."<<endl;
            while (available_answer.size() > 0) {
                DisplayBoard();
                DemandInput();
                ToggleTurn();
            }
            DisplayBoard();
        }

        void DisplayBoard() {
            cout<<row1<<endl<<line<<endl<<row2<<endl<<line<<endl<<row3<<endl<<endl;
        };

        void UpdateDisplay(string input) {
            if (input == "1" || input == "2" || input == "3") {
                int index = row1.find(input);
                row1[index] = turn;
            } else if (input == "4" || input == "5" || input == "6") {
                int index = row2.find(input);
                row2[index] = turn;
            } else if (input == "7" || input == "8" || input == "9") {
                int index = row3.find(input);
                row3[index] = turn;
            }
        };

        bool CheckInput(string input) {
            stringstream input_object(input);
            int int_input;
            input_object>>int_input;
            auto found = find(begin(available_answer), end(available_answer), int_input);
            if (found != end(available_answer)) {
                return true;
            } else {
                return false;
            }
        };

        void DemandInput() {
            string input;
            cin >> input;
            while (!CheckInput(input)) {
                cout << "please input a number available on the board." << endl;
                cin >> input;
            };
            UpdateDisplay(input);

            stringstream input_object(input);
            int int_input;
            input_object>>int_input;
            available_answer.erase(std::remove(available_answer.begin(), available_answer.end(), int_input), available_answer.end());
        };

        void ToggleTurn() {
            if (turn == 'x') {
                turn = 'o';
            } else if (turn == 'o') {
                turn = 'x';
            }
        };
};

int main() {
    Game game;
    game.Play();
    return 0;
}