package hw10_131044065_furkan_erdol;

/**
 * HW010_131044065_Furkan_Erdol / Created on 08/01/2016 by Furkan Erdol /
 * Operator class / Holds operators
 *
 * @author furkan
 */
public class Operator extends Expression {

    private char operatorType;

    /**
     *
     * @param newOperatorType
     */
    public Operator(char newOperatorType) {

        operatorType = newOperatorType;
    }

    /**
     *
     * @return
     */
    public char getOperator() {
        return operatorType;
    }

    /**
     *
     * @param newOperatorType
     */
    public void setOperator(char newOperatorType) {
        operatorType = newOperatorType;
    }

}
