#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "MonoStack.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class SpeakerView
{
public:
    SpeakerView();
    SpeakerView(string fileName);
    ~SpeakerView();
    void seating();
    int n;
    int p;

private:
    string inputFile;
    double *speakerArr;
};

#endif