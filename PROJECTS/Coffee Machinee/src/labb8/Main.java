package machine;
import java.util.Scanner;
public class CoffeeMachine {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int water = 400,milk = 540,coffee_beans =120,disp_cups=9,money=550;
        for(;;){
            System.out.printf("%nWrite action (buy, fill, take, remaining, exit):%n");
            String action =scanner.next();
            System.out.println();
            if(new String(action).equals("exit")==true){
                break;
            }
            if( new String(action).equals("remaining")){
                printState(water,milk,coffee_beans,disp_cups,money);
            }
            if(new String(action).equals("buy")==true ){
                System.out.println("What do you want to buy? 1 - espresso, 2 - latte, 3 - cappuccino, back - to main menu: ");
                String t = scanner.next();
                if(new String(t).equals("back")==true ){
                    continue;
                }
                int type=Integer.parseInt(String.valueOf(t));;
                int ok=1;
                if(type==1){
                    if(water-250<0){System.out.println("Sorry, not enough water!"); ok=0;}
                    if(coffee_beans-16<0){System.out.println("Sorry, not enough coffee beans!"); ok=0;}
                    if(disp_cups<=0){System.out.println("Sorry, not enough disposable coups!"); ok=0;}
                    if(ok==1){
                        System.out.println("I have enough resources, making you a coffee!");
                        water -=250;
                        coffee_beans -=16;
                        disp_cups--;
                        money+=4;
                    }
                }
                else if(type==2){
                    if(water-350<0){System.out.println("Sorry, not enough water!"); ok=0;}
                    if(coffee_beans-20<0){System.out.println("Sorry, not enough coffee beans!"); ok=0;}
                    if(disp_cups<=0){System.out.println("Sorry, not enough disposable coups!"); ok=0;}
                    if(milk-75<0){System.out.println("Sorry, not enough milk!"); ok=0;}
                    if(ok==1){
                        System.out.println("I have enough resources, making you a coffee!");
                        water -=350;
                        milk-=75;
                        coffee_beans -=20;
                        disp_cups--;
                        money+=7;}
                }
                else if(type==3){
                    if(water-200<0){System.out.println("Sorry, not enough water!"); ok=0;}
                    if(coffee_beans-12<0){System.out.println("Sorry, not enough coffee beans!"); ok=0;}
                    if(disp_cups<=0){System.out.println("Sorry, not enough disposable coups!"); ok=0;}
                    if(milk-100<0){System.out.println("Sorry, not enough milk!"); ok=0;}
                    if(ok==1){
                        System.out.println("I have enough resources, making you a coffee!");
                        water -=200;
                        milk-=100;
                        coffee_beans -=12;
                        disp_cups--;
                        money+=6;
                    }
                }
            }
            if(new String(action).equals("take")==true){
                System.out.printf("I gave you %d%n",money);
                money=0;
            }
            if(new String(action).equals("fill")==true){
                System.out.println("Write how many ml of water do you want to add:");
                water+=scanner.nextInt();
                System.out.println("Write how many ml of milk do you want to add:");
                milk+=scanner.nextInt();
                System.out.println("Write how many grams of coffee beans do you want to add:");
                coffee_beans+=scanner.nextInt();
                System.out.println("Write how many disposable cups of coffee do you want to add:");
                disp_cups+=scanner.nextInt();
            }
        }
    }
    public static void printState(int water,int milk,int coffee_beans,int disp_cups,int money){
        System.out.println("The coffee machine has:");
        System.out.printf("%d of water%n",water);
        System.out.printf("%d of milk%n",milk);
        System.out.printf("%d of coffee beans%n",coffee_beans);
        System.out.printf("%d of disposable cups%n",disp_cups);
        if(money!=0)
            System.out.printf("$%d of money%n",money);
        else
            System.out.printf("%d of money%n",money);
    }
}