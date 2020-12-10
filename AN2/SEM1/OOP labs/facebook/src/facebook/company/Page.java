package facebook.company;

public class Page {
    private String name;
    private String domain;
    private String description;
    private User admin;

    public Page(String name){
        this.name=name;
    }

    public User getAdmin() {
        return admin;
    }

    public void setAdmin(User admin) {
        this.admin = admin;
    }

    public Page(String name, String domain){
        this.name=name;
        this.domain=domain;
    }

    public Page(String name, String domain, String description) {
        this.name = name;
        this.domain = domain;
        this.description = description;
    }


    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDomain() {
        return this.domain;
    }

    public void setDomain(String domain) {
        this.domain = domain;
    }

    public String getDescription() {
        return this.description;
    }

    public void setDescription(String description) {
        this.description =description;
    }

}
