#include "TextFile.h"



TextFile::TextFile()
{
    //ctor
}


// ctor with filaname
TextFile::TextFile(std::string fileName)
{
    this->fileName = fileName;
}

TextFile::~TextFile()
{
    //dtor
}


// copy fileName
void TextFile::setFileName(std::string fileName){

this->fileName = fileName;


}

// get fileName
std::string TextFile::getFileName(){
return this->fileName;
}


// save content of the file as pointer.
void TextFile::setFileContent(Content* fileContentPtr){

this->fileContentVec.push_back(fileContentPtr);

}


// get all contents
std::vector<Content*> TextFile::getFileContent(){

return this->fileContentVec;
}

