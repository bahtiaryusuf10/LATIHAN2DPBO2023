// class deklarasi. Untuk java, huruf pertama harus kapital
public class Human {
    // private attributes
    protected int identity;
    protected String name;
    protected char gender;

    // Constructors

    // Constructor. Take note that it doesn't have any return type
    public Human() {
        this.identity = 0;
        this.name = "";
        this.gender = '-';
    }

    // another constructor with parameter
    public Human(int identity, String name, char gender) {
        this.identity = identity;
        this.name = name;
        this.gender = gender;
    }

    /* Getter dan Setter */

    // Get identity
    public int getIdentity() {
        return this.identity;
    }

    // set identity
    public void setIdentity(int identity) {
        this.identity = identity;
    }

    // Get name
    public String getName() {
        return this.name;
    }

    // set name
    public void setName(String name) {
        this.name = name;
    }

    // Get gender
    public char getGender() {
        return this.gender;
    }

    // set gender
    public void setGender(char gender) {
        this.gender = gender;
    }
}
