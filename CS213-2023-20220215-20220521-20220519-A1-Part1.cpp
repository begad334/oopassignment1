// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:CS213-2023-YourID-YourID-YourID-A1-Part1.cpp
// Last Modification Date:	10/10/2023
// Author1 and ID and gmail:	عمار محمد عباس عبدالله \ 20220215\ a.ibrahem7695@gmail.com
// Author2 and ID and gmail:	بيجاد عبدالغفار عبدالهادي محمود \20220521\ bogd1000messi@gmail.com
// Author3 and ID and gmail:	عبدالرحمن ابراهيم علي ابراهيم \20220519\ clementinetwd36@gmail.com










#include <iostream>
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









void Edge_Detection_Filter() {
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    unsigned char edgeImage[SIZE][SIZE] = {};

    for (int x = 1; x < SIZE - 1; x++) {
        for (int y = 1; y < SIZE - 1; y++) {
            int pixelX = 0;
            int pixelY = 0;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    pixelX += imgGS[x - i][y - j] * (-i);
                    pixelY += imgGS[x - i][y - j] * (-j);
                }
            }

            int gradient = sqrt(pixelX * pixelX + pixelY * pixelY);
            // Invert colors: Black lines on white background
            edgeImage[x][y] = (gradient > 127) ? 0 : 255;
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            imgGS[i][j] = edgeImage[i][j];
        }
    }

    showGSBMP(imgGS);
}







void Enlarge_Quarter(int x, int y, int width, int height, const char* outputFileName) {
    unsigned char enlargedImage[SIZE][SIZE] = {};

    for (int i = x; i < x + width; ++i) {
        for (int j = y; j < y + height; ++j) {
            int new_x = 2 * (i - x);
            int new_y = 2 * (j - y);
            enlargedImage[new_x][new_y] = imgGS[i][j];
            enlargedImage[new_x][new_y + 1] = imgGS[i][j];
            enlargedImage[new_x + 1][new_y] = imgGS[i][j];
            enlargedImage[new_x + 1][new_y + 1] = imgGS[i][j];
        }
    }

    writeGSBMP(outputFileName, enlargedImage);
    showGSBMP(enlargedImage);
}




void  Enlarge_Filter() {
    char choice;
    cout << "Select a quarter to enlarge: " << endl;
    cout << "1 - Top-Left\n2 - Top-Right\n3 - Bottom-Left\n4 - Bottom-Right\n0 - Cancel" << endl;
    cin >> choice;

    int x, y, width, height;

    switch (choice) {
        case '1':
            x = 0;
            y = 0;
            width = SIZE / 2;
            height = SIZE / 2;
            Enlarge_Quarter(x, y, width, height, "enlarged_top_left.bmp");
            break;
        case '2':
            x = 0;
            y = SIZE / 2;
            width = SIZE / 2;
            height = SIZE / 2;
            Enlarge_Quarter(x, y, width, height, "enlarged_top_right.bmp");
            break;
        case '3':
            x = SIZE / 2;
            y = 0;
            width = SIZE / 2;
            height = SIZE / 2;
            Enlarge_Quarter(x, y, width, height, "enlarged_bottom_left.bmp");
            break;
        case '4':
            x = SIZE / 2;
            y = SIZE / 2;
            width = SIZE / 2;
            height = SIZE / 2;
            Enlarge_Quarter(x, y, width, height, "enlarged_bottom_right.bmp");
            break;
        default:
            cout << "Cancelled." << endl;
    }
}




void Shrink_Filter(int factor) {
    if (factor <= 0) {
        cout << "Invalid shrink factor. Factor must be greater than 0." << endl;
        return;
    }

    int newWidth = SIZE / factor;
    int newHeight = SIZE / factor;
    unsigned char shrunkImage[SIZE][SIZE] = {};

    for (int x = 0; x < newWidth; x++) {
        for (int y = 0; y < newHeight; y++) {
            int sum = 0;
            for (int i = 0; i < factor; i++) {
                for (int j = 0; j < factor; j++) {
                    sum += imgGS[x * factor + i][y * factor + j];
                }
            }
            shrunkImage[x][y] = sum / (factor * factor);
        }
    }

    // Copy the shrunk image back to imgGS
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imgGS[i][j] = shrunkImage[i][j];
        }
    }

    showGSBMP(imgGS);
}
void Mirror_Image() {
    char choice;
    cout << "Mirror Image Filter Options:" << endl;
    cout << "1 - Mirror Left 1/2" << endl;
    cout << "2 - Mirror Right 1/2" << endl;
    cout << "3 - Mirror Upper 1/2" << endl;
    cout << "4 - Mirror Lower 1/2" << endl;
    cout << "0 - Cancel" << endl;
    cin >> choice;

    int halfWidth = SIZE / 2;
    int halfHeight = SIZE / 2;

    switch (choice) {
        case '1': // Mirror Left 1/2
            for (int x = 0; x < halfWidth; x++) {
                for (int y = 0; y < SIZE; y++) {
                    imgGS[x][y] = imgGS[SIZE - x - 1][y];
                }
            }
            break;
        case '2': // Mirror Right 1/2
            for (int x = halfWidth; x < SIZE; x++) {
                for (int y = 0; y < SIZE; y++) {
                    imgGS[x][y] = imgGS[SIZE - x - 1][y];
                }
            }
            break;
        case '3': // Mirror Upper 1/2
            for (int x = 0; x < SIZE; x++) {
                for (int y = 0; y < halfHeight; y++) {
                    imgGS[x][y] = imgGS[x][SIZE - y - 1];
                }
            }
            break;
        case '4': // Mirror Lower 1/2
            for (int x = 0; x < SIZE; x++) {
                for (int y = halfHeight; y < SIZE; y++) {
                    imgGS[x][y] = imgGS[x][SIZE - y - 1];
                }
            }
            break;
        default:
            cout << "Cancelled." << endl;
            break;
    }

    showGSBMP(imgGS);
}


void Shuffle_Image() {
    unsigned char shuffledImage[SIZE][SIZE] = {};

    cout << "Enter the order in which you want to shuffle the quarters (e.g., 3 1 4 2): ";
    int order[4];
    for (int i = 0; i < 4; i++) {
        cin >> order[i];
    }

    // Check if the input is valid (contains 1, 2, 3, and 4 exactly once)
    bool validInput = true;
    bool used[4] = { false };
    for (int i = 0; i < 4; i++) {
        if (order[i] < 1 || order[i] > 4 || used[order[i] - 1]) {
            validInput = false;
            break;
        }
        used[order[i] - 1] = true;
    }

    if (!validInput) {
        cout << "Invalid input. Please provide a valid order of quarters (1 to 4) exactly once." << endl;
        return;
    }

    // Copy quarters to the shuffled image based on the user's order
    unsigned char quarters[4][SIZE/2][SIZE/2];
    int qIndex = 0;
    for (int i = 0; i < SIZE; i += SIZE/2) {
        for (int j = 0; j < SIZE; j += SIZE/2) {
            for (int x = 0; x < SIZE/2; x++) {
                for (int y = 0; y < SIZE/2; y++) {
                    quarters[qIndex][x][y] = imgGS[i + x][j + y];
                }
            }
            qIndex++;
        }
    }

    qIndex = 0;
    for (int i = 0; i < SIZE; i += SIZE/2) {
        for (int j = 0; j < SIZE; j += SIZE/2) {
            int target = order[qIndex];
            for (int x = 0; x < SIZE/2; x++) {
                for (int y = 0; y < SIZE/2; y++) {
                    int qx = (target - 1) / 2;
                    int qy = (target - 1) % 2;
                    shuffledImage[i + x][j + y] = quarters[qx][x][y];
                }
            }
            qIndex++;
        }
    }

    // Copy the shuffled image back to imgGS
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imgGS[i][j] = shuffledImage[i][j];
        }
    }

    showGSBMP(imgGS);
}




void Blur_Image() {
    unsigned char blurredImage[SIZE][SIZE] = {};

    for (int x = 1; x < SIZE - 1; x++) {
        for (int y = 1; y < SIZE - 1; y++) {
            // Apply a simple box blur using a 3x3 kernel
            int sum = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    sum += imgGS[x + i][y + j];
                }
            }
            blurredImage[x][y] = sum / 9; // Divide by the number of pixels in the kernel
        }
    }

    // Copy the blurred image back to imgGS
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imgGS[i][j] = blurredImage[i][j];
        }
    }


}

void Crop_Image(int x, int y, int width, int height) {
    if (x < 0 || y < 0 || x + width > SIZE || y + height > SIZE) {
        cout << "Invalid crop dimensions. The selected area is out of bounds." << endl;
        return;
    }

    unsigned char croppedImage[SIZE][SIZE] = {};

    for (int i = x; i < x + width; ++i) {
        for (int j = y; j < y + height; ++j) {
            croppedImage[i - x][j - y] = imgGS[i][j];
        }
    }

    // Copy the cropped image back to imgGS
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            imgGS[i][j] = croppedImage[i][j];
        }
    }

    showGSBMP(imgGS);
}




void SkewHorizontally(int degree) {
    unsigned char skewedImage[SIZE][SIZE] = {};
    double radian = (degree * 3.14159265359) / 180.0;

    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            int newX = (int)(x + tan(radian) * (y - SIZE / 2));
            if (newX >= 0 && newX < SIZE) {
                skewedImage[x][y] = imgGS[newX][y];
            }
        }
    }

    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            imgGS[x][y] = skewedImage[x][y];
        }
    }

    showGSBMP(imgGS);
}

void SkewVertically(int degree) {
    unsigned char skewedImage[SIZE][SIZE] = {};
    double radian = (degree * 3.14159265359) / 180.0;

    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            int newY = (int)(y + tan(radian) * (x - SIZE / 2));
            if (newY >= 0 && newY < SIZE) {
                skewedImage[x][y] = imgGS[x][newY];
            }
        }
    }

    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            imgGS[x][y] = skewedImage[x][y];
        }
    }

    showGSBMP(imgGS);
}


    void filters() {

        char choice;
        read_image();
        cout
                << "1- Black & White Filter\n2- Invert Filter\n3- Merge Filter \n4- Flip filter \n5- Darken and Lighten filter \n6- Rotate filter\n7-Edge Detection'\n8-enlarge image \n9-shrink image \na-Mirror image\nb-shuffle  \nc-Blur image  \nd-crop \ne-skew horizontally \nf-skew vertically \n 0- exit ";
        cout << endl;
        cin >> choice;
        while (choice != '0') {
            if (choice == '1') {
                B_W_Filter();
            } else if (choice == '2') {
                INV_Filter();
            } else if (choice == '3') {
                Merge_Filter();
            } else if (choice == '4') {
                Flip_Image();
            } else if (choice == '5') {
                Darken_and_Lighten_Image();
            } else if (choice == '6') {
                Rotate_Image();
            } else if (choice == '7') {
                Edge_Detection_Filter();
            } else if (choice == '8') {
                Enlarge_Filter();


            } else if (choice == '9') {
                int factor;
                cout << "Enter shrink factor (e.g., 2 for half size, 3 for one-third size): ";
                cin >> factor;
                Shrink_Filter(factor);
            } else if (choice == 'a') {
                Mirror_Image();
            } else if (choice == 'b') {
                Shuffle_Image();

            }





            else if (choice == 'c') {
                Blur_Image();
                Blur_Image();
                Blur_Image();
                Blur_Image();
                showGSBMP(imgGS);
            }



            if (choice == 'e') {
                int degree;
                cout << "Enter the degree to skew horizontally: ";
                cin >> degree;
                SkewHorizontally(degree);
            } else if (choice == 'f') {
                int degree;
                cout << "Enter the degree to skew vertically: ";
                cin >> degree;
                SkewVertically(degree);
            }


            if (choice == 'd') {
                int x, y, width, height;
                cout << "Enter x-coordinate of the top-left corner: ";
                cin >> x;
                cout << "Enter y-coordinate of the top-left corner: ";
                cin >> y;
                cout << "Enter width of the cropped area: ";
                cin >> width;
                cout << "Enter height of the cropped area: ";
                cin >> height;
                Crop_Image(x, y, width, height);
            }
        }





        {
            cout << "Enter the filter you want or 0 to exit " << endl;
            cout<< "1- Black & White Filter\n2- Invert Filter\n3- Merge Filter \n4- Flip filter\n5- Darken and Lighten filter\n6- rotate filter \n7-Edge Detection \n8-enlarge image\n9-shrink \na-Mirror image \nb-shuffle image \nc-Blur image \nd-crop\ne-skew horizontally \nf-skew vertically \n0-exit";
            cout << endl;
            cin >> choice;
        }

            cout << "Exit" << endl;


        }






        int main() {
            filters();
            return 0;

        }
