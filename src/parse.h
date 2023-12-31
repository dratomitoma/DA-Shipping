//
// Created by tiago on 11/03/2023.
//
#ifndef PROJETO_DA_1_PARSE
#define PROJETO_DA_1_PARSE

#include "Graph.h"
#include <fstream>
#include <sstream>
#include "calculations.h"

using namespace std;

/**
 * Parses the information read in every line to make sure each field is correctly divided.
 * @param line Represents a line read from the csv file
 * @return vector with the information of a node.
 * @note Time-complexity -> O(n)
 */
vector<string> read(std::string filename);
/**
 * Checks if a node with a given id is already inside the vector of adjacent edges of another node
 * @param id
 * @param adj
 * @return True if the node is a destination of one of the adjacent edges, false otherwise.
 * @note Time-complexity -> O(n) with n being the size of the vector edges
 */
bool isAlreadyInEdges(int id, std::vector<Edge*> edges);
/**
 * Opens the file given, parses the nodes from the provided file, assuming it's in the Real World graphs' format and closes the file
 * @param graph
 * @param file
 * @note Time-complexity -> O(n)
 */
void readRealWorldNodes(Graph* graph, std::string filename);
/**
 * Opens the file given, parses the edges from the provided file, assuming it's in the Real World graphs' format and closes the file
 * @param graph
 * @param file
 * @note Time-complexity -> O(n)
 */
void readRealWorldEdges(Graph* graph, std::string filename);
/**
 * Opens the file given, parses the nodes and edges from the provided file, assuming it's in the Toy graphs' format, orders the nodes through their id's and closes the file
 * @param graph
 * @param file
 * @note Time-complexity -> O( n log(n) )
 */
void readToyGraph(Graph* graph, std::string filename);
/**
 * Opens the file given, parses the nodes and edges from the provided file, assuming it's in the Extra Fully Connected graphs' format, orders the nodes through their id's and closes the file
 * @param graph
 * @param file
 * @note Time-complexity -> O(n log(n))
 */
void readExtraFullyConnectedGraph(Graph* graph, std::string filename);

#endif //PROJETO_DA_1_PARSE
