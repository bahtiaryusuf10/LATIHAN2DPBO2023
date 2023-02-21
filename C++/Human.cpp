// Import library yang dibutuhkan
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std; // Menggunakan standard namespace

class Human // Deklarasi class Human (parent class)
{
protected:              // Membuat atribut berjenis protected
    long long identity; // Untuk menyimpan NIK mahasiswa
    string name;        // Untuk menyimpan nama mahasiswa
    char gender;        // Untuk menyimpan jenis kelamin mahasiswa

public:
    /* Konstruktor */
    Human() // Konstruktor tanpa isian
    {
        this->identity = 0LL;
        this->name = "";
        this->gender = '-';
    }

    Human(long long identity, string name, char gender) // Konstruktor dengan isian dari parameter
    {
        this->identity = identity;
        this->name = name;
        this->gender = gender;
    }

    /* Setter dan Getter untuk setiap atribut di dalam class Human*/
    void setIdentity(long long identity)
    {
        this->identity = identity;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setGender(char gender)
    {
        this->gender = gender;
    }

    long long getIdentity()
    {
        return this->identity;
    }

    string getName()
    {
        return this->name;
    }

    char getGender()
    {
        return this->gender;
    }

    /* Destruktor */
    ~Human()
    {
    }
};