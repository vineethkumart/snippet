What
----
1. Same common interface for leaf and internal hierarchial object
2. client treats internal and leaf as same.

How
---
Common Base interface and concreate internal and external node

class Employee {
    virtual string name()  = 0;
    list<Employee> reportees() = 0;
    ...
};

class mts : Employee() {
    name() { return name; }
    reportees() { return 0;}
};

class Manager {
    reportess() {
        => reportees
    }
private:
    list<Employee> reportees;
}

client()
{
    Employee e = new Manager();
    Employee e1 = new mts();
}
