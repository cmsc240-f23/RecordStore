#include "Artist.h"

using namespace std;
using namespace crow;

Artist::Artist(string id, string name) 
: artistId(id), artistName(name) 
{ }

Artist::Artist(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Artist::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = artistId;
    writeJson["name"] = artistName;
    return writeJson;
}

// Update from JSON
void Artist::updateFromJson(json::rvalue readValueJson) 
{
    artistId = readValueJson["id"].s();
    artistName = readValueJson["name"].s();
}

ostream& operator<<(ostream& os, const Artist& artist) 
{
    os << "Artist ID: " << artist.artistId << ", Name: " << artist.artistName;
    return os;
}
