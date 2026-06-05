//This is Library.h
#pragma once

#include "Book.h"
#include <string>
#include <vector>

namespace Libmark {
    class Library{
    private:
        std::string m_storageFileName;
        std::vector<Book> m_books;

    public:
        //Behaviours
        Library(); //default constructor

        void addBook(const Book& book);
        std::vector<Book> searchByTitle(const std::string& title) const;

        int saveToFile();
        int loadFromFile();

        //Setters
        void setStorageFileName(const std::string& filename);

    }; // class Library
} //namespace Libmark
