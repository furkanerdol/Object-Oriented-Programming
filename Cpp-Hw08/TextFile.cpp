#include <iostream>
#include <string>
#include "TextFile.h"

using namespace std;

namespace FurkanFileHierarchy {

    TextFile::TextFile(const string newFileName, const string newFileOwner, const int newFileSize, const string newTextType)
    : File(newFileName, newFileOwner, newFileSize), textType(newTextType) {
    }

    void TextFile::ls(const string parameter) const {
        cout << "error";
    }

    File& TextFile::cd(const string parameter) const {
        cout << "error";
    }

    bool TextFile::cp(const File* copyFile) {
        cout << "empty";
    }



}

