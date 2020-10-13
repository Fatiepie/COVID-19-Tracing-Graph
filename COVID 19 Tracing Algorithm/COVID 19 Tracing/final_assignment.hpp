/*
[final_assignment.hpp]
Definition of ContactTracingGraph
Authors: Neil Fernandes, Josh Cai 
Date: Aug 4, 2020
*/


#ifndef final_assignment_hpp
#define final_assignment_hpp

#include <string>
#include <list>

using namespace std;

class ContactTracingGraph {
protected:
    struct Edge;
    struct Node;
    
    struct Node{
        string name, id, recentDate;
        bool positive;
        list<Edge*> adjacentNodes; // List of pointers to edges of this node (adjacent nodes)
        
        Node(string newName, string newID, string newDate, bool newPositive):
            name(newName), id(newID), recentDate(newDate), positive(newPositive) {}
    };
    
    struct Edge{
        Node* adjacentNode; // The node adjacent to this edge's parent node
        unsigned int daysSinceContact;
        string contactLocation;
        
        Edge(Node* newNode, unsigned int newDays, string newLoc):
            adjacentNode(newNode), daysSinceContact(newDays), contactLocation(newLoc) {}
    };
    
    friend class ContactTracingGraphTest;
    
    // List of pointers to each node
    list<Node*> nodes;
    
public:
    ContactTracingGraph();
    
    ~ContactTracingGraph();
    
    // Add a node to the graph
    // Fails and returns false if id is non-unique
    // Returns true and succeeds otherwise
    bool addNode(string name, string id, string recentDate, bool positive);
    
    // Add an edge between two nodes
    // Return false if ids are the same
    bool addEdge(string id1, string id2, unsigned int daysSinceContact, string contactLocation);
    
    int count_virus_positive_contacts(string person_id);
    
    int find_largest_cluster_with_two_positive();
};

#endif /* final_assignment_hpp */
