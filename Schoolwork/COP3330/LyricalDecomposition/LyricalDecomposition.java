// David Robinson
// COP 3330, Spring 2023
// da034737

public class LyricalDecomposition
{
    public static void printLyrics()
    {
        // Swallowed a Fly
        printFlyVerse();

        // Swallowed a Spider
        printSpiderVerse();

        // Swallowed a Bird
        printBirdVerse();

        // Swallowed a Cat
        printCatVerse();

        // Swallowed a Dog
        printDogVerse();
        
        // Swallowed a Horse
        printHorseVerse();
    }

    public static void printFlyVerse()
    {
        System.out.println("There was an old woman who swallowed a fly.");
        dontKnowWhy();
        shellDie();
    }

    public static void printSpiderVerse()
    {
        System.out.println("There was an old woman who swallowed a spider,");
        System.out.println("That wriggled and iggled and jiggled inside her!");
        swallowedSpidertoCatchFly();
        dontKnowWhy();
        shellDie();
    }

    public static void printBirdVerse()
    {
        System.out.println("There was an old woman who swallowed a bird.");
        System.out.println("How absurd, to swallow a bird!");
        swallowedBirdtoCatchSpider();
        swallowedSpidertoCatchFly();
        dontKnowWhy();
        shellDie();
    }

    public static void printCatVerse()
    {
        System.out.println("There was an old woman who swallowed a cat.");
        System.out.println("Imagine that, to swallow a cat!");
        swallowedCattoCatchBird();
        swallowedBirdtoCatchSpider();
        swallowedSpidertoCatchFly();
        dontKnowWhy();
        shellDie();
    }

    public static void printDogVerse()
    {
        System.out.println("There was an old woman who swallowed a dog.");
        System.out.println("What a hog, to swallow a dog!");
        System.out.println("She swallowed the dog to catch the cat;");
        swallowedCattoCatchBird();
        swallowedBirdtoCatchSpider();
        swallowedSpidertoCatchFly();
        dontKnowWhy();
        shellDie();
    }

    public static void printHorseVerse()
    {
        System.out.println("There was an old woman who swallowed a horse.");
        System.out.println("She died, of course!");
    }

    public static double difficultyRating() 
    {
        return 1.0;
    }

    public static double hoursSpent() 
    {
        return 2;
    }

    public static void dontKnowWhy() 
    {
        System.out.println("I don't know why she swallowed that fly;");
    }

    public static void shellDie() 
    {
        System.out.println("Perhaps she'll die.\n");
    }

    public static void swallowedSpidertoCatchFly() 
    {
        System.out.println("She swallowed the spider to catch the fly.");
    }

    public static void swallowedBirdtoCatchSpider() 
    {
        System.out.println("She swallowed the bird to catch the spider;");
    }

    public static void swallowedCattoCatchBird() 
    {
        System.out.println("She swallowed the cat to catch the bird;");
    }
}