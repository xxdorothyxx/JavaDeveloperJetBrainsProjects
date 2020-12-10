package facebook.company;
import java.util.ArrayList;
public class User {
    private String username;
    private String email;
    private String fullname;
    private ArrayList<User> friends = new ArrayList();
    private ArrayList<Page> likedPages = new ArrayList();
    private String status;

    public User(){

    }

    public User(String username){
         this.username=username;
    }

    public User(String username,String email){
        this.username=username;
        this.email=email;
    }

    public User(String username,String email,String fullname){
        this.username=username;
        this.email=email;
        this.fullname=fullname;
    }

    public User(String username,String email,String fullname,String status){
        this.username=username;
        this.email=email;
        this.fullname=fullname;
        this.status=status;
    }

    public String getUsername(){
        return this.username;
    }

    public void setUsername(String username){
         this.username=username;
    }

    public String getStatus(){
        return this.status;
    }

    public void setStatus(String status){
        this.status=status;
    }

    public String getEmail(){
        return this.email;
    }

    public void setEmail(String email){
        this.email=email;
    }

    public String getFullname(){
        return this.fullname;
    }

    public void setFullname(String fullname){
        this.fullname=fullname;
    }

    public  ArrayList<User> getFriends(){
        return this.friends;
    }

    public void setFriends(ArrayList<User>friends){
        this.friends=friends;
    }

    public  ArrayList<Page> getlikedPages(){
        return this.likedPages;
    }

    public void setLikedPages(ArrayList<Page> likedPages){
        this.likedPages=likedPages;
    }

}
