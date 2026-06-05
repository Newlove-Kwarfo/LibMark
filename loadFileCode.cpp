#include <iostream>
#include <string>
#include <vector>

int Library::loadFromFile() {
        if (m_storageFileName.empty()) {
            std::cerr << "Error: Storage file name not set.\n";
            return -1;
        }

        std::ifstream inFile(m_storageFileName);
        if (!inFile) {
            std::cerr << "Error: Could not open data file for loading.\n";
            return -2;
        }

        // Clear out current library vector so we don't duplicate data if called twice
        m_books.clear();

        std::string line;
        
        // Loop continuously as long as we can successfully read a Book Title
        while (std::getline(inFile, line)) {
            // If the line is empty (e.g., trailing newlines at the end of the file), skip it
            if (line.empty()) continue;

            // 1. Read Core Strings
            std::string title = line; // Already grabbed by the while loop condition!
            std::string author, language, isbn, coverPath, review;
            
            std::getline(inFile, author);
            std::getline(inFile, language);

            // 2. Read Enums (Read string representation, then map back)
            std::string statusStr, typeStr;
            std::getline(inFile, statusStr);
            std::getline(inFile, typeStr);

            Libmark::BookStatus status = Libmark::BookStatus::WANT_TO_READ; // fallback default
            if (statusStr == "reading")       status = Libmark::BookStatus::READING;
            else if (statusStr == "complete")  status = Libmark::BookStatus::COMPLETED;
            else if (statusStr == "onHold")    status = Libmark::BookStatus::ON_HOLD;
            else if (statusStr == "gaveUp")    status = Libmark::BookStatus::GAVE_UP;

            Libmark::BookType type = Libmark::BookType::PAPERBACK; // fallback default
            if (typeStr == "Audiobook")      type = Libmark::BookType::AUDIOBOOK;
            else if (typeStr == "Hardcover") type = Libmark::BookType::HARDCOVER;
            else if (typeStr == "Ebook")     type = Libmark::BookType::EBOOK;

            // 3. Read Numbers (Read string, convert to type)
            std::string totalPagesStr, currentPageStr, ratingStr;
            std::getline(inFile, totalPagesStr);
            std::getline(inFile, currentPageStr);
            std::getline(inFile, ratingStr);
            std::getline(inFile, review);
            std::getline(inFile, isbn);
            std::getline(inFile, coverPath);

            int totalPages = std::stoi(totalPagesStr);
            int currentPage = std::stoi(currentPageStr);
            float rating = std::stof(ratingStr);

            // 4. Read Genres Vector
            std::string genreCountStr;
            std::getline(inFile, genreCountStr);
            int genreCount = std::stoi(genreCountStr);
            
            std::vector<std::string> genres;
            for (int i = 0; i < genreCount; ++i) {
                std::string genre;
                std::getline(inFile, genre);
                genres.push_back(genre);
            }

            // 5. Read Notes Vector
            std::string noteCountStr;
            std::getline(inFile, noteCountStr);
            int noteCount = std::stoi(noteCountStr);
            
            std::vector<Note> notes;
            for (int i = 0; i < noteCount; ++i) {
                std::string noteContent, pageNumStr, dateCreated;
                std::getline(inFile, noteContent);
                std::getline(inFile, pageNumStr);
                std::getline(inFile, dateCreated);
                
                int pageNum = std::stoi(pageNumStr);

                // Reconstruct the Note object
                // Assumes Note constructor matching: Note(content, pageNumber, date)
                Note dynamicNote(noteContent, pageNum, dateCreated); 
                notes.push_back(dynamicNote);
            }

            // 6. Reconstruct the Book object and store it
            // Adjust this constructor call to match whatever constructor parameters your Book class accepts.
            // (If you don't have an all-arguments constructor, you can use setters here instead)
            Book loadedBook(title, author, language, status, type, totalPages, currentPage, rating, review, isbn, coverPath, genres, notes);
            
            m_books.push_back(loadedBook);
        }

        inFile.close();
        std::cout << "App state loaded successfully. Rehydrated " << m_books.size() << " books.\n";
        return 0;
    }