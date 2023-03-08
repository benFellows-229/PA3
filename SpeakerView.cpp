/*
Ben Fellows
002369768
bfellows@chapman.edu
CPSC-350-02
CPSC350 PA3
SpeakerView.cpp
A cpp file containing the implementation of SpeakerView class which takes in a file name, and creates a speakerview object which
contains the columns, n, doubles p and makes an array containing all the doubles within a text file. 
SpeakerView also prints out relevent information for seating chart.
*/

#include "SpeakerView.h"

SpeakerView::~SpeakerView() {}

SpeakerView::SpeakerView() {}

SpeakerView::SpeakerView(string fileName)
{
    cout << " " << endl;
    int n = 0;
    int p = 0;
    int row = 0;
    int col = 0;
    string data;
    ifstream infile(fileName);
    ifstream infile2(fileName);
    if (infile.is_open())
    {
        //reads the given files elements seperated by spaces and increments n and p respectively, in order to find size of file.
        while (getline(infile, data))
        {
            istringstream ss(data);
            n++;
            double i = 0;
            while (ss >> i)
            {
                p++;
            }
        }
        p = p / n;
    }

    speakerArr = new double[n * p];
    if (infile2.is_open())
    {
        //creates array of size n*p and reads in the doubles from given file.
        while (getline(infile2, data))
        {
            col = 0;
            istringstream ss(data);
            double i = 0;
            row++;
            while (ss >> i)
            {
                speakerArr[row * p + col] = i;
                col++;
            }
        }
    }

    //increments through speakerArray and pushes items into monostack to find the ammount of people can see.
    for (int i = 0; i < p; i++)
    {
        MonoStack<double> tempStack(p, 'd');
        //nested loops are reversed from array loops so it reads through columns instead of rows, j decrements so it reads backwords.
        for (int j = n; j > 0; j--)
        {
            tempStack.push(speakerArr[j * p + i]);
        }
        //prints out relevent information using tempstack.
        cout << "In column " << i << " there are " << tempStack.size() << " People that can see. Their heights are: ";
        while (!tempStack.isEmpty())
        {
            cout << tempStack.peek() << ", ";
            tempStack.pop();
        }
        cout << "inches." << endl;
    }

    cout << endl;
}
