//package tictactoe;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i,j;
        char[][] ttt = new char[4][4];
        for(i=1;i<=3;i++){
            for(j=0;j<=3;j++){
                ttt[i][j]=' ';
            }
        }
        printGame(ttt);
        int ok_win=0, ok_draw=0,contor=0;
        while(ok_win==0 && ok_draw==0){
            char c1,c2;
            int coord1,coord2,ok_input=0;
            String coord;
            coord = scanner.nextLine();
            c1=coord.charAt(0);
            c2=coord.charAt(2);
            while(Character.isLetter(c1)==true || Character.isLetter(c2)==true){
                System.out.println("You should enter numbers!");
                coord = scanner.nextLine();
                c1=coord.charAt(0);
                c2=coord.charAt(2);
            }
            coord1 = Character.getNumericValue(c1);
            coord2 = Character.getNumericValue(c2);
            int cont;
            while(ok_input!=1){
                cont=0;
                if(coord1 >3  || coord2>3){
                    System.out.println("Coordinates should be from 1 to 3!");
                    cont=1;
                }
                else if( cont == 0 && ttt[coord1][coord2]!=' '){
                    System.out.println("This cell is occupied! Choose another one!");
                    cont=1;
                }
                if(cont ==0){
                    ok_input=1;}
                else{
                    coord = scanner.nextLine();
                    c1=coord.charAt(0) ;
                    c2=coord.charAt(2) ;
                    coord1 = Character.getNumericValue(c1);
                    coord2 = Character.getNumericValue(c2);

                }
            }

            if(contor%2==0){
                contor++;
                ttt[coord1][coord2] = 'X';}
            else{
                ttt[coord1][coord2] = 'O';
                contor++;
            }
            printGame(ttt);
            int ok_X=0,ok_O=0;;
            if((ttt[1][3]=='X'&& ttt[1][2]=='X'&& ttt[1][1]=='X')
                    || (ttt[2][3]=='X'&& ttt[2][2]=='X'&& ttt[2][1]=='X')
                    || (ttt[3][3]=='X'&& ttt[3][2]=='X'&& ttt[3][1]=='X')
                    || (ttt[1][3]=='X'&& ttt[2][3]=='X'&& ttt[3][3]=='X')
                    || (ttt[1][2]=='X'&& ttt[2][2]=='X'&& ttt[3][2]=='X')
                    || (ttt[1][1]=='X'&& ttt[2][1]=='X'&& ttt[3][1]=='X')
                    || (ttt[3][3]=='X'&& ttt[2][2]=='X'&& ttt[1][1]=='X')
                    || (ttt[1][3]=='X'&& ttt[2][2]=='X'&& ttt[3][1]=='X')){
                ok_X=1;
                System.out.println("X wins");
            }
            if((ttt[1][3]=='O'&& ttt[1][2]=='O'&& ttt[1][1]=='O')
                    || (ttt[2][3]=='O'&& ttt[2][2]=='O'&& ttt[2][1]=='O')
                    || (ttt[3][3]=='O'&& ttt[3][2]=='O'&& ttt[3][1]=='O')
                    || (ttt[1][3]=='O'&& ttt[2][3]=='O'&& ttt[3][3]=='O')
                    || (ttt[1][2]=='O'&& ttt[2][2]=='O'&& ttt[3][2]=='O')
                    || (ttt[1][1]=='O'&& ttt[2][1]=='O'&& ttt[3][1]=='O')
                    || (ttt[3][3]=='O'&& ttt[2][2]=='O'&& ttt[1][1]=='O')
                    || (ttt[1][3]=='O'&& ttt[2][2]=='O'&& ttt[3][1]=='O')){
                ok_O=1;
                System.out.println("O wins");
            }
            if(ok_O==1 || ok_X==1){
                ok_win=1;
            }
            else if(contor==9){
                ok_draw=1;
                System.out.println("Draw");
            }
        }
        return;
    }

    public static void printGame(char ttt[][]) {
        System.out.println("---------");
        System.out.println("| "+ttt[1][3]+" "+ttt[2][3]+" "+ttt[3][3]+" |");
        System.out.println("| "+ttt[1][2]+" "+ttt[2][2]+" "+ttt[3][2]+" |");
        System.out.println("| "+ttt[1][1]+" "+ttt[2][1]+" "+ttt[3][1]+" |");
        System.out.println("---------");
    }
}