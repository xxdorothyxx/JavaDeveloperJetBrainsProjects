//package tictactoe;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
       /* String g = scanner.nextLine();
        System.out.println("---------");
        System.out.println("| "+g.charAt(0)+" "+g.charAt(1)+" "+g.charAt(2)+" |");
        System.out.println("| "+g.charAt(3)+" "+g.charAt(4)+" "+g.charAt(5)+" |");
        System.out.println("| "+g.charAt(6)+" "+g.charAt(7)+" "+g.charAt(8)+" |");
        System.out.println("---------");
        int i,j,ok_X=0,ok_O=0;
        if((g.charAt(0)=='X'&& g.charAt(3)=='X'&& g.charAt(6)=='X')
            || (g.charAt(1)=='X'&& g.charAt(4)=='X'&& g.charAt(7)=='X')
            || (g.charAt(2)=='X'&& g.charAt(5)=='X'&& g.charAt(8)=='X')
            || (g.charAt(0)=='X'&& g.charAt(1)=='X'&& g.charAt(2)=='X')
            || (g.charAt(3)=='X'&& g.charAt(4)=='X'&& g.charAt(5)=='X')
            || (g.charAt(6)=='X'&& g.charAt(7)=='X'&& g.charAt(8)=='X')
            || (g.charAt(2)=='X'&& g.charAt(4)=='X'&& g.charAt(6)=='X')
            || (g.charAt(0)=='X'&& g.charAt(4)=='X'&& g.charAt(8)=='X')){
            ok_X=1;
            }
            if((g.charAt(0)=='O'&& g.charAt(3)=='O'&& g.charAt(6)=='O')
            || (g.charAt(1)=='O'&& g.charAt(4)=='O'&& g.charAt(7)=='O')
            || (g.charAt(2)=='O'&& g.charAt(5)=='O'&& g.charAt(8)=='O')
            || (g.charAt(0)=='O'&& g.charAt(1)=='O'&& g.charAt(2)=='O')
            || (g.charAt(3)=='O'&& g.charAt(4)=='O'&& g.charAt(5)=='O')
            || (g.charAt(6)=='O'&& g.charAt(7)=='O'&& g.charAt(8)=='O')
            || (g.charAt(2)=='O'&& g.charAt(4)=='O'&& g.charAt(6)=='O')
            || (g.charAt(0)=='O'&& g.charAt(4)=='O'&& g.charAt(8)=='O')){
            ok_O=1;
            }
            int kO=0,kX=0;
            for(i=0;i<9;i++){
                if(g.charAt(i)=='O'){
                    kO++;
                }
                else if(g.charAt(i)=='X'){
                    kX++;
                }
            }
            if((ok_X==1 && ok_O==1) || (kO-kX>1) || (kX-kO)>1){
                System.out.print("Impossible");
                return;
            }
            if(ok_O==1){
                System.out.print("O wins");
                return;
            }
            if(ok_X==1){
                System.out.print("X wins");
                return;
            }
        if(kO+kX!=9){
            System.out.print("Game not finished");
        }
        else{
            System.out.print("Draw");
        }*/
        char[][] ttt = new char[4][4];
        ttt[1][3] = scanner.next().charAt(0);  ttt[2][3] = scanner.next().charAt(1);  ttt[3][3] = scanner.next().charAt(2);
        ttt[1][2] = scanner.next().charAt(3);  ttt[2][2] = scanner.next().charAt(4);  ttt[3][2] = scanner.next().charAt(5);
        ttt[1][1] = scanner.next().charAt(6);  ttt[2][1] = scanner.next().charAt(7);  ttt[3][1] =scanner.next().charAt(8);
        System.out.println("---------");
        System.out.println("| "+ttt[1][3]+" "+ttt[1][3]+" "+ttt[1][3]+" |");
        System.out.println("| "+ttt[1][3]+" "+ttt[1][3]+" "+ttt[1][3]+" |");
        System.out.println("| "+ttt[1][3]+" "+ttt[1][3]+" "+ttt[1][3]+" |");
        System.out.println("---------");
        return;
    }
}

