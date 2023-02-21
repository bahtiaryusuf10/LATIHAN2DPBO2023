// Import library yang dibutuhkan
#include "CivitasAcademic.cpp" // Import file CivitasAcademic.cpp

using namespace std; // Menggunakan standard namespace

class Student : public CivitasAcademic // Membuat class Student (child) yang mengextends ke class CivitasAcademic (parent)
{
private:            // Membuat atribut berjenis private
    int idNumber;   // Untuk menyimpan NIM (ID number) mahasiswa
    string major;   // Untuk menyimpan jurusan mahasiswa
    string faculty; // Untuk menyimpan fakultas mahasiswa

public:
    /* Konstruktor */
    Student() : CivitasAcademic() // Membuat konstruktor tanpa isian, class yang di-extends akan diinstansiasi terlebih dahulu
    {
        this->idNumber = 0;
        this->major = "";
        this->faculty = "";
    }

    Student(long long identity, string name, char gender, string university, string email, int idNumber, string major, string faculty) : CivitasAcademic(identity, name, gender, university, email) // Membuat konstruktor dengan isian dari parameter
    {
        this->idNumber = idNumber;
        this->major = major;
        this->faculty = faculty;
    }

    /* Setter dan Getter untuk setiap atribut di dalam class Student */
    void setIdNumber(int idNumber)
    {
        this->idNumber = idNumber;
    }

    void setMajor(string major)
    {
        this->major = major;
    }

    void setFaculty(string faculty)
    {
        this->faculty = faculty;
    }

    int getIdNumber()
    {
        return this->idNumber;
    }

    string getMajor()
    {
        return this->major;
    }

    string getFaculty()
    {
        return this->faculty;
    }

    /* Method untuk perintah pilihan */
    void commandOptions() // Method untuk menampilkan menu program CRUD
    {
        cout << "==============================\n";
        cout << "|        CRUD Program        |\n"; // CRUD = Create, Read, Update, Delete
        cout << "==============================\n";
        cout << "|  0. Exit the program       |\n"; // 0 untuk keluar dari program
        cout << "|  1. Add student data       |\n"; // 1 untuk menambahkan data mahasiswa
        cout << "|  2. Update student data    |\n"; // 2 untuk mengubah data mahasiswa
        cout << "|  3. Delete student data    |\n"; // 3 untuk menghapus data mahasiswa
        cout << "|  4. Show list of students  |\n"; // 4 untuk menampilkan semua data dalam daftar mahasiswa
        cout << "==============================\n";
        cout << "Enter your choice : ";
    }

    /* Method untuk CRUD */
    void addStudentData(list<Student> &studentList, Student temp, long long identity, string name, char gender, string university, string email, int idNumber, string major, string faculty) // Method untuk menambahkan data mahasiswa
    {
        // Proses setter data inputan ke setiap atribut dari objek temp
        temp.setIdentity(identity);
        temp.setName(name);
        temp.setGender(gender);
        temp.setUniversity(university);
        temp.setEmail(email);
        temp.setIdNumber(idNumber);
        temp.setMajor(major);
        temp.setFaculty(faculty);

        if (studentList.empty()) // Jika list kosong, langsung masukan data ke dalam list
        {
            studentList.push_back(temp);                  // Memasukan data ke dalam list
            cout << "\n[SUCCESS] Data has been added.\n"; // Menampilkan pesan bahwa data berhasil dimasukan ke dalam list
        }
        else // Jika list tidak kosong, lakukan pengecekan terlebih dahulu
        {
            bool find = false;                                // Untuk mengecek apakah data sudah ada atau belum, nilai defaultnya adalah false yang menandakan data belum ditemukan
            list<Student>::iterator it = studentList.begin(); // Membuat iterator untuk mengecek data dalam list

            do // do while untuk mengecek apakah data sudah ada atau belum, pengecekkan menggunakan setiap primary key di tiap tabel
            {
                /* Jika ditemukan NIK atau email atau NIM yang sama, maka data tidak akan dimasukan ke dalam list dan akan menampilkan pesan error */
                if (temp.getIdentity() == it->getIdentity())
                {
                    find = true; // Jika data ditemukan, maka nilai find akan berubah menjadi true
                    cout << "\n[ERROR] Identity already exists, please add data with a different identity.\n";
                }
                else if (temp.getEmail() == it->getEmail())
                {
                    find = true;
                    cout << "\n[ERROR] Email already exists, please add data with a different Email.\n";
                }
                else if (temp.getIdNumber() == it->getIdNumber())
                {
                    find = true;
                    cout << "\n[ERROR] ID number already exists, please add data with a different ID number.\n";
                }
                it++;                                           // Iterasi untuk mengecek data selanjutnya
            } while (find == false && it != studentList.end()); // Jika data belum ditemukan dan iterator belum sampai ke akhir list, maka akan melakukan proses pengecekan data berikutnya

            if (find == false) // Jika data tidak ditemukan, maka data akan dimasukan ke dalam list dan menampilkan pesan success
            {
                studentList.push_back(temp);
                cout << "\n[SUCCESS] Data has been added.\n";
            }
        }
    }

    void updateStudentData(list<Student> &studentList, long long identity) // Method untuk mengubah data mahasiswa
    {
        bool find1 = false;                                // Untuk mengecek apakah data sudah ada atau belum, nilai defaultnya adalah false yang menandakan data belum ada
        list<Student>::iterator it1 = studentList.begin(); // Membuat iterator untuk mengecek data dalam list

        do // do while untuk mengecek apakah data yang akan diubah ada di dalam studentList atau tidak
        {
            if (it1->getIdentity() == identity) // Jika data yang akan diubah ditemukan di dalam studentList, maka akan meminta masukan universitas, email, jurusan, dan fakultas baru. Selain itu, akan dilakukan pengecekan apakah email sudah digunakan atau belum
            {
                find1 = true; // Jika data ditemukan, maka nilai find akan berubah menjadi true
                cout << "\nEnter University    : ";
                cin >> university;
                cout << "Enter Email         : ";
                cin >> email;
                cout << "Enter Major         : ";
                cin >> major;
                cout << "Enter Faculty       : ";
                cin >> faculty;

                bool find2 = false;                                // Untuk mengecek apakah email sudah digunakan atau belum, nilai defaultnya adalah false yang menandakan data belum digunakan
                list<Student>::iterator it2 = studentList.begin(); // Membuat iterator untuk mengecek data dalam list

                do // do while untuk mengecek apakah email baru sudah digunakan atau belum
                {
                    if (it2->getEmail() == email && it2->getIdentity() != identity) // Jika Email sudah digunakan, maka data tidak akan dimasukan ke dalam list dan akan menampilkan pesan error
                    {
                        find2 = true; // Jika data ditemukan, maka nilai find akan berubah menjadi true
                        cout << "\n[ERROR] Email already exists, please add data with a different Email.\n";
                    }
                    it2++;                                            // Iterasi untuk mengecek data selanjutnya
                } while (find2 == false && it2 != studentList.end()); // Jika data belum ditemukan dan iterator belum sampai ke akhir list, maka akan melakukan proses pengecekan data berikutnya

                if (find2 == false) // Jika email belum digunakan, maka perubahan data akan dilakukan dan menampilkan pesan success
                {
                    *it1 = Student(it1->getIdentity(), it1->getName(), it1->getGender(), university, email, it1->getIdNumber(), major, faculty);
                    cout << "\n[SUCCESS] Data has been changed.\n";
                }
            }
            it1++;                                            // Iterasi untuk mengecek data selanjutnya
        } while (find1 == false && it1 != studentList.end()); // Jika data belum ditemukan dan iterator belum sampai ke akhir list, maka akan melakukan proses pengecekan data berikutnya

        if (find1 == false) // Jika data yang akan diubah tidak ditemukan di dalam list, maka akan menampilkan pesan error
            cout << "\n[ERROR] Student data not found in the list.\n";
    }

    void deleteStudentData(list<Student> &studentList, long long identity) // Method untuk menghapus data mahasiswa
    {
        bool find = false;                                // Untuk mengecek apakah data sudah ada atau belum, nilai defaultnya adalah false yang menandakan data belum ditemukan
        list<Student>::iterator it = studentList.begin(); // Membuat iterator untuk mengecek data dalam list

        do // do while untuk mengecek apakah data yang akan dihapus ada di dalam studentList atau tidak
        {
            if (it->getIdentity() == identity) // Jika data yang akan dihapus ditemukan di dalam studentList, maka data akan langsung dihapus dan akan menampilkan pesan success
            {
                find = true; // Jika data ditemukan, maka nilai find akan berubah menjadi true
                studentList.erase(it);

                cout << "\n[SUCCESS] Data has been deleted.\n";
            }
            it++;                                           // Iterasi untuk mengecek data selanjutnya
        } while (find == false && it != studentList.end()); // Jika data belum ditemukan dan iterator belum sampai ke akhir list, maka akan melakukan proses pengecekan data berikutnya

        if (find == false) // Jika data tidak ditemukan, maka akan menampilkan pesan error
            cout << "\n[ERROR] ID number not exist!\n";
    }

    void showListOfStudent(list<Student> &studentList) // Method untuk menampilkan data mahasiswa dalam bentuk tabel
    {
        if (studentList.empty()) // Jika list kosong, maka akan menampilkan pesan error
        {
            cout << "\n[WARNING] The student list is still empty.\n";
        }
        else // Jika list tidak kosong, maka akan menampilkan data mahasiswa
        {
            cout << endl; // Untuk memberikan jarak antara menu dan data mahasiswa

            int maxLength[8] = {15, 4, 6, 10, 9, 9, 5, 7}; // Array untuk menyimpan panjang karakter terpanjang dari setiap kolom, diinstansiasi awal dengan panjang tiap judul header tabel
            for (auto &student : studentList)              // Looping untuk mengecek panjang karakter terpanjang dari setiap kolom
            {
                maxLength[0] = max(maxLength[0], (int)to_string(student.getIdentity()).length()); // Untuk membandingkan panjang karakter sebelumnya (isi dari maxLength[0] dengan panjang karakter yang baru (isi dari student.getIdentity().length())
                maxLength[1] = max(maxLength[1], (int)student.getName().length());
                maxLength[2] = max(maxLength[2], (int)to_string(student.getGender()).length());
                maxLength[3] = max(maxLength[3], (int)student.getUniversity().length());
                maxLength[4] = max(maxLength[4], (int)student.getEmail().length());
                maxLength[5] = max(maxLength[5], (int)to_string(student.getIdNumber()).length());
                maxLength[6] = max(maxLength[6], (int)student.getMajor().length());
                maxLength[7] = max(maxLength[7], (int)student.getFaculty().length());
            }

            printBorder(maxLength); // Menampilkan garis pemisah antara menu dan header tabel

            // Menampilkan header tabel dengan jumlah spasi sesuai dengan panjang karakter terpanjang dari setiap kolom dikurangi panjang karakter judul header tabel
            cout << "|Identity Number";
            printSpace(maxLength[0], 15);
            cout << "  |Name";
            printSpace(maxLength[1], 4);
            cout << "  |Gender";
            printSpace(maxLength[2], 6);
            cout << "  |University";
            printSpace(maxLength[3], 10);
            cout << "  |Email Edu";
            printSpace(maxLength[4], 9);
            cout << "  |ID Number";
            printSpace(maxLength[5], 9);
            cout << "  |Major";
            printSpace(maxLength[6], 5);
            cout << "  |Faculty";
            printSpace(maxLength[7], 7);
            cout << "  |" << endl;

            printBorder(maxLength); // Menampilkan garis pemisah antara header tabel dan data

            // Menampilkan setiap data mahasiswa dengan jumlah spasi sesuai dengan panjang karakter terpanjang dari setiap kolom dikurangi panjang karakter data mahasiswa
            for (auto &student : studentList)
            {
                cout << '|' << student.getIdentity();
                printSpace(maxLength[0], to_string(student.getIdentity()).length());
                cout << "  ";

                cout << '|' << student.getName();
                printSpace(maxLength[1], student.getName().length());
                cout << "  ";

                cout << '|' << student.getGender();
                printSpace(maxLength[2], to_string(student.getGender()).length());
                cout << "   ";

                cout << '|' << student.getUniversity();
                printSpace(maxLength[3], student.getUniversity().length());
                cout << "  ";

                cout << '|' << student.getEmail();
                printSpace(maxLength[4], student.getEmail().length());
                cout << "  ";

                cout << '|' << student.getIdNumber();
                printSpace(maxLength[5], to_string(student.getIdNumber()).length());
                cout << "  ";

                cout << '|' << student.getMajor();
                printSpace(maxLength[6], student.getMajor().length());
                cout << "  ";

                cout << '|' << student.getFaculty();
                printSpace(maxLength[7], student.getFaculty().length());
                cout << "  ";

                cout << "|" << endl;
            }

            printBorder(maxLength); // Menampilkan garis pemisah antara data dan warning pause
        }
    }

    void printBorder(int maxLength[]) // Method printBorder untuk menampilkan garis pemisah
    {
        cout << "+--";              // Menampilkan border di bagian pojok kiri
        for (int i = 0; i < 8; i++) // Proses menampilkan border bagian tengah
        {
            if (i > 0) // Jika i  lebih besar dari 0, maka akan menampilkan border dengan bentuk "+--"
            {
                cout << "+--";
            }

            for (int j = 0; j < maxLength[i]; j++) // Untuk setiap nilai j yang kurang dari panjang kata terpanjang, baik itu header maupun record data, akan ditampilkan karakter '='
            {
                cout << "-";
            }
        }
        cout << "+" << endl; // Menampilkan karakter '+' sebagai penutup border bagian kanan
    }

    void printSpace(int max, int len) // Method printSpace untuk menampilkan spasi
    {
        for (int i = 0; i < max - len; i++) // Menampilkan karakter spasi sebanyak panjang karakter terpanjang dikurangi panjang karakter yang akan ditampilkan
        {
            cout << " ";
        }
    }

    /* Destruktor */
    ~Student() // Membuat destruktor untuk menghapus semua objek yang telah dibuat
    {
    }
};