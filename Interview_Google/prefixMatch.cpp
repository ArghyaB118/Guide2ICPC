/* Google Interview: Summer 2023: November 2022
 
 Question: Match string against a list of prefixes.
 
 Input: 1) a list of string prefixes (frozen constant list given at the job startup, O(100)).
        2) many target strings to match, billions of them.
 Output: returns true if and only if one prefix in the list matches the target string as a prefix.

 Example:
 prefixes = ["aa", "bb", "cc"]
 target = "aaa" -> returns true
 target = "ddd" -> returns false
 target = "aa" -> returns true
 target = "a" -> returns false
 
 // Idea 0: to iterate over all the prefixes and compare, O(# prefixes)
 // Idea 1: put all prefix in a hashtable and incrementally append one char from target at a time
 //         and check against the hashtable. Complexity bound by O(max(|prefix|) * (1+load_factor))
 // Idea 2: Trie built from the prefixes. O(max(|prefix|))
 */
