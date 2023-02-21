<?php
require('Student.php'); // Require Class Student

$studentList = array(); // Inisialisasi array list
$arrStudentData = array(); // Inisialisasi array masukan

echo "<center>";
echo "<h3>Create Data</h3>"; // Menampilkan sesi Create

/* Input data mahasiswa */
$arrStudentData[0] = new Student(
    392023877778,
    "Cristiano Ronaldo",
    'L',
    "MIT",
    "siiuuu@mit@edu",
    21779876,
    "Teknik Informatika",
    "STEI",
    "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTgepFseq95ihyhJkaTi07Kpt9edGmzAiMTWg&usqp=CAU"
); // Create data dengan konstruktor
$arrStudentData[0]->addStudentData($studentList, $arrStudentData[0]);

$arrStudentData[1] = new Student(
    342112341451,
    "Pablo_Escobar",
    'L',
    "MIT",
    "donpablo@mit.edu",
    19450817,
    "Seni_Musik",
    "FSRD",
    "https://cdn.britannica.com/15/188715-050-94EA4753/Pablo-Escobar-1991.jpg"
); // Create data dengan konstruktor
$arrStudentData[1]->addStudentData($studentList, $arrStudentData[1]);

$arrStudentData[2] = new Student(
    321341233212,
    "Thomas_Shelby",
    'L',
    "MIT",
    "thomashelby@upi.edu",
    20021214,
    "Kedokteran",
    "FK",
    "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQjyI7hjlWBHlUKEwAuDnEqEYi4zQmfBsZiQQ&usqp=CAU"
); // Create data dengan konstruktor
$arrStudentData[2]->addStudentData($studentList, $arrStudentData[2]);

// Create data dengan setter tiap atribut
$arrStudentData[3] = new Student();
$arrStudentData[3]->setIdentity(377120192823);
$arrStudentData[3]->setName("Maikel");
$arrStudentData[3]->setGender('L');
$arrStudentData[3]->setUniversity("MIT");
$arrStudentData[3]->setEmail("maikel@mit.edu");
$arrStudentData[3]->setIdNumber(21098701);
$arrStudentData[3]->setMajor("Teknik Mesin");
$arrStudentData[3]->setFaculty("FTMD");
$arrStudentData[3]->setImage("https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSArlUh-WtcW4FQyFX1NzWbmX8dfpjcl0GCBw&usqp=CAU");
$arrStudentData[3]->addStudentData($studentList, $arrStudentData[3]);


$showStudentData = new Student(); // Objek untuk menampilkan isi array daftar mahasiswa
$showStudentData->showListOfStudent($studentList); // Menampilkan isi array setelah input data

echo "<h3>Update Data</h3>"; // Menampilkan sesi Update
$arrStudentData[0]->updateStudentData($studentList, $arrStudentData[3], "Harvard", "maikelganteng@harv.edu", "Mikrobiologi", "SITH", "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTF5nXC3S_lZdJgcAOOmxP3HB90aE1h7dDjQw5bW6ekyLwWHj4u-8PT3JYfvdCCDV4PLdY&usqp=CAU"); // Update data
$showStudentData->showListOfStudent($studentList); // Menampilkan isi array setelah update data

echo "<h3>Delete Data</h3>"; // Menampilkan sesi Delete
$arrStudentData[0]->deleteStudentData($studentList, 392023877778); // Delete data
$showStudentData->showListOfStudent($studentList); // Menampilkan isi array setelah delete data

echo "</center>";
