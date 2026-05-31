#include "Note.h"

namespace Libmark {
    //Constructor1 for notes with pages
    Note::Note(int page, const std::string& content, const std::string& date)
        : m_pageNumber(page), m_noteContent(content), m_dateCreated(date) //list method of assignment
        {
            //
        }

    //Constructor2 for notes without pages
    Note::Note(const std::string& content, const std::string& date)
        : m_pageNumber(-1), m_noteContent(content), m_dateCreated(date)
        // -1 assigned to pageNumber as a default flag
        {
            //
        }

    //Getters
    int Note::getPageNumber() const {
        return m_pageNumber;
    }

    std::string Note::getNoteContent() const {
        return m_noteContent;
    }

    std::string Note::getDateCreated() const {
        return m_dateCreated;
    }

    //Setters
    void Note::setPageNumber(int newPageNumber){
        m_pageNumber = newPageNumber;
    }
    void Note::setNoteContent(const std::string newConent){
        m_noteContent = newConent;
    }

} // namespace Libmark