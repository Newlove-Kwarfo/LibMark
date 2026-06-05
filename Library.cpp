//This is Library.cpp
#include "Library.h"
#include "Book.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace Libmark{

    Library::Library() {}; //default constructor

    //Setters
    void Library::setStorageFileName(const std::string& filename){
        m_storageFileName = filename;
    }

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
        if(m_storageFileName.empty()){ //check if there is a file determined for storageFileName;
            std::cerr << "Error: Storage file name not set.\n";
            return -1;
        }

        std::ofstream outFile(m_storageFileName);

        if (!outFile){ //check for existence of outfile
            std::cerr << "Error. Could not find data file to save.\n";
            return -2;
        }

        for (const auto& book : m_books){ //write content out for saving

        outFile << book.getTitle() << "\n";
        outFile << book.getAuthor() << "\n";
        outFile << book.getLanguage() << "\n";
        
            switch (book.getStatus()){
            case Libmark::BookStatus::WANT_TO_READ:
                outFile << "wantToRead\n";
                break;
            case Libmark::BookStatus::READING:
                outFile << "reading\n";
                break;
            case Libmark::BookStatus::COMPLETED:
                outFile << "completed\n";
                break;
            case Libmark::BookStatus::ON_HOLD:
                outFile << "onHold\n";
                break;
            case Libmark::BookStatus::GAVE_UP:
                outFile << "gaveUp\n";
                break;
            }

            switch (book.getType()){
            case Libmark::BookType::AUDIOBOOK:
                outFile << "Audiobook\n";
                break;
            case Libmark::BookType::PAPERBACK:
                outFile << "Paperback\n";
                break;
            case Libmark::BookType::HARDCOVER:
                outFile << "Hardcover\n";
                break;
            case Libmark::BookType::EBOOK:
                outFile << "Ebook\n";
                break;
            }

        outFile << book.getTotalPages() << "\n";
        outFile << book.getCurrentPage() << "\n";
        outFile << book.getRating() << "\n";
        outFile << book.getReview() << "\n";
        outFile << book.getIsbn() << "\n";
        outFile << book.getCoverPath() << "\n";

            outFile << book.getGenres().size() << "\n";
            for (const auto& genre : book.getGenres()){
                outFile << genre << "\n";
            }
        
            outFile << book.getNotes().size() << "\n";
            std::vector<Note> bookNotes = book.getNotes();
            for (const auto& note : bookNotes){
                outFile << note.getNoteContent() << "\n";
                outFile << note.getPageNumber() << "\n";
                outFile << note.getDateCreated() << "\n";
            }
        }
        outFile.close(); //close file
        std::cout << "App state saved successfully";
        return 0;
    } // save to file


    int Library::loadFromFile(){
        if(m_storageFileName.empty()){
            std::cerr << "Error: Storage file name not set.\n";
            return -1;
        }

        std::ifstream inFile(m_storageFileName);
        if(!inFile){
            std::cerr << "Error: Data file not found.\n";
            return -2;
        }

        m_books.clear(); //clear current library data to avoid duplication if there happens to be a double run

        std::string line;

        while(std::getline(inFile, line)){
            if(line.empty()){
                continue; // if the line is empty skip it
            }

            std::string title = line; //the first line(title) was captured in the while loop

            std::string author, language, review, isbn, coverPath, statusStr, typeStr; //variables to store string and enum info read
            std::string totalPagesStr, currentPageStr, ratingsStr; //varuiable for the number values

            // 1. Read Strings & Enums
            std::getline(inFile, author);
            std::getline(inFile, language);
            std::getline(inFile, statusStr);
            std::getline(inFile, typeStr);

            // 2. Read Numbers
            std::getline(inFile, totalPagesStr);
            std::getline(inFile, currentPageStr);
            std::getline(inFile, ratingsStr);

            // 3. Read Remaining Core Attributes (MOVED UP HERE TO MATCH SAVE ORDER)
            std::getline(inFile, review);
            std::getline(inFile, isbn);
            std::getline(inFile, coverPath);

            //Mapping back read enums
            Libmark::BookStatus status = Libmark::BookStatus::WANT_TO_READ; //default status
            if (statusStr == "reading") {status = Libmark::BookStatus::READING;}
            else if (statusStr == "completed") {status = Libmark::BookStatus::COMPLETED;}
            else if (statusStr == "gaveUp") {status = Libmark::BookStatus::GAVE_UP;}
            else if (statusStr == "onHold") {status = Libmark::BookStatus::ON_HOLD;}

            Libmark::BookType type = Libmark::BookType::PAPERBACK; //default type
            if (typeStr == "Hardcover") {type = Libmark::BookType::HARDCOVER;}
            else if (typeStr == "Ebook") {type = Libmark::BookType::EBOOK;}
            else if (typeStr == "Audiobook") {type = Libmark::BookType::AUDIOBOOK;}


            //getting book genres
            std::string genreNumberStr;
            std::getline(inFile, genreNumberStr);
            int genreCount = std::stoi(genreNumberStr);

            std::vector<std::string>  genres;
            for(int i=0; i<genreCount; ++i){
                std::string genre;
                std::getline(inFile, genre);
                genres.push_back(genre);
            }

            // casting numerical values
            int totalPages = std::stoi(totalPagesStr);
            int currentPage = std::stoi(currentPageStr);
            float ratings = std::stof(ratingsStr);


            //getting notes
            std::string noteNumberStr;
            std::getline(inFile, noteNumberStr);
            int noteCount = std::stoi(noteNumberStr);

            std::vector<Note> notes;
            for(int i=0; i < noteCount; ++i){
                std::string content, pageNumberStr, creationDate;
                std::getline(inFile, content);
                std::getline(inFile, pageNumberStr);
                std::getline(inFile, creationDate);

                int pageNumber = std::stoi(pageNumberStr);

                Note loadedNote(pageNumber, content, creationDate);
                notes.push_back(loadedNote);

                

            }

            //rebuilding the book based of the gathered info
            Book loadedBook(title, author,  totalPages, currentPage, type, status);

            //Book loadedBook(title, author, language, status, type, totalPages, currentPage, rating, review, isbn, coverPath, genres, notes);
            loadedBook.setAuthor(author);
            loadedBook.setLanguage(language);
            loadedBook.setRating(ratings);
            loadedBook.setReview(review);
            loadedBook.setIsbn(isbn);
            loadedBook.setCoverPath(coverPath);
            loadedBook.loadGenres(genres);
            loadedBook.loadNotes(notes);

            m_books.push_back(loadedBook);
        }

        inFile.close();
        std::cout << "App state loaded successfully.\n";
        return 0;
    } // load from file
}//namespace Libmark