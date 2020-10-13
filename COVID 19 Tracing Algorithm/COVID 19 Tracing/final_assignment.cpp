/*
[final_assignment.cpp]
Implementation of ContactTracingGraph
Authors: Neil Fernandes, Josh Cai
Date: Aug 4, 2020
*/
#include "final_assignment.hpp"
#include <queue>
#include <iostream>

using namespace std;

ContactTracingGraph::ContactTracingGraph(){}

ContactTracingGraph::~ContactTracingGraph(){
    for(auto const& i : nodes){
        for(auto const& j: i->adjacentNodes){
            delete j;
        }
        delete i;
    }
}

bool ContactTracingGraph::addNode(string name, string id, string recentDate, bool positive){
    // Add new node to list of nodes if id is unique
    for(auto const& i : nodes){
        if (i->id == id){
            return false;
        }
    }
    nodes.push_back(new Node(name, id, recentDate, positive));
    return true;
}

bool ContactTracingGraph::addEdge(string id1, string id2, unsigned int daysSinceContact, string contactLocation){
    // If ids are not equal
    if(id1 != id2){
        // Set pointers to the two nodes of interest
        Node* n1 = NULL;
        list<Node*>::iterator it = nodes.begin();
        while(it != nodes.end() && n1 == NULL){
            if((*it)->id == id1){
                n1 = *it;
            }
            it++;
        }

        Node * n2 = NULL;
        it = nodes.begin();
        while(it != nodes.end() && n2 == NULL){
            if((*it)->id == id2){
                n2 = *it;
            }
            it++;
        }

        // Add new edges to each node of interest
        n1->adjacentNodes.push_back(new Edge(n2, daysSinceContact, contactLocation));
        n2->adjacentNodes.push_back(new Edge(n1, daysSinceContact, contactLocation));
        
        return true;
    }
    
    return false;
}

int ContactTracingGraph::count_virus_positive_contacts(string person_id){
    Node* start = NULL;

    // Set pointer to starting node
    list<Node*>::iterator it = nodes.begin();
    while(it != nodes.end() && start == NULL){
        if((*it)->id == person_id){
            start = *it;
        }
        it++;
    }
    
    // Check if the id of interest exists
    if(start != NULL){
        // Traverse graph using a helper queue, similar to BFT
        int count = 0;
        list<Node*> visited;
        queue<Node*> nodeQueue;

        // Start by pushing nodes adjacent to the starting node into the queue
        list<Edge*>::iterator it2 = (start->adjacentNodes).begin();
        while(it2 != (start->adjacentNodes).end()){
            nodeQueue.push((*it2)->adjacentNode);
            it2++;
        }
        visited.push_back(start);
        while(!nodeQueue.empty()){
            Node* curNode = nodeQueue.front();
            nodeQueue.pop();

            // For each node, check if it has been visited
            bool visit = false;
            it = visited.begin();
            while(it != visited.end() && !visit){
                if((*it)->id == curNode->id){
                    visit = true;
                }
                it++;
            }
            
            // If not, check if that node is positive and mark it as visited
            if(!visit){
                if(curNode->positive){
                    count++;
                }

                visited.push_back(curNode);

                // Push adjacent nodes into the queue
                it2 = (curNode->adjacentNodes).begin();
                while(it2 != (curNode->adjacentNodes).end()){
                    nodeQueue.push((*it2)->adjacentNode);
                    it2++;
                }
            }
        }

        return count;
    }
    
    return -1;
}

int ContactTracingGraph::find_largest_cluster_with_two_positive(){
    // Keep variables keeping track of global unvisited nodes and max cluster size
    list<Node*> unvisited;
    int maxSize = -1;
    list<Edge*>::iterator it2;
    
    // Copy all nodes into the unvisited list
    list<Node*>::iterator it = nodes.begin();
    while(it != nodes.end()){
        unvisited.push_back(*it);
        it++;
    }
    
    // Loop until all nodes have been visited
    while(!unvisited.empty()){
        // Loop through each cluster by performing BFT on the first node in the unvisited list
        int size = 0;
        int numPositive = 0;
        list<Node*> visited;
        queue<Node*> nodeQueue;
        
        nodeQueue.push(unvisited.front());
        
        while(!nodeQueue.empty()) {
            Node* curNode = nodeQueue.front();
            nodeQueue.pop();
            
            // For each node, check if it has been visited
            bool visit = false;
            it = visited.begin();
            while(it != visited.end() && !visit){
                if((*it)->id == curNode->id){
                    visit = true;
                }
                it++;
            }
            
            // If unvisited, check if it's positive and mark it as visited
            if(!visit){
                if(curNode->positive){
                    numPositive++;
                }

                visited.push_back(curNode);
                size++;
                unvisited.remove(curNode);

                it2 = (curNode->adjacentNodes).begin();
                while(it2 != (curNode->adjacentNodes).end()){
                    nodeQueue.push((*it2)->adjacentNode);
                    it2++;
                }
            }
        }
        
        // Compare size and numPositive of the current cluster to max size
        if(numPositive >= 2 && size > maxSize){
            maxSize = size;
        }
    }
    
    return maxSize;
}
