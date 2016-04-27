#ifndef DIRECTORY_H
#define	DIRECTORY_H

#include <iostream>
#include <string>
#include <vector>
#include "File.h"

using namespace std;

namespace FurkanFileHierarchy {

    class Directory : public File {
    public:
        Directory(const string newFileName, const string newFileOwner, const int newFileSize);

        void ls(const string parameter) const;
        File& cd(const string parameter) const;
        bool cp(const File* copyFile);

    private:
        string directoryPath;
        vector <File *> directory;
    };

}



#endif	/* DIRECTORY_H */

