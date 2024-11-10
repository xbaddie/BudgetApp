#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Operation.h"
#include "OperationFile.h"
#include "File.h"


using namespace std;

class OperationFile : public File
{

public:
    OperationFile(string fileName) : File(fileName) {
    }
    vector <Operation> loadOperationsFromFile (const int loggedUserId);
    bool  addOperationToFile (const Operation &operation);
};
