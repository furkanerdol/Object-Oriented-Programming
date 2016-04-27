package polynomial;

import java.lang.Math; // For pow method

/**
 * HW09_131044065_Furkan_Erdol / Created on 25/12/2015 by Furkan Erdol /
 * Polynomial class
 *
 * @author furkan
 */
public class Polynomial {

    private double[] coefficients; // Double array holds coefficients

    /**
     * Double array holds coefficients
     *
     * @param newCoefficients
     */
    public Polynomial(double... newCoefficients) {

        coefficients = new double[newCoefficients.length];

        for (int i = 0; i < newCoefficients.length; ++i) {
            coefficients[i] = newCoefficients[newCoefficients.length - i - 1];
        }

    }

    /**
     *
     */
    public Polynomial() {
        /* intentionally empty */
    }

    /**
     * Takes a double array and sets coefficient values
     *
     * @param arr
     */
    public void setCoefficients(double[] arr) {

        coefficients = new double[arr.length];

        for (int i = 0; i < arr.length; ++i) {
            coefficients[i] = arr[i];
        }
    }

    /**
     *
     * @return coefficients
     */
    public double[] getCoefficients() {

        return coefficients;
    }

    /**
     * Takes variable degree and returns it's coefficient
     *
     * @param degreeOfVariable
     * @return
     */
    public double getAnyCoefficient(int degreeOfVariable) {

        return coefficients[degreeOfVariable];
    }

    /**
     * Takes variable degree and a coefficient, sets coefficient value
     *
     * @param degreeOfVariable
     * @param newCoefficient
     */
    public void SetAnyCoefficient(int degreeOfVariable, double newCoefficient) {

        coefficients[degreeOfVariable] = newCoefficient;
    }

    /**
     * Takes a double value and it can evaluate the polynomial and return the
     * result
     *
     * @param x
     * @return
     */
    public double evaluateXValue(double x) {

        double sum = 0.0;

        for (int i = 0; i < getCoefficients().length; ++i) {
            sum += Math.pow(x, i) * coefficients[i];
        }

        return sum;
    }

    /**
     * Takes Polynomial and adds them to new Polynomial and returns it
     *
     * @param other
     * @return
     */
    public Polynomial adds(Polynomial other) {

        Polynomial sum = new Polynomial();

        if (getCoefficients().length < other.getCoefficients().length) {

            sum.setCoefficients(other.getCoefficients());
            for (int i = 0; i < getCoefficients().length; ++i) {
                sum.SetAnyCoefficient(i, getAnyCoefficient(i) + other.getAnyCoefficient(i));
            }
        } else {

            sum.setCoefficients(getCoefficients());
            for (int i = 0; i < other.getCoefficients().length; ++i) {
                sum.SetAnyCoefficient(i, getAnyCoefficient(i) + other.getAnyCoefficient(i));
            }
        }

        return sum;
    }

    /**
     * Takes Polynomial and subtracts them to new Polynomial and returns it
     *
     * @param other
     * @return
     */
    public Polynomial subtracts(Polynomial other) {

        Polynomial result = new Polynomial();

        if (getCoefficients().length < other.getCoefficients().length) {
            result.setCoefficients(other.getCoefficients());
            for (int i = 0; i < getCoefficients().length; ++i) {
                result.SetAnyCoefficient(i, getAnyCoefficient(i) - other.getAnyCoefficient(i));
            }
            for (int i = getCoefficients().length; i < other.getCoefficients().length; ++i) {
                result.SetAnyCoefficient(i, -1 * other.getAnyCoefficient(i));
            }

        } else {
            result.setCoefficients(getCoefficients());
            for (int i = 0; i < other.getCoefficients().length; ++i) {
                result.SetAnyCoefficient(i, getAnyCoefficient(i) - other.getAnyCoefficient(i));
            }
        }

        return result;
    }

    /**
     * Takes Polynomial and multiplies them to new Polynomial and returns it
     *
     * @param other
     * @return
     */
    public Polynomial multiplies(Polynomial other) {

        int maxLength = getCoefficients().length + other.getCoefficients().length;

        double[] resultArr = new double[maxLength - 1];

        for (int i = 0; i < getCoefficients().length; ++i) {
            for (int j = 0; j < other.getCoefficients().length; ++j) {
                resultArr[i + j] += getAnyCoefficient(i) * other.getAnyCoefficient(j);
            }
        }

        Polynomial result = new Polynomial();

        result.setCoefficients(resultArr);

        return result;
    }

    // Redefine toString method
    public String toString() {

        String formatted = "";

        for (int i = 0; i < getCoefficients().length; ++i) {

            if (i < getCoefficients().length - 2) {
                formatted += String.format("%.1fx^%d", getAnyCoefficient(getCoefficients().length - i - 1), getCoefficients().length - i - 1);
                formatted += " + ";

            } else if (i == getCoefficients().length - 2) {
                formatted += String.format("%.1fx", getAnyCoefficient(getCoefficients().length - i - 1));
                formatted += " + ";

            } else if (i == getCoefficients().length - 1) {
                formatted += String.format("%.1f", getAnyCoefficient(getCoefficients().length - i - 1));
            }
        }

        return formatted;

    }

    // Redefine equals method
    public boolean equals(Object other) {

        if (other == this) {
            return true;
        } else if (!(other instanceof Polynomial)) {
            return false;
        }

        Polynomial temp = (Polynomial) other;

        if (getCoefficients().length != temp.getCoefficients().length) {
            return false;
        } else if (getCoefficients().length == temp.getCoefficients().length) {
            for (int i = 0; i < getCoefficients().length; ++i) {
                if (getAnyCoefficient(i) != temp.getAnyCoefficient(i)) {
                    return false;
                }
            }
        }

        return true;

    }

    /**
     * Test Polynomial class
     *
     * @param args
     */
    public static void main(String[] args) {

        Polynomial x = new Polynomial(3, 2, 5);
        Polynomial y = new Polynomial(5, 4);
        Polynomial z = new Polynomial(6, 9, 8, 7);
        Polynomial k = new Polynomial(8.4, 4.2, 13, 25, -7, 22);
        Polynomial l = new Polynomial(9, 4, -2, 7.8);

        System.out.println("\n~~~~~~~~~~~~~POLYNOMS");
        System.out.printf("Polynom x : %s\n", x);
        System.out.printf("Polynom y : %s\n", y);
        System.out.printf("Polynom z : %s\n", z);
        System.out.printf("Polynom k : %s\n", k);
        System.out.printf("Polynom l : %s\n", l);

        // TEST ADD
        System.out.println("\n~~~~~~~~~~~~~TEST ADD");
        System.out.printf("Polynom x + Polynom y : %s\n", x.adds(y));
        System.out.printf("Polynom x + Polynom z : %s\n", x.adds(z));
        System.out.printf("Polynom x + Polynom k : %s\n", x.adds(k));
        System.out.printf("Polynom x + Polynom l : %s\n", x.adds(l));
        System.out.printf("Polynom y + Polynom z : %s\n", y.adds(z));
        System.out.printf("Polynom y + Polynom k : %s\n", y.adds(k));
        System.out.printf("Polynom y + Polynom l : %s\n", y.adds(l));
        System.out.printf("Polynom z + Polynom k : %s\n", z.adds(k));
        System.out.printf("Polynom z + Polynom l : %s\n", z.adds(l));
        System.out.printf("Polynom k + Polynom l : %s\n", k.adds(l));

        // TEST SUBSTRACT
        System.out.println("\n~~~~~~~~~~~~~TEST SUBSTRACT");
        System.out.printf("Polynom x - Polynom y : %s\n", x.subtracts(y));
        System.out.printf("Polynom x - Polynom z : %s\n", x.subtracts(z));
        System.out.printf("Polynom x - Polynom k : %s\n", x.subtracts(k));
        System.out.printf("Polynom x - Polynom l : %s\n", x.subtracts(l));
        System.out.printf("Polynom y - Polynom z : %s\n", y.subtracts(z));
        System.out.printf("Polynom y - Polynom k : %s\n", y.subtracts(k));
        System.out.printf("Polynom y - Polynom l : %s\n", y.subtracts(l));
        System.out.printf("Polynom z - Polynom k : %s\n", z.subtracts(k));
        System.out.printf("Polynom z - Polynom l : %s\n", z.subtracts(l));
        System.out.printf("Polynom k - Polynom l : %s\n", k.subtracts(l));

        // TEST MULTIPLIE
        System.out.println("\n~~~~~~~~~~~~~TEST MULTIPLIE");
        System.out.printf("Polynom x * Polynom y : %s\n", x.multiplies(y));
        System.out.printf("Polynom x * Polynom z : %s\n", x.multiplies(z));
        System.out.printf("Polynom x * Polynom k : %s\n", x.multiplies(k));
        System.out.printf("Polynom x * Polynom l : %s\n", x.multiplies(l));
        System.out.printf("Polynom y * Polynom z : %s\n", y.multiplies(z));
        System.out.printf("Polynom y * Polynom k : %s\n", y.multiplies(k));
        System.out.printf("Polynom y * Polynom l : %s\n", y.multiplies(l));
        System.out.printf("Polynom z * Polynom k : %s\n", z.multiplies(k));
        System.out.printf("Polynom z * Polynom l : %s\n", z.multiplies(l));
        System.out.printf("Polynom k * Polynom l : %s\n", k.multiplies(l));

        double evulate = 5.0;
        // TEST EVULATE
        System.out.println("\n~~~~~~~~~~~~~TEST EVULATE");
        System.out.printf("Polynom x  ( x = %.1f )  Result : %.1f\n", evulate, x.evaluateXValue(evulate));
        System.out.printf("Polynom y  ( x = %.1f )  Result : %.1f\n", evulate, y.evaluateXValue(evulate));
        System.out.printf("Polynom z  ( x = %.1f )  Result : %.1f\n", evulate, z.evaluateXValue(evulate));
        System.out.printf("Polynom k  ( x = %.1f )  Result : %.1f\n", evulate, k.evaluateXValue(evulate));
        System.out.printf("Polynom l  ( x = %.1f )  Result : %.1f\n", evulate, l.evaluateXValue(evulate));

        evulate = 3.3;
        System.out.printf("Polynom x  ( x = %.1f )  Result : %.1f\n", evulate, x.evaluateXValue(evulate));
        System.out.printf("Polynom y  ( x = %.1f )  Result : %.1f\n", evulate, y.evaluateXValue(evulate));
        System.out.printf("Polynom z  ( x = %.1f )  Result : %.1f\n", evulate, z.evaluateXValue(evulate));
        System.out.printf("Polynom k  ( x = %.1f )  Result : %.1f\n", evulate, k.evaluateXValue(evulate));
        System.out.printf("Polynom l  ( x = %.1f )  Result : %.1f\n", evulate, l.evaluateXValue(evulate));

        Polynomial m = new Polynomial(6, 9, 8, 7);
        System.out.printf("\nNew Polynom m : %s\n", m);

        //TEST EQUALS
        System.out.println("\n~~~~~~~~~~~~~TEST EQUALS");
        System.out.printf("Polynom x and m equals : %s\n", x.equals(m));
        System.out.printf("Polynom y and m equals : %s\n", y.equals(m));
        System.out.printf("Polynom z and m equals : %s\n", z.equals(m));
        System.out.printf("Polynom k and m equals : %s\n", k.equals(m));
        System.out.printf("Polynom l and m equals : %s\n", l.equals(m));

    }

}
