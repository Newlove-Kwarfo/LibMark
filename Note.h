//This is Note.h
#pragma once
# include <string>

namespace Libmark {
    class Note {
    public:
        //Constructor1 for notes with pages
        Note(int page, const std::string& content, const std::string& date);
        //Constructor2 for notes without pages
        Note(const std::string& content, const std::string& date);

        //Getters
        int getPageNumber() const; 
        std::string getNoteContent() const;
        std::string getDateCreated() const;

        //Setters
        void setPageNumber(int newPageNumber);
        void setNoteContent(const std::string newConent);
        void setDateCreated(const std::string newDate);

    private:
        int m_pageNumber; //m_ conventionally denotes member variable of function
        std::string m_noteContent;
        std::string m_dateCreated;

    }; //class Note
} // namespace Libmark