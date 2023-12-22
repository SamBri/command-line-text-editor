#ifndef TEXTEDITORSERVICE_H
#define TEXTEDITORSERVICE_H
#include "TextFile.h"
#include <fstream>
#include <iostream>


// Object that gives clet editor functionality.
class TextEditorService
{
public:
    TextEditorService();
    virtual ~TextEditorService();
    static bool createTextFile(TextFile* txtFilePtr);// Create TextFile
    static TextFile* readTextFile(std::string fileName); // Read TextFile
    bool static doUpdateFileLineOnUpCmd(std::string content, int lineNumber, std::string fileName); // Insert Text Up
    bool static doUpdateFileLineOnDwnCmd(std::string content, int lineNumber, std::string fileName); // Insert Text down.
    bool static deleteText(int lineNumber, std::string fileName); // Delete text by linenumber
    bool static doCopyandPasteText(int srcCpLn, int destCpLn, int destPstLn, std::string fileName); // copy and paste text below the target paste line , -y axis direction
    bool static doFindAndReplace(std::string searchWord, std::string fileName, std::string replaceWord); // Find and Replace Text.
    bool static checkFileExist(TextFile* txtFilePtr); // Avoid duplicate creation of files.
    static TextFile* scrollFile(int lineNumber,TextFile* txtFilePtr, bool lineNumberisEnabled);// scroll through file

protected:

private:

};

#endif // TEXTEDITORSERVICE_H
