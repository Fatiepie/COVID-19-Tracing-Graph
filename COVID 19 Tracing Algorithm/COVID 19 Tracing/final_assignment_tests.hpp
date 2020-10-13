/*
[final_assignment_tests.cpp]
Test drivers for ContactTracingGraph
Authors: Neil Fernandes, Josh Cai
Date: Aug 4, 2020
*/


#ifndef final_assignment_tests_hpp
#define final_assignment_tests_hpp

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include <stdio.h>
#include "final_assignment.hpp"

class ContactTracingGraphTest{
    
public:
    // Node and edge insertions
    bool test1(){
        ContactTracingGraph graph;
        
        ASSERT_TRUE(graph.addNode("Darryl", "0", "", true));
        ASSERT_TRUE(graph.addNode("Maria", "1", "", true));
        ASSERT_TRUE(graph.addNode("Mike", "2", "", true));
        ASSERT_TRUE(graph.addNode("Andy", "3", "", false));
        ASSERT_TRUE(graph.addNode("Kelsey", "4", "", false));

        ASSERT_TRUE(graph.addEdge("0", "1", 2, ""));
        ASSERT_TRUE(graph.addEdge("1", "2", 6, ""));
        ASSERT_TRUE(graph.addEdge("2", "3", 3, ""));
        ASSERT_TRUE(graph.addEdge("3", "4", 1, ""))
        ASSERT_TRUE(graph.addEdge("0", "3", 9, ""));
        ASSERT_TRUE(graph.addEdge("4", "1", 2, ""));
        
        ASSERT_TRUE(graph.addNode("Nate", "5", "", true));
        ASSERT_TRUE(graph.addNode("Olivia", "6", "", true));
        ASSERT_TRUE(graph.addNode("Jess", "7", "", false));
        ASSERT_TRUE(graph.addNode("Shell", "8", "", false));
        ASSERT_FALSE(graph.addNode("Bill", "8", "", false));

        ASSERT_TRUE(graph.addEdge("5", "6", 0, ""));
        ASSERT_TRUE(graph.addEdge("5", "7", 0, ""));
        ASSERT_TRUE(graph.addEdge("6", "7", 0, ""));
        ASSERT_TRUE(graph.addEdge("6", "8", 0, ""));
        ASSERT_FALSE(graph.addEdge("8", "8", 0, ""));
        
        return true;
    }
    
    //Count contacts with empty list, no positives, and a start on a positive
    bool test2(){
        ContactTracingGraph graph;
        
        ASSERT_TRUE(graph.addNode("Darryl", "0", "", true));
        ASSERT_TRUE(graph.addNode("Maria", "1", "", true));
        ASSERT_TRUE(graph.addNode("Mike", "2", "", true));
        ASSERT_TRUE(graph.addNode("Andy", "3", "", false));
        ASSERT_TRUE(graph.addNode("Kelsey", "4", "", false));

        ASSERT_TRUE(graph.addEdge("0", "1", 2, ""));
        ASSERT_TRUE(graph.addEdge("1", "2", 6, ""));
        ASSERT_TRUE(graph.addEdge("2", "3", 3, ""));
        ASSERT_TRUE(graph.addEdge("3", "4", 1, ""))
        ASSERT_TRUE(graph.addEdge("0", "3", 9, ""));
        ASSERT_TRUE(graph.addEdge("4", "1", 2, ""));
        
        ASSERT_TRUE(graph.addNode("Nate", "5", "", true));
        ASSERT_TRUE(graph.addNode("Olivia", "6", "", true));
        ASSERT_TRUE(graph.addNode("Jess", "7", "", false));
        ASSERT_TRUE(graph.addNode("Shell", "8", "", false));

        ASSERT_TRUE(graph.addEdge("5", "6", 0, ""));
        ASSERT_TRUE(graph.addEdge("5", "7", 0, ""));
        ASSERT_TRUE(graph.addEdge("6", "7", 0, ""));
        ASSERT_TRUE(graph.addEdge("6", "8", 0, ""));
        ASSERT_TRUE(graph.addEdge("7", "8", 0, ""));
        
        ASSERT_TRUE(graph.count_virus_positive_contacts("3") == 3);
        ASSERT_TRUE(graph.count_virus_positive_contacts("5") == 1);
        
        ContactTracingGraph graph2;
        ASSERT_TRUE(graph2.count_virus_positive_contacts("3") == -1);
        
        ASSERT_TRUE(graph2.addNode("Nate", "5", "", false));
        ASSERT_TRUE(graph2.addNode("Olivia", "6", "", false));
        ASSERT_TRUE(graph2.addNode("Jess", "7", "", false));
        ASSERT_TRUE(graph2.addNode("Shell", "8", "", false));

        ASSERT_TRUE(graph2.addEdge("5", "6", 0, ""));
        ASSERT_TRUE(graph2.addEdge("5", "7", 0, ""));
        ASSERT_TRUE(graph2.addEdge("6", "7", 0, ""));
        ASSERT_TRUE(graph2.addEdge("6", "8", 0, ""));
        ASSERT_TRUE(graph2.addEdge("7", "8", 0, ""));
        
        ASSERT_TRUE(graph2.count_virus_positive_contacts("6") == 0);
        
        return true;
    }
    
    //Largest cluster with multiple valid clusters, empty list, no valid cluster, and 1 valid cluster
    bool test3(){
        ContactTracingGraph graph;
        
        ASSERT_TRUE(graph.addNode("Darryl", "0", "", true));
        ASSERT_TRUE(graph.addNode("Maria", "1", "", true));
        ASSERT_TRUE(graph.addNode("Mike", "2", "", true));
        ASSERT_TRUE(graph.addNode("Andy", "3", "", false));
        ASSERT_TRUE(graph.addNode("Kelsey", "4", "", false));

        ASSERT_TRUE(graph.addEdge("0", "1", 2, ""));
        ASSERT_TRUE(graph.addEdge("1", "2", 6, ""));
        ASSERT_TRUE(graph.addEdge("2", "3", 3, ""));
        ASSERT_TRUE(graph.addEdge("3", "4", 1, ""))
        ASSERT_TRUE(graph.addEdge("0", "3", 9, ""));
        ASSERT_TRUE(graph.addEdge("4", "1", 2, ""));
        
        ASSERT_TRUE(graph.addNode("Nate", "5", "", true));
        ASSERT_TRUE(graph.addNode("Olivia", "6", "", true));
        ASSERT_TRUE(graph.addNode("Jess", "7", "", false));
        ASSERT_TRUE(graph.addNode("Shell", "8", "", false));

        ASSERT_TRUE(graph.addEdge("5", "6", 0, ""));
        ASSERT_TRUE(graph.addEdge("5", "7", 0, ""));
        ASSERT_TRUE(graph.addEdge("6", "7", 0, ""));
        ASSERT_TRUE(graph.addEdge("6", "8", 0, ""));
        ASSERT_TRUE(graph.addEdge("7", "8", 0, ""));
        
        ASSERT_TRUE(graph.find_largest_cluster_with_two_positive() == 5);
        
        ContactTracingGraph graph2;
        ASSERT_TRUE(graph2.find_largest_cluster_with_two_positive() == -1);
        
        ASSERT_TRUE(graph2.addNode("Darryl", "0", "", false));
        ASSERT_TRUE(graph2.addNode("Maria", "1", "", false));
        ASSERT_TRUE(graph2.addNode("Mike", "2", "", false));
        ASSERT_TRUE(graph2.addNode("Andy", "3", "", false));
        ASSERT_TRUE(graph2.addNode("Kelsey", "4", "", false));

        ASSERT_TRUE(graph2.addEdge("0", "1", 2, ""));
        ASSERT_TRUE(graph2.addEdge("1", "2", 6, ""));
        ASSERT_TRUE(graph2.addEdge("2", "3", 3, ""));
        ASSERT_TRUE(graph2.addEdge("3", "4", 1, ""))
        ASSERT_TRUE(graph2.addEdge("0", "3", 9, ""));
        ASSERT_TRUE(graph2.addEdge("4", "1", 2, ""));
        
        ASSERT_TRUE(graph2.find_largest_cluster_with_two_positive() == -1);
        
        ASSERT_TRUE(graph2.addNode("Nate", "5", "", true));
        ASSERT_TRUE(graph2.addNode("Olivia", "6", "", true));
        ASSERT_TRUE(graph2.addNode("Jess", "7", "", false));
        ASSERT_TRUE(graph2.addNode("Shell", "8", "", false));

        ASSERT_TRUE(graph2.addEdge("5", "6", 0, ""));
        ASSERT_TRUE(graph2.addEdge("5", "7", 0, ""));
        ASSERT_TRUE(graph2.addEdge("6", "7", 0, ""));
        ASSERT_TRUE(graph2.addEdge("6", "8", 0, ""));
        ASSERT_TRUE(graph2.addEdge("7", "8", 0, ""));
        
        ASSERT_TRUE(graph2.find_largest_cluster_with_two_positive() == 4);
        
        return true;
    }
};

#endif /* final_assignment_tests_hpp */
