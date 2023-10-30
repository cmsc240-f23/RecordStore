#include <crow.h>
#include <map>
#include <csignal>
#include <string>
#include "Artist.h"
#include "GenericAPI.h"
#include "Genre.h"
#include "persistence.h"

using namespace std;
using namespace crow;

int main() 
{
    // Load resources from files.
    GenericAPI<Genre>::resourceMap = loadFromFile<Genre>("genres.json");
    GenericAPI<Artist>::resourceMap = loadFromFile<Artist>("artists.json");

    // Setup the simple web service.
    SimpleApp app;

    // Define resources:

    // Genres
    CROW_ROUTE(app, "/api/genres").methods("POST"_method)(GenericAPI<Genre>::createResource);
    CROW_ROUTE(app, "/api/genres").methods("GET"_method)(GenericAPI<Genre>::readAllResources);
    CROW_ROUTE(app, "/api/genres/<string>").methods("GET"_method)(GenericAPI<Genre>::readResource);
    CROW_ROUTE(app, "/api/genres/<string>").methods("PUT"_method)(GenericAPI<Genre>::updateResource);
    CROW_ROUTE(app, "/api/genres/<string>").methods("DELETE"_method)(GenericAPI<Genre>::deleteResource);

    // Artist
    CROW_ROUTE(app, "/api/artists").methods("POST"_method)(GenericAPI<Artist>::createResource);
    CROW_ROUTE(app, "/api/artists").methods("GET"_method)(GenericAPI<Artist>::readAllResources);
    CROW_ROUTE(app, "/api/artists/<string>").methods("GET"_method)(GenericAPI<Artist>::readResource);
    CROW_ROUTE(app, "/api/artists/<string>").methods("PUT"_method)(GenericAPI<Artist>::updateResource);
    CROW_ROUTE(app, "/api/artists/<string>").methods("DELETE"_method)(GenericAPI<Artist>::deleteResource);


    // Run the web service app.
    app.port(18080).run();
        
    // After the web service stops running:

    // Perform persistence of resources
    saveToFile<Genre>(GenericAPI<Genre>::resourceMap, "genres.json");
    saveToFile<Artist>(GenericAPI<Artist>::resourceMap, "artists.json");
}
