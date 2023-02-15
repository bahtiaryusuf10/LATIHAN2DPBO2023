public class CivitasAcademica extends Human {
    protected String university;
    protected String emailEdu;

    // Constructor
    public CivitasAcademica() {
        this.university = "";
        this.emailEdu = "";
    }

    // another constructor with parameter
    public CivitasAcademica(String university, String emailEdu) {
        this.university = university;
        this.emailEdu = emailEdu;
    }

    /* Getter dan Setter */
    public void setUniversity(String university) {
        this.university = university;
    }

    public void setEmailEdu(String emailEdu) {
        this.emailEdu = emailEdu;
    }

    public String getUniversity() {
        return this.university;
    }

    public String getEmailEdu() {
        return this.emailEdu;
    }
}