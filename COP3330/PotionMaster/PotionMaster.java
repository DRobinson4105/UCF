// =============================================================================
// POSTING THIS FILE ONLINE OR DISTRIBUTING IT IN ANY WAY, IN PART OR IN WHOLE,
// IS AN ACT OF ACADEMIC MISCONDUCT AND ALSO CONSTITUTES COPYRIGHT INFRINGEMENT.
// =============================================================================

// DAVID ROBINSON
// da034737
// COP 3330, Spring 2023

// =============================================================================
//             PotionMaster ~ Sean Szumlanski ~ COP 3330 ~ Spring 2023
// =============================================================================
// Note: I've put this template together for you so you can see one safe way of
// breaking up the method signatures that are too long to put on one line
// without exceeding the limit of 100 characters per line. You can modify
// anything you want in this file, and you can remove this comment.
// =============================================================================


import java.util.*;

public class PotionMaster
{
	public static Map<String, Set<String>> potionToReagentsMap(List<PotionInfo> potionsManual)
	{
		Map<String, Set<String>> res = new HashMap<>();
		
		// Loop through all potions mapping all potions to sets
		// of reagents that are used to make those potions
		for (PotionInfo potion : potionsManual)
			res.put(potion.name, new HashSet<>(potion.reagents));

		return res;
	}

	public static Map<String, Set<String>> reagentToPotionsMap(List<PotionInfo> potionsManual)
	{
		Map<String, Set<String>> res = new HashMap<>();

		// Loop through all potions mapping all reagents
		// to sets of potions that can be made with them
		for (PotionInfo potion : potionsManual)
		{
			// Loop through all reagents in the current potion,
			// adding the potion to each of the sets of the reagents
			for (String reagent : potion.reagents)
			{
				// If the set has not been created yet
				if (!res.containsKey(reagent))
					res.put(reagent, new HashSet<>());

				// Add potion to set
				res.get(reagent).add(potion.name);
			}
		}

		return res;
	}

	public static boolean canBrewPotion(PotionInfo potionInfo, Set<String> reagentsOnHand)
	{
		// Check if any needed reagents are not on hand
		for (String reagent : potionInfo.reagents)
			if (!reagentsOnHand.contains(reagent))
				return false;

		return true;
	}

	public static boolean canBrewPotion(String potionToBrew,
	                                    Map<String, Set<String>> potionToReagentsMap,
	                                    Set<String> reagentsOnHand)
	{
		// Potion does not need any reagents
		if (!potionToReagentsMap.containsKey(potionToBrew))
			return true;
		
		Set<String> neededReagents = potionToReagentsMap.get(potionToBrew);

		// Check if any needed reagents are not on hand
		for (String reagent : neededReagents)
			if (!reagentsOnHand.contains(reagent))
				return false;

		return true;
	}

	public static Set<String> allPossiblePotions(Map<String, Set<String>> potionToReagentsMap,
	                                             Map<String, Set<String>> reagentToPotionsMap,
	                                             Set<String> reagentsOnHand)
	{
		Set<String> possiblePotions = new HashSet<>();
		Set<String> filteredPotions = new HashSet<>();
		
		// Add all possible potions to set that are made with one of the reagents on hand
		for (String reagent : reagentsOnHand)
		{
			// If reagent is in map
			if (reagentToPotionsMap.containsKey(reagent))
				possiblePotions.addAll(reagentToPotionsMap.get(reagent));
		}

		// Filter out potions that can't be made with reagents on hand
		for (String potion : possiblePotions)
			if (canBrewPotion(potion, potionToReagentsMap, reagentsOnHand))
				filteredPotions.add(potion);

		return filteredPotions;
	}

	public static double difficultyRating()
	{
		return 1.0;
	}

	public static double hoursSpent()
	{
		return 1.0;
	}
}