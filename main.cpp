#include <iostream>
#include "TextFile.h"
#include "TextEditorService.h"
#include <stdlib.h>
#include <sstream>


using namespace std;

/**
Project Title : Basic Command Line Editor
Date :
Author :
Summary:
This a simple, user-friendly text editor that allows users to
create, edit,
save and read plain text files.
**/


void showManual()
{
    cout <<"CLET EDITOR v1.0 MANUAL"<<endl;

    cout <<endl;

    cout <<"*******************************"<<endl;
    cout <<"Create (C) is a single command."<<endl;
    cout <<"********************************"<<endl;

    cout <<endl;

    cout <<"********************************"<<endl;
    cout <<"Edit(E) has subcommands tree."<<endl;
    cout <<"1. E,I -> Insert Text"<<endl;
    cout <<"2. E,D -> Delete Text"<<endl;
    cout <<"3. E,P -> Copy and Paste"<<endl;
    cout <<"4. E,F -> Find and replace"<<endl;

    cout <<"Each Edit subcommand may or may not have tree"<<endl;

    cout <<"1. E,I -> Insert Text"<<endl;
    cout <<"(E,I) : L -> line insertion"<<endl;
    cout <<"(E,I) : C -> character insertion"<<endl;
    cout<<"(E,I,L) : U -> line insertion on top of lineNumber"<<endl;
    cout <<"(E,I,L) : D -> line insertion below lineNumber."<<endl;
    cout <<"(E,I,L,U) : lineNumber -> text to insert at line number"<<endl;
    cout <<"(E,I,L,D) : lineNumber -> text to insert at line number"<<endl;

    cout <<"2. E,D -> Delete Text"<<endl;
    cout <<"(E,D) : lineNumber -> text to delete on that lineNumber"<<endl;

    cout <<"3. E,P -> Copy and Paste"<<endl;
    cout <<"(E,P) : [srcCpy, destCpy, destPaste ] -> copy and paste text below the target paste line"<<endl;
    cout <<endl;
    cout <<endl;

    cout <<"4. E,F -> Find and replace"<<endl;
    cout <<"(E,F) : [searchText, replaceText] -> find searchText and replace with replaceText"<<endl;
    cout <<"***************************************************"<<endl;


    cout <<"***************************************************"<<endl;
    cout <<"Read (R) has subcommands."<<endl;
    cout <<"1. (R, L) -> read with linenumber"<<endl;
    cout <<"2. (R,N)  -> read with no lineNumber."<<endl;
    cout <<"************************************************"<<endl;


    cout <<"******* Other Commands *************************"<<endl;
    cout <<"1. Save with (S) on Creation of File"<<endl;
    cout <<"2. Scroll with (Y) on lines more than 50"<<endl;
    cout <<"***************************************************"<<endl;
}



void showWelcomeMessage()
{


    for(int i  =  0 ; i < 10; i++)
    {

        cout <<endl;
    }

    for(int j = 0; j < 5; j++)
    {

        cout <<"\t";
    }
    cout <<"clet editor"<<endl;

    for(int j = 0; j < 5; j++)
    {

        cout <<endl;
    }


}

void showTxtEditorMenuLine()
{

    cout <<"Menu Commands : "<<endl;
    cout <<"Create File (C)"<<"\t"<<" | "<<"\t"<<"Edit File (E)"<<"\t"<<" | "<<"\t"<<"Read File (R)"<<endl;

}

void showReadCommands()
{

    cout <<"Read Commands : "<<endl;
    cout <<"1. Read with Line Numbering (L) " <<" \n" <<"2. Read with no line numbering (N) " <<endl;


}

void showEditCommands()
{

    cout <<"Edit Commands: "<<endl;
    cout <<"1. Insert Text (I)"<<endl<<"2. Delete Text (D) "<<endl<<"3. Copy and Paste(P)"<<endl <<"4. Find and Replace (F) "<<endl;

}


void showInsertTextCommands()
{

    cout <<"Insert Text Commands:"<<endl;
    cout <<"1. Line Insertion (L) "<<endl;
    //<<endl<<"2. Character insertion (C)"<<endl;


}

void displayErrorSelectionMessage()
{

    printf(" ~ invalid selection...");
}



runtime_error* validateInputExceptionHandler(auto type)
{


    // int
    if(type == 0)
    {

        return new runtime_error("~ invalid input ::  expected an integer");

    }

    // double
    if(type == 0.0)
    {

        return new  runtime_error("~ invalid input :: expected a double");


    }

    // string



    //char
    if(type == '\0')
    {

        return new  runtime_error("~ invalid input  :: expected a character");

    }


    // object types
    auto o_type = type;
    if(o_type == NULL)
    {

        return new  runtime_error("~ invalid input :: expected an object");


    }



    return nullptr;


}

void showLineInsertionOptions()
{

    cout <<"Up: (U) "<<endl<<"Down: (D) "<<endl;

}

int acceptCommand()
{

    char c;

    cout <<"Enter Command :";

    c = getchar();


    return c;
}


int main(int argc, char *argv[])
{

    // 1. take user input as name of file
    TextFile* txtFilePtr = nullptr;

    string fileName;

    if(argc == 1)
    {
        showManual();
    }
    else if(argc > 2)
    {
        printf("clet editor takes a file as the next argument.");
        printf("invalid arguments");

    }
    else
    {

        char* txt = argv[1];
        fileName = txt;

        txtFilePtr = new TextFile(fileName);



        // clear screen.
        system("cls");
        showWelcomeMessage();
        showTxtEditorMenuLine();
        cout <<"File:"<<txtFilePtr->getFileName()<<".txt"<<endl;

        runtime_error* errPtr = nullptr;


        // Blocks of functionality.
        // Create(C), Edit(E), Read(R)
        /**

        *******************************
        Create (C) is a single command.
        ********************************

        /**
        ********************************
        Edit(E) has subcommands tree.
        1. E,I -> Insert Text,
        2. E,D -> Delete Text
        3. E,P -> Copy and Paste
        4. E,F -> Find and replace

        Each Edit subcommand may or may not have tree

         1. E,I -> Insert Text
        (E,I) : L -> line insertion
        (E,I,L) : U -> line insertion on top of lineNumber
        (E,I,L) : D -> line insertion below lineNumber.
        (E,I,L,U) : lineNumber -> text to insert at line number
        (E,I,L,D) : lineNumber -> text to insert at line number

         2. E,D -> Delete Text
        (E,D) : lineNumber -> text to delete on that lineNumber

        3. E,P -> Copy and Paste
        (E,P) : [srcCpy, destCpy, destPaste ] -> copy and paste text below the target paste line



        4. E,F -> Find and replace
        (E,F) : [searchText, replaceText] -> find searchText and replace with replaceText
        ***************************************************


        ***************************************************
        Read (R) has subcommands.
        1. (R, L) -> read with linenumber
        2. (R,N)  -> read with no lineNumber.
        ************************************************


        ******* Other Commands *************************
        1. Save with (S) on Creation of File
        2. Scroll with (Y) on lines more than 50
        ***************************************************

        **/
        switch(acceptCommand())
        {


        // Create File
        case 'C':
        {



            // check file exist before creating.

            if(TextEditorService::checkFileExist(txtFilePtr))
            {

                cout <<endl;
                cout <<"File exist -- duplicate file not allowed."<<endl;
            }
            else
            {

                system("cls");
                cout <<"Type Content.\n";
                bool isCreated = TextEditorService::createTextFile(txtFilePtr);



                if(isCreated)
                {

                    cout <<"File Created"<<endl;
                }

            }

        }
        break;

        //Edit File Block
        case 'E':
        {


            // clear screen.
            system("cls");
            char eCmd;
            showEditCommands();
            cout <<"Command:";
            cin >> eCmd;


            switch(eCmd)
            {

            //Insertion of text
            case 'I':

            {

                system("cls");
                showInsertTextCommands();


                cout<<"File:"<<fileName<<".txt"<<endl;
                cout <<"Content:"<<endl;


                TextFile* rTxtptr =  TextEditorService::readTextFile(fileName);


                if(rTxtptr != nullptr)
                    for(int i =0,  l = 1; i < rTxtptr->getFileContent().size(); i++, l++)
                    {


                        std::vector<Content*> cntVecPtr = rTxtptr->getFileContent();
                        cout <<l<<" "<<cntVecPtr[i]->getData();


                    }



                cout <<"command:";
                char iCmd;
                cin >> iCmd;

                switch(iCmd)
                {



                // Line Insertion -- Insertion of Text block
                case 'L':
                {

                    cout <<"--- Line Insertion ---"<<endl;

                    showLineInsertionOptions();

                    char lineOpt;
                    cin >> lineOpt;

                    // Direction of Insertion...
                    switch(lineOpt)
                    {

                    // Up
                    case 'U':
                    {
                        int lineNumber;
                        string text;

                        cout <<"lineNumber:";
                        cin >> lineNumber;


                        errPtr =   validateInputExceptionHandler(lineNumber);

                        if(errPtr != nullptr)
                        {

                            cout << errPtr->what() <<endl;

                        }
                        else
                        {

                            cout <<"text:";
                            getline(cin >> ws, text);
                            TextEditorService::doUpdateFileLineOnUpCmd(text,lineNumber,fileName);
                        }



                    }

                    break;

                    // Down
                    case 'D':
                    {
                        int lineNumber;
                        string text;

                        cout <<"lineNumber:";
                        cin >> lineNumber;

                        // check the input
                        errPtr =   validateInputExceptionHandler(lineNumber);

                        if(errPtr != nullptr)
                        {

                            cout << errPtr->what() <<endl;

                        }
                        else
                        {


                            cout <<"text:";
                            getline(cin >> ws, text);
                            TextEditorService::doUpdateFileLineOnDwnCmd(text,lineNumber,fileName);
                        }

                    }

                    break;

                    default:
                        displayErrorSelectionMessage();

                    }




                }

                break;

                default:
                    displayErrorSelectionMessage();


                }






            }
            break;


            //Delete Text Block
            case 'D':
            {


                cout<<"File:"<<txt<<".txt"<<endl;
                cout <<"Content:"<<endl;


                TextFile* rTxtptr =  TextEditorService::readTextFile(fileName);


                if(rTxtptr != nullptr)
                    for(int i =0,  l = 1; i < rTxtptr->getFileContent().size(); i++, l++)
                    {


                        std::vector<Content*> cntVecPtr = rTxtptr->getFileContent();
                        cout <<l<<" "<<cntVecPtr[i]->getData();


                    }



                int lineNumber;
                cout <<"lineNumber:"<<endl;
                cin >>lineNumber;


                // check the input
                errPtr =   validateInputExceptionHandler(lineNumber);

                if(errPtr != nullptr)
                {

                    cout << errPtr->what() <<endl;

                }
                else
                {


                    bool isDeleted =    TextEditorService::deleteText(lineNumber,fileName);

                    if(isDeleted)
                    {


                        cout <<" Text deleted "<<endl;
                    }

                }
            }

            break;

            //Copy and Paste Block
            case 'P':
            {


                cout<<"File:"<<fileName<<".txt"<<endl;
                cout <<"Content:"<<endl;


                TextFile* rTxtptr =  TextEditorService::readTextFile(fileName);


                if(rTxtptr != nullptr)
                    for(int i =0,  l = 1; i < rTxtptr->getFileContent().size(); i++, l++)
                    {


                        std::vector<Content*> cntVecPtr = rTxtptr->getFileContent();
                        cout <<l<<" "<<cntVecPtr[i]->getData();


                    }



                int srcCopy, dstCopy, dstPaste;
                cout <<"start copy (lineNumber):";
                cin >> srcCopy;

                errPtr =  validateInputExceptionHandler(srcCopy);

                if(errPtr != nullptr)
                {

                    cout << errPtr->what() <<endl;
                    break;
                }



                cout <<"end copy (lineNumber):";
                cin >>dstCopy;

                errPtr =  validateInputExceptionHandler(dstCopy);

                if(errPtr != nullptr)
                {

                    cout << errPtr->what() <<endl;
                    break;
                }


                cout <<"target paste (lineNumber):";
                cin >> dstPaste;

                errPtr =  validateInputExceptionHandler(dstPaste);

                if(errPtr != nullptr)
                {

                    cout << errPtr->what() <<endl;
                    break;
                }



                bool done = TextEditorService::doCopyandPasteText(srcCopy,dstCopy,dstPaste,fileName);

                if(done)
                {

                    printf("contents from lines (%d - %d) copied and pasted to %d", srcCopy, dstCopy, dstPaste);
                }
                else
                {
                    cout <<"copy and paste failed ...";

                }




            }

            break;

            //Find and Replace block
            case 'F':
            {




                cout<<"File:"<<txt<<".txt"<<endl;
                cout <<"Content:"<<endl;


                TextFile* rTxtptr =  TextEditorService::readTextFile(fileName);


                if(rTxtptr != nullptr)
                    for(int i =0,  l = 1; i < rTxtptr->getFileContent().size(); i++, l++)
                    {


                        std::vector<Content*> cntVecPtr = rTxtptr->getFileContent();
                        cout <<l<<" "<<cntVecPtr[i]->getData();


                    }


                cout <<"Find:";
                std::string txtToFind;
                getline(cin >> ws, txtToFind);


                cout <<"Replace:";
                std::string txtToReplace;
                cin >> txtToReplace;
                getline(cin >> ws, txtToReplace);



                // for each occurance of the word, replace.
                TextEditorService::doFindAndReplace(txtToFind,fileName,txtToReplace);





            }

            break;

            default:
                cout <<"Invalid edit commands"<<endl;






            }










        }



        break;

// READ BLOCK
        case 'R':
        {
            system("cls");

            showReadCommands();

            char rCmd;
            cout <<"Command :"<<endl;
            cin >> rCmd;

            TextFile* rTxtptr =  TextEditorService::readTextFile(fileName);

            int scrollingLineNumber; //0

            bool isScrolling = false;

            bool lineNumberisEnabled = true;



            switch(rCmd)
            {

            case 'L':
            {


                if(rTxtptr != nullptr)
                {

                    for(int i =0,  line = 1; i < rTxtptr->getFileContent().size(); i++, line++)
                    {


                        std::vector<Content*> cntVecPtr = rTxtptr->getFileContent();
                        cout <<line << " " <<cntVecPtr[i]->getData();

                        if(i == SCROLLING_CONTENT_SIZE)
                        {

                            scrollingLineNumber =i;
                            isScrolling = true; //enable scrolling.
                            break;
                        }

                    }

                }


                if(!isScrolling)
                {
                    ;
                }
                else
                {
                    //  linebreak when 50
                    TextEditorService::scrollFile(scrollingLineNumber,rTxtptr,lineNumberisEnabled);
                }







            }



            break;

            case 'N':
            {

                lineNumberisEnabled = false;


                if(rTxtptr != nullptr)
                {

                    for(int i =0; i < rTxtptr->getFileContent().size(); i++)
                    {


                        std::vector<Content*> cntVecPtr = rTxtptr->getFileContent();
                        cout  <<cntVecPtr[i]->getData();

                        if(i == SCROLLING_CONTENT_SIZE)
                        {

                            scrollingLineNumber =i;
                            isScrolling = true; //enable scrolling.
                            break;
                        }

                    }

                }


                if(!isScrolling)
                {
                    ;
                }
                else
                {
                    //  linebreak when 50
                    TextEditorService::scrollFile(scrollingLineNumber,rTxtptr,lineNumberisEnabled);
                }





            }


            break;

            default:
                displayErrorSelectionMessage();


            }




        }
        break;

        default:
            cout <<"Invalid command"<<endl;



        }


        // remove the err message from memory after display
        if(!errPtr)
        {

            delete errPtr;
        }


    }


    delete argv;


    return 0;
}
