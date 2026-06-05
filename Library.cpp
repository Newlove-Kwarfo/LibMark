//This is Library.cpp
#include "Library.h"
#include "Book.h"
#include <string>
#include <vector>
#include <iostream>

namespace Libmark{
    Library::Library() {}; //default constructor

    //Behaviours
    void Library::addBook(const Book& book){
        m_books.push_back(book);
    }

    std::vector<Book> Library::searchByTitle(const std::string& title) const{
        std::vector<Book> matchingBooks;

        for (const auto& book : m_books){ //auto used her means auto detect type
            if (book.getTitle() == title){
                matchingBooks.push_back(book);
            }
        }
        return matchingBooks;
    }

    int Library::saveToFile(){
        if(m_storageFileName.empty()){
            std::cerr << "Error: Storage file name not set.\n";
            return -1;
        }
        return 0;
    }

    int Library::loadFromFile(){
        if(m_storageFileName.empty()){
            std::cerr << "Error: Storage file name not set.\n";
            return -1;
        }
        return 0;
    }
}//namespace Libmark