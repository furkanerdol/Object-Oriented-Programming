#ifndef EXECUTABLE_H
#define	EXECUTABLE_H

#include <iostream>
#include <string>
#include "File.h"

using namespace std;

namespace FurkanFileHierarchy {

    class Executable : public File {
    public:
        Executable(const string newFileName, const string newFileOwner, const int newFileSize, const string newCreatedCompiler);

        void ls(const string parameter) const;
        File& cd(const string parameter) const; 
        bool cp(const File* copyFile);

    private:
        string createdCompiler;
    };
}



#endif	/* EXECUTABLE_H */

