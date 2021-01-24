/* Update - Thanks to some folks who pointed out a flaw in my code.
 * I have updated it. Hope it is correct now :-) 
 * Old version can be found here - 
 https://gist.github.com/krisys/4089748/262cbc10d9b9f1cb5df771e14a1e143a86d2ecc6/ 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BadNeighbors{
    public:
        int maxDonations(vector <int> amount);
};

int BadNeighbors::maxDonations(vector <int> amount){
    int N = amount.size();
    if (N < 3){
        return *max(amount.begin(), amount.end());
    }
    /* contains the best value till index i */
    vector <int> dp(50);

    /* Flag to denote if 0th element was included to get this value */
    vector <bool> zero_included(50, false);

    /* Flag to denote if ith element was included to get dp[i] */
    vector <bool> i_included(50, false);

    // Initialize first two elements
    dp[0] = amount[0];
    i_included[0] = zero_included[0] = true;

    if (amount[1] > dp[0]){
        dp[1] = amount[1];
        i_included[1] = true;
    } else {
        dp[1] = dp[0];
        i_included[1] = false;
        zero_included[1] = zero_included[0];
    }

    for(int i = 2; i < N; i++){
        if(dp[i-2] + amount[i] > dp[i-1]){
            dp[i] = dp[i-2] + amount[i];
            i_included[i] = true;
            zero_included[i] = zero_included[i-2];
        } else {
            dp[i] = dp[i-1];
            i_included[i] = false;
            zero_included[i] = zero_included[i-1];
        }
    }

    if(i_included[N-1] && zero_included[N-1]){
        return max(
            max(
                dp[N-2],
                dp[N-1] - amount[N-1]
            ),
            dp[N-1] - amount[0]
        );
    } else {
        return dp[N-1];
    }
}

int donations[] =   { 10, 3, 2, 5, 7, 8 };

/*int donations[] = { 11, 15 };*/

/*int donations[] = { 7, 7, 7, 7, 7, 7, 7 };*/

/*int donations[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };*/

/*int donations[] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
  6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };*/
/*int donations[] = {10, 3, 2, 5, 1};*/

/*int donations[] = {590, 260, 60, 331, 929, 661, 675, 181, 593,
    69, 253, 675, 410, 328, 734, 560, 547, 520, 408, 108, 346, 14,
    982, 808, 944, 896, 558, 691, 941, 341, 306, 471, 750, 592,
    279, 205, 485, 483, 895, 415}; */

/*int donations[] = {442, 851, 111, 479, 261, 770, 194, 619, 864, 263,
    323, 15, 110, 37, 926, 399, 916, 824, 811, 988, 290, 135, 633, 766,
    293, 554, 193, 943, 480, 239, 391, 865, 778, 962, 383, 792, 42,
    836, 646, 727};*/
/*int donations[] = {90, 1, 2, 89, 3, 4, 88, 5, 6, 87, 5, 4, 86, 3, 2, 85}; */

/*int donations[] = {307, 322, 35, 140, 667, 1, 884, 44, 546, 239,
    548, 881, 222, 459, 55, 158, 642, 280, 237, 561, 925, 539, 38,
    699, 107, 116, 449, 418, 720, 487, 983, 743}; */

/*int donations[] = {917, 19, 978, 687, 346, 245, 677, 708, 565, 940,
    211, 127, 993, 768, 469, 279, 460, 335, 734, 130, 691, 783, 182,
    391, 827, 295, 534, 263, 193, 498, 327, 120, 690
};*/


int main(int argc, char const *argv[]){
    BadNeighbors BN;
    int N = sizeof(donations)/ sizeof(donations[0]);
    cout << BN.maxDonations(vector <int> (donations, donations + N)) << endl;
}