#include <iostream>
using namespace std;

class Game {
    public:
        string line = "-----------";
        string row1 = " 1 | 2 | 3 ";
        string row2 = " 4 | 5 | 6 ";
        string row3 = " 7 | 8 | 9 ";
        char turn = 'x';

        void display_board() {
            cout<<row1<<endl<<line<<endl<<row2<<endl<<line<<endl<<row3<<endl;
        };

        void update_display(string input) {
            if (input == "1" || input == "2" || input == "3") {
                int index = row1.find(input);
                row1[index] = turn;
            };
        };
};

int main() {
    cout << "Tic-Tac-Toe" << endl;
    Game game;
    game.display_board();
    game.update_display("1");
    game.display_board();
    return 0;
}