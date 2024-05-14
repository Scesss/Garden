
#include "avl.h"

namespace trees {

AVL::Node::Node(int value) : value(value),
    height(1),
    x(0), y(0),
    left(nullptr),
    right(nullptr),
    parent(nullptr) {}


AVL::AVL() : root(nullptr) {}

AVL::~AVL() {
    deleteTree(root);
}

int getHeight(AVL::Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalance(AVL::Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void AVL::fixheight(Node *p) {
    unsigned char hl = getHeight(p->left);
    unsigned char hr = getHeight(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

void AVL::deleteTree(Node *node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void AVL::insert(int value) {
    insert(root, nullptr, value);
}

void AVL::insert(Node *&node, Node *prev, int value) {
    if (node == nullptr) {
        node = new Node(value);
        node->parent = prev;
    } else if (value < node->value) {
        insert(node->left, node, value);
    } else if (value > node->value) {
        insert(node->right, node, value);
    }
    node = balance(node);
}

void AVL::remove(int value) {
    remove(root, value);
}

void AVL::remove(Node *&node, int value) {
    if (node == nullptr) {
        return;
    }
    if (value < node->value) {
        remove(node->left, value);
    } else if (value > node->value) {
        remove(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            Node *temp = node;
            node = node->right;
            node->parent = temp->parent;
            delete temp;
        } else if (node->right == nullptr) {
            Node *temp = node;
            node = node->left;
            node->parent = temp->parent;
            delete temp;
        } else {
            Node *temp = node->left;
            while (temp->right != nullptr) {
                temp = temp->right;
            }
            node->value = temp->value;
            remove(node->left, temp->value);
        }
    }
    node = balance(node);
}

bool AVL::contains(int value) {
    return contains(root, value);
}

bool AVL::contains(Node *node, int value) {
    if (node == nullptr) {
        return false;
    } else if (value < node->value) {
        return contains(node->left, value);
    } else if (value > node->value) {
        return contains(node->right, value);
    } else {
        return true;
    }
}

AVL::Node *AVL::rotateLeft(Node *q) {
    Node *p = q->right;
    p->parent = q->parent;
    q->parent = p;

    q->right = p->left;
    p->left = q;
    if (q->right != nullptr)
        q->right->parent = q;

    fixheight(q);
    fixheight(p);
    return p;
}


AVL::Node *AVL::rotateRight(Node *p) {

    Node *q = p->left;
    q->parent = p->parent;
    p->parent = q;

    p->left = q->right;
    q->right = p;
    if (p->left != nullptr)
        p->left->parent = p;

    fixheight(p);
    fixheight(q);
    return q;
}

int AVL::bfactor(Node *p) {
    return getHeight(p->right) - getHeight(p->left);
}


AVL::Node *AVL::balance(Node *p) {
    if (!p) return nullptr;
    fixheight(p);
    if (bfactor(p) == 2) {
        if (bfactor(p->right) < 0) {
            p->right = rotateRight(p->right);
        }

        return rotateLeft(p);
    }
    if (bfactor(p) == -2) {
        if (bfactor(p->left) > 0) {
            p->left = rotateLeft(p->left);
        }
        return rotateRight(p);
    }
    return p;
}

void AVL::Node::setPos(int _x, int _y) {
    x = _x;
    y = _y;
}


void treeFilling(AVL::Node *&x, int dl) {
    if (x == nullptr) return;

    if (x->left) x->left->x -= dl;
    if (x->right) x->right->x -= dl;

    treeFilling(x->left, dl);
    treeFilling(x->right, dl);

}

int max_right(AVL::Node *x, int mx) {
    if (x == nullptr) return mx;
    mx = std::max(x->x + trees::AVL_NODE_DIAMETR, max_right(x->right, mx));
    mx = std::max(x->x + trees::AVL_NODE_DIAMETR, max_right(x->left, mx));
    return mx;
}

int max_left(AVL::Node *x, int mx) {
    if (x == nullptr) return mx;
    mx = std::min(x->x, max_left(x->right, mx));
    mx = std::min(x->x, max_left(x->left, mx));
    return mx;
}

void Stand(AVL::Node *&x) {
    if (x == nullptr) return;

    Stand(x->left);
    Stand(x->right);
    int mr = max_right(x->left, -1e6), ml = max_left(x->right, 1e6);

    int delta = (mr == -1e6 || ml == 1e6 ? 0 : ml - mr);
    if (delta < 0) {
        if (x->left)
            x->left->x -= (abs(delta) / 2 + 25);
        if (x->right)
            x->right->x += (abs(delta) / 2 + 25);

        treeFilling(x->left, (abs(delta) / 2 + 25));
        treeFilling(x->right, -(abs(delta) / 2 + 25));
    }

}

void fix_position(AVL::Node *&x) {
    if (x == nullptr) return;
    if (x->parent == nullptr) {
        x->x = 300;
        x->y = 100;
    } else {
        if (x->parent->left == x) {
            x->setPos(x->parent->x - trees::AVL_NODE_DIAMETR, x->parent->y + trees::AVL_Y_DISTANCE);
        } else {
            x->setPos(x->parent->x + trees::AVL_NODE_DIAMETR, x->parent->y + trees::AVL_Y_DISTANCE);

        }
    }
    fix_position(x->left);
    fix_position(x->right);
}

void Standing(AVL::Node *&x) {
    fix_position(x);
    Stand(x);
}

void paintTree(AVL::Node *x, QGraphicsScene *&scene) {
    if (!x) return;
    auto *ellipse = new QGraphicsEllipseItem(x->x, x->y, trees::AVL_NODE_DIAMETR, trees::AVL_NODE_DIAMETR);
    ellipse->setBrush(QBrush(Qt::white));
    auto *text = new QGraphicsTextItem(QString::number(x->value));
    text->setPos(ellipse->boundingRect().center() - text->boundingRect().center());
    scene->addItem(ellipse);
    scene->addItem(text);
    if (x->parent) {
        auto *line = new QGraphicsLineItem(x->parent->x + trees::AVL_NODE_DIAMETR / 2.,
                                           x->parent->y + trees::AVL_NODE_DIAMETR / 2.,
                                           x->x + trees::AVL_NODE_DIAMETR / 2.,
                                           x->y + trees::AVL_NODE_DIAMETR / 2.);
        line->setZValue(-1);
        auto uu = QPen(QColor(200, 100, 40));
        uu.setWidth(10);
        line->setPen(uu);

        scene->addItem(line);
    }
    paintTree(x->left, scene);
    paintTree(x->right, scene);

}


void AVL::display(QGraphicsScene *scene, AVL::Node *root) {
    scene->clear();
    Standing(root);
    paintTree(root, scene);

}


AVL::Node *AVL::getRoot() const {
    return root;
}

void AVL::click_delete(Node *cur, int x, int y) {
    if (!cur) return;
    if (x > cur->x && x < cur->x + trees::AVL_NODE_DIAMETR && y > cur->y && y < cur->y + trees::AVL_NODE_DIAMETR) {
        this->remove(cur->value);
    } else {
        click_delete(cur->left, x, y);
        click_delete(cur->right, x, y);
    }
}
} // trees
