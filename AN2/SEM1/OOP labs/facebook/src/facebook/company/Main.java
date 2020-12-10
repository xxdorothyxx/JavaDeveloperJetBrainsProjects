package facebook.company;
import java.util.Iterator;

public class Main {

    public static void main(String[] args) {

        User user1 = new User("Ferb", "ferbFletcher@yahoo.com", "Ferb Fletcher", "single");
        User user2 = new User("Phineas", "phineasFlynn@yahoo.com", "Phineas Flynn", "in a relationship");
        User user3 = new User("Dr.Doofenshmirtz", "heinzDoofenshmirtz@yahoo.com", "Heinz Doofenshmirtz", "single");
        User user4 = new User("Candace", "candaceFlynn@yahoo.com", "Candace Flynn", "in a relationship");
        User user5 = new User("Isabella", "isabellaShapiro@yahoo.com", "Isabella Shapiro", "in a relationship");
        User user6 = new User("Jeremy", "jeremyJohnson@yahoo.com", "Jeremy Johnson", "in a relationship");
        User user7 = new User("Linda", "lindaFlynnFletcher@yahoo.com", "Linda Flynn Fletcher", "married");
        User user8 = new User("Lawrence", "lawrenceFletcher@yahoo.com", "Lawrence Fletcher", "married");
        User user9 = new User("Perry", "perryThePlatypus@yahoo.com", "Perry The Platypus", "single");

        Page page1 = new Page("Vote NOW", "politics", "last news about the voting!!");
        Page page2 = new Page("How To Be A Good Parent:financial education", "economy", "teach your kid about money");
        Page page3 = new Page("move and live Healthy", "sport", "join us to have a more active life");
        Page page4 = new Page("CanCan", "entertainment", "find out the buzz");
        Page page5 = new Page("Nutrition for Platypus", "pets", "make sure your platypus is healthy and happy!");

        page1.setAdmin(user1);
        page2.setAdmin(user7);
        page3.setAdmin(user5);
        page4.setAdmin(user4);
        page5.setAdmin(user2);

        user1.getlikedPages().add(page1);
        user1.getlikedPages().add(page3);
        user2.getlikedPages().add(page2);
        user2.getlikedPages().add(page4);
        user3.getlikedPages().add(page3);
        user3.getlikedPages().add(page5);
        user4.getlikedPages().add(page2);
        user4.getlikedPages().add(page4);
        user5.getlikedPages().add(page5);
        user5.getlikedPages().add(page3);
        user6.getlikedPages().add(page2);
        user6.getlikedPages().add(page4);
        user7.getlikedPages().add(page1);
        user7.getlikedPages().add(page3);
        user8.getlikedPages().add(page2);
        user8.getlikedPages().add(page4);
        user9.getlikedPages().add(page3);
        user9.getlikedPages().add(page5);


        // we make an array list of friends for the user1
        user1.getFriends().add(user2);
        user1.getFriends().add(user5);
        user1.getFriends().add(user7);
        user1.getFriends().add(user8);
        user1.getFriends().add(user9);
        // we make an array list of friends for the user2
        user2.getFriends().add(user1);
        user2.getFriends().add(user5);
        user2.getFriends().add(user7);
        user2.getFriends().add(user8);
        user2.getFriends().add(user9);
        // we make an array list of friends for the user3
        user3.getFriends().add(user9);
        // we make an array list of friends for the user4
        user4.getFriends().add(user6);
        user4.getFriends().add(user7);
        user4.getFriends().add(user8);
        // we make an array list of friends for the user5
        user5.getFriends().add(user1);
        user5.getFriends().add(user2);
        // we make an array list of friends for the user6
        user6.getFriends().add(user4);
        // we make an array list of friends for the user7
        user7.getFriends().add(user1);
        user7.getFriends().add(user2);
        user7.getFriends().add(user4);
        user7.getFriends().add(user8);
        user7.getFriends().add(user9);
        // we make an array list of friends for the user8
        user8.getFriends().add(user1);
        user8.getFriends().add(user2);
        user8.getFriends().add(user4);
        user8.getFriends().add(user7);
        user8.getFriends().add(user9);
        // we make an array list of friends for the user9
        user9.getFriends().add(user1);
        user9.getFriends().add(user2);
        user9.getFriends().add(user3);
        user9.getFriends().add(user7);
        user9.getFriends().add(user8);
        //request 1)
        System.out.println("Friends that are single:");
        for (int i = 0; i < user9.getFriends().size(); ++i) {
            User friend = (User) user9.getFriends().get(i);
            if ((friend.getStatus()).equals("single")) {
                System.out.println(friend.getFullname());
            }
        }
        //request 2)
        if (page1.getDomain() == "economy" || page1.getDomain() == "politics") {
            page1 = null;
        }
        if (page2.getDomain() == "economy" || page2.getDomain() == "politics") {
            page2 = null;
        }
        if (page3.getDomain() == "economy" || page3.getDomain() == "politics") {
            page3 = null;
        }
        if (page4.getDomain() == "economy" || page4.getDomain() == "politics") {
            page1 = null;
        }
        if (page5.getDomain() == "economy" || page5.getDomain() == "politics") {
            page1 = null;
        }
        //request 3)
        isFriendOfAdminOfLikedPage(user9);
        System.out.println("Updated friends of most popular user:");
        for (int i = 0; i < user9.getFriends().size(); ++i) {
            User friend = (User) user9.getFriends().get(i);
            System.out.println(friend.getFullname());
        }
        //request 4)
        System.out.println("Friends admins of liked pages:");
        for (int i = 0; i < user9.getlikedPages().size(); ++i) {
            Page temp = user9.getlikedPages().get(i);
            for (int j = 0; j < user9.getFriends().size(); ++j) {
                User aux = user9.getFriends().get(j);
                if (aux == temp.getAdmin()) {
                    System.out.println(aux.getFullname());
                }
            }


        }
    }

    public static void isFriendOfAdminOfLikedPage(User u1) {
        for (int i = 0; i < u1.getlikedPages().size(); ++i) {
            int ok=0;
            Page temp = u1.getlikedPages().get(i);
            for (int j = 0; j < u1.getFriends().size(); ++j) {
                User aux = u1.getFriends().get(j);
                if (aux == temp.getAdmin()) {
                    ok=1;
                }
            }
            if(ok==0){
                u1.getFriends().add(temp.getAdmin());
            }
        }
    }

}


