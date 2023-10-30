#include "Genre.h"

using namespace std;
using namespace crow;

Genre::Genre(string id, string name) 
: genreId(id), genreName(name) 
{ }

Genre::Genre(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Genre::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = genreId;
    writeJson["name"] = genreName;
    return writeJson;
}

// Update from JSON
void Genre::updateFromJson(json::rvalue readValueJson) 
{
    genreId = readValueJson["id"].s();
    genreName = readValueJson["name"].s();
}

ostream& operator<<(ostream& os, const Genre& genre) 
{
    os << "Genre ID: " << genre.genreId << ", Name: " << genre.genreName;
    return os;
}
