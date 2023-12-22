#ifndef CONTENT_H
#define CONTENT_H
#include <string>

// File Content Object...
class Content
{
    public:
        Content();
        Content(std::string data); // the lines of the plain text files.
        virtual ~Content();

        void setData(std::string data);

        std::string getData();

    protected:

    private:
        std::string data;
};

#endif // CONTENT_H

//Content.data = "line1"
