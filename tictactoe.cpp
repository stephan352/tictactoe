#include <iostream>
using namespace std;

class Game {
    public:
        string line = "-----------";
        string row1 = " 1 | 2 | 3 ";
        string row2 = " 4 | 5 | 6 ";
        string row3 = " 7 | 8 | 9 ";

        void display_board() {
            cout<<row1<<endl<<line<<endl<<row2<<endl<<line<<endl<<row3;
        };

        void update_display(string input) {
            // if (input == "1" || input == "2" || input == "3") {
            //     row1.
            // }
        }
};

int main() {
    cout << "Tic-Tac-Toe" << endl;
    Game game;
    game.display_board();
    return 0;
}