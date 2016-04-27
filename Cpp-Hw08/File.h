#ifndef FILE_H
#define	FILE_H

#include <iostream>
#include <string>

using namespace std;

namespace FurkanFileHierarchy{
    
    class File{
    public:
        
        File(string newFileName, string newFileOwner, int newFileSize);
        File(string newFileName, string newFileOwner);
        File(string newFileName);
        File();
                
        string getFileName() const {return fileName;}
        string getFileOwner() const {return fileOwner;}
        int getFileSize() const {return fileSize;}
        tm getLastModification() const {return lastModificaiton;}
        
        void setFileName(const string newFileName);
        void setFileOwner(const string newFileOwner);
        void setFileSize(const int newFileSize);
        void setLastModification(const int newDay, const int newMonth, const int newYear);
        void setLastModification();
        
        void setFilePath(const string nextPath);
        string path();
        
        virtual void ls(const string parameter) const = 0 ;
        virtual File& cd(const string parameter) = 0;
        virtual bool cp(const File* copyFile) = 0;       
        
    private:
        string fileName;
        string fileOwner;
        int fileSize;
        tm lastModificaiton;
        string filePath;
    };
    
   
}

#endif	/* FILE_H */

