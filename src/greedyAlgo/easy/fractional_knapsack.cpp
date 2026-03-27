// statement- weight of N items & their corresponding values are given. put these items in knapsack of wt W such that total value obtained is maximized
// Note: We can either take item as whole or break it into smaller units

// method1(optimal) t.c- O(nlogn + n)  s.c- O(1)

struct Item{
    int value;
    int weight;
};

//  Comparator fxn to sort items in descending order in val/wt ratio
static bool comp(Item a, Item b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // descending order
}

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity){
    int n = val.size();
    vector<Item> items(n);
    for (int i = 0; i < n; i++){
        items[i] = {val[i], wt[i]};
    }

    sort(items.begin(), items.end(), comp);

    double ansValue = 0.0;

    for (int i = 0; i < n; i++){
        if (capacity >= items[i].weight){ // take full item
            ansValue += items[i].value; //incr ansVal
            capacity -= items[i].weight; //remaining capacity by substracting curr wt
        }
        else{ // take fraction
            ansValue += ((double)items[i].value / items[i].weight) * capacity;
            break;
        }
    }
    return ansValue;
}