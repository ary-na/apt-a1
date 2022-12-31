#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "../include/Types.h"
#include "../include/Node.h"
#include "../include/NodeList.h"
#include "../include/PathSolver.h"
#include "../include/milestone4.h"

// Helper test functions
void testNode();

void testNodeList();

// Read an environment from standard input.
void readEnvStdin(Env env);

// Print out an Environment to standard output with path.
// To be implemented for Milestone 3
void printEnvStdout(Env env, NodeList *solution);


int main(int argc, char **argv) {
    // THESE ARE SOME EXAMPLE FUNCTIONS TO HELP TEST YOUR CODE
    // AS YOU WORK ON MILESTONE 2. YOU CAN UPDATE THEM YOURSELF
    // AS YOU GO ALONG.
    // COMMENT THESE OUT BEFORE YOU SUBMIT!!!

    //    std::cout << "TESTING - COMMENT THE OUT TESTING BEFORE YOU SUBMIT!!!" << std::endl;
    //    testNode();
    //    testNodeList();
    //    std::cout << "DONE TESTING" << std::endl << std::endl;

    // Load Environment
    Env env = make_env(ROWS, COLS);
    readEnvStdin(env);

    // Solve using forwardSearch
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    auto *pathSolver = new PathSolver();

    // Set start and goal location Nodes
    // To test a different env modify ROWS and COLS in Types.h file
    pathSolver->getStartNode()->setRow(57);
    pathSolver->getStartNode()->setCol(54);
    pathSolver->getGoalNode()->setRow(1);
    pathSolver->getGoalNode()->setCol(3);

    pathSolver->forwardSearch(env);

    NodeList *exploredPositions = nullptr;
    exploredPositions = pathSolver->getNodesExplored();

    // Get the path
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    NodeList *solution = pathSolver->getPath(env);

    printEnvStdout(env, solution);

    delete pathSolver;
    delete exploredPositions;
    delete solution;
    delete_env(env, ROWS, COLS);

}

void readEnvStdin(Env env) {
    // Read env line by line
    for (int i = 0; i < ROWS; i++)
        std::cin.getline(env[i], COLS + 1);
}

void printEnvStdout(Env env, NodeList *solution) {

    // Update env file with navigation path
    for (int i = 0; i < solution->getLength() - 2; i++) {
        Node *p = solution->getNode(i);
        Node *c = solution->getNode(i + 1);

        if (p->getRow() + 1 == c->getRow() && p->getCol() == c->getCol()) {
            env[c->getRow()][c->getCol()] = SYMBOL_MOVE_UP;
        } else if (p->getRow() - 1 == c->getRow() && p->getCol() == c->getCol()) {
            env[c->getRow()][c->getCol()] = SYMBOL_MOVE_DOWN;
        } else if (p->getRow() == c->getRow() && p->getCol() + 1 == c->getCol()) {
            env[c->getRow()][c->getCol()] = SYMBOL_MOVE_LEFT;
        } else if (p->getRow() == c->getRow() && p->getCol() - 1 == c->getCol()) {
            env[c->getRow()][c->getCol()] = SYMBOL_MOVE_RIGHT;
        }
    }

    // Print env file
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            std::cout << env[i][j];
        std::cout << std::endl;
    }
}

void testNode() {
    std::cout << "TESTING Node" << std::endl;

    // Make a Node and print out the contents
    Node *node = new Node(1, 1, 2);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;

    // Change Node and print again
    node = new Node(4, 2, 3);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;
}

void testNodeList() {
    std::cout << "TESTING NodeList" << std::endl;

    // Make a simple NodeList, should be empty size
    auto *nodeList = new NodeList();
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add a Node to the NodeList, print size
    Node *b1 = new Node(1, 1, 1);
    nodeList->addElement(b1);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add second Nodetest
    Node *b2 = new Node(0, 0, 1);
    nodeList->addElement(b2);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Test Get-ith - should be 0,0,1
    Node *getB = nodeList->getNode(1);
    std::cout << getB->getRow() << ",";
    std::cout << getB->getCol() << ",";
    std::cout << getB->getDistanceTraveled() << std::endl;

    // Print out the NodeList
    std::cout << "PRINTING OUT A NODELIST IS AN EXERCISE FOR YOU TO DO" << std::endl;
}