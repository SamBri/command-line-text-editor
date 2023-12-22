#include "TextEditorService.h"

TextEditorService::TextEditorService()
{
    //ctor
}

TextEditorService::~TextEditorService()
{
    //dtor
}


/**
This function creates textfiles as a pointer
**/
bool TextEditorService::createTextFile(TextFile* txtFilePtr)
{


    std::ofstream out;
    std::string line;

    // open the file
    out.open(txtFilePtr->getFileName()+".txt"); //for write
    if(!out)
    {

        std::cout <<"Cannot open "<< txtFilePtr->getFileName() << " file " <<std::endl;

        throw std::runtime_error("file exception.");


        return false;
    }


    // read lines from standard input
    while(getline(std::cin, line))
    {

        if(!line.empty())
        {


            // write to file
            out << line << "\n";
        }


    }



    // deprecate....
    // upon detection of EOF, allow file to be saved on response.
//    if(std::cin.eof())
//    {
//
//        std::cout <<"--- Save (S) ---- "<<std::endl;
//        char saveCmd;
//        saveCmd =  getchar() ;
//        if(saveCmd == 'S')
//        {
// close file
            out.close();
//            std::cout <<"Saved!."<<std::endl;
//        }
//
//        else
//        {
//
//            return false;
//        }
//    }


    // success creation.
    return true;

}


/**
This function allows TextFile to be read.
**/
TextFile* TextEditorService::readTextFile(std::string fileName)
{


 std::ifstream in;


     //
    in.open(fileName+".txt"); // open file for read.
    if(!in)
    {



        std::cout <<"Cannot open "<< fileName << " file " <<std::endl;

        throw std::runtime_error("file exception. -- not found");

        return nullptr;

    }


    std::string text;

    // a single textfile
    TextFile* txtFilePtr = new TextFile();
    txtFilePtr->setFileName(fileName);


    // read a line from the file.
    while(getline(in,text))
    {

        // save the content
        text = text + "\n";
        Content* fileCntPtr = new Content(text); // a new content on each iteration.

        txtFilePtr->setFileContent(fileCntPtr);

    }


    in.close();


    return txtFilePtr;


}


/***
This function does insertion of text up a line number
**/
bool TextEditorService::doUpdateFileLineOnUpCmd(std::string content, int lineNumber, std::string fileName)
{

    std::ifstream in;



    in.open(fileName+".txt"); //for read

    if(!in)
    {

        std::cout <<"Cannot open "<< fileName << " file " <<std::endl;

        throw std::runtime_error("file exception.");

        return false; //false;

    }





    std::vector<std::string> backedUpLines; // have a vector of strings to save lines read.

    std::string line;
    int rowId;
    rowId = lineNumber  - 1;



    while(getline(in, line))
    {

        // save the file content
        backedUpLines.push_back(line);


    }

    in.close();

    std::vector<std::string> modifiedLines; // have a vector of strings to save lines modified.
    std::string textBefore;


    for(int i =0 ; i < backedUpLines.size(); i++)
    {


        if(i == rowId)
        {
            textBefore =  backedUpLines[i];
            modifiedLines.push_back(content);
            modifiedLines.push_back(textBefore);

        }
        else
        {

            modifiedLines.push_back(backedUpLines[i]);
        }




    }



    // write operations after copy to buffer.
    std::ofstream out;

    out.open(fileName+".txt", std::ofstream::out); //for read
    if(!out)
    {

        std::cout <<"Cannot open "<< fileName << " file " <<std::endl;

        throw std::runtime_error("file exception.");


        return false; // null account;

    }


    // then write new lines
    for(int i =0 ; i < modifiedLines.size(); i++)
    {

        // write content to file
        out << modifiedLines[i]<<"\n";
    }



//    // upon detection of EOF, allow file to be saved on response.
//
//    if(std::cin.eof())
//    {
//
//        std::cout <<"--- Save (S) ---- "<<std::endl;
//        char saveCmd;
//        saveCmd =  getchar() ;
//        if(saveCmd == 'S')
//        {
//// close file
//            out.close();
//            std::cout <<"Saved!."<<std::endl;
//        }
//
//        else
//        {
//
//            return false;
//        }
//    }


// close file
            out.close();
    return true;


};



bool TextEditorService::doUpdateFileLineOnDwnCmd(std::string content, int lineNumber, std::string fileName)
{


    std::ifstream in;

    in.open(fileName+".txt"); //for read

    if(!in)
    {

        std::cout <<"Cannot open "<< fileName << " file " <<std::endl;

        throw std::runtime_error("file exception.");

        return false; // null account;

    }





    std::vector<std::string> backedUpLines; // have a vector of strings to save lines read.

    std::string line;
    int rowId;
    rowId = lineNumber - 1;



    while(getline(in, line))
    {

        // save the records
        backedUpLines.push_back(line);


    }

    in.close();

    std::vector<std::string> modifiedLines; // have a vector of strings to save lines modified.
    std::string textAfter;


    // update the backup record with the new line.
    for(int i =0 ; i < backedUpLines.size(); i++)
    {


        if(i == rowId)
        {

            textAfter = backedUpLines[i];
            modifiedLines.push_back(textAfter);
            modifiedLines.push_back(content);


        }
        else
        {

            modifiedLines.push_back(backedUpLines[i]);
        }




    }


    std::ofstream out;

    out.open(fileName+".txt", std::ofstream::out); //for read
    if(!out)
    {

        std::cout <<"Cannot open "<< fileName << " file " <<std::endl;

        throw std::runtime_error("file exception.");


        return false; // null account;

    }


    // then write fresh records
    for(int i =0 ; i < modifiedLines.size(); i++)
    {

        // write content to file
        out << modifiedLines[i]<<"\n";
    }



    // close file
   out.close();



    return true;


};




bool TextEditorService::deleteText( int lineNumber, std::string fileName)
{

    std::ifstream in;

    in.open(fileName+".txt"); //for read

    if(!in)
    {

        std::cout <<"Cannot open "<< fileName << " file " <<std::endl;

        throw std::runtime_error("file exception.");

        return false; // null account;

    }





    std::vector<std::string> backedUpLines; // have a vector of strings to save lines read.

    std::string line;
    int rowId;
    rowId = lineNumber - 1;



    while(getline(in, line))
    {

        // save the lines
        backedUpLines.push_back(line);


    }

    in.close();

    std::vector<std::string> modifiedLines;   // have a vector of strings to save lines modified.



    // update the backup record with ""
    for(int i =0 ; i < backedUpLines.size(); i++)
    {


        if(i == rowId)
        {

            backedUpLines[i] = "";


        }
        else
        {

            modifiedLines.push_back(backedUpLines[i]);
        }




    }


    std::ofstream out;

    out.open(fileName+".txt", std::ofstream::out); //for read
    if(!out)
    {

        std::cout <<"Cannot open "<< fileName << " file " <<std::endl;

        throw std::runtime_error("file exception.");


        return false; //;

    }


    // then write fresh lines
    for(int i =0 ; i < modifiedLines.size(); i++)
    {

        // write content to file
        out << modifiedLines[i]<<"\n";
        std::cout <<modifiedLines[i]<<std::endl;
    }

    // close file
    out.close();



    return true;





}


bool TextEditorService::doCopyandPasteText(int srcCpLn, int destCpLn, int destPstLn, std::string fileName)
{
    std::ifstream in;

    in.open(fileName+".txt"); //for read

    if(!in)
    {

        std::cout <<"Cannot open "<< fileName << " file " <<std::endl;

        throw std::runtime_error("file exception.");

        return false; // null account;

    }


    std::vector<std::string> backedUpLines;

    std::string line;
    int srcCpRowId =  srcCpLn - 1;
    int dstCpRowId = destCpLn - 1;
    int destPstRowId =  destPstLn - 1;



    while(getline(in, line))
    {

        // save the records
        backedUpLines.push_back(line);


    }

    in.close();

    std::vector<std::string> modifiedLines; //
    std::vector<std::string> tempTextContainer; // clipboard or buffer to hold copied content


    // put the copy text in a tempTextContainter.
    for(int i = 0, head =srcCpRowId ; i < backedUpLines.size(); i++,head++)
    {


    modifiedLines.push_back(backedUpLines[i]); // save the lines to the modified lines

    //move copied lines to the clipboard.
    if(head >= i &&  head <= dstCpRowId){
     tempTextContainer.push_back(backedUpLines[head]);
    }

    }


    std::ofstream out;

    out.open(fileName+".txt", std::ofstream::out); //for read
    if(!out)
    {

        std::cout <<"Cannot open "<< fileName << " file " <<std::endl;

        throw std::runtime_error("file exception.");


        return false; // null account;

    }


    // then write fresh records
    for(int i =0 ; i < modifiedLines.size(); i++)
    {

        // write content to file
        out << modifiedLines[i]<<"\n";

     if(i == destPstRowId){

     // write contents from the clipboard.
      for(int k = 0; k < tempTextContainer.size(); k++)
      {

        out <<tempTextContainer[k]<<"\n";

      }

    }



    }

    // close file
    out.close();




    return true;

}


/**
This function finds a text, replaces a text
**/
bool TextEditorService::doFindAndReplace(std::string searchTxt, std::string fileName, std::string replaceTxt)
{


    std::ifstream in;

    in.open(fileName+".txt"); //for read

    if(!in)
    {

        std::cout <<"Cannot open "<< fileName << " file " <<std::endl;

        throw std::runtime_error("file exception.");

        return false; // null account;

    }





    std::vector<std::string> backedUpLines;

    std::string line;
    int modifiedRowNumber;




    while(getline(in, line))
    {

        // save the records
        backedUpLines.push_back(line);


    }

    in.close();

    std::vector<std::string> modifiedLines; //


    int wordCount = 0;

    // update the backup record with the new line.
    for(int i =0; i < backedUpLines.size(); i++)
    {


        if(backedUpLines[i] == searchTxt)
        {

            backedUpLines[i] = replaceTxt;
            modifiedLines.push_back(backedUpLines[i]);
            wordCount++;

        }
        else
        {

            modifiedLines.push_back(backedUpLines[i]);
        }




    }

    std::cout <<"Found:"<<wordCount<<","<<"Replaced:"<<wordCount<<std::endl;


    std::ofstream out;

    out.open(fileName+".txt", std::ofstream::out); //for read
    if(!out)
    {

        std::cout <<"Cannot open "<< fileName << " file " <<std::endl;

        throw std::runtime_error("file exception.");


        return false; // false;

    }


    // then write fresh records
    for(int i =0 ; i < modifiedLines.size(); i++)
    {

        // write content to file
        out << modifiedLines[i]<<"\n";
        std::cout <<modifiedLines[i]<<std::endl;
    }

    // close file
    out.close();



    return true;



}




/**
This function scrolls through a file to a page break of 50.
**/
TextFile* TextEditorService::scrollFile(int lineNumber,TextFile* txtFilePtr, bool lineNumberisEnabled)
{

// if the file size is more than 50 lines,

// paginate on Y command.
    std::ifstream in;


    in.open(txtFilePtr->getFileName()+".txt"); // open file for read.
    if(!in)
    {



        std::cout <<"Cannot open "<< txtFilePtr->getFileName() << " file " <<std::endl;

        throw std::runtime_error("file exception.");

        return nullptr;

    }


    std::string text;


    // check the file size. || number of lines
    int contentSize = txtFilePtr->getFileContent().size();


    char scroll = 'Y';
    for(int i = lineNumber; i < contentSize && scroll =='Y'; i++ )
    {

        std::vector<Content*> cntVecPtr = txtFilePtr->getFileContent();



        if(lineNumberisEnabled){
        std::cout <<i << " " <<cntVecPtr[i]->getData();
        } else{
        std::cout <<cntVecPtr[i]->getData();
        }

        // at line 50, prompt user to scroll.
        if(i % 50 == 0)
        {
            std::cout << "---------------- SCROLL -----------------------------"<<std::endl;
            std::cin >> scroll;

        }

    }




    in.close();


    return txtFilePtr;


}



/**
This function checks for the existance of a file.
**/
bool TextEditorService::checkFileExist(TextFile* txtFilePtr)
{

    std::ifstream in;

    in.open(txtFilePtr->getFileName()+".txt"); // open file for read.
    if(!in)
    {
   // i literally  do nothing if the file cannot open.
    }
    else
    {

        in.close();
        return true;
    }

    return false; // by default, the file does not exist




}













