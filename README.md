# LATIHAN2DPBO2023
### Saya Muhammad Yusuf Bahtiar NIM 2107980 mengerjakan Latihan 2 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

## Deskripsi Tugas
Buatlah program berbasis OOP menggunakan bahasa pemrograman C++, Java, Python, dan PHP yang mengimplementasikan konsep Multi-level Inheritance.

## Desain Program
![Desain](https://user-images.githubusercontent.com/100776170/220320126-5fe81cac-e95d-4919-bbc4-feab20debebf.jpg)

Program didesain menjadi 3 class:
* *Human* sebagai super class pertama, dalam class ini terdapat 3 atribut diantaranya:
  + identity -> berisikan NIK, bertipe data `default : long long`
  + name     -> berisikan Nama Mahasiswa, bertipe data `string`
  + gender   -> berisikan Jenis Kelamin Mahasiswa, bertipe data `character`
  
  Tiap atribut memiliki setter dan getternya masing-masing yang berada pada class `Human`.
  
* *CivitasAcademica* sebagai sub class dari class Human (Civitas Academica juga menjadi super class kedua), dalam class ini terdapat 2 atribut diantaranya:
  + university -> berisikan Universitas Asal, bertipe data `string`
  + emailEdu   -> berisikan Emaiil Mahasiswa, bertipe data `string`

  Tiap atribut memiliki setter dan getternya masing-masing yang berada pada class `Civitas Academica`.

* *Student* sebagai sub class dari class Civitas Academica, dalam class ini terdapat 3 atribut dan 4 method diantaranya:
  + idNumber -> berisikan NIM Mahasiswa, bertipe data `integer`
  + major    -> berisikan Jurusan Mahasiswa, bertipe data `string`
  + faculty  -> berisikan Fakultas Mahasiswa, bertipe data `string`

  Tiap atribut memiliki setter dan getternya masing-masing yang berada pada class `Student`. 


Selain itu, di dalam class `Student` juga terdapat beberapa method untuk memproses data mahasiswa, diantaranya ialah addStudentData untuk menambahkan data, updateStudentData untuk melakukan perubahan terhadap data, deleteStudentData untuk menghapus data dari daftar, dan showListOfStudent untuk menampilkan daftar data mahasiswa. 


## Alur Program


## Dokumentasi
Pada program Java

![Screenshot - Java](https://user-images.githubusercontent.com/100776170/218934153-3144f3b7-153a-4139-80c4-90764e81b57d.png)

<br>

Pada program Python

![Add - Python](https://user-images.githubusercontent.com/100776170/220263508-b24d0cf0-9a5d-4967-a30f-2f4bc603982c.png)
![Update - Python](https://user-images.githubusercontent.com/100776170/220263539-b4f1c9ad-b7bb-435e-a8ed-fbbf79edf8dc.png)
![Delete - Python](https://user-images.githubusercontent.com/100776170/220263555-d9761e68-a04d-4cb9-b684-a32ee4baf42b.png)

<br>

Pada program PHP

![Add - PHP](https://user-images.githubusercontent.com/100776170/220263669-1180bc4a-6f72-4742-8040-c320e224ec0f.png)
![Update - PHP](https://user-images.githubusercontent.com/100776170/220263682-540f719b-1807-4f83-8e4a-323d4c0028b7.png)
![Delete - PHP](https://user-images.githubusercontent.com/100776170/220263689-41c8be5e-c874-41e1-8c8c-fc8d2e848f2f.png)
