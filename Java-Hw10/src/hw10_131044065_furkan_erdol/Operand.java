package hw10_131044065_furkan_erdol;

/**
 * HW010_131044065_Furkan_Erdol / Created on 08/01/2016 by Furkan Erdol /
 * Operand class / Holds operands
 * @author furkan
 */
public class Operand extends Expression {

    private int operand;

    /**
     *
     * @param newOperand
     */
    public Operand(int newOperand) {
        operand = newOperand;
    }

    /**
     *
     */
    public Operand() {

    }

    /**
     *
     * @return
     */
    public int getOperand() {
        return operand;
    }

    /**
     *
     * @param newOperand
     */
    public void setOperand(int newOperand) {
        operand = newOperand;
    }

}
