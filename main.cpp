#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Note.h"

int main(){
    std::cout << " LIBMARK SYSTEM ENGINE BOOT \n";

    //instantiating a book using constructor2
    Libmark::Book myBook("Aurum", "Evolwen Kay",200);

    //creating some reading notes
    //note1 - note with page
    Libmark::Note note1(10, "What in the hell is going on? How you finna start a book like thatttt!", "17/05/2026");
    //note2 - note without page
    Libmark::Note note2("It seems the book is a mstery justice type", "17/05/2026");

    myBook.addNote(note1);
    myBook.addNote(note2);
    myBook.setType(Libmark::BookType::HARDCOVER);
    myBook.updateStatus(Libmark::BookStatus::READING);
    myBook.setCurrentPage(109);
    myBook.addGenre("Crime");
    myBook.addGenre("Mystery");

    //outputting book properties
    std::cout << " BOOK DETAILS \n";
    std::cout << " Title:       " << myBook.getTitle() << " \n";
    std::cout << " Author:      " << myBook.getAuthor() << " \n";
    std::cout << " Total Pages: " << myBook.getTotalPages() << " \n";
    std::cout << " Current Page:" << myBook.getCurrentPage() << " \n";
    
    std::cout << "\n Status:      ";
    switch (myBook.getStatus()){
        case Libmark::BookStatus::WANT_TO_READ:
            std::cout << "Want to read";
            break;
        case Libmark::BookStatus::READING:
            std::cout << "Reading";
            break;
        case Libmark::BookStatus::COMPLETED:
            std::cout << "Completed";
            break;
        case Libmark::BookStatus::ON_HOLD:
            std::cout << "On hold";
            break;
        case Libmark::BookStatus::GAVE_UP:
            std::cout << "Gave up";
            break;
    }
    
    std::cout << "\n Type:        ";
    switch (myBook.getType()){
        case Libmark::BookType::AUDIOBOOK:
            std::cout << "Audiobook";
            break;
        case Libmark::BookType::PAPERBACK:
            std::cout << "Paperback";
            break;
        case Libmark::BookType::HARDCOVER:
            std::cout << "Hardcover";
            break;
        case Libmark::BookType::EBOOK:
            std::cout << "Ebook";
            break;
    }

    std::cout << "\n Genres:      ";
    const std::vector<std::string>& bookGenres = myBook.getGenres();
    for (size_t i=0; i<bookGenres.size(); ++i){
        std::cout << bookGenres[i] << ", ";
    }

    std::cout << "\n\n Book Notes: \n";

    //createing a constant reference variable for notes getter
    const std::vector<Libmark::Note>& bookNotes = myBook.getNotes();

    //loop through and print each note's data
    for (size_t i = 0; i < bookNotes.size(); ++i){
        std::cout << " Note #" << i+1 << "\n";

        if (bookNotes[i].getPageNumber() == -1){
            std::cout << " (Global Note)";
        } else {
            std::cout << " Page " << bookNotes[i].getPageNumber();      
        }

        std::cout << " created on " << bookNotes[i].getDateCreated() << "\n";
        std::cout << "\"" << bookNotes[i].getNoteContent() << "\"\n\n";  
    }

    std::cout << "\n\n Press Enter to exit...";
    std::cin.get();

    return 0;
} // int main

//run this in terminal to compile .exe file
//g++ -std=c++17 main.cpp Book.cpp Note.cpp -o libmarkTest.exe