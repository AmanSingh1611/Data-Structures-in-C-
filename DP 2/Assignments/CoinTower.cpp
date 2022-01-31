/*
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. 
Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. 
The person to make the last move wins the game. Can you find out who wins the game?
*/
string findWinner(int n, int x, int y)
{
    int dp[n + 1]; 
    dp[0] = false; 
    dp[1] = true; 
  
    // Computing other values. 
    for (int i = 2; i <= n; i++) { 
        if (i - 1 >= 0 and !dp[i - 1]) 
            dp[i] = true; 
        else if (i - x >= 0 and !dp[i - x]) 
            dp[i] = true; 
        else if (i - y >= 0 and !dp[i - y]) 
            dp[i] = true;  
        else
            dp[i] = false; 
    } 
  
    // If dp[n] is true then A will 
    // game otherwise  he losses 
    string s="Whis";
    if (dp[n])
    {
        s="Beerus";
        return s;
    }
    else return s;
}