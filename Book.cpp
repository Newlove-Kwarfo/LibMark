#include "Book.h"

namespace Libmark {
        //Constructor1 - with currentPage and notes
        Book::Book(const std::string& title, const std::string& author, int totalPages, int currentPage, const std::vector<Note>& notes)
            : m_title(title), m_author(author), m_totalPages(totalPages), m_currentPage(currentPage), m_notes(notes)
            {
                //
            }
        
        //Constructor2 - without currentPage and notes
        Book::Book(const std::string& title, const std::string& author, int totalPages)
            : m_title(title), m_author(author), m_totalPages(totalPages), m_currentPage(0), m_notes()
            {
                //
            }

        //Constructor3 - without notes
        Book::Book(const std::string& title, const std::string& author, int totalPages, int currentPage)
            : m_title(title), m_author(author), m_totalPages(totalPages), m_currentPage(currentPage), m_notes()
            {
                //
            }
        
        //Behaviours
        void Book::addNote(const Note& newNote){
            m_notes.push_back(newNote);
        }

        //Getters
        std::string Book::getTitle() const{
            return m_title;
        }
        std::string Book::getAuthor() const{
            return m_author;
        }
        int Book::getTotalPages() const{
            return m_totalPages;
        }
        int Book::getCurrentPage() const {
            return m_currentPage;
        }
        const std::vector<Note>& Book::getNotes() const {
            return m_notes;
        }

} //namespace Libmark