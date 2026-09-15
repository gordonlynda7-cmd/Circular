#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>

// Represents one server in the load-balancing ring.
// Plain data class: no pointers, no loops — just fields and
// small helper functions, as specified.
class Server
{
private:
    int serverId;
    std::string serverName;
    std::string region;
    int requestsHandled;
    bool isOnline;

public:
    // Creates a new server. Servers start online with zero requests handled.
    Server(int id, const std::string &name, const std::string &regionLabel)
        : serverId(id), serverName(name), region(regionLabel),
          requestsHandled(0), isOnline(true) {}

    // Default constructor so Server can be used as a placeholder value
    // (e.g. when searching the ring for a server to remove).
    Server() : serverId(0), serverName(""), region(""),
               requestsHandled(0), isOnline(true) {}

    // ---- Getters ----
    int getId() const { return serverId; }
    std::string getName() const { return serverName; }
    std::string getRegion() const { return region; }
    int getRequestsHandled() const { return requestsHandled; }
    bool getIsOnline() const { return isOnline; }

    // Called every time this server is chosen to handle a request.
    void incrementRequestCount()
    {
        requestsHandled++;
    }

    // Toggles the server between online and offline.
    void setOnline(bool online)
    {
        isOnline = online;
    }

    // Prints a one-line status summary for this server.
    void printStatus() const
    {
        std::cout << "  [" << (isOnline ? "ONLINE " : "OFFLINE") << "] "
                  << serverName << " (id " << serverId << ", region " << region
                  << ") - " << requestsHandled << " requests handled\n";
    }

    // Needed so the ring can find/remove a server by comparing values.
    // Two servers are considered "equal" if they have the same id.
    bool operator==(const Server &other) const
    {
        return serverId == other.serverId;
    }
};

#endif