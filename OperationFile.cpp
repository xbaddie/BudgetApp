#include "OperationFile.h"



vector <Operation> OperationFile::loadOperationsFromFile (const int loggedUserId)
{
    Operation operation;
    vector <Operation> operations;

    if (!xmlFile.Load(getFileName()))
    {
        cerr << "Error: Could not load XML file." << endl;
        return operations;
    }

    xmlFile.FindElem("Users");
    xmlFile.IntoElem();

    while (xmlFile.FindElem("User"))
    {
        xmlFile.IntoElem();

        xmlFile.FindElem("ID");
        operation.id = stoi(xmlFile.GetData());

        xmlFile.FindElem("FirstName");
        operation.userId = xmlFile.GetData();

        xmlFile.FindElem("LastName");
        operation.date = xmlFile.GetData();

        xmlFile.FindElem("Login");
        operation.item = xmlFile.GetData();

        xmlFile.FindElem("Password");
        operation.amount = xmlFile.GetData();

        users.push_back(operation);
        xmlFile.OutOfElem();
    }

    return operations;
}

bool  OperationFile::addOperationToFile (const Operation &operation)
{
    ifstream infile(getFileName());
    bool fileExists = infile.good();
    infile.close();

    if (fileExists)
    {
        xmlFile.Load(getFileName());
    }
    else
    {
        xmlFile.AddElem("Operations");
    }

    xmlFile.FindElem("Operations");
    xmlFile.IntoElem();

    xmlFile.AddElem("Operation");
    xmlFile.IntoElem();
    xmlFile.AddElem("ID", operation.id);

    xmlFile.AddElem("FirstName", operation.userId);
    xmlFile.AddElem("LastName", operation.date);
    xmlFile.AddElem("Login", operation.item);
    xmlFile.AddElem("Password", operation.amount);
    xmlFile.OutOfElem();

    if (!xmlFile.Save(getFileName()))
    {
        cout << "Failed to save the operation to the file." << endl;
        return false;
    }


    return true;
}
