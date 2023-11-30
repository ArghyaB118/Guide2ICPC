/* LC#2115
 
 You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.
 
 You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

 Return a list of all the recipes that you can create. You may return the answer in any order.

 Note that two recipes may contain each other in their ingredients.
 
 Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
 Output: ["bread"]
 
 Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
 Output: ["bread","sandwich"]
 
 Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
 Output: ["bread","sandwich","burger"]*/

#include <iostream>
#include <vector>
// #include <list>
// #include <map>
#include <string>
using namespace std;

bool isCookable (vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies, int idx) {
    string recipe = recipes[idx];
    vector<string> ingredient = ingredients[idx];
    
    /*if (find(results.begin(), results.end(), recipe) != results.end())
        return true;
    else if (find(supplies.begin(), supplies.end(), recipe) != supplies.end())
        return true;*/
    
    for (auto i : ingredient) {
        if (find(supplies.begin(), supplies.end(), i) != supplies.end())
            continue;
        else if (find(recipes.begin(), recipes.end(), i) != recipes.end()) {
            int j;
            for (j = 0; j < recipes.size(); j++)
                if (recipes[j] == i)
                    break;
            if (isCookable(recipes, ingredients, supplies, j))
                continue;
            else
                return false;
        }
        else
            return false;
    }
    // results.push_back(recipe);
    // supplies.push_back(recipe);
    return true;
}

vector<string> findAllRecipes (vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    vector<string> results = {};
    for (int i = 0; i < recipes.size(); i++) {
        if (isCookable(recipes, ingredients, supplies, i))
            results.push_back(recipes[i]);
    }
    return results;
}

int main () {
    vector<string> recipes = {"bread","sandwich","burger"};
    vector<vector<string>> ingredients = {{"yeast","flour"}, {"bread","meat"}, {"sandwich","meat","bread"}};
    vector<string> supplies = {"yeast","flour","meat"};
    vector<string> result = findAllRecipes(recipes, ingredients, supplies);
    for (auto i : result)
        cout << i << endl;
    return 0;
}
