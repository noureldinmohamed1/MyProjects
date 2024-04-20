# File: CS112_A1_T2_3_20230444.py
# Purpose:
# 1- This Game Is Played By Two Players
# 2- Each Player Chooses A Perfect Square Number Of Coins To Take It From The Pile Of Coins Alternatively
# 3- The Player Who Take The Last Coin Is The Winner
# Author: Nour Eldin Mohamed Amin
# ID: 20230444

# Use (random) Library To Set Coins As A Random Number
import random

# Function To Check If The Number Is A Perfect Square
def Square_Check(num):
    for i in range(1,num//2+2):
        if i * i == num:
            return True

# The Start Of The Game
def main():

    # Game Display
    print("Welcome To Subtract A Square Game.")
    print("Do You Want To Choose The Number Of Coins Or Make It Random ?")
    print("Enter 1 If You Want To Choose The Number Of Coins.")
    print("Enter 2 If You Want To Make The Number Of Coins Random.")

    # Determine How To Set The Number Of Coins
    while True:
        try:
            ans = int(input("Enter Your Choise: "))
            if ans == 1 or ans == 2:
                break
            else:
                print("Your Choise Must Be 1 Or 2.")
        except:
            print("Your Choise Must Be 1 Or 2.")

    # If User Chose 1
    if ans == 1:
        while True:
            try:
                coins = int(input("Choose The Number Of Coins Between 10 And 1000 And Your Choise Must Not Be A Perfect Square Number: "))
            except:
                print("Your Input Must Be An Integer Number Between 10 And 1000 And Must Not Be A Perfect Square Number.")
                continue
            if coins > 1000 or coins < 10:
                print("Your Choise Must Be Between 10 And 1000.")
            elif Square_Check(coins):
                print("Your Choise Must Not Be A Perfect Square Number.")
            else:
                break
        print("The Number Of Coins Is: {}.".format(coins))

    #If User Chose 2
    elif ans == 2:
        while True:
            # Set Coins As A Random Number From 100 To 500
            coins = random.randint(100 , 500)
            if Square_Check(coins) is not True:
                break
        print("The Number Of Coins Is: {}.".format(coins))

    # Let's Start To Play
    while coins > 0:

        # Player One's Turn
        while True:
            try:
                num1 = int(input("Player One, Enter A Perfect Square Number Of Coins To Take It From The Pile Of Coins: "))
            except:
                print("Your Input Must Be A Perfect Square Integer Number.")
                continue

            # Check If The Number Is A Valid Or Not
            if Square_Check(num1) is True and num1 <= coins:
                break
            else:
                if num1 > coins:
                    print("{} Is Greater Than The Number Of Coins Which Is {}.".format(num1,coins))
                elif num1 <= 0:
                    print("{} Is Not A Valid Number".format(num1))
                elif Square_Check(num1) is not True:
                    print("{} Is Not A Perfect Square Number.".format(num1))

        # Update The Number Of Coins
        coins -= num1
        print("Now The Number Of Coins Is: {}.".format(coins))

        # Check If Player One Wins
        if coins == 0:
            print("Player One Is The Winner 🥳.")
            break

        # Player Two's Turn
        while True:
            try:
                num2 = int(input("Player Two, Enter A Perfect Square Number Of Coins To Take It From The Pile Of Coins: "))
            except:
                print("Your Input Must Be A Perfect Square Integer Number.")
                continue
            # Check If The Number Is A Valid Or Not
            if Square_Check(num2) is True and num2 <= coins:
                break
            else:
                if num2 > coins:
                    print("{} Is Greater Than Number Of Coins Which Is {}.".format(num2,coins))
                elif num2 <= 0:
                    print("{} Is Not A Valid Number".format(num2))
                elif Square_Check(num2) is not True:
                    print("{} Is Not A Perfect Square Number.".format(num2))

        # Update Coins
        coins -= num2
        print("Now The Number Of Coins Is: {}.".format(coins))

        # Check If Player Two Wins
        if coins == 0:
            print("Player Two Is The Winner 🥳.")

main()
