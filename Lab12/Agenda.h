#ifndef Agenda_h
#define Agenda_h

#include "Contact.h"
#include "Prieten.h"
#include "vector<Contact>.h"


class Agenda : public Contact {

 public:

    virtual Contact &getContactByName();

    virtual Prieten getPrieteni();

    virtual void deleteContact(void  name);

    virtual void addContact(void  name);


 private:
    vector<Contact> persoane;

};

#endif // Agenda_h
