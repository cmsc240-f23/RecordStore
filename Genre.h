#ifndef GENRE_H
#define GENRE_H

#include <string>
#include <crow.h>

class Genre 
{
public:
    // Constructors
    Genre() {}
    Genre(std::string id, std::string name);
    Genre(crow::json::rvalue readValueJson);

    // Getters
    std::string getId() const { return genreId; }
    std::string getName() const { return genreName; }

    // Setters
    void setId(std::string id) { genreId = id; }
    void setName(std::string name) { genreName = name; }

    // Convert to JSON.
    crow::json::wvalue convertToJson();

    // Update from JSON.
    void updateFromJson(crow::json::rvalue readValueJson);

    // Override the << operator.
    friend std::ostream& operator<<(std::ostream& os, const Genre& genre);

private:
    std::string genreId;
    std::string genreName;
};

#endif // GENRE_H
