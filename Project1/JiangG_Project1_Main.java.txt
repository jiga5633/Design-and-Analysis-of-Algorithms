import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
/*
@Name :Gangjun Jiang
@Student ID :23795633
@date 2/8/2023
@file name : JiangG_Project1_Main
* */
class ListNode {
    String data;

    ListNode next;

    ListNode(String data) {

        this.data = data;

        this.next = null;
    }


}




public class JiangG_Project1_Main {


    private static ListNode listHead = null;
    private static ListNode middleNode = null;
    private static String arrow = "-> ";
    //private static String arrow1 = ",";
    //private static String arrow2= ") ->";




    public static void main(String[] args) throws FileNotFoundException {
        Scanner inFile = new Scanner(new File(args[0]));
        PrintWriter outFile = new PrintWriter(args[1]);
        PrintWriter deBugFile = new PrintWriter(args[2]);

        listHead = new ListNode("Dummy");
        constructLL(listHead,inFile,deBugFile);
        printList(listHead,outFile);
        middleNode = findMiddleNode(listHead,deBugFile);
        if(middleNode != null){
            outFile.print("The word in the middle of list is: "+ middleNode.data );
        }
        inFile.close();
        outFile.close();
        deBugFile.close();

        /*ListNode cur = listHead;
        int n = 0;
        while (cur.next != null) {
            System.out.println(n + ": " + cur.data);
            cur = cur.next;
            n++;
        }*/
    }
    private static void constructLL(ListNode listHead,Scanner inFile, PrintWriter deBugFile) {
        deBugFile.println("In constructLL method");
        String word = "";

        while (inFile.hasNext()) {
            word = inFile.next();
            ListNode newNode = new ListNode(word);
            listInsert(listHead,newNode,deBugFile);
        }
    }
    private static void listInsert(ListNode listHead, ListNode newNode, PrintWriter deBugFile){
        deBugFile.println("In listInsert method");

        ListNode Spot = findSpot(listHead, newNode);

        deBugFile.println("Returns from findSpot where Spot.data is: " + Spot.data);

        newNode.next = Spot.next;
        Spot.next = newNode;
    }
    private static ListNode findSpot(ListNode listHead, ListNode newNode){

        ListNode Spot = listHead;
        while (Spot.next != null && Spot.next.data.compareToIgnoreCase(newNode.data) < 0) {
            Spot = Spot.next;
        }
        return Spot;
    }

    private static void printList(ListNode listHead, PrintWriter writeFile){
        ListNode current = listHead;
        writeFile.print("listHead ");

        while (current.next != null) {
            int count = 0;
            while (count < 5 && current.next != null) {
                if(count == 4 ){
                    writeFile.write("(" + current.data + "," + current.next.data + ")" );
                    current = current.next;
                    count++;
                }else {
                    writeFile.write("(" + current.data + "," + current.next.data + ")" + arrow);
                    current = current.next;
                    count++;
                }
            }
            if(current.next == null){
                writeFile.println("NULL");
            }
            writeFile.write("\n");
        }
    }

    private static ListNode findMiddleNode(ListNode listHead,PrintWriter deBugFile){
        deBugFile.println("\n\n\nIn findMiddleNode method");

        ListNode walker1 = listHead.next;
        ListNode walker2 = listHead.next;

        while(walker2 != null && walker2.next != null){
            walker1 = walker1.next;
            walker2 = walker2.next.next;
            deBugFile.println("walker1's data is " + walker1.data);
        }
        return walker1;
    }

}
