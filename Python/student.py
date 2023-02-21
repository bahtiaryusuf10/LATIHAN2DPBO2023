from prettytable import PrettyTable # Import library untuk menampilkan data dalam bentuk tabel
from civitasacademic import CivitasAcademic # Import class CivitasAcademic dari file CivitasAcademic.py

class Student(CivitasAcademic): # Deklarasi class Student (child class dari CivitasAcademic)
    __idNumber = 0 # Untuk menyimpan NIM mahasiswa, atribut berjenis private
    __major = "" # Untuk menyimpan jurusan mahasiswa, atribut berjenis private
    __faculty = "" # Untuk menyimpan fakultas mahasiswa, atribut berjenis private

    def __init__(self, identity = 0, name = "", gender = '', university = "", email = "", idNumber = 0, major = "", faculty = ""): # Membuat constructor
        super().__init__(identity, name, gender, university, email) # Menginisialisasi setiap atribut yang ada di dalam konstruktor parent class CivitasAcademic
        self.__idNumber = idNumber # Menginisialisasi atribut __idNumber
        self.__major = major # Menginisialisasi atribut __major
        self.__faculty = faculty # Menginisialisasi atribut __faculty
    
    def setIdNumber(self, idNumber): # Setter untuk atribut __idNumber
        self.__idNumber = idNumber # Menginisialisasi atribut __idNumber

    def setMajor(self, major): # Setter untuk atribut __major
        self.__major = major # Menginisialisasi atribut __major

    def setFaculty(self, faculty): # Setter untuk atribut __faculty
        self.__faculty = faculty # Menginisialisasi atribut __faculty

    def getIdNumber(self): # Getter untuk atribut __idNumber
        return self.__idNumber # Mengembalikan nilai atribut __idNumber

    def getMajor(self): # Getter untuk atribut __major
        return self.__major # Mengembalikan nilai atribut __major

    def getFaculty(self): # Getter untuk atribut __faculty
        return self.__faculty # Mengembalikan nilai atribut __faculty

    def commandOptions(self): # Membuat method untuk menampilkan menu command
        print("==============================")
        print("|        CRUD Program        |") # CRUD = Create, Read, Update, Delete
        print("==============================")
        print("|  0. Exit the program       |") # 0 untuk keluar dari program
        print("|  1. Add student data       |") # 1 untuk menambahkan data mahasiswa
        print("|  2. Update student data    |") # 2 untuk mengubah data mahasiswa
        print("|  3. Delete student data    |") # 3 untuk menghapus data mahasiswa
        print("|  4. Show list of students  |") # 4 untuk menampilkan semua data dalam daftar mahasiswa
        print("==============================")
        print("Enter your choice : ", end = '')

    def addStudentData(self, studentList, temp, identity, name, gender, university, email, idNumber, major, faculty): # Membuat method untuk menambahkan data mahasiswa
    # Proses setter data inputan ke setiap atribut dari objek temp
        temp.setIdentity(identity)
        temp.setName(name)
        temp.setGender(gender)
        temp.setUniversity(university)
        temp.setEmail(email)
        temp.setIdNumber(idNumber)
        temp.setMajor(major)
        temp.setFaculty(faculty)

        if not studentList: # Jika list kosong, langsung masukan data ke dalam list
            studentList.append(temp) # Memasukan data ke dalam list
            print("\n[SUCCESS] Data has been added.\n\n") # Menampilkan pesan bahwa data berhasil dimasukan ke dalam list
        else: # Jika list tidak kosong, lakukan pengecekan terlebih dahulu
            find = False # Untuk mengecek apakah data sudah ada atau belum, nilai defaultnya adalah false yang menandakan data belum ada

            i = 0 # Untuk mengecek data satu persatu
            while not find and i < len(studentList): # while untuk mengecek apakah NIK atau email atau NIM sudah ada atau belum
                if temp.getIdentity() == studentList[i].getIdentity(): # Jika NIK sudah ada, maka data tidak akan dimasukan ke dalam list dan akan menampilkan pesan error
                    find = True # Jika data ditemukan, maka nilai find akan berubah menjadi true
                    print("\n[ERROR] Identity already exists, please add data with a different identity.\n\n") # Pesan error
                elif temp.getEmail() == studentList[i].getEmail(): # Jika email sudah ada, maka data tidak akan dimasukan ke dalam list dan akan menampilkan pesan error
                    find = True # Jika data ditemukan, maka nilai find akan berubah menjadi true
                    print("\n[ERROR] Email already exists, please add data with a different Email.\n\n") # Pesan error
                elif temp.getIdNumber() == studentList[i].getIdNumber(): # Jika NIM sudah ada, maka data tidak akan dimasukan ke dalam list dan akan menampilkan pesan error
                    find = True # Jika NIM sudah ada, maka nilai find akan berubah menjadi true
                    print("\n[ERROR] ID number already exists, please add data with a different ID number.\n\n") # Pesan error
                i += 1 # Iterasi untuk mengecek data selanjutnya

            if not find : # Jika data tidak ditemukan, maka data akan dimasukan ke dalam list
                studentList.append(temp) # Memasukan data ke dalam list
                print("\n[SUCCESS] Data has been added.\n\n") # Menampilkan pesan bahwa data berhasil dimasukan ke dalam list

    def updateStudentData(self, studentList, identity): # Membuat method untuk mengubah data mahasiswa
        find1 = False # Untuk mengecek apakah data ada atau tidak, nilai defaultnya adalah false yang menandakan data tidak ada
        i = 0 # Membuat iterator untuk mengecek data dalam list

        while not find1 and i < len(studentList): # while untuk mengecek apakah data yang akan diubah ada di dalam studentList atau tidak
            if studentList[i].getIdentity() == identity: # Jika data yang akan diubah ditemukan di dalam studentList, maka akan meminta beberapa masukan
                find1 = True # Jika data ditemukan, maka nilai find1 akan berubah menjadi true
                self._university = input("\nEnter University      : ") # Meminta masukan untuk mengubah universitas
                self._email = input("Enter Email           : ") # Meminta masukan untuk mengubah email
                self.__major = input("Enter Major           : ") # Meminta masukan untuk mengubah jurusan
                self.__faculty = input("Enter Faculty         : ") # Meminta masukan untuk mengubah fakultas

                find2 = False #Untuk mengecek apakah email sudah digunakan atau belum, nilai defaultnya adalah false yang menandakan email belum digunakan
                ii = 0 # Membuat iterator untuk mengecek data dalam list

                while not find2 and ii < len(studentList): # while untuk mengecek apakah email sudah digunakan atau belum
                    if studentList[ii].getEmail() == self._email and studentList[ii].getIdentity() != identity: # Jika email sudah digunakan oleh mahasiswa lain, maka akan menampilkan pesan error
                        find2 = True
                        print("\n[ERROR] Email already exists, please add data with a different Email.\n\n")
                    ii += 1

                if not find2: # Jika email belum digunakan, maka akan mengubah data yang sudah ada di dalam studentList dengan data baru dan menampilkan pesan success
                    studentList[i] = Student(studentList[i].getIdentity(), studentList[i].getName(), studentList[i].getGender(), self._university, self._email, studentList[i].getIdNumber(), self.__major, self.__faculty) # Mengubah data yang sudah ada di dalam studentList dengan data baru
                    print("\n[SUCCESS] Data has been changed.\n\n") # Menampilkan pesan bahwa data berhasil diubah
            i += 1 # Iterasi untuk mengecek data selanjutnya

        if not find1: # Jika data tidak ditemukan, maka akan menampilkan pesan error
            print("\n[ERROR] Student data not found in the list.\n\n") # Pesan error

    def deleteStudentData(self, studentList, identity): # Membuat method untuk menghapus data mahasiswa
        find = False # Untuk mengecek apakah data ada atau tidak, nilai defaultnya adalah false yang menandakan data tidak ada
        i = 0 # Membuat iterator untuk mengecek data dalam list

        while not find and i < len(studentList): # while untuk mengecek apakah data yang akan diubah ada di dalam studentList atau tidak
            if studentList[i].getIdentity() == identity: # Jika data yang akan dihapus ditemukan di dalam studentList, maka data akan dihapus
                find = True # Jika data ditemukan, maka nilai find akan berubah menjadi true
                del studentList[i] # Menghapus data yang ditemukan

                print("\n[SUCCESS] Data has been deleted.\n\n") # Menampilkan pesan bahwa data berhasil dihapus  
            i += 1 # Iterasi untuk mengecek data selanjutnya

        if not find: # Jika data tidak ditemukan, maka akan menampilkan pesan error
            print("\n[ERROR] ID number not exist!\n\n") # Pesan error

    def showListOfStudent(self, studentList): # Membuat method untuk menampilkan daftar mahasiswa
        if not studentList: # Jika list kosong, maka akan menampilkan pesan error
            print("\n[WARNING] The student list is still empty.\n\n") # Pesan error
        else: # Jika list tidak kosong, maka akan menampilkan data mahasiswa
            print() # Untuk memberikan jarak antara menu command dan daftar mahasiswa
        
            table = PrettyTable() # Membuat objek table dari class PrettyTable
            table.field_names = ["No.", "Identity Number", "Name", "Gender", "University", "Email Edu", "ID Number", "Major", "Faculty"] # Membuat header untuk tabel

            for i, student in enumerate(studentList): # Looping untuk menampilkan data mahasiswa
                table.add_row([i+1, student.getIdentity(), student.getName(), student.getGender(), student.getUniversity(), student.getEmail(), student.getIdNumber(), student.getMajor(), student.getFaculty()]) # Menambahkan data mahasiswa ke dalam tabel

            print(table) # Menampilkan tabel
            print('\n') # Menambah baris kosong