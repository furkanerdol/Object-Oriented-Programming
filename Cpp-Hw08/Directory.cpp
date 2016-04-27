#include <iostream>
#include <string>
#include "Directory.h"

using namespace std;

namespace FurkanFileHierarchy{

    Directory::Directory(const string newFileName, const string newFileOwner, const int newFileSize)
            : File(newFileName, newFileOwner, newFileSize)
    {
     directoryPath = path();
    }
    
    void Directory::ls(const string parameter) const{
        cout << "empty";
    }

    File& Directory::cd(const string parameter) const{
        cout << "empty";
    }
    
    bool Directory::cp(const File* copyFile){
        cout << "empty";
    }
    
}
