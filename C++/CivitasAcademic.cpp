// Import library yang dibutuhkan
#include "Human.cpp" // Import file Human.cpp

using namespace std; // Menggunakan standard namespace

class CivitasAcademic : public Human // Membuat class CivitasAcademic (child) yang mengextends ke class Human (parent)
{
protected:             // Membuat atribut berjenis protected
    string university; // Untuk menyimpan nama universitas mahasiswa
    string email;      // Untuk menyimpan email mahasiswa

public:
    /* Konstruktor */
    CivitasAcademic() : Human() // Membuat konstruktor tanpa isian, class yang di-extends akan diinstansiasi terlebih dahulu
    {
        this->university = "";
        this->email = "";
    }

    CivitasAcademic(long long identity, string name, char gender, string university, string email) : Human(identity, name, gender) // Membuat konstruktor dengan isian dari parameter
    {
        this->university = university;
        this->email = email;
    }

    /* Setter dan Getter untuk setiap atribut di dalam class CivitasAcademic */
    void setUniversity(string university)
    {
        this->university = university;
    }

    void setEmail(string email)
    {
        this->email = email;
    }

    string getUniversity()
    {
        return this->university;
    }

    string getEmail()
    {
        return this->email;
    }

    /* Destruktor */
    ~CivitasAcademic()
    {
    }
};