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

    private:
        int m_pageNumber; //m_ conventionally denotes member variable of function
        std::string m_noteContent;
        std::string m_dateCreated;

    }; //class Note
} // namespace Libmark