#pragma once

#include "Note.h"
#include <string>
#include <vector>

namespace Libmark {
    class Book{
    public:
        //Constructor1 - with currentPage and notes
        Book(const std::string& title, const std::string& author, int totalPages, int currentPage, const std::vector<Note>& notes);
        //Constructor2 - without currentPage and notes
        Book(const std::string& title, const std::string& author, int totalPages);
        //Constructor3 - without notes
        Book(const std::string& title, const std::string& author, int totalPages, int currentPage);

        //Behaviours
        void addNote(const Note& newNote);

        //Getters
        std::string getTitle() const;
        std::string getAuthor() const;
        int getTotalPages() const;
        int getCurrentPage() const;
        const std::vector<Note>& getNotes() const; //retreives all notes belonging to book


    private:
        std::string m_title;
        std::string m_author;
        int m_totalPages;
        int m_currentPage;
        std::vector<Note> m_notes;
    }; //class Book
} // namespace Libmark