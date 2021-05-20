#ifndef Agenda_h
#define Agenda_h

#include "Contact.h"
#include "Prieten.h"
#include "vector<Contact>.h"


class Agenda : public Contact {

 public:

    virtual Contact &getContactByName();

    virtual Prieten getPrieteni();

    virtual void deleteContact(String name);

    virtual void addContact(String name);


 private:
    vector<Contact> persoane;

 public:



    /**
     * @element-type Contact
     */
    Contact *myContact;
};

#endif // Agenda_h
