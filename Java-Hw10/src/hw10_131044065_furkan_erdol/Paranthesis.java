package hw10_131044065_furkan_erdol;

/**
 * HW010_131044065_Furkan_Erdol / Created on 08/01/2016 by Furkan Erdol /
 * Paranthesis class / Holds paranthesis
 * @author furkan
 */
public class Paranthesis extends Expression {

    private char paranthes;

    /**
     *
     * @param newParanthes
     */
    public Paranthesis(char newParanthes) {
        paranthes = newParanthes;
    }

    /**
     *
     */
    public Paranthesis() {
        paranthes = '(';
    }

    /**
     *
     * @return
     */
    public char getParanthesis() {
        return paranthes;
    }

    /**
     *
     * @param newParanthes
     */
    public void setParanthesis(char newParanthes) {
        paranthes = newParanthes;
    }

}
