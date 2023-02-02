
import java.io.*;
/*
@Name :Gangjun Jiang
@Student ID :23795633
@date 1/31/2023
@file name : JiangG_Project01_Main
* */
class JiangG_Project02_Main {

    private static void processString(BufferedReader inFile2, BufferedWriter outFile2) throws IOException {
        String line;
        int count = 0;
        int total =0;
        outFile2.write("In processInt method:\n");
        outFile2.newLine();

        while ((line = inFile2.readLine()) != null) {
            String[] words = line.split(" ");
            for (int i = 0; i < words.length; i++) {
                outFile2.write(words[i] + " ");
                count++;
                if (count % 5 == 0) {
                    outFile2.newLine();
                    count = 0;
                } total++;
            }
        }
        outFile2.write( "\n the total string count is " + total);
    }
    public static void main(String[] args) {
        try {
// Open the input text file

                File inFile2 = new File(args[0]);
                //File inFile2 = new File("C:\\Users\\jjram\\IdeaProjects\\JiangG_Project02\\src\\data2.txt");
                BufferedReader inFile = new BufferedReader(new FileReader(inFile2));
                // Open the output text file
                File outFile2 = new File(args[1]);
                //File outFile2 = new File("C:\\Users\\jjram\\IdeaProjects\\JiangG_Project02\\src\\outFile2.txt");
                BufferedWriter outFile = new BufferedWriter(new FileWriter(outFile2));


                processString(inFile, outFile);

                inFile.close();
                outFile.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}