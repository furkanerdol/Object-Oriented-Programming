#include <iostream>
#include <string>
#include "Executable.h"

using namespace std;

namespace FurkanFileHierarchy {

    Executable::Executable(const string newFileName, const string newFileOwner, const int newFileSize, const string newCreatedCompiler)
    : File(newFileName, newFileOwner, newFileSize), createdCompiler(newCreatedCompiler) {
    }

    void Executable::ls(const string parameter) const {
        cout << "error";
    }

    File& Executable::cd(const string parameter) const {
        cout << "error";
    }

    bool Executable::cp(const File* copyFile) {
        cout << "empty";
    }

}



