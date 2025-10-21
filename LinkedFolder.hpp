#pragma once
#include <string>
#include <cstddef>
#include <stdexcept>
#include "File.hpp"
#include "LinkedList.hpp"
#include "VectorFolder.hpp"

class LinkedFolder
{
private:
    LinkedList<File> files_;
    /**
     * @brief Finds the index of a file with the given filename.
     * @param filename The name of the file to search for.
     *
     * @return The zero-based index of the file if found;
     * otherwise, returns the size of the internal LinkedList
     * (i.e. an index which is out of bounds of the actual LinkedList).
     */

    std::size_t indexOf(const std::string& filename) const;

public:
    /**
     * @brief Gets the total number of files currently in the folder.
     * @return The count of files as a size_t.
     */
    std::size_t getFileCount() const;

    /**
     * @brief Searches for a file by its name.
     * @param filename The name of the file to find, as a const reference to a string
     *
     * @throw std::runtime_error If the file is not found in the folder.
     * @return The file whose filename matches exactly, within the folder's files.
     */
    File findFile(const std::string& filename) const;

    /**
     * @brief Adds a new file to the folder.
     *
     * The file will not be added if a file with the same name already exists.
     *
     * @param file The File object to be added as a const reference.
     * @return True if the file was successfully added, false otherwise.
     */
    bool addFile(const File& file);

    /**
     * @brief Removes a file from the folder by its name.
     *
     * The file will not be removed if a file with the same name does NOT exist in the collection.
     *
     * @param filename The name of the file to remove, as a const. ref. to a string
     * @return True if the file was found and removed, false otherwise.
     */

    bool removeFile(const std::string& filename);

    /**
    * @brief Access the underlying files linked list.
    * @return A LinkedList<File> representing the files in the LinkedFolder.
    */
    LinkedList<File> getFiles() const;
};