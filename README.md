1. Get the project on your computer

Open a terminal and run:

git clone https://github.com/gordonlynda7-cmd/Circular.git

This downloads the whole project folder, you'll see Circular.LinkedList.h already in there, done and tested.


2.What to build 

build Server.h

A class/struct representing one server in the ring: an ID, a name, a region label, a count of requests handled, and an online/offline status
Include simple functions to increment the request count and print the server's status
No pointers or loops needed here, just a straightforward data class

build LoadBalancer.h and main.cpp (do this after Server.h is ready)

LoadBalancer.h wraps the CircularLinkedList (from Circular.LinkedList.h) holding Server objects, with functions like addServer(), removeServer(), routeRequest(), and printRingStatus()
main.cpp is the menu-driven program that lets someone interact with it (add a server, remove one, route requests, see status)

4. Pushing your work

Once you've written your file, save it in the project folder, then run:

git add .
git commit -m "Add Server class" 
git push

(swap the message for whatever you actually did)

5. Getting each other's updates

Before you start working each day, run:

git pull

so you have everyone's latest files.
