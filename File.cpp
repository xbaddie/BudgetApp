#include "File.h"

string File::getFileName()
{
    return FILE_NAME;
}

int File::getLastId()
{
    int lastId = 0;

    try {
        if (!xmlFile.Load(getFileName())) {
            return lastId;
        }

        xmlFile.FindElem("Users");
        xmlFile.IntoElem();

        while (xmlFile.FindElem("User")) {
            xmlFile.IntoElem();
            xmlFile.FindElem("ID");
            lastId = stoi(xmlFile.GetData());
            xmlFile.OutOfElem();
        }

    } catch (const exception &caughtException) {
        cerr << "Error getting last user ID: " << caughtException.what() << endl;
    }

    return lastId;
}
