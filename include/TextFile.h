#ifndef TEXTFILE_H
#define TEXTFILE_H
#include <string>
#include <vector>
#include "Content.h"


// Object to hold TextFile


#define SCROLLING_CONTENT_SIZE 50

/* Create,Read,Delete .... */
class TextFile
{
public:
    TextFile();
    TextFile(Content cnt);
    TextFile(std::string fileName);
    virtual ~TextFile();

    void setFileName(std::string fileName);

    std::string getFileName();

    void setFileContent(Content* fileContentPtr);

    std::vector<Content*> getFileContent();

protected:

private:
    std::string fileName; // the fileName
    std::vector<Content*> fileContentVec; // a pointer to buffer of file content to keep.

};



#endif // TEXTFILE_H


