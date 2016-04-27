#ifndef TEXTFILE_H
#define	TEXTFILE_H

#include <iostream>
#include <string>
#include "File.h"

using namespace std;

namespace FurkanFileHierarchy {

    class TextFile : public File {
    public:
        TextFile(const string newFileName, const string newFileOwner, const int newFileSize, const string newTextType);

        void ls(const string parameter) const;
        File& cd(const string parameter) const; 
        bool cp(const File* copyFile);

    private:
        string textType;

    };
}



#endif	/* TEXTFILE_H */

