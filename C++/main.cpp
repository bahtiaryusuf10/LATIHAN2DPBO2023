#include "Student.cpp" // Import file Student.cpp

using namespace std; // Menggunakan standard namespace

int main()
{
    bool flag = true;          // Deklarasi variabel flag untuk menentukan apakah program akan berulang atau tidak
    Student studentObject;     // Deklarasi objek studentObject dari kelas Student
    list<Student> studentList; // Deklarasi list studentList dari kelas Student

    do // do while untuk menampilkan menu dan meminta input dari user
    {
        system("cls");                  // Membersihkan layar
        studentObject.commandOptions(); // Menampilkan menu pilihan

        int input;    // Deklarasi variabel input untuk menyimpan masukan dari user
        cin >> input; // Meminta input dari user

        long long identity;                             // Deklarasi variabel identity untuk menyimpan NIK (Identity Number) mahasiswa
        int idNumber;                                   // Deklarasi variabel idNumber untuk menyimpan NIM (ID Number) mahasiswa
        char gender;                                    // Deklarasi variabel gender untuk menyimpan jenis kelamin mahasiswa
        string name, university, email, major, faculty; // Deklarasi variabel name, university, email, major, dan faculty untuk menyimpan nama, universitas, email, jurusan, dan fakultas mahasiswa

        switch (input) // Switch case untuk menentukan apa yang akan dilakukan berdasarkan input dari user
        {
        case 0:           // Jika input = 0, maka program akan berhenti
            flag = false; // Mengubah nilai flag menjadi false
            break;
        case 1: // Jika input = 1, maka program akan meminta input dari user terkait data mahasiswa yang akan ditambahkan
            cout << "\nEnter Identity number : ";
            cin >> identity; // Meminta input dari user untuk NIK (Identity number) mahasiswa
            cout << "Enter Name            : ";
            cin >> name; // Meminta input dari user untuk nama mahasiswa
            cout << "Enter Gender          : ";
            cin >> gender; // Meminta input dari user untuk jenis kelamin mahasiswa
            cout << "Enter University      : ";
            cin >> university; // Meminta input dari user untuk nama universitas mahasiswa
            cout << "Enter Email           : ";
            cin >> email; // Meminta input dari user untuk email mahasiswa
            cout << "Enter ID number       : ";
            cin >> idNumber; // Meminta input dari user untuk NIM (ID Number) mahasiswa
            cout << "Enter Major           : ";
            cin >> major; // Meminta input dari user untuk jurusan mahasiswa
            cout << "Enter Faculty         : ";
            cin >> faculty; // Meminta input dari user untuk fakultas mahasiswa

            studentObject.addStudentData(studentList, studentObject, identity, name, gender, university, email, idNumber, major, faculty); // Memanggil method addStudentData untuk menambahkan data mahasiswa ke dalam list
            break;
        case 2:                      // Jika input = 2, maka program akan meminta input dari user untuk mengubah data mahasiswa
            if (studentList.empty()) // Jika list kosong, maka akan menampilkan pesan peringatan
            {
                cout << "\n[WARNING] The student list is still empty.\n"; // Pesan peringatan
            }
            else // Jika list tidak kosong, maka akan meminta input dari user untuk NIK (Identity Number) mahasiswa yang akan diubah
            {
                cout << "\nEnter the Identity of the student you want to change : ";
                cin >> identity;

                studentObject.updateStudentData(studentList, identity); // Memanggil method updateStudentData untuk mengubah data mahasiswa di dalam list
            }
            break;
        case 3:                      // Jika input = 3, maka program akan meminta input dari user untuk menghapus data mahasiswa (berdasarkan NIM)
            if (studentList.empty()) // Jika list kosong, maka akan menampilkan pesan peringatan
            {
                cout << "\n[WARNING] The student list is still empty.\n"; // Pesan peringatan
            }
            else // Jika list tidak kosong, maka akan meminta input dari user untuk NIK (Identity Number) mahasiswa yang akan dihapus
            {
                cout << "\nEnter the Identity of the student you want to delete : ";
                cin >> identity;

                studentObject.deleteStudentData(studentList, identity); // Memanggil method deleteStudentData untuk menghapus data mahasiswa di dalam list
            }
            break;
        case 4:                                           // Jika input = 4, maka program akan menampilkan seluruh data mahasiswa yang ada di dalam list
            studentObject.showListOfStudent(studentList); // Memanggil method showListOfStudent untuk menampilkan seluruh data mahasiswa yang ada di dalam list
            break;
        default:                                                      // Jika input selain 0, 1, 2, 3, dan 4, maka akan menampilkan pesan peringatan
            cout << "\n[WARNING] Invalid input, please try again.\n"; // Pesan peringatan
            break;
        }

        if (input != 0) // Jika input tidak sama dengan 0, maka akan menampilkan 2 enter dan mempause program
        {
            cout << "\n\n";
            system("pause"); // Mempause program
        }
    } while (flag == true); // Loop akan berhenti jika flag bernilai false, yakni jika user memasukkan 0

    return 0;
}