#include <iostream>
#include <ctime>
#include "File.h"


using namespace std;

namespace FurkanFileHierarchy {
    
    File::File(string newFileName, string newFileOwner, int newFileSize)
    : fileName(newFileName), fileOwner(newFileOwner), fileSize(newFileSize) {
        setLastModification();
          }

    File::File(string newFileName, string newFileOwner)
    : fileName(newFileName), fileOwner(newFileOwner), fileSize(10) {
        setLastModification();
           }

    File::File(string newFileName)
    : fileName(newFileName), fileOwner("furkan"), fileSize(10) {
        setLastModification();
           }

    File::File()
    : fileName("new file"), fileOwner("furkan"), fileSize(10) {
        setLastModification();
            }

    void File::setFileName(const string newFileName) {
        fileName = newFileName;
    }

    void File::setFileOwner(const string newFileOwner) {
        fileOwner = newFileOwner;
    }

    void File::setFileSize(const int newFileSize) {
        fileSize = newFileSize;
    }

    void File::setLastModification(const int newDay, const int newMonth, const int newYear) {
        lastModificaiton.tm_mday = newDay;
        lastModificaiton.tm_mon = newMonth;
        lastModificaiton.tm_year = newYear;

    }

    void File::setLastModification() {
        time_t currentTime;

        time(&currentTime);
        tm* local = localtime(&currentTime);
        
        lastModificaiton.tm_mday = local->tm_mday;
        lastModificaiton.tm_mon = local->tm_mon + 1;
        lastModificaiton.tm_year = local->tm_year + 1900;
    }

    string File::path() {
        return filePath;
    }
   
}
