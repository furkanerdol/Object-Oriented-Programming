package hw10_131044065_furkan_erdol;

/**
 * HW010_131044065_Furkan_Erdol / Created on 08/01/2016 by Furkan Erdol /
 * Expression class / Holds expression elements / Operates on expressions
 *
 * @author furkan
 */
public class Expression {

    private Expression[] expressionElements;

    /**
     *
     */
    public Expression() {

        expressionElements = new Expression[0];

    }

    /**
     *
     * @param newExpressionElements
     */
    public Expression(Expression... newExpressionElements){

        expressionElements = new Expression[newExpressionElements.length];

        for (int i = 0; i < newExpressionElements.length; ++i) {
            expressionElements[i] = newExpressionElements[i];
        }

    }

    /**
     * Returns expression elements array
     *
     * @return
     */
    public Expression[] getExpressionElements() {
        return expressionElements;
    }

    /**
     * Takes index and returns an element
     *
     * @param index
     * @return
     */
    public Expression getExpressionElement(int index) {
        return expressionElements[index];
    }

    /**
     * Takes index and element then sets it
     *
     * @param element
     * @param index
     */
    public void setExpressionElement(Expression element, int index) {
        expressionElements[index] = element;
    }

    /**
     * Takes an expression element and add it to expression elements array
     *
     * @param element
     * @throws Exception
     */
    public void addExpressionElement(Expression element){

        Expression[] elemArray = new Expression[getExpressionElements().length];

        for (int i = 0; i < getExpressionElements().length; ++i) {
            elemArray[i] = getExpressionElement(i);
        }

        expressionElements = new Expression[getExpressionElements().length + 1];

        for (int i = 0; i < getExpressionElements().length - 1; ++i) {
            expressionElements[i] = elemArray[i];
        }

        expressionElements[getExpressionElements().length - 1] = element;

        

    }

    // Checks whether parentheses in the expression elements array
    private int checkParanthes() {

        for (int i = 0; i < getExpressionElements().length; ++i) {
            if (getExpressionElement(i) instanceof Paranthesis) {
                return 0;
            }
        }

        return -1;
    }

    // Override toString method
    public String toString() {

        String formatted = "";

        Operand tempOperand;
        Operator tempOperator;
        Paranthesis tempParanthesis;

        int counter = 0;
        for (int i = 0; i < getExpressionElements().length; ++i) {
            if (getExpressionElement(i) instanceof Operand) {

                tempOperand = (Operand) getExpressionElement(i);

                if (i + 1 < getExpressionElements().length && !(getExpressionElement(i + 1) instanceof Operand)) {
                    formatted += String.format("%d ", tempOperand.getOperand());
                } else if (i == getExpressionElements().length - 1) {
                    formatted += String.format("%d ", tempOperand.getOperand());
                }

            } else if (getExpressionElement(i) instanceof Operator) {
                tempOperator = (Operator) getExpressionElement(i);
                formatted += String.format("%c ", tempOperator.getOperator());
            } else if (getExpressionElement(i) instanceof Paranthesis) {
                tempParanthesis = (Paranthesis) getExpressionElement(i);
                formatted += String.format("%c ", tempParanthesis.getParanthesis());
            }
        }

        return formatted;
    }

    /**
     * Evaluate expression
     * When invalid ranking throws an exception
     * @return
     */
    public Operand evaluate() throws Exception {

        
        for (int i = 0; i < getExpressionElements().length - 1; ++i) {
            if (getExpressionElement(i) instanceof Operand && getExpressionElement(i + 1) instanceof Operand) {
                throw new Exception();
            } else if (getExpressionElement(i) instanceof Operator && getExpressionElement(i + 1) instanceof Operator) {
                throw new Exception();
            } else if (getExpressionElement(i) instanceof Paranthesis && getExpressionElement(i + 1) instanceof Paranthesis) {
                throw new Exception();
            }
        }
           
        Expression tempElements = new Expression(getExpressionElements());

        int result = 0;

        Operator temporaryOperator = new Operator('i');
        Operator beforeTemporaryOperator = new Operator('i');

        Operator operator;
        Paranthesis paranthes;

        Operand beforeOperator, afterOperator;

        Operand singularResult;
        Operand pluralResult = new Operand();
        Operand temporaryResult = new Operand();
        Operand finalResult;

        int first = 0;
        int last = 0;

        int counter = 2;

        Operand resultOfParanthesis;

        int stopper = 0;

        // Evaluate in paranthesis
        while (tempElements.checkParanthes() == 0) {

            for (int i = 0; i < tempElements.getExpressionElements().length && stopper == 0; ++i) {

                if (tempElements.getExpressionElement(i) instanceof Paranthesis) {
                    paranthes = (Paranthesis) tempElements.getExpressionElement(i);

                    if (paranthes.getParanthesis() == '(') {

                        first = i + 1;
                    } else if (paranthes.getParanthesis() == ')') {
                        last = i - 1;
                        resultOfParanthesis = tempElements.evaluateBetweenTheTwoIndexes(first, last);
                        for (int k = first - 1; k < last + 2; ++k) {
                            tempElements.setExpressionElement(resultOfParanthesis, k);
                        }
                        ++stopper;
                        System.out.printf("%d: %s\n\n", counter++, tempElements);
                    }

                }
            }

            stopper = 0;
        }

        // Evaluate * and / operation
        for (int i = 0; i < tempElements.getExpressionElements().length; ++i) {

            if (tempElements.getExpressionElement(i) instanceof Operator) {
                operator = (Operator) tempElements.getExpressionElement(i);
                if (operator.getOperator() == '*') {

                    if (temporaryOperator.getOperator() != '*' && temporaryOperator.getOperator() != '/') {

                        beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                        afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                        singularResult = new Operand(beforeOperator.getOperand() * afterOperator.getOperand());
                        tempElements.setExpressionElement(singularResult, i - 1);
                        tempElements.setExpressionElement(singularResult, i);

                        for (int j = i + 1; j < tempElements.getExpressionElements().length && tempElements.getExpressionElement(j) instanceof Operand; ++j) {
                            tempElements.setExpressionElement(singularResult, j);

                        }

                        for (int j = i - 1; j >= 0 && tempElements.getExpressionElement(j) instanceof Operand; --j) {
                            tempElements.setExpressionElement(singularResult, j);

                        }

                        temporaryResult.setOperand(singularResult.getOperand());
                        result = singularResult.getOperand();
                        System.out.printf("%d: %s\n\n", counter++, tempElements);
                    } else {

                        if (beforeTemporaryOperator.getOperator() == '+' || beforeTemporaryOperator.getOperator() == '-') {
                            pluralResult = new Operand(temporaryResult.getOperand());
                        }

                        beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                        afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                        pluralResult.setOperand(beforeOperator.getOperand() * afterOperator.getOperand());

                        tempElements.setExpressionElement(pluralResult, i - 1);
                        tempElements.setExpressionElement(pluralResult, i);
                        tempElements.setExpressionElement(pluralResult, i + 1);

                        tempElements.setExpressionElement(pluralResult, i - 2);
                        tempElements.setExpressionElement(pluralResult, i - 3);

                        result = pluralResult.getOperand();
                        System.out.printf("%d: %s\n\n", counter++, tempElements);

                    }

                } else if (operator.getOperator() == '/') {

                    if (temporaryOperator.getOperator() != '*' && temporaryOperator.getOperator() != '/') {

                        beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                        afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                        singularResult = new Operand(beforeOperator.getOperand() / afterOperator.getOperand());

                        tempElements.setExpressionElement(singularResult, i - 1);
                        tempElements.setExpressionElement(singularResult, i);

                        for (int j = i + 1; j < tempElements.getExpressionElements().length && tempElements.getExpressionElement(j) instanceof Operand; ++j) {
                            tempElements.setExpressionElement(singularResult, j);

                        }

                        for (int j = i - 1; j >= 0 && tempElements.getExpressionElement(j) instanceof Operand; --j) {
                            tempElements.setExpressionElement(singularResult, j);

                        }

                        temporaryResult.setOperand(singularResult.getOperand());
                        result = singularResult.getOperand();
                        System.out.printf("%d: %s\n\n", counter++, tempElements);
                    } else {

                        if (beforeTemporaryOperator.getOperator() == '+' || beforeTemporaryOperator.getOperator() == '-') {
                            pluralResult = new Operand(temporaryResult.getOperand());
                        }

                        beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                        afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                        pluralResult.setOperand(beforeOperator.getOperand() / afterOperator.getOperand());

                        tempElements.setExpressionElement(pluralResult, i - 1);
                        tempElements.setExpressionElement(pluralResult, i);
                        tempElements.setExpressionElement(pluralResult, i + 1);

                        tempElements.setExpressionElement(pluralResult, i - 2);
                        tempElements.setExpressionElement(pluralResult, i - 3);

                        result = pluralResult.getOperand();
                        System.out.printf("%d: %s\n\n", counter++, tempElements);
                    }

                }

                beforeTemporaryOperator = temporaryOperator;
                temporaryOperator = operator;
            }

        }

        // Evaluate + and - operation
        for (int i = 0; i < tempElements.getExpressionElements().length; ++i) {

            if (tempElements.getExpressionElement(i) instanceof Operator) {
                operator = (Operator) tempElements.getExpressionElement(i);
                if (operator.getOperator() == '+') {
                    beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                    afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                    finalResult = new Operand(beforeOperator.getOperand() + afterOperator.getOperand());
                    beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                    afterOperator = (Operand) tempElements.getExpressionElement(i + 1);

                    beforeOperator.setOperand(finalResult.getOperand());
                    afterOperator.setOperand(finalResult.getOperand());

                    tempElements.setExpressionElement(finalResult, i);
                    result = finalResult.getOperand();
                    System.out.printf("%d: %s\n\n", counter++, tempElements);
                } else if (operator.getOperator() == '-') {
                    beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                    afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                    finalResult = new Operand(beforeOperator.getOperand() - afterOperator.getOperand());
                    beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                    afterOperator = (Operand) tempElements.getExpressionElement(i + 1);

                    beforeOperator.setOperand(finalResult.getOperand());
                    afterOperator.setOperand(finalResult.getOperand());

                    tempElements.setExpressionElement(finalResult, i);
                    result = finalResult.getOperand();
                    System.out.printf("%d: %s\n\n", counter++, tempElements);
                }
            }

        }

        Operand resultOperand;

        resultOperand = (Operand) tempElements.getExpressionElement(tempElements.getExpressionElements().length - 1);

        return resultOperand;

    }

    /**
     * Takes two index first and last then evuluate between them
     *
     * @param firstIndex
     * @param lastIndex
     * @return
     */
    public Operand evaluateBetweenTheTwoIndexes(int firstIndex, int lastIndex) {

        Expression tempElements = new Expression(getExpressionElements());

        int result = 0;

        Operator temporaryOperator = new Operator('i');
        Operator beforeTemporaryOperator = new Operator('i');

        Operator operator;

        Operand beforeOperator, afterOperator;

        Operand singularResult;
        Operand pluralResult = new Operand();
        Operand temporaryResult = new Operand();
        Operand finalResult;

        // Evaluate * and / operation
        for (int i = firstIndex; i < lastIndex; ++i) {

            if (tempElements.getExpressionElement(i) instanceof Operator) {
                operator = (Operator) tempElements.getExpressionElement(i);
                if (operator.getOperator() == '*') {

                    if (temporaryOperator.getOperator() != '*' && temporaryOperator.getOperator() != '/') {

                        beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                        afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                        singularResult = new Operand(beforeOperator.getOperand() * afterOperator.getOperand());
                        tempElements.setExpressionElement(singularResult, i - 1);
                        tempElements.setExpressionElement(singularResult, i);

                        for (int j = i + 1; j < tempElements.getExpressionElements().length && tempElements.getExpressionElement(j) instanceof Operand; ++j) {
                            tempElements.setExpressionElement(singularResult, j);

                        }

                        for (int j = i - 1; j >= 0 && tempElements.getExpressionElement(j) instanceof Operand; --j) {
                            tempElements.setExpressionElement(singularResult, j);

                        }

                        temporaryResult.setOperand(singularResult.getOperand());
                        result = singularResult.getOperand();

                    } else {

                        if (beforeTemporaryOperator.getOperator() == '+' || beforeTemporaryOperator.getOperator() == '-') {
                            pluralResult = new Operand(temporaryResult.getOperand());
                        }

                        beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                        afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                        pluralResult.setOperand(beforeOperator.getOperand() * afterOperator.getOperand());

                        tempElements.setExpressionElement(pluralResult, i - 1);
                        tempElements.setExpressionElement(pluralResult, i);
                        tempElements.setExpressionElement(pluralResult, i + 1);

                        tempElements.setExpressionElement(pluralResult, i - 2);
                        tempElements.setExpressionElement(pluralResult, i - 3);

                        result = pluralResult.getOperand();

                    }

                } else if (operator.getOperator() == '/') {

                    if (temporaryOperator.getOperator() != '*' && temporaryOperator.getOperator() != '/') {

                        beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                        afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                        singularResult = new Operand(beforeOperator.getOperand() / afterOperator.getOperand());

                        tempElements.setExpressionElement(singularResult, i - 1);
                        tempElements.setExpressionElement(singularResult, i);

                        for (int j = i + 1; j < tempElements.getExpressionElements().length && tempElements.getExpressionElement(j) instanceof Operand; ++j) {
                            tempElements.setExpressionElement(singularResult, j);

                        }

                        for (int j = i - 1; j >= 0 && tempElements.getExpressionElement(j) instanceof Operand; --j) {
                            tempElements.setExpressionElement(singularResult, j);

                        }

                        temporaryResult.setOperand(singularResult.getOperand());
                        result = singularResult.getOperand();
                    } else {

                        if (beforeTemporaryOperator.getOperator() == '+' || beforeTemporaryOperator.getOperator() == '-') {
                            pluralResult = new Operand(temporaryResult.getOperand());
                        }

                        beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                        afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                        pluralResult.setOperand(beforeOperator.getOperand() / afterOperator.getOperand());

                        tempElements.setExpressionElement(pluralResult, i - 1);
                        tempElements.setExpressionElement(pluralResult, i);
                        tempElements.setExpressionElement(pluralResult, i + 1);

                        tempElements.setExpressionElement(pluralResult, i - 2);
                        tempElements.setExpressionElement(pluralResult, i - 3);

                        result = pluralResult.getOperand();

                    }

                }

                beforeTemporaryOperator = temporaryOperator;
                temporaryOperator = operator;
            }

        }

        // Evaluate + and - operation
        for (int i = firstIndex; i < lastIndex; ++i) {

            if (tempElements.getExpressionElement(i) instanceof Operator) {
                operator = (Operator) tempElements.getExpressionElement(i);
                if (operator.getOperator() == '+') {
                    beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                    afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                    finalResult = new Operand(beforeOperator.getOperand() + afterOperator.getOperand());
                    beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                    afterOperator = (Operand) tempElements.getExpressionElement(i + 1);

                    beforeOperator.setOperand(finalResult.getOperand());
                    afterOperator.setOperand(finalResult.getOperand());

                    tempElements.setExpressionElement(finalResult, i);
                    result = finalResult.getOperand();
                } else if (operator.getOperator() == '-') {
                    beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                    afterOperator = (Operand) tempElements.getExpressionElement(i + 1);
                    finalResult = new Operand(beforeOperator.getOperand() - afterOperator.getOperand());
                    beforeOperator = (Operand) tempElements.getExpressionElement(i - 1);
                    afterOperator = (Operand) tempElements.getExpressionElement(i + 1);

                    beforeOperator.setOperand(finalResult.getOperand());
                    afterOperator.setOperand(finalResult.getOperand());

                    tempElements.setExpressionElement(finalResult, i);
                    result = finalResult.getOperand();
                }
            }

        }

        Operand resultOperand = new Operand(result);

        return resultOperand;
    }

}
