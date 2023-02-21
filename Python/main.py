import os # Import library os untuk mengakses fungsi-fungsi yang berhubungan dengan sistem operasi
from student import Student # Import class Student dari file Student.py

flag = True # Flag untuk menentukan apakah program akan berhenti atau tidak
studentList = [] # List untuk menyimpan objek mahasiswa

while flag: # while akan terus berjalan selama flag bernilai True
    studentObject = Student() # Membuat objek dari class Student
    os.system('cls' if os.name == 'nt' else 'clear') # Menghapus layar
    studentObject.commandOptions() # Menampilkan menu

    choice = int(input()) # Meminta input dari user untuk memilih menu

    if choice == 0: # Jika user memilih menu 0, maka program akan berhenti
        flag = False # Mengubah nilai flag menjadi False
    elif choice == 1: # Jika user memilih menu 1, maka program akan meminta input dari user untuk data mahasiswa
        identity = int(input("\nEnter Identity Number : ")) # Meminta input dari user untuk NIK (Identity Number) mahasiswa
        name = input("Enter Name            : ") # Meminta input dari user untuk nama mahasiswa
        gender = input("Enter Gender          : ") # Meminta input dari user untuk jenis kelamin mahasiswa
        university = input("Enter University      : ") # Meminta input dari user untuk universitas mahasiswa
        email = input("Enter Email           : ") # Meminta input dari user untuk email mahasiswa
        idNumber = int(input("Enter ID number       : ")) # Meminta input dari user untuk NIM (ID Number) mahasiswa
        major = input("Enter Major           : ") # Meminta input dari user untuk jurusan mahasiswa
        faculty = input("Enter Faculty         : ") # Meminta input dari user untuk fakultas mahasiswa

        studentObject.addStudentData(studentList, studentObject, identity, name, gender, university, email, idNumber, major, faculty) # Memanggil method addStudentData untuk menambahkan data mahasiswa ke dalam list
    elif choice == 2: # Jika user memilih menu 2, maka program akan meminta input dari user untuk Identity mahasiswa yang akan diubah
        if len(studentList) == 0: # Jika list kosong, maka akan menampilkan pesan peringatan
            print('\n' + "[WARNING] The student list is still empty." + '\n\n') # Pesan peringatan
        else: # Jika list tidak kosong, maka akan meminta input dari user untuk Identity mahasiswa yang akan diubah
            identity = int(input("\nEnter the Identity of the student you want to change : "))
            
            studentObject.updateStudentData(studentList, identity); # Memanggil method updateStudentData untuk mengubah data mahasiswa di dalam list
    elif choice == 3: # Jika user memilih menu 3, maka program akan meminta input dari user untuk Identity mahasiswa yang akan dihapus
        if len(studentList) == 0: # Jika list kosong, maka akan menampilkan pesan peringatan
           print('\n' + "[WARNING] The student list is still empty." + '\n\n') # Pesan peringatan
        else: # Jika list tidak kosong, maka akan meminta input dari user untuk Identity mahasiswa yang akan dihapus
            identity = int(input("\nEnter the Identity of the student you want to delete : "))
            
            studentObject.deleteStudentData(studentList, identity); # Memanggil method deleteStudentData untuk menghapus data mahasiswa di dalam list
    elif choice == 4: # Jika user memilih menu 4, maka program akan menampilkan data mahasiswa yang ada di dalam list
        studentObject.showListOfStudent(studentList) # Memanggil method showListOfStudent untuk menampilkan data mahasiswa yang ada di dalam list
    else: # Jika user memilih menu selain 0, 1, 2, 3, dan 4, maka akan menampilkan pesan peringatan
        print('\n' + "[WARNING] Invalid input, please try again." + '\n\n') # Pesan peringatan

    if(choice != 0): # Jika user memilih menu selain 0, maka akan menampilkan pesan untuk menekan tombol apapun untuk melanjutkan
        os.system("pause") # Menampilkan pesan untuk menekan tombol apapun untuk melanjutkan
