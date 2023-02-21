<?php

class Human // Membuat class Human (parent class)
{
    /* Membuat atribut berjenis protected */
    protected $identity; // Untuk menyimpan nama
    protected $name; // Untuk menyimpan NIM (ID number)
    protected $gender; // Untuk menyimpan jurusan

    /* Konstruktor */
    public function __construct($identity = 0, $name = '', $gender = '') // Membuat konstruktor dengan isian dari parameter
    {
        $this->identity = $identity;         // Meng-assign atribut identity dengan nilai dari parameter identity
        $this->name = $name; // Meng-assign atribut name dengan nilai dari parameter name
        $this->gender = $gender;       // Meng-assign atribut gender dengan nilai dari parameter gender
    }

    /* Setter dan Getter */
    public function setIdentity($identity) // Setter untuk atribut identity
    {
        $this->identity = $identity; // Meng-assign atribut identity dengan nilai dari parameter identity
    }

    public function setName($name) // Setter untuk atribut name
    {
        $this->name = $name; // Meng-assign atribut name dengan nilai dari parameter name
    }

    public function setGender($gender) // Setter untuk atribut gender
    {
        $this->gender = $gender; // Meng-assign atribut gender dengan nilai dari parameter gender
    }

    public function getIdentity() // Getter untuk atribut identity
    {
        return $this->identity; // Me-return nilai dari atribut identity
    }

    public function getName() // Getter untuk atribut name
    {
        return $this->name; // Me-return nilai dari atribut name
    }

    public function getGender() // Getter untuk atribut gender
    {
        return $this->gender; // Me-return nilai dari atribut gender
    }

    /* Destuktor */
    public function __destruct()
    {
    }
}
