//Program:
//1- This Game Is Played By Two Players.
//2- Each Player Chooses A Perfect Square Number Of Coins To Take It From The Pile Of Coins Alternatively.
//3- The Player Who Removes The Last Coin Is The Winner.
//Author: Nour Eldin Mohamed Amin
//Section: None
//ID: 20230444
//Version: 1.0
//Date: 28 Feb 2024

#include <iostream>
#include "string"

// Use (cstdlib) Library and (ctime) Library To Set Coins As A Random Number.
#include <cstdlib>
#include <ctime>

using namespace std;

// Function To Check If The Number Is A Perfect Square.
int Square_Check(int num)
{
    for (int i = 1; i <= num/2+1; ++i) {
        if (i * i == num)
            return true;
    }
    return false;
}

// The Start Of The Game.
int main() {

    // Game Display
    cout << "Welcome To Subtract A Square Game" <<endl;
    cout << "Do You Want To Choose The Number Of Coins Or Make It Random ?" <<endl;
    cout << "Enter 1 If You Want To Choose The Number Of Coins." <<endl;
    cout << "Enter 2 If You Want To Make The Number Of Coins Random." <<endl;

    // Determine How To Set The Number Of Coins.
    string ans , coins;
    int n1 , n_coins , n2;
    bool flag;
    while (true)
    {
        cout << "Enter Your Choise: " <<endl;
        getline(cin , ans);
        if (ans != "1" && ans != "2")
            cout << "Your Choise Must Be 1 Or 2." <<endl;
        else
            break;
    }

    // If User Chose 1.
    if (ans == "1") {
        while (true) {
            flag = false;
            cout << "Choose The Number Of Coins Between 10 And 1000 And Your Choise Must Not Be A Perfect Square Number: "<< endl;
            getline(cin , coins);
            for (int i = 0; i < coins.size(); ++i) {
                if (coins[i] >= '0' && coins[i] <= '9')
                    flag = true;
                else
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                cout << "Your Input Must Be An Integer Number Between 10 And 1000 And Must Not Be A Perfect Square Number."<< endl;
                continue;
            }
            n_coins = stoi(coins);
            if (n_coins > 1000 || n_coins < 10)
                cout << "Your Input Must Be An Integer Number Between 10 And 1000 And Must Not Be A Perfect Square Number."<< endl;
            else if (Square_Check(n_coins))
                cout << "Your Choise Must Not Be A Perfect Square Number." << endl;
            else
                break;
        }
        cout << "The Number Of Coins Is: " << n_coins << endl;
    }

        // If User Chose 2.
    else if (ans == "2")
    {
        int c;
        while (true)
        {
            // Set Coins As A Random Number From 100 To 500.
            srand(time(NULL));
            c = rand() % 500 + 100;
            if (Square_Check(c) == false)
                break;
        }
        n_coins = c;
        cout << "The Number Of Coins Is: " << n_coins <<endl;
    }

    // Let's Start To Play.
    while (n_coins > 0)
    {
        // Player One's Turn.
        string num1;
        while (true)
        {
            flag = false;
            cout << "Player One, Enter A Perfect Square Number Of Coins To Take It From The Pile Of Coins: " <<endl;
            getline(cin , num1);
            for (int i = 0; i < num1.size(); ++i) {
                if (num1[i] >= '0' && num1[i] <= '9')
                    flag = true;
                else
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                cout << num1 <<" Is Not A Valid Input." <<endl;
                continue;
            }
            n1 = stoi(num1);
            // Check If The Number Is A Valid Or Not.
            if (Square_Check(n1) && n1 <= n_coins)
                break;
            else
            {
                if (n1 > n_coins)
                    cout << n1 << " Is Greater Than The Number Of Coins Which Is " <<n_coins <<endl;
                else if (n1 <= 0)
                    cout << n1 <<" Is Not A Valid Number." <<endl;
                else if (!Square_Check(n1))
                    cout << n1 <<" Is Not A Perfect Square Number." <<endl;
            }
        }

        // Update The Number Of Coins.
        n_coins -= n1;
        cout << "Now The Number Of Coins Is: " <<n_coins <<endl;

        // Check If Player One Wins.
        if (n_coins == 0)
        {
            cout << "Player One Is The Winner." <<endl;
            break;
        }

        // Player Two's Turn.
        string num2;
        while (true)
        {
            cout << "Player Two, Enter A Perfect Square Number Of Coins To Take It From The Pile Of Coins: " <<endl;
            getline(cin , num2);
            for (int i = 0; i < num2.size(); ++i) {
                if (num2[i] >= '0' && num2[i] <= '9')
                    flag = true;
                else
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                cout << num2 <<" Is Not A Valid Input." <<endl;
                continue;
            }

            n2 = stoi(num2);

            // Check If The Number Is A Valid Or Not.
            if (Square_Check(n2) && n2 <= n_coins)
                break;
            else
            {
                if (n2 > n_coins)
                    cout << n2 << " Is Greater Than The Number Of Coins Which Is " <<n_coins <<endl;
                else if (n2 <= 0)
                    cout << n2 <<" Is Not A Valid Number." <<endl;
                else if (!Square_Check(n2))
                    cout << n2 <<" Is Not A Perfect Square Number." <<endl;
            }
        }

        // Update The Number Of Coins.
        n_coins -= n2;
        cout << "Now The Number Of Coins Is: " << n_coins <<endl;

        // Check If Player Two Wins.
        if (n_coins == 0)
        {
            cout << "Player Two Is The Winner." <<endl;
            break;
        }
    }

    return 0;
}

