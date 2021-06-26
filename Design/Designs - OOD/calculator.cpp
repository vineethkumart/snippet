/*
object oriended expression evaluation
1+2*3-1

Can do this using composite pattern and representing the expression as a AST
*/

class Node { // operator or operand
public:
    virtual int evaluate() = 0;
private:
    list<Node*> children;
};

class Add  : public Node {
public:
    int evalute() {
        assert(children.size() == 2);
        int a = evaluate(children[0]);
        int b = evaluate(children[1]);
        return a + b;
    }
};

class Ternary : public Node {
    // define the evaluation semantics here.
};
class Constant : public Node {
public:
    Constant(int value) : val(value) {}
    int evaluate() {
        return val;
    }
private:
    int val;
};
// other concrete operators

int client()
{
    string e = "1+2*3-4";
    // preproces and conver to prefix/postfix
    // -+1*234
    // build the expression tree
    Node* root = BuildTree(e);
    return root->evaluate();
}