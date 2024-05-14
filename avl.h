
#ifndef TREE_VISUALIZER_AVL_H
#define TREE_VISUALIZER_AVL_H

#include "qgraphicsscene.h"
#include "qfontmetrics.h"
#include "qgraphicsitem.h"
#include "qgraphicsscene.h"

namespace trees {
const int AVL_NODE_DIAMETR = 200;
const int AVL_Y_DISTANCE = 500;

class AVL {
public:
    class Node {
    public:
        int x, y;
        int value;
        int height;

        Node *left;
        Node *right;
        Node *parent;

        void setPos(int, int);

        explicit Node(int value);
    };

    AVL();

    ~AVL();

    void insert(int value);

    void remove(int value);

    bool contains(int value);

    static void display(QGraphicsScene *scene, Node *root);

    [[nodiscard]] Node *getRoot() const;

    void click_delete(Node *cur, int x, int y);


private:
    Node *root;

    static void fixheight(Node *p);

    static int bfactor(Node *p);

    static Node *rotateLeft(Node *node);

    static Node *rotateRight(Node *node);

    static Node *balance(Node *node);

    void insert(Node *&node, Node *, int value);

    void remove(Node *&node, int value);

    bool contains(Node *node, int value);

    void deleteTree(Node *node);
}; //AVL

} //trees

#endif //TREE_VISUALIZER_AVL_H
