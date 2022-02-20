#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Game {
    public:
        string line = "-----------";
        string row1 = " 1 | 2 | 3 ";
        string row2 = " 4 | 5 | 6 ";
        string row3 = " 7 | 8 | 9 ";
        char turn = 'x';

        void display_board() {
            cout<<row1<<endl<<line<<endl<<row2<<endl<<line<<endl<<row3<<endl<<endl;
        };

        void update_display(string input) {
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

        bool check_input(string input) {
            int accepted_answers[9] = {1,2,3,4,5,6,7,8,9};
            stringstream input_object(input);
            int int_input;
            input_object>>int_input;
            auto found = find(begin(accepted_answers), end(accepted_answers), int_input);
            if (found != end(accepted_answers)) {
                return true;
            } else {
                return false;
            }
        };

        void demand_input() {
            string input;
            cin >> input;
            cout << check_input(input) << endl;
            while (!check_input(input)) {
                cout << "please input a number from 1 to 9." << endl;
                cin >> input;
            };
            update_display(input);
        }

};

int main() {
    cout << "Tic-Tac-Toe" << endl << endl;
    Game game;
    game.display_board();
    game.demand_input();
    game.display_board();
    return 0;
}