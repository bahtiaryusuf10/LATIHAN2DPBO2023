<?php

require_once('Human.php'); // Require Class Human (parent class

class CivitasAcademic extends Human // Membuat class CivitasAcademic (child) yang mewarisi sifat dari class Human (parent class)
{
    /* Membuat atribut berjenis protected */
    protected $university; // Untuk menyimpan nama universitas
    protected $email; // Untuk menyimpan email mahasiswa

    /* Konstruktor */
    public function __construct($identity = 0, $name = '', $gender = '', $university = '', $email = '') // Membuat konstruktor dengan isian dari parameter
    {
        parent::__construct($identity, $name, $gender); // Memanggil konstruktor dari parent class
        $this->university = $university; // Meng-assign atribut university dengan nilai dari parameter university
        $this->email = $email; // Meng-assign atribut email dengan nilai dari parameter email
    }

    /* Setter dan Getter */
    public function setUniversity($university) // Setter untuk atribut university
    {
        $this->university = $university; // Meng-assign atribut university dengan nilai dari parameter university
    }

    public function setEmail($email) // Setter untuk atribut email
    {
        $this->email = $email; // Meng-assign atribut email dengan nilai dari parameter email
    }

    public function getUniversity() // Getter untuk atribut university
    {
        return $this->university; // Me-return nilai dari atribut university
    }

    public function getEmail() // Getter untuk atribut email
    {
        return $this->email; // Me-return nilai dari atribut email
    }

    /* Destuktor */
    public function __destruct()
    {
    }
}
