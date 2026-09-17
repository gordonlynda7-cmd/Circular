#include <iostream>
#include <string>

#include "Loadbalancer.h"
#include "Server.h"

int main(){
    LoadBalancer loadBalancer;

    int choice = 0;

    while(choice != 5){
        std::cout << "\n===== SERVER LOAD BALANCER =====\n";
        std::cout << "1. Add Server\n";
        std::cout << "2. Remove Server\n";
        std::cout << "3. Route Request\n";
        std::cout << "4. Print Ring Status\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        if(choice == 1){
            int serverId;
            std::string serverName;
            std::string region;

            std::cout << "Enter server ID: ";
            std::cin >> serverId;

            std::cout << "Enter server name: ";
            std::cin.ignore();
            std::getline(std::cin, serverName);

            std::cout << "Enter server region: ";
            std::getline(std::cin, region);

            Server newServer(serverId, serverName, region);

            loadBalancer.addServer(newServer);

            std::cout << "Server added successfully.\n";
        }
        else if(choice == 2){
            int serverId;

            std::cout << "Enter the ID of the server to remove: ";
            std::cin >> serverId;

            loadBalancer.removeServer(serverId);
        }
        else if(choice == 3){
            loadBalancer.routeRequest();
        }
        else if(choice == 4){
            loadBalancer.printRingStatus();
        }
        else if(choice == 5){
            std::cout << "Exiting program.\n";
        }
        else{
            std::cout << "Invalid choice. Please eneter a number from 1 to 5.\n";
        }
    }

    return 0;
}