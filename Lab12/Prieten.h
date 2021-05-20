#ifndef Prieten_h
#define Prieten_h

#include ".h"
#include "Contact.h"


class Prieten : public Contact, public , public Contact {


 private:
    String dataNastere;
    String nrTelefon;
    String adresa;

 public:

    /**
     * @element-type Contact
     */
    Contact *Extends;
};

#endif // Prieten_h
