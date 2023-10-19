



// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:CS213-2023-YourID-YourID-YourID-A1-Part1.cpp
// Last Modification Date:	10/10/2023
// Author1 and ID and gmail:	عمار محمد عباس عبدالله \ 20220215\ a.ibrahem7695@gmail.com
// Author2 and ID and gmail:	بيجاد عبدالغفار عبدالهادي محمود \20220521\ bogd1000messi@gmail.com
// Author3 and ID and gmail:	عبدالرحمن ابراهيم علي ابراهيم \20220519\ clementinetwd36@gmail.com










#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cmath>
#include <unistd.h>
#include "bmplib.h"
#include<climits>


using namespace std;

unsigned char imgGS[SIZE][SIZE] = {};
unsigned char imgGS2[SIZE][SIZE] = {};




void read_image()
{
    string imageName, path = "\\images\\";
    cout << "Enter the name that must be in imges folder: " << endl;
    cin >> imageName;
    path += imageName;
    char cwd[PATH_MAX];
    readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgGS);

}

void B_W_Filter()
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (imgGS[i][j]>127)
                imgGS[i][j] = 255;
            else
                imgGS[i][j]=0;
        }
    }
    showGSBMP(imgGS);
}

void  INV_Filter()
{

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            imgGS[i][j]=(255-imgGS[i][j]);

        }
    }
    showGSBMP(imgGS);
}

void Merge_Filter() {
    char image_2_FileName[100];
    cout << "Enter the image 2 file name: ";
    cin >> image_2_FileName;
    readGSBMP(image_2_FileName, imgGS2);
    for (int i = 0;i < SIZE;i++)
    {
        for (int j = 0;j < SIZE;j++) {
            imgGS[i][j] = (imgGS[i][j] + imgGS2[i][j]) / 2;
        }
    }
    char imageFileName[100];
    cout << "Enter the image 1 file name: ";
    cin >> imageFileName;
    writeGSBMP(imageFileName, imgGS);
    showGSBMP(imgGS);
}


void Darken_and_Lighten_Image() {
    int choice;
    cout << "to be darker press 1 ,lighter press 2 : ";
    cin >> choice;
    while (choice == 1 || choice == 2)
    {
        if (choice == 1) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imgGS[i][j] = imgGS[i][j] / 2;
                }
            }
            break;
        }
        else if (choice == 2) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imgGS[i][j] = (imgGS[i][j] + 255) / 2;
                }
            }
            break;
        }

    }
    showGSBMP(imgGS);

}

void Flip_Image() {
    int choice;
    cout << "for  flipping  the image horizontally press=>1, vertically press=>2";
    cin >> choice;
    int tmp;
    while (choice == 1 || choice == 2) {
        if (choice == 1) {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    tmp = imgGS[i][j];
                    imgGS[i][j] = imgGS[SIZE - i][j];
                    imgGS[SIZE - i][j] = tmp;
                }
            }
            break;
        }

        else if (choice == 2) {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    tmp = imgGS[i][j];
                    imgGS[i][j] = imgGS[SIZE - i][j];
                    imgGS[SIZE - i][j] = tmp;
                }
            }
            for(int i=0;i<2;i++)
            {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        int temp = imgGS[i][j];
                        imgGS[i][j] = imgGS[SIZE - 1 - j][i];
                        imgGS[SIZE - 1 - j][i] = imgGS[SIZE - 1 - i][SIZE - 1 - j];
                        imgGS[SIZE - 1 - i][SIZE - 1 - j] = imgGS[j][SIZE - 1 - i];
                        imgGS[j][SIZE - 1 - i] = temp;
                    }
                }
            }
            break;
        }
    }
    showGSBMP(imgGS);
}
void Rotate_Image() {
    char s[SIZE][SIZE];
    int rotate;
    cout << "to rotate 90 or 180 or 270: ";
    cin >> rotate;
    while (true) {
        if (rotate == 90 || rotate == 180 || rotate == 270) {
            break;
        }
        cout << "enter the degree of rotate 90 or 180 or 270: ";
        cin >> rotate;
    }
    if (rotate == 90)
    {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                int temp = imgGS[i][j];
                imgGS[i][j] = imgGS[SIZE - 1 - j][i];
                imgGS[SIZE - 1 - j][i] = imgGS[SIZE - 1 - i][SIZE - 1 - j];
                imgGS[SIZE - 1 - i][SIZE - 1 - j] = imgGS[j][SIZE - 1 - i];
                imgGS[j][SIZE - 1 - i] = temp;
            }
        }
    }
    else if (rotate == 180) {

        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                int temp = imgGS[i][j];
                imgGS[i][j] = imgGS[SIZE - 1 - j][i];
                imgGS[SIZE - 1 - j][i] = imgGS[SIZE - 1 - i][SIZE - 1 - j];
                imgGS[SIZE - 1 - i][SIZE - 1 - j] = imgGS[j][SIZE - 1 - i];
                imgGS[j][SIZE - 1 - i] = temp;
            }
        } for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                int temp = imgGS[i][j];
                imgGS[i][j] = imgGS[SIZE - 1 - j][i];
                imgGS[SIZE - 1 - j][i] = imgGS[SIZE - 1 - i][SIZE - 1 - j];
                imgGS[SIZE - 1 - i][SIZE - 1 - j] = imgGS[j][SIZE - 1 - i];
                imgGS[j][SIZE - 1 - i] = temp;
            }
        }
    }
    else {

        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                int temp = imgGS[i][j];
                imgGS[i][j] = imgGS[SIZE - 1 - j][i];
                imgGS[SIZE - 1 - j][i] = imgGS[SIZE - 1 - i][SIZE - 1 - j];
                imgGS[SIZE - 1 - i][SIZE - 1 - j] = imgGS[j][SIZE - 1 - i];
                imgGS[j][SIZE - 1 - i] = temp;
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                int temp = imgGS[i][j];
                imgGS[i][j] = imgGS[SIZE - 1 - j][i];
                imgGS[SIZE - 1 - j][i] = imgGS[SIZE - 1 - i][SIZE - 1 - j];
                imgGS[SIZE - 1 - i][SIZE - 1 - j] = imgGS[j][SIZE - 1 - i];
                imgGS[j][SIZE - 1 - i] = temp;
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                int temp = imgGS[i][j];
                imgGS[i][j] = imgGS[SIZE - 1 - j][i];
                imgGS[SIZE - 1 - j][i] = imgGS[SIZE - 1 - i][SIZE - 1 - j];
                imgGS[SIZE - 1 - i][SIZE - 1 - j] = imgGS[j][SIZE - 1 - i];
                imgGS[j][SIZE - 1 - i] = temp;
            }
        }
    }
    showGSBMP(imgGS);
}

void filters()
{
    char choice;
    read_image();
    cout << "1- Black & White Filter\n2- Invert Filter\n3- Merge Filter \n4- Flip filter \n5- Darken and Lighten filter \n6- Rotate filter \n 0- exit ";
    cout << endl;
    cin >> choice;
    while (choice != '0') {
        if (choice == '1') {
            B_W_Filter();
        }
        else if (choice == '2') {
            INV_Filter();
        }
        else if (choice == '3') {
            Merge_Filter();
        }
        else if (choice == '4') {
            Flip_Image();
        }
        else if (choice == '5') {
            Darken_and_Lighten_Image();
        }
        else if (choice == '6') {
            Rotate_Image();
        }

        cout << "Enter the filter you want or 0 to exit " << endl;
        cout << "1- Black & White Filter\n2- Invert Filter\n3- Merge Filter \n4- Flip filter\n5- Darken and Lighten filter\n6- rotate filter\n0-exit";
        cout << endl;
        cin >> choice;
    }
    cout << "Exit" << endl;
}









int main() {
    filters();
    return 0;

}