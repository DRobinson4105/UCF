package finalsection;

import java.util.function.Consumer;

public class Callbacks {
    public static void main(String[] args) {
        hello("John", null, callback);
        hello("John", "Montana", callback);
        hello2("John", null, callback2);
        hello2("John", "Montana", callback2);
    }

    static Consumer<String> callback = firstName -> System.out.println("no last name provided for " + firstName);

    static Runnable callback2 = () -> System.out.println("no last name provided");

    static void hello(String firstName, String lastName, Consumer<String> callback) {
        System.out.print(firstName + " ");
        if (lastName != null)
            System.out.println(lastName);
        else
            callback.accept(firstName);
    }

    static void hello2(String firstName, String lastName, Runnable callback) {
        System.out.print(firstName + " ");
        if (lastName != null)
            System.out.println(lastName);
        else
            callback.run();
    }
}
