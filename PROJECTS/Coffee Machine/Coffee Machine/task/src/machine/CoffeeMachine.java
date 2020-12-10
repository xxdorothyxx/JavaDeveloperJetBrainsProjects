package machine;
import java.util.Scanner;
public class CoffeeMachine {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int water = 400,milk = 540,coffee_beans =120,disp_cups=9,money=550;
        System.out.printf("Write action (buy, fill, take, remaining, exit):%n");
        String action = scanner.next();
        while(!new String(action).equals("exit")){
            if( new String(action).equals("remaining")){
                printState(water,milk,coffee_beans,disp_cups,money);
            }
            else if(new String(action).equals("buy")==true){
                System.out.println("What do you want to buy? 1 - espresso, 2 - latte, 3 - cappuccino, back - to main menu: ");
                int type = scanner.nextInt();
                switch(type){
                    case 1:
                        water -=250;
                        coffee_beans -=16;
                        disp_cups--;
                        money+=4;
                        break;
                    case 2:
                        water -=350;
                        milk-=75;
                        coffee_beans -=20;
                        disp_cups--;
                        money+=7;
                        break;
                    case 3:
                        water -=200;
                        milk-=100;
                        coffee_beans -=12;
                        disp_cups--;
                        money+=6;
                        break;
                }
                if(water<=0) { System.out.println("Sorry, not enough water!"); }
                else if (milk<=0) { System.out.println("Sorry, not enough milk!"); }
                else if(coffee_beans<=0) {System.out.println("Sorry, not enough coffee beans!");}
                else if (disp_cups<=0) {System.out.println("Sorry, not enough disposable coups!");}
                else {System.out.println("I have enough resources, making you a coffee!");}
            }
            else if(new String(action).equals("take")==true){
                System.out.printf("I gave you %d%n",money);
                money=0;
            }
            else if(new String(action).equals("fill")==true){
                System.out.println("Write how many ml of water do you want to add:");
                water+=scanner.nextInt();
                System.out.println("Write how many ml of milk do you want to add:");
                milk+=scanner.nextInt();
                System.out.println("Write how many grams of coffee beans do you want to add:");
                coffee_beans+=scanner.nextInt();
                System.out.println("Write how many disposable cups of coffee do you want to add:");
                disp_cups+=scanner.nextInt();
            }
            System.out.printf("%nWrite action (buy, fill, take, remaining, exit):%n");
            action = scanner.next();
            System.out.println();
        }
    }
    public static void printState(int water,int milk,int coffee_beans,int disp_cups,int money){
        System.out.println("The coffee machine has:");
        System.out.printf("%d of water%n",water);
        System.out.printf("%d of milk%n",milk);
        System.out.printf("%d of coffee beans%n",coffee_beans);
        System.out.printf("%d of disposable cups%n",disp_cups);
        System.out.printf("$%d of money%n",money);
    }
}
