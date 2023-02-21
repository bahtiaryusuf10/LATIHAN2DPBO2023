from human import Human # Import class Human dari file human.py

class CivitasAcademic(Human): # Deklarasi class CivitasAcademic (child class dari Human)
    _university = "" # Untuk menyimpan nama universitas, atribut berjenis protected
    _email = "" # Untuk menyimpan email mahasiswa, atribut berjenis protected

    def __init__(self, identity = 0, name = "", gender = '', university = "", email = ""): # Membuat konstruktor
        super().__init__(identity, name, gender) # Menginisialisasi setiap atribut yang ada di dalam konstruktor parent class Human
        self._university = university # Menginisialisasi atribut _university
        self._email = email # Menginisialisasi atribut _email

    def setUniversity(self, university): # Setter untuk atribut _university
        self._university = university # Menginisialisasi atribut _university

    def setEmail(self, email): # Setter untuk atribut _email
        self._email = email # Menginisialisasi atribut _email

    def getUniversity(self): # Getter untuk atribut _university
        return self._university # Mengembalikan nilai atribut _university

    def getEmail(self): # Getter untuk atribut _email
        return self._email # Mengembalikan nilai atribut _email
