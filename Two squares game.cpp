//Program:
//1- This game is played by two players.
//2- There is a board consists of 4 rows and 4 columns of squares, every square has one number from 1 to 16 in the order.
//3- Every player chooses two adjacent numbers to remove it from the board.
//4- The player who can not choose any two adjacent numbers is the loser, and the other player is the winner.
//Author: Nour Eldin Mohamed Amin
//Section: None
//ID: 20230444
//Version: 1.0
//Date: 1 Mar 2024

#include <bits/stdc++.h>
using namespace std;

// Function to check if the number has any adjacent numbers or not.
// If the number has any adjacent numbers, the function returns true and continue playing.
// Other than that the function returns false and display an error message.
int check_possibility(int x , vector<int>v)
{
    bool flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 1) flag1 = true;
        if (i == 2 || i == 5) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 2) flag1 = true;
        if (i == 3 || i == 1 || i == 6) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 3) flag1 = true;
        if (i == 2 || i == 4 || i == 7) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 4) flag1 = true;
        if (i == 3 || i == 8) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 5) flag1 = true;
        if (i == 1 || i == 9 || i == 6) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 6) flag1 = true;
        if (i == 2 || i == 5 || i == 7 || i == 10) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 7) flag1 = true;
        if (i == 3 || i == 6 || i == 8 || i == 11) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 8) flag1 = true;
        if (i == 4 || i == 12 || i == 7) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 9) flag1 = true;
        if (i == 13 || i == 5 || i == 10) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 10) flag1 = true;
        if (i == 6 || i == 9 || i == 11 || i == 14) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 11) flag1 = true;
        if (i == 7 || i == 15 || i == 12 || i == 10) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 12) flag1 = true;
        if (i == 8 || i == 11 || i == 16) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 13) flag1 = true;
        if (i == 9 || i == 14) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 14) flag1 = true;
        if (i == 13 || i == 15 || i == 10) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 15) flag1 = true;
        if (i == 11 || i == 14 || i == 16) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (x == 16) flag1 = true;
        if (i == 12 || i == 15 ) flag2 = true;
    }
    if (flag1 && flag2) return true;

    return false;
}


// Function to check if the player wins or not.
// If any number exists and any of its adjacent numbers exists, the function returns true and continue playing.
// Other than that the function returns false, that means that one of the two players won.
int check_winner(vector<int>v)
{
    bool flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 1) flag1 = true;
        if (i == 2 || i == 5) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 2) flag1 = true;
        if (i == 3 || i == 1 || i == 6) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 3) flag1 = true;
        if (i == 2 || i == 4 || i == 7) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 4) flag1 = true;
        if (i == 3 || i == 8) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 5) flag1 = true;
        if (i == 1 || i == 9 || i == 6) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 6) flag1 = true;
        if (i == 2 || i == 5 || i == 7 || i == 10) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 7) flag1 = true;
        if (i == 3 || i == 6 || i == 8 || i == 11) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 8) flag1 = true;
        if (i == 4 || i == 12 || i == 7) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 9) flag1 = true;
        if (i == 13 || i == 5 || i == 10) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 10) flag1 = true;
        if (i == 6 || i == 9 || i == 11 || i == 14) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 11) flag1 = true;
        if (i == 7 || i == 15 || i == 12 || i == 10) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 12) flag1 = true;
        if (i == 8 || i == 11 || i == 16) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 13) flag1 = true;
        if (i == 9 || i == 14) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 14) flag1 = true;
        if (i == 13 || i == 15 || i == 10) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 15) flag1 = true;
        if (i == 11 || i == 14 || i == 16) flag2 = true;
    }
    if (flag1 && flag2) return true;

    flag1 = false , flag2 = false;
    for (int i : v)
    {
        if (i == 16) flag1 = true;
        if (i == 12 || i == 15 ) flag2 = true;
    }
    if (flag1 && flag2) return true;

    return false;
}

// Function to check if the player chose two adjacent number or not.
// If the player chose any number and any of its adjacent numbers, the function returns true and continue playing.
// Other than that the function returns false and display an error message.
int adjacent(string ch1 , string ch2)
{
    if (ch1 == "1" && (ch2 == "2" || ch2 == "5"))
    {return true;}
    else if (ch1 == "2" && (ch2 == "1" || ch2 == "3" || ch2 == "6"))
    {return true;}
    else if (ch1 == "3" && (ch2 == "2" || ch2 == "4" || ch2 == "7"))
    {return true;}
    else if (ch1 == "4" && (ch2 == "8" || ch2 == "3"))
    {return true;}
    else if (ch1 == "5" && (ch2 == "1" || ch2 == "9" || ch2 == "6"))
    {return true;}
    else if (ch1 == "6" && (ch2 == "2" || ch2 == "5" || ch2 == "7" || ch2 == "10"))
    {return true;}
    else if (ch1 == "7" && (ch2 == "3" || ch2 == "6" || ch2 == "8" || ch2 == "11"))
    {return true;}
    else if (ch1 == "8" && (ch2 == "4" || ch2 == "12" || ch2 == "7" ))
    {return true;}
    else if (ch1 == "9" && (ch2 == "5" || ch2 == "13" || ch2 == "10"))
    {return true;}
    else if (ch1 == "10" && (ch2 == "6" || ch2 == "9" || ch2 == "11" || ch2 == "14"))
    {return true;}
    else if (ch1 == "11" && (ch2 == "7" || ch2 == "12" || ch2 == "15" || ch2 == "10"))
    {return true;}
    else if (ch1 == "12" && (ch2 == "8" || ch2 == "11" || ch2 == "16"))
    {return true;}
    else if (ch1 == "13" && (ch2 == "9" || ch2 == "14"))
    {return true;}
    else if (ch1 == "14" && (ch2 == "13" || ch2 == "15" || ch2 == "10"))
    {return true;}
    else if (ch1 == "15" && (ch2 == "11" || ch2 == "14" || ch2 == "16"))
    {return true;}
    else if (ch1 == "16" && (ch2 == "12" || ch2 == "15"))
    {return true;}
    else
        return false;
}

// The start of the game.
int main()
{
    // Create a vector contains all available numbers.
    vector<int>available_nums(16);
    available_nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    // Create the board as an array.
    string board[4][4] = {{"1", "2", "3", "4"},
                          {"5", "6", "7", "8"},
                          {"9", "10", "11", "12"},
                          {"13", "14", "15", "16"}};

    // Display Welcome Message and the board.
    cout << "Welcome to two squares game." << endl;
    cout << "This is the board:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << setw(5) << board[i][j];
        }
        cout << endl;
    }
    string ch1 , ch2;
    bool flag = false;
    int num1 , num2 , index1 , index2;

    // Player one's turn.
    while (true)
    {
        cout << "Player 1, Choose two numbers from the board." << endl;
        cout << "Note: Your choice must be two adjacent numbers, either horizontally or vertically." << endl;

        // Player one's first number.
        while (true) {
            cout << "Enter your first number:" << endl;
            getline(cin , ch1);

            // Check the validation of the number.
            for (int i = 0; i < ch1.size(); ++i) {
                if (ch1[i] > '9' || ch1[i] < '0') {
                    flag = false;
                    break;
                } else if (stoi(ch1) > 16 || stoi(ch1) < 1) {
                    flag = false;
                    break;
                } else {
                    flag = true;
                }
            }
            if (!flag) {
                cout << "Your input is not a valid number." << endl;
            } else if (flag) {
                flag = false;
                for (int i = 0; i < available_nums.size(); ++i) {
                    if (available_nums.at(i) == stoi(ch1)) {
                        flag = true;
                        num1 = stoi(ch1);
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (!flag)
                    cout << "Your choice has been taken before." << endl;
                else if (flag)
                {
                    if (check_possibility(num1 , available_nums))
                        break;
                    else
                        cout << "You can not choose this number, because it has no adjacent numbers." <<endl;
                }
            }
        }

        // Player one's second number
        while (true)
        {
            flag = false;
            cout << "Enter your second number:" <<endl;
            getline(cin , ch2);

            // Check the validation of the number.
            if (ch1 == ch2)
            {
                cout << "Your two numbers must not be equal." <<endl;
                continue;
            }
            for (int i = 0; i < ch2.size(); ++i) {
                if (ch2[i] > '9' || ch2[i] < '0')
                {
                    flag = false;
                    break;
                }
                else if (stoi(ch2) > 16 || stoi(ch2) < 1)
                {
                    flag = false;
                    break;
                }
                else
                {
                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "Your input is not a valid number." <<endl;
            }
            else if (flag)
            {
                flag = false;
                for (int i = 0; i < available_nums.size() ; ++i)
                {
                    if (available_nums.at(i) == stoi(ch2))
                    {
                        flag = true;
                        num2 = stoi(ch2);
                        break;
                    }
                    else
                    {
                        flag = false;
                    }
                }
                if (!flag)
                    cout << "Your choice has been taken before." <<endl;
                else if (adjacent(ch1 , ch2) == false)
                {
                    cout << "Your two numbers must be adjacent." <<endl;
                    continue;
                }
                else if (flag)
                    break;
            }
        }

        // Remove the two numbers which have been chosen from the vector(available numbers).
        for (int i = 0; i < available_nums.size(); ++i) {
            if (available_nums.at(i) == num1)
            {
                index1 = i;
            }
            else if (available_nums.at(i) == num2)
            {
                index2 = i;
            }
        }
        available_nums.erase(available_nums.begin() + index1);
        if (num1 > num2)
            available_nums.erase(available_nums.begin() + index2);
        else
            available_nums.erase(available_nums.begin() + index2 - 1);

        // Display the board after removing.
        cout << "Now the board became:" <<endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (board[i][j] == ch1 || board[i][j] == ch2)
                {
                    board[i][j] = "X";
                }
                cout << setw(5) << board[i][j];
            }
            cout << endl;
        }

        // Check if player one won.
        if (check_winner(available_nums) == false)
        {
            cout << "Player one is the winner." <<endl;
            break;
        }



        // Player two's turn
        cout << "Player 2, Choose two numbers from the board." << endl;
        cout << "Note: Your choice must be two adjacent numbers, either horizontally or vertically." << endl;

        // Player two's first number
        while (true) {
            cout << "Enter your first number:" << endl;
            getline(cin , ch1);

            // Check the validation of the number.
            for (int i = 0; i < ch1.size(); ++i) {
                if (ch1[i] > '9' || ch1[i] < '0') {
                    flag = false;
                    break;
                } else if (stoi(ch1) > 16 || stoi(ch1) < 1) {
                    flag = false;
                    break;
                } else {
                    flag = true;
                }
            }
            if (!flag) {
                cout << "Your input is not a valid number." << endl;
            } else if (flag) {
                flag = false;
                for (int i = 0; i < available_nums.size(); ++i) {
                    if (available_nums.at(i) == stoi(ch1)) {
                        flag = true;
                        num1 = stoi(ch1);
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (!flag)
                    cout << "Your choice has been taken before." << endl;
                else if (flag)
                {
                    if (check_possibility(num1 , available_nums))
                        break;
                    else
                        cout << "You can not choose this number, because it has no adjacent numbers." <<endl;
                }
            }
        }

        // Player two's second number
        while (true)
        {
            flag = false;
            cout << "Enter your second number:" <<endl;
            getline(cin , ch2);

            // Check the validation of the number.
            if (ch1 == ch2)
            {
                cout << "Your two numbers must not be equal." <<endl;
                continue;
            }
            for (int i = 0; i < ch2.size(); ++i) {
                if (ch2[i] > '9' || ch2[i] < '0')
                {
                    flag = false;
                    break;
                }
                else if (stoi(ch2) > 16 || stoi(ch2) < 1)
                {
                    flag = false;
                    break;
                }
                else
                {
                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "Your input is not a valid number." <<endl;
            }
            else if (flag)
            {
                flag = false;
                for (int i = 0; i < available_nums.size() ; ++i)
                {
                    if (available_nums.at(i) == stoi(ch2))
                    {
                        flag = true;
                        num2 = stoi(ch2);
                        break;
                    }
                    else
                    {
                        flag = false;
                    }
                }
                if (!flag)
                    cout << "Your choice has been taken before." <<endl;
                else if (adjacent(ch1 , ch2) == false)
                {
                    cout << "Your two numbers must be adjacent." <<endl;
                    continue;
                }
                else if (flag)
                    break;
            }
        }

        // Remove the two numbers which have been chosen from the vector(available numbers).
        for (int i = 0; i < available_nums.size(); ++i) {
            if (available_nums.at(i) == num1)
            {
                index1 = i;
            }
            else if (available_nums.at(i) == num2)
            {
                index2 = i;
            }
        }
        available_nums.erase(available_nums.begin() + index1);
        if (num1 > num2)
            available_nums.erase(available_nums.begin() + index2);
        else
            available_nums.erase(available_nums.begin() + index2 - 1);

        // Display the board after removing.
        cout << "Now the board became:" <<endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (board[i][j] == ch1 || board[i][j] == ch2)
                {
                    board[i][j] = "X";
                }
                cout << setw(5) << board[i][j];
            }
            cout << endl;
        }

        // Check if player one won.
        if (check_winner(available_nums) == false)
        {
            cout << "Player two is the winner." <<endl;
            break;
        }
    }

    return 0;
}
