/*
 * FCAI-CU – Structured Programming – 2024 - Assignment 3 - Part 3
 * Program Name: CS112_A3_Part3_S18_20230021_20230444_20230586.cpp
 * Program Description: This is a Baby Photoshop. It takes an image from the user, applies a filter or more on it, and saves the new image if needed.
 *                      This part includes 18 filters + 3 extra filters: (mirror - salt and pepper noise - pro edge detector).
 *

 * Last Modification Date: 17/4/2024

 * Author1 and ID and Group: Ahmed Sayed Ahmed, 20230021, S18
 * Author2 and ID and Group: Noureldin Mohamed Amin, 20230444, S18
 * Author3 and ID and Group: Salsabil Bahaaeldin Rohaiem, 20230586, S18

 * Who did what:
 * The main function was distributed between us.
 * In filters:
   Ahmed: Grayscale, merge images, Darken, Lighten, edge detector, pro edge detector,  sunlight, infrared photography.
   Noureldin: Black and white, flip image, Crop, resize, oil painting, image skewing, mirror.
   Salsabil: Invert image, rotate, frame, blur, TV noise, salt and pepper noise, purple, mirror.
 * In the GUI: 
   Ahmed: grayscale, black and white, edge detector, pro edge detector, blur, infrared photography, sunlight, purple, 
          rotate, invert colors, flip, load, redo buttons. Show image & GUI design.
   Noureldin: redo, undo, dark mode, merge, lighten, darken, mirror, TV noise, salt and pepper noise, skew, resize, 
              crop, oil painting, frame buttons, and shortcuts.
   Salsabil: contributed to GUI Design.

   * Documents:
     Salsabil: did all of it
 
 * Teaching Assistant: Eng. Ahmed Lotfy
 * System design: https://drive.google.com/file/d/1LNBbq697i8JFA58ojfiKUmMJvORrV484/view?usp=drive_link
 */

#include "Image_Class.h"
#include <bits/stdc++.h>
using namespace std;

void save(Image &image, string imageName){

    // Save the new image
    string newName;
    cout << "What is the image's name you want after saving?" <<endl;
    cout << "1) The same name of last loaded image.\n"
            "2) New name.\n";
    string imagename;
    while (true)
    {
        cout << "Enter your choice:" <<endl;
        getline(cin , imagename);
        if (imagename == "1" || imagename == "2")
            break;
        else
            cout << "Your choice is invalid." <<endl;
    }

    if (imagename == "1")
        newName = imageName;
    else if (imagename == "2")
    {
        while (true)
        {
            cout << "Note: the formats you can write => (jpeg, jpg, png, and bmp)." <<endl;
            cout << "Enter the name you want to save your image and the format (ex: image.png):" <<endl;
            getline(cin , newName);
            string format = "";
            bool flag = false;
            for (int i = 0; i < newName.size(); ++i) {
                if (flag)
                    format += newName[i];
                if (newName[i] == '.')
                    flag = true;
            }
            if (format != "jpeg" && format != "jpg" && format != "png" && format != "bmp")
                cout << "Please Enter a correct new name." <<endl;
            else
                break;
        }
    }
    // Save new image
    image.saveImage(newName);
    cout << "Image saved successfully.\n";
    cout << "If the image did not appear yet, it will be in the folder!" <<endl;
}

void bw(Image &image)
{
    cout << "Loading...\n";
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            unsigned int bw = 0;
            for (int k = 0; k < image.channels; ++k)
            { //image.channels = 3
                bw += image(i , j , k);
            }
            // Calculate avg
            bw/=3;
            // Set the light pixels to white and the darken to black
            for (int k = 0; k < 3; ++k) {
                if (bw > 255/2)
                    image(i , j , k) = 255;
                else
                    image(i , j , k) = 0;
            }
        }
    }
    cout << "Black and white filter has been applied.\n";
}

void grayscale(Image &image)
{
    // Load image
    cout << "Loading...\n";
    // Loop over each row , column , channel
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            // Intialize the avg value
            unsigned int avg = 0;
            for (int k = 0; k < image.channels; ++k)
            {
                avg += image(i,j,k);
            }
            // Calculate avg
            avg /= 3;

            // Set all channels to the average value
            image.setPixel(i,j,0,avg);
            image.setPixel(i,j,1,avg);
            image.setPixel(i,j,2,avg);
        }
    }
    cout << "Grayscale filter has been applied.\n";
}

void darken(Image &image)
{
    // Load image
    cout << "Loading...\n";
    // Loop over each row , column , channel
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < image.channels; ++k)
            {
                image(i,j,k) /= 2;
            }
        }
    }
    cout << "Darken filter has been applied.\n";
}

void lighten(Image &image)
{
    // Load image
    cout << "Loading...\n";
    // Loop over each row , column , channel
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < image.channels; ++k)
            {
                if(1.5 * image(i,j,k) >= 255)
                    image(i,j,k) = 255;
                else
                    image(i,j,k) *= 1.5;
            }
        }
    }
    cout << "Lighten filter has been applied.\n";
}

void flip (Image &image)
{
    Image image2 (image.width , image.height);
    cout << "How do you want to flip the image." <<endl;
    cout << "1) horizontally.\n"
            "2) vertically.\n";
    string choice;
    while (true)
    {
        cout << "Enter your choice:" <<endl;
        getline(cin , choice);
        if (choice == "1" || choice == "2")
            break;
        else
            cout << "Your choice is invalid." <<endl;
    }
    cout << "Loading...\n";
    if (choice == "1")
    {
        for (int i = 0; i < image.width/2; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    swap(image(i , j , k) , image(image.width-i-1 , j , k));
                }
            }
        }
    }
    else if (choice == "2")
    {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height/2; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    swap(image(i , j , k) , image(i , image.height-j-1 , k));
                }
            }
        }
    }
    cout << "Flip filter has been applied.\n";
}

void crop(Image &image)
{
    cout << "Enter the point you want to crop from." << endl;
    cout << "Note: the point can not exceed the image's dimensions." << endl;
    cout << "The image's dimensions ==> (" << image.width << ", " << image.height << ")" <<endl;
    string x;
    while (true)
    {
        cout << "Enter X:" << endl;
        getline(cin , x);
        if (x[0] == '0' || x.empty())
        {
            cout << "Your input is invalid." << endl;
            continue;
        }
        bool flag = true;
        for (int i = 0; i < x.size(); ++i) {
            if (!isdigit(x[i]))
            {
                cout << "Your input is invalid." << endl;
                flag = false;
                break;
            }
            else if (stoll(x) > image.width || stoll(x) < 0)
            {
                cout << "Your input exceeds the dimensions of the image." << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    }
    string y;
    while (true)
    {
        cout << "Enter Y:" << endl;
        getline(cin , y);
        if (y[0] == '0' || y.empty())
        {
            cout << "Your input is invalid." << endl;
            continue;
        }
        bool flag = true;
        for (int i = 0; i < y.size(); ++i) {
            if (!isdigit(y[i]))
            {
                cout << "Your input is invalid." << endl;
                flag = false;
                break;
            }
            else if (stoll(x) > image.height || stoll(x) < 0)
            {
                cout << "Your input exceeds the dimensions of the image." << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    }
    cout << "Enter the new dimensions you want to crop to."<< endl;
    cout << "Note: the new dimensions can not exceed the image's dimensions." << endl;
    cout << "The image's dimensions ==> (" << image.width <<", " <<image.height << ")" << endl;
    string width;
    while (true)
    {
        cout << "Enter the width:" << endl;
        getline(cin , width);
        if (width[0] == '0' || width.empty())
        {
            cout << "Your input is invalid." << endl;
            continue;
        }
        bool flag = true;
        for (int i = 0; i < width.size(); ++i) {
            if (!isdigit(width[i]))
            {
                cout << "Your input is invalid." << endl;
                flag = false;
                break;
            }
            else if (stoll(width) > image.width || stoll(width) < 0)
            {
                cout << "Your input exceeds the dimensions of the image." << endl;
                flag = false;
                break;
            }
            else if (stoll(width) + stoll(x) > image.width)
            {
                cout << "Your input make the new image exceeds the dimensions of the image." << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    }
    string height;
    while (true)
    {
        cout << "Enter the height:" << endl;
        getline(cin , height);
        if (height[0] == '0' || height.empty())
        {
            cout << "Your input is invalid." << endl;
            continue;
        }
        bool flag = true;
        for (int i = 0; i < height.size(); ++i) {
            if (!isdigit(height[i]))
            {
                cout << "Your input is invalid." << endl;
                flag = false;
                break;
            }
            else if (stoll(height) > image.width || stoll(height) < 0)
            {
                cout << "Your input exceeds the dimensions of the image." << endl;
                flag = false;
                break;
            }
            else if (stoll(height) + stoll(y) > image.height)
            {
                cout << "Your input make the new image exceeds the dimensions of the image." << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    }
    Image image2(stoll(width) , stoll(height));
    cout << "Loading...\n";
    for (int i = stoll(x); i < stoll(width)+stoll(x); ++i) {
        for (int j = stoll(y); j < stoll(height)+stoll(y); ++j) {
            for (int k = 0; k < image.channels; ++k) {
                image2(i - stoll(x) , j - stoll(y) , k) = image(i , j , k);
            }
        }
    }
    image = image2;
    cout << "Crop filter has been applied.\n";
}

void invertColors(Image &image) {

    cout << "Loading...\n";

    // Loop over each row , column , channel
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {

            for (int k = 0; k < 3; ++k) { // 3 refers to number of channels (RGB).
                // For each channel, reverse the color.
                image(i, j, k) = 255 - image(i, j, k);
            }

        }
    }
    cout << "Color inversion filter has been applied.\n";
}

void rotate(Image &image) {
    string deg;
    cout << "Enter choice number:\n"
            "1) Rotate by 90 deg.\n"
            "2) Rotate by 180 deg.\n"
            "3) Rotate by 270 deg.\n";

    while (true) {
        cout << "Enter your choice:\n";
        getline(cin, deg);
        if (deg == "1" || deg == "2" || deg == "3")
            break;
        else
            cout << "Your choice is invalid.\n";
    }
    cout << "Loading...\n";
    if (deg == "1") {
        int newHeight = image.width; // After rotation, the height becomes the old width.
        int newWidth = image.height; // After rotation, the width becomes the old height.

        Image rotatedImage(newWidth, newHeight);

        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) { // 3 refers to number of channels (RGB)
                    rotatedImage(image.height - j - 1, i, k) = image(i, j, k);
                }
            }
        }
        image = rotatedImage;
        cout << "Rotation by 90 degree filter has been applied.\n";
    }
    else if (deg == "2") {
        // Loop over the upper half of the picture and swap between each pixel in it and in the lower part.
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height / 2; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    swap(image(i, j, k), image(i, image.height - j - 1, k));
                }
            }
        }
        cout << "Rotation by 180 degree filter has been applied.\n";
    }
    else if (deg == "3") {
        int newHeight = image.width; // After rotation, the height becomes the old width.
        int newWidth = image.height; // After rotation, the width becomes the old height.

        Image rotatedImage(newWidth, newHeight);

        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) { // 3 refers to number of channels (RGB)
                    rotatedImage(j, i, k) = image(i, j, k);
                }
            }
        }
        image = rotatedImage;
        cout << "Rotation by 270 degree filter has been applied.\n";
    }
}

void resize (Image &image)
{
    cout << "How do you want to resize the image?\n"
            "1) Enter new dimensions.\n"
            "2) Enter a ratio.\n";
    string choice;
    while (true)
    {
        cout << "Enter your choice:\n" <<endl;
        getline(cin , choice);
        if (choice == "1" || choice == "2")
            break;
        else
            cout << "Your choice is invalid.\n" <<endl;
    }
    string n_width;
    string n_height;
    if (choice == "1")
    {
        while (true)
        {
            cout << "Enter the new width:\n";
            getline(cin , n_width);
            if (n_width[0] == '0' || n_width.empty())
            {
                cout << "Your input is invalid.\n";
                continue;
            }
            bool flag = true;
            for (int i = 0; i < n_width.size(); ++i) {
                if (!isdigit(n_width[i]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                break;
            else
                cout << "Your input is invalid.\n";
        }
        while (true)
        {
            cout << "Enter the new height:\n";
            getline(cin , n_height);
            if (n_height[0] == '0' || n_height.empty())
            {
                cout << "Your input is invalid.\n";
                continue;
            }
            bool flag = true;
            for (int i = 0; i < n_height.size(); ++i) {
                if (!isdigit(n_height[i]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                break;
            else
                cout << "Your input is invalid.\n";
        }
    }
    else if (choice == "2")
    {
        string ratio;
        string num = "";
        string den = "";
        regex r("[0-9]+(/[0-9]+)?");
        while (true)
        {
            cout << "Note 1: You can enter the ratio as a fraction (a/b) or as an integer number (a).\n"
                    "Note 2: b can not be 0.\n";
            cout << "Enter the ratio:\n";
            getline(cin , ratio);
            bool zero = false , x = false;
            ll count = 0;
            if (regex_match(ratio , r))
            {
                if (ratio[0] == '0')
                {
                    cout << "Your input is invalid.\n";
                    continue;
                }
                for (int i = 0; i < ratio.size(); ++i) {
                    if (ratio[i] == '/')
                    {
                        x = true;
                        if (ratio[i+1] == '0')
                            zero = true;
                        continue;
                    }
                    if (x) count++;
                }
                if (zero)
                {
                    if (count == 1)
                        cout << "The denominator can not be 0.\n";
                    else
                        cout << "Your input is invalid.\n";
                    continue;
                }
                break;
            }
            else
                cout << "Please follow the notes.\n";
        }
        bool flag = false;
        for (int i = 0; i < ratio.size(); ++i) {
            if (ratio[i] == '/')
            {
                flag = true;
                continue;
            }
            if (!flag)
                num+=ratio[i];
            else den+=ratio[i];
        }
        if (!flag) den = "1";
        long long i_width , i_height;
        i_width = image.width * stoll(num) / stoll(den);
        i_height = image.height * stoll(num) / stoll(den);
        n_width = to_string(i_width);
        n_height = to_string(i_height);
    }
    Image image2(stoll(n_width) , stoll(n_height));
    cout << "Loading...\n";
    for (int i = 0; i < stoll(n_width); ++i)
    {
        for (int j = 0; j < stoll(n_height); ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image2(i,j,k) = image(i*image.width/stoll(n_width),j*image.height/stoll(n_height),k);
            }
        }
    }
    image = image2;
    cout << "Resize filter has been applied.\n";
}

void merge_resize (Image &image , int n_width , int n_height)
{
    Image image2(n_width , n_height);
    for (int i = 0; i < n_width; ++i)
    {
        for (int j = 0; j < n_height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image2(i,j,k) = image(i * image.width / n_width,j * image.height / n_height,k);
            }
        }
    }
    image = image2;
}

void merge(Image &img1)
{
    string name2;
    while (true)
    {
        cout << "Enter second image name and its format (ex: image.png):" <<endl;
        getline(cin , name2);
        Image image;
        try
        {
            image.loadNewImage(name2);
            cout << "Image loaded successfully." <<endl;
            break;
        }
        catch (...)
        {
            cout << "Please, check that you entered image's name correctly." << endl;
        }
    }

    // Loading images
    Image img2(name2);

    cout << "What do you want?\n"
            "1) Merge the common area.\n"
            "2) Resize the smaller image, then merge.\n"
            "3) Resize the bigger image, then merge.\n";

    string choice;
    while(true)
    {
        getline(cin,choice);
        if(choice == "1" || choice == "2" || choice == "3")
            break;
    }
    int n_width , n_height;
    if (choice == "1")
    {
        n_width = min(img1.width,img2.width);
        n_height = min(img1.height,img2.height);
    }
    else if (choice == "2")
    {
        long long area1 = img1.width * img1.height;
        long long area2 = img2.width * img2.height;
        if(area1 < area2)
        {
            merge_resize(img1 , img2.width , img2.height);
            n_width = img2.width;
            n_height = img2.height;
        }
        else
        {
            merge_resize(img2 , img1.width , img1.height);
            n_width = img1.width;
            n_height = img1.height;
        }
    }
    else if (choice == "3")
    {
        long long area1 = img1.width * img1.height;
        long long area2 = img2.width * img2.height;
        if(area1 > area2)
        {
            merge_resize(img1 , img2.width , img2.height);
            n_width = img2.width;
            n_height = img2.height;
        }
        else
        {
            merge_resize(img2 , img1.width , img1.height);
            n_width = img1.width;
            n_height = img1.height;
        }
    }

    // Set the image to the min width and the height
    Image imgRs(n_width,n_height);


    cout << "Loading...\n";
    for (int i = 0; i < imgRs.width; ++i)
    {
        for (int j = 0; j < imgRs.height; ++j)
        {
            for (int k = 0; k < imgRs.channels; ++k)
            {
                // Set the pixel to half of sum of two coordinate pixels
                imgRs(i,j,k) = (img1(i,j,k) + img2(i,j,k)) / 2;
            }
        }
    }
    img1 = imgRs;
    cout << "Merge filter has been applied.\n";
}

void infrared_photography(Image &image)
{

    // Loop over each row , column , channel and declare the avg
    unsigned int avg;
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            // Set the avg to zero
            avg = 0;

            // To get the sum and get the avg
            for (int k = 0; k < image.channels; ++k)
            {
                avg += image(i,j,k);
            }

            // Set the avg
            avg /= 3;

            // Set the red and white correctly
            image(i, j, 0) = 255;
            image(i, j, 1) = 255 - avg;
            image(i, j, 2) = 255 - avg;
        }
    }
    cout << "Infrared photography filter has been applied.\n";
}

void frame(Image &image) {

    int R, G, B;
    string color;
    while (true) {
        cout << "Choose the color of the frame (Enter a number):\n"
                "1) Red.\n"
                "2) Green\n"
                "3) Blue\n"
                "4) Purple\n"
                "5) Yellow\n";
        cin >> color;
        if (color == "1" || color == "2" || color == "3" || color == "4" || color == "5")
            break;
        else
            cout << "Invalid option. Please choose a number from 1 to 5.\n";
    }
    if (color == "1"){
        R = 255, G = 0, B = 0;
    }
    else if (color == "2"){
        R = 0, G = 255, B = 0;
    }
    else if (color == "3"){
        R = 0, G = 0, B = 255;
    }
    else if (color == "4"){
        R = 160, G = 32, B = 240;
    }
    else {
        R = 255, G = 255, B = 0;
    }

    string thick;
    while (true){
        cout << "Enter the thickness of the frame (number of pixels): ";
        cin >> thick;

        for (char ch : thick) {
            if (!isdigit(ch)) {
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }
        }
        break;
    }
    int thickness = stoi(thick);

    string choice;
    while (true) {

        cout << "Choose the option you want:\n"
                "1) Simple frame.\n"
                "2) Fancy frame.\n";
        cin >> choice;
        if (choice == "1" || choice == "2")
            break;
        else
            cout << "Invalid option. Please choose 1 or 2.\n";
    }

    // Loop over each row and column for the frame.
    for (int i = 0; i < thickness; ++i) {
        for(int j = 0; j < image.height; ++j) {
            // Set the color of the pixel.
            image.setPixel(i, j, 0, R);
            image.setPixel(i, j, 1, G);
            image.setPixel(i, j, 2, B);
            // Set the color of the corresponding pixel on the opposite side of the image.
            image.setPixel(image.width - i - 1, j, 0, R);
            image.setPixel(image.width - i - 1, j, 1, G);
            image.setPixel(image.width - i - 1, j, 2, B);
        }
    }

    // Loop over each column and row for the frame.
    for (int j = 0; j < thickness; ++j) {
        for (int i = 0; i < image.width; ++i) {

            // Set the color of the pixel.
            image.setPixel(i, j, 0, R);
            image.setPixel(i, j, 1, G);
            image.setPixel(i, j, 2, B);

            // Set the color of the corresponding pixel on the opposite side of the image.
            image.setPixel(i, image.height - j - 1, 0, R);
            image.setPixel(i, image.height - j - 1, 1, G);
            image.setPixel(i, image.height - j - 1, 2, B);
        }
    }
    if (choice == "1")
        cout << "Simple frame has been applied.\n";

        // Draw a fancy frame.
    else if (choice == "2") {

        // Draw the vertical white lines.
        for (int i = thickness + 4; i < thickness + 16; ++i) {
            // Leave space between the white lines.
            if (i == thickness + 8 || i == thickness + 9 || i == thickness + 10 || i == thickness + 11)
                continue;

            for(int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, 250);
                    image.setPixel(image.width - i - 1, j, k, 250);

                }
            }
        }

        // Draw the horizontal white lines.
        for (int j = thickness + 4; j < thickness + 16; ++j) {
            // Leave space between the white lines.
            if (j == thickness + 8 || j == thickness + 9 || j == thickness + 10 || j == thickness + 11)
                continue;

            for (int i = 0; i < image.width; ++i) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, 250);
                    image.setPixel(i, image.height - j - 1, k, 250);
                }
            }
        }
        cout << "Fancy frame has been applied.\n";
    }
}

void skew(Image &image)
{
    string theta;
    while (true)
    {
        cout << "Note: The degree must be greater than or equal 0 and less than 90.\n";
        cout << "Enter the degree:\n";
        getline(cin , theta);
        if ((theta[0] == '0' && theta.size() != 1) || theta.empty())
        {
            cout << "Your input is invalid.\n";
            continue;
        }
        bool flag = true;
        for (int i = 0; i < theta.size(); ++i) {
            if (!isdigit(theta[i]) || stoll(theta) < 0 || stoll(theta) >= 90)
            {
                cout << "Your input is invalid.\n";
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    }

    double d_theta = stod(theta);
    double rad_theta = M_PI * d_theta / 180.0;

    int l = image.height * tan(rad_theta);
    int n_width = image.width + l;

    Image image2(n_width , image.height);

    for (int i = 0; i < image2.width; ++i) {
        for (int j = 0; j < image2.height; ++j) {
            for (int k = 0; k < image2.channels; ++k) {
                image2(i , j , k) = 255;
            }
        }
    }
    cout << "Loading...\n";
    for (int i = l; i < image2.width; ++i) {
        double x = 0;
        for (int j = 0; j < image2.height; ++j) {
            for (int k = 0; k < image2.channels; ++k) {
                image2(i - x, j , k) = image(i-l , j , k);
            }
            x+=(double(l)/image2.height);
        }
    }
    image = image2;
    cout << "Skew filter has been applied.\n";
}

void edge_detector(Image &image)
{

    // Set X Matrix and Y Matrix
    int x[3][3] = {{1,0,-1},
                   {2,0,-2},
                   {1,0,-1}};

    int y[3][3] = {{1,2,1},
                   {0,0,0},
                   {-1,-2,-1}};

    cout << "Loading...\n";

    // Declare the new image
    Image imageEd(image.width ,image.height);

    for (int i = 0; i < image.width - 2; ++i)
    {
        for (int j = 0; j < image.height - 2; ++j)
        {
            // Intialize Treshold
            double sumx = 0, sumy = 0;
            int T = 100;
            for (int k = i; k < 3 + i; ++k)
            {
                for (int l = j; l < 3 + j; ++l)
                {
                    // Get the sum of multiply of matrix and the image pixels
                    sumx += (image(k,l,0) * x[k - i][l - j]);
                    sumy += (image(k,l,0) * y[k - i][l - j]);
                }
            }

            float gradient = sqrt((sumx * sumx) + (sumy * sumy)) / 2;
            // Make the pixel white or black depending on T and gradient
            if (gradient > T)
                for (int k = 0; k < 3; ++k)
                    imageEd(i, j, k) = 0;
            else
                for (int k = 0; k < 3; ++k)
                    imageEd(i, j, k) = 255;

        }
    }
    image = imageEd;
    cout << "Edge detector filter has been applied.\n";
}

void sunlight(Image &image)
{
    cout << "Loading...\n";
    int avg = 0;
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            if(image(i,j,0) + 30 > 255)
                image(i,j,0) = 255;
            else
                image(i,j,0) += 30;

            if(image(i,j,1) + 30 > 255)
                image(i,j,1) = 255;
            else
                image(i,j,1) += 30;

            if(image(i,j,2) - 30 < 0)
                image(i,j,2) = 0;
            else
                image(i,j,2) -= 30;

        }
    }
    cout << "Sunlight filter has been applied.\n";
}

void purple(Image &image){

    cout << "Loading...\n";
    // Loop over each row, column, channel.
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {

            // Check if the pixel is black.
            if (image(i, j, 0) == 0 && image(i, j, 1) == 0 && image(i, j, 2) == 0) {
                continue; // Leave black pixels unchanged.
            }

            // Calculate average of RGB.
            unsigned int avg = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;

            // Determine brightness based on average RGB value.
            bool isDark = (avg < 185);

            // Adjust color based on brightness.
            if (isDark) {
                // Make dark pixels less purple.
                if (image(i, j, 0) + 20 > 255)
                    image(i, j, 0) = 255;
                else
                    image(i, j, 0) += 20;

                if (image(i, j, 1) - 30 < 0)
                    image(i, j, 1) = 0;
                else
                    image(i, j, 1) -= 30;

                if (image(i, j, 2) + 15 > 255)
                    image(i, j, 2) = 255;
                else
                    image(i, j, 2) += 15;
            }
            else {
                // Make light pixels more purple.
                if (image(i, j, 0) + 40 > 255)
                    image(i, j, 0) = 255;
                else
                    image(i, j, 0) += 40;

                if (image(i, j, 1) - 40 < 0)
                    image(i, j, 1) = 0;
                else
                    image(i, j, 1) -= 40;

                if (image(i, j, 2) + 30 > 255)
                    image(i, j, 2) = 255;
                else
                    image(i, j, 2) += 30;
            }
        }
    }
    cout << "Purple filter has been applied.\n";
}

void blur(Image &image){

    cout << "What is the level of blur do you want?\n"
            "1) Low.\n"
            "2) Medium.\n"
            "3) High.\n";
    string choice;
    while (true)
    {
        cout << "Enter your choice:\n";
        getline(cin, choice);
        if (choice == "1" || choice == "2" || choice == "3")
            break;
        else
            cout << "Your choice is invalid.\n";
    }
    int box;
    if (choice == "1") {
        box = 10;
    }
    else if (choice == "2") {
        box = 18;
    }
    else {
        box = 25;
    }

    cout << "Loading..." << '\n';

    // Compute prefix sums for each channel.
    vector<vector<vector<unsigned long long>>> prefixSum(image.width + 1, vector<vector<unsigned long long>>(image.height + 1, vector<unsigned long long>(3, 0)));
    for (int channel = 0; channel < 3; ++channel) {
        for (int i = 1; i <= image.width; ++i) {
            for (int j = 1; j <= image.height; ++j) {
                prefixSum[i][j][channel] = image(i - 1, j - 1, channel) + prefixSum[i - 1][j][channel]
                                           + prefixSum[i][j - 1][channel] - prefixSum[i - 1][j - 1][channel];
            }
        }
    }

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {

            unsigned int red = 0, green = 0, blue = 0;

            // Adjust the bounds to ensure the blur operation covers the edges.
            int startX = max(i - box, 0);
            int endX = min(i + box, image.width - 1);
            int startY = max(j - box, 0);
            int endY = min(j + box, image.height - 1);

            // Compute the sum of pixels in the rectangular area using prefix sums.
            for (int channel = 0; channel < 3; ++channel) {
                unsigned long long sum = prefixSum[endX + 1][endY + 1][channel] - prefixSum[startX][endY + 1][channel]
                                         - prefixSum[endX + 1][startY][channel] + prefixSum[startX][startY][channel];
                if (channel == 0)
                    red = sum;
                else if (channel == 1)
                    green = sum;
                else
                    blue = sum;

            }

            int area = (endX - startX + 1) * (endY - startY + 1);
            unsigned long long avgRed = red / area;
            unsigned long long avgGreen = green / area;
            unsigned long long avgBlue = blue / area;

            image(i, j, 0) = avgRed;
            image(i, j, 1) = avgGreen;
            image(i, j, 2) = avgBlue;
        }
    }
    cout << "Blur filter has been applied\n";
}

void oil_paint(Image &image)
{
    int intensity_level = 2;
    int radius = 2;
    cout << "Loading..." << '\n';
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {

            double red = 0, green = 0, blue = 0;
            int intensity;

            int startX = max(i - radius, 0);
            int endX = min(i + radius, image.width - 1);
            int startY = max(j - radius, 0);
            int endY = min(j + radius, image.height - 1);


            vector<double> R(intensity_level) , G(intensity_level) , B(intensity_level) , count(intensity_level);

            for (int x = startX; x <= endX; ++x) {
                for (int y = startY; y <= endY; ++y) {
                    red = image(x , y , 0);
                    green = image(x , y , 1);
                    blue = image(x , y , 2);
                    intensity = (int)((double)((red+green+blue)/3)*intensity_level/255.0f);
                    count[intensity]++;
                    R[intensity] += red ;
                    G[intensity] += green ;
                    B[intensity] += blue ;
                }
            }
            double max_element = count[0];
            int max_index = 0;
            for (int k = 1; k < count.size(); ++k) {
                if (count[k] > max_element)
                {
                    max_element = count[k];
                    max_index = k;
                }
            }
            image(i, j, 0) = R[max_index] / max_element;
            image(i, j, 1) = G[max_index] / max_element;
            image(i, j, 2) = B[max_index] / max_element;

        }
    }
    cout << "Oil paint filter has been applied.\n";
}

void randomNoise(Image &image){

    float density = 0.1;
    int noisyPixels = static_cast<int>(image.width * image.height * density);
    cout << "Loading..." << '\n';

    for (int i = 0; i < noisyPixels; ++i) {

        // Select a random pixel.
        int x = rand() % image.width;
        int y = rand() % image.height;

        // Generate random gray value for the noisy pixel.
        unsigned char grayValue = rand() % 256;

        // Set pixel value to gray.
        image.setPixel(x, y, 0, grayValue);
        image.setPixel(x, y, 1, grayValue);
        image.setPixel(x, y, 2, grayValue);
    }
    cout << "The Salt and pepper noise filter has been applied.\n";
}

void tv_noise(Image &image){
    cout << "Loading..." << '\n';

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {

            if (j % 2 == 0) {
                for (int k = 0; k < 3; ++k) {
                    // Generate random value for the noisy pixel.
                    int randomValue = rand() % 31;
                    image(i, j, k) = min(image(i,j,k) + randomValue, 255);
                }
            } else {
                for (int k = 0; k < 3; ++k) {
                    // Generate random value for the noisy pixel.
                    int randomValue = rand() % 31;
                    image(i, j, k) = max(image(i,j,k) - randomValue, 0);
                }
            }
        }
    }
    cout << "Old TV noise has been applied.\n";
}

void mirror(Image &image)
{
    cout << "Choose the part you want to mirror:\n"
            "1) Up.\n"
            "2) Down.\n"
            "3) Left.\n"
            "4) Right.\n"
            "Enter your choice:\n";
    string choice;
    while(true)
    {
        getline(cin , choice);
        if (choice == "1" || choice == "2" || choice == "3" || choice == "4")
            break;
    }
    cout << "Loading..." << '\n';
    if (choice == "1")
    {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height/2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(i , image.height - j - 1, k) = image(i , j , k);
                }
            }
        }
    }
    else if (choice == "2")
    {
        for (int i = 0; i < image.width; ++i) {
            for (int j = image.height/2; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(i , image.height - j - 1, k) = image(i , j , k);
                }
            }
        }
    }
    else if(choice == "3")
    {
        for (int i = 0; i < image.width/2; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(image.width - i - 1, j , k) = image(i , j , k);
                }
            }
        }
    }
    else if(choice == "4")
    {
        for (int i = image.width/2; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(image.width - i - 1, j , k) = image(i , j , k);
                }
            }
        }
    }
    cout << "Mirror filter has been applied.\n";
}

int main() {
    cout << "Welcome to Baby Photoshop.\n";

    string name;
    Image image;
    while (true)
    {
        cout << "Enter your image's name and its format (ex: image.png):" <<endl;
        getline(cin , name);
        try
        {
            image.loadNewImage(name);
            cout << "Image loaded successfully." <<endl;
            break;
        }
        catch (...)
        {
            cout << "Please, check that you entered image's name correctly." << endl;
        }
    }

    while (true) {
        cout << "What do you want to do now?\n"
                "1) Load a new image.\n"
                "2) Add a new filter.\n"
                "3) Save the image.\n"
                "4) Exit.\n";
        string exit;
        while (true) {
            cout << "Enter your choice:\n";
            getline(cin, exit);
            if (exit == "1" || exit == "2" || exit == "3" || exit == "4")
                break;
            else
                cout << "Your input is invalid.\n";
        }

        if (exit == "1") {
            cout << "Do you want to save the current image before loading a new image?\n"
                    "1) Save.\n"
                    "2) Discard.\n";
            string ask;
            while (true)
            {
                cout << "Enter your choice:\n";
                getline(cin , ask);
                if (ask == "1" || ask == "2")
                    break;
                else
                    cout << "Your choice is invalid.\n";
            }
            if (ask == "1")
                save(image , name);
            string name;
            while (true)
            {
                cout << "Enter your image's name and its format (ex: image.png):" <<endl;
                getline(cin , name);
                try
                {
                    image.loadNewImage(name);
                    cout << "Image loaded successfully." <<endl;
                    break;
                }
                catch (...)
                {
                    cout << "Please, check that you entered image's name correctly." << endl;
                }
            }
            continue;
        }
        else if (exit == "2")
        {
            cout << "The filters you can do:" <<endl;
            cout << "1) Black and White filter.\n"
                    "2) Gray Scale filter.\n"
                    "3) Darken filter.\n"
                    "4) Lighten filter.\n"
                    "5) Flip filter.\n"
                    "6) Crop filter.\n"
                    "7) Invert Color filter.\n"
                    "8) Rotate filter.\n"
                    "9) Resize filter.\n"
                    "10) Merge filter.\n"
                    "11) Infrared photography filter.\n"
                    "12) Add a frame filter.\n"
                    "13) Image skewing filter.\n"
                    "14) Detect image edges filter.\n"
                    "15) Sun light filter.\n"
                    "16) Purple filter.\n"
                    "17) Blur filter.\n"
                    "18) Oil paint filter.\n"
                    "19) Salt and pepper noise filter.\n"
                    "20) Premium Detect image edges filter (Inverted).\n"
                    "21) Old TV noise filter.\n"
                    "22) Mirror image filter\n"
                    "23) Return.\n";

            string choice;
            while (true)
            {
                cout << "Enter your choice:" <<endl;
                getline(cin , choice);
                if (choice[0] == '0' || choice.empty())
                {
                    cout << "Your input is invalid." <<endl;
                    continue;
                }
                bool flag = true;
                for (int i = 0; i < choice.size(); ++i) {
                    if (!isdigit(choice[i]) || stoll(choice) > 23 || stoll(choice) < 1)
                    {
                        cout << "Your choice is invalid." <<endl;
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (choice == "1")
                bw(image);
            else if (choice == "2")
                grayscale(image);
            else if (choice == "3")
                darken(image);
            else if (choice == "4")
                lighten(image);
            else if (choice == "5")
                flip(image);
            else if (choice == "6")
                crop(image);
            else if (choice == "7")
                invertColors(image);
            else if (choice == "8")
                rotate(image);
            else if (choice == "9")
                resize(image);
            else if (choice == "10")
                merge(image);
            else if (choice == "11")
                infrared_photography(image);
            else if (choice == "12")
                frame(image);
            else if (choice == "13")
                skew(image);
            else if (choice == "14")
                edge_detector(image);
            else if (choice == "15")
                sunlight(image);
            else if (choice == "16")
                purple(image);
            else if (choice == "17")
                blur(image);
            else if (choice == "18")
                oil_paint(image);
            else if (choice == "19")
                randomNoise(image);
            else if (choice == "20")
            {
                edge_detector(image);
                invertColors(image);
            }
            else if (choice == "21")
                tv_noise(image);
            else if (choice == "22")
                mirror(image);
            else continue;
        }
        else if (exit == "3"){
            save(image, name);
        }

        else if (exit == "4"){

            cout << "Do you want to save the current image before exiting?\n"
                    "1) Save.\n"
                    "2) Discard.\n";
            string ask;
            while (true)
            {
                cout << "Enter your choice:\n";
                getline(cin , ask);
                if (ask == "1" || ask == "2")
                    break;
                else
                    cout << "Your choice is invalid.\n";
            }
            if (ask == "1")
                save(image , name);
            cout << "Thank you for using our app.\n";
            break;
        }
    }
}
