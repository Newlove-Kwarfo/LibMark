// This is main.cpp
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Note.h"
#include "Library.h" // <-- Include your new Library header file

int main() {
    std::cout << " === LIBMARK SYSTEM ENGINE BOOT === \n\n";

    // ----------------------------------------------------
    // STEP 1: POPULATE AND SAVE THE DATA
    // ----------------------------------------------------
    std::cout << "--- Phase 1: Creating Book Data and Saving ---\n";
    
    // Instantiating a book using constructor2
    Libmark::Book myBook("Aurum", "Evolwen Kay", 200, Libmark::BookType::PAPERBACK, Libmark::BookStatus::READING);

    // Creating some reading notes
    Libmark::Note note1(10, "What in the hell is going on? How you finna start a book like thatttt!", "17/05/2026");
    Libmark::Note note2("It seems the book is a mstery justice type", "17/05/2026");

    myBook.addNote(note1);
    myBook.addNote(note2);
    myBook.setType(Libmark::BookType::HARDCOVER);
    myBook.updateStatus(Libmark::BookStatus::ON_HOLD);
    myBook.setCurrentPage(109);
    myBook.addGenre("Crime");
    myBook.addGenre("Mystery");

    // Instantiating the library and setting its storage filename
    Libmark::Library savingLibrary;
    
    // Assuming m_storageFileName has a setter function like setStorageFileName() in your Library.h.
    // If it's a public variable instead, use: savingLibrary.m_storageFileName = "library_data.txt";
    savingLibrary.setStorageFileName("library_data.txt"); 

    // Add the book to the library configuration
    savingLibrary.addBook(myBook);

    // Run the file-saving function
    savingLibrary.saveToFile();
    std::cout << "Data successfully serialized to disk.\n\n";

    // ----------------------------------------------------
    // STEP 2: SIMULATE APPLICATION RESET (RELOADING)
    // ----------------------------------------------------
    std::cout << "--- Phase 2: Simulating App Restart & Loading Data ---\n";
    
    // Create a completely fresh, separate, empty library object
    Libmark::Library loadingLibrary;
    loadingLibrary.setStorageFileName("library_data.txt");

    // Execute the file loading loop
    loadingLibrary.loadFromFile();

    // ----------------------------------------------------
    // STEP 3: SEARCH AND VERIFY THE REHYDRATED DATA
    // ----------------------------------------------------
    std::cout << "\n--- Phase 3: Verifying Loaded Data Integrity ---\n";
    
    // Search the fresh library for our book
    std::vector<Libmark::Book> foundBooks = loadingLibrary.searchByTitle("Aurum");

    if (foundBooks.empty()) {
        std::cerr << "CRITICAL ERROR: Book could not be found after reloading file!\n";
        return -1;
    }

    // Grab the first matching book that came out of the text file
    Libmark::Book loadedBook = foundBooks[0];

    // Outputting book properties to make sure everything stayed accurate
    std::cout << " REHYDRATED BOOK DETAILS \n";
    std::cout << " Title:       " << loadedBook.getTitle() << " \n";
    std::cout << " Author:      " << loadedBook.getAuthor() << " \n";
    std::cout << " Total Pages: " << loadedBook.getTotalPages() << " \n";
    std::cout << " Current Page: " << loadedBook.getCurrentPage() << " \n";
    
    std::cout << " Status:      ";
    switch (loadedBook.getStatus()) {
        case Libmark::BookStatus::WANT_TO_READ: std::cout << "Want to read\n"; break;
        case Libmark::BookStatus::READING:      std::cout << "Reading\n"; break;
        case Libmark::BookStatus::COMPLETED:    std::cout << "Completed\n"; break;
        case Libmark::BookStatus::ON_HOLD:      std::cout << "On hold\n"; break;
        case Libmark::BookStatus::GAVE_UP:      std::cout << "Gave up\n"; break;
    }
    
    std::cout << " Type:        ";
    switch (loadedBook.getType()) {
        case Libmark::BookType::AUDIOBOOK: std::cout << "Audiobook\n"; break;
        case Libmark::BookType::PAPERBACK: std::cout << "Paperback\n"; break;
        case Libmark::BookType::HARDCOVER: std::cout << "Hardcover\n"; break;
        case Libmark::BookType::EBOOK:     std::cout << "Ebook\n"; break;
    }

    std::cout << " Genres:      ";
    const std::vector<std::string>& loadedGenres = loadedBook.getGenres();
    for (size_t i = 0; i < loadedGenres.size(); ++i) {
        std::cout << loadedGenres[i] << ", ";
    }

    std::cout << "\n\n Loaded Book Notes: \n";
    const std::vector<Libmark::Note>& loadedNotes = loadedBook.getNotes();

    for (size_t i = 0; i < loadedNotes.size(); ++i) {
        std::cout << " Note #" << i + 1 << "\n";

        if (loadedNotes[i].getPageNumber() == -1) {
            std::cout << " (Global Note)";
        } else {
            std::cout << " Page " << loadedNotes[i].getPageNumber();      
        }

        std::cout << " created on " << loadedNotes[i].getDateCreated() << "\n";
        std::cout << "\"" << loadedNotes[i].getNoteContent() << "\"\n\n";  
    }

    std::cout << " Press Enter to exit...";
    std::cin.get();

    return 0;
}

// You must include Library.cpp in your g++ build command now!
// g++ -std=c++17 main.cpp Book.cpp Note.cpp Library.cpp -o libmarkTest.exe
//
// Run command:
// Powershell: "./libmarkTest.exe"  |  GitBash: "winpty ./libmarkTest.exe"