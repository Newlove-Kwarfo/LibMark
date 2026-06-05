//This is Book.cpp
#include <iostream>
#include "Book.h"

namespace Libmark {
        //Constructor1 - with currentPage
        Book::Book(const std::string& title, const std::string& author, int totalPages, int currentPage, BookType type, BookStatus status)
            : m_title(title), m_author(author), m_totalPages(totalPages), m_currentPage(currentPage), m_type(type), m_status(status)
            {
                //
            }
        
        //Constructor2 - without currentPage
        Book::Book(const std::string& title, const std::string& author, int totalPages, BookType type, BookStatus status)
            : m_title(title), m_author(author), m_totalPages(totalPages), m_currentPage(0), m_type(type), m_status(status)
            {
                //
            }
        
        //Behaviours
        void Book::addNote(const Note& newNote){
            m_notes.push_back(newNote);
        }

        void Book::removeNote(int index){
            if (index >= 0 && static_cast<size_t>(index) < m_notes.size()){
                m_notes.erase(m_notes.begin() + index);
            } else {
                std::cout << "Error: Cannot remove note";
            }
        };

        void Book::addGenre(const std::string& genre){ //adding genre to genre list
            if (!genre.empty()){m_genres.push_back(genre);}
        }

        void Book::loadGenres(const std::vector<std::string>& genres){ //adding genre to genre list
            m_genres = genres;
        }

        void Book::loadNotes(const std::vector<Note>& notes){ //adding notes to notes list
            m_notes = notes;
        }

        float Book::calculateProgress() const {
            return (static_cast<float>(m_currentPage)/m_totalPages)*100.0f;
        }

        //Getters
        std::string Book::getTitle() const{
            return m_title;
        }
        std::string Book::getAuthor() const{
            return m_author;
        }
        std::string Book::getLanguage() const{
            return m_language;
        }
        int Book::getTotalPages() const{
            return m_totalPages;
        }
        int Book::getCurrentPage() const {
            return m_currentPage;
        }
        BookStatus Book::getStatus() const {
            return m_status;
        }
        BookType Book::getType() const {
            return m_type;
        }
        const std::vector<Note>& Book::getNotes() const {
            return m_notes;
        }

        const std::vector<std::string>& Book::getGenres() const {
            return m_genres;
        }
        float Book::getRating() const{
            return m_rating;
        }
        std::string Book::getReview() const{
            return m_review;
        }
        std::string Book::getIsbn() const{
            return m_isbn;
        }
        std::string Book::getCoverPath() const{
            return m_coverPath;
        }


        // Setters
        void Book::setTitle(const std::string& newTitle) {
            m_title = newTitle;
        }
        void Book::setAuthor(const std::string& newAuthor) {
            m_author = newAuthor;
        }
        void Book::setLanguage(const std::string& lang) {
            m_author = lang;
        }
        void Book::setCurrentPage(int page) {
            m_currentPage = page;
        }
        void Book::setTotalPages(int pages) {
            m_totalPages = pages;
        }
        void Book::setType(BookType newType){
            m_type = newType;
        }
        void Book::updateStatus(BookStatus newStatus) {
            m_status = newStatus;
        }
        void Book::setRating(float newRating){
            m_rating = newRating;
        }
        void Book::setReview(const std::string& newReview){
            m_review = newReview;
        }
        void Book::setIsbn(const std::string& newIsbn){
            m_isbn = newIsbn;
        }
        void Book::setCoverPath(const std::string& newCoverPath){
            m_coverPath = newCoverPath;
        }

} //namespace Libmark