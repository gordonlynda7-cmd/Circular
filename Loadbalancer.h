#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

#include <iostream>
#include "Circular.LinkedList.h"
#include "Server.h"

// Wraps a CircularLinkedList<Server> and gives it load-balancer-specific
// behavior: adding/removing servers, and routing requests to them in
// round-robin order.
class LoadBalancer
{
private:
    CircularLinkedList<Server> serverRing;
    int nextServerId; // auto-increments so every server gets a unique id

public:
    LoadBalancer() : nextServerId(1) {}

    // Adds a new server to the pool with the given name and region.
    void addServer(const std::string &name, const std::string &region)
    {
        Server newServer(nextServerId, name, region);
        serverRing.addToRing(newServer);
        std::cout << "Added server \"" << name << "\" (id " << nextServerId
                  << ", region " << region << ")\n";
        nextServerId++;
    }

    // Removes the server with the given id from the pool.
    void removeServer(int serverId)
    {
        Server searchTarget;
        // Build a throwaway Server with just the id set, since
        // Server::operator== only compares by id.
        searchTarget = Server(serverId, "", "");

        if (serverRing.removeFromRing(searchTarget))
        {
            std::cout << "Removed server id " << serverId << "\n";
        }
        else
        {
            std::cout << "No server with id " << serverId << " found\n";
        }
    }

    // Routes one incoming request to the next server in the rotation.
    void routeRequest()
    {
        if (serverRing.isEmpty())
        {
            std::cout << "No servers available — cannot route request\n";
            return;
        }
        Server &chosenServer = serverRing.getNextInRotation();
        chosenServer.incrementRequestCount();
        std::cout << "Routed request to \"" << chosenServer.getName()
                  << "\" (id " << chosenServer.getId() << ")\n";
    }

    // Prints the status of every server currently in the ring.
    void printRingStatus() const
    {
        if (serverRing.isEmpty())
        {
            std::cout << "The server ring is empty.\n";
            return;
        }
        std::cout << "\n--- Server ring status ---\n";
        serverRing.forEachOnce([](const Server &s)
                                { s.printStatus(); });
        std::cout << "--------------------------\n";
    }
};

#endif