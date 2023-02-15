
// Import library
import java.util.Scanner;

import javax.swing.plaf.synth.SynthOptionPaneUI;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) { // Method main yang akan dijalankan pertama kali
        ArrayList<Student> studentList = new ArrayList<>(); // Membuat objek ArrayList untuk menyimpan data mahasiswa
        Scanner scan = new Scanner(System.in); // Membuat objek Scanner untuk meminta masukan dari user

        boolean flag = true; // Deklarasi variabel flag untuk menentukan apakah program akan berulang atau
                             // tidak
        int input; // Deklarasi variabel input untuk menyimpan masukan dari user
        
        do{
            Student studentObject = new Student(); // Deklarasi objek studentObject dari kelas Student
            studentObject.clearScreen(); // Membersihkan layar
            studentObject.commandOptions(); // Menampilkan menu

            input = scan.nextInt(); // Meminta input dari user
            int identity, idNumber; // Deklarasi variabel idNumber untuk menyimpan NIM (ID Number) mahasiswa
            String name, major, faculty, university, email; // Deklarasi variabel name, major, faculty, university, dan email untuk menyimpan nama,
                                         // jurusan, akultas, universitas, dan email mahasiswa
                                             // 
            char gender;

            switch(input){
                case 0: // Jika input = 0, maka program akan berhenti
                    flag = false; // Mengubah nilai flag menjadi false
                    break;
                case 1:
                    System.out.print("\nEnter Identity number : ");
                    identity = scan.nextInt(); // Meminta input dari user untuk nik mahasiswa
                    System.out.print("Enter Name            : ");
                    name = scan.next(); // Meminta input dari user untuk nama mahasiswa
                    System.out.print("Enter gender          : ");
                    gender = scan.next().charAt(0);
                    System.out.print("Enter University      : ");
                    university = scan.next(); //
                    System.out.print("Enter ID number       : ");
                    idNumber = scan.nextInt(); // Meminta input dari user untuk nim mahasiswa
                    System.out.print("Enter Major           : ");
                    major = scan.next(); // Meminta input dari user untuk nama mahasiswa
                    System.out.print("Enter Faculty         : ");
                    faculty = scan.next();
                    System.out.print("Enter Email Edu       : ");
                    email = scan.next();
            
                    // Memanggil method addStudentData untuk menambahkan data mahasiswa ke dalam
                    // list
                    studentObject.addStudentData(studentList, studentObject, identity, name, gender, university, idNumber, major, faculty, email);
                break;
                case 2: // Jika input = 4, maka program akan menampilkan seluruh data mahasiswa yang ada
                    // di dalam list
                // Memanggil method showListOfStudent untuk menampilkan seluruh data mahasiswa
                // yang ada di dalam list
                    studentObject.showListOfStudent(studentList);
                    break;
                default: // Jika input selain 0, 1, 2, 3, dan 4, maka akan menampilkan pesan peringatan
                    System.out.println("\n[WARNING] Invalid input, please try again."); // Pesan peringatan
                    break;    
            }
                                

            if (input != 0) // Jika input tidak sama dengan 0, maka akan menampilkan 2 enter dan mempause
                            // program
            {
                System.out.println('\n');
                /* Mempause program */
                System.out.println("Press any key to continue . . .");
                new java.util.Scanner(System.in).nextLine();
            }
        }while (flag == true);

        scan.close(); // Menterminasi Scanner
    }
}


    
