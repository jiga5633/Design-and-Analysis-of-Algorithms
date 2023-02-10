import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;



public class LList {


    public static void main(String[] args) throws FileNotFoundException {

        Scanner inFile = new Scanner(new File(args[0]));

        //FileInputStream inFile = null;
        PrintWriter outFile = new PrintWriter(args[1]);
        PrintWriter deBugFile = new PrintWriter(args[2]);
        //PrintWriter outFile1 = null;

        if (args.length != 3) {
            System.err.println("Error: Not enough arguments provided. Please provide input, output, and debug files.");
            System.exit(1);
        }

        //String aLine;
        ArrayList<String> al = new ArrayList<String>();

        while(inFile.hasNext()) {
            String[] file = inFile.nextLine().split("\t");
            file.setWord(arg[0]);
                /*if(!aLine.trim().startsWith("-")&& aLine.trim().length() >0 ){
                    al.add(aLine);

                }*/
            al.add(inFile.next());
        }


            // Sorting the ArrayList
        Collections.sort(al);

             // outWrite

        /*for(String s:al){
            System.out.println(s);
            outFile.write(s + '\t');
        }*/

        ListNode listHead = new ListNode("dummy");
        Scanner inFile2 = new Scanner(new File(args[0]));
        constructLL(listHead, inFile2, deBugFile);
        printList(listHead, outFile);

        ListNode middleNode = findMiddleNode(listHead, deBugFile);


        if (middleNode != null) {
            outFile.println("The word in the middle of the list is: " + middleNode.data);
        }
    }





    private static void constructLL(ListNode listHead, Scanner input, PrintWriter deBugFile) {
        //Scanner reader = new Scanner(new InputStreamReader(outFile));
        //String line;


        deBugFile.write("In constructLL method \n");


        ListNode currentNode = listHead;

        while (input.hasNext()) {

                    ListNode newNode = new ListNode(input.next());

                    listInsert(currentNode, newNode, deBugFile);
                    printList(currentNode, deBugFile);
                    currentNode = currentNode.next;
                }


    }



    private static void listInsert(ListNode listHead, ListNode newNode, PrintWriter deBugFile) {
        deBugFile.println("In listInsert method");

        ListNode spot = findSpot(listHead, newNode);
        deBugFile.println("Returns from findSpot where Spot.data is " + spot.data);



        newNode.next = spot.next;

        spot.next = newNode;



    }




    private static ListNode findSpot(ListNode listHead, ListNode newNode) {
        ListNode spot = listHead;

        while (spot.next != null && spot.next.data.compareTo(newNode.data) < 0) {
            spot = spot.next;
        }

        return spot;
    }

    private static void printList(ListNode listHead, PrintWriter File) {
        ListNode currentNode = listHead.next;

        File.print("listHead -> (" + "dummy" + ", " + currentNode.data + ")");
        int count =0;
        while (currentNode.next != null ) {
            // = currentNode.next;

            count ++;
            if(count % 5 != 0) {
            File.write( " -> (" + currentNode.data + ", " + currentNode.next.data + ")");
                currentNode = currentNode.next;
            }else {
                File.write( " -> (" + currentNode.data + ", " + currentNode.next.data + ")");
                File.write(" \n\n");
                currentNode = currentNode.next;
            }
        }

        File.println(" -> NULL");
    }


    private static ListNode findMiddleNode(ListNode listHead, PrintWriter deBugFile) {
        deBugFile.println("\n\n\nIn findMiddleNode method");
        ListNode walker1 = listHead.next;
        ListNode walker2 = listHead.next;

        while (walker2 != null && walker2.next != null) {
            walker1 = walker1.next;
            walker2 = walker2.next.next;
            deBugFile.println("walker1's data is " + walker1.data);
        }

        return walker1;
    }
}



