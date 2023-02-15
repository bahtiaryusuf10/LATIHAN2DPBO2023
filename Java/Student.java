
//Import library
import java.util.Scanner;
import java.util.ArrayList;

public class Student extends CivitasAcademica { // Membuat class Student
    /* Membuat atribut berjenis private */
    private int idNumber; // Untuk menyimpan NIM (ID number)
    private String major; // Untuk menyimpan jurusan
    private String faculty; // Untuk menyimpan fakultas

    /* Konstruktor */
    public Student() // Membuat konstruktor default
    {
        this.idNumber = 0; // Meng-assign atribut idNumber dengan 0
        this.major = ""; // Meng-assign atribut major dengan string kosong
        this.faculty = ""; // Meng-assign atribut faculty dengan string kosong
    }

    public Student(int idNumber, String major, String faculty) // Membuat konstruktor dengan isian dari
                                                                            // parameter
    {
        this.idNumber = idNumber; // Meng-assign atribut idNumber dengan nilai dari parameter idNumber
        this.major = major; // Meng-assign atribut major dengan nilai dari parameter major
        this.faculty = faculty; // Meng-assign atribut faculty dengan nilai dari parameter faculty
    }

    /* Setter dan Getter */    
    public void setIdNumber(int idNumber) // Setter untuk atribut idNumber
    {
        this.idNumber = idNumber; // Meng-assign atribut idNumber dengan nilai dari parameter idNumber
    }

    public void setMajor(String major) // Setter untuk atribut major
    {
        this.major = major; // Meng-assign atribut major dengan nilai dari parameter major
    }

    public void setFaculty(String faculty) // Setter untuk atribut faculty
    {
        this.faculty = faculty; // Meng-assign atribut faculty dengan nilai dari parameter faculty
    }

    public int getIdNumber() // Getter untuk atribut idNumber
    {
        return this.idNumber; // Me-return nilai dari atribut idNumber
    }

    public String getMajor() // Getter untuk atribut major
    {
        return this.major; // Me-return nilai dari atribut major
    }

    public String getFaculty() // Getter untuk atribut faculty
    {
        return this.faculty; // Me-return nilai dari atribut faculty
    }

    /* Method untuk CRUD */
    public void commandOptions() // Method untuk menampilkan menu program CRUD
    {
        System.out.println("==============================");
        System.out.println("|        CRUD Program        |"); // CRUD = Create, Read, Update, Delete
        System.out.println("==============================");
        System.out.println("|  0. Exit the program       |"); // 0 untuk keluar dari program
        System.out.println("|  1. Add student data       |"); // 1 untuk menambahkan data mahasiswa
        System.out.println("|  2. Show list of students  |"); // 2 untuk menampilkan semua data dalam daftar mahasiswa
        System.out.println("==============================");
        System.out.print("Enter your choice : ");
    }

    public void addStudentData(ArrayList<Student> studentList, Student temp, int identity, String name, char gender, String university, int idNumber, String major,
            String faculty, String email) // Method untuk menambahkan data mahasiswa
    {
        // Proses setter dari inputan ke setiap atribut dari objek temp
        temp.setIdentity(identity);
        temp.setName(name);
        temp.setGender(gender);
        temp.setUniversity(university);
        temp.setIdNumber(idNumber);
        temp.setMajor(major);
        temp.setFaculty(faculty);
        temp.setEmailEdu(email);

        if (studentList.isEmpty()) // Jika list kosong, langsung masukan data ke dalam list
        {
            studentList.add(temp); // Memasukan data ke dalam list
            System.out.println("\n[SUCCESS] Data has been added."); // Menampilkan pesan bahwa data berhasil
                                                                    // dimasukan ke dalam list
        } else // Jika list tidak kosong, lakukan pengecekan terlebih dahulu
        {
            boolean find = false; // Untuk mengecek apakah data sudah ada atau belum, nilai defaultnya
                                  // adalah false yang menandakan data belum ada
            int i = 0; // Membuat iterator untuk mengecek data dalam list

            /*
             * do while untuk mengecek apakah data sudah ada atau belum, pengecekkan
             * menggunakan NIM sebagai primary key
             */
            do {
                if (temp.getIdNumber() == studentList.get(i).getIdNumber()) // Jika NIM sudah ada, maka data tidak akan
                                                                            // dimasukan ke dalam list dan akan
                                                                            // menampilkan pesan error
                {
                    find = true; // Jika NIM sudah ada, maka nilai find akan berubah menjadi true
                    System.out.println(
                            "\n[ERROR] ID number already exists, please add data with a different ID number."); // Pesan
                                                                                                                // error
                }
                i++; // Iterasi untuk mengecek data selanjutnya
            } while (find == false && i < studentList.size()); // Jika data belum ditemukan dan iterator
                                                               // belum sampai ke akhir list, maka akan
                                                               // melakukan proses pengecekan data
                                                               // berikutnya

            if (find == false) // Jika data tidak ditemukan, maka data akan dimasukan ke dalam list
            {
                studentList.add(temp); // Memasukan data ke dalam list
                System.out.println("\n[SUCCESS] Data has been added."); // Menampilkan pesan bahwa data
                                                                        // berhasil dimasukan ke dalam list
            }
        }
    }

    public void showListOfStudent(ArrayList<Student> studentList) // Method untuk menampilkan data mahasiswa
    {
        if (studentList.isEmpty()) // Jika list kosong, maka akan menampilkan pesan error
        {
            System.out.println("\n[WARNING] The student list is still empty."); // Pesan error
        } else // Jika list tidak kosong, maka akan menampilkan data mahasiswa
        {
            int i = 0, no = 0; // Untuk menampilkan nomor urut data mahasiswa

            System.out.println(); // Memberikan jarak antara menu dan data mahasiswa

            for (studentList.get(i); i < studentList.size(); i++) // Looping untuk menampilkan data
                                                                  // mahasiswa
            {

                System.out.println((no + 1) + ". Identity    : " + studentList.get(i).getIdentity());
                System.out.println("   Name        : " + studentList.get(i).getName());
                System.out.println("   Gender      : " + studentList.get(i).getGender());
                System.out.println("   University  : " + studentList.get(i).getUniversity());
                System.out.println("   ID number   : " + studentList.get(i).getIdNumber());
                System.out.println("   Major       : " + studentList.get(i).getMajor());
                System.out.println("   Faculty     : " + studentList.get(i).getFaculty());
                System.out.println("   Email       : " + studentList.get(i).getEmailEdu());
                if (i != studentList.size() - 1) // Jika bukan data terakhir, maka akan memberikan jarak
                                                 // antara data mahasiswa
                {
                    System.out.println();
                }
                no++; // Iterasi nomor urut
            }
        }
    }

    public void clearScreen() // Method untuk membersihkan layar
    {
        System.out.print("\033[H\033[2J"); // Membersihkan layar dengan menggunakan escape sequence
        System.out.flush(); // Membersihkan buffer dari escape sequence
    }
}
