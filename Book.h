//This is Book.h
#pragma once

#include "Note.h"
#include <string>
#include <vector>

namespace Libmark {
    enum class BookStatus {
        WANT_TO_READ,
        READING,
        COMPLETED,
        ON_HOLD,
        GAVE_UP
    };

    enum class BookType {
        PAPERBACK,
        HARDCOVER,
        EBOOK,
        AUDIOBOOK,
    };

    class Book{
    public:
        //Constructor1 - with currentPage
        Book(const std::string& title, const std::string& author, int totalPages, int currentPage, BookType type, BookStatus status);
        
        //Constructor2 - without currentPage
        Book(const std::string& title, const std::string& author, int totalPages, BookType type, BookStatus status);

        //Behaviours
        void addNote(const Note& newNote);
        void removeNote(int index);
        void addGenre(const std::string& genre);
        void loadGenres(const std::vector<std::string>& genres);
        void loadNotes(const std::vector<Note>& notes);
        float calculateProgress() const;

        //Getters
        std::string getTitle() const;
        std::string getAuthor() const;
        std::string getLanguage() const;
        BookStatus getStatus() const;
        BookType getType() const;
        int getTotalPages() const;
        int getCurrentPage() const;
        const std::vector<Note>& getNotes() const; //retreives all notes belonging to book
        const std::vector<std::string>& getGenres() const;
        float getRating() const;
        std::string getReview() const;
        std::string getIsbn() const;
        std::string getCoverPath() const;

        //Setter
        void setTitle(const std::string& newTitle);
        void setAuthor(const std::string& newAuthor);
        void setLanguage(const std::string& lang);
        void setType(BookType newType);
        void setTotalPages(int pages);
        void setCurrentPage(int page);
        void updateStatus(BookStatus newStatus);
        void setRating(float newRating);
        void setReview(const std::string& newReview);
        void setIsbn(const std::string& newIsbn);
        void setCoverPath(const std::string& newCoverPath);

    
    private:
        std::string m_title;
        std::string m_author;
        std::string m_language;
        BookStatus m_status;
        BookType m_type;
        int m_totalPages;
        int m_currentPage;
        std::vector<Note> m_notes;
        std::vector<std::string> m_genres;
        float m_rating;
        std::string m_review;
        std::string m_isbn;
        std::string m_coverPath;

    }; //class Book
} // namespace Libmark