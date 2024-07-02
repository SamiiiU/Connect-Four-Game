#include <iostream>
#include <array>
#include <string>

char arr[6][8];

void Print_Table(char arr[6][8]);
int RowCheck(int R, int C);
char check_player(char);
char check_T(char arr[6][8]);
char winner_char(char arr[6][8]);

int main(){ 
    std::string start;
    do{
        int Row = 0, Colomn = 3, count = 0;
        char winner = ' ', player = 'X', table = ' ';
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 8; j++) {
                arr[i][j] = ' '; // filling table  with empty spaces ;
            }
        }

        Print_Table(arr); // printing an empty table

        std::cout << "Welcome to the Matching game \nEnter the Colomn (0-6) \n";

        while (winner == ' ')
        {

            std::cout << "Player " << player << " turn : ";
            std::cin >> Colomn;

            if (!(Colomn >= 0 && Colomn <= 6))
            { // agar 6 sai bara colomn daalay tou wo invalid ho
                std::cout << "invalid Move Try again \n";
                continue;
            }

            Row = RowCheck(-1, Colomn);
            if (Row == -1){ // agar row -1 hai tou matlab us kai sarai colomn full hai
                std::cout << "This Colomn is full! \n";
                std::cout << "Enter any other colomn except " << Colomn << "\n";}
            else{ // Row may jaga hai
                arr[Row][Colomn] = player;

                Print_Table(arr);

                player = check_player(player);

                winner = winner_char(arr);

                if (check_T(arr) == 'F')
                    break;
            }

        } // ending while loop

        if (winner != ' ') // agar koi winner aya
            std::cout << "The winner is Player " << winner << "\n";
        else // warna board full hua hai
            std::cout << "The board got full\n";

        std::cout << "Enter \"Yes\" To start again : ";
        std::cin >> start;

    } while (start == "yes" || start == "YES");

    std::cout << "The game is over !\n";

    return 0;
}

void Print_Table(char arr[6][8]){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 8; j++){
            std::cout << '|' << arr[i][j];
        }
        std::cout << "\n";
    }
}

int RowCheck(int R, int C){
    for (int i = 0; i < 7; i++){
        if (arr[i][C] == ' ')
            R = i;
    }
    return R;   }

char check_player(char player){
    if (player == 'X')
        return '0';
    else
        return 'X';
}

char check_T(char arr[6][8]){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            if (arr[i][j] == ' ')
                return ' ';
        }
    }
    return 'F';
}

char winner_char(char arr[6][8]){
    int count = 0;

    // for horizontal checking
    for (int k = 0; k < 4; k++){
        for (int i = 5; i >= 0; i--){
            for (int j = 0; j <= 2; j++){
                if (arr[i][j + k] == arr[i][j + k + 1] && arr[i][j + k] != ' ')
                    count++; }
            if (count == 3)
                return arr[i][k];
            count = 0;
        }
    }

    // for vertical checking
    for (int k = 0; k < 4; k++){
        for (int i = 0; i <= 6; i++){
            for (int j = 5; j >= 3; j--){
                if (arr[j - k][i] == arr[j - k - 1][i] && arr[j - k][i] != ' ')
                    count++;
            }
            if (count == 3)
                return arr[k + 2][i];
            count = 0;
        }
    }

    // for diognal L to R

    for (int k = 0; k < 3; k++){
        for (int i = 0; i < 3 - k; i++){
            for (int j = 0; j < 3; j++){
                if (arr[i + j + k][j + i] == arr[i + j + k + 1][i + j + 1])
                    count++;}
            if (count == 3)
                return arr[k + i][i];
            count = 0; } 
    }
    for (int k = 1; k <= 3; k++){
        for (int i = 0; i <= 3 - k; i++){
            for (int j = 0; j < 3; j++){
                if (arr[i + j][j + i + k] == arr[i + j + 1][i + j + k + 1])
                    count++;}
            if (count == 3)
                return arr[i][k + i];
            count = 0;}
    }

    return ' ';
}


