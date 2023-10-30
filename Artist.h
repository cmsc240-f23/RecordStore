#ifndef ARTIST_H
#define ARTIST_H

#include <string>
#include <crow.h>

class Artist
{
public:
    // Constructors
    Artist() {}
    Artist(std::string id, std::string name);
    Artist(crow::json::rvalue readValueJson);

    // Getters
    std::string getId() const { return artistId; }
    std::string getName() const { return artistName; }

    // Setters
    void setId(std::string id) { artistId = id; }
    void setName(std::string name) { artistName = name; }

    // Convert to JSON.
    crow::json::wvalue convertToJson();

    // Update from JSON.
    void updateFromJson(crow::json::rvalue readValueJson);

    // Override the << operator.
    friend std::ostream& operator<<(std::ostream& os, const Artist& artist);

private:
    std::string artistId;
    std::string artistName;
};

#endif // ARTIST_H
