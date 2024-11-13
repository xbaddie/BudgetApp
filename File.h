#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>


#include "Markup.h"

using namespace std;

class File {
    const string FILE_NAME;

protected:
    int lastId;
    CMarkup xmlFile;
    string getFileName();

public:
    File(string fileName) : FILE_NAME(fileName) {
    }

    int getLastId();
};
