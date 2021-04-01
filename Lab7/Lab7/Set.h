#pragma once

#include <iostream>
#include <cstddef>

// set = vector unde elementele apar o singura data si sunt ordonate
// un set generic ar trebui sa primeasca un tip de data (notat aici prin T) si o functie de comparare
// ( vedeti ca e initializata cu o valoarea default std::less<T>) daca nu e specificati
template <typename T, typename Compare = std::less<T>>
class Set {
private:
    // vectorul curent de elemente
    T* data;
    // size-ul curent (cate elemente avem)
    size_t data_size;
    // capacitatea totala (cate elemente putem avea maxim)
    size_t data_capacity;
    // functia de comparare folosita
    Compare compare;

    // verificam daca putem aloca "with" elemente noi, daca nu dublam capacitatea curenta
    //    -> apoi creati un nou element folosind constructorul cu care primeste ca parametri capacitatea si functia de
    //    compare
    //    -> adaugati noile valori in noul Set
    //    -> folositi functia swap intre set-ul curent si cel nou pentru a muta elementele
    void reserve(size_t with);

    // daca nu exista un anumit index -> dam terminate
    void check_index(size_t index) const;

public:
    // creem un nou set care doar primeste o functie de compare, NU lasati restul membrilor neinitializati
    Set(const Compare& compare = Compare());

    // aloca memeorie pentru membrul data cu capacity elemente, NU lasati restul membrilor neinitializati
    Set(size_t capacity, const Compare& compare = Compare());

    // sterge memoria alocata, ca la ultimul laborator
    ~Set();

    // functii care returneaza elementul de pe pozitia index, se verifica cu check_index daca exista sau nu acel index
    const T& operator[](size_t index) const;
    T& operator[](size_t index); // care e diferenta dintre cele 2?

    // returneaza cate elemente avem in momentul de fata
    size_t size() const;

    // returneaza cate elemente putem avea in total
    size_t capacity() const;

    // adauga un nou element: daca exista nu-l mai adaugam, daca nu avem loc pentru el folosim reserve ca sa crestem
    // spatiul! In urma adaugarii vectorul sa fie in continuare sortat si neduplicat.
    Set& add(const T& value);

    // aceasta functie face swap pe rand la toti membrii din clasa curenta cu cei din clasa primita ca parametru, fara
    // functia de compare
    void swap(Set& other);
};

template <typename T, typename Compare>
void Set<T, Compare>::check_index(size_t index) const {
    if (index >= size()) {
        fprintf(stderr, "index out of range: %zu\n", index);
        std::terminate();
    }
}




// trece prin fiecare element cu operatorul de indexare si il scrie in stream folosind << urmat de ' ', la final '\n'
template <typename T, typename Compare>
std::ostream& operator<<(std::ostream& stream, const Set<T, Compare>& set);


//c++ code

template<typename T, typename Compare>
inline Set<T, Compare>::Set(const Compare& compare)
{
    data = new T[1];
    data_size = 0;
    data_capacity = 1;
}

template<typename T, typename Compare>
Set<T, Compare>::Set(size_t capacity, const Compare& compare)
{
    data = new T[capacity];
    data_size = 0;
    data_capacity = capacity;
}

template<typename T, typename Compare>
Set<T, Compare>::~Set()
{
    delete[] data;
}

template<typename T, typename Compare>
const T& Set<T, Compare>::operator[](size_t index) const
{
    return *(this->data[index]);
}

template<typename T, typename Compare>
inline T& Set<T, Compare>::operator[](size_t index)
{
    return *(this->data[index]);
}

template<typename T, typename Compare>
inline size_t Set<T, Compare>::size() const
{
    return data_size;
}

template<typename T, typename Compare>
inline size_t Set<T, Compare>::capacity() const
{
    return data_capacity;
}

template<typename T, typename Compare>
inline Set<T,Compare>& Set<T, Compare>::add(const T& value)
{
    //for (int i = 0; i < data_size; i++)
      //  if (value == data[i])
        //    return Set;
    

}
