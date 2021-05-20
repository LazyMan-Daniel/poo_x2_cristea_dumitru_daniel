#ifndef Contact_h
#define Contact_h

class Agenda;

class Contact {


 protected:
    String name;

 public:


    /**
     * @element-type Agenda
     */
    Agenda *myAgenda;
};

#endif // Contact_h
