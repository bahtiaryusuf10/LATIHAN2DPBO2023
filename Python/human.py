class Human: # Deklarasi class Human (parent class)
    _identity = 0 # Untuk menyimpan NIK (Identity Number) mahasiswa, atribut berjenis protected
    _name = "" # Untuk menyimpan nama mahasiswa, atribut berjenis protected
    _gender = '' # Untuk menyimpan jenis kelamin mahasiswa, atribut berjenis protected

    def __init__(self, identity = 0, name = "", gender = ''): # Membuat konstruktor
        self._identity = identity # Menginisialisasi atribut _identity
        self._name = name # Menginisialisasi atribut _name
        self._gender = gender # Menginisialisasi atribut _gender

    def setIdentity(self, identity): # Setter untuk atribut _identity
        self._identity = identity # Menginisialisasi atribut _identity

    def setName(self, name): # Setter untuk atribut _name
        self._name = name # Menginisialisasi atribut _name

    def setGender(self, gender): # Setter untuk atribut _gender
        self._gender = gender # Menginisialisasi atribut _gender

    def getIdentity(self): # Getter untuk atribut _identity
        return self._identity # Mengembalikan nilai atribut _identity

    def getName(self): # Getter untuk atribut _name
        return self._name # Mengembalikan nilai atribut _name

    def getGender(self): # Getter untuk atribut _gender
        return self._gender # Mengembalikan nilai atribut _gender
