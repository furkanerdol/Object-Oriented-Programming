package hw10_131044065_furkan_erdol;

import java.util.Scanner;

/**
 * HW010_131044065_Furkan_Erdol / Created on 08/01/2016 by Furkan Erdol / Test
 * class
 *
 * @author furkan
 */
public class test {

    /**
     * Test Expression class Takes expressions from user and evaluate them then
     * print screen result
     *
     * @param args
     */
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        Expression expression = new Expression();

        System.out.println("Enter your expression element");
        String input = scanner.nextLine();

        // Try block for invalid inputs
        try {

            while (input.charAt(0) != '=') {

                if (input.charAt(0) == '+' || input.charAt(0) == '-' || input.charAt(0) == '*' || input.charAt(0) == '/') {

                    expression.addExpressionElement(new Operator(input.charAt(0)));

                } else if (input.charAt(0) == '(' || input.charAt(0) == ')') {

                    expression.addExpressionElement(new Paranthesis(input.charAt(0)));
                } else {

                    int m = Integer.parseInt(input);

                    expression.addExpressionElement(new Operand(m));

                }

                System.out.println("Enter your expression element");
                input = scanner.nextLine();
            }

            System.out.printf("\nInput:\n\n%s\n", expression);
            System.out.printf("\nOutput:\n\n1: %s\n\n", expression);

            expression.evaluate();

        } catch (Exception exception) {
            System.out.printf("\nInvalid input!\n");
        }

    }

}
