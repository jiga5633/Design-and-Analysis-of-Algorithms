
import java.io.*;

class JiangG_Project01_Main {

    private static void processInt(BufferedReader inFile1, BufferedWriter outFile1) throws IOException {
        String line;
        int count = 0;
        int total =0;
        outFile1.write("In processInt method :");
        outFile1.newLine();

        while ((line = inFile1.readLine()) != null) {
            String[] words = line.split(" ");
            for (int i = 0; i < words.length; i++) {
                outFile1.write(words[i] + " ");

                count++;
                if (count % 5 == 0) {
                    outFile1.newLine();
                    count = 0;
                }
                total ++;
            }

        }
        outFile1.write("\nThe total string count is " + total );
    }
    public static void main(String[] args) {
        try {
// Open the input text file
           //File inFile1 = new File(args[0]);
             File inFile1 = new File("C:\\Users\\jjram\\IdeaProjects\\JiangG_Project01\\data1.txt");
            BufferedReader inFile = new BufferedReader(new FileReader(inFile1));
            // Open the output text file
            //File outFile1 = new File(args[1]);
             File outFile1 = new File("C:\\Users\\jjram\\IdeaProjects\\JiangG_Project01\\outFile1.txt");
            BufferedWriter outFile = new BufferedWriter(new FileWriter(outFile1));


            processInt(inFile, outFile);

            inFile.close();
            outFile.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}