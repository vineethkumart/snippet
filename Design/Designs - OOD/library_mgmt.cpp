/*
Functional Requirement
-----------------------
Think of the librarian there
Think of the user coming an taking books
Think of the books present there.
1. Book Store -> Add/Remove book and copies
2. Searchable Books
3. 
*/

enum bookcat_t {
    fiction,
    nonfiction
    /*...*/
};

enum booktype_t {
    hardcover,
    paperback,
    ebook
    /* ... */
};

class Book {
    Book(...);
private:
    int id;
    string name;
    string author;
    bookcat_t cat;
    
    int num_pages;
    list<string> authors;
};

/* represent an instance of book */
class BookItem : public Book {

private:
    int placedat;
    bool lended;
    int price;
    booktype_t type;
    int rack_id;
    date date_of_purchase;
};

class Reservation {

}

class Director {

}

class User {
// get/set methods
private:
    int id;
    name,
    joined at
    hash_of_pwd;
};

class Librarian : public User {
private:
};

class Subscriber : public User {

};

class General : public User {

};

class Library {
    Addmember();
    RemoveMember();
    GetMembers(); // based on many sort conditions
    User* login();

private:
    string name;
    int id;
    string location;
    /* ..*/
};

class LbraryA : public Library {
private:
    
};

client()
{
    Library* l = Director::Create(library_id/*other details to identify library*/);
    Librarian* a = l->login(librarian_id, librarian_pwd);
}