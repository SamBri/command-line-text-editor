#include "Content.h"

Content::Content()
{
    //ctor
}



Content::Content(std::string data)
{
    this->data=data;
}


Content::~Content()
{
    //dtor
}


void Content::setData(std::string data){
this->data = data;
}



std::string Content::getData(){
return this->data;
}

